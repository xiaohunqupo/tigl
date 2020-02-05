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
#include "CCPACSWingSparSegment.h"
#include "CPACSSparCrossSection.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSparCrossSection::CPACSSparCrossSection(CCPACSWingSparSegment* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_web1(this, m_uidMgr)
        , m_rotation(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSSparCrossSection::~CPACSSparCrossSection()
    {
    }

    const CCPACSWingSparSegment* CPACSSparCrossSection::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingSparSegment* CPACSSparCrossSection::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSSparCrossSection::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSSparCrossSection::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSSparCrossSection::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSSparCrossSection::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSSparCrossSection::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element upperCap
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/upperCap")) {
            m_upperCap = boost::in_place(this, m_uidMgr);
            try {
                m_upperCap->ReadCPACS(tixiHandle, xpath + "/upperCap");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read upperCap at xpath " << xpath << ": " << e.what();
                m_upperCap = boost::none;
            }
        }

        // read element lowerCap
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/lowerCap")) {
            m_lowerCap = boost::in_place(this, m_uidMgr);
            try {
                m_lowerCap->ReadCPACS(tixiHandle, xpath + "/lowerCap");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read lowerCap at xpath " << xpath << ": " << e.what();
                m_lowerCap = boost::none;
            }
        }

        // read element web1
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/web1")) {
            m_web1.ReadCPACS(tixiHandle, xpath + "/web1");
        }
        else {
            LOG(ERROR) << "Required element web1 is missing at xpath " << xpath;
        }

        // read element web2
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/web2")) {
            m_web2 = boost::in_place(this, m_uidMgr);
            try {
                m_web2->ReadCPACS(tixiHandle, xpath + "/web2");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read web2 at xpath " << xpath << ": " << e.what();
                m_web2 = boost::none;
            }
        }

        // read element sparCells
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparCells")) {
            m_sparCells = boost::in_place(this, m_uidMgr);
            try {
                m_sparCells->ReadCPACS(tixiHandle, xpath + "/sparCells");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read sparCells at xpath " << xpath << ": " << e.what();
                m_sparCells = boost::none;
            }
        }

        // read element rotation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotation")) {
            m_rotation = tixi::TixiGetElement<double>(tixiHandle, xpath + "/rotation");
        }
        else {
            LOG(ERROR) << "Required element rotation is missing at xpath " << xpath;
        }

    }

    void CPACSSparCrossSection::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element upperCap
        if (m_upperCap) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/upperCap");
            m_upperCap->WriteCPACS(tixiHandle, xpath + "/upperCap");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/upperCap")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/upperCap");
            }
        }

        // write element lowerCap
        if (m_lowerCap) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/lowerCap");
            m_lowerCap->WriteCPACS(tixiHandle, xpath + "/lowerCap");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/lowerCap")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/lowerCap");
            }
        }

        // write element web1
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/web1");
        m_web1.WriteCPACS(tixiHandle, xpath + "/web1");

        // write element web2
        if (m_web2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/web2");
            m_web2->WriteCPACS(tixiHandle, xpath + "/web2");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/web2")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/web2");
            }
        }

        // write element sparCells
        if (m_sparCells) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/sparCells");
            m_sparCells->WriteCPACS(tixiHandle, xpath + "/sparCells");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparCells")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/sparCells");
            }
        }

        // write element rotation
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotation");
        tixi::TixiSaveElement(tixiHandle, xpath + "/rotation", m_rotation);

    }

    const boost::optional<CPACSCap>& CPACSSparCrossSection::GetUpperCap() const
    {
        return m_upperCap;
    }

    boost::optional<CPACSCap>& CPACSSparCrossSection::GetUpperCap()
    {
        return m_upperCap;
    }

    const boost::optional<CPACSCap>& CPACSSparCrossSection::GetLowerCap() const
    {
        return m_lowerCap;
    }

    boost::optional<CPACSCap>& CPACSSparCrossSection::GetLowerCap()
    {
        return m_lowerCap;
    }

    const CPACSWeb& CPACSSparCrossSection::GetWeb1() const
    {
        return m_web1;
    }

    CPACSWeb& CPACSSparCrossSection::GetWeb1()
    {
        return m_web1;
    }

    const boost::optional<CPACSWeb>& CPACSSparCrossSection::GetWeb2() const
    {
        return m_web2;
    }

    boost::optional<CPACSWeb>& CPACSSparCrossSection::GetWeb2()
    {
        return m_web2;
    }

    const boost::optional<CPACSSparCells>& CPACSSparCrossSection::GetSparCells() const
    {
        return m_sparCells;
    }

    boost::optional<CPACSSparCells>& CPACSSparCrossSection::GetSparCells()
    {
        return m_sparCells;
    }

    const double& CPACSSparCrossSection::GetRotation() const
    {
        return m_rotation;
    }

    void CPACSSparCrossSection::SetRotation(const double& value)
    {
        m_rotation = value;
    }

    CPACSCap& CPACSSparCrossSection::GetUpperCap(CreateIfNotExistsTag)
    {
        if (!m_upperCap)
            m_upperCap = boost::in_place(this, m_uidMgr);
        return *m_upperCap;
    }

    void CPACSSparCrossSection::RemoveUpperCap()
    {
        m_upperCap = boost::none;
    }

    CPACSCap& CPACSSparCrossSection::GetLowerCap(CreateIfNotExistsTag)
    {
        if (!m_lowerCap)
            m_lowerCap = boost::in_place(this, m_uidMgr);
        return *m_lowerCap;
    }

    void CPACSSparCrossSection::RemoveLowerCap()
    {
        m_lowerCap = boost::none;
    }

    CPACSWeb& CPACSSparCrossSection::GetWeb2(CreateIfNotExistsTag)
    {
        if (!m_web2)
            m_web2 = boost::in_place(this, m_uidMgr);
        return *m_web2;
    }

    void CPACSSparCrossSection::RemoveWeb2()
    {
        m_web2 = boost::none;
    }

    CPACSSparCells& CPACSSparCrossSection::GetSparCells(CreateIfNotExistsTag)
    {
        if (!m_sparCells)
            m_sparCells = boost::in_place(this, m_uidMgr);
        return *m_sparCells;
    }

    void CPACSSparCrossSection::RemoveSparCells()
    {
        m_sparCells = boost::none;
    }

} // namespace generated
} // namespace tigl
