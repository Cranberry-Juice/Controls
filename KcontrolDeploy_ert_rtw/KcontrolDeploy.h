/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: KcontrolDeploy.h
 *
 * Code generated for Simulink model 'KcontrolDeploy'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Apr 20 17:31:19 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_KcontrolDeploy_h_
#define RTW_HEADER_KcontrolDeploy_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef KcontrolDeploy_COMMON_INCLUDES_
#define KcontrolDeploy_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_I2C.h"
#include "io_wrappers.h"
#include "MW_ServoWriteRead.h"
#endif                                 /* KcontrolDeploy_COMMON_INCLUDES_ */

#include "MW_target_hardware_resources.h"

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define KcontrolDeploy_M               (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_d_arduinodriver_ArduinoDigitalI
#define typedef_d_arduinodriver_ArduinoDigitalI

typedef struct tag_04b6x6tDldj9IrIH2gmbjG d_arduinodriver_ArduinoDigitalI;

#endif                             /* typedef_d_arduinodriver_ArduinoDigitalI */

#ifndef struct_tag_HaWnjzA2iiR2NMKNB2VNI
#define struct_tag_HaWnjzA2iiR2NMKNB2VNI

struct tag_HaWnjzA2iiR2NMKNB2VNI
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_arduinodriver_ArduinoDigitalI DigitalIODriverObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_HaWnjzA2iiR2NMKNB2VNI */

#ifndef typedef_codertarget_arduinobase_blocks_
#define typedef_codertarget_arduinobase_blocks_

typedef struct tag_HaWnjzA2iiR2NMKNB2VNI codertarget_arduinobase_blocks_;

#endif                             /* typedef_codertarget_arduinobase_blocks_ */

/* Custom Type definition for MATLABSystem: '<Root>/BNO055 IMU Sensor' */
#include "MW_SVD.h"
#ifndef struct_tag_jbIFaTBEZATkkvPSmnoPa
#define struct_tag_jbIFaTBEZATkkvPSmnoPa

struct tag_jbIFaTBEZATkkvPSmnoPa
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_jbIFaTBEZATkkvPSmnoPa */

#ifndef typedef_c_arduinodriver_ArduinoI2C
#define typedef_c_arduinodriver_ArduinoI2C

typedef struct tag_jbIFaTBEZATkkvPSmnoPa c_arduinodriver_ArduinoI2C;

#endif                                 /* typedef_c_arduinodriver_ArduinoI2C */

#ifndef struct_tag_9AnIRoZpmWNSR76ytV7oUG
#define struct_tag_9AnIRoZpmWNSR76ytV7oUG

struct tag_9AnIRoZpmWNSR76ytV7oUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_arduinodriver_ArduinoI2C I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_9AnIRoZpmWNSR76ytV7oUG */

#ifndef typedef_i_codertarget_arduinobase_inter
#define typedef_i_codertarget_arduinobase_inter

typedef struct tag_9AnIRoZpmWNSR76ytV7oUG i_codertarget_arduinobase_inter;

#endif                             /* typedef_i_codertarget_arduinobase_inter */

#ifndef struct_tag_7fis7mPSiuvb41xMrWYvrC
#define struct_tag_7fis7mPSiuvb41xMrWYvrC

struct tag_7fis7mPSiuvb41xMrWYvrC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  boolean_T isBNOcorrect;
  i_codertarget_arduinobase_inter i2cObj;
};

#endif                                 /* struct_tag_7fis7mPSiuvb41xMrWYvrC */

#ifndef typedef_codertarget_arduinobase_interna
#define typedef_codertarget_arduinobase_interna

typedef struct tag_7fis7mPSiuvb41xMrWYvrC codertarget_arduinobase_interna;

#endif                             /* typedef_codertarget_arduinobase_interna */

#ifndef struct_tag_dbvacMp9IP0OwUX1Fvoy4E
#define struct_tag_dbvacMp9IP0OwUX1Fvoy4E

struct tag_dbvacMp9IP0OwUX1Fvoy4E
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_dbvacMp9IP0OwUX1Fvoy4E */

#ifndef typedef_codertarget_arduinobase_inter_o
#define typedef_codertarget_arduinobase_inter_o

typedef struct tag_dbvacMp9IP0OwUX1Fvoy4E codertarget_arduinobase_inter_o;

#endif                             /* typedef_codertarget_arduinobase_inter_o */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_interna obj; /* '<Root>/BNO055 IMU Sensor' */
  codertarget_arduinobase_blocks_ obj_j;/* '<Root>/YCmd' */
  codertarget_arduinobase_blocks_ obj_f;/* '<Root>/XCmd' */
  codertarget_arduinobase_blocks_ obj_e;/* '<Root>/AltCmd' */
  real_T BNO055IMUSensor_o3[3];        /* '<Root>/BNO055 IMU Sensor' */
  real_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S3>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S3>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator[3];    /* '<S3>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S38>/Integrator' */
  real_T Filter_DSTATE;                /* '<S33>/Filter' */
  real_T HeightErr;                    /* '<S3>/Sum' */
  real_T Gain2;                        /* '<S2>/Gain2' */
  real_T Gain2_m;
  real_T Gain3;
  real_T rtb_BNO055IMUSensor_o1_idx_2;
  real_T d;
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void KcontrolDeploy_initialize(void);
extern void KcontrolDeploy_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/mass_burn_rate' : Eliminated nontunable gain of 1
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'KcontrolDeploy'
 * '<S1>'   : 'KcontrolDeploy/Controller'
 * '<S2>'   : 'KcontrolDeploy/Controller/Controll Allocator'
 * '<S3>'   : 'KcontrolDeploy/Controller/Error'
 * '<S4>'   : 'KcontrolDeploy/Controller/Height Controller'
 * '<S5>'   : 'KcontrolDeploy/Controller/Mass_Fuel'
 * '<S6>'   : 'KcontrolDeploy/Controller/Height Controller/PID Controller'
 * '<S7>'   : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Anti-windup'
 * '<S8>'   : 'KcontrolDeploy/Controller/Height Controller/PID Controller/D Gain'
 * '<S9>'   : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Filter'
 * '<S10>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Filter ICs'
 * '<S11>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/I Gain'
 * '<S12>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Ideal P Gain'
 * '<S13>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S14>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Integrator'
 * '<S15>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Integrator ICs'
 * '<S16>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/N Copy'
 * '<S17>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/N Gain'
 * '<S18>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/P Copy'
 * '<S19>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Parallel P Gain'
 * '<S20>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Reset Signal'
 * '<S21>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Saturation'
 * '<S22>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Saturation Fdbk'
 * '<S23>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Sum'
 * '<S24>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Sum Fdbk'
 * '<S25>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Tracking Mode'
 * '<S26>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Tracking Mode Sum'
 * '<S27>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Tsamp - Integral'
 * '<S28>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Tsamp - Ngain'
 * '<S29>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/postSat Signal'
 * '<S30>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/preSat Signal'
 * '<S31>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Anti-windup/Passthrough'
 * '<S32>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/D Gain/Internal Parameters'
 * '<S33>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S34>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/I Gain/Internal Parameters'
 * '<S36>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Integrator/Discrete'
 * '<S39>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S40>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/N Copy/Disabled'
 * '<S41>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/N Gain/Internal Parameters'
 * '<S42>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/P Copy/Disabled'
 * '<S43>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Reset Signal/Disabled'
 * '<S45>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Saturation/Enabled'
 * '<S46>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S47>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Sum/Sum_PID'
 * '<S48>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S49>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Tracking Mode/Disabled'
 * '<S50>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Tsamp - Integral/Passthrough'
 * '<S52>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'KcontrolDeploy/Controller/Height Controller/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_KcontrolDeploy_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
