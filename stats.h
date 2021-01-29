#include <stdlib.h>

/*structure for stats*/
struct Stats 
{
 float average; 
 float min;
 float max;
};

struct Stats compute_statistics_s(const float* numberset, int setlength);
typedef void (*alerter_funcptr)();
void check_and_alert_v(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
void emailAlerter_v();
void ledAlerter_v();

extern int emailAlertCallCount;
extern int ledAlertCallCount;
