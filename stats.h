#include <stdlib.h>

/* TYPE DEFINITIONS */
/*structure for stats*/
struct Stats 
{
 float average; 
 float min;
 float max;
};

typedef void (*alerter_funcptr)();

/* FUNCTION DECLARATION */
struct Stats compute_statistics_s(const float* numberset_a, int setlength_i);
void check_and_alert_v(float maxThreshold_f, alerter_funcptr alerters[], struct Stats computedStats_s);
void emailAlerter_v();
void ledAlerter_v();

/* EXTERN VARIABLES */
extern int emailAlertCallCount_i;
extern int ledAlertCallCount_i;
