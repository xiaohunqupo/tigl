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
#include "CPACSLinkToFileType_format.h"
#include "CTiglError.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDObject;
class CCPACSExternalObject;

namespace generated
{
    class CPACSGenericGeometryComponent;

    // This class is used in:
    // CPACSGenericGeometricComponent
    // CPACSGenericGeometryComponent

    /// @brief Link to file (Step, Iges or Stl)
    /// 
    /// Please provide a link to the additional file that shall
    /// be loaded by the TIGL library. Furthermore it is necessary to
    /// provide the format attribute so that the file type can be
    /// identified. Several CAD formats provide multiple endings, and
    /// hence, this measure seems necessary.
    /// 
    class CPACSLinkToFile
    {
    public:
        TIGL_EXPORT CPACSLinkToFile(CCPACSExternalObject* parent);
        TIGL_EXPORT CPACSLinkToFile(CPACSGenericGeometryComponent* parent);

        TIGL_EXPORT virtual ~CPACSLinkToFile();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
            static_assert(std::is_same<P, CCPACSExternalObject>::value || std::is_same<P, CPACSGenericGeometryComponent>::value, "template argument for P is not a parent class of CPACSLinkToFile");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
            static_assert(std::is_same<P, CCPACSExternalObject>::value || std::is_same<P, CPACSGenericGeometryComponent>::value, "template argument for P is not a parent class of CPACSLinkToFile");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<CPACSLinkToFileType_format>& GetFormat() const;
        TIGL_EXPORT virtual void SetFormat(const boost::optional<CPACSLinkToFileType_format>& value);

        TIGL_EXPORT virtual const std::string& GetValue() const;
        TIGL_EXPORT virtual void SetValue(const std::string& value);

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        boost::optional<CPACSLinkToFileType_format> m_format;
        std::string                                 m_value;

    private:
        CPACSLinkToFile(const CPACSLinkToFile&) = delete;
        CPACSLinkToFile& operator=(const CPACSLinkToFile&) = delete;

        CPACSLinkToFile(CPACSLinkToFile&&) = delete;
        CPACSLinkToFile& operator=(CPACSLinkToFile&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSLinkToFile = generated::CPACSLinkToFile;
using CCPACSGenericGeometryComponent = generated::CPACSGenericGeometryComponent;
} // namespace tigl
