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
#include "CCPACSPointListXY.h"
#include "CPACSGlobalBeamProperties.h"
#include "CPACSPointXY.h"
#include "CPACSSheet.h"
#include "CPACSTransformation2D.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSPointXY::CPACSPointXY(CPACSGlobalBeamProperties* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_x(0)
        , m_y(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CPACSGlobalBeamProperties);
    }

    CPACSPointXY::CPACSPointXY(CCPACSPointListXY* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_x(0)
        , m_y(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSPointListXY);
    }

    CPACSPointXY::CPACSPointXY(CPACSSheet* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_x(0)
        , m_y(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CPACSSheet);
    }

    CPACSPointXY::CPACSPointXY(CPACSTransformation2D* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_x(0)
        , m_y(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CPACSTransformation2D);
    }

    CPACSPointXY::~CPACSPointXY()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CTiglUIDObject* CPACSPointXY::GetNextUIDParent() const
    {
        if (IsParent<CPACSGlobalBeamProperties>()) {
            return GetParent<CPACSGlobalBeamProperties>();
        }
        if (IsParent<CCPACSPointListXY>()) {
            return GetParent<CCPACSPointListXY>()->GetNextUIDParent();
        }
        if (IsParent<CPACSSheet>()) {
            return GetParent<CPACSSheet>();
        }
        if (IsParent<CPACSTransformation2D>()) {
            return GetParent<CPACSTransformation2D>();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSPointXY::GetNextUIDParent()
    {
        if (IsParent<CPACSGlobalBeamProperties>()) {
            return GetParent<CPACSGlobalBeamProperties>();
        }
        if (IsParent<CCPACSPointListXY>()) {
            return GetParent<CCPACSPointListXY>()->GetNextUIDParent();
        }
        if (IsParent<CPACSSheet>()) {
            return GetParent<CPACSSheet>();
        }
        if (IsParent<CPACSTransformation2D>()) {
            return GetParent<CPACSTransformation2D>();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSPointXY::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSPointXY::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSPointXY::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read element y
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/y")) {
            m_y = tixi::TixiGetElement<double>(tixiHandle, xpath + "/y");
        }
        else {
            LOG(ERROR) << "Required element y is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSPointXY::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "x", "y" };

        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element x
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/x", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/x", m_x);

        // write element y
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/y", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/y", m_y);

    }

    const std::string& CPACSPointXY::GetUID() const
    {
        return m_uID;
    }

    void CPACSPointXY::SetUID(const std::string& value)
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

    const double& CPACSPointXY::GetX() const
    {
        return m_x;
    }

    void CPACSPointXY::SetX(const double& value)
    {
        m_x = value;
    }

    const double& CPACSPointXY::GetY() const
    {
        return m_y;
    }

    void CPACSPointXY::SetY(const double& value)
    {
        m_y = value;
    }

} // namespace generated
} // namespace tigl
