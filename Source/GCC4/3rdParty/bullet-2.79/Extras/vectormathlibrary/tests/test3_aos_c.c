/*
  Copyright (C) 2006, 2007 Sony Computer Entertainment Inc.
  All rights reserved.

  Redistribution and use in source and binary forms,
  with or without modification, are permitted provided that the
  following conditions are met:
   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   * Neither the name of the Sony Computer Entertainment Inc nor the names
     of its contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#define _VECTORMATH_AOS_TEST

#include "vectormath_aos.h"
#include "test.h"

int iteration = 0;

void
Matrix3_methods_test()
{
    VmathMatrix3 a_Matrix3, b_Matrix3;
    VmathMatrix4 a_Matrix4, b_Matrix4;
    VmathTransform3 a_Transform3, b_Transform3;
    VmathMatrix3 tmpM3_0, tmpM3_1, tmpM3_2, tmpM3_3, tmpM3_4, tmpM3_5;
    VmathVector3 a_Vector3, b_Vector3, c_Vector3, d_Vector3;
    VmathVector4 a_Vector4, b_Vector4, c_Vector4, d_Vector4;
    VmathPoint3 a_Point3, b_Point3, c_Point3, d_Point3;
    VmathQuat a_Quat, b_Quat, c_Quat, d_Quat;
    VmathVector4 tmpV4;
    VmathVector3 tmpV3_0, tmpV3_1, tmpV3_2, tmpV3_3, tmpV3_4, tmpV3_5, tmpV3_6, tmpV3_7, tmpV3_8;
    float rndflt1, rndflt2, rndflt3, rndflt4, rndflt5, rndflt6, pad;
    // set a pad value to detect invalid use of padding.
    // this will be nan for scalar/ppu implementations, max. float for spu
    union { float f; unsigned int u; } tmp;
    tmp.u = 0x7fffffff;
    pad = tmp.f;
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathV3MakeFromElems( &a_Vector3, rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathV3MakeFromElems( &b_Vector3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathV3MakeFromElems( &c_Vector3, rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathV3MakeFromElems( &d_Vector3, rndflt1, rndflt2, rndflt3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &a_Vector3, pad );
    vmathV4GetXYZ( &a_Vector3, &tmpV4 );
    vmathV4MakeFromV3Scalar( &tmpV4, &b_Vector3, pad );
    vmathV4GetXYZ( &b_Vector3, &tmpV4 );
    vmathV4MakeFromV3Scalar( &tmpV4, &c_Vector3, pad );
    vmathV4GetXYZ( &c_Vector3, &tmpV4 );
    vmathV4MakeFromV3Scalar( &tmpV4, &d_Vector3, pad );
    vmathV4GetXYZ( &d_Vector3, &tmpV4 );
    vmathV3Prints( &a_Vector3, "set Vector3 with floats" );
    vmathV3Prints( &b_Vector3, "set Vector3 with floats" );
    vmathV3Prints( &c_Vector3, "set Vector3 with floats" );
    vmathV3Prints( &d_Vector3, "set Vector3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathV4MakeFromElems( &a_Vector4, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathV4MakeFromElems( &b_Vector4, rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathV4MakeFromElems( &c_Vector4, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathV4MakeFromElems( &d_Vector4, rndflt1, rndflt2, rndflt3, rndflt4 );
    vmathV4Prints( &a_Vector4, "set Vector4 with floats" );
    vmathV4Prints( &b_Vector4, "set Vector4 with floats" );
    vmathV4Prints( &c_Vector4, "set Vector4 with floats" );
    vmathV4Prints( &d_Vector4, "set Vector4 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathP3MakeFromElems( &a_Point3, rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathP3MakeFromElems( &b_Point3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathP3MakeFromElems( &c_Point3, rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathP3MakeFromElems( &d_Point3, rndflt1, rndflt2, rndflt3 );
    vmathV3MakeFromP3( &tmpV3_0, &a_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_0, pad );
    vmathV4GetXYZ( &tmpV3_1, &tmpV4 );
    vmathP3MakeFromV3( &a_Point3, &tmpV3_1 );
    vmathV3MakeFromP3( &tmpV3_2, &b_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_2, pad );
    vmathV4GetXYZ( &tmpV3_3, &tmpV4 );
    vmathP3MakeFromV3( &b_Point3, &tmpV3_3 );
    vmathV3MakeFromP3( &tmpV3_4, &c_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_4, pad );
    vmathV4GetXYZ( &tmpV3_5, &tmpV4 );
    vmathP3MakeFromV3( &c_Point3, &tmpV3_5 );
    vmathV3MakeFromP3( &tmpV3_6, &d_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_6, pad );
    vmathV4GetXYZ( &tmpV3_7, &tmpV4 );
    vmathP3MakeFromV3( &d_Point3, &tmpV3_7 );
    vmathP3Prints( &a_Point3, "set Point3 with floats" );
    vmathP3Prints( &b_Point3, "set Point3 with floats" );
    vmathP3Prints( &c_Point3, "set Point3 with floats" );
    vmathP3Prints( &d_Point3, "set Point3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathQMakeFromElems( &a_Quat, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathQMakeFromElems( &b_Quat, rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathQMakeFromElems( &c_Quat, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathQMakeFromElems( &d_Quat, rndflt1, rndflt2, rndflt3, rndflt4 );
    vmathQPrints( &a_Quat, "set Quat with floats" );
    vmathQPrints( &b_Quat, "set Quat with floats" );
    vmathQPrints( &c_Quat, "set Quat with floats" );
    vmathQPrints( &d_Quat, "set Quat with floats" );
    vmathM3MakeFromCols( &a_Matrix3, &a_Vector3, &b_Vector3, &c_Vector3 );
    vmathM3MakeFromCols( &b_Matrix3, &d_Vector3, &a_Vector3, &b_Vector3 );
    vmathM3Prints( &a_Matrix3, "set Matrix3 columns" );
    vmathM3Prints( &b_Matrix3, "set Matrix3 columns" );
    vmathM4MakeFromCols( &a_Matrix4, &a_Vector4, &b_Vector4, &c_Vector4, &d_Vector4 );
    vmathM4MakeFromCols( &b_Matrix4, &d_Vector4, &a_Vector4, &b_Vector4, &c_Vector4 );
    vmathM4Prints( &a_Matrix4, "set Matrix4 columns" );
    vmathM4Prints( &b_Matrix4, "set Matrix4 columns" );
    vmathT3MakeFromCols( &a_Transform3, &a_Vector3, &b_Vector3, &c_Vector3, &d_Vector3 );
    vmathT3MakeFromCols( &b_Transform3, &d_Vector3, &a_Vector3, &b_Vector3, &c_Vector3 );
    vmathT3Prints( &a_Transform3, "set Transform3 columns" );
    vmathT3Prints( &b_Transform3, "set Transform3 columns" );
    vmathM3Add( &tmpM3_0, &a_Matrix3, &b_Matrix3 );
    vmathM3Prints( &tmpM3_0, "Matrix3 + Matrix3" );
    vmathM3Sub( &tmpM3_1, &a_Matrix3, &b_Matrix3 );
    vmathM3Prints( &tmpM3_1, "Matrix3 - Matrix3" );
    vmathM3Neg( &tmpM3_2, &a_Matrix3 );
    vmathM3Prints( &tmpM3_2, "-Matrix3" );
    vmathM3ScalarMul( &tmpM3_3, &a_Matrix3, randfloat() );
    vmathM3Prints( &tmpM3_3, "Matrix3 * float" );
    vmathM3ScalarMul( &tmpM3_4, &a_Matrix3, randfloat() );
    vmathM3Prints( &tmpM3_4, "float * Matrix3" );
    vmathM3MulV3( &tmpV3_8, &a_Matrix3, &a_Vector3 );
    vmathV3Prints( &tmpV3_8, "Matrix3 * Vector3" );
    vmathM3Mul( &tmpM3_5, &a_Matrix3, &b_Matrix3 );
    vmathM3Prints( &tmpM3_5, "Matrix3 * Matrix3" );
}

void
Matrix4_methods_test()
{
    VmathMatrix3 a_Matrix3, b_Matrix3;
    VmathMatrix4 a_Matrix4, b_Matrix4;
    VmathTransform3 a_Transform3, b_Transform3;
    VmathMatrix4 tmpM4_0, tmpM4_1, tmpM4_2, tmpM4_3, tmpM4_4, tmpM4_5, tmpM4_6;
    VmathVector3 a_Vector3, b_Vector3, c_Vector3, d_Vector3;
    VmathVector4 a_Vector4, b_Vector4, c_Vector4, d_Vector4;
    VmathPoint3 a_Point3, b_Point3, c_Point3, d_Point3;
    VmathQuat a_Quat, b_Quat, c_Quat, d_Quat;
    VmathVector4 tmpV4;
    VmathVector3 tmpV3_0, tmpV3_1, tmpV3_2, tmpV3_3, tmpV3_4, tmpV3_5, tmpV3_6, tmpV3_7;
    VmathVector4 tmpV4_0, tmpV4_1, tmpV4_2;
    float rndflt1, rndflt2, rndflt3, rndflt4, rndflt5, rndflt6, pad;
    // set a pad value to detect invalid use of padding.
    // this will be nan for scalar/ppu implementations, max. float for spu
    union { float f; unsigned int u; } tmp;
    tmp.u = 0x7fffffff;
    pad = tmp.f;
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathV3MakeFromElems( &a_Vector3, rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathV3MakeFromElems( &b_Vector3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathV3MakeFromElems( &c_Vector3, rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathV3MakeFromElems( &d_Vector3, rndflt1, rndflt2, rndflt3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &a_Vector3, pad );
    vmathV4GetXYZ( &a_Vector3, &tmpV4 );
    vmathV4MakeFromV3Scalar( &tmpV4, &b_Vector3, pad );
    vmathV4GetXYZ( &b_Vector3, &tmpV4 );
    vmathV4MakeFromV3Scalar( &tmpV4, &c_Vector3, pad );
    vmathV4GetXYZ( &c_Vector3, &tmpV4 );
    vmathV4MakeFromV3Scalar( &tmpV4, &d_Vector3, pad );
    vmathV4GetXYZ( &d_Vector3, &tmpV4 );
    vmathV3Prints( &a_Vector3, "set Vector3 with floats" );
    vmathV3Prints( &b_Vector3, "set Vector3 with floats" );
    vmathV3Prints( &c_Vector3, "set Vector3 with floats" );
    vmathV3Prints( &d_Vector3, "set Vector3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathV4MakeFromElems( &a_Vector4, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathV4MakeFromElems( &b_Vector4, rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathV4MakeFromElems( &c_Vector4, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathV4MakeFromElems( &d_Vector4, rndflt1, rndflt2, rndflt3, rndflt4 );
    vmathV4Prints( &a_Vector4, "set Vector4 with floats" );
    vmathV4Prints( &b_Vector4, "set Vector4 with floats" );
    vmathV4Prints( &c_Vector4, "set Vector4 with floats" );
    vmathV4Prints( &d_Vector4, "set Vector4 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathP3MakeFromElems( &a_Point3, rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathP3MakeFromElems( &b_Point3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathP3MakeFromElems( &c_Point3, rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathP3MakeFromElems( &d_Point3, rndflt1, rndflt2, rndflt3 );
    vmathV3MakeFromP3( &tmpV3_0, &a_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_0, pad );
    vmathV4GetXYZ( &tmpV3_1, &tmpV4 );
    vmathP3MakeFromV3( &a_Point3, &tmpV3_1 );
    vmathV3MakeFromP3( &tmpV3_2, &b_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_2, pad );
    vmathV4GetXYZ( &tmpV3_3, &tmpV4 );
    vmathP3MakeFromV3( &b_Point3, &tmpV3_3 );
    vmathV3MakeFromP3( &tmpV3_4, &c_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_4, pad );
    vmathV4GetXYZ( &tmpV3_5, &tmpV4 );
    vmathP3MakeFromV3( &c_Point3, &tmpV3_5 );
    vmathV3MakeFromP3( &tmpV3_6, &d_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_6, pad );
    vmathV4GetXYZ( &tmpV3_7, &tmpV4 );
    vmathP3MakeFromV3( &d_Point3, &tmpV3_7 );
    vmathP3Prints( &a_Point3, "set Point3 with floats" );
    vmathP3Prints( &b_Point3, "set Point3 with floats" );
    vmathP3Prints( &c_Point3, "set Point3 with floats" );
    vmathP3Prints( &d_Point3, "set Point3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathQMakeFromElems( &a_Quat, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathQMakeFromElems( &b_Quat, rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathQMakeFromElems( &c_Quat, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathQMakeFromElems( &d_Quat, rndflt1, rndflt2, rndflt3, rndflt4 );
    vmathQPrints( &a_Quat, "set Quat with floats" );
    vmathQPrints( &b_Quat, "set Quat with floats" );
    vmathQPrints( &c_Quat, "set Quat with floats" );
    vmathQPrints( &d_Quat, "set Quat with floats" );
    vmathM3MakeFromCols( &a_Matrix3, &a_Vector3, &b_Vector3, &c_Vector3 );
    vmathM3MakeFromCols( &b_Matrix3, &d_Vector3, &a_Vector3, &b_Vector3 );
    vmathM3Prints( &a_Matrix3, "set Matrix3 columns" );
    vmathM3Prints( &b_Matrix3, "set Matrix3 columns" );
    vmathM4MakeFromCols( &a_Matrix4, &a_Vector4, &b_Vector4, &c_Vector4, &d_Vector4 );
    vmathM4MakeFromCols( &b_Matrix4, &d_Vector4, &a_Vector4, &b_Vector4, &c_Vector4 );
    vmathM4Prints( &a_Matrix4, "set Matrix4 columns" );
    vmathM4Prints( &b_Matrix4, "set Matrix4 columns" );
    vmathT3MakeFromCols( &a_Transform3, &a_Vector3, &b_Vector3, &c_Vector3, &d_Vector3 );
    vmathT3MakeFromCols( &b_Transform3, &d_Vector3, &a_Vector3, &b_Vector3, &c_Vector3 );
    vmathT3Prints( &a_Transform3, "set Transform3 columns" );
    vmathT3Prints( &b_Transform3, "set Transform3 columns" );
    vmathM4Add( &tmpM4_0, &a_Matrix4, &b_Matrix4 );
    vmathM4Prints( &tmpM4_0, "Matrix4 + Matrix4" );
    vmathM4Sub( &tmpM4_1, &a_Matrix4, &b_Matrix4 );
    vmathM4Prints( &tmpM4_1, "Matrix4 - Matrix4" );
    vmathM4Neg( &tmpM4_2, &a_Matrix4 );
    vmathM4Prints( &tmpM4_2, "-Matrix4" );
    vmathM4ScalarMul( &tmpM4_3, &a_Matrix4, randfloat() );
    vmathM4Prints( &tmpM4_3, "Matrix4 * float" );
    vmathM4ScalarMul( &tmpM4_4, &a_Matrix4, randfloat() );
    vmathM4Prints( &tmpM4_4, "float * Matrix4" );
    vmathM4MulV4( &tmpV4_0, &a_Matrix4, &a_Vector4 );
    vmathV4Prints( &tmpV4_0, "Matrix4 * Vector4" );
    vmathM4MulV3( &tmpV4_1, &a_Matrix4, &a_Vector3 );
    vmathV4Prints( &tmpV4_1, "Matrix4 * Vector3" );
    vmathM4MulP3( &tmpV4_2, &a_Matrix4, &a_Point3 );
    vmathV4Prints( &tmpV4_2, "Matrix4 * Point3" );
    vmathM4Mul( &tmpM4_5, &a_Matrix4, &b_Matrix4 );
    vmathM4Prints( &tmpM4_5, "Matrix4 * Matrix4" );
    vmathM4MulT3( &tmpM4_6, &a_Matrix4, &b_Transform3 );
    vmathM4Prints( &tmpM4_6, "Matrix4 * Transform3" );
}

void
Transform3_methods_test()
{
    VmathMatrix3 a_Matrix3, b_Matrix3;
    VmathMatrix4 a_Matrix4, b_Matrix4;
    VmathTransform3 a_Transform3, b_Transform3, tmpT3_0;
    VmathVector3 a_Vector3, b_Vector3, c_Vector3, d_Vector3;
    VmathVector4 a_Vector4, b_Vector4, c_Vector4, d_Vector4;
    VmathPoint3 a_Point3, b_Point3, c_Point3, d_Point3;
    VmathQuat a_Quat, b_Quat, c_Quat, d_Quat;
    VmathVector4 tmpV4;
    VmathVector3 tmpV3_0, tmpV3_1, tmpV3_2, tmpV3_3, tmpV3_4, tmpV3_5, tmpV3_6, tmpV3_7, tmpV3_8;
    VmathPoint3 tmpP3_0;
    float rndflt1, rndflt2, rndflt3, rndflt4, rndflt5, rndflt6, pad;
    // set a pad value to detect invalid use of padding.
    // this will be nan for scalar/ppu implementations, max. float for spu
    union { float f; unsigned int u; } tmp;
    tmp.u = 0x7fffffff;
    pad = tmp.f;
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathV3MakeFromElems( &a_Vector3, rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathV3MakeFromElems( &b_Vector3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathV3MakeFromElems( &c_Vector3, rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathV3MakeFromElems( &d_Vector3, rndflt1, rndflt2, rndflt3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &a_Vector3, pad );
    vmathV4GetXYZ( &a_Vector3, &tmpV4 );
    vmathV4MakeFromV3Scalar( &tmpV4, &b_Vector3, pad );
    vmathV4GetXYZ( &b_Vector3, &tmpV4 );
    vmathV4MakeFromV3Scalar( &tmpV4, &c_Vector3, pad );
    vmathV4GetXYZ( &c_Vector3, &tmpV4 );
    vmathV4MakeFromV3Scalar( &tmpV4, &d_Vector3, pad );
    vmathV4GetXYZ( &d_Vector3, &tmpV4 );
    vmathV3Prints( &a_Vector3, "set Vector3 with floats" );
    vmathV3Prints( &b_Vector3, "set Vector3 with floats" );
    vmathV3Prints( &c_Vector3, "set Vector3 with floats" );
    vmathV3Prints( &d_Vector3, "set Vector3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathV4MakeFromElems( &a_Vector4, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathV4MakeFromElems( &b_Vector4, rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathV4MakeFromElems( &c_Vector4, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathV4MakeFromElems( &d_Vector4, rndflt1, rndflt2, rndflt3, rndflt4 );
    vmathV4Prints( &a_Vector4, "set Vector4 with floats" );
    vmathV4Prints( &b_Vector4, "set Vector4 with floats" );
    vmathV4Prints( &c_Vector4, "set Vector4 with floats" );
    vmathV4Prints( &d_Vector4, "set Vector4 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathP3MakeFromElems( &a_Point3, rndflt1, rndflt2, rndflt3 );
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathP3MakeFromElems( &b_Point3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathP3MakeFromElems( &c_Point3, rndflt1, rndflt2, rndflt3 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    vmathP3MakeFromElems( &d_Point3, rndflt1, rndflt2, rndflt3 );
    vmathV3MakeFromP3( &tmpV3_0, &a_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_0, pad );
    vmathV4GetXYZ( &tmpV3_1, &tmpV4 );
    vmathP3MakeFromV3( &a_Point3, &tmpV3_1 );
    vmathV3MakeFromP3( &tmpV3_2, &b_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_2, pad );
    vmathV4GetXYZ( &tmpV3_3, &tmpV4 );
    vmathP3MakeFromV3( &b_Point3, &tmpV3_3 );
    vmathV3MakeFromP3( &tmpV3_4, &c_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_4, pad );
    vmathV4GetXYZ( &tmpV3_5, &tmpV4 );
    vmathP3MakeFromV3( &c_Point3, &tmpV3_5 );
    vmathV3MakeFromP3( &tmpV3_6, &d_Point3 );
    vmathV4MakeFromV3Scalar( &tmpV4, &tmpV3_6, pad );
    vmathV4GetXYZ( &tmpV3_7, &tmpV4 );
    vmathP3MakeFromV3( &d_Point3, &tmpV3_7 );
    vmathP3Prints( &a_Point3, "set Point3 with floats" );
    vmathP3Prints( &b_Point3, "set Point3 with floats" );
    vmathP3Prints( &c_Point3, "set Point3 with floats" );
    vmathP3Prints( &d_Point3, "set Point3 with floats" );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathQMakeFromElems( &a_Quat, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    rndflt5 = randfloat();
    rndflt6 = randfloat();
    vmathQMakeFromElems( &b_Quat, rndflt3, rndflt4, rndflt5, rndflt6 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathQMakeFromElems( &c_Quat, rndflt1, rndflt2, rndflt3, rndflt4 );
    rndflt1 = randfloat();
    rndflt2 = randfloat();
    rndflt3 = randfloat();
    rndflt4 = randfloat();
    vmathQMakeFromElems( &d_Quat, rndflt1, rndflt2, rndflt3, rndflt4 );
    vmathQPrints( &a_Quat, "set Quat with floats" );
    vmathQPrints( &b_Quat, "set Quat with floats" );
    vmathQPrints( &c_Quat, "set Quat with floats" );
    vmathQPrints( &d_Quat, "set Quat with floats" );
    vmathM3MakeFromCols( &a_Matrix3, &a_Vector3, &b_Vector3, &c_Vector3 );
    vmathM3MakeFromCols( &b_Matrix3, &d_Vector3, &a_Vector3, &b_Vector3 );
    vmathM3Prints( &a_Matrix3, "set Matrix3 columns" );
    vmathM3Prints( &b_Matrix3, "set Matrix3 columns" );
    vmathM4MakeFromCols( &a_Matrix4, &a_Vector4, &b_Vector4, &c_Vector4, &d_Vector4 );
    vmathM4MakeFromCols( &b_Matrix4, &d_Vector4, &a_Vector4, &b_Vector4, &c_Vector4 );
    vmathM4Prints( &a_Matrix4, "set Matrix4 columns" );
    vmathM4Prints( &b_Matrix4, "set Matrix4 columns" );
    vmathT3MakeFromCols( &a_Transform3, &a_Vector3, &b_Vector3, &c_Vector3, &d_Vector3 );
    vmathT3MakeFromCols( &b_Transform3, &d_Vector3, &a_Vector3, &b_Vector3, &c_Vector3 );
    vmathT3Prints( &a_Transform3, "set Transform3 columns" );
    vmathT3Prints( &b_Transform3, "set Transform3 columns" );
    vmathT3MulV3( &tmpV3_8, &a_Transform3, &a_Vector3 );
    vmathV3Prints( &tmpV3_8, "Transform3 * Vector3" );
    vmathT3MulP3( &tmpP3_0, &a_Transform3, &a_Point3 );
    vmathP3Prints( &tmpP3_0, "Transform3 * Point3" );
    vmathT3Mul( &tmpT3_0, &a_Transform3, &b_Transform3 );
    vmathT3Prints( &tmpT3_0, "Transform3 * Transform3" );
}

int main()
{
    int i;
    printf("\n __begin__ \n");
    for ( i = 0; i < 2; i++ ) {
        Matrix3_methods_test();
        Matrix4_methods_test();
        Transform3_methods_test();
    }
    printf("\n __end__ \n");
    return 0;
}
