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
#include "CPACSGuideCurveProfileGeometry.h"
#include "CPACSGuideCurveProfiles.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSGuideCurveProfileGeometry::CPACSGuideCurveProfileGeometry(CPACSGuideCurveProfiles* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_pointList(reinterpret_cast<CCPACSGuideCurveProfile*>(this))
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSGuideCurveProfileGeometry::~CPACSGuideCurveProfileGeometry()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CPACSGuideCurveProfiles* CPACSGuideCurveProfileGeometry::GetParent() const
    {
        return m_parent;
    }

    CPACSGuideCurveProfiles* CPACSGuideCurveProfileGeometry::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSGuideCurveProfileGeometry::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSGuideCurveProfileGeometry::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSGuideCurveProfileGeometry::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSGuideCurveProfileGeometry::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSGuideCurveProfileGeometry::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute symmetry
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
            m_symmetry = stringToTiglSymmetryAxis(tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "symmetry"));
        }

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

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSGuideCurveProfileGeometry::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute symmetry
        if (m_symmetry) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "symmetry", TiglSymmetryAxisToString(*m_symmetry));
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "symmetry");
            }
        }

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

    }

    const boost::optional<TiglSymmetryAxis>& CPACSGuideCurveProfileGeometry::GetSymmetry() const
    {
        return m_symmetry;
    }

    void CPACSGuideCurveProfileGeometry::SetSymmetry(const boost::optional<TiglSymmetryAxis>& value)
    {
        m_symmetry = value;
    }

    const std::string& CPACSGuideCurveProfileGeometry::GetUID() const
    {
        return m_uID;
    }

    void CPACSGuideCurveProfileGeometry::SetUID(const std::string& value)
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

    const std::string& CPACSGuideCurveProfileGeometry::GetName() const
    {
        return m_name;
    }

    void CPACSGuideCurveProfileGeometry::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSGuideCurveProfileGeometry::GetDescription() const
    {
        return m_description;
    }

    void CPACSGuideCurveProfileGeometry::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const CCPACSPointListRelXYZVector& CPACSGuideCurveProfileGeometry::GetPointList() const
    {
        return m_pointList;
    }

    CCPACSPointListRelXYZVector& CPACSGuideCurveProfileGeometry::GetPointList()
    {
        return m_pointList;
    }

} // namespace generated
} // namespace tigl
