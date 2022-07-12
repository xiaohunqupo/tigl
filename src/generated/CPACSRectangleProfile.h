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
#include "CPACSPosExcl0DoubleBase.h"
#include "CPACSRectangleProfile_cornerRadius.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDObject;

namespace generated
{
    class CPACSStandardProfile;

    // This class is used in:
    // CPACSStandardProfile

    /// @brief Rectangle
    /// 
    /// The width of the profile is always 1, since scaling is performed after referencing it (e.g., in the fuselage).
    /// The resulting profile is defined by the following equation:
    /// @see eq_roundedRectangle
    /// with c = cornerRadius and r = heightToWidthRatio .
    /// Example: Rectangle with cornerRadius =0.125 and heightToWidthRatio =0.5
    /// @see rectangleRoundedCorners
    /// 
    class CPACSRectangleProfile
    {
    public:
        TIGL_EXPORT CPACSRectangleProfile(CPACSStandardProfile* parent);

        TIGL_EXPORT virtual ~CPACSRectangleProfile();

        TIGL_EXPORT CPACSStandardProfile* GetParent();

        TIGL_EXPORT const CPACSStandardProfile* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<CPACSRectangleProfile_cornerRadius>& GetCornerRadius() const;
        TIGL_EXPORT virtual boost::optional<CPACSRectangleProfile_cornerRadius>& GetCornerRadius();

        TIGL_EXPORT virtual const CPACSPosExcl0DoubleBase& GetHeightToWidthRatio() const;
        TIGL_EXPORT virtual CPACSPosExcl0DoubleBase& GetHeightToWidthRatio();

        TIGL_EXPORT virtual CPACSRectangleProfile_cornerRadius& GetCornerRadius(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveCornerRadius();

    protected:
        CPACSStandardProfile* m_parent;

        boost::optional<CPACSRectangleProfile_cornerRadius> m_cornerRadius;
        CPACSPosExcl0DoubleBase                             m_heightToWidthRatio;

    private:
        CPACSRectangleProfile(const CPACSRectangleProfile&) = delete;
        CPACSRectangleProfile& operator=(const CPACSRectangleProfile&) = delete;

        CPACSRectangleProfile(CPACSRectangleProfile&&) = delete;
        CPACSRectangleProfile& operator=(CPACSRectangleProfile&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSRectangleProfile = generated::CPACSRectangleProfile;
using CCPACSStandardProfile = generated::CPACSStandardProfile;
} // namespace tigl
