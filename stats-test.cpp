  
/******************************************************************************
*****     (C) COPYRIGHT Robert Bosch GmbH CM-CI2 - All Rights Reserved    *****
******************************************************************************/
/*!                                                                            
***     \file        stats-test.cpp                                                            
***     \author                                                                
\nt                  ABINESH KANJI KOVIL THATCHINAMOORTHY (RBEI/ECK1)                                                  
***                  Created on 1/29/2021                                                                                    
***                                                                            
\par    File_description                                                       
***                  CPP file consisting of Unit Test cases for the Statistics
***                  and alert functionalities
***                                                                                                                                                                     
*\n*/                                                                          
/*****************************************************************************/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

/* INCLUSIONS */
#include "catch.hpp"
#include "alerts.h"

#include <stdlib.h>
#include <math.h>

TEST_CASE("reports average, minimum and maximum") {
    float numberset_a[] = {1.5, 8.9, 3.2, 4.5};
    int setlength_i = sizeof(numberset_a) / sizeof(numberset_a[0]);
    struct Stats computedStats_s = compute_statistics_s(numberset_a, setlength_i);
    float epsilon = 0.001;
    REQUIRE(abs(computedStats_s.average - 4.525) < epsilon);
    REQUIRE(abs(computedStats_s.max - 8.9) < epsilon);
    REQUIRE(abs(computedStats_s.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    float numberset_a[] = {0.0, 0.0, 0.0, 0.0};
    struct Stats computedStats_s = compute_statistics_s(numberset_a, 0);
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    //Design the REQUIRE statement here.
    //Use https://stackoverflow.com/questions/1923837/how-to-use-nan-and-inf-in-c
    REQUIRE(1 == isnan(computedStats_s.average));
}

TEST_CASE("raises alerts when max is greater than threshold") {
    // create additional .c and .h files
    // containing the emailAlerter, ledAlerter functions
    alerter_funcptr alerters[] = {emailAlerter_v, ledAlerter_v};

    float numberset_a[] = {99.8, 34.2, 4.5};
    int setlength_i = sizeof(numberset_a) / sizeof(numberset_a[0]);
    Stats computedStats_s = compute_statistics_s(numberset_a, setlength_i );

    const float maxThreshold_f = 10.2;
    check_and_alert_v(maxThreshold_f, alerters, computedStats_s);

    // need a way to check if both emailAlerter, ledAlerter were called
    // you can define call-counters along with the functions, as shown below
    REQUIRE(emailAlertCallCount_i == 1);
    REQUIRE(ledAlertCallCount_i == 1);
}
