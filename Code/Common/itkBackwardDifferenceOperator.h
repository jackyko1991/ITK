/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkBackwardDifferenceOperator.h
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
#ifndef __itkBackwardDifferenceOperator_h
#define __itkBackwardDifferenceOperator_h

#include "itkNeighborhoodOperator.h"
#include "itkExceptionObject.h"

namespace itk {

/**
 * \class BackwardDifferenceOperator
 * \brief Operator whose inner product with a neighborhood returns
 * a "half" derivative at the center of the neighborhood.
 *
 * BackwardDifferenceOperator uses backward differences
 * i.e. F(x) - F(x-1) to calculate a "half" derivative useful, among
 * other things, in solving differential equations. It is a directional
 * NeighborhoodOperator that should be applied to a Neighborhood using the
 * inner product. 
 *
 * \ingroup Operators
 *
 */
template<class TPixel, unsigned int VDimension=2,
  class TAllocator = NeighborhoodAllocator<TPixel> >
class ITK_EXPORT BackwardDifferenceOperator
  : public NeighborhoodOperator<TPixel, VDimension, TAllocator>
{
public:
  /** Standard class typedefs. */
  typedef BackwardDifferenceOperator Self;
  typedef NeighborhoodOperator<TPixel, VDimension, TAllocator> Superclass;
    
  /** Constructor. */
  BackwardDifferenceOperator() {}

protected:
  /** Necessary to work around a compiler bug in VC++. */
  typedef typename Superclass::CoefficientVector CoefficientVector;

  /** Calculates operator coefficients. */
  CoefficientVector GenerateCoefficients();

  /** Arranges coefficients spatially in the memory buffer. */
  void Fill(const CoefficientVector &coeff)
    { this->FillCenteredDirectional(coeff); }

private:
  BackwardDifferenceOperator(const Self& other); //purposely not implemented
  Self &operator=(const Self& other); //purposely not implemented
  
};

} // namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkBackwardDifferenceOperator.txx"
#endif

#endif


