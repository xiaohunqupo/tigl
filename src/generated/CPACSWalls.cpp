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

#include <cassert>
#include "CCPACSFuselageStructure.h"
#include "CCPACSVesselStructure.h"
#include "CPACSWalls.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWalls::CPACSWalls(CCPACSFuselageStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_wallPositions(reinterpret_cast<CCPACSWalls*>(this), m_uidMgr)
        , m_wallSegments(reinterpret_cast<CCPACSWalls*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSFuselageStructure);
    }

    CPACSWalls::CPACSWalls(CCPACSVesselStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_wallPositions(reinterpret_cast<CCPACSWalls*>(this), m_uidMgr)
        , m_wallSegments(reinterpret_cast<CCPACSWalls*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSVesselStructure);
    }

    CPACSWalls::~CPACSWalls()
    {
    }

    const CTiglUIDObject* CPACSWalls::GetNextUIDParent() const
    {
        if (m_parent) {
            if (IsParent<CCPACSFuselageStructure>()) {
                return GetParent<CCPACSFuselageStructure>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSVesselStructure>()) {
                return GetParent<CCPACSVesselStructure>()->GetNextUIDParent();
            }
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSWalls::GetNextUIDParent()
    {
        if (m_parent) {
            if (IsParent<CCPACSFuselageStructure>()) {
                return GetParent<CCPACSFuselageStructure>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSVesselStructure>()) {
                return GetParent<CCPACSVesselStructure>()->GetNextUIDParent();
            }
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSWalls::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWalls::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSWalls::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element wallPositions
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/wallPositions")) {
            m_wallPositions.ReadCPACS(tixiHandle, xpath + "/wallPositions");
        }
        else {
            LOG(ERROR) << "Required element wallPositions is missing at xpath " << xpath;
        }

        // read element wallSegments
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/wallSegments")) {
            m_wallSegments.ReadCPACS(tixiHandle, xpath + "/wallSegments");
        }
        else {
            LOG(ERROR) << "Required element wallSegments is missing at xpath " << xpath;
        }

    }

    void CPACSWalls::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element wallPositions
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/wallPositions");
        m_wallPositions.WriteCPACS(tixiHandle, xpath + "/wallPositions");

        // write element wallSegments
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/wallSegments");
        m_wallSegments.WriteCPACS(tixiHandle, xpath + "/wallSegments");

    }

    const CPACSWallPositions& CPACSWalls::GetWallPositions() const
    {
        return m_wallPositions;
    }

    CPACSWallPositions& CPACSWalls::GetWallPositions()
    {
        return m_wallPositions;
    }

    const CPACSWallSegments& CPACSWalls::GetWallSegments() const
    {
        return m_wallSegments;
    }

    CPACSWallSegments& CPACSWalls::GetWallSegments()
    {
        return m_wallSegments;
    }

} // namespace generated
} // namespace tigl
