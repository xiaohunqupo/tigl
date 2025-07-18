/*
* Copyright (C) 2007-2014 German Aerospace Center (DLR/SC)
*
* Created: 2014-02-10 Tobias Stollenwerk <Tobias.Stollenwerk@dlr.de>
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
* @brief Tests for wing guide curves
*/

#include "test.h" // Brings in the GTest framework
#include "tigl.h"
#include "testUtils.h"
#include "tiglcommonfunctions.h"
#include "CSharedPtr.h"
#include "CCPACSConfigurationManager.h"
#include "BRep_Tool.hxx"
#include "TopoDS_Shape.hxx"
#include "TopTools_SequenceOfShape.hxx"
#include "TopExp_Explorer.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepTools_WireExplorer.hxx"
#include "Geom_Curve.hxx"
#include "Geom_Plane.hxx"
#include "Geom_Circle.hxx"
#include "gp_Pnt.hxx"
#include "gp_Vec.hxx"
#include "BRep_Builder.hxx"
#include "GeomAPI_IntCS.hxx"
#include "GeomAPI_ProjectPointOnCurve.hxx"
#include "CTiglError.h"
#include "CTiglTransformation.h"
#include "CCPACSGuideCurveProfile.h"
#include "generated/CPACSGuideCurveProfiles.h"
#include "generated/CPACSGuideCurve.h"
#include "CCPACSGuideCurves.h"
#include "CCPACSWingProfileGetPointAlgo.h"
#include "CCPACSGuideCurveAlgo.h"
#include "CCPACSWingSegment.h"
#include "tiglcommonfunctions.h"
#include "CTiglWingSegmentGuidecurveBuilder.h"

/******************************************************************************/

typedef class CSharedPtr<tigl::CTiglPoint> PCTiglPoint;

class WingGuideCurve : public ::testing::Test
{
protected:
    void SetUp() override
    {
        const char* filename = "TestData/simple_test_guide_curves.xml";
        ReturnCode tixiRet;
        TiglReturnCode tiglRet;

        tiglHandle = -1;
        tixiHandle = -1;

        tixiRet = tixiOpenDocument(filename, &tixiHandle);
        ASSERT_TRUE (tixiRet == SUCCESS);
        tiglRet = tiglOpenCPACSConfiguration(tixiHandle, "GuideCurveModel", &tiglHandle);
        ASSERT_TRUE(tiglRet == TIGL_SUCCESS);

        // get guide curve
        //tigl::CCPACSGuideCurve & guideCurve = config.GetGuideCurve("GuideCurveModel_Wing_Sec1_El1_Pro");

        // constant values for the guide curve points
        const double tempy[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
        beta=std::vector<double>(tempy, tempy + sizeof(tempy) / sizeof(tempy[0]) );
        const double tempz[] = {0.0, 0.001, 0.003, 0.009, 0.008, 0.007, 0.006, 0.002, 0.0};
        gamma=std::vector<double>(tempz, tempz + sizeof(tempz) / sizeof(tempz[0]) );
    }

    void TearDown() override
    {
        ASSERT_TRUE(tiglCloseCPACSConfiguration(tiglHandle) == TIGL_SUCCESS);
        ASSERT_TRUE(tixiCloseDocument(tixiHandle) == SUCCESS);
        tiglHandle = -1;
        tixiHandle = -1;
    }

    TixiDocumentHandle           tixiHandle;
    TiglCPACSConfigurationHandle tiglHandle;
    //tigl::CCPACSGuideCurve guideCurve;
    std::vector<double> alpha;
    std::vector<double> beta;
    std::vector<double> gamma;
};


/******************************************************************************/

/**
* Tests CCPACSGuideCurveProfile class
*/
TEST_F(WingGuideCurve, tiglWingGuideCurve_CCPACSGuideCurveProfile)
{
    tigl::CCPACSGuideCurveProfile guideCurve(NULL, NULL);
    guideCurve.ReadCPACS(tixiHandle, "/cpacs/vehicles/profiles/guideCurves/guideCurveProfile[5]");
    ASSERT_EQ(guideCurve.GetUID(), "GuideCurveModel_Wing_GuideCurveProfile_LeadingEdge_NonLinear");
    ASSERT_EQ(guideCurve.GetName(), "NonLinear Leading Edge Guide Curve Profile for GuideCurveModel - Wing");
}

/**
* Tests CCPACSGuideCurveProfiles class
*/
TEST_F(WingGuideCurve, tiglWingGuideCurve_CCPACSGuideCurveProfiles)
{
    tigl::CCPACSGuideCurveProfiles guideCurves(NULL, NULL);
    guideCurves.ReadCPACS(tixiHandle, "/cpacs/vehicles/profiles/guideCurves");
    ASSERT_EQ(guideCurves.GetGuideCurveProfileCount(), 6);
    tigl::CCPACSGuideCurveProfile& guideCurve = guideCurves.GetGuideCurveProfile("GuideCurveModel_Wing_GuideCurveProfile_LeadingEdge_NonLinear");
    ASSERT_EQ(guideCurve.GetUID(), "GuideCurveModel_Wing_GuideCurveProfile_LeadingEdge_NonLinear");
    ASSERT_EQ(guideCurve.GetName(), "NonLinear Leading Edge Guide Curve Profile for GuideCurveModel - Wing");
}

/**
* Tests CCPACSGuideCurve class
*/
TEST_F(WingGuideCurve, tiglWingGuideCurve_CCPACSGuideCurve)
{
    tigl::CCPACSGuideCurve guideCurve(NULL, NULL);
    guideCurve.ReadCPACS(tixiHandle, "/cpacs/vehicles/aircraft/model/wings/wing/segments/segment[1]/guideCurves/guideCurve[1]");
    ASSERT_EQ(guideCurve.GetUID(), "GuideCurveModel_Wing_Seg_1_2_GuideCurve_TrailingEdgeLower");
    ASSERT_EQ(guideCurve.GetName(), "Lower Trailing Edge GuideCurve from GuideCurveModel - Wing Section 1 Main Element to GuideCurveModel - Wing Section 2 Main Element ");
    ASSERT_EQ(guideCurve.GetGuideCurveProfileUID(), "GuideCurveModel_Wing_GuideCurveProfile_TrailingEdgeLower_NonLinear");
    ASSERT_TRUE(guideCurve.GetFromRelativeCircumference_choice2_1());
    ASSERT_EQ(*guideCurve.GetFromRelativeCircumference_choice2_1(), -1.0);
    ASSERT_EQ(*guideCurve.GetToRelativeCircumference_choice1(), -1.0);
}

/**
* Tests CCPACSGuideCurves class
*/
TEST_F(WingGuideCurve, tiglWingGuideCurve_CCPACSGuideCurves)
{
    tigl::CCPACSGuideCurves guideCurves((tigl::CCPACSWingSegment*)NULL, NULL);
    guideCurves.ReadCPACS(tixiHandle, "/cpacs/vehicles/aircraft/model/wings/wing/segments/segment[2]/guideCurves");
    ASSERT_EQ(guideCurves.GetGuideCurveCount(), 3);
    const tigl::CCPACSGuideCurve& guideCurve = guideCurves.GetGuideCurve("GuideCurveModel_Wing_Seg_2_3_GuideCurve_LeadingEdge");
    ASSERT_EQ(guideCurve.GetUID(), "GuideCurveModel_Wing_Seg_2_3_GuideCurve_LeadingEdge");
    ASSERT_EQ(guideCurve.GetName(), "Leading Edge GuideCurve from GuideCurveModel - Wing Section 2 Main Element to GuideCurveModel - Wing Section 3 Main Element ");
    ASSERT_EQ(guideCurve.GetGuideCurveProfileUID(), "GuideCurveModel_Wing_GuideCurveProfile_LeadingEdge_NonLinear");
    ASSERT_TRUE(!guideCurve.GetFromRelativeCircumference_choice2_1());
    ASSERT_EQ(*guideCurve.GetFromGuideCurveUID_choice1(), "GuideCurveModel_Wing_Seg_1_2_GuideCurve_LeadingEdge_NonLinear" );
    ASSERT_EQ(*guideCurve.GetToRelativeCircumference_choice1(), 0.0);
}

/**
* Tests CCPACSWingProfileGetPointAlgo class
*/
TEST_F(WingGuideCurve, tiglWingGuideCurve_CCPACSWingProfileGetPointAlgoOnProfile)
{
    // read configuration
    tigl::CCPACSConfigurationManager& manager = tigl::CCPACSConfigurationManager::GetInstance();
    tigl::CCPACSConfiguration& config = manager.GetConfiguration(tiglHandle);

    // get upper and lower wing profile
    tigl::CCPACSWingProfile& profile = config.GetWingProfile("GuideCurveModel_Wing_Sec3_El1_Pro");
    TopoDS_Edge upperWire = profile.GetUpperWire();
    TopoDS_Edge lowerWire = profile.GetLowerWire();

    // concatenate wires
    TopTools_SequenceOfShape wireContainer;
    wireContainer.Append(lowerWire);
    wireContainer.Append(upperWire);

    // instantiate getPointAlgo
    tigl::CCPACSWingProfileGetPointAlgo getPointAlgo(wireContainer);
    gp_Pnt point;
    gp_Vec tangent;

    // plot points and tangents
    int N = 20;
    int M = 2;
    for (int i=0; i<=N+2*M; i++) {
        double da = 2.0/double(N);
        double alpha = -1.0 -M*da + da*i;
        getPointAlgo.GetPointTangent(alpha, point, tangent);
        outputXY(i, point.X(), point.Z(), "./TestData/analysis/tiglWingGuideCurve_profileSamplePoints_points.dat");
        outputXYVector(i, point.X(), point.Z(), tangent.X(), tangent.Z(), "./TestData/analysis/tiglWingGuideCurve_profileSamplePoints_tangents.dat");
        // plot points and tangents with gnuplot by:
        // echo "plot 'TestData/analysis/tiglWingGuideCurve_profileSamplePoints_tangents.dat' u 1:2:3:4 with vectors filled head lw 2, 'TestData/analysis/tiglWingGuideCurve_profileSamplePoints_points.dat' w linespoints lw 2" | gnuplot -persist
    }

    // leading edge: point must be zero and tangent must be in z-direction
    getPointAlgo.GetPointTangent(0.0, point, tangent);
    ASSERT_NEAR(point.X(), 0.0, 1E-10);
    ASSERT_NEAR(point.Y(), 0.0, 1E-10);
    ASSERT_NEAR(point.Z(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.X(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.Y(), 0.0, 1E-10);

    // lower trailing edge
    getPointAlgo.GetPointTangent(-1.0, point, tangent);
    ASSERT_NEAR(point.X(), 1.0, 1E-5);
    ASSERT_NEAR(point.Y(), 0.0, 1E-10);
    ASSERT_NEAR(point.Z(), -0.003, 1E-5);

    // upper trailing edge
    getPointAlgo.GetPointTangent(1.0, point, tangent);
    ASSERT_NEAR(point.X(), 1.0, 1E-10);
    ASSERT_NEAR(point.Y(), 0.0, 1E-10);
    ASSERT_NEAR(point.Z(), 0.00126, 1E-10);

    // check if tangent is constant for alpha > 1
    gp_Vec tangent2;
    getPointAlgo.GetPointTangent(1.0, point, tangent);
    getPointAlgo.GetPointTangent(2.0, point, tangent2);
    ASSERT_EQ(tangent.X(), tangent2.X());
    ASSERT_EQ(tangent.Y(), tangent2.Y());
    ASSERT_EQ(tangent.Z(), tangent2.Z());

    // check if tangent is constant for alpha < 1
    getPointAlgo.GetPointTangent(-1.0, point, tangent);
    getPointAlgo.GetPointTangent(-2.0, point, tangent2);
    ASSERT_EQ(tangent.X(), tangent2.X());
    ASSERT_EQ(tangent.Y(), tangent2.Y());
    ASSERT_EQ(tangent.Z(), tangent2.Z());
}

/**
* Tests CCPACSWingProfileGetPointAlgo class
*/
TEST_F(WingGuideCurve, tiglWingGuideCurve_CCPACSWingProfileGetPointAlgoOnCircle)
{
    double radius1=1.0;
    gp_Pnt location1(radius1, 0.0,  0.0);
    gp_Ax2 circlePosition1(location1, gp::DY(), gp::DX());
    Handle(Geom_Circle) circle1 = new Geom_Circle(circlePosition1, radius1);

    // cut into lower and upper half circle
    double start=0.0;
    double mid=start+M_PI;
    double end=mid+M_PI;
    TopoDS_Edge innerLowerEdge = BRepBuilderAPI_MakeEdge(circle1, start, mid);
    TopoDS_Edge innerUpperEdge = BRepBuilderAPI_MakeEdge(circle1,   mid, end);

    // concatenate wires for guide curve algo
    TopTools_SequenceOfShape innerWireContainer;
    innerWireContainer.Append(innerLowerEdge);
    innerWireContainer.Append(innerUpperEdge);

    // instantiate getPointAlgo
    tigl::CCPACSWingProfileGetPointAlgo getPointAlgo(innerWireContainer);
    gp_Pnt point;
    gp_Vec tangent;

    // plot points and tangents
    int N = 20;
    int M = 2;
    for (int i=0; i<=N+2*M; i++) {
        double da = 2.0/double(N);
        double alpha = -1.0 -M*da + da*i;
        getPointAlgo.GetPointTangent(alpha, point, tangent);
        outputXY(i, point.X(), point.Z(), "./TestData/analysis/tiglWingGuideCurve_circleSamplePoints_points.dat");
        outputXYVector(i, point.X(), point.Z(), tangent.X(), tangent.Z(), "./TestData/analysis/tiglWingGuideCurve_circleSamplePoints_tangents.dat");
        // plot points and tangents with gnuplot by:
        // echo "plot 'TestData/analysis/tiglWingGuideCurve_circleSamplePoints_tangents.dat' u 1:2:3:4 with vectors filled head lw 2, 'TestData/analysis/tiglWingGuideCurve_circleSamplePoints_points.dat' w linespoints lw 2" | gnuplot -persist
    }

    // leading edge: point must be zero and tangent must be in z-direction and has to be of length pi
    getPointAlgo.GetPointTangent(0.0, point, tangent);
    ASSERT_NEAR(point.X(), 0.0, 1E-10);
    ASSERT_NEAR(point.Y(), 0.0, 1E-10);
    ASSERT_NEAR(point.Z(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.X(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.Y(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.Z(), M_PI, 1E-10);

    // check lower trailing edge point. Tangent must be in negative z-direction has to be of length pi
    getPointAlgo.GetPointTangent(-1.0, point, tangent);
    ASSERT_NEAR(point.X(), 2.0, 1E-10);
    ASSERT_NEAR(point.Y(), 0.0, 1E-10);
    ASSERT_NEAR(point.Z(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.X(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.Y(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.Z(), -M_PI, 1E-10);

    // check upper trailing edge point. Tangent must be in negative z-direction has to be of length pi
    getPointAlgo.GetPointTangent(1.0, point, tangent);
    ASSERT_NEAR(point.X(), 2.0, 1E-10);
    ASSERT_NEAR(point.Y(), 0.0, 1E-10);
    ASSERT_NEAR(point.Z(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.X(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.Y(), 0.0, 1E-10);
    ASSERT_NEAR(tangent.Z(), -M_PI, 1E-10);

    // check points and tangents for alpha > 1
    gp_Pnt point2;
    gp_Vec tangent2;
    getPointAlgo.GetPointTangent(1.0, point, tangent);
    getPointAlgo.GetPointTangent(2.0, point2, tangent2);
    ASSERT_NEAR(point2.X(), 2.0, 1E-10);
    ASSERT_NEAR(point2.Y(), 0.0, 1E-10);
    ASSERT_NEAR(point2.Z(), -M_PI, 1E-10);
    ASSERT_EQ(tangent.X(), tangent2.X());
    ASSERT_EQ(tangent.Y(), tangent2.Y());
    ASSERT_EQ(tangent.Z(), tangent2.Z());
    ASSERT_NEAR(point.Distance(point2), M_PI, 1E-10);

    // check if tangent is constant for alpha < 1
    getPointAlgo.GetPointTangent(-1.0, point, tangent);
    getPointAlgo.GetPointTangent(-2.0, point2, tangent2);
    ASSERT_NEAR(point2.X(), 2.0, 1E-10);
    ASSERT_NEAR(point2.Y(), 0.0, 1E-10);
    ASSERT_NEAR(point2.Z(), M_PI, 1E-10);
    ASSERT_EQ(tangent.X(), tangent2.X());
    ASSERT_EQ(tangent.Y(), tangent2.Y());
    ASSERT_EQ(tangent.Z(), tangent2.Z());
    ASSERT_NEAR(point.Distance(point2), M_PI, 1E-10);
}

/**
* Tests CCPACSGuideCurveAlgo class
*/
TEST_F(WingGuideCurve, tiglWingGuideCurve_CCPACSGuideCurveAlgo)
{

    // create two circles parallel to the x-z plane going through the y-axis at alpha=0 
    // the sense of rotation is such that the negative z-values come first
    double radius1=1.0;
    double radius2=1.0;
    double distance=1.0;
    gp_Pnt location1(radius1, 0.0,  0.0);
    gp_Ax2 circlePosition1(location1, gp::DY(), gp::DX());
    Handle(Geom_Circle) circle1 = new Geom_Circle(circlePosition1, radius1);
    gp_Pnt location2(radius2, distance, 0.0);
    gp_Ax2 circlePosition2(location2, gp::DY(), gp::DX());
    Handle(Geom_Circle) circle2 = new Geom_Circle(circlePosition2, radius2);

    // cut into lower and upper half circle
    double start=0.0;
    double mid=start+M_PI;
    double end=mid+M_PI;
    TopoDS_Edge innerLowerEdge = BRepBuilderAPI_MakeEdge(circle1, start, mid);
    TopoDS_Edge innerUpperEdge = BRepBuilderAPI_MakeEdge(circle1,   mid, end);
    TopoDS_Edge outerLowerEdge = BRepBuilderAPI_MakeEdge(circle2, start, mid);
    TopoDS_Edge outerUpperEdge = BRepBuilderAPI_MakeEdge(circle2,   mid, end);

    // concatenate wires for guide curve algo
    TopTools_SequenceOfShape innerWireContainer;
    innerWireContainer.Append(innerLowerEdge);
    innerWireContainer.Append(innerUpperEdge);
    TopTools_SequenceOfShape outerWireContainer;
    outerWireContainer.Append(outerLowerEdge);
    outerWireContainer.Append(outerUpperEdge);

    // get guide curve profile
    tigl::CCPACSGuideCurveProfile guideCurveProfile(NULL, NULL);
    guideCurveProfile.ReadCPACS(tixiHandle, "/cpacs/vehicles/profiles/guideCurves/guideCurveProfile[5]");


    std::vector<gp_Pnt> guideCurvePnts;
    // instantiate guideCurveAlgo
     guideCurvePnts = tigl::CCPACSGuideCurveAlgo<tigl::CCPACSWingProfileGetPointAlgo> (innerWireContainer, outerWireContainer, 0.0, 0.0, 2*radius1, 2*radius2, gp_Dir(1., 0., 0.), guideCurveProfile);
    TopoDS_Edge guideCurveEdge = EdgeSplineFromPoints(guideCurvePnts);;

    // check if guide curve runs through sample points
    // get curve
    Standard_Real u1, u2;
    Handle(Geom_Curve) curve =  BRep_Tool::Curve(guideCurveEdge, u1, u2);
    // set predicted sample points from cpacs file
    const double temp[] = {0.0, 0.0, -0.01, -0.03, -0.09, -0.08, -0.07, -0.06, -0.02, 0.0, 0.0};
    std::vector<double> predictedSamplePointsX (temp, temp + sizeof(temp) / sizeof(temp[0]) );
    for (unsigned int i = 0; i <= 10; ++i) {
        // get intersection point of the guide curve with planes parallel to the x-z plane located at b
        double b = i/double(10);
        Handle(Geom_Plane) plane = new Geom_Plane(gp_Pnt(0.0, b*distance, 0.0), gp_Dir(0.0, 1.0, 0.0));
        GeomAPI_IntCS intersection (curve, plane);
        ASSERT_EQ(Standard_True, intersection.IsDone());
        ASSERT_EQ(intersection.NbPoints(), 1);
        gp_Pnt point = intersection.Point(1);

        // scale sample points since 2nd profile is scaled by a factor 2
        predictedSamplePointsX[i]*=(2*radius1+(2*radius2-2*radius1)*b);
        // check is guide curve runs through the predicted sample points
        ASSERT_NEAR(predictedSamplePointsX[i], point.X(), 1E-14);
        ASSERT_NEAR(b*distance, point.Y(), 1E-14);
        ASSERT_NEAR(0.0, point.Z(), 1E-14);
    }
}

/**
* Tests wing segment guide curve routines
*/
TEST_F(WingGuideCurve, tiglWingGuideCurve_CCPACSWingSegment)
{
    tigl::CCPACSConfigurationManager& manager = tigl::CCPACSConfigurationManager::GetInstance();
    tigl::CCPACSConfiguration& config = manager.GetConfiguration(tiglHandle);
    tigl::CCPACSWing& wing = config.GetWing(1);

    ASSERT_EQ(wing.GetSegmentCount(),3);

    tigl::CCPACSWingSegment& segment3 = wing.GetSegment(3);

    ASSERT_TRUE(segment3.GetGuideCurves().get_ptr() != NULL);
    tigl::CCPACSGuideCurves& guides = *segment3.GetGuideCurves();
    ASSERT_EQ(guides.GetGuideCurveCount(), 3);

    // obtain leading edge guide curve 
    TopoDS_Edge guideCurveEdge = guides.GetGuideCurve(1).GetCurve();

    // check if guide curve runs through sample points
    // get curve
    Standard_Real u1, u2;
    Handle(Geom_Curve) curve =  BRep_Tool::Curve(guideCurveEdge, u1, u2);
    // gamma values of cpacs data points
    const double temp[] = {0.0, 0.0, -0.01, -0.03, -0.09, -0.08, -0.07, -0.06, -0.02, 0.0, 0.0};
    std::vector<double> gammaDeviation (temp, temp + sizeof(temp) / sizeof(temp[0]) );
    // number of sample points
    unsigned int N=10;
    // segment width
    double width=2.0;
    // segment position
    double position=12.0;
    // inner profile scale factor
    double innerScale=1.0;
    // outer profile scale factor
    double outerScale=0.5;
    // outer profile has a sweep angle of -30 degrees)
    double angle=-M_PI/6.0;
    for (unsigned int i = 0; i <= N; ++i) {
        // get intersection point of the guide curve with planes in direction n located at b
        // n is the y direction rotated pi/6 (30 degrees) inside the x-y plane
        double b = width*i/double(N);
        gp_Pnt planeLocation = gp_Pnt(b*sin(angle), b*cos(angle)+position, 0.0);
        Handle(Geom_Plane) plane = new Geom_Plane(planeLocation, gp_Dir(0.0, 1.0, 0.0));
        GeomAPI_IntCS intersection (curve, plane);
        ASSERT_EQ(intersection.NbPoints(), 1);
        gp_Pnt point = intersection.Point(1);

        // start at segment leading edge
        gp_Vec predictedPoint(0.0, position, 0.0);
        // go along the leading edge
        predictedPoint += gp_Vec(b*sin(angle), b*cos(angle), 0.0);
        // scale sample points since outer profile's chordline smaller by a factor of 0.5
        double s=(innerScale+(outerScale-innerScale)*i/double(N));
        // go along direction perpendicular to the leading edge in the x-y plane
        predictedPoint += gp_Vec(gammaDeviation[i]*s, 0.0, 0.0);

        // check is guide curve runs through the predicted sample points
        ASSERT_NEAR(predictedPoint.X(), point.X(), 1E-5);
        ASSERT_NEAR(predictedPoint.Y(), point.Y(), 1E-5);
        ASSERT_NEAR(predictedPoint.Z(), point.Z(), 1E-14);
    }
}

TEST_F(WingGuideCurve, bug975)
{
    //https://github.com/DLR-SC/tigl/issues/975

    tigl::CCPACSConfigurationManager& manager = tigl::CCPACSConfigurationManager::GetInstance();
    tigl::CCPACSConfiguration& config = manager.GetConfiguration(tiglHandle);
    tigl::CCPACSWing& wing = config.GetWing(1);


    tigl::CCPACSWingSegment& segment1 = wing.GetSegment(1);
    tigl::CTiglWingSegmentGuidecurveBuilder builder(segment1);

    auto const& guideCurves = segment1.GetGuideCurves();
    if(guideCurves) {
        tigl::CCPACSGuideCurve const& guidecurve = guideCurves->GetGuideCurve(1);
        auto points_before = builder.BuildGuideCurvePnts(&guidecurve);

        tigl::CCPACSTransformation& trafo = wing.GetTransformation();
        trafo.setRotation(tigl::CTiglPoint(0, 90, 0));
        wing.SetTransformation(trafo);
        tigl::CTiglTransformation const& wingTrafo = wing.GetTransformationMatrix();

        auto points_after = builder.BuildGuideCurvePnts(&guidecurve);
        int idx = 0;
        for (auto const& p : points_after) {

            // per design, the guide curve should have a zero x-component
            EXPECT_NEAR(p.X(), 0.0, 1e-12);

            // transforming the guide curve points of the untransformed wing should
            // yield the same points as building the points after transforming the wing
            gp_Pnt pt = wingTrafo.Transform(points_before[idx++]);
            EXPECT_NEAR(p.X(), pt.X(), 1e-12);
            EXPECT_NEAR(p.Y(), pt.Y(), 1e-12);
            EXPECT_NEAR(p.Z(), pt.Z(), 1e-12);

        }
    }

}


TEST_F(WingGuideCurve, bug962)
{
    //https://github.com/DLR-SC/tigl/issues/962

    TixiDocumentHandle           tixi_h;
    TiglCPACSConfigurationHandle tigl_h;

    // open simpletest with tixi and add empty guidecurves node
    const char* filename = "TestData/simpletest.cpacs.xml";
    auto tixiRet = tixiOpenDocument(filename, &tixi_h);
    ASSERT_EQ (tixiRet, SUCCESS);
    tixiRet = tixiCreateElement(tixi_h, "/cpacs/vehicles/aircraft/model/wings/wing[1]/segments/segment[1]", "guideCurves");
    ASSERT_EQ (tixiRet, SUCCESS);

    // open with tigl and try to build segment loft
    auto tiglRet = tiglOpenCPACSConfiguration(tixi_h, "Cpacs2Test", &tigl_h);
    ASSERT_EQ(tiglRet, TIGL_SUCCESS);


    tigl::CCPACSConfigurationManager& manager = tigl::CCPACSConfigurationManager::GetInstance();
    tigl::CCPACSConfiguration& config = manager.GetConfiguration(tigl_h);
    tigl::CCPACSWing& wing = config.GetWing(1);
    tigl::CCPACSWingSegment& segment1 = wing.GetSegment(1);
    segment1.GetLoft();
}

TEST_F(WingGuideCurve, BuildGuideCurvePnts_checkArgs)
{
    const char* filename = "TestData/simple_test_guide_curves_wrong_gc_Def.xml";

    TiglCPACSConfigurationHandle tiglHandle = -1;
    TixiDocumentHandle tixiHandle = -1;
    ASSERT_EQ(SUCCESS, tixiOpenDocument(filename, &tixiHandle));
    ASSERT_EQ(TIGL_SUCCESS, tiglOpenCPACSConfiguration(tixiHandle, "", &tiglHandle));

    auto& uid_mgr = tigl::CCPACSConfigurationManager::GetInstance().GetConfiguration(tiglHandle).GetUIDManager();
    auto& segment = uid_mgr.ResolveObject<tigl::CCPACSWingSegment>("GuideCurveModel_Wing_Seg_1_2");
    auto& guideCurves = *segment.GetGuideCurves();
    const tigl::CCPACSGuideCurve& guideCurve = guideCurves.GetGuideCurve(2);

    tigl::CTiglWingSegmentGuidecurveBuilder builder(segment);
    EXPECT_THROW(builder.BuildGuideCurvePnts(&guideCurve), tigl::CTiglError);
}
