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
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;

namespace generated
{
    class CPACSStructuralProfile;
    class CPACSStructuralProfile3D;
    class CPACSProfiles;

    // This class is used in:
    // CPACSProfiles

    /// @brief Definition cross sections of structural profiles.
    /// 
    /// Structuralprofiles type, containing cross section
    /// information of structural profiles.
    /// 
    class CPACSStructuralProfiles
    {
    public:
        TIGL_EXPORT CPACSStructuralProfiles(CPACSProfiles* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSStructuralProfiles();

        TIGL_EXPORT CPACSProfiles* GetParent();

        TIGL_EXPORT const CPACSProfiles* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CPACSStructuralProfile>>& GetStructuralProfile2Ds() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CPACSStructuralProfile>>& GetStructuralProfile2Ds();

        TIGL_EXPORT virtual size_t GetStructuralProfile2DCount() const;
        TIGL_EXPORT virtual size_t GetStructuralProfile2DIndex(const std::string& UID) const;

        TIGL_EXPORT virtual const CPACSStructuralProfile& GetStructuralProfile2D(size_t index) const;
        TIGL_EXPORT virtual CPACSStructuralProfile& GetStructuralProfile2D(size_t index);

        TIGL_EXPORT virtual const CPACSStructuralProfile& GetStructuralProfile2D(const std::string& UID) const;
        TIGL_EXPORT virtual CPACSStructuralProfile& GetStructuralProfile2D(const std::string& UID);

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CPACSStructuralProfile3D>>& GetStructuralProfile3Ds() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CPACSStructuralProfile3D>>& GetStructuralProfile3Ds();

        TIGL_EXPORT virtual size_t GetStructuralProfile3DCount() const;
        TIGL_EXPORT virtual size_t GetStructuralProfile3DIndex(const std::string& UID) const;

        TIGL_EXPORT virtual const CPACSStructuralProfile3D& GetStructuralProfile3D(size_t index) const;
        TIGL_EXPORT virtual CPACSStructuralProfile3D& GetStructuralProfile3D(size_t index);

        TIGL_EXPORT virtual const CPACSStructuralProfile3D& GetStructuralProfile3D(const std::string& UID) const;
        TIGL_EXPORT virtual CPACSStructuralProfile3D& GetStructuralProfile3D(const std::string& UID);

        TIGL_EXPORT virtual CPACSStructuralProfile& AddStructuralProfile2D();
        TIGL_EXPORT virtual void RemoveStructuralProfile2D(CPACSStructuralProfile& ref);

        TIGL_EXPORT virtual CPACSStructuralProfile3D& AddStructuralProfile3D();
        TIGL_EXPORT virtual void RemoveStructuralProfile3D(CPACSStructuralProfile3D& ref);

    protected:
        CPACSProfiles* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CPACSStructuralProfile>>   m_structuralProfile2Ds;
        std::vector<std::unique_ptr<CPACSStructuralProfile3D>> m_structuralProfile3Ds;

    private:
        CPACSStructuralProfiles(const CPACSStructuralProfiles&) = delete;
        CPACSStructuralProfiles& operator=(const CPACSStructuralProfiles&) = delete;

        CPACSStructuralProfiles(CPACSStructuralProfiles&&) = delete;
        CPACSStructuralProfiles& operator=(CPACSStructuralProfiles&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSStructuralProfiles = generated::CPACSStructuralProfiles;
using CCPACSStructuralProfile = generated::CPACSStructuralProfile;
using CCPACSStructuralProfile3D = generated::CPACSStructuralProfile3D;
using CCPACSProfiles = generated::CPACSProfiles;
} // namespace tigl
