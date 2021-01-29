/******************************************************************************
*****     (C) COPYRIGHT Robert Bosch GmbH CM-CI2 - All Rights Reserved    *****
******************************************************************************/
/*!                                                                            
***     \file        stats.c                                                           
***     \author                                                                
\nt                  ABINESH KANJI KOVIL THATCHINAMOORTHY (RBEI/ECK1)                                                  
***                  Created on 1/28/2021                                                                                    
***                                                                            
\par    File_description                                                       
***                  Implementation for computation of Statistics data
***                                                                                                                                                                     
*\n*/                                                                          
/*****************************************************************************/

/* INCLUSIONS */
#include "stats.h"

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
