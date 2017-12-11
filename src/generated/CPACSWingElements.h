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

#pragma once

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
    class CTiglUIDManager;
    class CCPACSWingSectionElement;
    class CCPACSWingSection;
    
    namespace generated
    {
        // This class is used in:
        // CPACSWingSection
        
        // generated from /xsd:schema/xsd:complexType[930]
        class CPACSWingElements
        {
        public:
            TIGL_EXPORT CPACSWingElements(CCPACSWingSection* parent, CTiglUIDManager* uidMgr);
            
            TIGL_EXPORT virtual ~CPACSWingElements();
            
            TIGL_EXPORT CCPACSWingSection* GetParent() const;
            
            TIGL_EXPORT CTiglUIDManager& GetUIDManager();
            TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSWingSectionElement> >& GetElements() const;
            TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSWingSectionElement> >& GetElements();
            
            TIGL_EXPORT virtual CCPACSWingSectionElement& AddElement();
            TIGL_EXPORT virtual void RemoveElement(CCPACSWingSectionElement& ref);
            
        protected:
            CCPACSWingSection* m_parent;
            
            CTiglUIDManager* m_uidMgr;
            
            std::vector<unique_ptr<CCPACSWingSectionElement> > m_elements;
            
        private:
            #ifdef HAVE_CPP11
            CPACSWingElements(const CPACSWingElements&) = delete;
            CPACSWingElements& operator=(const CPACSWingElements&) = delete;
            
            CPACSWingElements(CPACSWingElements&&) = delete;
            CPACSWingElements& operator=(CPACSWingElements&&) = delete;
            #else
            CPACSWingElements(const CPACSWingElements&);
            CPACSWingElements& operator=(const CPACSWingElements&);
            #endif
        };
    }
    
    // CPACSWingElements is customized, use type CCPACSWingSectionElements directly
}
