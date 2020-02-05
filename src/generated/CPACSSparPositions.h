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

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;
class CCPACSWingSparPosition;
class CCPACSWingSpars;

namespace generated
{
    // This class is used in:
    // CPACSWingSpar

    // generated from /xsd:schema/xsd:complexType[827]
    /// @brief Spar definition points on the wing.
    /// 
    /// sparPositionType, a sparPostion defines a location
    /// within the componentSegment where a spar in mounted. Eta and xsi
    /// are relative to the componentSegment.
    /// Please find below a picture for an example definition
    /// of 3 spars in one wing, by using spar position points and spar
    /// segments:
    /// @see spars1
    /// 
    class CPACSSparPositions
    {
    public:
        TIGL_EXPORT CPACSSparPositions(CCPACSWingSpars* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSSparPositions();

        TIGL_EXPORT CCPACSWingSpars* GetParent();

        TIGL_EXPORT const CCPACSWingSpars* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CCPACSWingSparPosition>>& GetSparPositions() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CCPACSWingSparPosition>>& GetSparPositions();

        TIGL_EXPORT virtual CCPACSWingSparPosition& AddSparPosition();
        TIGL_EXPORT virtual void RemoveSparPosition(CCPACSWingSparPosition& ref);

    protected:
        CCPACSWingSpars* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CCPACSWingSparPosition>> m_sparPositions;

    private:
        CPACSSparPositions(const CPACSSparPositions&) = delete;
        CPACSSparPositions& operator=(const CPACSSparPositions&) = delete;

        CPACSSparPositions(CPACSSparPositions&&) = delete;
        CPACSSparPositions& operator=(CPACSSparPositions&&) = delete;
    };
} // namespace generated

// CPACSSparPositions is customized, use type CCPACSWingSparPositions directly
} // namespace tigl
