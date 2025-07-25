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

namespace generated
{
    class CPACSSeatElement;
    class CPACSDeckElements;

    // This class is used in:
    // CPACSDeckElements

    /// @brief Seat elements
    /// 
    /// Seat element collection type
    /// 
    class CPACSSeatElements
    {
    public:
        TIGL_EXPORT CPACSSeatElements(CPACSDeckElements* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSSeatElements();

        TIGL_EXPORT CPACSDeckElements* GetParent();

        TIGL_EXPORT const CPACSDeckElements* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CPACSSeatElement>>& GetSeatElements() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CPACSSeatElement>>& GetSeatElements();

        TIGL_EXPORT virtual size_t GetSeatElementCount() const;
        TIGL_EXPORT virtual size_t GetSeatElementIndex(const std::string& UID) const;

        TIGL_EXPORT virtual const CPACSSeatElement& GetSeatElement(size_t index) const;
        TIGL_EXPORT virtual CPACSSeatElement& GetSeatElement(size_t index);

        TIGL_EXPORT virtual const CPACSSeatElement& GetSeatElement(const std::string& UID) const;
        TIGL_EXPORT virtual CPACSSeatElement& GetSeatElement(const std::string& UID);

        TIGL_EXPORT virtual CPACSSeatElement& AddSeatElement();
        TIGL_EXPORT virtual void RemoveSeatElement(CPACSSeatElement& ref);

    protected:
        CPACSDeckElements* m_parent;

        CTiglUIDManager* m_uidMgr;

        /// Seat element for use in the decks
        std::vector<std::unique_ptr<CPACSSeatElement>> m_seatElements;

    private:
        CPACSSeatElements(const CPACSSeatElements&) = delete;
        CPACSSeatElements& operator=(const CPACSSeatElements&) = delete;

        CPACSSeatElements(CPACSSeatElements&&) = delete;
        CPACSSeatElements& operator=(CPACSSeatElements&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSSeatElements = generated::CPACSSeatElements;
using CCPACSSeatElement = generated::CPACSSeatElement;
using CCPACSDeckElements = generated::CPACSDeckElements;
} // namespace tigl
