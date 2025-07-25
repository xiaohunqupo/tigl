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
#include "CPACSDoorCutOut.h"
#include "CPACSDoors.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSDoorCutOut::CPACSDoorCutOut(CPACSDoors* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSDoorCutOut::~CPACSDoorCutOut()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        if (m_uidMgr) {
            if (m_dssDesignUID && !m_dssDesignUID->empty()) m_uidMgr->TryUnregisterReference(*m_dssDesignUID, *this);
        }
    }

    const CPACSDoors* CPACSDoorCutOut::GetParent() const
    {
        return m_parent;
    }

    CPACSDoors* CPACSDoorCutOut::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSDoorCutOut::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSDoorCutOut::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSDoorCutOut::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSDoorCutOut::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSDoorCutOut::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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
            if (m_name->empty()) {
                LOG(WARNING) << "Optional element name is present but empty at xpath " << xpath;
            }
        }

        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }

        // read element filletRadius
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/filletRadius")) {
            m_filletRadius = tixi::TixiGetElement<double>(tixiHandle, xpath + "/filletRadius");
        }

        // read element dssDesignUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/dssDesignUID")) {
            m_dssDesignUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/dssDesignUID");
            if (m_dssDesignUID->empty()) {
                LOG(WARNING) << "Optional element dssDesignUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_dssDesignUID->empty()) m_uidMgr->RegisterReference(*m_dssDesignUID, *this);
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSDoorCutOut::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element name
        if (m_name) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
            tixi::TixiSaveElement(tixiHandle, xpath + "/name", *m_name);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/name");
            }
        }

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

        // write element filletRadius
        if (m_filletRadius) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/filletRadius");
            tixi::TixiSaveElement(tixiHandle, xpath + "/filletRadius", *m_filletRadius);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/filletRadius")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/filletRadius");
            }
        }

        // write element dssDesignUID
        if (m_dssDesignUID) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/dssDesignUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/dssDesignUID", *m_dssDesignUID);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/dssDesignUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/dssDesignUID");
            }
        }

    }

    const std::string& CPACSDoorCutOut::GetUID() const
    {
        return m_uID;
    }

    void CPACSDoorCutOut::SetUID(const std::string& value)
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

    const boost::optional<std::string>& CPACSDoorCutOut::GetName() const
    {
        return m_name;
    }

    void CPACSDoorCutOut::SetName(const boost::optional<std::string>& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSDoorCutOut::GetDescription() const
    {
        return m_description;
    }

    void CPACSDoorCutOut::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const boost::optional<double>& CPACSDoorCutOut::GetFilletRadius() const
    {
        return m_filletRadius;
    }

    void CPACSDoorCutOut::SetFilletRadius(const boost::optional<double>& value)
    {
        m_filletRadius = value;
    }

    const boost::optional<std::string>& CPACSDoorCutOut::GetDssDesignUID() const
    {
        return m_dssDesignUID;
    }

    void CPACSDoorCutOut::SetDssDesignUID(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_dssDesignUID && !m_dssDesignUID->empty()) m_uidMgr->TryUnregisterReference(*m_dssDesignUID, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_dssDesignUID = value;
    }

    const CTiglUIDObject* CPACSDoorCutOut::GetNextUIDObject() const
    {
        return this;
    }

    void CPACSDoorCutOut::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_dssDesignUID && *m_dssDesignUID == oldUid) {
            m_dssDesignUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl
