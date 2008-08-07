import FWCore.ParameterSet.Config as cms

# -*-SH-*-
# include geometry and magnetic field
from Geometry.CaloEventSetup.CaloTopology_cfi import *
from Geometry.CommonDetUnit.bareGlobalTrackingGeometry_cfi import *
# add the SteppingHelixPropagator to the EventSetup
from TrackPropagation.SteppingHelixPropagator.SteppingHelixPropagatorAny_cfi import *
from TrackPropagation.SteppingHelixPropagator.SteppingHelixPropagatorAlong_cfi import *
from TrackPropagation.SteppingHelixPropagator.SteppingHelixPropagatorOpposite_cfi import *
# add TrackDetectorAssociator lookup maps to the EventSetup
from TrackingTools.TrackAssociator.DetIdAssociatorESProducer_cff import *
from RecoMuon.MuonIdentification.isolation_cff import *
from RecoMuon.MuonIdentification.muons_cfi import *
from RecoMuon.MuonIdentification.calomuons_cfi import *
muonIdProducerSequence = cms.Sequence(muons*calomuons)

