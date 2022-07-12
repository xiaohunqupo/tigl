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
#include <CCPACSStringVector.h>
#include <string>
#include <tixi.h>
#include <typeinfo>
#include "CTiglError.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDObject;
class CCPACSNacelleProfile;

namespace generated
{
    class CPACSProfileGeometry;

    // This class is used in:
    // CPACSProfileGeometry
    // CPACSProfileGeometry2D

    /// @brief cst2DType
    /// 
    /// 
    /// 
    class CPACSCst2D
    {
    public:
        TIGL_EXPORT CPACSCst2D(CPACSProfileGeometry* parent);
        TIGL_EXPORT CPACSCst2D(CCPACSNacelleProfile* parent);

        TIGL_EXPORT virtual ~CPACSCst2D();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
            static_assert(std::is_same<P, CPACSProfileGeometry>::value || std::is_same<P, CCPACSNacelleProfile>::value, "template argument for P is not a parent class of CPACSCst2D");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
            static_assert(std::is_same<P, CPACSProfileGeometry>::value || std::is_same<P, CCPACSNacelleProfile>::value, "template argument for P is not a parent class of CPACSCst2D");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSStringVector& GetPsi() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetPsi();

        TIGL_EXPORT virtual const double& GetUpperN1() const;
        TIGL_EXPORT virtual void SetUpperN1(const double& value);

        TIGL_EXPORT virtual const double& GetUpperN2() const;
        TIGL_EXPORT virtual void SetUpperN2(const double& value);

        TIGL_EXPORT virtual const CCPACSStringVector& GetUpperB() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetUpperB();

        TIGL_EXPORT virtual const double& GetLowerN1() const;
        TIGL_EXPORT virtual void SetLowerN1(const double& value);

        TIGL_EXPORT virtual const double& GetLowerN2() const;
        TIGL_EXPORT virtual void SetLowerN2(const double& value);

        TIGL_EXPORT virtual const CCPACSStringVector& GetLowerB() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetLowerB();

        TIGL_EXPORT virtual const boost::optional<double>& GetTrailingEdgeThickness() const;
        TIGL_EXPORT virtual void SetTrailingEdgeThickness(const boost::optional<double>& value);

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        /// The psi vector for definition of the class and
        /// shape function, i.e. the points at which the CST functions will
        /// be evaluated
        CCPACSStringVector      m_psi;

        /// N1 for the class function for the upper side
        /// of the profile
        double                  m_upperN1;

        /// N2 for the class function for the upper side
        /// of the profile
        double                  m_upperN2;

        /// B Coefficients for the Bernstein polynominal
        /// on the upper side
        CCPACSStringVector      m_upperB;

        /// N1 for the class function for the lower side
        /// of the profile
        double                  m_lowerN1;

        /// N2 for the class function for the lower side
        /// of the profile
        double                  m_lowerN2;

        /// B Coefficients for the Bernstein polynominal
        /// on the lower side
        CCPACSStringVector      m_lowerB;

        /// Optionally, the trailingEdgeThickness of the
        /// profile
        boost::optional<double> m_trailingEdgeThickness;

    private:
        CPACSCst2D(const CPACSCst2D&) = delete;
        CPACSCst2D& operator=(const CPACSCst2D&) = delete;

        CPACSCst2D(CPACSCst2D&&) = delete;
        CPACSCst2D& operator=(CPACSCst2D&&) = delete;
    };
} // namespace generated

// CPACSCst2D is customized, use type CCPACSWingProfileCST directly

// Aliases in tigl namespace
using CCPACSProfileGeometry = generated::CPACSProfileGeometry;
} // namespace tigl
