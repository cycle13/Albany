//*****************************************************************//
//    Albany 2.0:  Copyright 2012 Sandia Corporation               //
//    This Software is released under the BSD license detailed     //
//    in the file "license.txt" in the top-level Albany directory  //
//*****************************************************************//
#ifndef ALBANY_RYTHMOSSNAPSHOTCOLLECTIONOBSERVER_HPP
#define ALBANY_RYTHMOSSNAPSHOTCOLLECTIONOBSERVER_HPP

#include "Rythmos_IntegrationObserverBase.hpp"

#include "Albany_SnapshotCollection.hpp"

class Epetra_Map;

#include "Teuchos_ParameterList.hpp"

namespace Albany {

class RythmosSnapshotCollectionObserver : public Rythmos::IntegrationObserverBase<double> {
public:
  explicit RythmosSnapshotCollectionObserver(const Teuchos::RCP<Teuchos::ParameterList> &params,
                                             const Teuchos::RCP<const Epetra_Map> &stateMap);

  // Overridden
  virtual Teuchos::RCP<Rythmos::IntegrationObserverBase<double> > cloneIntegrationObserver() const;

  virtual void resetIntegrationObserver(const Rythmos::TimeRange<double> &integrationTimeDomain);

  virtual void observeStartTimeStep(
    const Rythmos::StepperBase<double> &stepper,
    const Rythmos::StepControlInfo<double> &stepCtrlInfo,
    const int timeStepIter);

  virtual void observeCompletedTimeStep(
    const Rythmos::StepperBase<double> &stepper,
    const Rythmos::StepControlInfo<double> &stepCtrlInfo,
    const int timeStepIter);

private:
  SnapshotCollection snapshotCollector_;
  Teuchos::RCP<const Epetra_Map> stateMap_;

  virtual void observeTimeStep(
    const Rythmos::StepperBase<double> &stepper,
    const Rythmos::StepControlInfo<double> &stepCtrlInfo,
    const int timeStepIter);

};

} // namespace Albany

#endif /*ALBANY_RYTHMOSSNAPSHOTCOLLECTIONOBSERVER_HPP*/