/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkRedPixelAccessor.h
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
#ifndef __itkRedPixelAccessor_h
#define __itkRedPixelAccessor_h


#include "itkRGBPixel.h"


namespace itk
{

/** \class RedPixelAccessor
 * \brief Give access to the red component of a RGBPixel type 
 *
 * This class is intended to be used as parameter of 
 * an ImageAdaptor to make an RGBPixel image appear as being
 * of scalar type T, showing only the Red component.
 *
 * \sa ImageAdaptor
 * \ingroup ImageAdaptors
 */

template <class T>
class ITK_EXPORT RedPixelAccessor
{
public:
  /** Standard class typedefs. */
  typedef   RedPixelAccessor        Self;

 /** External typedef. It defines the external aspect
   * that this class will exhibit */
  typedef T ExternalType;

  /** Internal typedef. It defines the internal real
   * representation of data */
  typedef     RGBPixel<T>      InternalType;

  /** Write access to the Red component */
  inline void Set( InternalType & output, const ExternalType & input ) const
    { output.SetRed( input ); }

  /** Read access to the Red component */
  inline const ExternalType & Get( const InternalType & input ) const
    { return input.GetRed(); }
};

  
  
}  // end namespace itk


#endif

