/*==========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkVectorLinearInterpolateImageFunction.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$
Copyright (c) 2001 Insight Consortium
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * The name of the Insight Consortium, nor the names of any consortium members,
   nor of any contributors, may be used to endorse or promote products derived
   from this software without specific prior written permission.

  * Modified source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
#ifndef _itkVectorLinearInterpolateImageFunction_h
#define _itkVectorLinearInterpolateImageFunction_h

#include "itkVectorInterpolateImageFunction.h"

namespace itk
{

/** 
 * \class VectorLinearInterpolateImageFunction
 * \brief Linearly interpolate a vector image at specified positions.
 *
 * VectorLinearInterpolateImageFunction linearly interpolates a vector
 * image intensity non-integer pixel position. This class is templated
 * over the input image type.
 *
 * This function works for N-dimensional images.
 *
 * \warning This function work only for Vector images. For
 * sclar images use LinearInterpolateImageFunction.
 *
 * \ingroup ImageFunctions
 * 
 */
template <class TInputImage>
class ITK_EXPORT VectorLinearInterpolateImageFunction : 
  public VectorInterpolateImageFunction<TInputImage> 
{
public:
  /** Standard class typedefs. */
  typedef VectorLinearInterpolateImageFunction Self;
  typedef VectorInterpolateImageFunction<TInputImage> Superclass;
  typedef SmartPointer<Self> Pointer;
  typedef SmartPointer<const Self>  ConstPointer;
  
  /** Method for creation through the object factory. */
  itkNewMacro(Self);  

  /** Run-time type information (and related methods). */
  itkTypeMacro(VectorLinearInterpolateImageFunction, 
    VectorInterpolateImageFunction);

  /** InputImageType typedef support. */
  typedef typename Superclass::InputImageType InputImageType;
  typedef typename Superclass::PixelType      PixelType;
  typedef typename Superclass::ValueType      ValueType;
    
  /** Grab the vector dimension from the superclass. */
  enum { VectorDimension = Superclass::VectorDimension };

  /** Dimension underlying input image. */
  enum { ImageDimension = Superclass::ImageDimension };

  /** Index typedef support. */
  typedef typename Superclass::IndexType IndexType;

  /** ContinuousIndex typedef support. */
  typedef typename Superclass::ContinuousIndexType ContinuousIndexType;

  /** Output type is Vector<double,VectorDimension> */
  typedef typename Superclass::OutputType OutputType;

  /** Evaluate the function at a ContinuousIndex position
   *
   * Returns the linearly interpolated image intensity at a 
   * specified point position. No bounds checking is done.
   * The point is assume to lie within the image buffer.
   *
   * ImageFunction::IsInsideBuffer() can be used to check bounds before
   * calling the method. */
  virtual OutputType EvaluateAtContinuousIndex( 
    const ContinuousIndexType & index ) const;

protected:
  VectorLinearInterpolateImageFunction();
  ~VectorLinearInterpolateImageFunction(){};
  void PrintSelf(std::ostream& os, Indent indent) const;

private:
  VectorLinearInterpolateImageFunction(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  /** Number of neighbors used in the interpolation */
  static const unsigned long  m_Neighbors;  

};

} // namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkVectorLinearInterpolateImageFunction.txx"
#endif

#endif
