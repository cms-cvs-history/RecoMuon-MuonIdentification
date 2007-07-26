#ifndef MuonIdentification_IdGlobalFunctions_h
#define MuonIdentification_IdGlobalFunctions_h
//
// Package:    MuonIdentification
// 
//
// Original Author:  Jake Ribnik, Dmytro Kovalskyi
// $Id: IdGlobalFunctions.h,v 1.1 2007/07/25 23:38:14 dmytro Exp $

#include "DataFormats/MuonReco/interface/Muon.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

namespace muonid {
   enum AlgorithmType { TMLastStation };
   enum SelectionType { TMLastStationLoose, TMLastStationTight };
   
   bool isGoodMuon( const reco::Muon& muon, SelectionType type = TMLastStationLoose );
   
   bool isGoodMuon( const reco::Muon& muon, 
		    AlgorithmType type,
		    int minNumberOfMatches,
		    double maxAbsDx,
		    double maxAbsPullX,
		    double maxAbsDy,
		    double maxAbsPullY,
		    double maxChamberDist,
		    double maxChamberDistPull,
		    reco::Muon::ArbitrationType arbitrationType );
   
   // determine if station was crossed well withing active volume
   unsigned int RequiredStationMask( const reco::Muon& muon,
				     double maxChamberDist,
				     double maxChamberDistPull,
				     reco::Muon::ArbitrationType arbitrationType );

}
#endif
