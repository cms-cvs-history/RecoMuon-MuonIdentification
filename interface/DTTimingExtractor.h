
#ifndef MuonIdentification_DTTimingExtractor_H
#define MuonIdentification_DTTimingExtractor_H

/**\class DTTimingExtractor
 *
 * Extracts timing information associated to a muon track
 *
*/
//
// Original Author:  Traczyk Piotr
//         Created:  Thu Oct 11 15:01:28 CEST 2007
// $Id: DTTimingExtractor.h,v 1.4 2010/07/01 08:48:11 ptraczyk Exp $
//
//

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "RecoMuon/TrackingTools/interface/MuonServiceProxy.h"

#include "DataFormats/Common/interface/Ref.h"

#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GlobalTrackingGeometry.h"

#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "RecoMuon/TrackingTools/interface/MuonSegmentMatcher.h"
#include "RecoMuon/MuonIdentification/interface/TimeMeasurementSequence.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/TrackExtra.h"
#include "DataFormats/TrackReco/interface/TrackExtraFwd.h"

#include <vector>
#include <TFile.h>
#include <TH1F.h>
namespace edm {
  class ParameterSet;
  class EventSetup;
  class InputTag;
}

class MuonServiceProxy;

class DTTimingExtractor {

public:
  
  /// Constructor
  DTTimingExtractor(const edm::ParameterSet&);
  
  /// Destructor
  ~DTTimingExtractor();

 class TimeMeasurement
  {
   public:
     bool isLeft;
     bool isPhi;
     float posInLayer;
     float distIP;
     float timeCorr;
     int station;
     DetId driftCell;
  };

  void fillTiming(TimeMeasurementSequence &tmSequence, reco::TrackRef muonTrack, const edm::Event& iEvent, const edm::EventSetup& iSetup);

private:
  double fitT0(double &a, double &b, std::vector<double> xl, std::vector<double> yl, std::vector<double> xr, std::vector<double> yr );

  edm::InputTag DTSegmentTags_; 
  unsigned int theHitsMin_;
  double thePruneCut_;
  bool useSegmentT0_;
  bool doWireCorr_;
  bool dropTheta_;
  bool requireBothProjections_;
  double theDTTimeOffset_;
  double theDTError_;
  bool debug;
  //TFile *file;
  //TH1F *segTimes;
  
  MuonServiceProxy* theService;
  
  MuonSegmentMatcher *theMatcher;
};

#endif
