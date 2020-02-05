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
#include <CCPACSTransformation.h>
#include <string>
#include <tixi.h>
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSNacelleSections;

namespace generated
{
    // This class is used in:
    // CPACSNacelleSections

    // generated from /xsd:schema/xsd:complexType[685]
    /// @brief nacelleSectionType
    /// 
    /// 
    /// 
    class CPACSNacelleSection : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSNacelleSection(CCPACSNacelleSections* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSNacelleSection();

        TIGL_EXPORT CCPACSNacelleSections* GetParent();

        TIGL_EXPORT const CCPACSNacelleSections* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const CCPACSTransformation& GetTransformation() const;
        TIGL_EXPORT virtual CCPACSTransformation& GetTransformation();

        TIGL_EXPORT virtual const std::string& GetProfileUID() const;
        TIGL_EXPORT virtual void SetProfileUID(const std::string& value);

    protected:
        CCPACSNacelleSections* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                  m_uID;
        std::string                  m_name;
        boost::optional<std::string> m_description;
        CCPACSTransformation         m_transformation;
        std::string                  m_profileUID;

    private:
        const CTiglUIDObject* GetNextUIDObject() const final;
        void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSNacelleSection(const CPACSNacelleSection&) = delete;
        CPACSNacelleSection& operator=(const CPACSNacelleSection&) = delete;

        CPACSNacelleSection(CPACSNacelleSection&&) = delete;
        CPACSNacelleSection& operator=(CPACSNacelleSection&&) = delete;
    };
} // namespace generated

// CPACSNacelleSection is customized, use type CCPACSNacelleSection directly
} // namespace tigl
