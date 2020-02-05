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
#include <CCPACSSkinSegment.h>
#include "CPACSSkin.h"
#include "CPACSSkinSegments.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSkinSegments::CPACSSkinSegments(CPACSSkin* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSSkinSegments::~CPACSSkinSegments()
    {
    }

    const CPACSSkin* CPACSSkinSegments::GetParent() const
    {
        return m_parent;
    }

    CPACSSkin* CPACSSkinSegments::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSSkinSegments::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSSkinSegments::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSSkinSegments::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSSkinSegments::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSSkinSegments::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element skinSegment
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/skinSegment")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/skinSegment", m_skinSegments, 1, tixi::xsdUnbounded, this, m_uidMgr);
        }

    }

    void CPACSSkinSegments::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element skinSegment
        tixi::TixiSaveElements(tixiHandle, xpath + "/skinSegment", m_skinSegments);

    }

    const std::vector<std::unique_ptr<CCPACSSkinSegment>>& CPACSSkinSegments::GetSkinSegments() const
    {
        return m_skinSegments;
    }

    std::vector<std::unique_ptr<CCPACSSkinSegment>>& CPACSSkinSegments::GetSkinSegments()
    {
        return m_skinSegments;
    }

    CCPACSSkinSegment& CPACSSkinSegments::AddSkinSegment()
    {
        m_skinSegments.push_back(make_unique<CCPACSSkinSegment>(this, m_uidMgr));
        return *m_skinSegments.back();
    }

    void CPACSSkinSegments::RemoveSkinSegment(CCPACSSkinSegment& ref)
    {
        for (std::size_t i = 0; i < m_skinSegments.size(); i++) {
            if (m_skinSegments[i].get() == &ref) {
                m_skinSegments.erase(m_skinSegments.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
