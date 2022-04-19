//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'KcontrolDeploy'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.6 (R2021b) 14-May-2021
// C/C++ source code generated on : Sun Apr 17 23:00:49 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "KcontrolDeploy.h"
#include "rtwtypes.h"

static KcontrolDeployModelClass rtObj; // Instance of model class
volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  // Check for overrun. Protect OverrunFlag against preemption
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  rtObj.step();

  // Get model outputs here
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.02;
  float systemClock = 0;

  // Initialize variables
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(rtObj.getRTM(), 0);
  initialize();
  cli();
  configureArduinoAVRTimer();
  runModel =
    rtmGetErrorStatus(rtObj.getRTM()) == (nullptr);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(rtObj.getRTM()) == (nullptr));
    runModel = !(stopRequested);
    MW_Arduino_Loop();
  }

  cli();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
