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
#include <typeinfo>
#include "CTiglError.h"
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingRibCrossSection;

namespace generated
{
    class CPACSWingRibCell;

    // This class is used in:
    // CPACSWingRibCell
    // CPACSWingRibCrossSection

    /// @brief Point: x
    /// 
    /// Point type, containing a x data.
    /// 
    class CPACSPointX : public CTiglOptUIDObject
    {
    public:
        TIGL_EXPORT CPACSPointX(CPACSWingRibCell* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSPointX(CCPACSWingRibCrossSection* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSPointX();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
            static_assert(std::is_same<P, CPACSWingRibCell>::value || std::is_same<P, CCPACSWingRibCrossSection>::value, "template argument for P is not a parent class of CPACSPointX");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
            static_assert(std::is_same<P, CPACSWingRibCell>::value || std::is_same<P, CCPACSWingRibCrossSection>::value, "template argument for P is not a parent class of CPACSPointX");
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

        TIGL_EXPORT virtual const double& GetX() const;
        TIGL_EXPORT virtual void SetX(const double& value);

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        CTiglUIDManager* m_uidMgr;

        boost::optional<std::string> m_uID;

        /// X-Component
        double                       m_x;

    private:
        CPACSPointX(const CPACSPointX&) = delete;
        CPACSPointX& operator=(const CPACSPointX&) = delete;

        CPACSPointX(CPACSPointX&&) = delete;
        CPACSPointX& operator=(CPACSPointX&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSPointX = generated::CPACSPointX;
using CCPACSWingRibCell = generated::CPACSWingRibCell;
} // namespace tigl
