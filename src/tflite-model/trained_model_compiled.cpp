/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
// Generated on: 13.12.2020 03:29:46

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/kernels/micro_ops.h"

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

namespace {

constexpr int kTensorArenaSize = 1600;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_ADD, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[31];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[15];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,637 } };
const TfArray<1, float> quant0_scale = { 1, { 0.047152537852525711, } };
const TfArray<1, int> quant0_zero = { 1, { -4 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[2] = { -1, 208, };
const TfArray<1, int> tensor_dimension1 = { 1, { 2 } };
const ALIGN(8) int8_t tensor_data2[8] = { -127, -65, -60, -104, -31, -34, -54, -78, };
const TfArray<1, int> tensor_dimension2 = { 1, { 8 } };
const TfArray<1, float> quant2_scale = { 1, { 0.0045177522115409374, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(8) int8_t tensor_data3[16] = { -127, 1, 41, 21, -103, -22, -39, -8, 28, -3, -24, -55, 46, 86, 44, -52, };
const TfArray<1, int> tensor_dimension3 = { 1, { 16 } };
const TfArray<1, float> quant3_scale = { 1, { 0.0026500211097300053, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(8) int32_t tensor_data4[2] = { -1024, 1024, };
const TfArray<1, int> tensor_dimension4 = { 1, { 2 } };
const TfArray<1, float> quant4_scale = { 1, { 0.00019444891950115561, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(8) int8_t tensor_data5[2*208] = { 
  -2, -29, 15, -69, 13, 18, 38, 8, -28, -24, 18, -26, -35, -56, 11, 12, 29, 4, 5, -43, 29, 18, -3, 9, -50, -41, 42, -61, 21, -34, -39, 47, 41, 5, 8, -52, 29, 0, 36, 19, -50, -10, 19, -18, -15, 1, -39, 29, 36, -20, 12, -11, 24, 5, -22, 11, -3, -36, 29, 6, -6, -8, -75, 60, 30, -2, -40, -44, 30, -11, -24, 6, -27, -32, -47, 5, -26, 28, -46, -2, 23, -16, -40, -14, 3, -15, -5, -65, 10, -16, -23, -14, -43, 20, -39, -17, 29, 11, -30, 4, 36, -56, 15, -56, 8, 16, 4, 19, -19, 3, -14, -39, -21, -33, -40, 4, -49, -83, -6, -42, 18, 5, 17, 34, -14, -38, -4, -8, -29, -16, -25, 14, -5, -46, -33, -16, 27, -15, 11, -5, 11, -97, -20, 24, -40, -31, 38, 17, -21, -8, -37, 0, 19, -25, -12, 31, 12, -72, 28, -30, -23, -7, 20, 0, -15, -16, -25, 42, -18, -49, -44, 30, -17, -19, -16, -45, -26, -14, -1, -8, -26, -7, -27, -9, -59, -19, -28, -30, -42, 35, 7, -16, -37, -92, -20, -37, -3, 23, 34, 10, -46, 15, -27, 11, -46, 26, 26, 8, 
  10, -23, -20, 67, 11, -21, -13, 8, 34, 33, -16, 34, 34, 58, -21, -41, -9, -22, 27, 47, -42, -9, -13, -17, 12, 26, 6, 44, -15, 46, 48, -14, -45, 0, -4, 30, -27, -29, -17, -29, 20, 32, -8, 54, -2, -27, 59, -16, -16, 22, 5, 34, -22, -6, 13, 15, 19, 0, 1, -8, 7, -33, 78, -44, -46, 17, 31, -9, -35, -13, 45, 15, 24, -10, 25, -3, 11, -15, 23, -10, -47, 26, 71, -8, -20, -1, 40, 51, -35, -21, 19, -24, 32, -9, 44, 19, -13, 20, 74, 1, -38, 54, 23, 54, 18, -8, -5, -13, -15, -16, 23, 40, 32, 14, 44, -8, 30, 41, 6, 57, 5, -3, -9, -10, 4, 23, 16, 5, 25, 14, 33, 14, 20, 32, 30, 32, 15, 15, 19, 21, -13, 127, 21, -24, 46, 4, -16, 21, 46, -3, 36, -16, 11, 37, 41, -22, 5, 61, -8, -10, 21, 28, 13, 18, 30, 8, 24, -11, -27, 15, 74, -46, -26, 37, 59, 21, 51, 39, 3, 30, -16, -5, 55, 11, 11, 57, 31, 48, 36, -26, -23, 16, 37, 94, -3, 10, 41, -38, -28, -20, 83, -33, 35, 7, 59, -24, -23, 14, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 2,208 } };
const TfArray<1, float> quant5_scale = { 1, { 0.0061371214687824249, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(8) int32_t tensor_data6[8] = { 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension6 = { 1, { 8 } };
const TfArray<8, float> quant6_scale = { 8, { 0.00016901631897781044, 0.0001896698959171772, 0.00018370653560850769, 0.00017157096590381116, 0.00022261164849624038, 0.00029539642855525017, 0.0001913478336064145, 0.00021539656154345721, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(8) int8_t tensor_data7[8*1*3*13] = { 
  /* [0][0][][] */ -90,17,45,-83,89,-44,-46,-44,89,-86,7,39,-17, 18,23,-3,-45,98,-47,-110,-24,54,-77,35,62,28, -127,34,10,-56,76,-58,-115,-101,93,-65,-32,35,17, 
  /* [1][0][][] */ 49,-26,34,-71,14,-32,-84,-85,-1,62,34,-85,58, 113,-45,127,75,57,-10,23,-81,-67,7,-34,58,46, 80,-23,24,46,-25,-89,-46,-64,-113,36,46,-22,-38, 
  /* [2][0][][] */ -2,-72,34,110,-106,-59,-46,28,-65,-30,19,84,5, 21,-27,-95,-52,14,8,127,-68,-99,-95,-21,-81,25, 33,-42,-55,-44,-43,-26,35,35,-30,4,-64,-51,78, 
  /* [3][0][][] */ -106,117,-54,121,36,-73,21,20,59,42,16,-2,9, 108,90,-127,78,-3,-25,50,-5,5,73,-71,104,48, 36,35,-75,98,-10,-2,70,35,10,86,-72,115,37, 
  /* [4][0][][] */ -66,-41,-9,20,21,-100,-8,-47,-73,9,42,35,-18, -27,-48,-18,20,-43,-18,-38,-4,-57,-34,-36,65,11, -46,-43,127,-98,-14,-45,55,-49,-90,-85,9,56,-57, 
  /* [5][0][][] */ 64,6,60,-54,7,21,-4,-65,43,-28,-27,38,16, 39,-55,55,-11,44,33,42,5,43,10,-8,12,-46, 127,-30,63,30,80,49,-35,12,4,31,14,-60,-31, 
  /* [6][0][][] */ -77,-63,-69,-23,-24,17,88,19,-39,55,-29,-106,12, -24,22,66,71,-25,18,2,-25,-73,11,118,-67,43, -41,52,89,22,-18,-44,22,88,8,13,-49,-127,-8, 
  /* [7][0][][] */ -6,-5,31,55,4,-41,29,127,43,6,-99,-33,-4, 78,74,2,-36,-27,35,-30,26,-52,21,68,40,35, -3,9,48,-9,-89,-76,12,-57,16,-25,42,-90,19, 
};
const TfArray<4, int> tensor_dimension7 = { 4, { 8,1,3,13 } };
const TfArray<8, float> quant7_scale = { 8, { 0.0035844587255269289, 0.0040224748663604259, 0.0038960052188485861, 0.0036386370193213224, 0.0047210957854986191, 0.0062646986916661263, 0.0040580602362751961, 0.0045680799521505833, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(8) int32_t tensor_data8[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
const TfArray<1, int> tensor_dimension8 = { 1, { 16 } };
const TfArray<16, float> quant8_scale = { 16, { 0.00018546469800639898, 0.00014554437075275928, 0.00015768394223414361, 0.00012822578719351441, 0.00015486817574128509, 0.00010754856339190155, 0.00017941280384548008, 0.0001585907448315993, 0.00017964202561415732, 0.00014418362115975469, 0.00011555152741493657, 0.00015955546405166388, 0.00012577776215039194, 0.00013584259431809187, 0.00017506333824712783, 0.00013704474258702248, } };
const TfArray<16, int> quant8_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const ALIGN(8) int8_t tensor_data9[16*1*3*8] = { 
  /* [0][0][][] */ 30,-68,-100,46,6,-66,-19,-127, 79,-36,-98,-6,-56,-67,-44,-83, -10,-24,51,98,-24,-25,-6,10, 
  /* [1][0][][] */ -45,119,11,-10,63,39,-3,22, -127,-82,-50,3,-9,-24,-34,-35, -18,42,-36,31,86,-42,-93,-31, 
  /* [2][0][][] */ -83,37,-50,-69,38,127,-70,-54, -9,-12,-24,15,16,-20,-63,33, -70,-40,-25,-82,55,87,-13,-9, 
  /* [3][0][][] */ -31,57,64,-66,-13,71,-17,105, -63,48,-1,-5,28,59,55,-21, -64,-127,-25,-24,-77,103,86,-18, 
  /* [4][0][][] */ 69,-10,30,19,20,-94,-127,-32, -32,-73,-32,-15,-65,-95,-59,-5, 35,-115,57,123,-81,-40,-87,-5, 
  /* [5][0][][] */ 91,-61,-127,45,76,83,-28,75, -71,-64,-120,-16,-1,73,-37,-124, 72,52,-53,-69,124,-12,-85,33, 
  /* [6][0][][] */ 39,-32,-5,38,59,-5,-16,0, -19,12,-22,-38,16,65,-49,-68, -52,62,19,-62,127,-87,-15,-41, 
  /* [7][0][][] */ -50,3,23,5,68,15,37,26, -31,-126,3,-23,127,63,27,-110, -26,-56,-31,-11,90,17,-76,23, 
  /* [8][0][][] */ -23,23,51,-75,21,16,23,49, -32,-40,-127,36,-5,13,22,23, -21,35,-19,-42,-24,-48,49,44, 
  /* [9][0][][] */ -52,-92,18,43,33,49,-93,-71, -46,100,6,-13,1,56,42,-55, -42,69,127,-11,18,1,-3,26, 
  /* [10][0][][] */ -84,35,59,-43,20,-127,-40,-46, 60,63,44,-6,110,-69,67,-125, 33,28,-36,-118,7,-113,35,-118, 
  /* [11][0][][] */ -54,-23,29,45,-115,-51,47,-10, -38,34,34,-127,-122,-47,71,60, -16,4,-74,-23,16,-66,69,40, 
  /* [12][0][][] */ -23,65,-40,-51,52,40,6,-59, -67,25,95,-25,30,-124,111,1, -59,-94,-127,41,3,-1,-28,6, 
  /* [13][0][][] */ 14,-21,-18,127,-9,-119,-26,-18, -50,-26,33,-3,78,3,-2,-41, -60,-49,12,103,-67,55,-12,-66, 
  /* [14][0][][] */ -35,-26,-49,-32,-45,77,-51,-56, -40,12,-96,-11,21,32,-33,-12, -74,50,5,-49,-35,127,-2,2, 
  /* [15][0][][] */ 94,3,-30,-24,-37,-100,-77,-45, -40,4,-65,-117,57,-63,22,-34, 107,-86,3,-127,2,-58,-47,-26, 
};
const TfArray<4, int> tensor_dimension9 = { 4, { 16,1,3,8 } };
const TfArray<16, float> quant9_scale = { 16, { 0.0051475036889314651, 0.0040395297110080719, 0.0043764589354395866, 0.0035588587634265423, 0.0042983083985745907, 0.0029849703423678875, 0.0049795354716479778, 0.0044016269966959953, 0.0049858973361551762, 0.004001762717962265, 0.0032070896122604609, 0.0044284025207161903, 0.0034909150563180447, 0.0037702606059610844, 0.0048588179051876068, 0.0038036259356886148, } };
const TfArray<16, int> quant9_zero = { 16, { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const ALIGN(8) int32_t tensor_data10[4] = { 1, 1, 49, 13, };
const TfArray<1, int> tensor_dimension10 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data11[3] = { 1, 49, 8, };
const TfArray<1, int> tensor_dimension11 = { 1, { 3 } };
const ALIGN(8) int32_t tensor_data12[4] = { 1, 49, 1, 8, };
const TfArray<1, int> tensor_dimension12 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data13[4] = { 1, 1, 25, 8, };
const TfArray<1, int> tensor_dimension13 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data14[3] = { 1, 25, 16, };
const TfArray<1, int> tensor_dimension14 = { 1, { 3 } };
const ALIGN(8) int32_t tensor_data15[4] = { 1, 25, 1, 16, };
const TfArray<1, int> tensor_dimension15 = { 1, { 4 } };
const TfArray<4, int> tensor_dimension16 = { 4, { 1,1,49,13 } };
const TfArray<1, float> quant16_scale = { 1, { 0.047152537852525711, } };
const TfArray<1, int> quant16_zero = { 1, { -4 } };
const TfLiteAffineQuantization quant16 = { (TfLiteFloatArray*)&quant16_scale, (TfLiteIntArray*)&quant16_zero, 0 };
const TfArray<4, int> tensor_dimension17 = { 4, { 1,1,49,8 } };
const TfArray<1, float> quant17_scale = { 1, { 0.071499437093734741, } };
const TfArray<1, int> quant17_zero = { 1, { -4 } };
const TfLiteAffineQuantization quant17 = { (TfLiteFloatArray*)&quant17_scale, (TfLiteIntArray*)&quant17_zero, 0 };
const TfArray<3, int> tensor_dimension18 = { 3, { 1,49,8 } };
const TfArray<1, float> quant18_scale = { 1, { 0.071499437093734741, } };
const TfArray<1, int> quant18_zero = { 1, { -4 } };
const TfLiteAffineQuantization quant18 = { (TfLiteFloatArray*)&quant18_scale, (TfLiteIntArray*)&quant18_zero, 0 };
const TfArray<3, int> tensor_dimension19 = { 3, { 1,49,8 } };
const TfArray<1, float> quant19_scale = { 1, { 0.036030028015375137, } };
const TfArray<1, int> quant19_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant19 = { (TfLiteFloatArray*)&quant19_scale, (TfLiteIntArray*)&quant19_zero, 0 };
const TfArray<4, int> tensor_dimension20 = { 4, { 1,49,1,8 } };
const TfArray<1, float> quant20_scale = { 1, { 0.036030028015375137, } };
const TfArray<1, int> quant20_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant20 = { (TfLiteFloatArray*)&quant20_scale, (TfLiteIntArray*)&quant20_zero, 0 };
const TfArray<4, int> tensor_dimension21 = { 4, { 1,25,1,8 } };
const TfArray<1, float> quant21_scale = { 1, { 0.036030028015375137, } };
const TfArray<1, int> quant21_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant21 = { (TfLiteFloatArray*)&quant21_scale, (TfLiteIntArray*)&quant21_zero, 0 };
const TfArray<4, int> tensor_dimension22 = { 4, { 1,1,25,8 } };
const TfArray<1, float> quant22_scale = { 1, { 0.036030028015375137, } };
const TfArray<1, int> quant22_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant22 = { (TfLiteFloatArray*)&quant22_scale, (TfLiteIntArray*)&quant22_zero, 0 };
const TfArray<4, int> tensor_dimension23 = { 4, { 1,1,25,16 } };
const TfArray<1, float> quant23_scale = { 1, { 0.090351760387420654, } };
const TfArray<1, int> quant23_zero = { 1, { 39 } };
const TfLiteAffineQuantization quant23 = { (TfLiteFloatArray*)&quant23_scale, (TfLiteIntArray*)&quant23_zero, 0 };
const TfArray<3, int> tensor_dimension24 = { 3, { 1,25,16 } };
const TfArray<1, float> quant24_scale = { 1, { 0.090351760387420654, } };
const TfArray<1, int> quant24_zero = { 1, { 39 } };
const TfLiteAffineQuantization quant24 = { (TfLiteFloatArray*)&quant24_scale, (TfLiteIntArray*)&quant24_zero, 0 };
const TfArray<3, int> tensor_dimension25 = { 3, { 1,25,16 } };
const TfArray<1, float> quant25_scale = { 1, { 0.031684059649705887, } };
const TfArray<1, int> quant25_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant25 = { (TfLiteFloatArray*)&quant25_scale, (TfLiteIntArray*)&quant25_zero, 0 };
const TfArray<4, int> tensor_dimension26 = { 4, { 1,25,1,16 } };
const TfArray<1, float> quant26_scale = { 1, { 0.031684059649705887, } };
const TfArray<1, int> quant26_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant26 = { (TfLiteFloatArray*)&quant26_scale, (TfLiteIntArray*)&quant26_zero, 0 };
const TfArray<4, int> tensor_dimension27 = { 4, { 1,13,1,16 } };
const TfArray<1, float> quant27_scale = { 1, { 0.031684059649705887, } };
const TfArray<1, int> quant27_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant27 = { (TfLiteFloatArray*)&quant27_scale, (TfLiteIntArray*)&quant27_zero, 0 };
const TfArray<2, int> tensor_dimension28 = { 2, { 1,208 } };
const TfArray<1, float> quant28_scale = { 1, { 0.031684059649705887, } };
const TfArray<1, int> quant28_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant28 = { (TfLiteFloatArray*)&quant28_scale, (TfLiteIntArray*)&quant28_zero, 0 };
const TfArray<2, int> tensor_dimension29 = { 2, { 1,2 } };
const TfArray<1, float> quant29_scale = { 1, { 0.13555251061916351, } };
const TfArray<1, int> quant29_zero = { 1, { 1 } };
const TfLiteAffineQuantization quant29 = { (TfLiteFloatArray*)&quant29_scale, (TfLiteIntArray*)&quant29_zero, 0 };
const TfArray<2, int> tensor_dimension30 = { 2, { 1,2 } };
const TfArray<1, float> quant30_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant30_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant30 = { (TfLiteFloatArray*)&quant30_scale, (TfLiteIntArray*)&quant30_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,10 } };
const TfArray<1, int> outputs0 = { 1, { 16 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActNone, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 16,7,6 } };
const TfArray<1, int> outputs1 = { 1, { 17 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 17,11 } };
const TfArray<1, int> outputs2 = { 1, { 18 } };
const TfLiteAddParams opdata3 = { kTfLiteActRelu };
const TfArray<2, int> inputs3 = { 2, { 18,2 } };
const TfArray<1, int> outputs3 = { 1, { 19 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 19,12 } };
const TfArray<1, int> outputs4 = { 1, { 20 } };
const TfLitePoolParams opdata5 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs5 = { 1, { 20 } };
const TfArray<1, int> outputs5 = { 1, { 21 } };
const TfLiteReshapeParams opdata6 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs6 = { 2, { 21,13 } };
const TfArray<1, int> outputs6 = { 1, { 22 } };
const TfLiteConvParams opdata7 = { kTfLitePaddingSame, 1,1, kTfLiteActNone, 1,1 };
const TfArray<3, int> inputs7 = { 3, { 22,9,8 } };
const TfArray<1, int> outputs7 = { 1, { 23 } };
const TfLiteReshapeParams opdata8 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs8 = { 2, { 23,14 } };
const TfArray<1, int> outputs8 = { 1, { 24 } };
const TfLiteAddParams opdata9 = { kTfLiteActRelu };
const TfArray<2, int> inputs9 = { 2, { 24,3 } };
const TfArray<1, int> outputs9 = { 1, { 25 } };
const TfLiteReshapeParams opdata10 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs10 = { 2, { 25,15 } };
const TfArray<1, int> outputs10 = { 1, { 26 } };
const TfLitePoolParams opdata11 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs11 = { 1, { 26 } };
const TfArray<1, int> outputs11 = { 1, { 27 } };
const TfLiteReshapeParams opdata12 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs12 = { 2, { 27,1 } };
const TfArray<1, int> outputs12 = { 1, { 28 } };
const TfLiteFullyConnectedParams opdata13 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs13 = { 3, { 28,5,4 } };
const TfArray<1, int> outputs13 = { 1, { 29 } };
const TfLiteSoftmaxParams opdata14 = { 1 };
const TfArray<1, int> inputs14 = { 1, { 29 } };
const TfArray<1, int> outputs14 = { 1, { 30 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 640, (TfLiteIntArray*)&tensor_dimension0, 637, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 8, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 16, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 416, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 312, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data9, (TfLiteIntArray*)&tensor_dimension9, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data10, (TfLiteIntArray*)&tensor_dimension10, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data11, (TfLiteIntArray*)&tensor_dimension11, 12, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data12, (TfLiteIntArray*)&tensor_dimension12, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data13, (TfLiteIntArray*)&tensor_dimension13, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data14, (TfLiteIntArray*)&tensor_dimension14, 12, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data15, (TfLiteIntArray*)&tensor_dimension15, 16, {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension16, 637, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant16))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 640, (TfLiteIntArray*)&tensor_dimension17, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant17))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension18, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant18))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension19, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant19))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension20, 392, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant20))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension21, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant21))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension22, 200, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant22))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension23, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant23))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension24, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant24))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension25, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant25))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension26, 400, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant26))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 400, (TfLiteIntArray*)&tensor_dimension27, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant27))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension28, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant28))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 208, (TfLiteIntArray*)&tensor_dimension29, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant29))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension30, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant30))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_ADD, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs5, (TfLiteIntArray*)&outputs5, const_cast<void*>(static_cast<const void*>(&opdata5)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs6, (TfLiteIntArray*)&outputs6, const_cast<void*>(static_cast<const void*>(&opdata6)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs7, (TfLiteIntArray*)&outputs7, const_cast<void*>(static_cast<const void*>(&opdata7)), OP_CONV_2D, },
  { (TfLiteIntArray*)&inputs8, (TfLiteIntArray*)&outputs8, const_cast<void*>(static_cast<const void*>(&opdata8)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs9, (TfLiteIntArray*)&outputs9, const_cast<void*>(static_cast<const void*>(&opdata9)), OP_ADD, },
  { (TfLiteIntArray*)&inputs10, (TfLiteIntArray*)&outputs10, const_cast<void*>(static_cast<const void*>(&opdata10)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs11, (TfLiteIntArray*)&outputs11, const_cast<void*>(static_cast<const void*>(&opdata11)), OP_MAX_POOL_2D, },
  { (TfLiteIntArray*)&inputs12, (TfLiteIntArray*)&outputs12, const_cast<void*>(static_cast<const void*>(&opdata12)), OP_RESHAPE, },
  { (TfLiteIntArray*)&inputs13, (TfLiteIntArray*)&outputs13, const_cast<void*>(static_cast<const void*>(&opdata13)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs14, (TfLiteIntArray*)&outputs14, const_cast<void*>(static_cast<const void*>(&opdata14)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static TfLiteStatus AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                                 size_t bytes, void** ptr) {
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    *ptr = malloc(bytes);
    if (*ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %u\n", bytes);
      return kTfLiteError;
    }
    overflow_buffers.push_back(*ptr);
    return kTfLiteOk;
  }

  current_location -= bytes;

  *ptr = current_location;
  return kTfLiteOk;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  TfLiteStatus s = AllocatePersistentBuffer(ctx, b.bytes, &b.ptr);
  if (s != kTfLiteOk) {
    return s;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}
} // namespace

  TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 31;
  for(size_t i = 0; i < 31; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;
    #if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    #if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);
      uint8_t* end = start + tensorData[i].bytes;

     tflTensors[i].data.data =  start;

     if (end > tensor_boundary) {
       tensor_boundary = end;
     }
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
  }
  registrations[OP_RESHAPE] = *tflite::ops::micro::Register_RESHAPE();
  registrations[OP_CONV_2D] = *tflite::ops::micro::Register_CONV_2D();
  registrations[OP_ADD] = *tflite::ops::micro::Register_ADD();
  registrations[OP_MAX_POOL_2D] = *tflite::ops::micro::Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = *tflite::ops::micro::Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = *tflite::ops::micro::Register_SOFTMAX();

  for(size_t i = 0; i < 15; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
    tflNodes[i].custom_initial_data = nullptr;
    tflNodes[i].custom_initial_data_size = 0;
    if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 15; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  30, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 15; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);
    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}
