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
#include "CCPACSStructuralProfiles.h"
#include "CPACSStructuralProfile3D.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSStructuralProfile3D::CPACSStructuralProfile3D(CCPACSStructuralProfiles* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_pointList(this, m_uidMgr)
        , m_sheetList3D(this, m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSStructuralProfile3D::~CPACSStructuralProfile3D()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CCPACSStructuralProfiles* CPACSStructuralProfile3D::GetParent() const
    {
        return m_parent;
    }

    CCPACSStructuralProfiles* CPACSStructuralProfile3D::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSStructuralProfile3D::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSStructuralProfile3D::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSStructuralProfile3D::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSStructuralProfile3D::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSStructuralProfile3D::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name.empty()) {
                LOG(WARNING) << "Required element name is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element name is missing at xpath " << xpath;
        }

        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }

        // read element pointList
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/pointList")) {
            m_pointList.ReadCPACS(tixiHandle, xpath + "/pointList");
        }
        else {
            LOG(ERROR) << "Required element pointList is missing at xpath " << xpath;
        }

        // read element sheetList3D
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sheetList3D")) {
            m_sheetList3D.ReadCPACS(tixiHandle, xpath + "/sheetList3D");
        }
        else {
            LOG(ERROR) << "Required element sheetList3D is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSStructuralProfile3D::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element name
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element pointList
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/pointList");
        m_pointList.WriteCPACS(tixiHandle, xpath + "/pointList");

        // write element sheetList3D
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sheetList3D");
        m_sheetList3D.WriteCPACS(tixiHandle, xpath + "/sheetList3D");

    }

    const std::string& CPACSStructuralProfile3D::GetUID() const
    {
        return m_uID;
    }

    void CPACSStructuralProfile3D::SetUID(const std::string& value)
    {
        if (m_uidMgr && value != m_uID) {
            if (m_uID.empty()) {
                m_uidMgr->RegisterObject(value, *this);
            }
            else {
                m_uidMgr->UpdateObjectUID(m_uID, value);
            }
        }
        m_uID = value;
    }

    const std::string& CPACSStructuralProfile3D::GetName() const
    {
        return m_name;
    }

    void CPACSStructuralProfile3D::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSStructuralProfile3D::GetDescription() const
    {
        return m_description;
    }

    void CPACSStructuralProfile3D::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const CPACSPointList& CPACSStructuralProfile3D::GetPointList() const
    {
        return m_pointList;
    }

    CPACSPointList& CPACSStructuralProfile3D::GetPointList()
    {
        return m_pointList;
    }

    const CPACSSheetList3D& CPACSStructuralProfile3D::GetSheetList3D() const
    {
        return m_sheetList3D;
    }

    CPACSSheetList3D& CPACSStructuralProfile3D::GetSheetList3D()
    {
        return m_sheetList3D;
    }

} // namespace generated
} // namespace tigl
