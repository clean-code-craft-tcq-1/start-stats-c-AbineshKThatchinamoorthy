
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
#include <stdlib.h>


/*structure for stats*/
struct Stats 
{
 float average; 
 float min;
 float max;
};

/* FUNCTION DECLARATION */
struct Stats compute_statistics_s(const float* numberset_a, int setlength_i);

/* EOF */
