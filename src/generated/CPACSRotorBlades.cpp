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
#include <CCPACSWing.h>
#include "CCPACSRotorcraftModel.h"
#include "CPACSRotorBlades.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
    namespace generated
    {
        CPACSRotorBlades::CPACSRotorBlades(CCPACSRotorcraftModel* parent, CTiglUIDManager* uidMgr) :
            m_uidMgr(uidMgr)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSRotorBlades::~CPACSRotorBlades() {}
        
        CCPACSRotorcraftModel* CPACSRotorBlades::GetParent() const
        {
            return m_parent;
        }
        
        CTiglUIDManager& CPACSRotorBlades::GetUIDManager()
        {
            return *m_uidMgr;
        }
        
        const CTiglUIDManager& CPACSRotorBlades::GetUIDManager() const
        {
            return *m_uidMgr;
        }
        
        void CPACSRotorBlades::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read element rotorBlade
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/rotorBlade")) {
                tixihelper::TixiReadElements(tixiHandle, xpath + "/rotorBlade", m_rotorBlades, reinterpret_cast<CCPACSRotorBlades*>(this), m_uidMgr);
            }
            
        }
        
        void CPACSRotorBlades::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write element rotorBlade
            tixihelper::TixiSaveElements(tixiHandle, xpath + "/rotorBlade", m_rotorBlades);
            
        }
        
        const std::vector<unique_ptr<CCPACSWing> >& CPACSRotorBlades::GetRotorBlades() const
        {
            return m_rotorBlades;
        }
        
        std::vector<unique_ptr<CCPACSWing> >& CPACSRotorBlades::GetRotorBlades()
        {
            return m_rotorBlades;
        }
        
    }
}
