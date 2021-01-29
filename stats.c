#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    
  float sum_f = 0.0; 
  int count_i;
  struct Stats statistics_s;
  statistics_s.min = numberset[0];
  statistics_s.max = numberset[0];
    
  /*calculating sum*/
  for (count=0 ;count<setlength;count++)  
  {
      sum +=numberset[count];
      if (statistics_s.min > numberset[count])
      {
         statistics_s.min = numberset[count];
      }
      if (statistics_s.max < numberset[count])
      {
          statistics_s.max = numberset[count];
      }
  }
    
  /*calculating avg*/  
  statistics_s.average = (sum_f/setlength);
    
    return statistics_s;
}


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
