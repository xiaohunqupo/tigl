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
#include "CPACSProfiles.h"
#include "CPACSStructuralProfile.h"
#include "CPACSStructuralProfile3D.h"
#include "CPACSStructuralProfiles.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSStructuralProfiles::CPACSStructuralProfiles(CPACSProfiles* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSStructuralProfiles::~CPACSStructuralProfiles()
    {
    }

    const CPACSProfiles* CPACSStructuralProfiles::GetParent() const
    {
        return m_parent;
    }

    CPACSProfiles* CPACSStructuralProfiles::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSStructuralProfiles::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSStructuralProfiles::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSStructuralProfiles::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSStructuralProfiles::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSStructuralProfiles::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element structuralProfile2D
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralProfile2D")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/structuralProfile2D", m_structuralProfile2Ds, 0, tixi::xsdUnbounded, this, m_uidMgr);
        }

        // read element structuralProfile3D
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralProfile3D")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/structuralProfile3D", m_structuralProfile3Ds, 0, tixi::xsdUnbounded, this, m_uidMgr);
        }

    }

    void CPACSStructuralProfiles::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "structuralProfile2D", "structuralProfile3D" };

        // write element structuralProfile2D
        tixi::TixiSaveElements(tixiHandle, xpath + "/structuralProfile2D", m_structuralProfile2Ds);

        // write element structuralProfile3D
        tixi::TixiSaveElements(tixiHandle, xpath + "/structuralProfile3D", m_structuralProfile3Ds);

    }

    const std::vector<std::unique_ptr<CPACSStructuralProfile>>& CPACSStructuralProfiles::GetStructuralProfile2Ds() const
    {
        return m_structuralProfile2Ds;
    }

    std::vector<std::unique_ptr<CPACSStructuralProfile>>& CPACSStructuralProfiles::GetStructuralProfile2Ds()
    {
        return m_structuralProfile2Ds;
    }

    size_t CPACSStructuralProfiles::GetStructuralProfile2DCount() const
    {
        return m_structuralProfile2Ds.size();
    }

    size_t CPACSStructuralProfiles::GetStructuralProfile2DIndex(const std::string& UID) const
    {
        for (size_t i=0; i < GetStructuralProfile2DCount(); i++) {
            const std::string tmpUID(m_structuralProfile2Ds[i]->GetUID());
            if (tmpUID == UID) {
                return i+1;
            }
        }
        throw CTiglError("Invalid UID in CPACSStructuralProfiles::GetStructuralProfile2DIndex", TIGL_UID_ERROR);
    }

    CPACSStructuralProfile& CPACSStructuralProfiles::GetStructuralProfile2D(size_t index)
    {
        if (index < 1 || index > GetStructuralProfile2DCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSStructuralProfile>>::GetStructuralProfile2D", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_structuralProfile2Ds[index];
    }

    const CPACSStructuralProfile& CPACSStructuralProfiles::GetStructuralProfile2D(size_t index) const
    {
        if (index < 1 || index > GetStructuralProfile2DCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSStructuralProfile>>::GetStructuralProfile2D", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_structuralProfile2Ds[index];
    }

    CPACSStructuralProfile& CPACSStructuralProfiles::GetStructuralProfile2D(const std::string& UID)
    {
        for (auto& elem : m_structuralProfile2Ds ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSStructuralProfiles::GetStructuralProfile2D. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }

    const CPACSStructuralProfile& CPACSStructuralProfiles::GetStructuralProfile2D(const std::string& UID) const
    {
        for (auto& elem : m_structuralProfile2Ds ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSStructuralProfiles::GetStructuralProfile2D. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }


    const std::vector<std::unique_ptr<CPACSStructuralProfile3D>>& CPACSStructuralProfiles::GetStructuralProfile3Ds() const
    {
        return m_structuralProfile3Ds;
    }

    std::vector<std::unique_ptr<CPACSStructuralProfile3D>>& CPACSStructuralProfiles::GetStructuralProfile3Ds()
    {
        return m_structuralProfile3Ds;
    }

    size_t CPACSStructuralProfiles::GetStructuralProfile3DCount() const
    {
        return m_structuralProfile3Ds.size();
    }

    size_t CPACSStructuralProfiles::GetStructuralProfile3DIndex(const std::string& UID) const
    {
        for (size_t i=0; i < GetStructuralProfile3DCount(); i++) {
            const std::string tmpUID(m_structuralProfile3Ds[i]->GetUID());
            if (tmpUID == UID) {
                return i+1;
            }
        }
        throw CTiglError("Invalid UID in CPACSStructuralProfiles::GetStructuralProfile3DIndex", TIGL_UID_ERROR);
    }

    CPACSStructuralProfile3D& CPACSStructuralProfiles::GetStructuralProfile3D(size_t index)
    {
        if (index < 1 || index > GetStructuralProfile3DCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSStructuralProfile3D>>::GetStructuralProfile3D", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_structuralProfile3Ds[index];
    }

    const CPACSStructuralProfile3D& CPACSStructuralProfiles::GetStructuralProfile3D(size_t index) const
    {
        if (index < 1 || index > GetStructuralProfile3DCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSStructuralProfile3D>>::GetStructuralProfile3D", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_structuralProfile3Ds[index];
    }

    CPACSStructuralProfile3D& CPACSStructuralProfiles::GetStructuralProfile3D(const std::string& UID)
    {
        for (auto& elem : m_structuralProfile3Ds ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSStructuralProfiles::GetStructuralProfile3D. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }

    const CPACSStructuralProfile3D& CPACSStructuralProfiles::GetStructuralProfile3D(const std::string& UID) const
    {
        for (auto& elem : m_structuralProfile3Ds ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSStructuralProfiles::GetStructuralProfile3D. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }


    CPACSStructuralProfile& CPACSStructuralProfiles::AddStructuralProfile2D()
    {
        m_structuralProfile2Ds.push_back(make_unique<CPACSStructuralProfile>(this, m_uidMgr));
        return *m_structuralProfile2Ds.back();
    }

    void CPACSStructuralProfiles::RemoveStructuralProfile2D(CPACSStructuralProfile& ref)
    {
        for (std::size_t i = 0; i < m_structuralProfile2Ds.size(); i++) {
            if (m_structuralProfile2Ds[i].get() == &ref) {
                m_structuralProfile2Ds.erase(m_structuralProfile2Ds.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

    CPACSStructuralProfile3D& CPACSStructuralProfiles::AddStructuralProfile3D()
    {
        m_structuralProfile3Ds.push_back(make_unique<CPACSStructuralProfile3D>(this, m_uidMgr));
        return *m_structuralProfile3Ds.back();
    }

    void CPACSStructuralProfiles::RemoveStructuralProfile3D(CPACSStructuralProfile3D& ref)
    {
        for (std::size_t i = 0; i < m_structuralProfile3Ds.size(); i++) {
            if (m_structuralProfile3Ds[i].get() == &ref) {
                m_structuralProfile3Ds.erase(m_structuralProfile3Ds.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
