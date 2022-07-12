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
#include "CPACSControlSurfaceTrackType.h"
#include "CPACSTrackActuator.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSTrackActuator::CPACSTrackActuator(CPACSControlSurfaceTrackType* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_material(this, m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSTrackActuator::~CPACSTrackActuator()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
        if (m_uidMgr) {
            if (!m_actuatorUID.empty()) m_uidMgr->TryUnregisterReference(m_actuatorUID, *this);
        }
    }

    const CPACSControlSurfaceTrackType* CPACSTrackActuator::GetParent() const
    {
        return m_parent;
    }

    CPACSControlSurfaceTrackType* CPACSTrackActuator::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSTrackActuator::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSTrackActuator::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSTrackActuator::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSTrackActuator::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSTrackActuator::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read element actuatorUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/actuatorUID")) {
            m_actuatorUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/actuatorUID");
            if (m_actuatorUID.empty()) {
                LOG(WARNING) << "Required element actuatorUID is empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_actuatorUID.empty()) m_uidMgr->RegisterReference(m_actuatorUID, *this);
        }
        else {
            LOG(ERROR) << "Required element actuatorUID is missing at xpath " << xpath;
        }

        // read element material
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/material")) {
            m_material.ReadCPACS(tixiHandle, xpath + "/material");
        }
        else {
            LOG(ERROR) << "Required element material is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSTrackActuator::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element actuatorUID
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/actuatorUID");
        tixi::TixiSaveElement(tixiHandle, xpath + "/actuatorUID", m_actuatorUID);

        // write element material
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/material");
        m_material.WriteCPACS(tixiHandle, xpath + "/material");

    }

    const std::string& CPACSTrackActuator::GetUID() const
    {
        return m_uID;
    }

    void CPACSTrackActuator::SetUID(const std::string& value)
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

    const std::string& CPACSTrackActuator::GetActuatorUID() const
    {
        return m_actuatorUID;
    }

    void CPACSTrackActuator::SetActuatorUID(const std::string& value)
    {
        if (m_uidMgr) {
            if (!m_actuatorUID.empty()) m_uidMgr->TryUnregisterReference(m_actuatorUID, *this);
            if (!value.empty()) m_uidMgr->RegisterReference(value, *this);
        }
        m_actuatorUID = value;
    }

    const CCPACSMaterialDefinition& CPACSTrackActuator::GetMaterial() const
    {
        return m_material;
    }

    CCPACSMaterialDefinition& CPACSTrackActuator::GetMaterial()
    {
        return m_material;
    }

    const CTiglUIDObject* CPACSTrackActuator::GetNextUIDObject() const
    {
        return this;
    }

    void CPACSTrackActuator::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_actuatorUID == oldUid) {
            m_actuatorUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl
