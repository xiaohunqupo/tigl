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
#include "CCPACSRotorHinges.h"
#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSRotorHubHinge.h"

namespace tigl
{
    namespace generated
    {
        CPACSRotorHubHinge::CPACSRotorHubHinge(CCPACSRotorHinges* parent)
        {
            //assert(parent != NULL);
            m_parent = parent;
        }
        
        CPACSRotorHubHinge::~CPACSRotorHubHinge() {}
        
        CCPACSRotorHinges* CPACSRotorHubHinge::GetParent() const
        {
            return m_parent;
        }
        
        void CPACSRotorHubHinge::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute uID
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                m_uID = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            }
            
            // read element name
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/name")) {
                m_name = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            }
            
            // read element description
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/description")) {
                m_description = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            }
            
            // read element transformation
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/transformation")) {
                m_transformation.ReadCPACS(tixiHandle, xpath + "/transformation");
            }
            else {
                LOG(ERROR) << "Required element transformation is missing";
            }
            
            // read element type
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/type")) {
                m_type = stringToCPACSRotorHubHinge_type(tixihelper::TixiGetElement<std::string>(tixiHandle, xpath + "/type"));
            }
            else {
                LOG(ERROR) << "Required element type is missing";
            }
            
            // read element neutralPosition
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/neutralPosition")) {
                m_neutralPosition = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/neutralPosition");
            }
            
            // read element staticStiffness
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/staticStiffness")) {
                m_staticStiffness = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/staticStiffness");
            }
            
            // read element dynamicStiffness
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/dynamicStiffness")) {
                m_dynamicStiffness = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/dynamicStiffness");
            }
            
            // read element damping
            if (tixihelper::TixiCheckElement(tixiHandle, xpath + "/damping")) {
                m_damping = tixihelper::TixiGetElement<double>(tixiHandle, xpath + "/damping");
            }
            
        }
        
        void CPACSRotorHubHinge::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute uID
            if (m_uID) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uID");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
            }
            
            // write element name
            if (m_name) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/name", *m_name);
            }
            
            // write element description
            if (m_description) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
            }
            
            // write element transformation
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/transformation");
            m_transformation.WriteCPACS(tixiHandle, xpath + "/transformation");
            
            // write element type
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/type");
            tixihelper::TixiSaveElement(tixiHandle, xpath + "/type", CPACSRotorHubHinge_typeToString(m_type));
            
            // write element neutralPosition
            if (m_neutralPosition) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/neutralPosition");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/neutralPosition", *m_neutralPosition);
            }
            
            // write element staticStiffness
            if (m_staticStiffness) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/staticStiffness");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/staticStiffness", *m_staticStiffness);
            }
            
            // write element dynamicStiffness
            if (m_dynamicStiffness) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/dynamicStiffness");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/dynamicStiffness", *m_dynamicStiffness);
            }
            
            // write element damping
            if (m_damping) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/damping");
                tixihelper::TixiSaveElement(tixiHandle, xpath + "/damping", *m_damping);
            }
            
        }
        
        bool CPACSRotorHubHinge::HasUID() const
        {
            return static_cast<bool>(m_uID);
        }
        
        const std::string& CPACSRotorHubHinge::GetUID() const
        {
            return *m_uID;
        }
        
        void CPACSRotorHubHinge::SetUID(const std::string& value)
        {
            m_uID = value;
        }
        
        bool CPACSRotorHubHinge::HasName() const
        {
            return static_cast<bool>(m_name);
        }
        
        const std::string& CPACSRotorHubHinge::GetName() const
        {
            return *m_name;
        }
        
        void CPACSRotorHubHinge::SetName(const std::string& value)
        {
            m_name = value;
        }
        
        bool CPACSRotorHubHinge::HasDescription() const
        {
            return static_cast<bool>(m_description);
        }
        
        const std::string& CPACSRotorHubHinge::GetDescription() const
        {
            return *m_description;
        }
        
        void CPACSRotorHubHinge::SetDescription(const std::string& value)
        {
            m_description = value;
        }
        
        const CCPACSTransformation& CPACSRotorHubHinge::GetTransformation() const
        {
            return m_transformation;
        }
        
        CCPACSTransformation& CPACSRotorHubHinge::GetTransformation()
        {
            return m_transformation;
        }
        
        const CPACSRotorHubHinge_type& CPACSRotorHubHinge::GetType() const
        {
            return m_type;
        }
        
        void CPACSRotorHubHinge::SetType(const CPACSRotorHubHinge_type& value)
        {
            m_type = value;
        }
        
        bool CPACSRotorHubHinge::HasNeutralPosition() const
        {
            return static_cast<bool>(m_neutralPosition);
        }
        
        const double& CPACSRotorHubHinge::GetNeutralPosition() const
        {
            return *m_neutralPosition;
        }
        
        void CPACSRotorHubHinge::SetNeutralPosition(const double& value)
        {
            m_neutralPosition = value;
        }
        
        bool CPACSRotorHubHinge::HasStaticStiffness() const
        {
            return static_cast<bool>(m_staticStiffness);
        }
        
        const double& CPACSRotorHubHinge::GetStaticStiffness() const
        {
            return *m_staticStiffness;
        }
        
        void CPACSRotorHubHinge::SetStaticStiffness(const double& value)
        {
            m_staticStiffness = value;
        }
        
        bool CPACSRotorHubHinge::HasDynamicStiffness() const
        {
            return static_cast<bool>(m_dynamicStiffness);
        }
        
        const double& CPACSRotorHubHinge::GetDynamicStiffness() const
        {
            return *m_dynamicStiffness;
        }
        
        void CPACSRotorHubHinge::SetDynamicStiffness(const double& value)
        {
            m_dynamicStiffness = value;
        }
        
        bool CPACSRotorHubHinge::HasDamping() const
        {
            return static_cast<bool>(m_damping);
        }
        
        const double& CPACSRotorHubHinge::GetDamping() const
        {
            return *m_damping;
        }
        
        void CPACSRotorHubHinge::SetDamping(const double& value)
        {
            m_damping = value;
        }
        
    }
}