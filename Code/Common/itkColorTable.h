/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkColorTable.h
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
#ifndef __itkColorTable_h
#define __itkColorTable_h

#include <itkObject.h>
#include <itkRGBPixel.h>
#include <itkObjectFactory.h>

namespace itk 
{
/** \class ColorTable
 *  itkColorTable Class define a Color table for image visualisation
 * 
 * \ingroup DataRepresentation
 */

template<class TPixel>
class ITK_EXPORT ColorTable : public Object
{
public:
  /** Standard class typedefs. */
  typedef ColorTable   Self;
  typedef Object Superclass;
  typedef SmartPointer<Self>  Pointer;
  typedef SmartPointer<const Self>  ConstPointer;
  
  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(ColorTable,Object);

  /** Badly named methods that require renaming and documentation. */ 
  void    useDiscrete(void);
  void    useGray(int n=256);
  void    useHeat(int n=256);
  int     size(void);
  RGBPixel<TPixel>*          color(int c);
  
  /** Given the position in the table and the color 
   * returns the value. \todo Needs renaming. */
  TPixel  color(int c, char rgb);
  char *  colorName(int c);
   
protected:
  ColorTable();
  virtual ~ColorTable();

  int                  m_NumberOfColors;
  RGBPixel<TPixel> *   m_Color;
  char **              m_ColorName;

private:
  ColorTable(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented
};


}// namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkColorTable.txx"
#endif

#endif
