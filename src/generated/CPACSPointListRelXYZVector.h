// Copyright (c) 2018 RISC Software GmbH
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

#include <CCPACSStringVector.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSGuideCurveProfileGeometry

    // generated from /xsd:schema/xsd:complexType[718]
    class CPACSPointListRelXYZVector
    {
    public:
        TIGL_EXPORT CPACSPointListRelXYZVector();
        TIGL_EXPORT virtual ~CPACSPointListRelXYZVector();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSStringVector& GetRX() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetRX();

        TIGL_EXPORT virtual const CCPACSStringVector& GetRY() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetRY();

        TIGL_EXPORT virtual const CCPACSStringVector& GetRZ() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetRZ();

    protected:
        CCPACSStringVector m_rX;
        CCPACSStringVector m_rY;
        CCPACSStringVector m_rZ;

    private:
#ifdef HAVE_CPP11
        CPACSPointListRelXYZVector(const CPACSPointListRelXYZVector&) = delete;
        CPACSPointListRelXYZVector& operator=(const CPACSPointListRelXYZVector&) = delete;

        CPACSPointListRelXYZVector(CPACSPointListRelXYZVector&&) = delete;
        CPACSPointListRelXYZVector& operator=(CPACSPointListRelXYZVector&&) = delete;
#else
        CPACSPointListRelXYZVector(const CPACSPointListRelXYZVector&);
        CPACSPointListRelXYZVector& operator=(const CPACSPointListRelXYZVector&);
#endif
    };
} // namespace generated

// CPACSPointListRelXYZVector is customized, use type CCPACSPointListRelXYZVector directly
} // namespace tigl
