/* 
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2013-05-28 Martin Siggel <Martin.Siggel@dlr.de>
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

#include "CCPACSWingCells.h"

#include "CCPACSWingCell.h"
#include "CTiglError.h"

namespace tigl
{

CCPACSWingCells::CCPACSWingCells(CCPACSWingShell* parent, CTiglUIDManager* uidMgr)
    : generated::CPACSWingCells(parent, uidMgr) {}

void CCPACSWingCells::Invalidate(const boost::optional<std::string>& source) const
{
    for (size_t i = 0; i < m_cells.size(); i++) {
        m_cells[i]->Invalidate(source);
    }
}
} // namespace tigl
