/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkCastImageFilter.h
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
#ifndef __itkCastImageFilter_h
#define __itkCastImageFilter_h

#include "itkUnaryFunctorImageFilter.h"

namespace itk
{
  
/** \class CastImageFilter
 *
 * \brief Casts input pixels to output pixel type.
 *
 * This filter is templated over the input image type
 * and the output image type.
 * 
 * The filter expect both images to have the same number of dimensions.
 *
 * \ingroup IntensityImageFilters  Multithreaded
 */
namespace Functor {  
  
  template< class TInput, class TOutput>
  class Cast
  {
  public:
    Cast() {};
    ~Cast() {};
    inline TOutput operator()( const TInput & A )
    {
      return static_cast<TOutput>( A );
    }
  };
}

template <class TInputImage, class TOutputImage>
class ITK_EXPORT CastImageFilter :
    public
    UnaryFunctorImageFilter<TInputImage,TOutputImage, 
    Functor::Cast< 
              typename TInputImage::PixelType, 
              typename TOutputImage::PixelType> >
{
public:
  /** Standard class typedefs. */
  typedef CastImageFilter  Self;
  typedef UnaryFunctorImageFilter<TInputImage,TOutputImage, 
    Functor::Cast< 
              typename TInputImage::PixelType, 
              typename TOutputImage::PixelType>   
                >  Superclass;
  typedef SmartPointer<Self>   Pointer;
  typedef SmartPointer<const Self>  ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);
  
protected:
  CastImageFilter() {}
  virtual ~CastImageFilter() {}

private:
  CastImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

};


} // end namespace itk


#endif
