int ChamberSerial (int ec, int st, int ri, int ch){
  int kSerial = ch;
  switch (st){
    case 1: switch(ri){
      case 2: kSerial += 36; break;
      case 3: kSerial += 72; break;
      default: break;
    } break;
    case 2: if (ri == 1) kSerial += 108; else kSerial += 126; break;
    case 3: if (ri == 1) kSerial += 162; else kSerial += 180; break;
    case 4: if (ri == 1) kSerial += 216; else kSerial += 234; break;
  } if (ec == 2) kSerial += 300;
  return kSerial;
}
