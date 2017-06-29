class ReverseChamberSerial{
  public:
    int set_id(int cid) int id = cid;
    int ec,st,ri,ch;
    if (id > 301){
      ec = 2;
      id -= 300;
    } else ec = 1;
    if (id < 109) st = 1;
    else if (id < 163) st = 2;
    else if (id < 217) st = 3;
    else st = 4;
    if (st = 1){
      if (id > 72){
        ri = 3; ch = id - 72;
      } else if (if > 36){
        ri = 2; ch = id - 36;
      } else {
        ri = 1; ch = id;
      }
    } else {
      id = id - 108 - 54*(st - 2);
      if (id > 18){
        ri = 2; ch = id - 18;
      } else {
        ri = 1; ch = id;
      }
    }
};
