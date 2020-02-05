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
#include <string>
#include <tixi.h>
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;
class CCPACSWingSparPosition;

namespace generated
{
    // This class is used in:
    // CPACSSparPosition

    // generated from /xsd:schema/xsd:complexType[965]
    /// @brief wingRibPointType
    /// 
    /// The wingRibPointType is used to define reference points on ribs.
    /// It can be used for rib set definitions (wingRibsPositioningType) as 
    /// well as explicit rib definitions (wingRibExplicitPositioningType).
    /// 
    class CPACSWingRibPoint : public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSWingRibPoint(CCPACSWingSparPosition* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWingRibPoint();

        TIGL_EXPORT CCPACSWingSparPosition* GetParent();

        TIGL_EXPORT const CCPACSWingSparPosition* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetRibDefinitionUID() const;
        TIGL_EXPORT virtual void SetRibDefinitionUID(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<int>& GetRibNumber() const;
        TIGL_EXPORT virtual void SetRibNumber(const boost::optional<int>& value);

        TIGL_EXPORT virtual const double& GetXsi() const;
        TIGL_EXPORT virtual void SetXsi(const double& value);

    protected:
        CCPACSWingSparPosition* m_parent;

        CTiglUIDManager* m_uidMgr;

        /// The UID of the rib definition. Can be a reference to nodes 
        /// of either wingRibsPositioningType or wingRibExplicitPositioningType.
        std::string          m_ribDefinitionUID;

        /// For references of type wingRibsPositioningType this node indicates the rib number of the rib set. 
        /// If not given it defaults to 1.
        boost::optional<int> m_ribNumber;

        /// Normalized xsi coordinate of the rib point which is measured along the rib 
        /// from the start point [0] towards the end point [1].
        double               m_xsi;

    private:
        const CTiglUIDObject* GetNextUIDObject() const final;
        void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSWingRibPoint(const CPACSWingRibPoint&) = delete;
        CPACSWingRibPoint& operator=(const CPACSWingRibPoint&) = delete;

        CPACSWingRibPoint(CPACSWingRibPoint&&) = delete;
        CPACSWingRibPoint& operator=(CPACSWingRibPoint&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSWingRibPoint = generated::CPACSWingRibPoint;
} // namespace tigl
