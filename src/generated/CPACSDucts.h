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
class CCPACSDuct;
class CCPACSAircraftModel;

namespace generated
{
    // This class is used in:
    // CPACSAircraftModel

    /// @brief Ducts
    /// 
    /// 
    class CPACSDucts
    {
    public:
        TIGL_EXPORT CPACSDucts(CCPACSAircraftModel* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSDucts();

        TIGL_EXPORT CCPACSAircraftModel* GetParent();

        TIGL_EXPORT const CCPACSAircraftModel* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CCPACSDuct>>& GetDucts() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CCPACSDuct>>& GetDucts();

        TIGL_EXPORT virtual CCPACSDuct& AddDuct();
        TIGL_EXPORT virtual void RemoveDuct(CCPACSDuct& ref);

    protected:
        CCPACSAircraftModel* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CCPACSDuct>> m_ducts;

    private:
        CPACSDucts(const CPACSDucts&) = delete;
        CPACSDucts& operator=(const CPACSDucts&) = delete;

        CPACSDucts(CPACSDucts&&) = delete;
        CPACSDucts& operator=(CPACSDucts&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSDucts = generated::CPACSDucts;
} // namespace tigl
