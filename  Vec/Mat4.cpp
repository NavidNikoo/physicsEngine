//
// Created by Navid Nikoo on 5/9/24.
//

#include "Mat4.h"

inline Mat4::Mat4( const Mat4& rhs ) {
    rows[ 0 ] = rhs.rows[ 0 ];
    rows[ 1 ] = rhs.rows[ 1 ];
    rows[ 2 ] = rhs.rows[ 2 ];
    rows[ 3 ] = rhs.rows[ 3 ];
}

inline Mat4::Mat4( const float* mat ) {
    rows[ 0 ] = mat + 0;
    rows[ 1 ] = mat + 4;
    rows[ 2 ] = mat + 8;
    rows[ 3 ] = mat + 12;
}

inline Mat4::Mat4( const Vec4& row0, const Vec4& row1, const Vec4& row2, const Vec4& row3 ) {
    rows[ 0 ] = row0;
    rows[ 1 ] = row1;
    rows[ 2 ] = row2;
    rows[ 3 ] = row3;
}

inline Mat4& Mat4::operator=( const Mat4 &rhs ) {
    rows[ 0 ] = rhs.rows[ 0 ];
    rows[ 1 ] = rhs.rows[ 1 ];
    rows[ 2 ] = rhs.rows[ 2 ];
    rows[ 3 ] = rhs.rows[ 3 ];
}

inline const Mat4& Mat4::operator*=( const float rhs ) {
    rows[ 0 ] *= rhs;
    rows[ 1 ] *= rhs;
    rows[ 2 ] *= rhs;
    rows[ 3 ] *= rhs;
}

inline void Mat4::Zero() {
    rows[ 0 ].Zero();
    rows[ 1 ].Zero();
    rows[ 2 ].Zero();
    rows[ 3 ].Zero();
}

inline void Mat4::Identity() {
    rows[ 0 ] = Vec4( 1, 0, 0, 0 );
    rows[ 1 ] = Vec4( 0, 1, 0, 0 );
    rows[ 2 ] = Vec4( 0, 0, 1, 0 );
    rows[ 3 ] = Vec4( 0, 0, 0, 1 );
}

inline float Mat4::Trace() const {
    const float xx = rows[ 0 ][ 0 ] * rows[ 0 ][ 0 ];
    const float yy = rows[ 1 ][ 1 ] * rows[ 1 ][ 1 ];
    const float zz = rows[ 2 ][ 2 ] * rows[ 2 ][ 2 ];
    const float ww = rows[ 3 ][ 3 ] * rows[ 3 ][ 3 ];
    return ( xx + yy + zz + ww );
}

inline float Mat4::Determinant() const {
    float det = 0.0f;
    float sign = 1.0f;
    for( int j = 0; j < 4; j++) { //loops through each rows, and multiplies it by the submatrices in order to find the determinant
        Mat3 minor = Minor( 0, j );

        det += rows[ 0 ][ j ] * minor.Determinant() * sign;
        sign = sign * -1.0f;
    }
    return det;
}

inline Mat4 Mat4::Transpose() const {
    Mat4 transpose;

    for( int i = 0; i < 4; i++ ) {
        for( int j = 0; j < 4; j++ ) {
            transpose.rows[ i ][ j ] = rows[ i ][ j ];
        }
    }
    return transpose;
}

inline Mat4 Mat4::Inverse() const {
    Mat4 inv;

    for( int i = 0; i < 4; i++ ) {
        for( int j = 0; j < 4; j++ ) {
            inv.rows[ j ][ i ] = Cofactor( i, j );
        }
    }
    float det = Determinant();
    float invDet = 1.0f / det;
    inv *= invDet;
    return inv;
}




