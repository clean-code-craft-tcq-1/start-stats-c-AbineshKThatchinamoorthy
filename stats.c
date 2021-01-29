#include "stats.h"

int emailAlertCallCount_i = 0;
int ledAlertCallCount_i = 0;

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    compute_statistics_s
 */
/*!    \brief       Calculate the average and identify the minimum & maximum numbers
 *                  in the received array
 *
 *     \param       const float* [IN] - pointer for the array
 *     \param       int [IN]          - length of the array
 *     \returns     struct Stats      - Statistics result values
*//*------------------------------------------------------------------------*/
struct Stats compute_statistics_s(const float* numberset_a, int setlength_i) {
    
  float sum_f = 0.0; 
  int count_i;
  struct Stats statistics_s;
  statistics_s.min = numberset_a[0];
  statistics_s.max = numberset_a[0];
    
  for (count_i=0 ;count_i<setlength_i;count_i++)  
  {
      /* calculating sum */
      sum_f +=numberset_a[count_i];
      /*Identify Minimum Number in the array */
      if (statistics_s.min > numberset_a[count_i])
      {
         statistics_s.min = numberset_a[count_i];
      }
      /*Identify Maximum Number in the array */
      if (statistics_s.max < numberset_a[count_i])
      {
          statistics_s.max = numberset_a[count_i];
      }
  }
    
  /*calculating average*/  
  statistics_s.average = (sum_f/setlength_i);
    
  return statistics_s;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    check_and_alert_v
 */
/*!    \brief       Raises alerts when max is greater than threshold
 *
 *
 *     \param       float [IN]          - Maximum allowed threshold value
 *     \param       alerter_funcptr[IN] - Function pointer for alert functions
 *     \param       Stats[IN]           - Statistic result values
 *     \returns     void
*//*------------------------------------------------------------------------*/
void check_and_alert_v(float maxThreshold_f, alerter_funcptr alerters[], struct Stats computedStats_s) {
    int count_i;
    
    if(computedStats_s.max > maxThreshold_f)
    {
        for (count_i=0 ;count_i<2;count_i++)  
            alerters[count_i]();
    }
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    emailAlerter_v
 */
/*!    \brief       Email Alert when max is greater than threshold
 *
 *
 *     \param       void
 *     \returns     void
*//*------------------------------------------------------------------------*/
void emailAlerter_v() {
    /* Email trigger has to be done */
    ++emailAlertCallCount_i;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    ledAlerter_v
 */
/*!    \brief       LED Alert when max is greater than threshold
 *
 *
 *     \param       void
 *     \returns     void
*//*------------------------------------------------------------------------*/
void ledAlerter_v() {
    /* LED trigger has to be done */
    ++ledAlertCallCount_i;
}
