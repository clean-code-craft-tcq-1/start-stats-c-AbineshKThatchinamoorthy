#include <stdlib.h>

/*structure for stats*/
struct Stats 
{
 float average; 
 float min;
 float max;
};

struct Stats compute_statistics(const float* numberset, int setlength);
typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
void emailAlerter();
void ledAlerter();

extern int emailAlertCallCount;
extern int ledAlertCallCount;
