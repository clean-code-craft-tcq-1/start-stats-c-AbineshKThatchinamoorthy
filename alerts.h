#include "stats.h"

typedef void (*alerter_funcptr)();

/* FUNCTION DECLARATION */
void check_and_alert_v(float maxThreshold_f, alerter_funcptr alerters[], struct Stats computedStats_s);
void emailAlerter_v();
void ledAlerter_v();

/* EXTERN VARIABLES */
extern int emailAlertCallCount_i;
extern int ledAlertCallCount_i;
