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
#include "CPACSCpacs.h"
#include "CPACSVehicles.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSVehicles::CPACSVehicles(CPACSCpacs* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSVehicles::~CPACSVehicles()
    {
    }

    const CPACSCpacs* CPACSVehicles::GetParent() const
    {
        return m_parent;
    }

    CPACSCpacs* CPACSVehicles::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSVehicles::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSVehicles::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSVehicles::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSVehicles::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSVehicles::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element aircraft
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/aircraft")) {
            m_aircraft = boost::in_place(this, m_uidMgr);
            try {
                m_aircraft->ReadCPACS(tixiHandle, xpath + "/aircraft");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read aircraft at xpath " << xpath << ": " << e.what();
                m_aircraft = boost::none;
            }
        }

        // read element rotorcraft
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotorcraft")) {
            m_rotorcraft = boost::in_place(this, m_uidMgr);
            try {
                m_rotorcraft->ReadCPACS(tixiHandle, xpath + "/rotorcraft");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read rotorcraft at xpath " << xpath << ": " << e.what();
                m_rotorcraft = boost::none;
            }
        }

        // read element performanceCases
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/performanceCases")) {
            m_performanceCases = boost::in_place(this, m_uidMgr);
            try {
                m_performanceCases->ReadCPACS(tixiHandle, xpath + "/performanceCases");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read performanceCases at xpath " << xpath << ": " << e.what();
                m_performanceCases = boost::none;
            }
        }

        // read element flightPoints
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/flightPoints")) {
            m_flightPoints = boost::in_place(this, m_uidMgr);
            try {
                m_flightPoints->ReadCPACS(tixiHandle, xpath + "/flightPoints");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read flightPoints at xpath " << xpath << ": " << e.what();
                m_flightPoints = boost::none;
            }
        }

        // read element engines
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/engines")) {
            m_engines = boost::in_place(this, m_uidMgr);
            try {
                m_engines->ReadCPACS(tixiHandle, xpath + "/engines");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read engines at xpath " << xpath << ": " << e.what();
                m_engines = boost::none;
            }
        }

        // read element profiles
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/profiles")) {
            m_profiles = boost::in_place(this, m_uidMgr);
            try {
                m_profiles->ReadCPACS(tixiHandle, xpath + "/profiles");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read profiles at xpath " << xpath << ": " << e.what();
                m_profiles = boost::none;
            }
        }

        // read element structuralElements
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralElements")) {
            m_structuralElements = boost::in_place(this, m_uidMgr);
            try {
                m_structuralElements->ReadCPACS(tixiHandle, xpath + "/structuralElements");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read structuralElements at xpath " << xpath << ": " << e.what();
                m_structuralElements = boost::none;
            }
        }

        // read element deckElements
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/deckElements")) {
            m_deckElements = boost::in_place(this, m_uidMgr);
            try {
                m_deckElements->ReadCPACS(tixiHandle, xpath + "/deckElements");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read deckElements at xpath " << xpath << ": " << e.what();
                m_deckElements = boost::none;
            }
        }

        // read element materials
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/materials")) {
            m_materials = boost::in_place(this, m_uidMgr);
            try {
                m_materials->ReadCPACS(tixiHandle, xpath + "/materials");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read materials at xpath " << xpath << ": " << e.what();
                m_materials = boost::none;
            }
        }

    }

    void CPACSVehicles::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element aircraft
        if (m_aircraft) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/aircraft");
            m_aircraft->WriteCPACS(tixiHandle, xpath + "/aircraft");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/aircraft")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/aircraft");
            }
        }

        // write element rotorcraft
        if (m_rotorcraft) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotorcraft");
            m_rotorcraft->WriteCPACS(tixiHandle, xpath + "/rotorcraft");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotorcraft")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/rotorcraft");
            }
        }

        // write element performanceCases
        if (m_performanceCases) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/performanceCases");
            m_performanceCases->WriteCPACS(tixiHandle, xpath + "/performanceCases");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/performanceCases")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/performanceCases");
            }
        }

        // write element flightPoints
        if (m_flightPoints) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/flightPoints");
            m_flightPoints->WriteCPACS(tixiHandle, xpath + "/flightPoints");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/flightPoints")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/flightPoints");
            }
        }

        // write element engines
        if (m_engines) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/engines");
            m_engines->WriteCPACS(tixiHandle, xpath + "/engines");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/engines")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/engines");
            }
        }

        // write element profiles
        if (m_profiles) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/profiles");
            m_profiles->WriteCPACS(tixiHandle, xpath + "/profiles");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/profiles")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/profiles");
            }
        }

        // write element structuralElements
        if (m_structuralElements) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/structuralElements");
            m_structuralElements->WriteCPACS(tixiHandle, xpath + "/structuralElements");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralElements")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/structuralElements");
            }
        }

        // write element deckElements
        if (m_deckElements) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/deckElements");
            m_deckElements->WriteCPACS(tixiHandle, xpath + "/deckElements");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/deckElements")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/deckElements");
            }
        }

        // write element materials
        if (m_materials) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/materials");
            m_materials->WriteCPACS(tixiHandle, xpath + "/materials");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/materials")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/materials");
            }
        }

    }

    const boost::optional<CPACSAircraft>& CPACSVehicles::GetAircraft() const
    {
        return m_aircraft;
    }

    boost::optional<CPACSAircraft>& CPACSVehicles::GetAircraft()
    {
        return m_aircraft;
    }

    const boost::optional<CPACSRotorcraft>& CPACSVehicles::GetRotorcraft() const
    {
        return m_rotorcraft;
    }

    boost::optional<CPACSRotorcraft>& CPACSVehicles::GetRotorcraft()
    {
        return m_rotorcraft;
    }

    const boost::optional<CPACSGlobalPerformanceCases>& CPACSVehicles::GetPerformanceCases() const
    {
        return m_performanceCases;
    }

    boost::optional<CPACSGlobalPerformanceCases>& CPACSVehicles::GetPerformanceCases()
    {
        return m_performanceCases;
    }

    const boost::optional<CPACSFlightPoints>& CPACSVehicles::GetFlightPoints() const
    {
        return m_flightPoints;
    }

    boost::optional<CPACSFlightPoints>& CPACSVehicles::GetFlightPoints()
    {
        return m_flightPoints;
    }

    const boost::optional<CPACSEngines>& CPACSVehicles::GetEngines() const
    {
        return m_engines;
    }

    boost::optional<CPACSEngines>& CPACSVehicles::GetEngines()
    {
        return m_engines;
    }

    const boost::optional<CPACSProfiles>& CPACSVehicles::GetProfiles() const
    {
        return m_profiles;
    }

    boost::optional<CPACSProfiles>& CPACSVehicles::GetProfiles()
    {
        return m_profiles;
    }

    const boost::optional<CPACSStructuralElements>& CPACSVehicles::GetStructuralElements() const
    {
        return m_structuralElements;
    }

    boost::optional<CPACSStructuralElements>& CPACSVehicles::GetStructuralElements()
    {
        return m_structuralElements;
    }

    const boost::optional<CPACSDeckElements>& CPACSVehicles::GetDeckElements() const
    {
        return m_deckElements;
    }

    boost::optional<CPACSDeckElements>& CPACSVehicles::GetDeckElements()
    {
        return m_deckElements;
    }

    const boost::optional<CPACSMaterials>& CPACSVehicles::GetMaterials() const
    {
        return m_materials;
    }

    boost::optional<CPACSMaterials>& CPACSVehicles::GetMaterials()
    {
        return m_materials;
    }

    CPACSAircraft& CPACSVehicles::GetAircraft(CreateIfNotExistsTag)
    {
        if (!m_aircraft)
            m_aircraft = boost::in_place(this, m_uidMgr);
        return *m_aircraft;
    }

    void CPACSVehicles::RemoveAircraft()
    {
        m_aircraft = boost::none;
    }

    CPACSRotorcraft& CPACSVehicles::GetRotorcraft(CreateIfNotExistsTag)
    {
        if (!m_rotorcraft)
            m_rotorcraft = boost::in_place(this, m_uidMgr);
        return *m_rotorcraft;
    }

    void CPACSVehicles::RemoveRotorcraft()
    {
        m_rotorcraft = boost::none;
    }

    CPACSGlobalPerformanceCases& CPACSVehicles::GetPerformanceCases(CreateIfNotExistsTag)
    {
        if (!m_performanceCases)
            m_performanceCases = boost::in_place(this, m_uidMgr);
        return *m_performanceCases;
    }

    void CPACSVehicles::RemovePerformanceCases()
    {
        m_performanceCases = boost::none;
    }

    CPACSFlightPoints& CPACSVehicles::GetFlightPoints(CreateIfNotExistsTag)
    {
        if (!m_flightPoints)
            m_flightPoints = boost::in_place(this, m_uidMgr);
        return *m_flightPoints;
    }

    void CPACSVehicles::RemoveFlightPoints()
    {
        m_flightPoints = boost::none;
    }

    CPACSEngines& CPACSVehicles::GetEngines(CreateIfNotExistsTag)
    {
        if (!m_engines)
            m_engines = boost::in_place(this, m_uidMgr);
        return *m_engines;
    }

    void CPACSVehicles::RemoveEngines()
    {
        m_engines = boost::none;
    }

    CPACSProfiles& CPACSVehicles::GetProfiles(CreateIfNotExistsTag)
    {
        if (!m_profiles)
            m_profiles = boost::in_place(this, m_uidMgr);
        return *m_profiles;
    }

    void CPACSVehicles::RemoveProfiles()
    {
        m_profiles = boost::none;
    }

    CPACSStructuralElements& CPACSVehicles::GetStructuralElements(CreateIfNotExistsTag)
    {
        if (!m_structuralElements)
            m_structuralElements = boost::in_place(this, m_uidMgr);
        return *m_structuralElements;
    }

    void CPACSVehicles::RemoveStructuralElements()
    {
        m_structuralElements = boost::none;
    }

    CPACSDeckElements& CPACSVehicles::GetDeckElements(CreateIfNotExistsTag)
    {
        if (!m_deckElements)
            m_deckElements = boost::in_place(this, m_uidMgr);
        return *m_deckElements;
    }

    void CPACSVehicles::RemoveDeckElements()
    {
        m_deckElements = boost::none;
    }

    CPACSMaterials& CPACSVehicles::GetMaterials(CreateIfNotExistsTag)
    {
        if (!m_materials)
            m_materials = boost::in_place(this, m_uidMgr);
        return *m_materials;
    }

    void CPACSVehicles::RemoveMaterials()
    {
        m_materials = boost::none;
    }

} // namespace generated
} // namespace tigl
