// Copyright (c) 2020 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSTransformation.h>
#include <string>
#include <TiglSymmetryAxis.h>
#include <tixi.h>
#include "CPACSLandingGearComponentAssembly.h"
#include "CPACSLandingGearControl.h"
#include "CreateIfNotExists.h"
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    class CPACSLandingGears;

    // This class is used in:
    // CPACSLandingGears

    /// @brief Landing gear base
    /// 
    /// Base type for landing gears (i.e. nose gear, main gear and skid gear).
    /// An example of a nose and main gear is shown below:
    /// @see landingGears
    /// 
    class CPACSLandingGearBase : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSLandingGearBase(CPACSLandingGears* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSLandingGearBase();

        TIGL_EXPORT CPACSLandingGears* GetParent();

        TIGL_EXPORT const CPACSLandingGears* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT bool ValidateChoices() const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<TiglSymmetryAxis>& GetSymmetry() const;
        TIGL_EXPORT virtual void SetSymmetry(const boost::optional<TiglSymmetryAxis>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetName() const;
        TIGL_EXPORT virtual void SetName(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetParentUID() const;
        TIGL_EXPORT virtual void SetParentUID(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSLandingGearControl>& GetControl() const;
        TIGL_EXPORT virtual boost::optional<CPACSLandingGearControl>& GetControl();

        TIGL_EXPORT virtual const boost::optional<CPACSLandingGearComponentAssembly>& GetComponentAssembly_choice1() const;
        TIGL_EXPORT virtual boost::optional<CPACSLandingGearComponentAssembly>& GetComponentAssembly_choice1();

        TIGL_EXPORT virtual const boost::optional<double>& GetTotalLength_choice2() const;
        TIGL_EXPORT virtual void SetTotalLength_choice2(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetStaticSuspensionTravel_choice2() const;
        TIGL_EXPORT virtual void SetStaticSuspensionTravel_choice2(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetCompressedSuspensionTravel_choice2() const;
        TIGL_EXPORT virtual void SetCompressedSuspensionTravel_choice2(const boost::optional<double>& value);

        TIGL_EXPORT virtual const CCPACSTransformation& GetTransformation() const;
        TIGL_EXPORT virtual CCPACSTransformation& GetTransformation();

        TIGL_EXPORT virtual CPACSLandingGearControl& GetControl(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveControl();

        TIGL_EXPORT virtual CPACSLandingGearComponentAssembly& GetComponentAssembly_choice1(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveComponentAssembly_choice1();

    protected:
        CPACSLandingGears* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                                        m_uID;

        boost::optional<TiglSymmetryAxis>                  m_symmetry;

        /// Name
        boost::optional<std::string>                       m_name;

        /// Description
        boost::optional<std::string>                       m_description;

        /// UID of the parent component. If set, the position of the main strut is defined relative to the parent coordinate system.
        boost::optional<std::string>                       m_parentUID;

        boost::optional<CPACSLandingGearControl>           m_control;

        boost::optional<CPACSLandingGearComponentAssembly> m_componentAssembly_choice1;

        /// Total length of landing gear, equals the distance from the middle of the bogie/axles to the axis of rotation of the pintle strut. Distance is measured while landing gear is fully extended and in airborne condition (i.e., if a spring is present, the totalLength includes the springDeflectionLength)
        boost::optional<double>                            m_totalLength_choice2;

        /// Static suspension travel means the positive distance between the total length in airborne condition and the reduced length due to compression on the ground.
        boost::optional<double>                            m_staticSuspensionTravel_choice2;

        /// Compressed suspension travel means the positive distance between the total length in airborne condition and the maximum reduced length due to maximum compression on the ground (e.g., landing shock).
        boost::optional<double>                            m_compressedSuspensionTravel_choice2;

        /// Transformation with respect to the uppermost point of the main strut. From this point the landing gear is oriented in negative z-direction by default.
        CCPACSTransformation                               m_transformation;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSLandingGearBase(const CPACSLandingGearBase&) = delete;
        CPACSLandingGearBase& operator=(const CPACSLandingGearBase&) = delete;

        CPACSLandingGearBase(CPACSLandingGearBase&&) = delete;
        CPACSLandingGearBase& operator=(CPACSLandingGearBase&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSLandingGearBase = generated::CPACSLandingGearBase;
using CCPACSLandingGears = generated::CPACSLandingGears;
} // namespace tigl