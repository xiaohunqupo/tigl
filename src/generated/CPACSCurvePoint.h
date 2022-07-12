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
#include <typeinfo>
#include "CTiglError.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDObject;
class CCPACSWingRibExplicitPositioning;
class CCPACSWingRibsPositioning;

namespace generated
{
    // This class is used in:
    // CPACSWingRibExplicitPositioning
    // CPACSWingRibsPositioning

    /// @brief curvePointType
    /// 
    /// Point on a curve in normalized curve coordinates.
    /// The referenceUID must reference a one-dimensional curve such as spars.
    /// 
    class CPACSCurvePoint
    {
    public:
        TIGL_EXPORT CPACSCurvePoint(CCPACSWingRibExplicitPositioning* parent);
        TIGL_EXPORT CPACSCurvePoint(CCPACSWingRibsPositioning* parent);

        TIGL_EXPORT virtual ~CPACSCurvePoint();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
            static_assert(std::is_same<P, CCPACSWingRibExplicitPositioning>::value || std::is_same<P, CCPACSWingRibsPositioning>::value, "template argument for P is not a parent class of CPACSCurvePoint");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
            static_assert(std::is_same<P, CCPACSWingRibExplicitPositioning>::value || std::is_same<P, CCPACSWingRibsPositioning>::value, "template argument for P is not a parent class of CPACSCurvePoint");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const double& GetEta() const;
        TIGL_EXPORT virtual void SetEta(const double& value);

        TIGL_EXPORT virtual const std::string& GetReferenceUID() const;
        TIGL_EXPORT virtual void SetReferenceUID(const std::string& value);

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        /// Relative position on the referenced line/curve.
        double      m_eta;

        /// This reference uID determines the reference curve.
        /// If it points to a spar, then the eta value is considered to be a spar coordinate
        /// between start (eta=0) and end (eta=1) of the spar.
        std::string m_referenceUID;

    private:
        CPACSCurvePoint(const CPACSCurvePoint&) = delete;
        CPACSCurvePoint& operator=(const CPACSCurvePoint&) = delete;

        CPACSCurvePoint(CPACSCurvePoint&&) = delete;
        CPACSCurvePoint& operator=(CPACSCurvePoint&&) = delete;
    };
} // namespace generated

// CPACSCurvePoint is customized, use type CCPACSCurvePoint directly
} // namespace tigl
