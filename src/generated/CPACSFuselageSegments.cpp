// Copyright (c) 2016 RISC Software GmbH
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
#include <CCPACSFuselageSegment.h>
#include "CCPACSFuselage.h"
#include "CPACSFuselageSegments.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSFuselageSegments::CPACSFuselageSegments(CCPACSFuselage* parent, CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSFuselageSegments::~CPACSFuselageSegments() {}
        
        CCPACSFuselage* CPACSFuselageSegments::GetParent() const
        {
            return m_parent;
        }
        
        CTiglUIDManager& CPACSFuselageSegments::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSFuselageSegments::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSFuselageSegments::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element segment
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/segment")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/segment", m_segments, reinterpret_cast<CCPACSFuselageSegments*>(this), m_uidMgr);
            }
            
        }
        
        void CPACSFuselageSegments::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element segment
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/segment", m_segments);
            
        }
        
        const std::vector<unique_ptr<CCPACSFuselageSegment> >& CPACSFuselageSegments::GetSegments() const
        {
            return m_segments;
        }
        
        std::vector<unique_ptr<CCPACSFuselageSegment> >& CPACSFuselageSegments::GetSegments()
        {
            return m_segments;
        }
        
    }
}
