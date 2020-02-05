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
#include <CCPACSWingCSStructure.h>
#include <string>
#include <tixi.h>
#include "CPACSControlSurfaceOuterShapeTrailingEdge.h"
#include "CPACSControlSurfacePath.h"
#include "CPACSControlSurfaceTracks.h"
#include "CPACSControlSurfaceWingCutOut.h"
#include "CreateIfNotExists.h"
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSTrailingEdgeDevices;

namespace generated
{
    // This class is used in:
    // CPACSTrailingEdgeDevices

    // generated from /xsd:schema/xsd:complexType[889]
    /// @brief Trailing edge device of the wing.
    /// 
    /// A trailingEdgeDevice (TED) is defined via its
    /// outerShape relative to the componentSegment. The WingCutOut
    /// defines the area of the skin that is removed by the TED.
    /// Structure is similar to the wing structure. The mechanical links
    /// between the TED and the parrent are defined in tracks. The
    /// deflection path is described in path. Additional actuators, that
    /// are not included into a track, can be defined in actuators.
    /// Leading and trailing edge are defined by the outer
    /// shape of the wing segments, i.e. the trailing edge of a
    /// trailingEdgeDevice is the trailing edge of the wing. This is also
    /// valid for kinks that are present in the wing but not explicitly
    /// modeled in the control surface.
    /// The edges of the control surface within the wing are a
    /// straight line in absolute coordinates! Hence, there needs to be a
    /// straight connection between the eta-wise outer and inner points
    /// of the edge that is within the wing in absolute coordinates.
    /// 
    class CPACSTrailingEdgeDevice : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSTrailingEdgeDevice(CCPACSTrailingEdgeDevices* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSTrailingEdgeDevice();

        TIGL_EXPORT CCPACSTrailingEdgeDevices* GetParent();

        TIGL_EXPORT const CCPACSTrailingEdgeDevices* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const std::string& GetParentUID() const;
        TIGL_EXPORT virtual void SetParentUID(const std::string& value);

        TIGL_EXPORT virtual const CPACSControlSurfaceOuterShapeTrailingEdge& GetOuterShape() const;
        TIGL_EXPORT virtual CPACSControlSurfaceOuterShapeTrailingEdge& GetOuterShape();

        TIGL_EXPORT virtual const boost::optional<CPACSControlSurfaceWingCutOut>& GetWingCutOut() const;
        TIGL_EXPORT virtual boost::optional<CPACSControlSurfaceWingCutOut>& GetWingCutOut();

        TIGL_EXPORT virtual const boost::optional<CCPACSWingCSStructure>& GetStructure() const;
        TIGL_EXPORT virtual boost::optional<CCPACSWingCSStructure>& GetStructure();

        TIGL_EXPORT virtual const CPACSControlSurfacePath& GetPath() const;
        TIGL_EXPORT virtual CPACSControlSurfacePath& GetPath();

        TIGL_EXPORT virtual const boost::optional<CPACSControlSurfaceTracks>& GetTracks() const;
        TIGL_EXPORT virtual boost::optional<CPACSControlSurfaceTracks>& GetTracks();

        TIGL_EXPORT virtual CPACSControlSurfaceWingCutOut& GetWingCutOut(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveWingCutOut();

        TIGL_EXPORT virtual CCPACSWingCSStructure& GetStructure(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStructure();

        TIGL_EXPORT virtual CPACSControlSurfaceTracks& GetTracks(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveTracks();

    protected:
        CCPACSTrailingEdgeDevices* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                                    m_uID;

        /// Name of the trailing edge device.
        std::string                                    m_name;

        /// Description of the trailing edge device.
        boost::optional<std::string>                   m_description;

        /// UID of the parent of the TED. The parent can
        /// either be the uID of the componentSegment of the wing, or the
        /// uID of another TED. In the second case this TED is placed within
        /// the other TED (double slotted flap). In this way n-slotted TEDs
        /// can be created.
        std::string                                    m_parentUID;

        CPACSControlSurfaceOuterShapeTrailingEdge      m_outerShape;

        boost::optional<CPACSControlSurfaceWingCutOut> m_wingCutOut;

        boost::optional<CCPACSWingCSStructure>         m_structure;

        CPACSControlSurfacePath                        m_path;

        boost::optional<CPACSControlSurfaceTracks>     m_tracks;

    private:
        const CTiglUIDObject* GetNextUIDObject() const final;
        void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSTrailingEdgeDevice(const CPACSTrailingEdgeDevice&) = delete;
        CPACSTrailingEdgeDevice& operator=(const CPACSTrailingEdgeDevice&) = delete;

        CPACSTrailingEdgeDevice(CPACSTrailingEdgeDevice&&) = delete;
        CPACSTrailingEdgeDevice& operator=(CPACSTrailingEdgeDevice&&) = delete;
    };
} // namespace generated

// CPACSTrailingEdgeDevice is customized, use type CCPACSTrailingEdgeDevice directly
} // namespace tigl
