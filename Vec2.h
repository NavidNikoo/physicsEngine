
#ifndef VEC2_H
#define VEC2_H

class Vec2 {
public:
    Vec2();
    Vec2( const float value );
    Vec2( const Vec2 &rhs );
    Vec2( float X, float Y );
    Vec2( const float* xy );

    Vec2 & operator=( const Vec2 &rhs );
    bool operator==( const Vec2 &rhs ) const;
    bool operator!=( const Vec2 &rhs) const;
    Vec2 operator+( const Vec2 &rhs ) const;
    const Vec2& operator+=( const Vec2 &rhs );
    const Vec2& operator-= ( const Vec2 &rhs );
    Vec2 operator-( const Vec2 &rhs ) const;
    Vec2 operator *( const float rhs) const;
    const Vec2& operator *=( const float rhs );
    const Vec2& operator /=( const float rhs);
    float operator[] ( const int idx ) const;
    float& operator [] ( const int idx );

    const Vec2& Normalize();
    float GetMagnitude() const;
    bool IsValid() const;
    float Dot( const Vec2& rhs ) const { return x * rhs.x + y * rhs.y; }
    const float * ToPtr() const { return &x; }

public:
    float x;
    float y;
};

#endif //VEC2_H
