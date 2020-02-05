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
class CCPACSFuselageSection;
class CCPACSFuselage;

namespace generated
{
    // This class is used in:
    // CPACSFuselage

    // generated from /xsd:schema/xsd:complexType[383]
    /// @brief fuselageSectionsType
    /// 
    /// FuselageSections type, containing fuselage sections
    /// 
    class CPACSFuselageSections
    {
    public:
        TIGL_EXPORT CPACSFuselageSections(CCPACSFuselage* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSFuselageSections();

        TIGL_EXPORT CCPACSFuselage* GetParent();

        TIGL_EXPORT const CCPACSFuselage* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CCPACSFuselageSection>>& GetSections() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CCPACSFuselageSection>>& GetSections();

        TIGL_EXPORT virtual CCPACSFuselageSection& AddSection();
        TIGL_EXPORT virtual void RemoveSection(CCPACSFuselageSection& ref);

    protected:
        CCPACSFuselage* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CCPACSFuselageSection>> m_sections;

    private:
        CPACSFuselageSections(const CPACSFuselageSections&) = delete;
        CPACSFuselageSections& operator=(const CPACSFuselageSections&) = delete;

        CPACSFuselageSections(CPACSFuselageSections&&) = delete;
        CPACSFuselageSections& operator=(CPACSFuselageSections&&) = delete;
    };
} // namespace generated

// CPACSFuselageSections is customized, use type CCPACSFuselageSections directly
} // namespace tigl
