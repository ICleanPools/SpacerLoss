// This Macro Plots Information About Missed LCTs In the Spacer Bar Region.

#include "HistGetter.h"
#include "ChamberSerial.h"
#include "WireGroup.h"
#include <TMath.h>
#include <TTree.h>

int main(){

  // Some Goddamn Black Magic
  HistGetter plotter;
 
  // Open File and Load Tree
  TFile inFile("blocks/cscDigiTree.root");
  TTree* myTree = (TTree*) inFile.Get("CSCDigiTree");
 
  // Declaration Of Variables and Branches
  bool os;
  Double_t Pt;
  Double_t eta;
  Double_t phi;
  Int_t Nseg;
  std::vector<int> *segEc;
  std::vector<int> *segSt;
  std::vector<int> *segRi;
  std::vector<int> *segCh;
  std::vector<int> *segX;
  std::vector<int> *segY;
  std::vector<int> *lctId;
  std::vector<std::vector<int> > *lctKWG;
  std::vector<std::vector<int> > *lctKHS;
  std::vector<int> *csctflctId;
  std::vector<std::vector<int> > *csctflctKWG;
  std::vector<std::vector<int> > *csctflctKHS;
  std::vector<int> *emtflctId;
  std::vector<std::vector<int> > *emtflctKWG;
  std::vector<std::vector<int> > *emtflctKHS;
  std::vector<int> *clctId;
  std::vector<std::vector<int> > *clctKHS;
  std::vector<int> *alctId;
  std::vector<std::vector<int> > *alctKWG;
  std::vector<int> *compId;
  std::vector<int> *compLay;
  std::vector<std::vector<int> > *compStr;
  std::vector<std::vector<int> > *compHS;
  std::vector<std::vector<std::vector<int> > > *compTimeOn;
  std::vector<int> *wireId;
  std::vector<int> *wireLay; 
  std::vector<std::vector<int> > *wireGrp;
  std::vector<std::vector<std::vector<int> > > *wireTimeOn;
 
  long int  nEntries = myTree->TTree::GetEntries(); // Number of Muons Recorded

  segEc = 0;
  segSt = 0;
  segRi = 0;
  segCh = 0;
  segX = 0;
  segY = 0;
  lctId = 0;
  lctKWG = 0;
  lctKHS = 0;
  csctflctId = 0;
  csctflctKWG = 0;
  csctflctKHS = 0;
  emtflctId = 0;
  emtflctKWG = 0;
  emtflctKHS = 0;
  clctId = 0;
  clctKHS = 0;
  alctId = 0;
  alctKWG = 0;
  compId = 0;
  compLay = 0;
  compStr = 0;
  compHS = 0;
  compTimeOn = 0;
  wireId = 0;
  wireLay = 0;
  wireGrp = 0;
  wireTimeOn = 0;

  TBranch *b_os;
  TBranch *b_Pt;
  TBranch *b_eta;
  TBranch *b_phi;
  TBranch *b_Nseg;
  TBranch *b_segEc;
  TBranch *b_segSt;
  TBranch *b_segRi;
  TBranch *b_segCh;
  TBranch *b_segX;
  TBranch *b_segY;
  TBranch *b_lctId;
  TBranch *b_lctKWG;
  TBranch *b_lctKHS;
  TBranch *b_csctflctId;
  TBranch *b_csctflctKWG;
  TBranch *b_csctflctKHS;
  TBranch *b_emtflctId;
  TBranch *b_emtflctKWG;
  TBranch *b_emtflctKHS;
  TBranch *b_clctId;
  TBranch *b_clctKHS;
  TBranch *b_alctId;
  TBranch *b_alctKWG;
  TBranch *b_compId;
  TBranch *b_compLay;
  TBranch *b_compStr;
  TBranch *b_compHS;
  TBranch *b_compTimeOn;
  TBranch *b_wireId;
  TBranch *b_wireLay;
  TBranch *b_wireGrp;
  TBranch *b_wireTimeOn;

  // Set Branch Addresses
  myTree->SetBranchAddress("os",&os,&b_os);
  myTree->SetBranchAddress("Pt",&Pt,&b_Pt);
  myTree->SetBranchAddress("eta",&eta,&b_eta);
  myTree->SetBranchAddress("phi",&phi,&b_phi);
  myTree->SetBranchAddress("Nseg",&Nseg,&b_Nseg);
  myTree->SetBranchAddress("segEc",&segEc,&b_segEc);
  myTree->SetBranchAddress("segSt",&segSt,&b_segSt);
  myTree->SetBranchAddress("segRi",&segRi,&b_segRi);
  myTree->SetBranchAddress("segCh",&segCh,&b_segCh);
  myTree->SetBranchAddress("segX",&segX,&b_segX);
  myTree->SetBranchAddress("segY",&segY,&b_segY);
  myTree->SetBranchAddress("lctId",&lctId,&b_lctId);
  myTree->SetBranchAddress("lctKWG",&lctKWG,&b_lctKWG);
  myTree->SetBranchAddress("lctKHS",&lctKHS,&b_lctKHS);
  myTree->SetBranchAddress("csctflctId",&csctflctId,&b_csctflctId);
  myTree->SetBranchAddress("csctflctKWG",&csctflctKWG,&b_csctflctKWG);
  myTree->SetBranchAddress("csctflctKHS",&csctflctKHS,&b_csctflctKHS);
  myTree->SetBranchAddress("emtflctId",&emtflctId,&b_emtflctId);
  myTree->SetBranchAddress("emtflctKWG",&emtflctKWG,&b_emtflctKWG);
  myTree->SetBranchAddress("emtflctKHS",&emtflctKHS,&b_emtflctKHS);
  myTree->SetBranchAddress("clctId",&clctId,&b_clctId);
  myTree->SetBranchAddress("clctKHS",&clctKHS,&b_clctKHS);
  myTree->SetBranchAddress("alctId",&alctId,&b_alctId);
  myTree->SetBranchAddress("alctKWG",&alctKWG,&b_alctKWG);
  myTree->SetBranchAddress("compId",&compId,&b_compId);
  myTree->SetBranchAddress("compLay",&compLay,&b_compLay);
  myTree->SetBranchAddress("compStr",&compStr,&b_compStr);
  myTree->SetBranchAddress("compHS",&compHS,&b_compHS);
  myTree->SetBranchAddress("compTimeOn",&compTimeOn,&b_compTimeOn);
  myTree->SetBranchAddress("wireId",&wireId,&b_wireId);
  myTree->SetBranchAddress("wireLay",&wireLay,&b_wireLay);
  myTree->SetBranchAddress("wireGrp",&wireGrp,&b_wireGrp);
  myTree->SetBranchAddress("wireTimeOn",&wireTimeOn,&b_wireTimeOn);

  // Create Histograms
  
  // Types of Error
  plotter.book2D("cscVseg","CSCTF LCTs v. Segments",9,0,9,9,0,9);
  plotter.get2D("cscVseg")->GetXaxis()->SetTitle("CSCTF LCTs");
  plotter.get2D("cscVseg")->GetYaxis()->SetTitle("Segments");

  plotter.book2D("emtfVseg","EMTF LCTs v. Segments",9,0,9,9,0,9);
  plotter.get2D("emtfVseg")->GetXaxis()->SetTitle("EMTF LCTs");
  plotter.get2D("emtfVseg")->GetYaxis()->SetTitle("Segments");

  plotter.book2D("cscVemtf","CSCTF LCTs v. EMTF LCTs",9,0,9,9,0,9);
  plotter.get2D("cscVemtf")->GetXaxis()->SetTitle("CSCTF LCTs");
  plotter.get2D("cscVemtf")->GetYaxis()->SetTitle("EMTF LCTs");

  plotter.book2D("lctVemtf","LCTs v. EMTF LCTs",9,0,9,9,0,9);
  plotter.get2D("lctVemtf")->GetXaxis()->SetTitle("LCTs");
  plotter.get2D("lctVemtf")->GetYaxis()->SetTitle("EMTF LCTs");

  plotter.book2D("lctVcsc","LCTs v. CSC LCTs",9,0,9,9,0,9);
  plotter.get2D("lctVcsc")->GetXaxis()->SetTitle("LCTs");
  plotter.get2D("lctVcsc")->GetYaxis()->SetTitle("CSC LCTs");

  plotter.book2D("allVseg","All LCT Types v. Segments",9,0,9,9,0,9);
  plotter.get2D("allVseg")->GetXaxis()->SetTitle("All LCT Types");
  plotter.get2D("allVseg")->GetYaxis()->SetTitle("Segments");

  plotter.book1D("miLaSp","Missing Layers",6,1,7);
  plotter.get1D("miLaSp")->GetXaxis()->SetTitle("Missing Layer");

  plotter.book1D("miLaNoSp","Missing Layers",6,1,7);
  plotter.get1D("miLaNoSp")->GetXaxis()->SetTitle("Missing Layer");

  plotter.book2D("asWG","Difference in Wire Group Assignment for LCTs",112,0.5,112.5,112,0.5,112.5);
  plotter.get2D("asWG")->GetXaxis()->SetTitle("WG Assignment");
  plotter.get2D("asWG")->GetYaxis()->SetTitle("KWG");

  plotter.book1D("diWG","Difference in Wire Group Assignment for LCTs",225,-112.5,112.5);
  plotter.get1D("diWG")->GetXaxis()->SetTitle("KWG - WG Assignment");

  plotter.book1D("badAss","Bad WG Assignment",9,-0.5,8.5);

  // Occupancy and Efficiency Plots
  for (int j = 1; j < 5; j++){
    for (int k = 1; k < 4; k++){
      if (j != 1 && k == 3) continue;
      plotter.book2D(Form("oc%i%i",j,k),Form("Occupancy - Station %i Ring %i",j,k),84,-2,82,120,-4,116);
      plotter.get2D(Form("oc%i%i",j,k))->GetXaxis()->SetTitle("Strip");
      plotter.get2D(Form("oc%i%i",j,k))->GetYaxis()->SetTitle("Wire Group");

      plotter.book1D(Form("efEtNu%i%iFr",j,k),Form("Efficiency - Station %i Ring %i",j,k),140,1.1,2.5);
      plotter.get1D(Form("efEtNu%i%iFr",j,k))->GetXaxis()->SetTitle("Eta");
      plotter.get1D(Form("efEtNu%i%iFr",j,k))->GetYaxis()->SetTitle("Efficiency");
      plotter.book1D(Form("efEtDe%i%iFr",j,k),Form("Efficiency - Station %i Ring %i",j,k),140,1.1,2.5);

      plotter.book1D(Form("efEtNu%i%iRe",j,k),Form("Efficiency - Station %i Ring %i",j,k),140,1.1,2.5);
      plotter.get1D(Form("efEtNu%i%iRe",j,k))->GetXaxis()->SetTitle("Eta");
      plotter.get1D(Form("efEtNu%i%iRe",j,k))->GetYaxis()->SetTitle("Efficiency");
      plotter.book1D(Form("efEtDe%i%iRe",j,k),Form("Efficiency - Station %i Ring %i",j,k),140,1.1,2.5);

      plotter.book1D(Form("efThNu%i%iFr",j,k),Form("Efficiency - Station %i Ring %i",j,k),240,10,34);
      plotter.get1D(Form("efThNu%i%iFr",j,k))->GetXaxis()->SetTitle("Theta");
      plotter.get1D(Form("efThNu%i%iFr",j,k))->GetYaxis()->SetTitle("Efficiency");
      plotter.book1D(Form("efThDe%i%iFr",j,k),Form("Efficiency - Station %i Ring %i",j,k),240,10,34);

      plotter.book1D(Form("efThNu%i%iRe",j,k),Form("Efficiency - Station %i Ring %i",j,k),240,10,34);
      plotter.get1D(Form("efThNu%i%iRe",j,k))->GetXaxis()->SetTitle("Theta");
      plotter.get1D(Form("efThNu%i%iRe",j,k))->GetYaxis()->SetTitle("Efficiency");
      plotter.book1D(Form("efThDe%i%iRe",j,k),Form("Efficiency - Station %i Ring %i",j,k),240,10,34);

      plotter.book1D(Form("efWGNu%i%i",j,k),Form("Efficiency - Station %i Ring %i",j,k),120,-4,116);
      plotter.get1D(Form("efWGNu%i%i",j,k))->GetXaxis()->SetTitle("Wire Group");
      plotter.get1D(Form("efWGNu%i%i",j,k))->GetYaxis()->SetTitle("Efficiency");
      plotter.book1D(Form("efWGDe%i%i",j,k),Form("Efficiency - Station %i Ring %i",j,k),120,-4,116);

      plotter.book1D(Form("laSpLCT%i%i",j,k),Form("Number of Layer Hits - Station %i Ring %i",j,k),7,0,7);
      plotter.get1D(Form("laSpLCT%i%i",j,k))->GetXaxis()->SetTitle("Number of Layer Hits");

      plotter.book1D(Form("laSpNoLCT%i%i",j,k),Form("Number of Layer Hits - Station %i Ring %i",j,k),7,0,7);
      plotter.get1D(Form("laSpNoLCT%i%i",j,k))->GetXaxis()->SetTitle("Number of Layer Hits");

      plotter.book1D(Form("laNoSpLCT%i%i",j,k),Form("Number of Layer Hits - Station %i Ring %i",j,k),7,0,7);
      plotter.get1D(Form("laNoSpLCT%i%i",j,k))->GetXaxis()->SetTitle("Number of Layer Hits");

      plotter.book1D(Form("laNoSpNoLCT%i%i",j,k),Form("Number of Layer Hits - Station %i Ring %i",j,k),7,0,7);
      plotter.get1D(Form("laNoSpNoLCT%i%i",j,k))->GetXaxis()->SetTitle("Number of Layer Hits");

      plotter.book1D(Form("spOc%i%i",j,k),Form("Wire Group Occupancy (Eta Spacer Regions) - Station %i Ring %i",j,k),114,0,114);
      plotter.get1D(Form("spOc%i%i",j,k))->GetXaxis()->SetTitle("Wire Group");

      plotter.book2D(Form("yWG%i%i",j,k),Form("Y Position v. Wire Group - Station %i Ring %i",j,k),82,-164,164,114,0,114);
      plotter.get2D(Form("yWG%i%i",j,k))->GetXaxis()->SetTitle("Segment Y Position");
      plotter.get2D(Form("yWG%i%i",j,k))->GetYaxis()->SetTitle("Wire Group");

      plotter.book2D(Form("yKWG%i%i",j,k),Form("Y Position v. Wire Group - Station %i Ring %i",j,k),82,-164,164,114,0,114);
      plotter.get2D(Form("yKWG%i%i",j,k))->GetXaxis()->SetTitle("Segment Y Position");
      plotter.get2D(Form("yKWG%i%i",j,k))->GetYaxis()->SetTitle("Key Wire Group");

      plotter.book2D(Form("etEf%i%i",j,k),Form("Eta v. Wire Group Assignment - Station %i Ring %i",j,k),140,1.1,2.5,114,0,114);
      plotter.get2D(Form("etEf%i%i",j,k))->GetXaxis()->SetTitle("Eta");
      plotter.get2D(Form("etEf%i%i",j,k))->GetYaxis()->SetTitle("Wire Group");
    }   
  }

  plotter.book1D("spTiOn","Time Bins for Spacer Region Non-LCTs with 6 Layer Hits",40,0,40);
  plotter.book1D("noTiOn","Time Bins for Spacer Region LCTs with 6 Layer Hits",40,0,40);

  // Loop Over Muons
  
//  nEntries = 10000;

  for (long int muon = 0; muon < nEntries; ++muon){
    int pbar = (long int) (muon+1) * 50 / (long int) nEntries;
    std::string prog(pbar,'-');
    std::string left(50-pbar,' ');
    std::cout << "\r" << "|" << prog << left << "| " << (long int) (muon+1)*100/nEntries << "%"; 
    std::cout.flush();
  
    myTree->TTree::GetEntry(muon); 
    if (!os) continue;

    double aeta = TMath::Abs(eta);
    double theta = 360/TMath::Pi()*TMath::ATan(exp(-aeta));

    plotter.get2D("cscVseg")->Fill(csctflctId->size(),Nseg);
    plotter.get2D("emtfVseg")->Fill(emtflctId->size(),Nseg);
    plotter.get2D("cscVemtf")->Fill(csctflctId->size(),emtflctId->size());
    plotter.get2D("lctVemtf")->Fill(lctId->size(),emtflctId->size());
    plotter.get2D("lctVcsc")->Fill(lctId->size(),csctflctId->size());
    plotter.get2D("allVseg")->Fill(max({csctflctId->size(),emtflctId->size(),lctId->size()}),Nseg);

    // Loop Over Segments
    if (emtflctId->size() != lctId->size()) continue;
    for (int iseg = 0; iseg < (int) Nseg; ++iseg){
      // Calculate Chamber Serial
      int EC = segEc->at(iseg);
      int ST = segSt->at(iseg);
      int RI = segRi->at(iseg);
      int CH = segCh->at(iseg);
      int serial = ChamberSerial(EC,ST,RI,CH);
      // Determine if Segment Has LCT
      bool has_lct = false;
      for (int ilct = 0; ilct < lctId->size(); ++ilct){
        if (lctId->at(ilct) == serial){
	  has_lct = true;
          break;
        }
      }
      if (ST == 1 && RI == 4) RI = 1;
      // Assign a Primary Wire Group For The Segment
      int WG;
      if (has_lct){
        for (int iwid = 0; iwid < lctId->size(); iwid++){
          if (lctId->at(iwid) != serial) continue;
          if (lctKWG->at(iwid).size() > 0) WG = lctKWG->at(iwid).at(0);
        }    
      } else WG = WireGroup(serial,ST,RI,segY->at(iseg),wireId,wireGrp);
      double WGuess = WireGroup(serial,ST,RI,segY->at(iseg),wireId,wireGrp);
      int nLay = 0, nALay = 0, nCLay = 0, nCoLay = 0;
      bool is_spacer = false;
      int closest;
      plotter.get2D(Form("etEf%i%i",ST,RI))->Fill(aeta,WG);
      // Plot Efficiency
      if (CH % 2 == 0){
        plotter.get1D(Form("efEtDe%i%iFr",ST,RI))->Fill(aeta);
        plotter.get1D(Form("efThDe%i%iFr",ST,RI))->Fill(theta);
      } else {
        plotter.get1D(Form("efEtDe%i%iRe",ST,RI))->Fill(aeta);
        plotter.get1D(Form("efThDe%i%iRe",ST,RI))->Fill(theta);
      } plotter.get1D(Form("efWGDe%i%i",ST,RI))->Fill(WG);
      if (has_lct){
        if (CH % 2 == 0){
          plotter.get1D(Form("efEtNu%i%iFr",ST,RI))->Fill(aeta);
          plotter.get1D(Form("efThNu%i%iFr",ST,RI))->Fill(theta);
        } else {
          plotter.get1D(Form("efEtNu%i%iRe",ST,RI))->Fill(aeta);
          plotter.get1D(Form("efThNu%i%iRe",ST,RI))->Fill(theta);
        } plotter.get1D(Form("efWGNu%i%i",ST,RI))->Fill(WG);
      }
      std::vector<bool> layers = {true,true,true,true,true,true};
      for (int iwid = 0; iwid < wireGrp->size(); iwid++){
        if (wireId->at(iwid) == serial){
          if (wireGrp->at(iwid).size() > 0){
            closest = 999;
            for (int igrp = 0; igrp < wireGrp->at(iwid).size(); igrp++){
              int wHit = wireGrp->at(iwid).at(igrp);
	      if ((abs(wHit - WG) < 5) && (abs(wHit - WG) < abs(closest - WG))) closest = wHit; 
            }
          } if (closest == 999) layers.at(iwid % 6) = false; 
	  else {
            nLay++;
            if ((ST == 1 && RI == 2) && (closest == 24 || closest == 25 || closest == 48 || closest == 49)) is_spacer = true;
            else if ((ST == 1 && RI == 3) && (closest == 12 || closest == 13 || closest == 22 || closest == 23)) is_spacer = true;
            else if ((ST == 2 && RI == 1) && (closest == 44 || closest == 45 || closest == 80 || closest == 81)) is_spacer = true;
            else if ((ST != 1 && RI == 1) && (closest == 32 || closest == 33 || closest == 64 || closest == 65)) is_spacer = true;
            else if ((ST != 1 && RI == 2) && (closest == 16 || closest == 17 || closest == 28 || closest == 29 || closest == 40 || closest == 41 || closest == 52 || closest == 52)) is_spacer = true;
          }
        }
      }
      for (int i = 0; i < 6; i++){
        if (layers.at(i) == false){
          if (is_spacer) plotter.get1D("miLaSp")->Fill(i+1);
          else plotter.get1D("miLaNoSp")->Fill(i+1);
        }
      }
      if (is_spacer) plotter.get1D(Form("spOc%i%i",ST,RI))->Fill(WG);
      if (is_spacer && has_lct) plotter.get1D(Form("laSpLCT%i%i",ST,RI))->Fill(nLay);
      else if (is_spacer && !has_lct) plotter.get1D(Form("laSpNoLCT%i%i",ST,RI))->Fill(nLay);
      else if (!is_spacer && has_lct) plotter.get1D(Form("laNoSpLCT%i%i",ST,RI))->Fill(nLay);
      else plotter.get1D(Form("laNoSpNoLCT%i%i",ST,RI))->Fill(nLay);
      if (has_lct){
        for (int ilct = 0; ilct < lctId->size(); ilct++){
          if (lctId->at(ilct) == serial){
            if (lctKWG->at(ilct).size() > 0){
              plotter.get2D("asWG")->Fill(WGuess,lctKWG->at(ilct).at(0));
              plotter.get1D("diWG")->Fill(lctKWG->at(ilct).at(0) - WGuess);
              plotter.get2D(Form("yWG%i%i",ST,RI))->Fill(segY->at(iseg),WGuess);
              plotter.get2D(Form("yKWG%i%i",ST,RI))->Fill(segY->at(iseg),lctKWG->at(ilct).at(0));
              if (fabs(lctKWG->at(ilct).at(0) - WGuess) > 4){
                if (ST == 1 && RI == 3) plotter.get1D("badAss")->Fill(0);
                else plotter.get1D("badAss")->Fill(2*(ST-1)+RI);
              }
            }
          }
        }
      }

      if (is_spacer && nLay == 6){
        for (int iwid = 0; iwid < wireGrp->size(); iwid++){
          if (wireId->at(iwid) == serial){
            for (int igrp = 0; igrp < wireGrp->at(iwid).size(); igrp++){
              if (fabs(wireGrp->at(iwid).at(igrp) - WG) < 5){
                for (int iton = 0; iton < wireTimeOn->at(iwid).at(igrp).size(); iton++){
                  if (!has_lct) plotter.get1D("spTiOn")->Fill(wireTimeOn->at(iwid).at(igrp).at(iton));
                  else plotter.get1D("noTiOn")->Fill(wireTimeOn->at(iwid).at(igrp).at(iton));
                }
              }
            }
          }
        }
      }  
      
            
      /* if (has_lct && nLay < 4){
        std::cout << endl << WG << "  " << nLay << "   " << segY->at(iseg) << endl;
        for (int iwid = 0; iwid < wireGrp->size(); iwid++){
          if (wireId->at(iwid) == serial){
            std::cout << iwid%6 + 1 << "   ";
            if (wireGrp->at(iwid).size() > 0){
              for (int igrp = 0; igrp < wireGrp->at(iwid).size(); igrp++){
                std::cout << wireGrp->at(iwid).at(igrp) << " ";
	      }
	    } std::cout << endl;
          }
        }
        for (int ilid = 0; ilid < lctKWG->size(); ilid++){
          if (lctId->at(ilid) == serial){
            std::cout << ilid%6 + 1 << "   ";
            if (lctKWG->at(ilid).size() > 0){
              for (int ilwg = 0; ilwg < lctKWG->at(ilid).size(); ilwg++){
                std::cout << lctKWG->at(ilid).at(ilwg) << " ";
              }
            } std::cout << endl;
          }
        } 
      } */
/*      if (ST == 1){
        if (RI == 2){
          if ((WG > 21 && WG < 28) || (WG > 45 && WG < 52)){
            if (has_lct){
              plotter.get1D("laSpLCT12")->Fill(nLay);
              plotter.get1D("alaSpLCT12")->Fill(nALay);
              plotter.get1D("claSpLCT12")->Fill(nCLay);
              plotter.get1D("colaSpLCT12")->Fill(nCoLay);
            } else {
              plotter.get1D("laSpNoLCT12")->Fill(nLay);
              plotter.get1D("alaSpNoLCT12")->Fill(nALay);
              plotter.get1D("claSpNoLCT12")->Fill(nCLay);
              plotter.get1D("colaSpNoLCT12")->Fill(nCoLay);
            }
          } else {
            if (has_lct){
              plotter.get1D("laNoSpLCT12")->Fill(nLay);
              plotter.get1D("alaNoSpLCT12")->Fill(nALay);
              plotter.get1D("claNoSpLCT12")->Fill(nCLay);
              plotter.get1D("colaNoSpLCT12")->Fill(nCoLay);
            } else {
              plotter.get1D("laNoSpNoLCT12")->Fill(nLay);
              plotter.get1D("alaNoSpNoLCT12")->Fill(nALay);
              plotter.get1D("claNoSpNoLCT12")->Fill(nCLay);
              plotter.get1D("colaNoSpNoLCT12")->Fill(nCoLay);
            }
          }
        }
        if (RI == 3){
          if ((WG > 10 && WG < 15) || (WG > 20 && WG < 25)){
            if (has_lct) {
              plotter.get1D("laSpLCT13")->Fill(nLay);
              plotter.get1D("alaSpLCT13")->Fill(nALay);
              plotter.get1D("claSpLCT13")->Fill(nCLay);
              plotter.get1D("colaSpLCT13")->Fill(nCoLay);
            } else {
	      plotter.get1D("laSpNoLCT13")->Fill(nLay);
              plotter.get1D("alaSpNoLCT13")->Fill(nALay);
              plotter.get1D("claSpNoLCT13")->Fill(nCLay);
              plotter.get1D("colaSpNoLCT13")->Fill(nCoLay);
            }
          } else {
            if (has_lct) {
              plotter.get1D("laNoSpLCT13")->Fill(nLay);
              plotter.get1D("alaNoSpLCT13")->Fill(nALay);
              plotter.get1D("claNoSpLCT13")->Fill(nCLay);
              plotter.get1D("colaNoSpLCT13")->Fill(nCoLay);
            } else {
              plotter.get1D("laNoSpNoLCT13")->Fill(nLay);
              plotter.get1D("alaNoSpNoLCT13")->Fill(nALay);
              plotter.get1D("claNoSpNoLCT13")->Fill(nCLay);
              plotter.get1D("colaNoSpNoLCT13")->Fill(nCoLay);
            }
          }
        }
      }
      if (ST == 2){
        if (RI == 1){
          if ((WG > 41 && WG < 48) || (WG > 77 && WG < 84)){
            if (has_lct) {
              plotter.get1D("laSpLCT21")->Fill(nLay);
              plotter.get1D("alaSpLCT21")->Fill(nALay);
              plotter.get1D("claSpLCT21")->Fill(nCLay);
              plotter.get1D("colaSpLCT21")->Fill(nCoLay);
            } else {
              plotter.get1D("laSpNoLCT21")->Fill(nLay);
              plotter.get1D("alaSpNoLCT21")->Fill(nALay);
              plotter.get1D("claSpNoLCT21")->Fill(nCLay);
              plotter.get1D("colaSpNoLCT21")->Fill(nCoLay);
            }
          } else {
            if (has_lct) {
              plotter.get1D("laNoSpLCT21")->Fill(nLay);
              plotter.get1D("alaNoSpLCT21")->Fill(nALay);
              plotter.get1D("claNoSpLCT21")->Fill(nCLay);
              plotter.get1D("colaNoSpLCT21")->Fill(nCoLay);
            } else {
              plotter.get1D("laNoSpNoLCT21")->Fill(nLay);
              plotter.get1D("alaNoSpNoLCT21")->Fill(nALay);
              plotter.get1D("claNoSpNoLCT21")->Fill(nCLay);
              plotter.get1D("colaNoSpNoLCT21")->Fill(nCoLay);
            }
          }
        }
      }
      if ((ST == 3 || ST == 4) && RI == 1){
        if ((WG > 29 && WG < 36) || (WG > 61 && WG < 68)){
          if (has_lct) {
            plotter.get1D(Form("laSpLCT%i1",ST))->Fill(nLay);
            plotter.get1D(Form("alaSpLCT%i1",ST))->Fill(nALay);
            plotter.get1D(Form("claSpLCT%i1",ST))->Fill(nCLay);
            plotter.get1D(Form("colaSpLCT%i1",ST))->Fill(nCoLay);
          } else {
            plotter.get1D(Form("laSpNoLCT%i1",ST))->Fill(nLay);
            plotter.get1D(Form("alaSpNoLCT%i1",ST))->Fill(nALay);
            plotter.get1D(Form("claSpNoLCT%i1",ST))->Fill(nCLay);
            plotter.get1D(Form("colaSpNoLCT%i1",ST))->Fill(nCoLay);
          }
        } else {
          if (has_lct) {
            plotter.get1D(Form("laNoSpLCT%i1",ST))->Fill(nLay);
            plotter.get1D(Form("alaNoSpLCT%i1",ST))->Fill(nALay);
            plotter.get1D(Form("claNoSpLCT%i1",ST))->Fill(nCLay);
            plotter.get1D(Form("colaNoSpLCT%i1",ST))->Fill(nCoLay);
          } else {
            plotter.get1D(Form("laNoSpNoLCT%i1",ST))->Fill(nLay);
            plotter.get1D(Form("alaNoSpNoLCT%i1",ST))->Fill(nALay);
            plotter.get1D(Form("claNoSpNoLCT%i1",ST))->Fill(nCLay);
            plotter.get1D(Form("colaNoSpNoLCT%i1",ST))->Fill(nCoLay);
          }
        }
      }
      if ((ST == 2 || ST == 3 || ST == 4) && RI == 2){
        if ((WG > 14 && WG < 19) || (WG > 26 && WG < 31) || (WG > 38 && WG < 43) || (WG > 50 && WG < 55)){
          if (has_lct) {
            plotter.get1D(Form("laSpLCT%i2",ST))->Fill(nLay);
            plotter.get1D(Form("alaSpLCT%i2",ST))->Fill(nALay);
            plotter.get1D(Form("claSpLCT%i2",ST))->Fill(nCLay);
            plotter.get1D(Form("colaSpLCT%i2",ST))->Fill(nCoLay);
          } else {
            plotter.get1D(Form("laSpNoLCT%i2",ST))->Fill(nLay);
            plotter.get1D(Form("alaSpNoLCT%i2",ST))->Fill(nALay);
            plotter.get1D(Form("claSpNoLCT%i2",ST))->Fill(nCLay);
            plotter.get1D(Form("colaSpNoLCT%i2",ST))->Fill(nCoLay);
          }
        } else {
          if (has_lct) {
            plotter.get1D(Form("laNoSpLCT%i2",ST))->Fill(nLay);
            plotter.get1D(Form("alaNoSpLCT%i2",ST))->Fill(nALay);
            plotter.get1D(Form("claNoSpLCT%i2",ST))->Fill(nCLay);
            plotter.get1D(Form("colaNoSpLCT%i2",ST))->Fill(nCoLay);
          } else {
            plotter.get1D(Form("laNoSpNoLCT%i2",ST))->Fill(nLay);
            plotter.get1D(Form("alaNoSpNoLCT%i2",ST))->Fill(nALay);
            plotter.get1D(Form("claNoSpNoLCT%i2",ST))->Fill(nCLay);
            plotter.get1D(Form("colaNoSpNoLCT%i2",ST))->Fill(nCoLay);
          }
        } 
      } */ 

/*      if (!has_lct && ST == 1 && theta > 13.5 && theta < 14.6){
        for (int iwid = 0; iwid < wireId->size(); ++iwid){
          if (wireId->at(iwid) != serial) continue;
          int lay = wireLay->at(iwid);
          std::vector<std::vector<int> > wtio = wireTimeOn->at(iwid);
          std::vector<int> wgrp = wireGrp->at(iwid);
          std::cout << nMu << "   " << iseg << "   " << lay << "   ";
          for (int igrp = 0; igrp < wgrp.size(); igrp++){
            std::cout << wgrp.at(igrp) << "(";
            std::vector<int> wtit = wtio.at(igrp);
            for (int iwit = 0; iwit < wtit.size(); iwit++){
              std::cout << wtit.at(iwit) << " ";
            } std::cout << ") ";
          } std::cout << endl; 
        } for (int icid = 0; icid < compId->size(); ++icid){
          if (compId->at(icid) != serial) continue;
          int clay = compLay->at(icid);
          std::vector<int> chs = compHS->at(icid);
          std::vector<int> cst = compStr->at(icid);
          std::cout << nMu << "   " << iseg << "   " << clay << "   ";
          for (int icst = 0; icst < compStr->at(icid).size(); ++icst){
            if (clay % 2 == 1) std::cout << 2*(compStr->at(icid).at(icst) - 1) + compHS->at(icid).at(icst) << "(";
            else std::cout << 2*(compStr->at(icid).at(icst) - 1) + compHS->at(icid).at(icst) - 1 << "(";
            for (int icot = 0; icot < compTimeOn->at(icid).at(icst).size(); ++icot){
              std::cout << compTimeOn->at(icid).at(icst).at(icot) << " ";
            } std::cout << ") ";
          } std::cout << endl;
        } 
        std::cout << ST << "  " << RI << "  " << CH << "  " << theta << endl << endl; nMi++;
      }
      // Fill Numerator and Denominator Histograms for Efficiency Plots
      switch (ST){
        case 1: if (CH % 2 == 0){ thDeOnFr->Fill(theta); efDeOnFr->Fill(aeta); }
                else{ thDeOnRe->Fill(theta); efDeOnRe->Fill(aeta); } break; 
        case 2: if (CH % 2 == 0){ thDeTwFr->Fill(theta); efDeTwFr->Fill(aeta); }
                else{ thDeTwRe->Fill(theta); efDeTwRe->Fill(aeta); } break;
        case 3: if (CH % 2 == 0){ thDeThFr->Fill(theta); efDeThFr->Fill(aeta); }
                else{ thDeThRe->Fill(theta); efDeThRe->Fill(aeta); } break;
        case 4: if (CH % 2 == 0){ thDeFoFr->Fill(theta); efDeFoFr->Fill(aeta); }
                else{ thDeFoRe->Fill(theta); efDeFoRe->Fill(aeta); } break;
      }
      if (has_lct){
        switch (ST){
          case 1: if (CH % 2 == 0){ thNuOnFr->Fill(theta); efNuOnFr->Fill(aeta); }
                  else{ thNuOnRe->Fill(theta); efNuOnRe->Fill(aeta); } break;
          case 2: if (CH % 2 == 0){ thNuTwFr->Fill(theta); efNuTwFr->Fill(aeta); }
                  else{ thNuTwRe->Fill(theta); efNuTwRe->Fill(aeta); } break;
          case 3: if (CH % 2 == 0){ thNuThFr->Fill(theta); efNuThFr->Fill(aeta); }
                  else{ thNuThRe->Fill(theta); efNuThRe->Fill(aeta); } break;
          case 4: if (CH % 2 == 0){ thNuFoFr->Fill(theta); efNuFoFr->Fill(aeta); }
                  else{ thNuFoRe->Fill(theta); efNuFoRe->Fill(aeta); } break;
        }
      } */
    }       
  } std::cout << endl;

/*  efNuOnFr->Divide(efDeOnFr);
  efNuTwFr->Divide(efDeTwFr);
  efNuThFr->Divide(efDeThFr);
  efNuFoFr->Divide(efDeFoFr);
  efNuOnRe->Divide(efDeOnRe);
  efNuTwRe->Divide(efDeTwRe);
  efNuThRe->Divide(efDeThRe);
  efNuFoRe->Divide(efDeFoRe);

  thNuOnFr->Divide(thDeOnFr);
  thNuTwFr->Divide(thDeTwFr);
  thNuThFr->Divide(thDeThFr);
  thNuFoFr->Divide(thDeFoFr);
  thNuOnRe->Divide(thDeOnRe);
  thNuTwRe->Divide(thDeTwRe);
  thNuThRe->Divide(thDeThRe);
  thNuFoRe->Divide(thDeFoRe);

  efNuOnFr->SetMinimum(0.7);
  efNuTwFr->SetMinimum(0.7);
  efNuThFr->SetMinimum(0.7);
  efNuFoFr->SetMinimum(0.7);
  efNuOnRe->SetMinimum(0.7);
  efNuTwRe->SetMinimum(0.7);
  efNuThRe->SetMinimum(0.7);
  efNuFoRe->SetMinimum(0.7);

  thNuOnFr->SetMinimum(0.7);
  thNuTwFr->SetMinimum(0.7);
  thNuThFr->SetMinimum(0.7);
  thNuFoFr->SetMinimum(0.7);
  thNuOnRe->SetMinimum(0.7);
  thNuTwRe->SetMinimum(0.7);
  thNuThRe->SetMinimum(0.7);
  thNuFoRe->SetMinimum(0.7);

  // Superimpose Histograms
  c1->cd();
  thNuOnFr->Draw();
  thNuOnRe->Draw("same");
  thNuOnFr->TAttLine::SetLineColor(kRed);  
  thNuOnRe->TAttLine::SetLineColor(kBlue);
  TLegend *l1 = new TLegend(.9,.7,.98,.78);
  l1->AddEntry(thNuOnFr,"Front");
  l1->AddEntry(thNuOnRe,"Rear");
  l1->Draw();
 
  c2->cd();
  thNuTwFr->Draw();
  thNuTwRe->Draw("same");
  thNuTwFr->TAttLine::SetLineColor(kRed);
  thNuTwRe->TAttLine::SetLineColor(kBlue);
  l1->Draw();

  c3->cd();
  thNuThFr->Draw();
  thNuThRe->Draw("same");
  thNuThFr->TAttLine::SetLineColor(kRed);
  thNuThRe->TAttLine::SetLineColor(kBlue);
  l1->Draw();

  c4->cd();
  thNuFoFr->Draw();
  thNuFoRe->Draw("same");
  thNuFoFr->TAttLine::SetLineColor(kRed);
  thNuFoRe->TAttLine::SetLineColor(kBlue);
  l1->Draw();

  c5->cd();
  efNuOnFr->Draw();
  efNuOnRe->Draw("same");
  efNuOnFr->TAttLine::SetLineColor(kRed);
  efNuOnRe->TAttLine::SetLineColor(kBlue);
  l1->Draw();

  c6->cd();
  efNuTwFr->Draw();
  efNuTwRe->Draw("same");
  efNuTwFr->TAttLine::SetLineColor(kRed);
  efNuTwRe->TAttLine::SetLineColor(kBlue);
  l1->Draw();

  c7->cd();
  efNuThFr->Draw();
  efNuThRe->Draw("same");
  efNuThFr->TAttLine::SetLineColor(kRed);
  efNuThRe->TAttLine::SetLineColor(kBlue);
  l1->Draw();

  c8->cd();
  efNuFoFr->Draw();
  efNuFoRe->Draw("same");
  efNuFoFr->TAttLine::SetLineColor(kRed);
  efNuFoRe->TAttLine::SetLineColor(kBlue);
  l1->Draw();

  for (int l = 0; l < 5; ++l){
    cans[0]->cd();
    ocOn[i]->Draw("same");
    cans[1]->cd();
    ocTw[i]->Draw("same");
    cans[2]->cd();
    ocTh[i]->Draw("same");
    cans[3]->cd();
    ocFo[i]->Draw("same");
  }     

  // Save Histograms to File
  TFile *outFile = new TFile("analysis/outFile.root","RECREATE");

  efNuOnFr->Write("efNuOnFr");
  efNuTwFr->Write("efNuTwFr");
  efNuThFr->Write("efNuThFr");
  efNuFoFr->Write("efNuFoFr");
  efNuOnRe->Write("efNuOnRe");
  efNuTwRe->Write("efNuTwRe");
  efNuThRe->Write("efNuThRe");
  efNuFoRe->Write("efNuFoRe");

  thNuOnFr->Write("thNuOnFr");
  thNuTwFr->Write("thNuTwFr");
  thNuThFr->Write("thNuThFr");
  thNuFoFr->Write("thNuFoFr");
  thNuOnRe->Write("thNuOnRe");
  thNuTwRe->Write("thNuTwRe");
  thNuThRe->Write("thNuThRe");
  thNuFoRe->Write("thNuFoRe");

  nuMi->Write("nuMi");

  c1->Write();
  c2->Write();
  c3->Write();
  c4->Write();
  c5->Write();
  c6->Write();
  c7->Write();
  c8->Write();

  for (int l = 0; l < 4; ++l) cans[i]->Write();

  outFile->Write();
  outFile->Close(); */

  plotter.write("analysis/outFile.root");

//  for (int i = 0; i < 18; i++) std::cout << yranges.at(i) << "  ";
} 
