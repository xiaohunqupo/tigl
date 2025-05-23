/*
* Copyright (C) 2022 German Aerospace Center (DLR/SC)
*
* Created: 2022-03-16 Jan Kleinert <Jan.Kleinert@dlr.de>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#pragma once

#include "generated/CPACSSkin.h"

namespace tigl {

class CTiglRelativelyPositionedComponent;

class CCPACSSkin : public generated::CPACSSkin
{
public:
    TIGL_EXPORT CCPACSSkin(CCPACSDuctStructure* parent, CTiglUIDManager* uidMgr);
    TIGL_EXPORT CCPACSSkin(CCPACSFuselageStructure* parent, CTiglUIDManager* uidMgr);
    TIGL_EXPORT CCPACSSkin(CCPACSVesselSkinLayers* parent, CTiglUIDManager* uidMgr);

    // returns the parent as abstract geometric component
    TIGL_EXPORT CTiglRelativelyPositionedComponent const* GetParentComponent() const;
};

} //namespace tigl
