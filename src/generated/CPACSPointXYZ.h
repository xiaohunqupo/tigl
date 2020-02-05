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
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSGuideCurve;

namespace generated
{
    // This class is used in:
    // CPACSGuideCurve

    // generated from /xsd:schema/xsd:complexType[731]
    /// @brief pointXYZType
    /// 
    /// Point type, containing an xyz data triplet.
    /// 
    class CPACSPointXYZ : public CTiglReqUIDObject
    {
    public:
        TIGL_EXPORT CPACSPointXYZ(CCPACSGuideCurve* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSPointXYZ();

        TIGL_EXPORT CCPACSGuideCurve* GetParent();

        TIGL_EXPORT const CCPACSGuideCurve* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetX() const;
        TIGL_EXPORT virtual void SetX(const double& value);

        TIGL_EXPORT virtual const double& GetY() const;
        TIGL_EXPORT virtual void SetY(const double& value);

        TIGL_EXPORT virtual const double& GetZ() const;
        TIGL_EXPORT virtual void SetZ(const double& value);

    protected:
        CCPACSGuideCurve* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string m_uID;

        /// X-Component
        double      m_x;

        /// Y-Component
        double      m_y;

        /// Z-Component
        double      m_z;

    private:
        CPACSPointXYZ(const CPACSPointXYZ&) = delete;
        CPACSPointXYZ& operator=(const CPACSPointXYZ&) = delete;

        CPACSPointXYZ(CPACSPointXYZ&&) = delete;
        CPACSPointXYZ& operator=(CPACSPointXYZ&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSPointXYZ = generated::CPACSPointXYZ;
} // namespace tigl
