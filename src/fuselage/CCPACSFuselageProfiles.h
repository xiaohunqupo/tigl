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
* @brief  Implementation of CPACS fuselage profiles handling routines.
*/

#ifndef CCPACSFUSELAGEPROFILES_H
#define CCPACSFUSELAGEPROFILES_H

#include <string>
#include <boost/optional.hpp>

#include "generated/CPACSFuselageProfiles.h"
#include "CCPACSFuselageProfile.h"

namespace tigl
{

class CCPACSFuselageProfiles : public generated::CPACSFuselageProfiles
{
public:
    TIGL_EXPORT CCPACSFuselageProfiles(CCPACSProfiles* parent, CTiglUIDManager* uidMgr);

    // Read CPACS fuselage profiles
    TIGL_EXPORT void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) override;

    TIGL_EXPORT CCPACSFuselageProfile& AddFuselageProfile() override;

    TIGL_EXPORT bool HasProfile(std::string uid) const;

    // Adds a CPACS fuselage profile to list
    TIGL_EXPORT void AddProfile(CCPACSFuselageProfile* profile);
    
    // Removes a CPACS wing profile from the list
    TIGL_EXPORT void DeleteProfile(std::string uid );

    // Returns the total count of fuselage profiles in this configuration
    TIGL_EXPORT size_t GetProfileCount() const;

    // Returns the fuselage profile for a given index.
    TIGL_EXPORT const CCPACSFuselageProfile& GetProfile(size_t index) const;
    TIGL_EXPORT CCPACSFuselageProfile& GetProfile(size_t index);

    // Returns the fuselage profile for a given uid.
    TIGL_EXPORT const CCPACSFuselageProfile& GetProfile(std::string uid) const;
    TIGL_EXPORT CCPACSFuselageProfile& GetProfile(std::string uid);

    // Invalidates internal state
    TIGL_EXPORT void Invalidate(const boost::optional<std::string>& source = boost::none) const;
};

} // end namespace tigl

#endif // CCPACSFUSELAGEPROFILES_H
