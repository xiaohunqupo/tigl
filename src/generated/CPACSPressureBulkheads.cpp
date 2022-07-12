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
#include <CCPACSPressureBulkhead.h>
#include "CPACSPressureBulkheads.h"
#include "CPACSStructuralElements.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSPressureBulkheads::CPACSPressureBulkheads(CPACSStructuralElements* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSPressureBulkheads::~CPACSPressureBulkheads()
    {
    }

    const CPACSStructuralElements* CPACSPressureBulkheads::GetParent() const
    {
        return m_parent;
    }

    CPACSStructuralElements* CPACSPressureBulkheads::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSPressureBulkheads::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSPressureBulkheads::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSPressureBulkheads::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSPressureBulkheads::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSPressureBulkheads::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element pressureBulkhead
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/pressureBulkhead")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/pressureBulkhead", m_pressureBulkheads, 1, tixi::xsdUnbounded, reinterpret_cast<CCPACSPressureBulkheads*>(this), m_uidMgr);
        }

    }

    void CPACSPressureBulkheads::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element pressureBulkhead
        tixi::TixiSaveElements(tixiHandle, xpath + "/pressureBulkhead", m_pressureBulkheads);

    }

    const std::vector<std::unique_ptr<CCPACSPressureBulkhead>>& CPACSPressureBulkheads::GetPressureBulkheads() const
    {
        return m_pressureBulkheads;
    }

    std::vector<std::unique_ptr<CCPACSPressureBulkhead>>& CPACSPressureBulkheads::GetPressureBulkheads()
    {
        return m_pressureBulkheads;
    }

    CCPACSPressureBulkhead& CPACSPressureBulkheads::AddPressureBulkhead()
    {
        m_pressureBulkheads.push_back(make_unique<CCPACSPressureBulkhead>(reinterpret_cast<CCPACSPressureBulkheads*>(this), m_uidMgr));
        return *m_pressureBulkheads.back();
    }

    void CPACSPressureBulkheads::RemovePressureBulkhead(CCPACSPressureBulkhead& ref)
    {
        for (std::size_t i = 0; i < m_pressureBulkheads.size(); i++) {
            if (m_pressureBulkheads[i].get() == &ref) {
                m_pressureBulkheads.erase(m_pressureBulkheads.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
