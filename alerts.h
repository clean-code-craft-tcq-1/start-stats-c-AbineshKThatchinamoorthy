/******************************************************************************
*****     (C) COPYRIGHT Robert Bosch GmbH CM-CI2 - All Rights Reserved    *****
******************************************************************************/
/*!                                                                            
***     \file        alerts.c                                                              
***     \author                                                                
\nt                  ABINESH KANJI KOVIL THATCHINAMOORTHY (RBEI/ECK1)                                                  
***                  Created on 1/29/2021                                                                                    
***                                                                            
\par    File_description                                                       
***                  To handle the alerts during unexpected situations  
***                                                                                                     
***                                                                            
*\n*/                                                                          
/*****************************************************************************/

/* INCLUSIONS */
#include "stats.h"

typedef void (*alerter_funcptr)();

/* FUNCTION DECLARATION */
void check_and_alert_v(float maxThreshold_f, alerter_funcptr alerters[], struct Stats computedStats_s);
void emailAlerter_v();
void ledAlerter_v();

/* EXTERN VARIABLES */
extern int emailAlertCallCount_i;
extern int ledAlertCallCount_i;
