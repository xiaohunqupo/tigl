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
#include "CCPACSProfileBasedStructuralElement.h"
#include "CPACSTransformation2D.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSTransformation2D::CPACSTransformation2D(CCPACSProfileBasedStructuralElement* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSTransformation2D::~CPACSTransformation2D()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CCPACSProfileBasedStructuralElement* CPACSTransformation2D::GetParent() const
    {
        return m_parent;
    }

    CCPACSProfileBasedStructuralElement* CPACSTransformation2D::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSTransformation2D::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSTransformation2D::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSTransformation2D::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSTransformation2D::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSTransformation2D::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read element scaling
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/scaling")) {
            m_scaling = boost::in_place(this, m_uidMgr);
            try {
                m_scaling->ReadCPACS(tixiHandle, xpath + "/scaling");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read scaling at xpath " << xpath << ": " << e.what();
                m_scaling = boost::none;
            }
        }

        // read element rotation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotation")) {
            m_rotation = boost::in_place(this, m_uidMgr);
            try {
                m_rotation->ReadCPACS(tixiHandle, xpath + "/rotation");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read rotation at xpath " << xpath << ": " << e.what();
                m_rotation = boost::none;
            }
        }

        // read element translation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/translation")) {
            m_translation = boost::in_place(this, m_uidMgr);
            try {
                m_translation->ReadCPACS(tixiHandle, xpath + "/translation");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read translation at xpath " << xpath << ": " << e.what();
                m_translation = boost::none;
            }
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSTransformation2D::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "scaling", "rotation", "translation" };

        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element scaling
        if (m_scaling) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/scaling", childElemOrder);
            m_scaling->WriteCPACS(tixiHandle, xpath + "/scaling");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/scaling")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/scaling");
            }
        }

        // write element rotation
        if (m_rotation) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/rotation", childElemOrder);
            m_rotation->WriteCPACS(tixiHandle, xpath + "/rotation");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotation")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/rotation");
            }
        }

        // write element translation
        if (m_translation) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/translation", childElemOrder);
            m_translation->WriteCPACS(tixiHandle, xpath + "/translation");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/translation")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/translation");
            }
        }

    }

    const std::string& CPACSTransformation2D::GetUID() const
    {
        return m_uID;
    }

    void CPACSTransformation2D::SetUID(const std::string& value)
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

    const boost::optional<CCPACSPointXY>& CPACSTransformation2D::GetScaling() const
    {
        return m_scaling;
    }

    boost::optional<CCPACSPointXY>& CPACSTransformation2D::GetScaling()
    {
        return m_scaling;
    }

    const boost::optional<CPACSPointZ>& CPACSTransformation2D::GetRotation() const
    {
        return m_rotation;
    }

    boost::optional<CPACSPointZ>& CPACSTransformation2D::GetRotation()
    {
        return m_rotation;
    }

    const boost::optional<CCPACSPointXY>& CPACSTransformation2D::GetTranslation() const
    {
        return m_translation;
    }

    boost::optional<CCPACSPointXY>& CPACSTransformation2D::GetTranslation()
    {
        return m_translation;
    }

    CCPACSPointXY& CPACSTransformation2D::GetScaling(CreateIfNotExistsTag)
    {
        if (!m_scaling)
            m_scaling = boost::in_place(this, m_uidMgr);
        return *m_scaling;
    }

    void CPACSTransformation2D::RemoveScaling()
    {
        m_scaling = boost::none;
    }

    CPACSPointZ& CPACSTransformation2D::GetRotation(CreateIfNotExistsTag)
    {
        if (!m_rotation)
            m_rotation = boost::in_place(this, m_uidMgr);
        return *m_rotation;
    }

    void CPACSTransformation2D::RemoveRotation()
    {
        m_rotation = boost::none;
    }

    CCPACSPointXY& CPACSTransformation2D::GetTranslation(CreateIfNotExistsTag)
    {
        if (!m_translation)
            m_translation = boost::in_place(this, m_uidMgr);
        return *m_translation;
    }

    void CPACSTransformation2D::RemoveTranslation()
    {
        m_translation = boost::none;
    }

} // namespace generated
} // namespace tigl
