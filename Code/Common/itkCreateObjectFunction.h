/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkCreateObjectFunction.h
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
#ifndef __itkCreateObjectFunction_h
#define __itkCreateObjectFunction_h

#include "itkObject.h"

namespace itk
{

/** \class CreateObjectFunctionBase
 * \brief Define API for object creation callback functions.
 *
 * \ingroup ITKSystemObjects
 */
class CreateObjectFunctionBase: public Object
{
public:
  /** Standard typedefs. */
  typedef CreateObjectFunctionBase  Self;
  typedef Object  Superclass;
  typedef SmartPointer<Self>        Pointer;
  typedef SmartPointer<const Self>  ConstPointer;
  
  /** Create an object and return a pointer to it as an
   * itkLightObject. */
  virtual SmartPointer<LightObject> CreateObject() = 0;
};


/** \class CreateObjectFunction
 * \brief CreateObjectFunction is used to create callback functions that
 * create itkObjects for use with the itkObjectFactory.
 * 
 * \ingroup ITKSystemObjects
 */
template <class T>
class CreateObjectFunction : public CreateObjectFunctionBase
{
public:
  /** Standard class typedefs. */
  typedef CreateObjectFunction  Self;
  typedef SmartPointer<Self>    Pointer;
    
  /** Methods from itk:LightObject. */
  static Pointer New() { return new Self;}
  LightObject::Pointer CreateObject()
    {
    return LightObject::Pointer(T::New());
    }
  };

} // end namespace itk

#endif


