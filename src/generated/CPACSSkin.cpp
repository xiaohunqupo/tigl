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
#include "CCPACSFuselageStructure.h"
#include "CPACSSkin.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSkin::CPACSSkin(CCPACSFuselageStructure* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSSkin::~CPACSSkin()
    {
        if (m_uidMgr) {
            if (m_standardSheetElementUID && !m_standardSheetElementUID->empty()) m_uidMgr->TryUnregisterReference(*m_standardSheetElementUID, *this);
        }
    }

    const CCPACSFuselageStructure* CPACSSkin::GetParent() const
    {
        return m_parent;
    }

    CCPACSFuselageStructure* CPACSSkin::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSSkin::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSSkin::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSSkin::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSSkin::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSSkin::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element standardSheetElementUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/standardSheetElementUID")) {
            m_standardSheetElementUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/standardSheetElementUID");
            if (m_standardSheetElementUID->empty()) {
                LOG(WARNING) << "Optional element standardSheetElementUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_standardSheetElementUID->empty()) m_uidMgr->RegisterReference(*m_standardSheetElementUID, *this);
        }

        // read element skinSegments
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/skinSegments")) {
            m_skinSegments = boost::in_place(this, m_uidMgr);
            try {
                m_skinSegments->ReadCPACS(tixiHandle, xpath + "/skinSegments");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read skinSegments at xpath " << xpath << ": " << e.what();
                m_skinSegments = boost::none;
            }
        }

    }

    void CPACSSkin::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element standardSheetElementUID
        if (m_standardSheetElementUID) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/standardSheetElementUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/standardSheetElementUID", *m_standardSheetElementUID);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/standardSheetElementUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/standardSheetElementUID");
            }
        }

        // write element skinSegments
        if (m_skinSegments) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/skinSegments");
            m_skinSegments->WriteCPACS(tixiHandle, xpath + "/skinSegments");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/skinSegments")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/skinSegments");
            }
        }

    }

    const boost::optional<std::string>& CPACSSkin::GetStandardSheetElementUID() const
    {
        return m_standardSheetElementUID;
    }

    void CPACSSkin::SetStandardSheetElementUID(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_standardSheetElementUID && !m_standardSheetElementUID->empty()) m_uidMgr->TryUnregisterReference(*m_standardSheetElementUID, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_standardSheetElementUID = value;
    }

    const boost::optional<CPACSSkinSegments>& CPACSSkin::GetSkinSegments() const
    {
        return m_skinSegments;
    }

    boost::optional<CPACSSkinSegments>& CPACSSkin::GetSkinSegments()
    {
        return m_skinSegments;
    }

    CPACSSkinSegments& CPACSSkin::GetSkinSegments(CreateIfNotExistsTag)
    {
        if (!m_skinSegments)
            m_skinSegments = boost::in_place(this, m_uidMgr);
        return *m_skinSegments;
    }

    void CPACSSkin::RemoveSkinSegments()
    {
        m_skinSegments = boost::none;
    }

    const CTiglUIDObject* CPACSSkin::GetNextUIDObject() const
    {
        return GetNextUIDParent();
    }

    void CPACSSkin::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_standardSheetElementUID && *m_standardSheetElementUID == oldUid) {
            m_standardSheetElementUID = newUid;
        }
    }

} // namespace generated
} // namespace tigl
