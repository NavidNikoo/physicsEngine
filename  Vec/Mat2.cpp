//
// Created by Navid Nikoo on 5/8/24.
//

#include "Mat2.h"

inline Mat2::Mat2( const Mat2 &rhs ) {
    rows[ 0 ] = rhs.rows[ 0 ];
    rows[ 1 ] = rhs.rows[ 1 ];
}

inline Mat2::Mat2( const float *mat ) {
    rows[ 0 ] = mat + 0;
    rows[ 1 ] = mat + 2;
}

inline Mat2::Mat2( const Vec2 &row0, const Vec2 &row1 ) {
    rows[ 0 ] = row0;
    rows[ 1 ] = row1;
}

inline Mat2& Mat2::operator=(const Mat2 &rhs) {
    rows[ 0 ] = rhs.rows[ 0 ];
    rows[ 1 ] = rhs.rows[ 1 ];
    return *this;
}

inline const Mat2 &Mat2::operator*=( const float rhs ) {
    rows[ 0 ] *= rhs;
    rows[ 1 ] *= rhs;
    return *this;
}

const Mat2 &Mat2::operator+=(const Mat2 &rhs) {
    rows[ 0 ] += rhs.rows[ 0 ];
    rows[ 1 ] += rhs.rows[ 1 ];
    return *this;
}
