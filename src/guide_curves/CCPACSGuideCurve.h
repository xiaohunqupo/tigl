/*
* Copyright (C) 2007-2014 German Aerospace Center (DLR/SC)
*
* Created: 2014-02-10 Tobias Stollenwerk <tobias.stollenwerk@dlr.de>
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
/**
* @file
* @brief  Implementation of a CPACS guide curve profile
*/

#ifndef CCPACSGUIDECURVE_H
#define CCPACSGUIDECURVE_H

#include "tigl_internal.h"
#include "tixi.h"
#include "CSharedPtr.h"
#include "generated/CPACSGuideCurve.h"
#include "generated/UniquePtr.h"
#include "Cache.h"

#include <gp_Pnt.hxx>
#include <TopoDS_Edge.hxx>

#include <vector>
#include <string>

namespace tigl
{

class CTiglPoint;
typedef class CSharedPtr<CTiglPoint> PCTiglPoint;

class IGuideCurveBuilder;

class CCPACSGuideCurve : public generated::CPACSGuideCurve
{
public:
    enum FromOrToDefinition
    {
        UID,
        CIRCUMFERENCE,
        PARAMETER
    };

private:
    // Typedefs for a container to store the coordinates of a guide curve element.
    typedef std::vector<PCTiglPoint> CCPACSGuideCurvePoints;

public:
    // Constructor
    TIGL_EXPORT CCPACSGuideCurve(CCPACSGuideCurves* parent, CTiglUIDManager* uidMgr);

    // Virtual Destructor
    TIGL_EXPORT ~CCPACSGuideCurve(void) override;

    TIGL_EXPORT FromOrToDefinition GetFromDefinition() const;
    TIGL_EXPORT FromOrToDefinition GetToDefinition() const;

    // Returns the value which defines the position of the starting point of a guide curve
    // Depending on used CPACS node it is either based on the relative circumference, the parameter or the guide curve uid
    TIGL_EXPORT double GetFromDefinitionValue() const;

    // Returns the value which defines the position of the end point of a guide curve
    // Depending on used CPACS node it is either based on the relative circumference or the parameter
    TIGL_EXPORT double GetToDefinitionValue() const;

    TIGL_EXPORT std::vector<gp_Pnt> GetCurvePoints() const;
    TIGL_EXPORT TopoDS_Edge GetCurve() const;

    TIGL_EXPORT CCPACSGuideCurve* GetConnectedCurve() const;
    TIGL_EXPORT CCPACSGuideCurve const* GetRootCurve() const;

    TIGL_EXPORT void SetGuideCurveBuilder(IGuideCurveBuilder& b);
protected:
    // Cleanup routine
    void Cleanup(void);

private:
    // Copy constructor
    CCPACSGuideCurve(const CCPACSGuideCurve&);

    // Assignment operator
    void operator=(const CCPACSGuideCurve&);

    // Invalidates internal state
    void InvalidateImpl(const boost::optional<std::string>& source) const override;

    void BuildCurve(TopoDS_Edge& cache) const;

    Cache<TopoDS_Edge, CCPACSGuideCurve> guideCurveTopo; /**< Actual topological entity of the curve */

    IGuideCurveBuilder* m_builder;

};

class IGuideCurveBuilder
{
public:
    virtual std::vector<gp_Pnt> BuildGuideCurvePnts(const CCPACSGuideCurve*) const = 0;
    virtual ~IGuideCurveBuilder();
};

} // end namespace tigl

#endif // CCPACSGUIDECURVE_H

