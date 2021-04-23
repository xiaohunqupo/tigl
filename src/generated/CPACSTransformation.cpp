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
#include "CCPACSEnginePosition.h"
#include "CCPACSEnginePylon.h"
#include "CCPACSExternalObject.h"
#include "CCPACSFuselage.h"
#include "CCPACSFuselageSection.h"
#include "CCPACSFuselageSectionElement.h"
#include "CCPACSGenericSystem.h"
#include "CCPACSNacelleSection.h"
#include "CCPACSRotor.h"
#include "CCPACSRotorHinge.h"
#include "CCPACSWing.h"
#include "CCPACSWingSection.h"
#include "CCPACSWingSectionElement.h"
#include "CPACSTransformation.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSTransformation::CPACSTransformation(CCPACSEnginePosition* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSEnginePosition);
    }

    CPACSTransformation::CPACSTransformation(CCPACSEnginePylon* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSEnginePylon);
    }

    CPACSTransformation::CPACSTransformation(CCPACSFuselage* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSFuselage);
    }

    CPACSTransformation::CPACSTransformation(CCPACSFuselageSectionElement* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSFuselageSectionElement);
    }

    CPACSTransformation::CPACSTransformation(CCPACSFuselageSection* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSFuselageSection);
    }

    CPACSTransformation::CPACSTransformation(CCPACSExternalObject* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSExternalObject);
    }

    CPACSTransformation::CPACSTransformation(CCPACSGenericSystem* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSGenericSystem);
    }

    CPACSTransformation::CPACSTransformation(CCPACSNacelleSection* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSNacelleSection);
    }

    CPACSTransformation::CPACSTransformation(CCPACSRotor* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSRotor);
    }

    CPACSTransformation::CPACSTransformation(CCPACSRotorHinge* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSRotorHinge);
    }

    CPACSTransformation::CPACSTransformation(CCPACSWing* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSWing);
    }

    CPACSTransformation::CPACSTransformation(CCPACSWingSectionElement* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSWingSectionElement);
    }

    CPACSTransformation::CPACSTransformation(CCPACSWingSection* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSWingSection);
    }

    CPACSTransformation::~CPACSTransformation()
    {
        if (m_uidMgr && m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
    }

    const CTiglUIDObject* CPACSTransformation::GetNextUIDParent() const
    {
        if (m_parent) {
            if (IsParent<CCPACSEnginePosition>()) {
                return GetParent<CCPACSEnginePosition>();
            }
            if (IsParent<CCPACSEnginePylon>()) {
                return GetParent<CCPACSEnginePylon>();
            }
            if (IsParent<CCPACSFuselage>()) {
                return GetParent<CCPACSFuselage>();
            }
            if (IsParent<CCPACSFuselageSectionElement>()) {
                return GetParent<CCPACSFuselageSectionElement>();
            }
            if (IsParent<CCPACSFuselageSection>()) {
                return GetParent<CCPACSFuselageSection>();
            }
            if (IsParent<CCPACSExternalObject>()) {
                return GetParent<CCPACSExternalObject>();
            }
            if (IsParent<CCPACSGenericSystem>()) {
                return GetParent<CCPACSGenericSystem>();
            }
            if (IsParent<CCPACSNacelleSection>()) {
                return GetParent<CCPACSNacelleSection>();
            }
            if (IsParent<CCPACSRotor>()) {
                return GetParent<CCPACSRotor>();
            }
            if (IsParent<CCPACSRotorHinge>()) {
                return GetParent<CCPACSRotorHinge>();
            }
            if (IsParent<CCPACSWing>()) {
                return GetParent<CCPACSWing>();
            }
            if (IsParent<CCPACSWingSectionElement>()) {
                return GetParent<CCPACSWingSectionElement>();
            }
            if (IsParent<CCPACSWingSection>()) {
                return GetParent<CCPACSWingSection>();
            }
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSTransformation::GetNextUIDParent()
    {
        if (m_parent) {
            if (IsParent<CCPACSEnginePosition>()) {
                return GetParent<CCPACSEnginePosition>();
            }
            if (IsParent<CCPACSEnginePylon>()) {
                return GetParent<CCPACSEnginePylon>();
            }
            if (IsParent<CCPACSFuselage>()) {
                return GetParent<CCPACSFuselage>();
            }
            if (IsParent<CCPACSFuselageSectionElement>()) {
                return GetParent<CCPACSFuselageSectionElement>();
            }
            if (IsParent<CCPACSFuselageSection>()) {
                return GetParent<CCPACSFuselageSection>();
            }
            if (IsParent<CCPACSExternalObject>()) {
                return GetParent<CCPACSExternalObject>();
            }
            if (IsParent<CCPACSGenericSystem>()) {
                return GetParent<CCPACSGenericSystem>();
            }
            if (IsParent<CCPACSNacelleSection>()) {
                return GetParent<CCPACSNacelleSection>();
            }
            if (IsParent<CCPACSRotor>()) {
                return GetParent<CCPACSRotor>();
            }
            if (IsParent<CCPACSRotorHinge>()) {
                return GetParent<CCPACSRotorHinge>();
            }
            if (IsParent<CCPACSWing>()) {
                return GetParent<CCPACSWing>();
            }
            if (IsParent<CCPACSWingSectionElement>()) {
                return GetParent<CCPACSWingSectionElement>();
            }
            if (IsParent<CCPACSWingSection>()) {
                return GetParent<CCPACSWingSection>();
            }
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSTransformation::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSTransformation::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSTransformation::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID->empty()) {
                LOG(WARNING) << "Optional attribute uID is present but empty at xpath " << xpath;
            }
        }

        // read element scaling
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/scaling")) {
            m_scaling = boost::in_place(reinterpret_cast<CCPACSTransformation*>(this), m_uidMgr);
            try {
                m_scaling->ReadCPACS(tixiHandle, xpath + "/scaling");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read scaling at xpath " << xpath << ": " << e.what();
                m_scaling = boost::none;
            }
        }

        // read element rotation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotation")) {
            m_rotation = boost::in_place(reinterpret_cast<CCPACSTransformation*>(this), m_uidMgr);
            try {
                m_rotation->ReadCPACS(tixiHandle, xpath + "/rotation");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read rotation at xpath " << xpath << ": " << e.what();
                m_rotation = boost::none;
            }
        }

        // read element translation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/translation")) {
            m_translation = boost::in_place(reinterpret_cast<CCPACSTransformation*>(this), m_uidMgr);
            try {
                m_translation->ReadCPACS(tixiHandle, xpath + "/translation");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read translation at xpath " << xpath << ": " << e.what();
                m_translation = boost::none;
            }
        }

        if (m_uidMgr && m_uID) m_uidMgr->RegisterObject(*m_uID, *this);
    }

    void CPACSTransformation::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        if (m_uID) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "uID");
            }
        }

        // write element scaling
        if (m_scaling) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/scaling");
            m_scaling->WriteCPACS(tixiHandle, xpath + "/scaling");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/scaling")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/scaling");
            }
        }

        // write element rotation
        if (m_rotation) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotation");
            m_rotation->WriteCPACS(tixiHandle, xpath + "/rotation");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotation")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/rotation");
            }
        }

        // write element translation
        if (m_translation) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/translation");
            m_translation->WriteCPACS(tixiHandle, xpath + "/translation");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/translation")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/translation");
            }
        }

    }

    const boost::optional<std::string>& CPACSTransformation::GetUID() const
    {
        return m_uID;
    }

    void CPACSTransformation::SetUID(const boost::optional<std::string>& value)
    {
        if (m_uidMgr && value != m_uID) {
            if (!m_uID && value) {
                m_uidMgr->RegisterObject(*value, *this);
            }
            else if (m_uID && !value) {
                m_uidMgr->TryUnregisterObject(*m_uID);
            }
            else if (m_uID && value) {
                m_uidMgr->UpdateObjectUID(*m_uID, *value);
            }
        }
        m_uID = value;
    }

    const boost::optional<CCPACSPoint>& CPACSTransformation::GetScaling() const
    {
        return m_scaling;
    }

    boost::optional<CCPACSPoint>& CPACSTransformation::GetScaling()
    {
        return m_scaling;
    }

    const boost::optional<CCPACSPoint>& CPACSTransformation::GetRotation() const
    {
        return m_rotation;
    }

    boost::optional<CCPACSPoint>& CPACSTransformation::GetRotation()
    {
        return m_rotation;
    }

    const boost::optional<CCPACSPointAbsRel>& CPACSTransformation::GetTranslation() const
    {
        return m_translation;
    }

    boost::optional<CCPACSPointAbsRel>& CPACSTransformation::GetTranslation()
    {
        return m_translation;
    }

    CCPACSPoint& CPACSTransformation::GetScaling(CreateIfNotExistsTag)
    {
        if (!m_scaling)
            m_scaling = boost::in_place(reinterpret_cast<CCPACSTransformation*>(this), m_uidMgr);
        return *m_scaling;
    }

    void CPACSTransformation::RemoveScaling()
    {
        m_scaling = boost::none;
    }

    CCPACSPoint& CPACSTransformation::GetRotation(CreateIfNotExistsTag)
    {
        if (!m_rotation)
            m_rotation = boost::in_place(reinterpret_cast<CCPACSTransformation*>(this), m_uidMgr);
        return *m_rotation;
    }

    void CPACSTransformation::RemoveRotation()
    {
        m_rotation = boost::none;
    }

    CCPACSPointAbsRel& CPACSTransformation::GetTranslation(CreateIfNotExistsTag)
    {
        if (!m_translation)
            m_translation = boost::in_place(reinterpret_cast<CCPACSTransformation*>(this), m_uidMgr);
        return *m_translation;
    }

    void CPACSTransformation::RemoveTranslation()
    {
        m_translation = boost::none;
    }

} // namespace generated
} // namespace tigl
