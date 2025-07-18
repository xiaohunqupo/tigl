/*
* Copyright (C) 2007-2014 German Aerospace Center (DLR/SC)
*
* Created: 2014-04-11 Philipp Kunze <Philipp.Kunze@dlr.de>
* Changed: $Id$
*
* Version: $Revision$
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file
* @brief  Implementation of CPACS rotor blade attachment handling routines.
*/

#include "CCPACSRotorBladeAttachment.h"
#include "CCPACSRotor.h"
#include "CCPACSConfiguration.h"
#include "CTiglError.h"

namespace tigl
{
CCPACSRotorBladeAttachment::CCPACSRotorBladeAttachment(CCPACSRotorBladeAttachments* parent, CTiglUIDManager* uidMgr)
    : generated::CPACSRotorBladeAttachment(parent, uidMgr) {}


// Invalidates internal state
void CCPACSRotorBladeAttachment::InvalidateImpl(const boost::optional<std::string>& source) const
{
    lazyCreateAttachedRotorBlades();
    for (unsigned int i = 0; i < attachedRotorBlades.size(); i++) {
        attachedRotorBlades[i]->Invalidate();
    }
}

// Builds and returns the transformation matrix for an attached rotor blade
//     rotorThetaDeg:         current azimuthal position of the rotor in degrees
//     bladeDeltaThetaDeg:    azimuth angle offset of the attached blade
//     doRotorTransformation: include the parent rotor transformation?
CTiglTransformation CCPACSRotorBladeAttachment::GetRotorBladeTransformationMatrix(double rotorThetaDeg, double bladeDeltaThetaDeg, bool doHingeTransformation, bool doRotationDirTransformation, bool doRotorTransformation)
{
    double bladeThetaDeg = rotorThetaDeg + bladeDeltaThetaDeg; // current azimuthal position of the rotor blade in degrees

    // Rotor blade transformation chain:
    CTiglTransformation rotorBladeTransformation;

    // 0. Initialize matrix
    rotorBladeTransformation.SetIdentity();

    // 1. Rotation around hinges, beginning with the last
    if (doHingeTransformation) {
        for (int k=GetHingeCount()-1; k>=0; --k) {
            CTiglPoint curHingePosition = GetHinge(k+1).GetTranslation();
            const ECPACSRotorHubHinge_type& curHingeType = GetHinge(k+1).GetType();
            // a. move to origin
            rotorBladeTransformation.AddTranslation(-curHingePosition.x, -curHingePosition.y, -curHingePosition.z);
            // b. rotate around hinge axis
            if (curHingeType == ECPACSRotorHubHinge_type::pitch) {
                rotorBladeTransformation.AddRotationX( (GetHinge(k+1).GetHingeAngle(bladeThetaDeg)));
            }
            else if (curHingeType == ECPACSRotorHubHinge_type::flap) {
                rotorBladeTransformation.AddRotationY(-(GetHinge(k+1).GetHingeAngle(bladeThetaDeg)));
            }
            else if (curHingeType == ECPACSRotorHubHinge_type::leadLag) {
                rotorBladeTransformation.AddRotationZ( (GetHinge(k+1).GetHingeAngle(bladeThetaDeg)));
            }
            // c. move back to origin
            rotorBladeTransformation.AddTranslation(curHingePosition.x, curHingePosition.y, curHingePosition.z);
            //TODO: account for rotation and scaling of hinge?
        }
    }
    // 2. If the rotation direction is clockwise (e.g. french rotor): mirror rotor blade in x direction
    if (doRotationDirTransformation) {
        if (GetRotor().GetNominalRotationsPerMinute() < 0. ) {
            rotorBladeTransformation.AddMirroringAtYZPlane();
            bladeThetaDeg *= -1.;
        }
    }
    // 3. Rotate the rotor blade around z to its azimuth position
    rotorBladeTransformation.AddRotationZ(bladeThetaDeg);

    // 4. Add rotor transformation if desired
    if (doRotorTransformation) {
        rotorBladeTransformation.PreMultiply(GetRotor().GetTransformationMatrix());
    }

    return rotorBladeTransformation;
}

// Returns the number of attached rotor blades
size_t CCPACSRotorBladeAttachment::GetNumberOfBlades() const
{
    if (m_numberOfBlades_choice2)
        return *m_numberOfBlades_choice2;
    else
        return static_cast<int>(m_azimuthAngles_choice1->AsVector().size());
}

// Returns the azimuth angle of the attached rotor blade with the given index
double CCPACSRotorBladeAttachment::GetAzimuthAngle(size_t index) const
{
    index --;
    if (index < 0 || index >= GetNumberOfBlades()) {
        throw CTiglError("Invalid index in CCPACSRotorBladeAttachment::GetAzimuthAngle", TIGL_INDEX_ERROR);
    }
    if (m_azimuthAngles_choice1)
        return m_azimuthAngles_choice1->AsVector()[index];
    else
        return index * 360.0 / static_cast<double>(*m_numberOfBlades_choice2);
}

// Returns the index of the referenced wing definition
size_t CCPACSRotorBladeAttachment::GetWingIndex() const
{
    return GetConfiguration().GetWingIndex(m_rotorBladeUID);
}

// Get hinge count
size_t CCPACSRotorBladeAttachment::GetHingeCount() const
{
    if (m_hinges)
        return m_hinges->GetRotorHingeCount();
    else
        return 0;
}

// Returns the hinge for a given index
const CCPACSRotorHinge& CCPACSRotorBladeAttachment::GetHinge(size_t index) const
{
    return m_hinges->GetRotorHinge(index);
}
CCPACSRotorHinge& CCPACSRotorBladeAttachment::GetHinge(size_t index)
{
    return m_hinges->GetRotorHinge(index);
}

// Returns the rotor blade for a given index
const CTiglAttachedRotorBlade& CCPACSRotorBladeAttachment::GetAttachedRotorBlade(size_t index) const
{
    lazyCreateAttachedRotorBlades();
    index--;
    if (index < 0 || index >= GetNumberOfBlades()) {
        throw CTiglError("Invalid index in CCPACSRotorBladeAttachment::GetAttachedRotorBlade", TIGL_INDEX_ERROR);
    }
    return *attachedRotorBlades[index];
}

// Returns the rotor blade for a given index
CTiglAttachedRotorBlade& CCPACSRotorBladeAttachment::GetAttachedRotorBlade(size_t index) {
    return const_cast<CTiglAttachedRotorBlade&>(std::as_const(*this).GetAttachedRotorBlade(index));
}

// Returns the parent rotor
const CCPACSRotor& CCPACSRotorBladeAttachment::GetRotor() const
{
    return *m_parent->GetParent()->GetParent();
}

CCPACSRotor& CCPACSRotorBladeAttachment::GetRotor()
{
    return *m_parent->GetParent()->GetParent();
}

void CCPACSRotorBladeAttachment::lazyCreateAttachedRotorBlades() const
{
    // Create wrappers for attached rotor blades
    // We have to do these lazily, as we do not have control of the order in which CPACS elements are read
    // (wings may not be loaded yet, when ReadCPACS of this class is called)
    CCPACSRotorcraftModel& rotorcraft = *m_parent->GetParent()->GetParent()->GetParent()->GetParent();
    const int bladeCount = GetNumberOfBlades();
    if (attachedRotorBlades.size() != bladeCount) {
        attachedRotorBlades.clear();
        if (rotorcraft.GetRotorBlades()) {
            CCPACSWing& blade = rotorcraft.GetRotorBlades()->GetRotorBlade(m_rotorBladeUID);
            for (int i = 0; i < bladeCount; i++) {
                attachedRotorBlades.push_back(make_unique<CTiglAttachedRotorBlade>(const_cast<CCPACSRotorBladeAttachment*>(this), blade, i + 1));
            }
        }
    }
    assert(attachedRotorBlades.size() == bladeCount);
}

// Returns the parent configuration
const CCPACSConfiguration& CCPACSRotorBladeAttachment::GetConfiguration() const
{
    return m_parent->GetConfiguration();
}

CCPACSConfiguration& CCPACSRotorBladeAttachment::GetConfiguration()
{
    return m_parent->GetConfiguration();
}

} // end namespace tigl
