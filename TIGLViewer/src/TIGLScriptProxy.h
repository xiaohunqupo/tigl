/*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef TIGLSCRIPTPOXY_H
#define TIGLSCRIPTPOXY_H

#include "TIGLScriptProxy.h"
#include "tigl.h"

#include <QtCore/QString>
#include <QtCore/QObject>

#include <QtScript>
#include <QString>

namespace tigl
{
class CCPACSConfiguration;
}

class TIGLViewerWindow;

class TIGLScriptProxy :public QObject, public QScriptable
{
    Q_OBJECT
    Q_CLASSINFO("Description", "TiGL Interface")
    
    Q_PROPERTY(QString version READ getVersion() )
    
private:
    // Returns the CPACS configuration
    tigl::CCPACSConfiguration& GetConfiguration();
    TiglCPACSConfigurationHandle getTiglHandle();
    
public:
    TIGLScriptProxy(TIGLViewerWindow* app);
    //~TIGLScriptProxy();
    
public slots:
    // wrapped tigl functions
    QScriptValue getWingCount();
    QString getVersion();
    QScriptValue componentGetHashCode (QString componentUID);

    // exports
    QScriptValue exportComponent (QString uid, QString filename, double deflection);
    QScriptValue exportConfiguration (QString filename, bool fuseAllShapes, double deflection);
    QScriptValue exportFusedWingFuselageIGES (QString filename);
    QScriptValue exportIGES (QString filename);
    QScriptValue exportSTEP (QString filename);
    QScriptValue exportFusedSTEP (QString filename);
    QScriptValue exportMeshedFuselageSTL(int fuselageIndex, QString filename, double deflection);
    QScriptValue exportMeshedFuselageVTKByIndex (int fuselageIndex, QString filename, double deflection);
    QScriptValue exportMeshedFuselageVTKByUID (QString fuselageUID, QString filename, double deflection);
    QScriptValue setExportOptions(QString exporter, QString optionName, QString optionValue);
    
    // fuselage stuff
    QScriptValue fuselageGetUID(int fuselageIndex);
    QScriptValue fuselageGetCircumference (int fuselageIndex, int segmentIndex, double eta);
    QScriptValue fuselageGetPoint (int fuselageIndex, int segmentIndex, double eta, double zeta);
    QScriptValue fuselageGetSegmentUID (int fuselageIndex, int segmentIndex);
    QScriptValue fuselageGetSegmentVolume (int fuselageIndex, int segmentIndex);
    QScriptValue getFuselageCount();
    QScriptValue fuselageGetSegmentCount(int fuselageIndex);
    QScriptValue fuselageGetCenterLineLength(QString fuselageUID);
    QScriptValue wingGetUpperPoint(int wingIndex, int segmentIndex, double eta, double xsi);
    
    // wing stuff
    QScriptValue wingGetUID(int wingIndex);
    QScriptValue wingGetLowerPoint(int wingIndex, int segmentIndex, double eta, double xsi);
    QScriptValue wingGetUpperPointAtDirection(int wingIndex, int segmentIndex, double eta, double xsi, double dirx, double diry, double dirz);
    QScriptValue wingGetLowerPointAtDirection(int wingIndex, int segmentIndex, double eta, double xsi, double dirx, double diry, double dirz);
    QScriptValue wingGetChordPoint(int wingIndex, int segmentIndex, double eta, double xsi);
    QScriptValue wingGetChordNormal(int wingIndex, int segmentIndex, double eta, double xsi);
    QScriptValue wingComponentSegmentGetPoint(QString compSegUID, double eta, double xsi);
    QScriptValue wingGetSegmentCount(int wingIndex);
    QScriptValue wingGetSegmentUID(int wingIndex, int segmentIndex);
    QScriptValue wingGetSpan(QString wingUID);
    QScriptValue wingGetSegmentVolume (int wingIndex, int segmentIndex);
    QScriptValue controlSurfaceSetControlParameter(QString controlSurfaceUID, double controlParameter);
    QScriptValue wingSetGetPointBehaviour (int behaviour);
    QScriptValue wingGetSegmentEtaXsi(int wingIdx, double px, double py, double pz);


    // Component
    QScriptValue componentTransformPointToGlobal(QString componentUID,
                                                 double localX,
                                                 double localY,
                                                 double localZ);

    QString      getErrorString(int errorCode);
    QScriptValue getShape(QString uid);
    
private:
    QString m_fileName;
    QStringList memberFunctions;
    TIGLViewerWindow* _app;

};

QScriptValue TIGLScriptProxyConstructor(QScriptContext *, QScriptEngine *);

#endif // TIGLSCRIPTPOXY_H

