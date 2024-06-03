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
    // CPACSAxle

    enum CPACSAxle_sideOfFirstWheel
    {
        inboard,
        outboard,
        centre
    };

    inline std::string CPACSAxle_sideOfFirstWheelToString(const CPACSAxle_sideOfFirstWheel& value)
    {
        switch(value) {
        case inboard: return "inboard";
        case outboard: return "outboard";
        case centre: return "centre";
        default: throw CTiglError("Invalid enum value \"" + std_to_string(static_cast<int>(value)) + "\" for enum type CPACSAxle_sideOfFirstWheel");
        }
    }
    inline CPACSAxle_sideOfFirstWheel stringToCPACSAxle_sideOfFirstWheel(const std::string& value)
    {
        auto toLower = [](std::string str) { for (char& c : str) { c = std::tolower(c); } return str; };
        if (toLower(value) == "inboard") { return inboard; }
        if (toLower(value) == "outboard") { return outboard; }
        if (toLower(value) == "centre") { return centre; }
        throw CTiglError("Invalid string value \"" + value + "\" for enum type CPACSAxle_sideOfFirstWheel");
    }
} // namespace generated

// Aliases in tigl namespace
using ECPACSAxle_sideOfFirstWheel = generated::CPACSAxle_sideOfFirstWheel;
} // namespace tigl