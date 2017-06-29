int WireGroup(int ser, int stat, int ring, int sY, std::vector<int> *sId, std::vector<std::vector<int> > *sWG){
 double mY = 0, mWG = 0, guess = 0;
 double sYd = (double) sY;
 if (stat == 1){
    if (ring == 1) {guess = (sYd + 77) / 153 * 48; mY = 75; mWG = 48;}
    if (ring == 2) {guess = (sYd + 89) / 177 * 64; mY = 90; mWG = 64;}
    if (ring == 3) {guess = (sYd + 85) / 169 * 32; mY = 85; mWG = 32;}
  } else if (stat == 2){
    if (ring == 1) {guess = (sYd + 97) / 193 * 112; mY = 95; mWG = 112;}
    if (ring == 2) {guess = (sYd + 161) / 321 * 64; mY = 160; mWG = 64;}
  } else if (stat ==  3){
    if (ring == 1) {guess = (sYd + 88) / 175 * 96; mY = 85; mWG = 96;}
    if (ring == 2) {guess = (sYd + 161) / 321 * 64; mY = 160; mWG = 64;}
  } else if (stat == 4){
    if (ring == 1) {guess = (sYd + 77) / 153 * 96; mY = 75; mWG = 96;}
    if (ring == 2) {guess = (sYd + 161) / 321 * 64; mY = 160; mWG = 64;}
  } 
  int best = 1000;
  for (int i = 0; i < sId->size(); i++){
    if (sId->at(i) != ser) continue;
    for (int j = 0; j < sWG->at(i).size(); j++){
      if (fabs((double) sWG->at(i).at(j) - guess) < fabs((double) best - guess)) best = sWG->at(i).at(j);
    }
  }
  return best;
}
