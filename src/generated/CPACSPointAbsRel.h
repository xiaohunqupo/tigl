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
#include <ECPACSTranslationType.h>
#include <string>
#include <tixi.h>
#include <typeinfo>
#include "CTiglError.h"
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSTransformation;

namespace generated
{
    class CPACSStrutAssembly;

    // This class is used in:
    // CPACSStrutAssembly
    // CPACSTransformation

    /// @brief Point with global/local reference
    /// 
    /// PointAbsRel type, containing an xyz data triplet. Each
    /// of the components is optional. The refType attribute defines,
    /// whether coordinates are absolute in the global ccordinate system
    /// [absGlobal], absolute in the parent element's local coordinate
    /// system [absLocal]. If the object does not have a
    /// parent, only [absGlobal] is permitted.
    /// 
    class CPACSPointAbsRel : public CTiglOptUIDObject
    {
    public:
        TIGL_EXPORT CPACSPointAbsRel(CPACSStrutAssembly* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSPointAbsRel(CCPACSTransformation* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSPointAbsRel();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
            static_assert(std::is_same<P, CPACSStrutAssembly>::value || std::is_same<P, CCPACSTransformation>::value, "template argument for P is not a parent class of CPACSPointAbsRel");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
            static_assert(std::is_same<P, CPACSStrutAssembly>::value || std::is_same<P, CCPACSTransformation>::value, "template argument for P is not a parent class of CPACSPointAbsRel");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<ECPACSTranslationType>& GetRefType() const;
        TIGL_EXPORT virtual void SetRefType(const boost::optional<ECPACSTranslationType>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetX() const;
        TIGL_EXPORT virtual void SetX(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetY() const;
        TIGL_EXPORT virtual void SetY(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetZ() const;
        TIGL_EXPORT virtual void SetZ(const boost::optional<double>& value);

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        CTiglUIDManager* m_uidMgr;

        boost::optional<std::string>           m_uID;

        boost::optional<ECPACSTranslationType> m_refType;

        /// X-Component
        boost::optional<double>                m_x;

        /// Y-Component
        boost::optional<double>                m_y;

        /// Z-Component
        boost::optional<double>                m_z;

    private:
        CPACSPointAbsRel(const CPACSPointAbsRel&) = delete;
        CPACSPointAbsRel& operator=(const CPACSPointAbsRel&) = delete;

        CPACSPointAbsRel(CPACSPointAbsRel&&) = delete;
        CPACSPointAbsRel& operator=(CPACSPointAbsRel&&) = delete;
    };
} // namespace generated

// CPACSPointAbsRel is customized, use type CCPACSPointAbsRel directly

// Aliases in tigl namespace
using CCPACSStrutAssembly = generated::CPACSStrutAssembly;
} // namespace tigl
