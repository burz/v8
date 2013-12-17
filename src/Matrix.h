#pragma once

#include "Vector.h"

class Matrix3
{
  private:
    double m[3][3];
  public:
    Matrix3(void);

    double& operator()(int x, int y);
    Matrix3 operator-(void) const;
    Matrix3 operator+(const Matrix3& n);
    Matrix3 operator+=(const Matrix3& n);
    Matrix3 operator-(const Matrix3& n);
    Matrix3 operator-=(const Matrix3& n);
    Matrix3 operator*(double k) const;
    Matrix3 operator*=(double k) const;
    Vector3 operator*(const Vector3& v);
    Matrix3 operator*(const Matrix3& n);
    Matrix3 operator*=(const Matrix3& n);
    Matrix3 operator/(double k) const;
    Matrix3 operator/=(double k) const;

    Matrix3 transpose(void) const;
    Matrix3 invert(void) const;
};

class Matrix4
{
  private:
    double m[4][4];
  public:
    Matrix4(void);

    double& operator()(int x, int y);
    Matrix4 operator-(void) const;
    Matrix4 operator+(const Matrix4& n);
    Matrix4 operator+=(const Matrix4& n);
    Matrix4 operator-(const Matrix4& n);
    Matrix4 operator-=(const Matrix4& n);
    Matrix4 operator*(double k) const;
    Matrix4 operator*=(double k) const;
    Matrix4 operator*(const Matrix4& n);
    Matrix4 operator*=(const Matrix4& n);
    Matrix4 operator/(double k) const;
    Matrix4 operator/=(double k) const;

    Matrix4 transpose(void) const;
    Matrix4 invert(void) const;
};

