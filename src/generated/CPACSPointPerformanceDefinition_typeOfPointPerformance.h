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
#include <cctype>

#include "CTiglError.h"
#include "to_string.h"

namespace tigl
{
namespace generated
{
    // This enum is used in:
    // CPACSPointPerformanceDefinition

    enum CPACSPointPerformanceDefinition_typeOfPointPerformance
    {
        takeOff,
        climb,
        cruise,
        descent,
        landing,
        acceleration,
        sustained_turn,
        instantaneous_turn,
        service_ceiling,
        combat_ceiling,
        level_flight
    };

    inline std::string CPACSPointPerformanceDefinition_typeOfPointPerformanceToString(const CPACSPointPerformanceDefinition_typeOfPointPerformance& value)
    {
        switch(value) {
        case takeOff: return "takeOff";
        case climb: return "climb";
        case cruise: return "cruise";
        case descent: return "descent";
        case landing: return "landing";
        case acceleration: return "acceleration";
        case sustained_turn: return "sustained turn";
        case instantaneous_turn: return "instantaneous turn";
        case service_ceiling: return "service ceiling";
        case combat_ceiling: return "combat ceiling";
        case level_flight: return "level flight";
        default: throw CTiglError("Invalid enum value \"" + std_to_string(static_cast<int>(value)) + "\" for enum type CPACSPointPerformanceDefinition_typeOfPointPerformance");
        }
    }
    inline CPACSPointPerformanceDefinition_typeOfPointPerformance stringToCPACSPointPerformanceDefinition_typeOfPointPerformance(const std::string& value)
    {
        auto toLower = [](std::string str) { for (char& c : str) { c = std::tolower(c); } return str; };
        if (toLower(value) == "takeoff") { return takeOff; }
        if (toLower(value) == "climb") { return climb; }
        if (toLower(value) == "cruise") { return cruise; }
        if (toLower(value) == "descent") { return descent; }
        if (toLower(value) == "landing") { return landing; }
        if (toLower(value) == "acceleration") { return acceleration; }
        if (toLower(value) == "sustained turn") { return sustained_turn; }
        if (toLower(value) == "instantaneous turn") { return instantaneous_turn; }
        if (toLower(value) == "service ceiling") { return service_ceiling; }
        if (toLower(value) == "combat ceiling") { return combat_ceiling; }
        if (toLower(value) == "level flight") { return level_flight; }
        throw CTiglError("Invalid string value \"" + value + "\" for enum type CPACSPointPerformanceDefinition_typeOfPointPerformance");
    }
} // namespace generated

// Aliases in tigl namespace
using ECPACSPointPerformanceDefinition_typeOfPointPerformance = generated::CPACSPointPerformanceDefinition_typeOfPointPerformance;
} // namespace tigl
