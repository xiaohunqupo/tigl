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
#include <TiglSymmetryAxis.h>
#include <tixi.h>
#include "CPACSGenericSystem_geometricBaseType.h"
#include "CTiglUIDObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSGenericSystems;

namespace generated
{
    // This class is used in:
    // CPACSGenericSystems

    /// @brief Generic system type containing describing the basic dimensions of a system component using simple geometric shapes
    /// 
    /// The generic base types must be one of the following cone|sphere|cube|cylinder. The origin of the shapes is at the center of volume for cube, sphere and cylinder. Since the cone is constructued from a cylindric shape, its origin is at the same location as the origin of the basic cylinder, although not any longer the center of volume due to scaling of one side. While cube and sphere are symmetrical in all three axis, cylinder and cone are standing upright in the direction of cpacs z-axis. The tip of the cone is located in direction of the positive z-axis. The figure below illustrates the default position and orientation of the different shapes. Note that the cube, cylinder and sphere were moved along the x-axis for demonstration by 2, 4 and 6 meters respectively.
    /// For spheres the default diameter is 1m. Cubes have a length of 1m in all three dimensions. Cylinders have a length of 1m and a diameter of 1m for the circular cross section. The cone is a cylinder with the top face scaled down to zero.
    /// @see geometricBaseType
    /// 
    class CPACSGenericSystem : public CTiglReqUIDObject
    {
    public:
        TIGL_EXPORT CPACSGenericSystem(CCPACSGenericSystems* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSGenericSystem();

        TIGL_EXPORT CCPACSGenericSystems* GetParent();

        TIGL_EXPORT const CCPACSGenericSystems* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<TiglSymmetryAxis>& GetSymmetry() const;
        TIGL_EXPORT virtual void SetSymmetry(const boost::optional<TiglSymmetryAxis>& value);

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSGenericSystem_geometricBaseType>& GetGeometricBaseType() const;
        TIGL_EXPORT virtual void SetGeometricBaseType(const boost::optional<CPACSGenericSystem_geometricBaseType>& value);

        TIGL_EXPORT virtual const CCPACSTransformation& GetTransformation() const;
        TIGL_EXPORT virtual CCPACSTransformation& GetTransformation();

    protected:
        CCPACSGenericSystems* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                                           m_uID;

        boost::optional<TiglSymmetryAxis>                     m_symmetry;

        /// Name of the system component.
        std::string                                           m_name;

        /// Description of the system component.
        boost::optional<std::string>                          m_description;

        /// Enum for selecting the basic shape of the
        /// component
        boost::optional<CPACSGenericSystem_geometricBaseType> m_geometricBaseType;

        CCPACSTransformation                                  m_transformation;

    private:
        CPACSGenericSystem(const CPACSGenericSystem&) = delete;
        CPACSGenericSystem& operator=(const CPACSGenericSystem&) = delete;

        CPACSGenericSystem(CPACSGenericSystem&&) = delete;
        CPACSGenericSystem& operator=(CPACSGenericSystem&&) = delete;
    };
} // namespace generated

// CPACSGenericSystem is customized, use type CCPACSGenericSystem directly
} // namespace tigl
