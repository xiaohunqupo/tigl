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
#include "CCPACSWingRibCrossSection.h"
#include "CPACSPointX.h"
#include "CPACSWingRibCell.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSPointX::CPACSPointX(CPACSWingRibCell* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_x(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CPACSWingRibCell);
    }

    CPACSPointX::CPACSPointX(CCPACSWingRibCrossSection* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_x(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSWingRibCrossSection);
    }

    CPACSPointX::~CPACSPointX()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CTiglUIDObject* CPACSPointX::GetNextUIDParent() const
    {
        if (IsParent<CPACSWingRibCell>()) {
            return GetParent<CPACSWingRibCell>();
        }
        if (IsParent<CCPACSWingRibCrossSection>()) {
            return GetParent<CCPACSWingRibCrossSection>()->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSPointX::GetNextUIDParent()
    {
        if (IsParent<CPACSWingRibCell>()) {
            return GetParent<CPACSWingRibCell>();
        }
        if (IsParent<CCPACSWingRibCrossSection>()) {
            return GetParent<CCPACSWingRibCrossSection>()->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSPointX::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSPointX::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSPointX::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read element x
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/x")) {
            m_x = tixi::TixiGetElement<double>(tixiHandle, xpath + "/x");
        }
        else {
            LOG(ERROR) << "Required element x is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSPointX::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element x
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/x");
        tixi::TixiSaveElement(tixiHandle, xpath + "/x", m_x);

    }

    const std::string& CPACSPointX::GetUID() const
    {
        return m_uID;
    }

    void CPACSPointX::SetUID(const std::string& value)
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

    const double& CPACSPointX::GetX() const
    {
        return m_x;
    }

    void CPACSPointX::SetX(const double& value)
    {
        m_x = value;
    }

} // namespace generated
} // namespace tigl
