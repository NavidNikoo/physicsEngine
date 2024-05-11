 //
// Created by Navid Nikoo on 5/10/24.
//

#ifndef QUAT_H
#define QUAT_H

#include "Vec3.h"
#include "Vec4.h"
#include "Mat3.h"

class Quat {
public:
    Quat();
    Quat( const Quat& rhs );
    Quat( float X, float Y, float Z, float W );
    Quat( Vec3 n, const float angleRadians );
    const Quat& operator=( const Quat& rhs );

    Quat& operator*=( const float &rhs );
    Quat& operator*=( const Quat& rhs );
    Quat& operator*=( const Quat& &rhs ) const;

    void Normalize();
    void Invert();
    Quat Inverse() const;
    float MagintudeSquared() const;
    float GetMagnitude() const;
    Vec3 RotatePoint( const Vec3& rhs );
    Mat3 RotateMatrix( const Mat3& rhs ) const;
    Vec3 xyz() const { return Vec3( x, y, z); }
    bool IsValid() const;

    Mat3 ToMat3() const;
    Vec4 ToVec4() const { return Vec4( w, x, y, z )};
public:
    float w;
    float x;
    float y;
    float z;
};


#endif //QUAT_H
