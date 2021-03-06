itk_module_test()
set(ITKHighDimensionalOptimizersTests
  itkArray1DToDataTest.cxx
  itkObjectToObjectOptimizerBaseTest.cxx
  itkGradientDescentObjectOptimizerBaseTest.cxx
  itkGradientDescentObjectOptimizerTest.cxx
  itkImageToDataTest.cxx
  itkOptimizerParameterScalesEstimatorTest.cxx
  itkRegistrationParameterScalesEstimatorTest.cxx
  itkRegistrationParameterScalesFromShiftTest.cxx
  itkRegistrationParameterScalesFromJacobianTest.cxx
)

set(INPUTDATA ${ITK_DATA_ROOT}/Input)
set(BASELINE_ROOT ${ITK_DATA_ROOT}/Baseline)
set(TEMP ${ITK_TEST_OUTPUT_DIR})

CreateTestDriver(ITKHighDimensionalOptimizers  "${ITKHighDimensionalOptimizers-Test_LIBRARIES}" "${ITKHighDimensionalOptimizersTests}")

itk_add_test(NAME itkArray1DToDataTest
         COMMAND ITKHighDimensionalOptimizersTestDriver itkArray1DToDataTest)

itk_add_test(NAME itkObjectToObjectOptimizerBaseTest
         COMMAND ITKHighDimensionalOptimizersTestDriver
         itkObjectToObjectOptimizerBaseTest)

itk_add_test(NAME itkGradientDescentObjectOptimizerBaseTest
      COMMAND ITKHighDimensionalOptimizersTestDriver
      itkGradientDescentObjectOptimizerBaseTest)

itk_add_test(NAME itkGradientDescentObjectOptimizerTest
      COMMAND ITKHighDimensionalOptimizersTestDriver
      itkGradientDescentObjectOptimizerTest)

itk_add_test(NAME itkImageToDataTest
         COMMAND ITKHighDimensionalOptimizersTestDriver itkImageToDataTest)

itk_add_test(NAME itkOptimizerParameterScalesEstimatorTest
      COMMAND ITKHighDimensionalOptimizersTestDriver
      itkOptimizerParameterScalesEstimatorTest)

itk_add_test(NAME itkRegistrationParameterScalesEstimatorTest
      COMMAND ITKHighDimensionalOptimizersTestDriver
      itkRegistrationParameterScalesEstimatorTest)

itk_add_test(NAME itkRegistrationParameterScalesFromShiftTest
      COMMAND ITKHighDimensionalOptimizersTestDriver
      itkRegistrationParameterScalesFromShiftTest)

itk_add_test(NAME itkRegistrationParameterScalesFromJacobianTest
      COMMAND ITKHighDimensionalOptimizersTestDriver
      itkRegistrationParameterScalesFromJacobianTest)
