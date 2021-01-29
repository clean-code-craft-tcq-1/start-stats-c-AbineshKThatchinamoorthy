#include <stdlib.h>

/* TYPE DEFINITIONS */
/*structure for stats*/
struct Stats 
{
 float average; 
 float min;
 float max;
};

/* FUNCTION DECLARATION */
struct Stats compute_statistics_s(const float* numberset_a, int setlength_i);
