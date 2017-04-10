// This Macro Plots Information About Missed LCTs In the Spacer Bar Region.

#include "HistGetter.h"
#include "ChamberSerial.h"
#include <TMath.h>
#include <TTree.h>

int main(){

  // Some Goddamn Black Magic
  HistGetter plotter;
 
  // Allow Vector Types Included In Data
//  gInterpreter->GenerateDictionary("std::vector<std::vector<int> >","vector");
//  gInterpreter->GenerateDictionary("std::vector<std::vector<std::vector<int> > >","vector");

  // Open File and Load Tree
  TFile inFile("blocks/cscDigiTree.root");
  TTree* myTree = (TTree*) inFile.Get("CSCDigiTree");
 
  // Declaration Of Variables and Branches
  Int_t Nseg;
  Double_t eta;
  Double_t phi;
  bool os;
  Double_t Pt;
  std::vector<int> *segEc;
  std::vector<int> *segSt;
  std::vector<int> *segRi;
  std::vector<int> *segCh;
  std::vector<int> *rhId;
  std::vector<int> *lctId;
  std::vector<int> *alctId;
  std::vector<int> *clctId;
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

  long int nMu = 0;
  long int nMi = 0;
  int wEC, wST, wRI, wCH;

  TBranch *b_Nseg;
  TBranch *b_eta;
  TBranch *b_phi;
  TBranch *b_os;
  TBranch *b_Pt;
  TBranch *b_segEc;
  TBranch *b_segSt;
  TBranch *b_segRi;
  TBranch *b_segCh;
  TBranch *b_rhId;
  TBranch *b_lctId;
  TBranch *b_alctId;
  TBranch *b_clctId;
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
  myTree->SetBranchAddress("Nseg",&Nseg,&b_Nseg);
  myTree->SetBranchAddress("os",&os,&b_os);
  myTree->SetBranchAddress("Pt",&Pt,&b_Pt);
  myTree->SetBranchAddress("eta",&eta,&b_eta);
  myTree->SetBranchAddress("phi",&phi,&b_phi);
  myTree->SetBranchAddress("segEc",&segEc,&b_segEc);
  myTree->SetBranchAddress("segSt",&segSt,&b_segSt);
  myTree->SetBranchAddress("segRi",&segRi,&b_segRi);
  myTree->SetBranchAddress("segCh",&segCh,&b_segCh);
  myTree->SetBranchAddress("rhId",&rhId,&b_rhId);
  myTree->SetBranchAddress("lctId",&lctId,&b_lctId);
  myTree->SetBranchAddress("alctId",&alctId,&b_alctId);
  myTree->SetBranchAddress("clctId",&clctId,&b_clctId);
  myTree->SetBranchAddress("compId",&compId,&b_compId);
  myTree->SetBranchAddress("compLay",&compLay,&b_compLay);
  myTree->SetBranchAddress("compStr",&compStr,&b_compStr);
  myTree->SetBranchAddress("compHS",&compHS,&b_compHS);
  myTree->SetBranchAddress("compTimeOn",&compTimeOn,&b_compTimeOn);
  myTree->SetBranchAddress("wireId",&wireId,&b_wireId);
  myTree->SetBranchAddress("wireLay",&wireLay,&b_wireLay);
  myTree->SetBranchAddress("wireGrp",&wireGrp,&b_wireGrp);
  myTree->SetBranchAddress("wireTimeOn",&wireTimeOn,&b_wireTimeOn);

  // Create Canvasses
/*  TCanvas *c1 = new TCanvas("Station One - Theta");
  TCanvas *c2 = new TCanvas("Station Two - Theta");
  TCanvas *c3 = new TCanvas("Station Three - Theta");
  TCanvas *c4 = new TCanvas("Station Four - Theta");
  TCanvas *c5 = new TCanvas("Station One - Eta");
  TCanvas *c6 = new TCanvas("Station Two - Eta");
  TCanvas *c7 = new TCanvas("Station Three - Eta");
  TCanvas *c8 = new TCanvas("Station Four - Eta");
  TCanvas *c9 = new TCanvas("Occupancy - Station One");
  TCanvas *c10 = new TCanvas("Occupancy - Station Two");
  TCanvas *c11 = new TCanvas("Occupancy - Station Three");
  TCanvas *c12 = new TCanvas("Occupancy - Station Four"); */

  // Create Histograms
  plotter.book1D("numSegs","Number of Segments",3,1,4);
  for (Int_t i = 1; i < 4; ++i) plotter.get1D("numSegs")->GetXaxis()->SetBinLabel(i,Form("%i",i));
  plotter.get1D("numSegs")->SetMinimum(0);

  plotter.book1D("miSt","Missing Station",4,1,5);
  for (Int_t i = 1; i < 5; ++i) plotter.get1D("miSt")->GetXaxis()->SetBinLabel(i,Form("%i",i));
  plotter.get1D("miSt")->SetMinimum(0);

  plotter.book1D("nuMi","Number of Missing Layers",6,0,6);
  for (Int_t i = 1; i < 7; ++i) plotter.get1D("nuMi")->GetXaxis()->SetBinLabel(i,Form("%i",i-1));
  plotter.get1D("nuMi")->SetMinimum(0);

  plotter.book1D("miEtOn","Eta of Missing LCTs - Station One",140,1.1,2.5);
  plotter.get1D("miEtOn")->SetMinimum(0);

  plotter.book1D("miEtTw","Eta of Missing LCTs - Station Two",140,1.1,2.5);
  plotter.get1D("miEtTw")->SetMinimum(0);

  plotter.book1D("miEtTh","Eta of Missing LCTs - Station Three",140,1.1,2.5);
  plotter.get1D("miEtTh")->SetMinimum(0);

  plotter.book1D("miEtFo","Eta of Missing LCTs - Station Four",140,1.1,2.5);
  plotter.get1D("miEtFo")->SetMinimum(0);

  // Efficiency Plots in Eta and Theta
  for (int j = 1; j < 5; j++){
    plotter.book1D(Form("efNu%iFr",j),Form("Station %i Efficiency",j),140,1.1,2.5);
    plotter.book1D(Form("efNu%iRe",j),Form("Station %i Efficiency",j),140,1.1,2.5);
    plotter.book1D(Form("efDe%iFr",j),Form("Station %i Efficiency",j),140,1.1,2.5);
    plotter.book1D(Form("efDe%iRe",j),Form("Station %i Efficiency",j),140,1.1,2.5);
    plotter.book1D(Form("thNu%iFr",j),Form("Station %i Efficiency",j),240,10,34);
    plotter.book1D(Form("thNu%iRe",j),Form("Station %i Efficiency",j),240,10,34);
    plotter.book1D(Form("thDe%iFr",j),Form("Station %i Efficiency",j),240,10,34);
    plotter.book1D(Form("thDe%iRe",j),Form("Station %i Efficiency",j),240,10,34);
  }

  // Occupancy Plots
  for (int k = 0; k < 5; k++){
    plotter.book2D(Form("ocOn%i",k),"Occupancy - Station One",160,-8,8,160,-8,8);
    plotter.book2D(Form("ocTw%i",k),"Occupancy - Station Two",160,-8,8,160,-8,8);
    plotter.book2D(Form("ocTh%i",k),"Occupancy - Station Three",160,-8,8,160,-8,8);
    plotter.book2D(Form("ocFo%i",k),"Occupancy - Station Four",160,-8,8,160,-8,8);
  }
  
  // Loop Over Muons
  for (long int muon = 0; muon < 1000; ++muon){
    myTree->TTree::GetEntry(muon); 
    if (!os) continue;
    double aeta = TMath::Abs(eta);
    if (aeta < 1.2 || aeta > 2.4) continue;
    double theta = 360/TMath::Pi()*TMath::ATan(exp(-aeta));
    nMu++;
    // Loop Over Segments
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
      if (has_lct) continue;
      double x,y,r;
      double rtheta = TMath::Pi()/180*theta;
      switch (ST){
        case 1: if (RI == 1 || RI == 4) r = 5.68*TMath::Tan(rtheta);
                else r = 6.68*TMath::Tan(rtheta);
                x = r*TMath::Cos(phi);
                y = r*TMath::Sin(phi);
                plotter.get2D(Form("ocOn%i",CH%5))->Fill(x,y); break;               
        case 2: r = 8.1*TMath::Tan(rtheta);
                x = r*TMath::Cos(phi);
                y = r*TMath::Sin(phi);
                plotter.get2D(Form("ocTw%i",CH%5))->Fill(x,y); break;
        case 3: r = 9.115*TMath::Tan(rtheta);
                x = r*TMath::Cos(phi);
                y = r*TMath::Sin(phi);
                plotter.get2D(Form("ocTh%i",CH%5))->Fill(x,y); break;
        case 4: r = 10.002*TMath::Tan(rtheta);
                x = r*TMath::Cos(phi);
                y = r*TMath::Sin(phi);
                plotter.get2D(Form("ocFo%i",CH%5))->Fill(x,y); break;
      }
//      if (!has_lct && ST == 1 && theta > 13.5 && theta < 14.6){
//        for (int iwid = 0; iwid < wireId->size(); ++iwid){
//          if (wireId->at(iwid) != serial) continue;
//          int lay = wireLay->at(iwid);
//          std::vector<std::vector<int> > wtio = wireTimeOn->at(iwid);
//          std::vector<int> wgrp = wireGrp->at(iwid);
//          std::cout << nMu << "   " << iseg << "   " << lay << "   ";
//          for (int igrp = 0; igrp < wgrp.size(); igrp++){
//            std::cout << wgrp.at(igrp) << "(";
//            std::vector<int> wtit = wtio.at(igrp);
//            for (int iwit = 0; iwit < wtit.size(); iwit++){
//              std::cout << wtit.at(iwit) << " ";
//            } std::cout << ") ";
//          } std::cout << endl; 
//        } for (int icid = 0; icid < compId->size(); ++icid){
//          if (compId->at(icid) != serial) continue;
//          int clay = compLay->at(icid);
//          std::vector<int> chs = compHS->at(icid);
//          std::vector<int> cst = compStr->at(icid);
//          std::cout << nMu << "   " << iseg << "   " << clay << "   ";
//          for (int icst = 0; icst < compStr->at(icid).size(); ++icst){
//            if (clay % 2 == 1) std::cout << 2*(compStr->at(icid).at(icst) - 1) + compHS->at(icid).at(icst) << "(";
//            else std::cout << 2*(compStr->at(icid).at(icst) - 1) + compHS->at(icid).at(icst) - 1 << "(";
//            for (int icot = 0; icot < compTimeOn->at(icid).at(icst).size(); ++icot){
//              std::cout << compTimeOn->at(icid).at(icst).at(icot) << " ";
//            } std::cout << ") ";
//          } std::cout << endl;
//        } 
//        std::cout << ST << "  " << RI << "  " << CH << "  " << theta << endl << endl; nMi++;
//      }
      // Fill Numerator and Denominator Histograms for Efficiency Plots
//      switch (ST){
//        case 1: if (CH % 2 == 0){ thDeOnFr->Fill(theta); efDeOnFr->Fill(aeta); }
//                else{ thDeOnRe->Fill(theta); efDeOnRe->Fill(aeta); } break; 
//        case 2: if (CH % 2 == 0){ thDeTwFr->Fill(theta); efDeTwFr->Fill(aeta); }
//                else{ thDeTwRe->Fill(theta); efDeTwRe->Fill(aeta); } break;
//        case 3: if (CH % 2 == 0){ thDeThFr->Fill(theta); efDeThFr->Fill(aeta); }
//                else{ thDeThRe->Fill(theta); efDeThRe->Fill(aeta); } break;
//        case 4: if (CH % 2 == 0){ thDeFoFr->Fill(theta); efDeFoFr->Fill(aeta); }
//                else{ thDeFoRe->Fill(theta); efDeFoRe->Fill(aeta); } break;
//      }
//      if (has_lct){
//        switch (ST){
//          case 1: if (CH % 2 == 0){ thNuOnFr->Fill(theta); efNuOnFr->Fill(aeta); }
//                  else{ thNuOnRe->Fill(theta); efNuOnRe->Fill(aeta); } break;
//          case 2: if (CH % 2 == 0){ thNuTwFr->Fill(theta); efNuTwFr->Fill(aeta); }
//                  else{ thNuTwRe->Fill(theta); efNuTwRe->Fill(aeta); } break;
//          case 3: if (CH % 2 == 0){ thNuThFr->Fill(theta); efNuThFr->Fill(aeta); }
//                  else{ thNuThRe->Fill(theta); efNuThRe->Fill(aeta); } break;
//          case 4: if (CH % 2 == 0){ thNuFoFr->Fill(theta); efNuFoFr->Fill(aeta); }
//                  else{ thNuFoRe->Fill(theta); efNuFoRe->Fill(aeta); } break;
//        }
//      }
    }       
  } std::cout << nMi << endl;

//  efNuOnFr->Divide(efDeOnFr);
//  efNuTwFr->Divide(efDeTwFr);
//  efNuThFr->Divide(efDeThFr);
//  efNuFoFr->Divide(efDeFoFr);
//  efNuOnRe->Divide(efDeOnRe);
//  efNuTwRe->Divide(efDeTwRe);
//  efNuThRe->Divide(efDeThRe);
//  efNuFoRe->Divide(efDeFoRe);

//  thNuOnFr->Divide(thDeOnFr);
//  thNuTwFr->Divide(thDeTwFr);
//  thNuThFr->Divide(thDeThFr);
//  thNuFoFr->Divide(thDeFoFr);
//  thNuOnRe->Divide(thDeOnRe);
 // thNuTwRe->Divide(thDeTwRe);
//  thNuThRe->Divide(thDeThRe);
//  thNuFoRe->Divide(thDeFoRe);

//  efNuOnFr->SetMinimum(0.7);
//  efNuTwFr->SetMinimum(0.7);
//  efNuThFr->SetMinimum(0.7);
//  efNuFoFr->SetMinimum(0.7);
//  efNuOnRe->SetMinimum(0.7);
//  efNuTwRe->SetMinimum(0.7);
//  efNuThRe->SetMinimum(0.7);
//  efNuFoRe->SetMinimum(0.7);

//  thNuOnFr->SetMinimum(0.7);
//  thNuTwFr->SetMinimum(0.7);
//  thNuThFr->SetMinimum(0.7);
//  thNuFoFr->SetMinimum(0.7);
//  thNuOnRe->SetMinimum(0.7);
//  thNuTwRe->SetMinimum(0.7);
//  thNuThRe->SetMinimum(0.7);
//  thNuFoRe->SetMinimum(0.7);

  // Superimpose Histograms
//  c1->cd();
//  thNuOnFr->Draw();
//  thNuOnRe->Draw("same");
//  thNuOnFr->TAttLine::SetLineColor(kRed);  
//  thNuOnRe->TAttLine::SetLineColor(kBlue);
//  TLegend *l1 = new TLegend(.9,.7,.98,.78);
//  l1->AddEntry(thNuOnFr,"Front");
//  l1->AddEntry(thNuOnRe,"Rear");
//  l1->Draw();
 
//  c2->cd();
 // thNuTwFr->Draw();
 // thNuTwRe->Draw("same");
 // thNuTwFr->TAttLine::SetLineColor(kRed);
//  thNuTwRe->TAttLine::SetLineColor(kBlue);
//  l1->Draw();

//  c3->cd();
//  thNuThFr->Draw();
//  thNuThRe->Draw("same");
//  thNuThFr->TAttLine::SetLineColor(kRed);
//  thNuThRe->TAttLine::SetLineColor(kBlue);
//  l1->Draw();

//  c4->cd();
//  thNuFoFr->Draw();
//  thNuFoRe->Draw("same");
//  thNuFoFr->TAttLine::SetLineColor(kRed);
//  thNuFoRe->TAttLine::SetLineColor(kBlue);
//  l1->Draw();

//  c5->cd();
//  efNuOnFr->Draw();
//  efNuOnRe->Draw("same");
//  efNuOnFr->TAttLine::SetLineColor(kRed);
//  efNuOnRe->TAttLine::SetLineColor(kBlue);
//  l1->Draw();

//  c6->cd();
//  efNuTwFr->Draw();
//  efNuTwRe->Draw("same");
//  efNuTwFr->TAttLine::SetLineColor(kRed);
//  efNuTwRe->TAttLine::SetLineColor(kBlue);
//  l1->Draw();

//  c7->cd();
// efNuThFr->Draw();
//  efNuThRe->Draw("same");
//  efNuThFr->TAttLine::SetLineColor(kRed);
//  efNuThRe->TAttLine::SetLineColor(kBlue);
//  l1->Draw();

//  c8->cd();
//  efNuFoFr->Draw();
//  efNuFoRe->Draw("same");
//  efNuFoFr->TAttLine::SetLineColor(kRed);
//  efNuFoRe->TAttLine::SetLineColor(kBlue);
//  l1->Draw();

//  for (int l = 0; l < 5; ++l){
//    cans[0]->cd();
//    ocOn[i]->Draw("same");
//    cans[1]->cd();
//    ocTw[i]->Draw("same");
//    cans[2]->cd();
//    ocTh[i]->Draw("same");
//    cans[3]->cd();
//    ocFo[i]->Draw("same");
//  }     

  // Save Histograms to File
//  TFile *outFile = new TFile("analysis/outFile.root","RECREATE");

    plotter.write("analysis/outFile.root");

//  efNuOnFr->Write("efNuOnFr");
//  efNuTwFr->Write("efNuTwFr");
//  efNuThFr->Write("efNuThFr");
//  efNuFoFr->Write("efNuFoFr");
//  efNuOnRe->Write("efNuOnRe");
//  efNuTwRe->Write("efNuTwRe");
//  efNuThRe->Write("efNuThRe");
//  efNuFoRe->Write("efNuFoRe");

//  thNuOnFr->Write("thNuOnFr");
//  thNuTwFr->Write("thNuTwFr");
//  thNuThFr->Write("thNuThFr");
//  thNuFoFr->Write("thNuFoFr");
//  thNuOnRe->Write("thNuOnRe");
//  thNuTwRe->Write("thNuTwRe");
//  thNuThRe->Write("thNuThRe");
 // thNuFoRe->Write("thNuFoRe");

//  nuMi->Write("nuMi");

//  c1->Write();
//  c2->Write();
//  c3->Write();
//  c4->Write();
//  c5->Write();
//  c6->Write();
//  c7->Write();
//  c8->Write();

//  for (int l = 0; l < 4; ++l) cans[i]->Write();

//  outFile->Write();
//  outFile->Close();
} 
