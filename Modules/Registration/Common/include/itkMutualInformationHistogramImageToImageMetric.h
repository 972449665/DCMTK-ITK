/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkMutualInformationHistogramImageToImageMetric_h
#define __itkMutualInformationHistogramImageToImageMetric_h

#include "itkHistogramImageToImageMetric.h"

namespace itk
{
/** \class MutualInformationHistogramImageToImageMetric
 * \brief Computes the mutual information between two images to be
 * registered using the histograms of the intensities in the images.
 * This class is templated over the type of the fixed and moving
 * images to be compared.
 *
 * This metric computes the similarity measure between pixels in the
 * moving image and pixels in the fixed images using a histogram.
 *
 * \ingroup RegistrationMetrics
 * \ingroup ITKRegistrationCommon
 */
template< class TFixedImage, class TMovingImage >
class ITK_EXPORT MutualInformationHistogramImageToImageMetric:
  public HistogramImageToImageMetric< TFixedImage, TMovingImage >
{
public:
  /** Standard class typedefs. */
  typedef MutualInformationHistogramImageToImageMetric             Self;
  typedef HistogramImageToImageMetric< TFixedImage, TMovingImage > Superclass;
  typedef SmartPointer< Self >                                     Pointer;
  typedef SmartPointer< const Self >                               ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(MutualInformationHistogramImageToImageMetric,
               HistogramImageToImageMetric);

  /** Types transferred from the base class */
  typedef typename Superclass::RealType                RealType;
  typedef typename Superclass::TransformType           TransformType;
  typedef typename Superclass::TransformPointer        TransformPointer;
  typedef typename Superclass::TransformParametersType TransformParametersType;
  typedef typename Superclass::TransformJacobianType   TransformJacobianType;
  typedef typename Superclass::GradientPixelType       GradientPixelType;

  typedef typename Superclass::MeasureType             MeasureType;
  typedef typename Superclass::DerivativeType          DerivativeType;
  typedef typename Superclass::FixedImageType          FixedImageType;
  typedef typename Superclass::MovingImageType         MovingImageType;
  typedef typename Superclass::FixedImageConstPointer  FixedImageConstPointer;
  typedef typename Superclass::MovingImageConstPointer MovingImageConstPointer;

  typedef typename Superclass::HistogramType            HistogramType;
  typedef typename HistogramType::AbsoluteFrequencyType HistogramFrequencyType;
  typedef typename HistogramType::Iterator              HistogramIteratorType;
  typedef typename HistogramType::MeasurementVectorType HistogramMeasurementVectorType;
protected:
  /** Constructor is protected to ensure that \c New() function is used to
      create instances. */
  MutualInformationHistogramImageToImageMetric(){}
  virtual ~MutualInformationHistogramImageToImageMetric(){}

  /** Evaluates the mutual information from the histogram. */
  virtual MeasureType EvaluateMeasure(HistogramType & histogram) const;

private:
  // Purposely not implemented.
  MutualInformationHistogramImageToImageMetric(Self const &);
  void operator=(Self const &); // Purposely not implemented.
};
} // End namespace itk.

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkMutualInformationHistogramImageToImageMetric.hxx"
#endif

#endif // __itkMutualInformationHistogramImageToImageMetric_h
