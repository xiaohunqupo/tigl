/* 
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
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
/**
* @file 
* @brief  Implementation of CPACS fuselage sections handling routines.
*/

#ifndef CCPACSFUSELAGESECTIONS_H
#define CCPACSFUSELAGESECTIONS_H

#include "generated/CPACSFuselageSections.h"
#include "tigl_internal.h"
#include "tixi.h"
#include <string>
#include <vector>

namespace tigl
{

class CCPACSFuselageSection;

class CCPACSFuselageSections : public generated::CPACSFuselageSections
{
public:
    TIGL_EXPORT CCPACSFuselageSections(CCPACSFuselage* parent, CTiglUIDManager* uidMgr);
    TIGL_EXPORT CCPACSFuselageSections(CCPACSDuct* parent, CTiglUIDManager* uidMgr);
    TIGL_EXPORT CCPACSFuselageSections(CCPACSVessel* parent, CTiglUIDManager* uidMgr);

    // Get section count
    TIGL_EXPORT int GetSectionCount() const;

    // Returns the section for a given index
    TIGL_EXPORT CCPACSFuselageSection& GetSection(int index) const;

    // Returns the section for a given uid
    TIGL_EXPORT CCPACSFuselageSection& GetSection(const std::string& sectionUID);
};

} // end namespace tigl

#endif // CCPACSFUSELAGESECTIONS_H
