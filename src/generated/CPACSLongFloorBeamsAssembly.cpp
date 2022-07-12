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
#include <CCPACSLongFloorBeam.h>
#include "CCPACSFuselageStructure.h"
#include "CPACSLongFloorBeamsAssembly.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSLongFloorBeamsAssembly::CPACSLongFloorBeamsAssembly(CCPACSFuselageStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSLongFloorBeamsAssembly::~CPACSLongFloorBeamsAssembly()
    {
    }

    const CCPACSFuselageStructure* CPACSLongFloorBeamsAssembly::GetParent() const
    {
        return m_parent;
    }

    CCPACSFuselageStructure* CPACSLongFloorBeamsAssembly::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSLongFloorBeamsAssembly::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSLongFloorBeamsAssembly::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSLongFloorBeamsAssembly::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSLongFloorBeamsAssembly::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSLongFloorBeamsAssembly::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element longFloorBeam
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/longFloorBeam")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/longFloorBeam", m_longFloorBeams, 1, tixi::xsdUnbounded, reinterpret_cast<CCPACSLongFloorBeamsAssembly*>(this), m_uidMgr);
        }

    }

    void CPACSLongFloorBeamsAssembly::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element longFloorBeam
        tixi::TixiSaveElements(tixiHandle, xpath + "/longFloorBeam", m_longFloorBeams);

    }

    const std::vector<std::unique_ptr<CCPACSLongFloorBeam>>& CPACSLongFloorBeamsAssembly::GetLongFloorBeams() const
    {
        return m_longFloorBeams;
    }

    std::vector<std::unique_ptr<CCPACSLongFloorBeam>>& CPACSLongFloorBeamsAssembly::GetLongFloorBeams()
    {
        return m_longFloorBeams;
    }

    CCPACSLongFloorBeam& CPACSLongFloorBeamsAssembly::AddLongFloorBeam()
    {
        m_longFloorBeams.push_back(make_unique<CCPACSLongFloorBeam>(reinterpret_cast<CCPACSLongFloorBeamsAssembly*>(this), m_uidMgr));
        return *m_longFloorBeams.back();
    }

    void CPACSLongFloorBeamsAssembly::RemoveLongFloorBeam(CCPACSLongFloorBeam& ref)
    {
        for (std::size_t i = 0; i < m_longFloorBeams.size(); i++) {
            if (m_longFloorBeams[i].get() == &ref) {
                m_longFloorBeams.erase(m_longFloorBeams.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
