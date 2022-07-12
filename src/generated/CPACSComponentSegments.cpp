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
#include <CCPACSWingComponentSegment.h>
#include "CCPACSWing.h"
#include "CPACSComponentSegments.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSComponentSegments::CPACSComponentSegments(CCPACSWing* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSComponentSegments::~CPACSComponentSegments()
    {
    }

    const CCPACSWing* CPACSComponentSegments::GetParent() const
    {
        return m_parent;
    }

    CCPACSWing* CPACSComponentSegments::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSComponentSegments::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSComponentSegments::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSComponentSegments::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSComponentSegments::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSComponentSegments::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element componentSegment
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/componentSegment")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/componentSegment", m_componentSegments, 1, tixi::xsdUnbounded, reinterpret_cast<CCPACSWingComponentSegments*>(this), m_uidMgr);
        }

    }

    void CPACSComponentSegments::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element componentSegment
        tixi::TixiSaveElements(tixiHandle, xpath + "/componentSegment", m_componentSegments);

    }

    const std::vector<std::unique_ptr<CCPACSWingComponentSegment>>& CPACSComponentSegments::GetComponentSegments() const
    {
        return m_componentSegments;
    }

    std::vector<std::unique_ptr<CCPACSWingComponentSegment>>& CPACSComponentSegments::GetComponentSegments()
    {
        return m_componentSegments;
    }

    CCPACSWingComponentSegment& CPACSComponentSegments::AddComponentSegment()
    {
        m_componentSegments.push_back(make_unique<CCPACSWingComponentSegment>(reinterpret_cast<CCPACSWingComponentSegments*>(this), m_uidMgr));
        return *m_componentSegments.back();
    }

    void CPACSComponentSegments::RemoveComponentSegment(CCPACSWingComponentSegment& ref)
    {
        for (std::size_t i = 0; i < m_componentSegments.size(); i++) {
            if (m_componentSegments[i].get() == &ref) {
                m_componentSegments.erase(m_componentSegments.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
