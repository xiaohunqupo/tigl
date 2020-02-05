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
#include <string>
#include <tixi.h>
#include "CPACSBoundingElementUIDs.h"
#include "CPACSWallPositionUIDs.h"
#include "CreateIfNotExists.h"
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    class CPACSWallSegments;

    // This class is used in:
    // CPACSWallSegments

    // generated from /xsd:schema/xsd:complexType[1006]
    class CPACSWallSegment : public CTiglOptUIDObject
    {
    public:
        TIGL_EXPORT CPACSWallSegment(CPACSWallSegments* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWallSegment();

        TIGL_EXPORT CPACSWallSegments* GetParent();

        TIGL_EXPORT const CPACSWallSegments* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const double& GetPhi() const;
        TIGL_EXPORT virtual void SetPhi(const double& value);

        TIGL_EXPORT virtual const boost::optional<bool>& GetNegativeExtrusion() const;
        TIGL_EXPORT virtual void SetNegativeExtrusion(const boost::optional<bool>& value);

        TIGL_EXPORT virtual const boost::optional<bool>& GetFlushConnectionStart() const;
        TIGL_EXPORT virtual void SetFlushConnectionStart(const boost::optional<bool>& value);

        TIGL_EXPORT virtual const boost::optional<bool>& GetFlushConnectionEnd() const;
        TIGL_EXPORT virtual void SetFlushConnectionEnd(const boost::optional<bool>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSBoundingElementUIDs>& GetBoundingElementUIDs() const;
        TIGL_EXPORT virtual boost::optional<CPACSBoundingElementUIDs>& GetBoundingElementUIDs();

        TIGL_EXPORT virtual const boost::optional<std::string>& GetStructuralWallElementUID() const;
        TIGL_EXPORT virtual void SetStructuralWallElementUID(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const CPACSWallPositionUIDs& GetWallPositionUIDs() const;
        TIGL_EXPORT virtual CPACSWallPositionUIDs& GetWallPositionUIDs();

        TIGL_EXPORT virtual CPACSBoundingElementUIDs& GetBoundingElementUIDs(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveBoundingElementUIDs();

    protected:
        CPACSWallSegments* m_parent;

        CTiglUIDManager* m_uidMgr;

        boost::optional<std::string>              m_uID;

        /// Defines extrusion direction. Rotation angle
        /// around fuselage x-axis of extrusion direction. A
        /// value of 0deg means fuselage z-axis as extrusion
        /// direction. Default: 0.0deg.
        double                                    m_phi;

        /// By default, the wall is only extruded in positive direction. If negativeExtrusion is selected, the wall is additionaly extruded in negative direction. Default: false.
        boost::optional<bool>                     m_negativeExtrusion;

        /// Rotates the first edge of the wall segment so that it is adjacent with the structural element defined in the first wall position (bulkhead, fuselage section or another plane wall). Default: false.
        boost::optional<bool>                     m_flushConnectionStart;

        /// Rotates the last edge of the wall segment so that it is adjacent with the structural element defined in the last wall position (bulkhead, fuselage section or another plane wall). Default: false.
        boost::optional<bool>                     m_flushConnectionEnd;

        /// A list of uIDs referencing other
        /// structural/geometric elements that shall serve
        /// as a boundary of the wall element. Possible
        /// references are floor, wall or
        /// genericGeometryComponent. A major requirement is
        /// that the referenced element has an intersection
        /// with the wall for at least the distance between
        /// two wall positions. So that a full geometric
        /// face of the wall is bounded by it. Neighbouring
        /// wall faces that are not completely bounded by
        /// the reference element are not affected.
        boost::optional<CPACSBoundingElementUIDs> m_boundingElementUIDs;

        /// Reference to the structural property definition
        /// of this wall segment.
        boost::optional<std::string>              m_structuralWallElementUID;

        /// List of wall position uIDs that are used for
        /// this wall segment. At least two positions must
        /// be defined (for start and end position of wall).
        /// If more than two positions are referenced here,
        /// the wall is constructed out of several planar
        /// faces that connect two consecutive positions
        /// (Note: Order of position uIDs defines
        /// connectivity).
        CPACSWallPositionUIDs                     m_wallPositionUIDs;

    private:
        CPACSWallSegment(const CPACSWallSegment&) = delete;
        CPACSWallSegment& operator=(const CPACSWallSegment&) = delete;

        CPACSWallSegment(CPACSWallSegment&&) = delete;
        CPACSWallSegment& operator=(CPACSWallSegment&&) = delete;
    };
} // namespace generated

// CPACSWallSegment is customized, use type CCPACSFuselageWallSegment directly

// Aliases in tigl namespace
using CCPACSWallSegments = generated::CPACSWallSegments;
} // namespace tigl
