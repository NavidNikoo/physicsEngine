//
// Created by Navid Nikoo on 5/9/24.
//

#ifndef MAT4_H
#define MAT4_H

#include"Vec4.h"
#include"Mat3.h"

class Mat4 {
public:
    Mat4() {}
    Mat4( const Mat4& rhs );
    Mat4( const float *mat );
    Mat4( const Vec4& row0, const Vec4& row1, const Vec4& row2, const Vec4& row3 );
    Mat4& operator=( const Mat4& rhs );
    ~Mat4() {}

    void Zero();
    void Identity();

    //const does not modify the v
    float Trace() const;
    float Determinant() const;
    Mat4 Transpose() const;
    Mat4 Inverse() const;
    Mat3 Minor( const int i, const int j ) const;
    float Cofactor( const int i, const int j ) const;

    void Orient( Vec3 pos, Vec3 fwd, Vec3 up );
    void LookAt( Vec3 pos, Vec3 lookAt, Vec3 up );
    void PerspectiveOpenGL( float fovy, float aspect_ratio, float near, float far );
    void PerspectiveVulkan( float fovy, float aspect_ratio, float near, float far );
    void OrthoOpenGL( float xmin, float xmax, float ymin, float ymax, float znear, float zfar );
    void OrthoVulkan( float xmin, float xmax, float ymin, float ymax, float znear, float zfar );

    const float * ToPtr() const { return rows[ 0 ].ToPtr(); }
    float * ToPtr() { return rows[ 0 ].ToPtr(); }

    Vec4 operator*( const Vec4& rhs ) const;
    Mat4 operator*( const float rhs ) const;
    Mat4 operator*( const Mat4& rhs ) const;
    const Mat4& operator*=( const float rhs );

public: //variables defined in a class are non static variables
    Vec4 rows[ 4 ];
};

#endif //MAT4_H
