/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkSymmetricEllipsoidInteriorExteriorSpatialFunction.h
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
#ifndef __itkSymmetricEllipsoidInteriorExteriorSpatialFunction_h
#define __itkSymmetricEllipsoidInteriorExteriorSpatialFunction_h

#include "itkInteriorExteriorSpatialFunction.h"

namespace itk
{

/**
 * \class EllipsoidSpatialFunction
 * \brief Function implementation of an ellipsoid
 *
 * Similar to itkEllipsoidInteriorExteriorSpatialFunction in that it 
 * implements a function that returns 1 for points inside or on the surface
 * of a ellipsoid and 0 for points outside the ellipsoid. However, this
 * ellipsoid is defined by a single orientation vector and deals
 * only with symmetric ellipsoids. An n-dimensional symmetric ellipsoid 
 * is one which has m axes of equal length and (n - m) unique axes lengths.
 * Specifically, this class deals with the case where (n - m) = 1 and
 * the ellipsoid's major axis is oriented along a singles orientation vector.
 **/

template <class T, unsigned int VImageDimension=3>
class ITK_EXPORT SymmetricEllipsoidInteriorExteriorSpatialFunction : public InteriorExteriorSpatialFunction<VImageDimension>
{
public:

  /**
   * Standard "Self" typedef.
   */
  typedef SymmetricEllipsoidInteriorExteriorSpatialFunction Self;

  /**
   * Standard "Superclass" typedef.
   */
  typedef InteriorExteriorSpatialFunction<VImageDimension> Superclass;
    
  /**
   * Input type for the function
   */
  typedef typename Superclass::InputType InputType;

  /**
   * Output type for the function
   */
  typedef typename Superclass::OutputType OutputType;
    
  /** 
   * Smart pointer typedef support.
   */
  typedef SmartPointer<Self>  Pointer;
  typedef SmartPointer<const Self>  ConstPointer; 

  itkTypeMacro(SymmetricEllipsoidInteriorExteriorSpatialFunction,InteriorExteriorSpatialFunction);

  /**
   * Method for creation through the object factory.
   */
  itkNewMacro(Self);

  /**
   * Evaluates the function at a given position.
   */
  OutputType Evaluate(const InputType& position) const;

  /**
   * Vector typedef.
   */
  typedef T VectorType;

  /**
   * Get and set the center of the ellipsoid.
   */
  itkGetMacro(Center, InputType);
  itkSetMacro(Center, InputType);

  /**
   * Set the orientation vector of the ellipsoid's unique axis and axes lengths.
   * Must be normalized!!!!!
   */
  void SetOrientation(Vector<VectorType> orientation, VectorType uniqueAxis, VectorType symmetricAxes);

     
protected:
  SymmetricEllipsoidInteriorExteriorSpatialFunction();
  virtual ~SymmetricEllipsoidInteriorExteriorSpatialFunction();

private:
  SymmetricEllipsoidInteriorExteriorSpatialFunction(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented

  /**
   * The center of the ellipsoid.
   */
  InputType m_Center;

  /**
   * The unique axis length of the ellipsoid.
   */
  VectorType m_UniqueAxis;
  
  /**
   * The symmetric axes lengths of the ellipsoid.
   */
  VectorType m_SymmetricAxes;

  /**
   * The orientation vector of the ellipsoid's unique axis.
   */  
  Vector<VectorType, VImageDimension> m_Orientation;

  /**
   * The vector ratio.
   */  
  VectorType m_VectorRatio;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkSymmetricEllipsoidInteriorExteriorSpatialFunction.txx"
#endif

#endif
