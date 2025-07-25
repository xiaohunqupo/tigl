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
#include "CPACSRivet.h"
#include "CPACSRivets.h"
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
    CPACSRivets::CPACSRivets(CPACSStructuralElements* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSRivets::~CPACSRivets()
    {
    }

    const CPACSStructuralElements* CPACSRivets::GetParent() const
    {
        return m_parent;
    }

    CPACSStructuralElements* CPACSRivets::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSRivets::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSRivets::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSRivets::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSRivets::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSRivets::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element rivet
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rivet")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/rivet", m_rivets, 1, tixi::xsdUnbounded, this, m_uidMgr);
        }

    }

    void CPACSRivets::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element rivet
        tixi::TixiSaveElements(tixiHandle, xpath + "/rivet", m_rivets);

    }

    const std::vector<std::unique_ptr<CPACSRivet>>& CPACSRivets::GetRivets() const
    {
        return m_rivets;
    }

    std::vector<std::unique_ptr<CPACSRivet>>& CPACSRivets::GetRivets()
    {
        return m_rivets;
    }

    size_t CPACSRivets::GetRivetCount() const
    {
        return m_rivets.size();
    }

    size_t CPACSRivets::GetRivetIndex(const std::string& UID) const
    {
        for (size_t i=0; i < GetRivetCount(); i++) {
            const std::string tmpUID(m_rivets[i]->GetUID());
            if (tmpUID == UID) {
                return i+1;
            }
        }
        throw CTiglError("Invalid UID in CPACSRivets::GetRivetIndex", TIGL_UID_ERROR);
    }

    CPACSRivet& CPACSRivets::GetRivet(size_t index)
    {
        if (index < 1 || index > GetRivetCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSRivet>>::GetRivet", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_rivets[index];
    }

    const CPACSRivet& CPACSRivets::GetRivet(size_t index) const
    {
        if (index < 1 || index > GetRivetCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSRivet>>::GetRivet", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_rivets[index];
    }

    CPACSRivet& CPACSRivets::GetRivet(const std::string& UID)
    {
        for (auto& elem : m_rivets ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSRivets::GetRivet. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }

    const CPACSRivet& CPACSRivets::GetRivet(const std::string& UID) const
    {
        for (auto& elem : m_rivets ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSRivets::GetRivet. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }


    CPACSRivet& CPACSRivets::AddRivet()
    {
        m_rivets.push_back(make_unique<CPACSRivet>(this, m_uidMgr));
        return *m_rivets.back();
    }

    void CPACSRivets::RemoveRivet(CPACSRivet& ref)
    {
        for (std::size_t i = 0; i < m_rivets.size(); i++) {
            if (m_rivets[i].get() == &ref) {
                m_rivets.erase(m_rivets.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
