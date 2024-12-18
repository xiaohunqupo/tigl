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

#include <cassert>
#include "CPACSDeckElementMass.h"
#include "CPACSMassInertia.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSMassInertia::CPACSMassInertia(CPACSDeckElementMass* parent)
        : m_Jxx(0)
        , m_Jyy(0)
        , m_Jzz(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSMassInertia::~CPACSMassInertia()
    {
    }

    const CPACSDeckElementMass* CPACSMassInertia::GetParent() const
    {
        return m_parent;
    }

    CPACSDeckElementMass* CPACSMassInertia::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSMassInertia::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSMassInertia::GetNextUIDParent()
    {
        return m_parent;
    }

    void CPACSMassInertia::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element Jxx
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/Jxx")) {
            m_Jxx = tixi::TixiGetElement<double>(tixiHandle, xpath + "/Jxx");
        }
        else {
            LOG(ERROR) << "Required element Jxx is missing at xpath " << xpath;
        }

        // read element Jyy
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/Jyy")) {
            m_Jyy = tixi::TixiGetElement<double>(tixiHandle, xpath + "/Jyy");
        }
        else {
            LOG(ERROR) << "Required element Jyy is missing at xpath " << xpath;
        }

        // read element Jzz
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/Jzz")) {
            m_Jzz = tixi::TixiGetElement<double>(tixiHandle, xpath + "/Jzz");
        }
        else {
            LOG(ERROR) << "Required element Jzz is missing at xpath " << xpath;
        }

        // read element Jxy
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/Jxy")) {
            m_Jxy = tixi::TixiGetElement<double>(tixiHandle, xpath + "/Jxy");
        }

        // read element Jxz
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/Jxz")) {
            m_Jxz = tixi::TixiGetElement<double>(tixiHandle, xpath + "/Jxz");
        }

        // read element Jyz
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/Jyz")) {
            m_Jyz = tixi::TixiGetElement<double>(tixiHandle, xpath + "/Jyz");
        }

    }

    void CPACSMassInertia::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element Jxx
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/Jxx");
        tixi::TixiSaveElement(tixiHandle, xpath + "/Jxx", m_Jxx);

        // write element Jyy
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/Jyy");
        tixi::TixiSaveElement(tixiHandle, xpath + "/Jyy", m_Jyy);

        // write element Jzz
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/Jzz");
        tixi::TixiSaveElement(tixiHandle, xpath + "/Jzz", m_Jzz);

        // write element Jxy
        if (m_Jxy) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/Jxy");
            tixi::TixiSaveElement(tixiHandle, xpath + "/Jxy", *m_Jxy);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/Jxy")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/Jxy");
            }
        }

        // write element Jxz
        if (m_Jxz) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/Jxz");
            tixi::TixiSaveElement(tixiHandle, xpath + "/Jxz", *m_Jxz);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/Jxz")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/Jxz");
            }
        }

        // write element Jyz
        if (m_Jyz) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/Jyz");
            tixi::TixiSaveElement(tixiHandle, xpath + "/Jyz", *m_Jyz);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/Jyz")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/Jyz");
            }
        }

    }

    const double& CPACSMassInertia::GetJxx() const
    {
        return m_Jxx;
    }

    void CPACSMassInertia::SetJxx(const double& value)
    {
        m_Jxx = value;
    }

    const double& CPACSMassInertia::GetJyy() const
    {
        return m_Jyy;
    }

    void CPACSMassInertia::SetJyy(const double& value)
    {
        m_Jyy = value;
    }

    const double& CPACSMassInertia::GetJzz() const
    {
        return m_Jzz;
    }

    void CPACSMassInertia::SetJzz(const double& value)
    {
        m_Jzz = value;
    }

    const boost::optional<double>& CPACSMassInertia::GetJxy() const
    {
        return m_Jxy;
    }

    void CPACSMassInertia::SetJxy(const boost::optional<double>& value)
    {
        m_Jxy = value;
    }

    const boost::optional<double>& CPACSMassInertia::GetJxz() const
    {
        return m_Jxz;
    }

    void CPACSMassInertia::SetJxz(const boost::optional<double>& value)
    {
        m_Jxz = value;
    }

    const boost::optional<double>& CPACSMassInertia::GetJyz() const
    {
        return m_Jyz;
    }

    void CPACSMassInertia::SetJyz(const boost::optional<double>& value)
    {
        m_Jyz = value;
    }

} // namespace generated
} // namespace tigl