/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkNeighborhoodInnerProduct.h
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
#ifndef __itkNeighborhoodInnerProduct_h
#define __itkNeighborhoodInnerProduct_h

#include "itkNeighborhoodIterator.h"
#include "itkSmartNeighborhoodIterator.h"
#include "itkNeighborhood.h"
#include "itkConstSliceIterator.h"
#include "itkImageBoundaryCondition.h"

namespace itk {
  
/** \class NeighborhoodInnerProduct
 *
 * This class defines the inner product operation between an
 * itk::Neighborhood and and itk::NeighborhoodOperator.  The
 * operator() method is overloaded to support various types of
 * neighborhoods as well as inner products with slices of
 * neighborhoods. The second template parameter allows you to set the
 * value type of the operator. The third templage parameter allows you
 * to set the value type used as the return type of the inner product
 * calculation. The operator value type defaults to the image pixel
 * type and the output value type defaults to the operator type.
 *
 * \ingroup Operators
 */
template<class TImage, class TOperator=ITK_TYPENAME TImage::PixelType, class TComputation=TOperator>
class NeighborhoodInnerProduct
{
public:
  /** Capture some typedefs from the template parameters. */
  typedef typename TImage::PixelType ImagePixelType;
  typedef TOperator OperatorPixelType;
  typedef TComputation OutputPixelType;
    
  /** Capture some typedefs from the template parameters. */
  enum {ImageDimension = TImage::ImageDimension};

  /** Reference oeprator. */
  OutputPixelType operator()(const ConstNeighborhoodIterator<TImage> &it,
                       const Neighborhood<OperatorPixelType, ImageDimension>
                       &op) const;
  OutputPixelType operator()(const std::slice &s,
                       const ConstNeighborhoodIterator<TImage> &it,
                       const Neighborhood<OperatorPixelType, ImageDimension>
                       &op) const;
  };

template<class TImage, class TOperator=ITK_TYPENAME TImage::PixelType, class TComputation=TOperator>
class SmartNeighborhoodInnerProduct
{
public:
  /** Capture some typedefs from the template parameters. */
  typedef typename TImage::PixelType ImagePixelType;
  typedef TOperator OperatorPixelType;
  typedef TComputation OutputPixelType;
  
  /** Capture some typedefs from the template parameters. */
  enum {ImageDimension = TImage::ImageDimension};

  /** Reference oeprator. */
  OutputPixelType operator()(const std::slice &s,
                       const ConstSmartNeighborhoodIterator<TImage> &it,
                       const Neighborhood<OperatorPixelType, ImageDimension>
                       &op) const;
  OutputPixelType operator()(const ConstSmartNeighborhoodIterator<TImage> &it,
                       const Neighborhood<OperatorPixelType, ImageDimension>
                       &op) const
    {
      return this->operator()(std::slice(0, it.Size(), 1), it, op);
    }
  };
  
  
  
} // end namespace itk
  
#ifndef ITK_MANUAL_INSTANTIATION
#include "itkNeighborhoodInnerProduct.txx"
#endif

#endif
