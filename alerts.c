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
#include "alerts.h"

/* Declaration of Global variables */
int emailAlertCallCount_i = 0;
int ledAlertCallCount_i = 0;

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
