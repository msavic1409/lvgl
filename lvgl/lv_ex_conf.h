/**
 * @file lv_ex_conf.h
 * 
 */


#ifndef LV_EX_CONF_H
#define LV_EX_CONF_H

/*******************
 * GENERAL SETTING
 *******************/
#define LV_EX_PRINTF    0       /*Enable printf-ing data*/

/*******************
 *   TEST USAGE    
 *******************/
#define USE_LV_TESTS        0

/*******************
 * TUTORIAL USAGE    
 *******************/
#define USE_LV_TUTORIALS   0


/*********************
 * APPLICATION USAGE    
 *********************/

/* Test the graphical performance of your MCU
 * with different settings*/
#define USE_LV_BENCHMARK   1

/*A demo application with Keyboard, Text area, List and Chart
 * placed on Tab view */
#define USE_LV_DEMO        1
#if USE_LV_DEMO
#define LV_DEMO_WALLPAPER  0    /*Create a wallpaper too*/
#define LV_DEMO_SLIDE_SHOW 0	/*Automatically switch between tabs*/
#endif

/*MCU and memory usage monitoring*/
#define USE_LV_SYSMON      1

/*A terminal to display received characters*/
#define USE_LV_TERMINAL    0

/*Touch pad calibration with 4 points*/
#define USE_LV_TPCAL       0

#endif /*LV_EX_CONF_H*/