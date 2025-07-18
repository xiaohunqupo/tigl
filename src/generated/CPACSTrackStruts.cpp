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
#include "CPACSTrackStructure.h"
#include "CPACSTrackStrut.h"
#include "CPACSTrackStruts.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSTrackStruts::CPACSTrackStruts(CPACSTrackStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSTrackStruts::~CPACSTrackStruts()
    {
    }

    const CPACSTrackStructure* CPACSTrackStruts::GetParent() const
    {
        return m_parent;
    }

    CPACSTrackStructure* CPACSTrackStruts::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSTrackStruts::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSTrackStruts::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSTrackStruts::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSTrackStruts::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSTrackStruts::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element strut
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/strut")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/strut", m_struts, 1, tixi::xsdUnbounded, this, m_uidMgr);
        }

    }

    void CPACSTrackStruts::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element strut
        tixi::TixiSaveElements(tixiHandle, xpath + "/strut", m_struts);

    }

    const std::vector<std::unique_ptr<CPACSTrackStrut>>& CPACSTrackStruts::GetStruts() const
    {
        return m_struts;
    }

    std::vector<std::unique_ptr<CPACSTrackStrut>>& CPACSTrackStruts::GetStruts()
    {
        return m_struts;
    }

    size_t CPACSTrackStruts::GetStrutCount() const
    {
        return m_struts.size();
    }

    CPACSTrackStrut& CPACSTrackStruts::GetStrut(size_t index)
    {
        if (index < 1 || index > GetStrutCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSTrackStrut>>::GetStrut", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_struts[index];
    }

    const CPACSTrackStrut& CPACSTrackStruts::GetStrut(size_t index) const
    {
        if (index < 1 || index > GetStrutCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSTrackStrut>>::GetStrut", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_struts[index];
    }


    CPACSTrackStrut& CPACSTrackStruts::AddStrut()
    {
        m_struts.push_back(make_unique<CPACSTrackStrut>(this, m_uidMgr));
        return *m_struts.back();
    }

    void CPACSTrackStruts::RemoveStrut(CPACSTrackStrut& ref)
    {
        for (std::size_t i = 0; i < m_struts.size(); i++) {
            if (m_struts[i].get() == &ref) {
                m_struts.erase(m_struts.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
