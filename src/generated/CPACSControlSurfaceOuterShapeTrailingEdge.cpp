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
#include "CCPACSTrailingEdgeDevice.h"
#include "CPACSControlSurfaceOuterShapeTrailingEdge.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSControlSurfaceOuterShapeTrailingEdge::CPACSControlSurfaceOuterShapeTrailingEdge(CCPACSTrailingEdgeDevice* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_innerBorder(this, m_uidMgr)
        , m_outerBorder(this, m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSControlSurfaceOuterShapeTrailingEdge::~CPACSControlSurfaceOuterShapeTrailingEdge()
    {
    }

    const CCPACSTrailingEdgeDevice* CPACSControlSurfaceOuterShapeTrailingEdge::GetParent() const
    {
        return m_parent;
    }

    CCPACSTrailingEdgeDevice* CPACSControlSurfaceOuterShapeTrailingEdge::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSControlSurfaceOuterShapeTrailingEdge::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSControlSurfaceOuterShapeTrailingEdge::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSControlSurfaceOuterShapeTrailingEdge::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSControlSurfaceOuterShapeTrailingEdge::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSControlSurfaceOuterShapeTrailingEdge::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element innerBorder
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/innerBorder")) {
            m_innerBorder.ReadCPACS(tixiHandle, xpath + "/innerBorder");
        }
        else {
            LOG(ERROR) << "Required element innerBorder is missing at xpath " << xpath;
        }

        // read element outerBorder
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/outerBorder")) {
            m_outerBorder.ReadCPACS(tixiHandle, xpath + "/outerBorder");
        }
        else {
            LOG(ERROR) << "Required element outerBorder is missing at xpath " << xpath;
        }

        // read element intermediateAirfoils
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/intermediateAirfoils")) {
            m_intermediateAirfoils = boost::in_place(this, m_uidMgr);
            try {
                m_intermediateAirfoils->ReadCPACS(tixiHandle, xpath + "/intermediateAirfoils");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read intermediateAirfoils at xpath " << xpath << ": " << e.what();
                m_intermediateAirfoils = boost::none;
            }
        }

    }

    void CPACSControlSurfaceOuterShapeTrailingEdge::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "innerBorder", "outerBorder", "intermediateAirfoils" };

        // write element innerBorder
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/innerBorder", childElemOrder);
        m_innerBorder.WriteCPACS(tixiHandle, xpath + "/innerBorder");

        // write element outerBorder
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/outerBorder", childElemOrder);
        m_outerBorder.WriteCPACS(tixiHandle, xpath + "/outerBorder");

        // write element intermediateAirfoils
        if (m_intermediateAirfoils) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/intermediateAirfoils", childElemOrder);
            m_intermediateAirfoils->WriteCPACS(tixiHandle, xpath + "/intermediateAirfoils");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/intermediateAirfoils")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/intermediateAirfoils");
            }
        }

    }

    const CCPACSControlSurfaceBorderTrailingEdge& CPACSControlSurfaceOuterShapeTrailingEdge::GetInnerBorder() const
    {
        return m_innerBorder;
    }

    CCPACSControlSurfaceBorderTrailingEdge& CPACSControlSurfaceOuterShapeTrailingEdge::GetInnerBorder()
    {
        return m_innerBorder;
    }

    const CCPACSControlSurfaceBorderTrailingEdge& CPACSControlSurfaceOuterShapeTrailingEdge::GetOuterBorder() const
    {
        return m_outerBorder;
    }

    CCPACSControlSurfaceBorderTrailingEdge& CPACSControlSurfaceOuterShapeTrailingEdge::GetOuterBorder()
    {
        return m_outerBorder;
    }

    const boost::optional<CPACSControlSurfaceContours>& CPACSControlSurfaceOuterShapeTrailingEdge::GetIntermediateAirfoils() const
    {
        return m_intermediateAirfoils;
    }

    boost::optional<CPACSControlSurfaceContours>& CPACSControlSurfaceOuterShapeTrailingEdge::GetIntermediateAirfoils()
    {
        return m_intermediateAirfoils;
    }

    CPACSControlSurfaceContours& CPACSControlSurfaceOuterShapeTrailingEdge::GetIntermediateAirfoils(CreateIfNotExistsTag)
    {
        if (!m_intermediateAirfoils)
            m_intermediateAirfoils = boost::in_place(this, m_uidMgr);
        return *m_intermediateAirfoils;
    }

    void CPACSControlSurfaceOuterShapeTrailingEdge::RemoveIntermediateAirfoils()
    {
        m_intermediateAirfoils = boost::none;
    }

} // namespace generated
} // namespace tigl
