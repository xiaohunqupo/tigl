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
#include <CCPACSFuselageStringer.h>
#include "CCPACSDuctStructure.h"
#include "CCPACSFuselageStructure.h"
#include "CCPACSVesselStructure.h"
#include "CPACSStringersAssembly.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSStringersAssembly::CPACSStringersAssembly(CCPACSDuctStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSDuctStructure);
    }

    CPACSStringersAssembly::CPACSStringersAssembly(CCPACSFuselageStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSFuselageStructure);
    }

    CPACSStringersAssembly::CPACSStringersAssembly(CCPACSVesselStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSVesselStructure);
    }

    CPACSStringersAssembly::~CPACSStringersAssembly()
    {
    }

    const CTiglUIDObject* CPACSStringersAssembly::GetNextUIDParent() const
    {
        if (m_parent) {
            if (IsParent<CCPACSDuctStructure>()) {
                return GetParent<CCPACSDuctStructure>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSFuselageStructure>()) {
                return GetParent<CCPACSFuselageStructure>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSVesselStructure>()) {
                return GetParent<CCPACSVesselStructure>()->GetNextUIDParent();
            }
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSStringersAssembly::GetNextUIDParent()
    {
        if (m_parent) {
            if (IsParent<CCPACSDuctStructure>()) {
                return GetParent<CCPACSDuctStructure>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSFuselageStructure>()) {
                return GetParent<CCPACSFuselageStructure>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSVesselStructure>()) {
                return GetParent<CCPACSVesselStructure>()->GetNextUIDParent();
            }
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSStringersAssembly::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSStringersAssembly::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSStringersAssembly::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element stringer
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/stringer")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/stringer", m_stringers, 1, tixi::xsdUnbounded, reinterpret_cast<CCPACSStringersAssembly*>(this), m_uidMgr);
        }

    }

    void CPACSStringersAssembly::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element stringer
        tixi::TixiSaveElements(tixiHandle, xpath + "/stringer", m_stringers);

    }

    const std::vector<std::unique_ptr<CCPACSFuselageStringer>>& CPACSStringersAssembly::GetStringers() const
    {
        return m_stringers;
    }

    std::vector<std::unique_ptr<CCPACSFuselageStringer>>& CPACSStringersAssembly::GetStringers()
    {
        return m_stringers;
    }

    size_t CPACSStringersAssembly::GetStringerCount() const
    {
        return m_stringers.size();
    }

    size_t CPACSStringersAssembly::GetStringerIndex(const std::string& UID) const
    {
        for (size_t i=0; i < GetStringerCount(); i++) {
            const std::string tmpUID(m_stringers[i]->GetUID());
            if (tmpUID == UID) {
                return i+1;
            }
        }
        throw CTiglError("Invalid UID in CPACSStringersAssembly::GetStringerIndex", TIGL_UID_ERROR);
    }

    CCPACSFuselageStringer& CPACSStringersAssembly::GetStringer(size_t index)
    {
        if (index < 1 || index > GetStringerCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CCPACSFuselageStringer>>::GetStringer", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_stringers[index];
    }

    const CCPACSFuselageStringer& CPACSStringersAssembly::GetStringer(size_t index) const
    {
        if (index < 1 || index > GetStringerCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CCPACSFuselageStringer>>::GetStringer", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_stringers[index];
    }

    CCPACSFuselageStringer& CPACSStringersAssembly::GetStringer(const std::string& UID)
    {
        for (auto& elem : m_stringers ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSStringersAssembly::GetStringer. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }

    const CCPACSFuselageStringer& CPACSStringersAssembly::GetStringer(const std::string& UID) const
    {
        for (auto& elem : m_stringers ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSStringersAssembly::GetStringer. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }


    CCPACSFuselageStringer& CPACSStringersAssembly::AddStringer()
    {
        m_stringers.push_back(make_unique<CCPACSFuselageStringer>(reinterpret_cast<CCPACSStringersAssembly*>(this), m_uidMgr));
        return *m_stringers.back();
    }

    void CPACSStringersAssembly::RemoveStringer(CCPACSFuselageStringer& ref)
    {
        for (std::size_t i = 0; i < m_stringers.size(); i++) {
            if (m_stringers[i].get() == &ref) {
                m_stringers.erase(m_stringers.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
