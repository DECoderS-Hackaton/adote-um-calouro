#include "../../../model/data.h"

namespace  adopt_a_freshman {
  namespace service {

    struct Profile : public ::adopt_a_freshman::Profile {
      list<string> notification;    
    };
    
  } /* service */ 
  
} /*  adopt_a_freshman */ 
