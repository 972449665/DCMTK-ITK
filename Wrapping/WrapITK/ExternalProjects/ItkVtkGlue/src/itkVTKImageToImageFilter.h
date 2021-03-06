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

#ifndef __itkVTKImageToImageFilter_h
#define __itkVTKImageToImageFilter_h

#include "itkVTKImageImport.h"
#include "vtkImageExport.h"
#include "vtkImageData.h"

#ifndef vtkFloatingPointType
#define vtkFloatingPointType float
#endif

namespace itk
{

/** \class VTKImageToImageFilter
 * \brief Converts a VTK image into an ITK image and plugs a
 *  vtk data pipeline to an ITK datapipeline.
 *
 *  This class puts together an itkVTKImageImporter and a vtkImageExporter.
 *  It takes care of the details related to the connection of ITK and VTK
 *  pipelines. The User will perceive this filter as an adaptor to which
 *  a vtkImage can be plugged as input and an itk::Image is produced as
 *  output.
 *
 * \ingroup   ImageFilters
 */
template <class TOutputImage >
class ITK_EXPORT VTKImageToImageFilter : public VTKImageImport< TOutputImage >
{
public:
  /** Standard class typedefs. */
  typedef VTKImageToImageFilter             Self;
  typedef VTKImageImport< TOutputImage >    Superclass;
  typedef SmartPointer<Self>                Pointer;
  typedef SmartPointer<const Self>          ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(VTKImageToImageFilter, VTKImageImport);

  /** Some typedefs. */
  typedef TOutputImage                              OutputImageType;
  typedef typename    OutputImageType::ConstPointer OutputImagePointer;

  /** Set the input in the form of a vtkImageData */
  void SetInput( vtkImageData * );

  /** Return the internal VTK image exporter filter.
      This is intended to facilitate users the access
      to methods in the exporter */
  vtkImageExport * GetExporter() const;

  /** Return the internal ITK image importer filter.
      This is intended to facilitate users the access
      to methods in the importer.
      Deprecated - the method now return 'this'.
      */
  const Superclass * GetImporter() const;

protected:
  VTKImageToImageFilter();
  virtual ~VTKImageToImageFilter();

private:
  VTKImageToImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  vtkImageExport            * m_Exporter;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkVTKImageToImageFilter.txx"
#endif

#endif
