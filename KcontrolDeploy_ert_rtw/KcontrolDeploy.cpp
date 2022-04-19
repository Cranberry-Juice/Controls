//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: KcontrolDeploy.cpp
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
#define NumBitsPerChar                 8U

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);

//===========*
//  Constants *
// ===========
#define RT_PI                          3.14159265358979323846
#define RT_PIF                         3.1415927F
#define RT_LN_10                       2.30258509299404568402
#define RT_LN_10F                      2.3025851F
#define RT_LOG10E                      0.43429448190325182765
#define RT_LOG10EF                     0.43429449F
#define RT_E                           2.7182818284590452354
#define RT_EF                          2.7182817F

//
//  UNUSED_PARAMETER(x)
//    Used to specify that a function parameter (argument) is required but not
//    accessed by the function body.

#ifndef UNUSED_PARAMETER
#if defined(__LCC__)
#define UNUSED_PARAMETER(x)                                      // do nothing
#else

//
//  This is the semi-ANSI standard way of indicating that an
//  unused function parameter is required.

#define UNUSED_PARAMETER(x)            (void) (x)
#endif
#endif

extern "C" {
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}
  extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetNaN(void)
  {
    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    real_T nan{ 0.0 };

    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetNaNF(void)
  {
    IEEESingle nanF{ { 0.0F } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C" {
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  static void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    boolean_T result{ (boolean_T) 0 };

    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    if (bitsPerReal == 32U) {
      result = rtIsNaNF((real32_T)value);
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.fltVal = value;
      result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                           0x7FF00000 &&
                           ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                            (tmpVal.bitVal.words.wordL != 0) ));
    }

    return result;
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}
  extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetInf(void)
  {
    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    real_T inf{ 0.0 };

    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal{ sizeof(real_T) * (NumBitsPerChar) };

    real_T minf{ 0.0 };

    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int16_T u0_0;
    int16_T u1_0;
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

void KcontrolDeployModelClass::SystemCore_setup(codertarget_arduinobase_interna *
  obj)
{
  uint32_T i2cname;
  i_codertarget_arduinobase_inter *obj_0;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T CastedData;
  uint8_T SwappedDataBytes_0;
  uint8_T x;
  obj->isSetupComplete = false;
  obj->isInitialized = 1L;
  obj_0 = &obj->i2cObj;
  i2cname = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
  obj->i2cObj.BusSpeed = 100000UL;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  MW_delay_in_milliseconds(600UL);
  x = 0U;
  std::memcpy((void *)&SwappedDataBytes_0, (void *)&x, (uint16_T)((size_t)1 *
    sizeof(uint8_T)));
  SwappedDataBytes_0 = MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE,
    40UL, &SwappedDataBytes_0, 1UL, true, false);
  if (0 == SwappedDataBytes_0) {
    MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                      &SwappedDataBytes_0, 1UL, false, true);
    std::memcpy((void *)&CastedData, (void *)&SwappedDataBytes_0, (uint16_T)
                ((size_t)1 * sizeof(uint8_T)));
  } else {
    CastedData = 0U;
  }

  obj->isBNOcorrect = (CastedData == 160);
  if (obj->isBNOcorrect) {
    CastedData = 0U;
    std::memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
                ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 61U;
    std::memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
                (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    MW_delay_in_milliseconds(25UL);
    CastedData = 32U;
    std::memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
                ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 63U;
    std::memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
                (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    std::memcpy((void *)&SwappedDataBytes_0, (void *)&x, (uint16_T)((size_t)1 *
      sizeof(uint8_T)));
    SwappedDataBytes_0 = MW_I2C_MasterWrite
      (obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL, &SwappedDataBytes_0, 1UL,
       true, false);
    if (0 == SwappedDataBytes_0) {
      MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                        &SwappedDataBytes_0, 1UL, false, true);
      std::memcpy((void *)&CastedData, (void *)&SwappedDataBytes_0, (uint16_T)
                  ((size_t)1 * sizeof(uint8_T)));
    } else {
      CastedData = 0U;
    }

    obj->isBNOcorrect = (CastedData == 160);
    while (!obj->isBNOcorrect) {
      MW_delay_in_milliseconds(10UL);
      std::memcpy((void *)&SwappedDataBytes_0, (void *)&x, (uint16_T)((size_t)1 *
        sizeof(uint8_T)));
      SwappedDataBytes_0 = MW_I2C_MasterWrite
        (obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL, &SwappedDataBytes_0, 1UL,
         true, false);
      if (0 == SwappedDataBytes_0) {
        MW_I2C_MasterRead(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                          &SwappedDataBytes_0, 1UL, false, true);
        std::memcpy((void *)&CastedData, (void *)&SwappedDataBytes_0, (uint16_T)
                    ((size_t)1 * sizeof(uint8_T)));
      } else {
        CastedData = 0U;
      }

      obj->isBNOcorrect = (CastedData == 160);
    }

    MW_delay_in_milliseconds(50UL);
    CastedData = 0U;
    std::memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
                ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 62U;
    std::memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
                (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    std::memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
                ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 63U;
    std::memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
                (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    std::memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
                ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 7U;
    std::memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
                (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    MW_delay_in_milliseconds(10UL);
    CastedData = 128U;
    std::memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
                ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 59U;
    std::memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
                (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    CastedData = 12U;
    std::memcpy((void *)&b_SwappedDataBytes[1], (void *)&CastedData, (uint16_T)
                ((size_t)1 * sizeof(uint8_T)));
    b_SwappedDataBytes[0] = 61U;
    std::memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
                (uint16_T)((size_t)2 * sizeof(uint8_T)));
    MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 40UL,
                       &SwappedDataBytes[0], 2UL, false, false);
    MW_delay_in_milliseconds(25UL);
  }

  obj->isSetupComplete = true;
}

// Model step function
void KcontrolDeployModelClass::step()
{
  // local block i/o variables
  real_T rtb_FilterCoefficient;
  real_T rtb_IntegralGain;
  i_codertarget_arduinobase_inter *obj;
  int16_T b_RegisterValue[3];
  int16_T b_RegisterValue_0[3];
  int16_T b_RegisterValue_1[3];
  uint8_T output_raw[6];
  uint8_T SwappedDataBytes;
  uint8_T status;
  boolean_T rtb_AltCmd_i_0;
  boolean_T rtb_XCmd_h_0;
  boolean_T rtb_YCmd_a_0;

  // MATLABSystem: '<Root>/BNO055 IMU Sensor'
  if (rtDW.obj.SampleTime != 0.02) {
    rtDW.obj.SampleTime = 0.02;
  }

  obj = &rtDW.obj.i2cObj;
  status = 20U;
  std::memcpy((void *)&SwappedDataBytes, (void *)&status, (uint16_T)((size_t)1 *
    sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL,
    &SwappedDataBytes, 1UL, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL, &output_raw[0], 6UL,
                      false, true);
    std::memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint16_T)
                ((size_t)3 * sizeof(int16_T)));
  } else {
    b_RegisterValue[0] = 0;
    b_RegisterValue[1] = 0;
  }

  obj = &rtDW.obj.i2cObj;
  status = 26U;
  std::memcpy((void *)&SwappedDataBytes, (void *)&status, (uint16_T)((size_t)1 *
    sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL,
    &SwappedDataBytes, 1UL, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL, &output_raw[0], 6UL,
                      false, true);
    std::memcpy((void *)&b_RegisterValue_0[0], (void *)&output_raw[0], (uint16_T)
                ((size_t)3 * sizeof(int16_T)));
  } else {
    b_RegisterValue_0[0] = 0;
    b_RegisterValue_0[1] = 0;
  }

  obj = &rtDW.obj.i2cObj;
  status = 40U;
  std::memcpy((void *)&SwappedDataBytes, (void *)&status, (uint16_T)((size_t)1 *
    sizeof(uint8_T)));
  status = MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL,
    &SwappedDataBytes, 1UL, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 40UL, &output_raw[0], 6UL,
                      false, true);
    std::memcpy((void *)&b_RegisterValue_1[0], (void *)&output_raw[0], (uint16_T)
                ((size_t)3 * sizeof(int16_T)));
  } else {
    b_RegisterValue_1[0] = 0;
    b_RegisterValue_1[1] = 0;
    b_RegisterValue_1[2] = 0;
  }

  // MATLABSystem: '<Root>/BNO055 IMU Sensor'
  rtDW.BNO055IMUSensor_o3[0] = static_cast<real_T>(b_RegisterValue_1[0]) / 100.0;
  rtDW.BNO055IMUSensor_o3[1] = static_cast<real_T>(b_RegisterValue_1[1]) / 100.0;
  rtDW.BNO055IMUSensor_o3[2] = static_cast<real_T>(b_RegisterValue_1[2]) / 100.0;

  // MATLABSystem: '<Root>/AltCmd'
  if (rtDW.obj_e.SampleTime != 0.02) {
    rtDW.obj_e.SampleTime = 0.02;
  }

  rtb_AltCmd_i_0 = readDigitalPin(3);

  // MATLABSystem: '<Root>/XCmd'
  if (rtDW.obj_f.SampleTime != 0.02) {
    rtDW.obj_f.SampleTime = 0.02;
  }

  rtb_XCmd_h_0 = readDigitalPin(4);

  // MATLABSystem: '<Root>/YCmd'
  if (rtDW.obj_j.SampleTime != 0.02) {
    rtDW.obj_j.SampleTime = 0.02;
  }

  rtb_YCmd_a_0 = readDigitalPin(5);

  // Outputs for Atomic SubSystem: '<Root>/Controller'
  // DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
  rtDW.DiscreteTimeIntegrator[0] = rtDW.DiscreteTimeIntegrator_DSTATE[0];
  rtDW.DiscreteTimeIntegrator[1] = rtDW.DiscreteTimeIntegrator_DSTATE[1];
  rtDW.DiscreteTimeIntegrator[2] = rtDW.DiscreteTimeIntegrator_DSTATE[2];

  // Product: '<S1>/MatrixMultiply1' incorporates:
  //   Constant: '<S1>/X State Gain Controller'
  //   DataTypeConversion: '<Root>/Data Type Conversion5'
  //   DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
  //   MATLABSystem: '<Root>/BNO055 IMU Sensor'
  //   MATLABSystem: '<Root>/XCmd'
  //   Sum: '<S3>/Sum1'

  rtDW.d = (((0.0 - static_cast<real_T>(b_RegisterValue_0[1]) / 16.0) *
             -737.36799698752691 + (static_cast<real_T>(rtb_XCmd_h_0) -
              rtDW.DiscreteTimeIntegrator1_DSTATE[0]) * 44.721359549989636) +
            (0.0 - rtDW.DiscreteTimeIntegrator[0]) * 60.186495759237317) + (0.0
    - static_cast<real_T>(b_RegisterValue[1]) / 16.0) * -50.700708798726637;

  // Product: '<S1>/MatrixMultiply2' incorporates:
  //   Constant: '<S1>/Y State Gain Controller'
  //   DataTypeConversion: '<Root>/Data Type Conversion6'
  //   DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
  //   MATLABSystem: '<Root>/BNO055 IMU Sensor'
  //   MATLABSystem: '<Root>/YCmd'
  //   Sum: '<S3>/Sum2'

  rtDW.Gain2_m = (((0.0 - static_cast<real_T>(b_RegisterValue_0[0]) / 16.0) *
                   737.36799698753578 + (static_cast<real_T>(rtb_YCmd_a_0) -
    rtDW.DiscreteTimeIntegrator1_DSTATE[1]) * 44.721359549996443) + (0.0 -
    rtDW.DiscreteTimeIntegrator[1]) * 60.186495759245886) + (0.0 -
    static_cast<real_T>(b_RegisterValue[0]) / 16.0) * 50.700708798730368;

  // Sum: '<S3>/Sum' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion4'
  //   DiscreteIntegrator: '<S3>/Discrete-Time Integrator1'
  //   MATLABSystem: '<Root>/AltCmd'

  rtDW.HeightErr = static_cast<real_T>(rtb_AltCmd_i_0) -
    rtDW.DiscreteTimeIntegrator1_DSTATE[2];

  // Gain: '<S41>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S33>/Filter'
  //   Gain: '<S32>/Derivative Gain'
  //   Sum: '<S33>/SumD'

  rtb_FilterCoefficient = (13.3428538970744 * rtDW.HeightErr -
    rtDW.Filter_DSTATE) * 45.4968011971303;

  // Sum: '<S47>/Sum' incorporates:
  //   DiscreteIntegrator: '<S38>/Integrator'
  //   Gain: '<S43>/Proportional Gain'

  rtDW.rtb_BNO055IMUSensor_o1_idx_2 = (0.203941393902336 * rtDW.HeightErr +
    rtDW.Integrator_DSTATE) + rtb_FilterCoefficient;

  // Saturate: '<S45>/Saturation'
  if (rtDW.rtb_BNO055IMUSensor_o1_idx_2 > 500.0) {
    rtDW.rtb_BNO055IMUSensor_o1_idx_2 = 500.0;
  } else if (rtDW.rtb_BNO055IMUSensor_o1_idx_2 < -500.0) {
    rtDW.rtb_BNO055IMUSensor_o1_idx_2 = -500.0;
  }

  // End of Saturate: '<S45>/Saturation'

  // SignalConversion generated from: '<S2>/Dot Product' incorporates:
  //   Clock: '<S5>/Clock'
  //   Constant: '<S1>/Constant'
  //   Constant: '<S5>/mass_intial_fuel'
  //   Gain: '<S1>/Gain'
  //   Gain: '<S1>/Gain1'
  //   Sum: '<S1>/Sum3'
  //   Sum: '<S4>/Sum'
  //   Sum: '<S5>/Sum'

  rtDW.rtb_BNO055IMUSensor_o1_idx_2 = -(((10.0 - (&rtM)->Timing.t[0]) +
    33.5417099062419) * 9.81 + rtDW.rtb_BNO055IMUSensor_o1_idx_2);

  // Sqrt: '<S2>/Square Root' incorporates:
  //   DotProduct: '<S2>/Dot Product'
  //   Gain: '<S1>/Gain2'
  //   Gain: '<S1>/Gain3'
  //   Product: '<S1>/MatrixMultiply1'
  //   Product: '<S1>/MatrixMultiply2'

  rtDW.Gain2 = std::sqrt((-rtDW.d * -rtDW.d + -rtDW.Gain2_m * -rtDW.Gain2_m) +
    rtDW.rtb_BNO055IMUSensor_o1_idx_2 * rtDW.rtb_BNO055IMUSensor_o1_idx_2);

  // Gain: '<S2>/Gain'
  rtDW.rtb_BNO055IMUSensor_o1_idx_2 = 0.18 * rtDW.Gain2;

  // Gain: '<S2>/Gain2'
  rtDW.Gain2 *= 0.5;

  // Sum: '<S2>/Sum2' incorporates:
  //   Constant: '<S2>/Constant'
  //   Gain: '<S1>/Gain3'
  //   Gain: '<S2>/Gain4'
  //   Product: '<S1>/MatrixMultiply1'
  //   Trigonometry: '<S2>/Atan1'

  rtDW.Gain3 = 90.0 - 57.295779513082323 * rt_atan2d_snf(rtDW.Gain2, -rtDW.d);

  // Sum: '<S2>/Sum' incorporates:
  //   Constant: '<S2>/Constant'
  //   Gain: '<S1>/Gain2'
  //   Gain: '<S2>/Gain5'
  //   Product: '<S1>/MatrixMultiply2'
  //   Trigonometry: '<S2>/Atan2'

  rtDW.Gain2_m = 57.295779513082323 * rt_atan2d_snf(rtDW.Gain2, -rtDW.Gain2_m) -
    90.0;

  // Gain: '<S35>/Integral Gain'
  rtb_IntegralGain = 0.000548507911387826 * rtDW.HeightErr;

  // MATLABSystem: '<Root>/Servo1' incorporates:
  //   Gain: '<S2>/Gain3'

  if (-rtDW.Gain2_m < 0.0) {
    status = 0U;
  } else if (-rtDW.Gain2_m > 180.0) {
    status = 180U;
  } else {
    rtDW.d = std::round(-rtDW.Gain2_m);
    if (rtDW.d < 256.0) {
      status = static_cast<uint8_T>(rtDW.d);
    } else {
      status = MAX_uint8_T;
    }
  }

  // End of Outputs for SubSystem: '<Root>/Controller'
  MW_servoWrite(0, status);

  // End of MATLABSystem: '<Root>/Servo1'

  // Outputs for Atomic SubSystem: '<Root>/Controller'
  // MATLABSystem: '<Root>/Servo2' incorporates:
  //   Gain: '<S2>/Gain1'

  if (-rtDW.Gain3 < 0.0) {
    status = 0U;
  } else if (-rtDW.Gain3 > 180.0) {
    status = 180U;
  } else {
    rtDW.d = std::round(-rtDW.Gain3);
    if (rtDW.d < 256.0) {
      status = static_cast<uint8_T>(rtDW.d);
    } else {
      status = MAX_uint8_T;
    }
  }

  // End of Outputs for SubSystem: '<Root>/Controller'
  MW_servoWrite(1, status);

  // End of MATLABSystem: '<Root>/Servo2'

  // MATLABSystem: '<Root>/Servo3'
  if (rtDW.Gain2_m < 0.0) {
    status = 0U;
  } else if (rtDW.Gain2_m > 180.0) {
    status = 180U;
  } else {
    rtDW.d = std::round(rtDW.Gain2_m);
    if (rtDW.d < 256.0) {
      status = static_cast<uint8_T>(rtDW.d);
    } else {
      status = MAX_uint8_T;
    }
  }

  MW_servoWrite(2, status);

  // End of MATLABSystem: '<Root>/Servo3'

  // MATLABSystem: '<Root>/Servo4'
  if (rtDW.Gain3 < 0.0) {
    status = 0U;
  } else if (rtDW.Gain3 > 180.0) {
    status = 180U;
  } else {
    rtDW.d = std::round(rtDW.Gain3);
    if (rtDW.d < 256.0) {
      status = static_cast<uint8_T>(rtDW.d);
    } else {
      status = MAX_uint8_T;
    }
  }

  MW_servoWrite(3, status);

  // End of MATLABSystem: '<Root>/Servo4'

  // MATLABSystem: '<Root>/Servo5'
  if (rtDW.rtb_BNO055IMUSensor_o1_idx_2 < 0.0) {
    status = 0U;
  } else if (rtDW.rtb_BNO055IMUSensor_o1_idx_2 > 180.0) {
    status = 180U;
  } else {
    rtDW.d = std::round(rtDW.rtb_BNO055IMUSensor_o1_idx_2);
    if (rtDW.d < 256.0) {
      status = static_cast<uint8_T>(rtDW.d);
    } else {
      status = MAX_uint8_T;
    }
  }

  MW_servoWrite(4, status);

  // End of MATLABSystem: '<Root>/Servo5'

  // Update for Atomic SubSystem: '<Root>/Controller'
  // Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S3>/Discrete-Time Integrator'

  rtDW.DiscreteTimeIntegrator1_DSTATE[0] += 0.02 * rtDW.DiscreteTimeIntegrator[0];

  // Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
  //   MATLABSystem: '<Root>/BNO055 IMU Sensor'

  rtDW.DiscreteTimeIntegrator_DSTATE[0] += 0.02 * rtDW.BNO055IMUSensor_o3[0];

  // Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S3>/Discrete-Time Integrator'

  rtDW.DiscreteTimeIntegrator1_DSTATE[1] += 0.02 * rtDW.DiscreteTimeIntegrator[1];

  // Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
  //   MATLABSystem: '<Root>/BNO055 IMU Sensor'

  rtDW.DiscreteTimeIntegrator_DSTATE[1] += 0.02 * rtDW.BNO055IMUSensor_o3[1];

  // Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' incorporates:
  //   DiscreteIntegrator: '<S3>/Discrete-Time Integrator'

  rtDW.DiscreteTimeIntegrator1_DSTATE[2] += 0.02 * rtDW.DiscreteTimeIntegrator[2];

  // Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
  //   MATLABSystem: '<Root>/BNO055 IMU Sensor'

  rtDW.DiscreteTimeIntegrator_DSTATE[2] += 0.02 * rtDW.BNO055IMUSensor_o3[2];

  // Update for DiscreteIntegrator: '<S38>/Integrator'
  rtDW.Integrator_DSTATE += 0.02 * rtb_IntegralGain;

  // Update for DiscreteIntegrator: '<S33>/Filter'
  rtDW.Filter_DSTATE += 0.02 * rtb_FilterCoefficient;

  // End of Update for SubSystem: '<Root>/Controller'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&rtM)->Timing.t[0] =
    ((time_T)(++(&rtM)->Timing.clockTick0)) * (&rtM)->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.02s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.02, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&rtM)->Timing.clockTick1++;
  }
}

// Model initialize function
void KcontrolDeployModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&rtM)->solverInfo, &(&rtM)->Timing.simTimeStep);
    rtsiSetTPtr(&(&rtM)->solverInfo, &rtmGetTPtr((&rtM)));
    rtsiSetStepSizePtr(&(&rtM)->solverInfo, &(&rtM)->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&rtM)->solverInfo, (&rtmGetErrorStatus((&rtM))));
    rtsiSetRTModelPtr(&(&rtM)->solverInfo, (&rtM));
  }

  rtsiSetSimTimeStep(&(&rtM)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&(&rtM)->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr((&rtM), &(&rtM)->Timing.tArray[0]);
  (&rtM)->Timing.stepSize0 = 0.02;

  {
    i_codertarget_arduinobase_inter *obj;

    // Start for MATLABSystem: '<Root>/BNO055 IMU Sensor'
    rtDW.obj.i2cObj.matlabCodegenIsDeleted = true;
    rtDW.obj.matlabCodegenIsDeleted = true;
    rtDW.obj.isInitialized = 0L;
    rtDW.obj.SampleTime = -1.0;
    obj = &rtDW.obj.i2cObj;
    rtDW.obj.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    rtDW.obj.i2cObj.isInitialized = 0L;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    rtDW.obj.i2cObj.matlabCodegenIsDeleted = false;
    rtDW.obj.matlabCodegenIsDeleted = false;
    rtDW.obj.SampleTime = 0.02;
    SystemCore_setup(&rtDW.obj);

    // Start for MATLABSystem: '<Root>/AltCmd'
    rtDW.obj_e.matlabCodegenIsDeleted = false;
    rtDW.obj_e.SampleTime = 0.02;
    rtDW.obj_e.isInitialized = 1L;
    digitalIOSetup(3, 0);
    rtDW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/XCmd'
    rtDW.obj_f.matlabCodegenIsDeleted = false;
    rtDW.obj_f.SampleTime = 0.02;
    rtDW.obj_f.isInitialized = 1L;
    digitalIOSetup(4, 0);
    rtDW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/YCmd'
    rtDW.obj_j.matlabCodegenIsDeleted = false;
    rtDW.obj_j.SampleTime = 0.02;
    rtDW.obj_j.isInitialized = 1L;
    digitalIOSetup(5, 0);
    rtDW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Servo1'
    MW_servoAttach(0, 2);

    // Start for MATLABSystem: '<Root>/Servo2'
    MW_servoAttach(1, 6);

    // Start for MATLABSystem: '<Root>/Servo3'
    MW_servoAttach(2, 7);

    // Start for MATLABSystem: '<Root>/Servo4'
    MW_servoAttach(3, 8);

    // Start for MATLABSystem: '<Root>/Servo5'
    MW_servoAttach(4, 9);
  }
}

// Constructor
KcontrolDeployModelClass::KcontrolDeployModelClass() :
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
KcontrolDeployModelClass::~KcontrolDeployModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
KcontrolDeployModelClass::RT_MODEL * KcontrolDeployModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
