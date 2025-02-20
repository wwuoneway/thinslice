#ifndef HADANA_H
#define HADANA_H

#include "EventType.h"
#include "EventSelection.h"
#include "SliceParams.h"

class anavar;

class HadAna{
 public: 

  HadAna();

  void InitPi();

  void InitP();

  void AddTruePDG(int pdg);

  //Check if the desired particle is selected
  bool isSelectedPart(const anavar& evt) const;

  //Select events with cosmic trigger in data
  bool isCosmics(const anavar& evt) const;

  // Set beam cut values
  void SetBeamQualityCuts(double dx_min = 3, double dx_max = -3,
                          double dy_min = 3, double dy_max = -3,
                          double dz_min = -3, double dz_max = 3,
                          double dxy_min = -1, double dxy_max = 3,
                          double costh_min = 0.95, double costh_max = 2);

  int GetPiParType(const anavar& evt);
  int GetPParType(const anavar& evt);

  // Pandora slice pdg
  int pandora_slice_pdg;
  void SetPandoraSlicePDG(int pdg);

  bool PassPandoraSliceCut(const anavar& evt) const;
  bool PassBeamQualityCut() const;
  bool PassAPA3Cut(const anavar& evt) const;
  bool PassCaloSizeCut(const anavar& evt) const;
  bool PassMichelScoreCut() const;
  bool PassMediandEdxCut() const;

  bool PassPiCuts(const anavar& evt) const;
  bool PassPCuts(const anavar& evt) const;

  // Event information
  void ProcessEvent(const anavar& evt);
  int pitype;
  int ptype;
  double median_dEdx;
  double daughter_michel_score;
  double dEdx_5cm;
  double beam_dx, beam_dy, beam_dz, beam_dxy, beam_costh;
  
  double true_trklen;
  double reco_trklen;
  std::vector<double> true_trklen_accum;
  std::vector<double> reco_trklen_accum;

 private:
  
  //Selected true pdg list
  std::vector<int> truepdglist;

  double beamcut_dx_min, beamcut_dx_max;
  double beamcut_dy_min, beamcut_dy_max;
  double beamcut_dz_min, beamcut_dz_max;
  double beamcut_dxy_min, beamcut_dxy_max;
  double beamcut_costh_min, beamcut_costh_max;

};

#endif
