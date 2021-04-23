// Copyright (c) 2020 RISC Software GmbH
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
#include "CCPACSWingRibsDefinition.h"
#include "CPACSWingRibsPositioning.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingRibsPositioning::CPACSWingRibsPositioning(CCPACSWingRibsDefinition* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_ribRotation(reinterpret_cast<CCPACSWingRibsPositioning*>(this))
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSWingRibsPositioning::~CPACSWingRibsPositioning()
    {
        if (m_uidMgr) {
            if (m_startSparPositionUID_choice3 && !m_startSparPositionUID_choice3->empty()) m_uidMgr->TryUnregisterReference(*m_startSparPositionUID_choice3, *this);
            if (m_endSparPositionUID_choice3 && !m_endSparPositionUID_choice3->empty()) m_uidMgr->TryUnregisterReference(*m_endSparPositionUID_choice3, *this);
        }
    }

    const CCPACSWingRibsDefinition* CPACSWingRibsPositioning::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingRibsDefinition* CPACSWingRibsPositioning::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSWingRibsPositioning::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSWingRibsPositioning::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSWingRibsPositioning::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWingRibsPositioning::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSWingRibsPositioning::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element startEtaXsiPoint
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/startEtaXsiPoint")) {
            m_startEtaXsiPoint_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibsPositioning*>(this), m_uidMgr);
            try {
                m_startEtaXsiPoint_choice1->ReadCPACS(tixiHandle, xpath + "/startEtaXsiPoint");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read startEtaXsiPoint at xpath " << xpath << ": " << e.what();
                m_startEtaXsiPoint_choice1 = boost::none;
            }
        }

        // read element startCurvePoint
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/startCurvePoint")) {
            m_startCurvePoint_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibsPositioning*>(this));
            try {
                m_startCurvePoint_choice2->ReadCPACS(tixiHandle, xpath + "/startCurvePoint");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read startCurvePoint at xpath " << xpath << ": " << e.what();
                m_startCurvePoint_choice2 = boost::none;
            }
        }

        // read element startSparPositionUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/startSparPositionUID")) {
            m_startSparPositionUID_choice3 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/startSparPositionUID");
            if (m_startSparPositionUID_choice3->empty()) {
                LOG(WARNING) << "Optional element startSparPositionUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_startSparPositionUID_choice3->empty()) m_uidMgr->RegisterReference(*m_startSparPositionUID_choice3, *this);
        }

        // read element endEtaXsiPoint
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/endEtaXsiPoint")) {
            m_endEtaXsiPoint_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibsPositioning*>(this), m_uidMgr);
            try {
                m_endEtaXsiPoint_choice1->ReadCPACS(tixiHandle, xpath + "/endEtaXsiPoint");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read endEtaXsiPoint at xpath " << xpath << ": " << e.what();
                m_endEtaXsiPoint_choice1 = boost::none;
            }
        }

        // read element endCurvePoint
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/endCurvePoint")) {
            m_endCurvePoint_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibsPositioning*>(this));
            try {
                m_endCurvePoint_choice2->ReadCPACS(tixiHandle, xpath + "/endCurvePoint");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read endCurvePoint at xpath " << xpath << ": " << e.what();
                m_endCurvePoint_choice2 = boost::none;
            }
        }

        // read element endSparPositionUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/endSparPositionUID")) {
            m_endSparPositionUID_choice3 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/endSparPositionUID");
            if (m_endSparPositionUID_choice3->empty()) {
                LOG(WARNING) << "Optional element endSparPositionUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_endSparPositionUID_choice3->empty()) m_uidMgr->RegisterReference(*m_endSparPositionUID_choice3, *this);
        }

        // read element ribStart
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribStart")) {
            m_ribStart = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribStart");
            if (m_ribStart.empty()) {
                LOG(WARNING) << "Required element ribStart is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element ribStart is missing at xpath " << xpath;
        }

        // read element ribEnd
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribEnd")) {
            m_ribEnd = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribEnd");
            if (m_ribEnd.empty()) {
                LOG(WARNING) << "Required element ribEnd is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element ribEnd is missing at xpath " << xpath;
        }

        // read element spacing
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/spacing")) {
            m_spacing_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/spacing");
        }

        // read element numberOfRibs
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/numberOfRibs")) {
            m_numberOfRibs_choice2 = tixi::TixiGetElement<int>(tixiHandle, xpath + "/numberOfRibs");
        }

        // read element ribReference
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribReference")) {
            m_ribReference = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribReference");
            if (m_ribReference.empty()) {
                LOG(WARNING) << "Required element ribReference is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element ribReference is missing at xpath " << xpath;
        }

        // read element ribCrossingBehaviour
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribCrossingBehaviour")) {
            m_ribCrossingBehaviour = stringToCPACSRibCrossingBehaviour(tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribCrossingBehaviour"));
        }
        else {
            LOG(ERROR) << "Required element ribCrossingBehaviour is missing at xpath " << xpath;
        }

        // read element ribRotation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribRotation")) {
            m_ribRotation.ReadCPACS(tixiHandle, xpath + "/ribRotation");
        }
        else {
            LOG(ERROR) << "Required element ribRotation is missing at xpath " << xpath;
        }

        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSWingRibsPositioning::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "startEtaXsiPoint", "startCurvePoint", "startSparPositionUID", "endEtaXsiPoint", "endCurvePoint", "endSparPositionUID", "ribStart", "ribEnd", "spacing", "numberOfRibs", "ribReference", "ribCrossingBehaviour", "ribRotation" };

        // write element startEtaXsiPoint
        if (m_startEtaXsiPoint_choice1) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/startEtaXsiPoint", childElemOrder);
            m_startEtaXsiPoint_choice1->WriteCPACS(tixiHandle, xpath + "/startEtaXsiPoint");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/startEtaXsiPoint")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/startEtaXsiPoint");
            }
        }

        // write element startCurvePoint
        if (m_startCurvePoint_choice2) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/startCurvePoint", childElemOrder);
            m_startCurvePoint_choice2->WriteCPACS(tixiHandle, xpath + "/startCurvePoint");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/startCurvePoint")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/startCurvePoint");
            }
        }

        // write element startSparPositionUID
        if (m_startSparPositionUID_choice3) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/startSparPositionUID", childElemOrder);
            tixi::TixiSaveElement(tixiHandle, xpath + "/startSparPositionUID", *m_startSparPositionUID_choice3);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/startSparPositionUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/startSparPositionUID");
            }
        }

        // write element endEtaXsiPoint
        if (m_endEtaXsiPoint_choice1) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/endEtaXsiPoint", childElemOrder);
            m_endEtaXsiPoint_choice1->WriteCPACS(tixiHandle, xpath + "/endEtaXsiPoint");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/endEtaXsiPoint")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/endEtaXsiPoint");
            }
        }

        // write element endCurvePoint
        if (m_endCurvePoint_choice2) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/endCurvePoint", childElemOrder);
            m_endCurvePoint_choice2->WriteCPACS(tixiHandle, xpath + "/endCurvePoint");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/endCurvePoint")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/endCurvePoint");
            }
        }

        // write element endSparPositionUID
        if (m_endSparPositionUID_choice3) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/endSparPositionUID", childElemOrder);
            tixi::TixiSaveElement(tixiHandle, xpath + "/endSparPositionUID", *m_endSparPositionUID_choice3);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/endSparPositionUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/endSparPositionUID");
            }
        }

        // write element ribStart
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/ribStart", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribStart", m_ribStart);

        // write element ribEnd
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/ribEnd", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribEnd", m_ribEnd);

        // write element spacing
        if (m_spacing_choice1) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/spacing", childElemOrder);
            tixi::TixiSaveElement(tixiHandle, xpath + "/spacing", *m_spacing_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/spacing")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/spacing");
            }
        }

        // write element numberOfRibs
        if (m_numberOfRibs_choice2) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/numberOfRibs", childElemOrder);
            tixi::TixiSaveElement(tixiHandle, xpath + "/numberOfRibs", *m_numberOfRibs_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/numberOfRibs")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/numberOfRibs");
            }
        }

        // write element ribReference
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/ribReference", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribReference", m_ribReference);

        // write element ribCrossingBehaviour
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/ribCrossingBehaviour", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribCrossingBehaviour", CPACSRibCrossingBehaviourToString(m_ribCrossingBehaviour));

        // write element ribRotation
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/ribRotation", childElemOrder);
        m_ribRotation.WriteCPACS(tixiHandle, xpath + "/ribRotation");

    }

    bool CPACSWingRibsPositioning::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_startEtaXsiPoint_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_startCurvePoint_choice2.is_initialized()
                        ||
                        m_startSparPositionUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_startCurvePoint_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_startEtaXsiPoint_choice1.is_initialized()
                        ||
                        m_startSparPositionUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_startSparPositionUID_choice3.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_startEtaXsiPoint_choice1.is_initialized()
                        ||
                        m_startCurvePoint_choice2.is_initialized()
                    )
                )
                == 1
            )
            &&
            (
                (
                    // mandatory elements of this choice must be there
                    m_endEtaXsiPoint_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_endCurvePoint_choice2.is_initialized()
                        ||
                        m_endSparPositionUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_endCurvePoint_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_endEtaXsiPoint_choice1.is_initialized()
                        ||
                        m_endSparPositionUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_endSparPositionUID_choice3.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_endEtaXsiPoint_choice1.is_initialized()
                        ||
                        m_endCurvePoint_choice2.is_initialized()
                    )
                )
                == 1
            )
            &&
            (
                (
                    // mandatory elements of this choice must be there
                    m_spacing_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_numberOfRibs_choice2.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_numberOfRibs_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_spacing_choice1.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const boost::optional<CCPACSEtaXsiPoint>& CPACSWingRibsPositioning::GetStartEtaXsiPoint_choice1() const
    {
        return m_startEtaXsiPoint_choice1;
    }

    boost::optional<CCPACSEtaXsiPoint>& CPACSWingRibsPositioning::GetStartEtaXsiPoint_choice1()
    {
        return m_startEtaXsiPoint_choice1;
    }

    const boost::optional<CCPACSCurvePoint>& CPACSWingRibsPositioning::GetStartCurvePoint_choice2() const
    {
        return m_startCurvePoint_choice2;
    }

    boost::optional<CCPACSCurvePoint>& CPACSWingRibsPositioning::GetStartCurvePoint_choice2()
    {
        return m_startCurvePoint_choice2;
    }

    const boost::optional<std::string>& CPACSWingRibsPositioning::GetStartSparPositionUID_choice3() const
    {
        return m_startSparPositionUID_choice3;
    }

    void CPACSWingRibsPositioning::SetStartSparPositionUID_choice3(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_startSparPositionUID_choice3 && !m_startSparPositionUID_choice3->empty()) m_uidMgr->TryUnregisterReference(*m_startSparPositionUID_choice3, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_startSparPositionUID_choice3 = value;
    }

    const boost::optional<CCPACSEtaXsiPoint>& CPACSWingRibsPositioning::GetEndEtaXsiPoint_choice1() const
    {
        return m_endEtaXsiPoint_choice1;
    }

    boost::optional<CCPACSEtaXsiPoint>& CPACSWingRibsPositioning::GetEndEtaXsiPoint_choice1()
    {
        return m_endEtaXsiPoint_choice1;
    }

    const boost::optional<CCPACSCurvePoint>& CPACSWingRibsPositioning::GetEndCurvePoint_choice2() const
    {
        return m_endCurvePoint_choice2;
    }

    boost::optional<CCPACSCurvePoint>& CPACSWingRibsPositioning::GetEndCurvePoint_choice2()
    {
        return m_endCurvePoint_choice2;
    }

    const boost::optional<std::string>& CPACSWingRibsPositioning::GetEndSparPositionUID_choice3() const
    {
        return m_endSparPositionUID_choice3;
    }

    void CPACSWingRibsPositioning::SetEndSparPositionUID_choice3(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_endSparPositionUID_choice3 && !m_endSparPositionUID_choice3->empty()) m_uidMgr->TryUnregisterReference(*m_endSparPositionUID_choice3, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_endSparPositionUID_choice3 = value;
    }

    const std::string& CPACSWingRibsPositioning::GetRibStart() const
    {
        return m_ribStart;
    }

    void CPACSWingRibsPositioning::SetRibStart(const std::string& value)
    {
        m_ribStart = value;
    }

    const std::string& CPACSWingRibsPositioning::GetRibEnd() const
    {
        return m_ribEnd;
    }

    void CPACSWingRibsPositioning::SetRibEnd(const std::string& value)
    {
        m_ribEnd = value;
    }

    const boost::optional<double>& CPACSWingRibsPositioning::GetSpacing_choice1() const
    {
        return m_spacing_choice1;
    }

    void CPACSWingRibsPositioning::SetSpacing_choice1(const boost::optional<double>& value)
    {
        m_spacing_choice1 = value;
    }

    const boost::optional<int>& CPACSWingRibsPositioning::GetNumberOfRibs_choice2() const
    {
        return m_numberOfRibs_choice2;
    }

    void CPACSWingRibsPositioning::SetNumberOfRibs_choice2(const boost::optional<int>& value)
    {
        m_numberOfRibs_choice2 = value;
    }

    const std::string& CPACSWingRibsPositioning::GetRibReference() const
    {
        return m_ribReference;
    }

    void CPACSWingRibsPositioning::SetRibReference(const std::string& value)
    {
        m_ribReference = value;
    }

    const CPACSRibCrossingBehaviour& CPACSWingRibsPositioning::GetRibCrossingBehaviour() const
    {
        return m_ribCrossingBehaviour;
    }

    void CPACSWingRibsPositioning::SetRibCrossingBehaviour(const CPACSRibCrossingBehaviour& value)
    {
        m_ribCrossingBehaviour = value;
    }

    const CCPACSWingRibRotation& CPACSWingRibsPositioning::GetRibRotation() const
    {
        return m_ribRotation;
    }

    CCPACSWingRibRotation& CPACSWingRibsPositioning::GetRibRotation()
    {
        return m_ribRotation;
    }

    CCPACSEtaXsiPoint& CPACSWingRibsPositioning::GetStartEtaXsiPoint_choice1(CreateIfNotExistsTag)
    {
        if (!m_startEtaXsiPoint_choice1)
            m_startEtaXsiPoint_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibsPositioning*>(this), m_uidMgr);
        return *m_startEtaXsiPoint_choice1;
    }

    void CPACSWingRibsPositioning::RemoveStartEtaXsiPoint_choice1()
    {
        m_startEtaXsiPoint_choice1 = boost::none;
    }

    CCPACSCurvePoint& CPACSWingRibsPositioning::GetStartCurvePoint_choice2(CreateIfNotExistsTag)
    {
        if (!m_startCurvePoint_choice2)
            m_startCurvePoint_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibsPositioning*>(this));
        return *m_startCurvePoint_choice2;
    }

    void CPACSWingRibsPositioning::RemoveStartCurvePoint_choice2()
    {
        m_startCurvePoint_choice2 = boost::none;
    }

    CCPACSEtaXsiPoint& CPACSWingRibsPositioning::GetEndEtaXsiPoint_choice1(CreateIfNotExistsTag)
    {
        if (!m_endEtaXsiPoint_choice1)
            m_endEtaXsiPoint_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibsPositioning*>(this), m_uidMgr);
        return *m_endEtaXsiPoint_choice1;
    }

    void CPACSWingRibsPositioning::RemoveEndEtaXsiPoint_choice1()
    {
        m_endEtaXsiPoint_choice1 = boost::none;
    }

    CCPACSCurvePoint& CPACSWingRibsPositioning::GetEndCurvePoint_choice2(CreateIfNotExistsTag)
    {
        if (!m_endCurvePoint_choice2)
            m_endCurvePoint_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibsPositioning*>(this));
        return *m_endCurvePoint_choice2;
    }

    void CPACSWingRibsPositioning::RemoveEndCurvePoint_choice2()
    {
        m_endCurvePoint_choice2 = boost::none;
    }

    const CTiglUIDObject* CPACSWingRibsPositioning::GetNextUIDObject() const
    {
        return GetNextUIDParent();
    }

    void CPACSWingRibsPositioning::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_startSparPositionUID_choice3 && *m_startSparPositionUID_choice3 == oldUid) {
            m_startSparPositionUID_choice3 = newUid;
        }
        if (m_endSparPositionUID_choice3 && *m_endSparPositionUID_choice3 == oldUid) {
            m_endSparPositionUID_choice3 = newUid;
        }
    }

} // namespace generated
} // namespace tigl
