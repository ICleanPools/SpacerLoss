#include "vector"
#ifdef __CINT__ 
#pragma link C++ nestedclasses;
#pragma link C++ nestedtypedefs;
#pragma link C++ class std::vector<std::vector<std::vector<int> > >+;
#pragma link C++ class std::vector<std::vector<std::vector<int> > >::*;
#ifdef G__VECTOR_HAS_CLASS_ITERATOR
#pragma link C++ operators std::vector<std::vector<std::vector<int> > >::iterator;
#pragma link C++ operators std::vector<std::vector<std::vector<int> > >::const_iterator;
#pragma link C++ operators std::vector<std::vector<std::vector<int> > >::reverse_iterator;
#endif
#endif
