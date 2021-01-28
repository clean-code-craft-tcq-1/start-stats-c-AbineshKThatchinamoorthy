typedef struct
{
	int average = 0;
	int min = 0;
	int max = 0;
}Stats;

Stats compute_statistics(float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;
