//Code generated automatically by TMVA for Inference of Model file [Higgs_Model_4L_50.keras] at [Mon Mar  2 18:22:43 202] 

#ifndef ROOT_TMVA_SOFIE_HIGGS_MODEL_4L_50
#define ROOT_TMVA_SOFIE_HIGGS_MODEL_4L_50

#include <algorithm>
#include <cmath>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>
#include "TFile.h"

namespace TMVA_SOFIE_Higgs_Model_4L_50{
namespace BLAS{
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
}//BLAS
struct Session {
// initialized (weights and constant) tensors
std::vector<float> fTensor_dense_4kernel = std::vector<float>(64);
float * tensor_dense_4kernel = fTensor_dense_4kernel.data();
std::vector<float> fTensor_dense_3kernel = std::vector<float>(4096);
float * tensor_dense_3kernel = fTensor_dense_3kernel.data();
std::vector<float> fTensor_dense_4bias = std::vector<float>(1);
float * tensor_dense_4bias = fTensor_dense_4bias.data();
std::vector<float> fTensor_dense_2bias = std::vector<float>(64);
float * tensor_dense_2bias = fTensor_dense_2bias.data();
std::vector<float> fTensor_dense_3bias = std::vector<float>(64);
float * tensor_dense_3bias = fTensor_dense_3bias.data();
std::vector<float> fTensor_dense_2kernel = std::vector<float>(4096);
float * tensor_dense_2kernel = fTensor_dense_2kernel.data();
std::vector<float> fTensor_dense_1bias = std::vector<float>(64);
float * tensor_dense_1bias = fTensor_dense_1bias.data();
std::vector<float> fTensor_dense_1kernel = std::vector<float>(4096);
float * tensor_dense_1kernel = fTensor_dense_1kernel.data();
std::vector<float> fTensor_densebias = std::vector<float>(64);
float * tensor_densebias = fTensor_densebias.data();
std::vector<float> fTensor_densekernel = std::vector<float>(448);
float * tensor_densekernel = fTensor_densekernel.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
std::vector<char> fIntermediateMemoryPool = std::vector<char>(512);


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor denseDense with size 256 bytes
float* tensor_denseDense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense with size 256 bytes
float* tensor_tensor_output_dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_1Dense with size 256 bytes
float* tensor_dense_1Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_1 with size 256 bytes
float* tensor_tensor_output_dense_1 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_2Dense with size 256 bytes
float* tensor_dense_2Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_2 with size 256 bytes
float* tensor_tensor_output_dense_2 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_3Dense with size 256 bytes
float* tensor_dense_3Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_3 with size 256 bytes
float* tensor_tensor_output_dense_3 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_4Dense with size 4 bytes
float* tensor_dense_4Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 252);

 // Allocating memory for intermediate tensor tensor_output_dense_4 with size 4 bytes
float* tensor_tensor_output_dense_4 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 248);


Session(std::string filename ="Higgs_Model_4L_50.root") {

//--- reading weights from file
  {
   std::unique_ptr<TFile> rootFile(TFile::Open(filename.c_str(), "READ"));
   if (!rootFile->IsOpen()) {
      throw std::runtime_error("tmva-sofie failed to open ROOT file for input weights");
   }
   if (!rootFile->GetKey("Higgs_Model_4L_50_weights")) {
      throw std::runtime_error("tmva-sofie failed to open ROOT directory for input weights");
   }
  {
      fTensor_dense_4kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_dense_4kernel"));
  }
  {
      fTensor_dense_3kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_dense_3kernel"));
  }
  {
      fTensor_dense_4bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_dense_4bias"));
  }
  {
      fTensor_dense_2bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_dense_2bias"));
  }
  {
      fTensor_dense_3bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_dense_3bias"));
  }
  {
      fTensor_dense_2kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_dense_2kernel"));
  }
  {
      fTensor_dense_1bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_dense_1bias"));
  }
  {
      fTensor_dense_1kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_dense_1kernel"));
  }
  {
      fTensor_densebias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_densebias"));
  }
  {
      fTensor_densekernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_50_weights/tensor_densekernel"));
  }
  }

}

void doInfer(float const* tensor_input_layer,  std::vector<float> &output_tensor_tensor_output_dense_4 ){


//--------- Gemm op_0 { 1 , 7 } * { 7 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_denseDense[y_index + k] = tensor_densebias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_denseDense, false, false, 64, 1, 7, 1, tensor_densekernel, tensor_input_layer, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense[id] = ((tensor_denseDense[id] > 0 )? tensor_denseDense[id] : 0);
   }

//--------- Gemm op_2 { 1 , 64 } * { 64 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_1Dense[y_index + k] = tensor_dense_1bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_1Dense, false, false, 64, 1, 64, 1, tensor_dense_1kernel, tensor_tensor_output_dense, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_1[id] = ((tensor_dense_1Dense[id] > 0 )? tensor_dense_1Dense[id] : 0);
   }

//--------- Gemm op_4 { 1 , 64 } * { 64 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_2Dense[y_index + k] = tensor_dense_2bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_2Dense, false, false, 64, 1, 64, 1, tensor_dense_2kernel, tensor_tensor_output_dense_1, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_2[id] = ((tensor_dense_2Dense[id] > 0 )? tensor_dense_2Dense[id] : 0);
   }

//--------- Gemm op_6 { 1 , 64 } * { 64 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_3Dense[y_index + k] = tensor_dense_3bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_3Dense, false, false, 64, 1, 64, 1, tensor_dense_3kernel, tensor_tensor_output_dense_2, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_3[id] = ((tensor_dense_3Dense[id] > 0 )? tensor_dense_3Dense[id] : 0);
   }

//--------- Gemm op_8 { 1 , 64 } * { 64 , 1 } -> { 1 , 1 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = j;
      for (size_t k = 0; k < 1; k++) { 
         tensor_dense_4Dense[y_index + k] = tensor_dense_4bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_4Dense, false, false, 1, 1, 64, 1, tensor_dense_4kernel, tensor_tensor_output_dense_3, 1,nullptr);

//------ Sigmoid -- 9
   for (int id = 0; id < 1 ; id++){
      tensor_tensor_output_dense_4[id] = 1 / (1 + std::exp( - tensor_dense_4Dense[id]));
   }
   using TMVA::Experimental::SOFIE::UTILITY::FillOutput;

   FillOutput(tensor_tensor_output_dense_4, output_tensor_tensor_output_dense_4, 1);
}



std::vector<float> infer(float const* tensor_input_layer){
   std::vector<float > output_tensor_tensor_output_dense_4;
   doInfer(tensor_input_layer, output_tensor_tensor_output_dense_4 );
   return {output_tensor_tensor_output_dense_4};
}
};   // end of Session

} //TMVA_SOFIE_Higgs_Model_4L_50

#endif  // ROOT_TMVA_SOFIE_HIGGS_MODEL_4L_50
//Code generated automatically by TMVA for Inference of Model file [Higgs_Model_4L_200.keras] at [Mon Mar  2 18:22:44 202] 

#ifndef ROOT_TMVA_SOFIE_HIGGS_MODEL_4L_200
#define ROOT_TMVA_SOFIE_HIGGS_MODEL_4L_200

#include <algorithm>
#include <cmath>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>
#include "TFile.h"

namespace TMVA_SOFIE_Higgs_Model_4L_200{
namespace BLAS{
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
}//BLAS
struct Session {
// initialized (weights and constant) tensors
std::vector<float> fTensor_dense_9kernel = std::vector<float>(64);
float * tensor_dense_9kernel = fTensor_dense_9kernel.data();
std::vector<float> fTensor_dense_8bias = std::vector<float>(64);
float * tensor_dense_8bias = fTensor_dense_8bias.data();
std::vector<float> fTensor_dense_9bias = std::vector<float>(1);
float * tensor_dense_9bias = fTensor_dense_9bias.data();
std::vector<float> fTensor_dense_8kernel = std::vector<float>(4096);
float * tensor_dense_8kernel = fTensor_dense_8kernel.data();
std::vector<float> fTensor_dense_7bias = std::vector<float>(64);
float * tensor_dense_7bias = fTensor_dense_7bias.data();
std::vector<float> fTensor_dense_7kernel = std::vector<float>(4096);
float * tensor_dense_7kernel = fTensor_dense_7kernel.data();
std::vector<float> fTensor_dense_6bias = std::vector<float>(64);
float * tensor_dense_6bias = fTensor_dense_6bias.data();
std::vector<float> fTensor_dense_6kernel = std::vector<float>(4096);
float * tensor_dense_6kernel = fTensor_dense_6kernel.data();
std::vector<float> fTensor_dense_5bias = std::vector<float>(64);
float * tensor_dense_5bias = fTensor_dense_5bias.data();
std::vector<float> fTensor_dense_5kernel = std::vector<float>(448);
float * tensor_dense_5kernel = fTensor_dense_5kernel.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
std::vector<char> fIntermediateMemoryPool = std::vector<char>(512);


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor dense_5Dense with size 256 bytes
float* tensor_dense_5Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_5 with size 256 bytes
float* tensor_tensor_output_dense_5 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_6Dense with size 256 bytes
float* tensor_dense_6Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_6 with size 256 bytes
float* tensor_tensor_output_dense_6 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_7Dense with size 256 bytes
float* tensor_dense_7Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_7 with size 256 bytes
float* tensor_tensor_output_dense_7 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_8Dense with size 256 bytes
float* tensor_dense_8Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_8 with size 256 bytes
float* tensor_tensor_output_dense_8 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_9Dense with size 4 bytes
float* tensor_dense_9Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 252);

 // Allocating memory for intermediate tensor tensor_output_dense_9 with size 4 bytes
float* tensor_tensor_output_dense_9 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 248);


Session(std::string filename ="Higgs_Model_4L_200.root") {

//--- reading weights from file
  {
   std::unique_ptr<TFile> rootFile(TFile::Open(filename.c_str(), "READ"));
   if (!rootFile->IsOpen()) {
      throw std::runtime_error("tmva-sofie failed to open ROOT file for input weights");
   }
   if (!rootFile->GetKey("Higgs_Model_4L_200_weights")) {
      throw std::runtime_error("tmva-sofie failed to open ROOT directory for input weights");
   }
  {
      fTensor_dense_9kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_9kernel"));
  }
  {
      fTensor_dense_8bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_8bias"));
  }
  {
      fTensor_dense_9bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_9bias"));
  }
  {
      fTensor_dense_8kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_8kernel"));
  }
  {
      fTensor_dense_7bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_7bias"));
  }
  {
      fTensor_dense_7kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_7kernel"));
  }
  {
      fTensor_dense_6bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_6bias"));
  }
  {
      fTensor_dense_6kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_6kernel"));
  }
  {
      fTensor_dense_5bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_5bias"));
  }
  {
      fTensor_dense_5kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_4L_200_weights/tensor_dense_5kernel"));
  }
  }

}

void doInfer(float const* tensor_input_layer_1,  std::vector<float> &output_tensor_tensor_output_dense_9 ){


//--------- Gemm op_0 { 1 , 7 } * { 7 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_5Dense[y_index + k] = tensor_dense_5bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_5Dense, false, false, 64, 1, 7, 1, tensor_dense_5kernel, tensor_input_layer_1, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_5[id] = ((tensor_dense_5Dense[id] > 0 )? tensor_dense_5Dense[id] : 0);
   }

//--------- Gemm op_2 { 1 , 64 } * { 64 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_6Dense[y_index + k] = tensor_dense_6bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_6Dense, false, false, 64, 1, 64, 1, tensor_dense_6kernel, tensor_tensor_output_dense_5, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_6[id] = ((tensor_dense_6Dense[id] > 0 )? tensor_dense_6Dense[id] : 0);
   }

//--------- Gemm op_4 { 1 , 64 } * { 64 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_7Dense[y_index + k] = tensor_dense_7bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_7Dense, false, false, 64, 1, 64, 1, tensor_dense_7kernel, tensor_tensor_output_dense_6, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_7[id] = ((tensor_dense_7Dense[id] > 0 )? tensor_dense_7Dense[id] : 0);
   }

//--------- Gemm op_6 { 1 , 64 } * { 64 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_8Dense[y_index + k] = tensor_dense_8bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_8Dense, false, false, 64, 1, 64, 1, tensor_dense_8kernel, tensor_tensor_output_dense_7, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_8[id] = ((tensor_dense_8Dense[id] > 0 )? tensor_dense_8Dense[id] : 0);
   }

//--------- Gemm op_8 { 1 , 64 } * { 64 , 1 } -> { 1 , 1 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = j;
      for (size_t k = 0; k < 1; k++) { 
         tensor_dense_9Dense[y_index + k] = tensor_dense_9bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_9Dense, false, false, 1, 1, 64, 1, tensor_dense_9kernel, tensor_tensor_output_dense_8, 1,nullptr);

//------ Sigmoid -- 9
   for (int id = 0; id < 1 ; id++){
      tensor_tensor_output_dense_9[id] = 1 / (1 + std::exp( - tensor_dense_9Dense[id]));
   }
   using TMVA::Experimental::SOFIE::UTILITY::FillOutput;

   FillOutput(tensor_tensor_output_dense_9, output_tensor_tensor_output_dense_9, 1);
}



std::vector<float> infer(float const* tensor_input_layer_1){
   std::vector<float > output_tensor_tensor_output_dense_9;
   doInfer(tensor_input_layer_1, output_tensor_tensor_output_dense_9 );
   return {output_tensor_tensor_output_dense_9};
}
};   // end of Session

} //TMVA_SOFIE_Higgs_Model_4L_200

#endif  // ROOT_TMVA_SOFIE_HIGGS_MODEL_4L_200
//Code generated automatically by TMVA for Inference of Model file [Higgs_Model_2L_500.keras] at [Mon Mar  2 18:22:44 202] 

#ifndef ROOT_TMVA_SOFIE_HIGGS_MODEL_2L_500
#define ROOT_TMVA_SOFIE_HIGGS_MODEL_2L_500

#include <algorithm>
#include <cmath>
#include <vector>
#include "TMVA/SOFIE_common.hxx"
#include <fstream>
#include "TFile.h"

namespace TMVA_SOFIE_Higgs_Model_2L_500{
namespace BLAS{
	extern "C" void sgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k,
	                       const float * alpha, const float * A, const int * lda, const float * B, const int * ldb,
	                       const float * beta, float * C, const int * ldc);
	extern "C" void sgemv_(const char * trans, const int * m, const int * n, const float * alpha, const float * A,
	                       const int * lda, const float * X, const int * incx, const float * beta, const float * Y, const int * incy);
}//BLAS
struct Session {
// initialized (weights and constant) tensors
std::vector<float> fTensor_dense_14bias = std::vector<float>(1);
float * tensor_dense_14bias = fTensor_dense_14bias.data();
std::vector<float> fTensor_dense_14kernel = std::vector<float>(64);
float * tensor_dense_14kernel = fTensor_dense_14kernel.data();
std::vector<float> fTensor_dense_13kernel = std::vector<float>(4096);
float * tensor_dense_13kernel = fTensor_dense_13kernel.data();
std::vector<float> fTensor_dense_12bias = std::vector<float>(64);
float * tensor_dense_12bias = fTensor_dense_12bias.data();
std::vector<float> fTensor_dense_12kernel = std::vector<float>(4096);
float * tensor_dense_12kernel = fTensor_dense_12kernel.data();
std::vector<float> fTensor_dense_11bias = std::vector<float>(64);
float * tensor_dense_11bias = fTensor_dense_11bias.data();
std::vector<float> fTensor_dense_13bias = std::vector<float>(64);
float * tensor_dense_13bias = fTensor_dense_13bias.data();
std::vector<float> fTensor_dense_11kernel = std::vector<float>(4096);
float * tensor_dense_11kernel = fTensor_dense_11kernel.data();
std::vector<float> fTensor_dense_10bias = std::vector<float>(64);
float * tensor_dense_10bias = fTensor_dense_10bias.data();
std::vector<float> fTensor_dense_10kernel = std::vector<float>(448);
float * tensor_dense_10kernel = fTensor_dense_10kernel.data();

//--- Allocating session memory pool to be used for allocating intermediate tensors
std::vector<char> fIntermediateMemoryPool = std::vector<char>(512);


// --- Positioning intermediate tensor memory --
 // Allocating memory for intermediate tensor dense_10Dense with size 256 bytes
float* tensor_dense_10Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_10 with size 256 bytes
float* tensor_tensor_output_dense_10 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_11Dense with size 256 bytes
float* tensor_dense_11Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_11 with size 256 bytes
float* tensor_tensor_output_dense_11 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_12Dense with size 256 bytes
float* tensor_dense_12Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_12 with size 256 bytes
float* tensor_tensor_output_dense_12 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_13Dense with size 256 bytes
float* tensor_dense_13Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 0);

 // Allocating memory for intermediate tensor tensor_output_dense_13 with size 256 bytes
float* tensor_tensor_output_dense_13 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 256);

 // Allocating memory for intermediate tensor dense_14Dense with size 4 bytes
float* tensor_dense_14Dense = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 252);

 // Allocating memory for intermediate tensor tensor_output_dense_14 with size 4 bytes
float* tensor_tensor_output_dense_14 = reinterpret_cast<float*>(fIntermediateMemoryPool.data() + 248);


Session(std::string filename ="Higgs_Model_2L_500.root") {

//--- reading weights from file
  {
   std::unique_ptr<TFile> rootFile(TFile::Open(filename.c_str(), "READ"));
   if (!rootFile->IsOpen()) {
      throw std::runtime_error("tmva-sofie failed to open ROOT file for input weights");
   }
   if (!rootFile->GetKey("Higgs_Model_2L_500_weights")) {
      throw std::runtime_error("tmva-sofie failed to open ROOT directory for input weights");
   }
  {
      fTensor_dense_14bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_14bias"));
  }
  {
      fTensor_dense_14kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_14kernel"));
  }
  {
      fTensor_dense_13kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_13kernel"));
  }
  {
      fTensor_dense_12bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_12bias"));
  }
  {
      fTensor_dense_12kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_12kernel"));
  }
  {
      fTensor_dense_11bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_11bias"));
  }
  {
      fTensor_dense_13bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_13bias"));
  }
  {
      fTensor_dense_11kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_11kernel"));
  }
  {
      fTensor_dense_10bias = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_10bias"));
  }
  {
      fTensor_dense_10kernel = *reinterpret_cast<std::vector<float>*>(rootFile->Get("Higgs_Model_2L_500_weights/tensor_dense_10kernel"));
  }
  }

}

void doInfer(float const* tensor_input_layer_2,  std::vector<float> &output_tensor_tensor_output_dense_14 ){


//--------- Gemm op_0 { 1 , 7 } * { 7 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_10Dense[y_index + k] = tensor_dense_10bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_10Dense, false, false, 64, 1, 7, 1, tensor_dense_10kernel, tensor_input_layer_2, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_10[id] = ((tensor_dense_10Dense[id] > 0 )? tensor_dense_10Dense[id] : 0);
   }

//--------- Gemm op_2 { 1 , 64 } * { 64 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_11Dense[y_index + k] = tensor_dense_11bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_11Dense, false, false, 64, 1, 64, 1, tensor_dense_11kernel, tensor_tensor_output_dense_10, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_11[id] = ((tensor_dense_11Dense[id] > 0 )? tensor_dense_11Dense[id] : 0);
   }

//--------- Gemm op_4 { 1 , 64 } * { 64 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_12Dense[y_index + k] = tensor_dense_12bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_12Dense, false, false, 64, 1, 64, 1, tensor_dense_12kernel, tensor_tensor_output_dense_11, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_12[id] = ((tensor_dense_12Dense[id] > 0 )? tensor_dense_12Dense[id] : 0);
   }

//--------- Gemm op_6 { 1 , 64 } * { 64 , 64 } -> { 1 , 64 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = 64 * j;
      for (size_t k = 0; k < 64; k++) { 
         tensor_dense_13Dense[y_index + k] = tensor_dense_13bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_13Dense, false, false, 64, 1, 64, 1, tensor_dense_13kernel, tensor_tensor_output_dense_12, 1,nullptr);

//------ RELU
   for (int id = 0; id < 64 ; id++){
      tensor_tensor_output_dense_13[id] = ((tensor_dense_13Dense[id] > 0 )? tensor_dense_13Dense[id] : 0);
   }

//--------- Gemm op_8 { 1 , 64 } * { 64 , 1 } -> { 1 , 1 }
   for (size_t j = 0; j < 1; j++) { 
      size_t y_index = j;
      for (size_t k = 0; k < 1; k++) { 
         tensor_dense_14Dense[y_index + k] = tensor_dense_14bias[k];
      }
   }
   TMVA::Experimental::SOFIE::Gemm_Call(tensor_dense_14Dense, false, false, 1, 1, 64, 1, tensor_dense_14kernel, tensor_tensor_output_dense_13, 1,nullptr);

//------ Sigmoid -- 9
   for (int id = 0; id < 1 ; id++){
      tensor_tensor_output_dense_14[id] = 1 / (1 + std::exp( - tensor_dense_14Dense[id]));
   }
   using TMVA::Experimental::SOFIE::UTILITY::FillOutput;

   FillOutput(tensor_tensor_output_dense_14, output_tensor_tensor_output_dense_14, 1);
}



std::vector<float> infer(float const* tensor_input_layer_2){
   std::vector<float > output_tensor_tensor_output_dense_14;
   doInfer(tensor_input_layer_2, output_tensor_tensor_output_dense_14 );
   return {output_tensor_tensor_output_dense_14};
}
};   // end of Session

} //TMVA_SOFIE_Higgs_Model_2L_500

#endif  // ROOT_TMVA_SOFIE_HIGGS_MODEL_2L_500
