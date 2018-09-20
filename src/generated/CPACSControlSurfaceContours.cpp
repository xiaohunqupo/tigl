// Copyright (c) 2018 RISC Software GmbH
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

#include "CPACSControlSurfaceAirfoil.h"
#include "CPACSControlSurfaceContours.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSControlSurfaceContours::CPACSControlSurfaceContours()
    {
    }

    CPACSControlSurfaceContours::~CPACSControlSurfaceContours()
    {
    }

    void CPACSControlSurfaceContours::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element intermediateAirfoil
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/intermediateAirfoil")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/intermediateAirfoil", m_intermediateAirfoils);
        }

    }

    void CPACSControlSurfaceContours::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element intermediateAirfoil
        tixi::TixiSaveElements(tixiHandle, xpath + "/intermediateAirfoil", m_intermediateAirfoils);

    }

    const std::vector<unique_ptr<CPACSControlSurfaceAirfoil> >& CPACSControlSurfaceContours::GetIntermediateAirfoils() const
    {
        return m_intermediateAirfoils;
    }

    std::vector<unique_ptr<CPACSControlSurfaceAirfoil> >& CPACSControlSurfaceContours::GetIntermediateAirfoils()
    {
        return m_intermediateAirfoils;
    }

    CPACSControlSurfaceAirfoil& CPACSControlSurfaceContours::AddIntermediateAirfoil()
    {
        m_intermediateAirfoils.push_back(make_unique<CPACSControlSurfaceAirfoil>());
        return *m_intermediateAirfoils.back();
    }

    void CPACSControlSurfaceContours::RemoveIntermediateAirfoil(CPACSControlSurfaceAirfoil& ref)
    {
        for (std::size_t i = 0; i < m_intermediateAirfoils.size(); i++) {
            if (m_intermediateAirfoils[i].get() == &ref) {
                m_intermediateAirfoils.erase(m_intermediateAirfoils.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl