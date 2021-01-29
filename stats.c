#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    
  float sum_f = 0.0; 
  int count_i;
  struct Stats statistics_s;
  statistics_s.min = numberset[0];
  statistics_s.max = numberset[0];
    
  for (count_i=0 ;count_i<setlength;count_i++)  
  {
      /* calculating sum */
      sum_f +=numberset[count_i];
      /*Identify Minimum Number in the array */
      if (statistics_s.min > numberset[count_i])
      {
         statistics_s.min = numberset[count_i];
      }
      /*Identify Maximum Number in the array */
      if (statistics_s.max < numberset[count_i])
      {
          statistics_s.max = numberset[count_i];
      }
  }
    
  /*calculating average*/  
  statistics_s.average = (sum_f/setlength);
    
  return statistics_s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats computedStats)
{
    int count_i;
    
    if(computedStats.max > maxThreshold)
    {
        for (count_i=0 ;count_i<2;count_i++)  
            alerters[count_i]();
    }
}

void emailAlerter()
{
    ++emailAlertCallCount;
}

void ledAlerter()
{
    ++ledAlertCallCount;
}
