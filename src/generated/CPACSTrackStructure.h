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

#pragma once

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSMaterialDefinition.h>
#include <string>
#include <tixi.h>
#include "CPACSTrackCar.h"
#include "CPACSTrackFairing.h"
#include "CPACSTrackStrut1.h"
#include "CPACSTrackStrut2.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;
class CCPACSControlSurfaceTrackType;

namespace generated
{
    // This class is used in:
    // CPACSControlSurfaceTrackType

    // generated from /xsd:schema/xsd:complexType[885]
    /// @brief wingSparsType
    /// 
    /// Spars type, a spar is defined by sparSegments that
    /// stretch between multiple sparPositions
    /// 
    class CPACSTrackStructure
    {
    public:
        TIGL_EXPORT CPACSTrackStructure(CCPACSControlSurfaceTrackType* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSTrackStructure();

        TIGL_EXPORT CCPACSControlSurfaceTrackType* GetParent();

        TIGL_EXPORT const CCPACSControlSurfaceTrackType* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<CCPACSMaterialDefinition>& GetControlSurfaceAttachment() const;
        TIGL_EXPORT virtual boost::optional<CCPACSMaterialDefinition>& GetControlSurfaceAttachment();

        TIGL_EXPORT virtual const boost::optional<CPACSTrackCar>& GetCar() const;
        TIGL_EXPORT virtual boost::optional<CPACSTrackCar>& GetCar();

        TIGL_EXPORT virtual const boost::optional<CPACSTrackStrut1>& GetStrut1() const;
        TIGL_EXPORT virtual boost::optional<CPACSTrackStrut1>& GetStrut1();

        TIGL_EXPORT virtual const boost::optional<CPACSTrackStrut2>& GetStrut2() const;
        TIGL_EXPORT virtual boost::optional<CPACSTrackStrut2>& GetStrut2();

        TIGL_EXPORT virtual const boost::optional<CCPACSMaterialDefinition>& GetStrut3() const;
        TIGL_EXPORT virtual boost::optional<CCPACSMaterialDefinition>& GetStrut3();

        TIGL_EXPORT virtual const boost::optional<CCPACSMaterialDefinition>& GetSidePanels() const;
        TIGL_EXPORT virtual boost::optional<CCPACSMaterialDefinition>& GetSidePanels();

        TIGL_EXPORT virtual const boost::optional<CCPACSMaterialDefinition>& GetUpperPanel() const;
        TIGL_EXPORT virtual boost::optional<CCPACSMaterialDefinition>& GetUpperPanel();

        TIGL_EXPORT virtual const boost::optional<CCPACSMaterialDefinition>& GetLowerPanel() const;
        TIGL_EXPORT virtual boost::optional<CCPACSMaterialDefinition>& GetLowerPanel();

        TIGL_EXPORT virtual const boost::optional<CCPACSMaterialDefinition>& GetRollerTrack() const;
        TIGL_EXPORT virtual boost::optional<CCPACSMaterialDefinition>& GetRollerTrack();

        TIGL_EXPORT virtual const boost::optional<CCPACSMaterialDefinition>& GetRibs() const;
        TIGL_EXPORT virtual boost::optional<CCPACSMaterialDefinition>& GetRibs();

        TIGL_EXPORT virtual const boost::optional<CPACSTrackFairing>& GetFairing() const;
        TIGL_EXPORT virtual boost::optional<CPACSTrackFairing>& GetFairing();

        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetControlSurfaceAttachment(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveControlSurfaceAttachment();

        TIGL_EXPORT virtual CPACSTrackCar& GetCar(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveCar();

        TIGL_EXPORT virtual CPACSTrackStrut1& GetStrut1(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStrut1();

        TIGL_EXPORT virtual CPACSTrackStrut2& GetStrut2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStrut2();

        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetStrut3(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStrut3();

        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetSidePanels(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveSidePanels();

        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetUpperPanel(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveUpperPanel();

        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetLowerPanel(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveLowerPanel();

        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetRollerTrack(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRollerTrack();

        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetRibs(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRibs();

        TIGL_EXPORT virtual CPACSTrackFairing& GetFairing(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveFairing();

    protected:
        CCPACSControlSurfaceTrackType* m_parent;

        CTiglUIDManager* m_uidMgr;

        boost::optional<CCPACSMaterialDefinition> m_controlSurfaceAttachment;
        boost::optional<CPACSTrackCar>            m_car;
        boost::optional<CPACSTrackStrut1>         m_strut1;
        boost::optional<CPACSTrackStrut2>         m_strut2;
        boost::optional<CCPACSMaterialDefinition> m_strut3;
        boost::optional<CCPACSMaterialDefinition> m_sidePanels;
        boost::optional<CCPACSMaterialDefinition> m_upperPanel;
        boost::optional<CCPACSMaterialDefinition> m_lowerPanel;
        boost::optional<CCPACSMaterialDefinition> m_rollerTrack;
        boost::optional<CCPACSMaterialDefinition> m_ribs;
        boost::optional<CPACSTrackFairing>        m_fairing;

    private:
        CPACSTrackStructure(const CPACSTrackStructure&) = delete;
        CPACSTrackStructure& operator=(const CPACSTrackStructure&) = delete;

        CPACSTrackStructure(CPACSTrackStructure&&) = delete;
        CPACSTrackStructure& operator=(CPACSTrackStructure&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSTrackStructure = generated::CPACSTrackStructure;
} // namespace tigl
