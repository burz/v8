#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "Matrix.h"

Matrix3::Matrix3(void)
{
  m[0][0] = 0;
  m[0][1] = 0;
  m[0][2] = 0;
  m[1][0] = 0;
  m[1][1] = 0;
  m[1][2] = 0;
  m[2][0] = 0;
  m[2][1] = 0;
  m[2][2] = 0;
}

Matrix3 Matrix3::Identity(void)
{
  Matrix3 result;

  result(0, 0) = 1;
  result(1, 1) = 1;
  result(2, 2) = 1;

  return result;
}

double& Matrix3::operator()(int x, int y)
{
  assert(!(x < 0 || x >= 3 || y < 0 || y >= 3));

  return m[x][y];
}

double Matrix3::operator()(int x, int y) const
{
  assert(!(x < 0 || x >= 3 || y < 0 || y >= 3));

  return m[x][y];
}

Matrix3 Matrix3::operator-(void) const
{
  Matrix3 result;

  result(0, 0) = -m[0][0];
  result(0, 1) = -m[0][1];
  result(0, 2) = -m[0][2];
  result(1, 0) = -m[1][0];
  result(1, 1) = -m[1][1];
  result(1, 2) = -m[1][2];
  result(2, 0) = -m[2][0];
  result(2, 1) = -m[2][1];
  result(2, 2) = -m[2][2];

  return result;
}

Matrix3 Matrix3::operator+(const Matrix3& n) const
{
  Matrix3 result;

  result(0, 0) = m[0][0] + n(0, 0);
  result(0, 1) = m[0][1] + n(0, 1);
  result(0, 2) = m[0][2] + n(0, 2);
  result(1, 0) = m[1][0] + n(1, 0);
  result(1, 1) = m[1][1] + n(1, 1);
  result(1, 2) = m[1][2] + n(1, 2);
  result(2, 0) = m[2][0] + n(2, 0);
  result(2, 1) = m[2][1] + n(2, 1);
  result(2, 2) = m[2][2] + n(2, 2);

  return result;
}

Matrix3& Matrix3::operator+=(const Matrix3& n)
{
  m[0][0] += n(0, 0);
  m[0][1] += n(0, 1);
  m[0][2] += n(0, 2);
  m[1][0] += n(1, 0);
  m[1][1] += n(1, 1);
  m[1][2] += n(1, 2);
  m[2][0] += n(2, 0);
  m[2][1] += n(2, 1);
  m[2][2] += n(2, 2);

  return *this;
}

Matrix3 Matrix3::operator-(const Matrix3& n) const
{
  Matrix3 result;

  result(0, 0) = m[0][0] - n(0, 0);
  result(0, 1) = m[0][1] - n(0, 1);
  result(0, 2) = m[0][2] - n(0, 2);
  result(1, 0) = m[1][0] - n(1, 0);
  result(1, 1) = m[1][1] - n(1, 1);
  result(1, 2) = m[1][2] - n(1, 2);
  result(2, 0) = m[2][0] - n(2, 0);
  result(2, 1) = m[2][1] - n(2, 1);
  result(2, 2) = m[2][2] - n(2, 2);

  return result;
}

Matrix3& Matrix3::operator-=(const Matrix3& n)
{
  m[0][0] -= n(0, 0);
  m[0][1] -= n(0, 1);
  m[0][2] -= n(0, 2);
  m[1][0] -= n(1, 0);
  m[1][1] -= n(1, 1);
  m[1][2] -= n(1, 2);
  m[2][0] -= n(2, 0);
  m[2][1] -= n(2, 1);
  m[2][2] -= n(2, 2);

  return *this;
}

Matrix3 Matrix3::operator*(double k) const
{
  Matrix3 result;

  result(0, 0) = m[0][0] * k;
  result(0, 1) = m[0][1] * k;
  result(0, 2) = m[0][2] * k;
  result(1, 0) = m[1][0] * k;
  result(1, 1) = m[1][1] * k;
  result(1, 2) = m[1][2] * k;
  result(2, 0) = m[2][0] * k;
  result(2, 1) = m[2][1] * k;
  result(2, 2) = m[2][2] * k;

  return result;
}

Matrix3& Matrix3::operator*=(double k)
{
  m[0][0] *= k;
  m[0][1] *= k;
  m[0][2] *= k;
  m[1][0] *= k;
  m[1][1] *= k;
  m[1][2] *= k;
  m[2][0] *= k;
  m[2][1] *= k;
  m[2][2] *= k;

  return *this;
}

Vector3 Matrix3::operator*(const Vector3& v) const
{
  Vector3 result;

  result[0] = m[0][0] * v[0] + m[0][1] * v[1] + m[0][2]  * v[2];
  result[1] = m[1][0] * v[0] + m[1][1] * v[1] + m[1][2]  * v[2];
  result[2] = m[2][0] * v[0] + m[2][1] * v[1] + m[2][2]  * v[2];

  return result;
}

Matrix3 Matrix3::operator*(const Matrix3& n) const
{
  Matrix3 result;

  result(0, 0) = m[0][0] * n(0, 0) + m[1][0] * n(0, 1) + m[2][0] * n(0, 2);
  result(0, 1) = m[0][1] * n(1, 0) + m[1][1] * n(1, 1) + m[2][1] * n(1, 2);
  result(0, 2) = m[0][2] * n(2, 0) + m[1][2] * n(2, 1) + m[2][2] * n(2, 2);
  result(1, 0) = m[0][0] * n(0, 0) + m[1][0] * n(0, 1) + m[2][0] * n(0, 2);
  result(1, 1) = m[0][1] * n(1, 0) + m[1][1] * n(1, 1) + m[2][1] * n(1, 2);
  result(1, 2) = m[0][2] * n(2, 0) + m[1][2] * n(2, 1) + m[2][2] * n(2, 2);
  result(2, 0) = m[0][0] * n(0, 0) + m[1][0] * n(0, 1) + m[2][0] * n(0, 2);
  result(2, 1) = m[0][1] * n(1, 0) + m[1][1] * n(1, 1) + m[2][1] * n(1, 2);
  result(2, 2) = m[0][2] * n(2, 0) + m[1][2] * n(2, 1) + m[2][2] * n(2, 2);

  return result;
}

Matrix3& Matrix3::operator*=(const Matrix3& n)
{
  m[0][0] = m[0][0] * n(0, 0) + m[1][0] * n(0, 1) + m[2][0] * n(0, 2);
  m[0][1] = m[0][1] * n(1, 0) + m[1][1] * n(1, 1) + m[2][1] * n(1, 2);
  m[0][2] = m[0][2] * n(2, 0) + m[1][2] * n(2, 1) + m[2][2] * n(2, 2);
  m[1][0] = m[0][0] * n(0, 0) + m[1][0] * n(0, 1) + m[2][0] * n(0, 2);
  m[1][1] = m[0][1] * n(1, 0) + m[1][1] * n(1, 1) + m[2][1] * n(1, 2);
  m[1][2] = m[0][2] * n(2, 0) + m[1][2] * n(2, 1) + m[2][2] * n(2, 2);
  m[2][0] = m[0][0] * n(0, 0) + m[1][0] * n(0, 1) + m[2][0] * n(0, 2);
  m[2][1] = m[0][1] * n(1, 0) + m[1][1] * n(1, 1) + m[2][1] * n(1, 2);
  m[2][2] = m[0][2] * n(2, 0) + m[1][2] * n(2, 1) + m[2][2] * n(2, 2);

  return *this;
}

Matrix3 Matrix3::operator/(double k) const
{
  Matrix3 result;

  result(0, 0) = m[0][0] / k;
  result(0, 1) = m[0][1] / k;
  result(0, 2) = m[0][2] / k;
  result(1, 0) = m[1][0] / k;
  result(1, 1) = m[1][1] / k;
  result(1, 2) = m[1][2] / k;
  result(2, 0) = m[2][0] / k;
  result(2, 1) = m[2][1] / k;
  result(2, 2) = m[2][2] / k;

  return result;
}

Matrix3& Matrix3::operator/=(double k)
{
  m[0][0] /= k;
  m[0][1] /= k;
  m[0][2] /= k;
  m[1][0] /= k;
  m[1][1] /= k;
  m[1][2] /= k;
  m[2][0] /= k;
  m[2][1] /= k;
  m[2][2] /= k;

  return *this;
}

double Matrix3::determinant(void) const
{
  return m[0][0] * m[1][1] * m[2][2] +
         m[0][1] * m[1][2] * m[2][0] +
         m[0][2] * m[1][0] * m[2][1] -
         m[0][2] * m[1][1] * m[2][0] -
         m[0][1] * m[1][0] * m[2][2] -
         m[0][0] * m[1][2] * m[2][1];
}

Matrix3 Matrix3::transpose(void) const
{
  Matrix3 result;

  result(0, 0) = m[0][0];
  result(0, 1) = m[1][0];
  result(0, 2) = m[2][0];
  result(1, 0) = m[0][1];
  result(1, 1) = m[1][1];
  result(1, 2) = m[2][1];
  result(2, 0) = m[0][2];
  result(2, 1) = m[1][2];
  result(2, 2) = m[2][2];

  return result;
}

Matrix3 Matrix3::invert(void) const
{
  double det = determinant();

  assert(det != 0);

  Matrix3 result;

  result(0, 0) = (m[1][1] * m[1][2] - m[2][1] * m[2][2]) / det;
  result(0, 1) = (m[0][2] * m[0][1] - m[2][2] * m[2][1]) / det;
  result(0, 2) = (m[0][1] * m[0][2] - m[1][1] * m[1][2]) / det;
  result(1, 0) = (m[1][2] * m[1][0] - m[2][2] * m[2][0]) / det;
  result(1, 1) = (m[0][0] * m[0][2] - m[2][0] * m[2][2]) / det;
  result(1, 2) = (m[0][2] * m[0][0] - m[1][2] * m[1][0]) / det;
  result(2, 0) = (m[1][0] * m[1][1] - m[2][0] * m[2][1]) / det;
  result(2, 1) = (m[0][1] * m[0][0] - m[2][1] * m[2][0]) / det;
  result(2, 2) = (m[0][0] * m[0][1] - m[1][0] * m[1][1]) / det;

  return result;
}

void Matrix3::print(void) const
{
  for(int x = 0; x < 3; x++)
    printf("[ %f, %f, %f ]\n", m[x][0], m[x][1], m[x][2]);
}

Matrix4::Matrix4(void)
{
  m[0][0] = 0;
  m[0][1] = 0;
  m[0][2] = 0;
  m[0][3] = 0;
  m[1][0] = 0;
  m[1][1] = 0;
  m[1][2] = 0;
  m[1][3] = 0;
  m[2][0] = 0;
  m[2][1] = 0;
  m[2][2] = 0;
  m[2][3] = 0;
  m[3][0] = 0;
  m[3][1] = 0;
  m[3][2] = 0;
  m[3][3] = 0;
}

Matrix4 Matrix4::Identity(void)
{
  Matrix4 result;

  result(0, 0) = 1;
  result(1, 1) = 1;
  result(2, 2) = 1;
  result(3, 3) = 1;

  return result;
}

double& Matrix4::operator()(int x, int y)
{
  assert(!(x < 0 || x >= 4 || y < 0 || y >= 4));

  return m[x][y];
}

double Matrix4::operator()(int x, int y) const
{
  assert(!(x < 0 || x >= 4 || y < 0 || y >= 4));

  return m[x][y];
}

Matrix4 Matrix4::operator-(void) const
{
  Matrix4 result;

  result(0, 0) = -m[0][0];
  result(0, 1) = -m[0][1];
  result(0, 2) = -m[0][2];
  result(0, 3) = -m[0][3];
  result(1, 0) = -m[1][0];
  result(1, 1) = -m[1][1];
  result(1, 2) = -m[1][2];
  result(1, 3) = -m[1][3];
  result(2, 0) = -m[2][0];
  result(2, 1) = -m[2][1];
  result(2, 2) = -m[2][2];
  result(2, 3) = -m[2][3];
  result(3, 0) = -m[3][0];
  result(3, 1) = -m[3][1];
  result(3, 2) = -m[3][2];
  result(3, 3) = -m[3][3];

  return result;
}

Matrix4 Matrix4::operator+(const Matrix4& n) const
{
  Matrix4 result;

  result(0, 0) = m[0][0] + n(0, 0);
  result(0, 1) = m[0][1] + n(0, 1);
  result(0, 2) = m[0][2] + n(0, 2);
  result(0, 3) = m[0][3] + n(0, 3);
  result(1, 0) = m[1][0] + n(1, 0);
  result(1, 1) = m[1][1] + n(1, 1);
  result(1, 2) = m[1][2] + n(1, 2);
  result(1, 3) = m[1][3] + n(1, 3);
  result(2, 0) = m[2][0] + n(2, 0);
  result(2, 1) = m[2][1] + n(2, 1);
  result(2, 2) = m[2][2] + n(2, 2);
  result(2, 3) = m[2][3] + n(2, 3);
  result(3, 0) = m[3][0] + n(3, 0);
  result(3, 1) = m[3][1] + n(3, 1);
  result(3, 2) = m[3][2] + n(3, 2);
  result(3, 3) = m[3][3] + n(3, 3);

  return result;
}

Matrix4& Matrix4::operator+=(const Matrix4& n)
{
  m[0][0] += n(0, 0);
  m[0][1] += n(0, 1);
  m[0][2] += n(0, 2);
  m[0][3] += n(0, 3);
  m[1][0] += n(1, 0);
  m[1][1] += n(1, 1);
  m[1][2] += n(1, 2);
  m[1][3] += n(1, 3);
  m[2][0] += n(2, 0);
  m[2][1] += n(2, 1);
  m[2][2] += n(2, 2);
  m[2][3] += n(2, 3);
  m[3][0] += n(3, 0);
  m[3][1] += n(3, 1);
  m[3][2] += n(3, 2);
  m[3][3] += n(3, 3);

  return *this;
}

Matrix4 Matrix4::operator-(const Matrix4& n) const
{
  Matrix4 result;

  result(0, 0) = m[0][0] - n(0, 0);
  result(0, 1) = m[0][1] - n(0, 1);
  result(0, 2) = m[0][2] - n(0, 2);
  result(0, 3) = m[0][3] - n(0, 3);
  result(1, 0) = m[1][0] - n(1, 0);
  result(1, 1) = m[1][1] - n(1, 1);
  result(1, 2) = m[1][2] - n(1, 2);
  result(1, 3) = m[1][3] - n(1, 3);
  result(2, 0) = m[2][0] - n(2, 0);
  result(2, 1) = m[2][1] - n(2, 1);
  result(2, 2) = m[2][2] - n(2, 2);
  result(2, 3) = m[2][3] - n(2, 3);
  result(3, 0) = m[3][0] - n(3, 0);
  result(3, 1) = m[3][1] - n(3, 1);
  result(3, 2) = m[3][2] - n(3, 2);
  result(3, 3) = m[3][3] - n(3, 3);

  return result;
}

Matrix4& Matrix4::operator-=(const Matrix4& n)
{
  m[0][0] -= n(0, 0);
  m[0][1] -= n(0, 1);
  m[0][2] -= n(0, 2);
  m[0][3] -= n(0, 3);
  m[1][0] -= n(1, 0);
  m[1][1] -= n(1, 1);
  m[1][2] -= n(1, 2);
  m[1][3] -= n(1, 3);
  m[2][0] -= n(2, 0);
  m[2][1] -= n(2, 1);
  m[2][2] -= n(2, 2);
  m[2][3] -= n(2, 3);
  m[3][0] -= n(3, 0);
  m[3][1] -= n(3, 1);
  m[3][2] -= n(3, 2);
  m[3][3] -= n(3, 3);

  return *this;
}

Matrix4 Matrix4::operator*(double k) const
{
  Matrix4 result;

  result(0, 0) = m[0][0] * k;
  result(0, 1) = m[0][1] * k;
  result(0, 2) = m[0][2] * k;
  result(0, 3) = m[0][3] * k;
  result(1, 0) = m[1][0] * k;
  result(1, 1) = m[1][1] * k;
  result(1, 2) = m[1][2] * k;
  result(1, 3) = m[1][3] * k;
  result(2, 0) = m[2][0] * k;
  result(2, 1) = m[2][1] * k;
  result(2, 2) = m[2][2] * k;
  result(2, 3) = m[2][3] * k;
  result(3, 0) = m[3][0] * k;
  result(3, 1) = m[3][1] * k;
  result(3, 2) = m[3][2] * k;
  result(3, 3) = m[3][3] * k;

  return result;
}

Matrix4& Matrix4::operator*=(double k)
{
  m[0][0] *= k;
  m[0][1] *= k;
  m[0][2] *= k;
  m[0][3] *= k;
  m[1][0] *= k;
  m[1][1] *= k;
  m[1][2] *= k;
  m[1][3] *= k;
  m[2][0] *= k;
  m[2][1] *= k;
  m[2][2] *= k;
  m[2][3] *= k;
  m[3][0] *= k;
  m[3][1] *= k;
  m[3][2] *= k;
  m[3][3] *= k;

  return *this;
}

Matrix4 Matrix4::operator*(const Matrix4& n) const
{
  Matrix4 r;

  r(0, 0) = m[0][0] * n(0, 0) + m[1][0] * n(0, 1) + m[2][0] * n(0, 2) + m[3][0] * n(0, 3);
  r(0, 1) = m[0][1] * n(0, 0) + m[1][1] * n(0, 1) + m[2][1] * n(0, 2) + m[3][1] * n(0, 3);
  r(0, 2) = m[0][2] * n(0, 0) + m[1][2] * n(0, 1) + m[2][2] * n(0, 2) + m[3][2] * n(0, 3);
  r(0, 3) = m[0][3] * n(0, 0) + m[1][3] * n(0, 1) + m[2][3] * n(0, 2) + m[3][3] * n(0, 3);
  r(1, 0) = m[0][0] * n(1, 0) + m[1][0] * n(1, 1) + m[2][0] * n(1, 2) + m[3][0] * n(1, 3);
  r(1, 1) = m[0][1] * n(1, 0) + m[1][1] * n(1, 1) + m[2][1] * n(1, 2) + m[3][1] * n(1, 3);
  r(1, 2) = m[0][2] * n(1, 0) + m[1][2] * n(1, 1) + m[2][2] * n(1, 2) + m[3][2] * n(1, 3);
  r(1, 3) = m[0][3] * n(1, 0) + m[1][3] * n(1, 1) + m[2][3] * n(1, 2) + m[3][3] * n(1, 3);
  r(2, 0) = m[0][0] * n(2, 0) + m[1][0] * n(2, 1) + m[2][0] * n(2, 2) + m[3][0] * n(2, 3);
  r(2, 1) = m[0][1] * n(2, 0) + m[1][1] * n(2, 1) + m[2][1] * n(2, 2) + m[3][1] * n(2, 3);
  r(2, 2) = m[0][2] * n(2, 0) + m[1][2] * n(2, 1) + m[2][2] * n(2, 2) + m[3][2] * n(2, 3);
  r(2, 3) = m[0][3] * n(2, 0) + m[1][3] * n(2, 1) + m[2][3] * n(2, 2) + m[3][3] * n(2, 3);
  r(3, 0) = m[0][0] * n(3, 0) + m[1][0] * n(3, 1) + m[2][0] * n(3, 2) + m[3][0] * n(3, 3);
  r(3, 1) = m[0][1] * n(3, 0) + m[1][1] * n(3, 1) + m[2][1] * n(3, 2) + m[3][1] * n(3, 3);
  r(3, 2) = m[0][2] * n(3, 0) + m[1][2] * n(3, 1) + m[2][2] * n(3, 2) + m[3][2] * n(3, 3);
  r(3, 3) = m[0][3] * n(3, 0) + m[1][3] * n(3, 1) + m[2][3] * n(3, 2) + m[3][3] * n(3, 3);

  return r;
}

Matrix4& Matrix4::operator*=(const Matrix4& n)
{
  m[0][0] = m[0][0] * n(0, 0) + m[1][0] * n(0, 1) + m[2][0] * n(0, 2) + m[3][0] * n(0, 3);
  m[0][1] = m[0][1] * n(0, 0) + m[1][1] * n(0, 1) + m[2][1] * n(0, 2) + m[3][1] * n(0, 3);
  m[0][2] = m[0][2] * n(0, 0) + m[1][2] * n(0, 1) + m[2][2] * n(0, 2) + m[3][2] * n(0, 3);
  m[0][3] = m[0][3] * n(0, 0) + m[1][3] * n(0, 1) + m[2][3] * n(0, 2) + m[3][3] * n(0, 3);
  m[1][0] = m[0][0] * n(1, 0) + m[1][0] * n(1, 1) + m[2][0] * n(1, 2) + m[3][0] * n(1, 3);
  m[1][1] = m[0][1] * n(1, 0) + m[1][1] * n(1, 1) + m[2][1] * n(1, 2) + m[3][1] * n(1, 3);
  m[1][2] = m[0][2] * n(1, 0) + m[1][2] * n(1, 1) + m[2][2] * n(1, 2) + m[3][2] * n(1, 3);
  m[1][3] = m[0][3] * n(1, 0) + m[1][3] * n(1, 1) + m[2][3] * n(1, 2) + m[3][3] * n(1, 3);
  m[2][0] = m[0][0] * n(2, 0) + m[1][0] * n(2, 1) + m[2][0] * n(2, 2) + m[3][0] * n(2, 3);
  m[2][1] = m[0][1] * n(2, 0) + m[1][1] * n(2, 1) + m[2][1] * n(2, 2) + m[3][1] * n(2, 3);
  m[2][2] = m[0][2] * n(2, 0) + m[1][2] * n(2, 1) + m[2][2] * n(2, 2) + m[3][2] * n(2, 3);
  m[2][3] = m[0][3] * n(2, 0) + m[1][3] * n(2, 1) + m[2][3] * n(2, 2) + m[3][3] * n(2, 3);
  m[3][0] = m[0][0] * n(3, 0) + m[1][0] * n(3, 1) + m[2][0] * n(3, 2) + m[3][0] * n(3, 3);
  m[3][1] = m[0][1] * n(3, 0) + m[1][1] * n(3, 1) + m[2][1] * n(3, 2) + m[3][1] * n(3, 3);
  m[3][2] = m[0][2] * n(3, 0) + m[1][2] * n(3, 1) + m[2][2] * n(3, 2) + m[3][2] * n(3, 3);
  m[3][3] = m[0][3] * n(3, 0) + m[1][3] * n(3, 1) + m[2][3] * n(3, 2) + m[3][3] * n(3, 3);

  return *this;
}

Matrix4 Matrix4::operator/(double k) const
{
  Matrix4 result;

  result(0, 0) = m[0][0] / k;
  result(0, 1) = m[0][1] / k;
  result(0, 2) = m[0][2] / k;
  result(0, 3) = m[0][3] / k;
  result(1, 0) = m[1][0] / k;
  result(1, 1) = m[1][1] / k;
  result(1, 2) = m[1][2] / k;
  result(1, 3) = m[1][3] / k;
  result(2, 0) = m[2][0] / k;
  result(2, 1) = m[2][1] / k;
  result(2, 2) = m[2][2] / k;
  result(2, 3) = m[2][3] / k;
  result(3, 0) = m[3][0] / k;
  result(3, 1) = m[3][1] / k;
  result(3, 2) = m[3][2] / k;
  result(3, 3) = m[3][3] / k;

  return result;
}

Matrix4& Matrix4::operator/=(double k)
{
  m[0][0] /= k;
  m[0][1] /= k;
  m[0][2] /= k;
  m[0][3] /= k;
  m[1][0] /= k;
  m[1][1] /= k;
  m[1][2] /= k;
  m[1][3] /= k;
  m[2][0] /= k;
  m[2][1] /= k;
  m[2][2] /= k;
  m[2][3] /= k;
  m[3][0] /= k;
  m[3][1] /= k;
  m[3][2] /= k;
  m[3][3] /= k;

  return *this;
}

Matrix3 Matrix4::submatrix(int x, int y) const
{
  Matrix3 result;

  int x_prime = -1;
  int y_prime;

  for(int i = 0; i < 4; i++) {
    if(i == x)
      continue;

    x_prime++;
    y_prime = -1;

    for(int j = 0; j < 4; j++) {
      if(j == y)
        continue;

      y_prime++;

      result(x_prime, y_prime) = m[i][j];
    }
  }

  return result;
}

double Matrix4::subdeterminant(int x, int y) const
{
  return submatrix(x, y).determinant();
}

double Matrix4::determinant(void) const
{
  double result = 0;

  if(m[0][0] != 0)
    result += m[0][0] * subdeterminant(0, 0);
  if(m[0][1] != 0)
    result -= m[0][1] * subdeterminant(0, 1);
  if(m[0][2] != 0)
    result += m[0][2] * subdeterminant(0, 2);
  if(m[0][3] != 0)
    result -= m[0][3] * subdeterminant(0, 3);

  return result;
}

Matrix4 Matrix4::transpose(void) const
{
  Matrix4 result;

  result(0, 0) = m[0][0];
  result(0, 1) = m[1][0];
  result(0, 2) = m[2][0];
  result(0, 3) = m[3][0];
  result(1, 0) = m[0][1];
  result(1, 1) = m[1][1];
  result(1, 2) = m[2][1];
  result(1, 3) = m[3][1];
  result(2, 0) = m[0][2];
  result(2, 1) = m[1][2];
  result(2, 2) = m[2][2];
  result(2, 3) = m[3][2];
  result(3, 0) = m[0][3];
  result(3, 1) = m[1][3];
  result(3, 2) = m[2][3];
  result(3, 3) = m[3][3];

  return result;
}

Matrix4 Matrix4::invert(void) const
{
  Matrix4 result;

  double det = determinant();

  assert(det != 0);

  result(0, 0) = subdeterminant(0, 0) / det;
  result(0, 1) = subdeterminant(0, 1) / det;
  result(0, 2) = subdeterminant(0, 2) / det;
  result(0, 3) = subdeterminant(0, 3) / det;
  result(1, 0) = subdeterminant(1, 0) / det;
  result(1, 1) = subdeterminant(1, 1) / det;
  result(1, 2) = subdeterminant(1, 2) / det;
  result(1, 3) = subdeterminant(1, 3) / det;
  result(2, 0) = subdeterminant(2, 0) / det;
  result(2, 1) = subdeterminant(2, 1) / det;
  result(2, 2) = subdeterminant(2, 2) / det;
  result(2, 3) = subdeterminant(2, 3) / det;
  result(3, 0) = subdeterminant(3, 0) / det;
  result(3, 1) = subdeterminant(3, 1) / det;
  result(3, 2) = subdeterminant(3, 2) / det;
  result(3, 3) = subdeterminant(3, 3) / det;

  return result;
}

void Matrix4::print(void) const
{
  for(int x = 0; x < 4; x++)
    printf("[ %f, %f, %f, %f ]\n", m[x][0], m[x][1], m[x][2], m[x][3]);
}

