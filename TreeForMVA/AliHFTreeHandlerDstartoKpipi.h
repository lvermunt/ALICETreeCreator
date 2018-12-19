#ifndef ALIHFTREEHANDLERDSTARTOKPIPI_H
#define ALIHFTREEHANDLERDSTARTOKPIPI_H

/* Copyright(c) 1998-2008, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/* $Id$ */

//*************************************************************************
// \class AliHFTreeHandlerDstartoKpipi
// \brief helper class to handle a tree for D+ cut optimisation and MVA analyses
// \authors:
// F. Catalano, fabio.catalano@cern.ch
// A. Festanti, andrea.festanti@cern.ch
// F. Grosa, fabrizio.grosa@cern.ch
// G. Innocenti, gian.michele.innocenti@cern.ch
// F. Prino, prino@to.infn.it
// L. Vermunt, luuk.vermunt@cern.ch
/////////////////////////////////////////////////////////////

#include "AliHFTreeHandler.h"

using std::vector;

class AliHFTreeHandlerDstartoKpipi : public AliHFTreeHandler
{
  public:
    AliHFTreeHandlerDstartoKpipi();
    AliHFTreeHandlerDstartoKpipi(int PIDopt);

    virtual ~AliHFTreeHandlerDstartoKpipi();

    virtual TTree* BuildTree(TString name="tree", TString title="tree");
    virtual bool SetVariables(AliAODRecoDecayHF* cand, float bfield, int masshypo=0, AliAODPidHF* pidHF=0x0);
    virtual void FillTree(); //to be called for each event, not each candidate!

  private:

    vector<float> fImpParProng[knMaxProngs]; ///vectors of prong impact parameter
    vector<float> fCosThetaStar; ///vector of candidate cos theta star
    vector<float> fImpParProd; ///vector of D0 product of impact parameter
    vector<float> fSoftPiPt; ///vector of pT soft pion
    vector<float> fNormd0MeasMinusExp; ///vector of candidate topomatic variable

    vector<float> fInvMass_D0; ///vector of candidate invariant mass D0
    vector<float> fPt_D0; ///vector of D0 pt
    vector<float> fY_D0; ///vector of D0 rapidity
    vector<float> fEta_D0; ///vector of D0 pseudorapidity
    vector<float> fPhi_D0; ///vector of D0 azimuthal angle

    /// \cond CLASSIMP
    ClassDef(AliHFTreeHandlerDstartoKpipi,2); ///
    /// \endcond
};
#endif