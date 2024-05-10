//
// Created by Navid Nikoo on 5/8/24.
//

#ifndef MAT2_H
#define MAT2_H
#include "Vec2.h"

class Mat2 {
public:
    Mat2() {}
    Mat2( const Mat2& rhs );
    Mat2( const float *mat );
    Mat2( const Vec2& row0, const Vec2& row1 );

    Mat2& operator=( const Mat2 &rhs );
    const Mat2& operator *=( const float rhs );
    const Mat2& operator +=( const Mat2& rhs );
    float Determinant() const { return rows[ 0 ].x * rows[ 1 ].y - rows[ 0 ].y * rows[ 1 ].x; }

public:
    Vec2 rows[ 2 ];
};



#endif //MAT2_H
