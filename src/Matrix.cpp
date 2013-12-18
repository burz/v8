#include <assert.h>
#include <math.h>

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

  result(0, 0) = m[0][0] * n(0, 0) + m[0][1] * n(1, 0) + m[0][2] * n(2, 0);
  result(0, 1) = m[1][0] * n(0, 1) + m[1][1] * n(1, 1) + m[1][2] * n(2, 1);
  result(0, 2) = m[2][0] * n(0, 2) + m[2][1] * n(1, 2) + m[2][2] * n(2, 2);
  result(1, 0) = m[0][0] * n(0, 0) + m[0][1] * n(1, 0) + m[0][2] * n(2, 0);
  result(1, 1) = m[1][0] * n(0, 1) + m[1][1] * n(1, 1) + m[1][2] * n(2, 1);
  result(1, 2) = m[2][0] * n(0, 2) + m[2][1] * n(1, 2) + m[2][2] * n(2, 2);
  result(2, 0) = m[0][0] * n(0, 0) + m[0][1] * n(1, 0) + m[0][2] * n(2, 0);
  result(2, 1) = m[1][0] * n(0, 1) + m[1][1] * n(1, 1) + m[1][2] * n(2, 1);
  result(2, 2) = m[2][0] * n(0, 2) + m[2][1] * n(1, 2) + m[2][2] * n(2, 2);

  return result;
}

Matrix3& Matrix3::operator*=(const Matrix3& n)
{
  m[0][0] = m[0][0] * n(0, 0) + m[0][1] * n(1, 0) + m[0][2] * n(2, 0);
  m[0][1] = m[1][0] * n(0, 1) + m[1][1] * n(1, 1) + m[1][2] * n(2, 1);
  m[0][2] = m[2][0] * n(0, 2) + m[2][1] * n(1, 2) + m[2][2] * n(2, 2);
  m[1][0] = m[0][0] * n(0, 0) + m[0][1] * n(1, 0) + m[0][2] * n(2, 0);
  m[1][1] = m[1][0] * n(0, 1) + m[1][1] * n(1, 1) + m[1][2] * n(2, 1);
  m[1][2] = m[2][0] * n(0, 2) + m[2][1] * n(1, 2) + m[2][2] * n(2, 2);
  m[2][0] = m[0][0] * n(0, 0) + m[0][1] * n(1, 0) + m[0][2] * n(2, 0);
  m[2][1] = m[1][0] * n(0, 1) + m[1][1] * n(1, 1) + m[1][2] * n(2, 1);
  m[2][2] = m[2][0] * n(0, 2) + m[2][1] * n(1, 2) + m[2][2] * n(2, 2);

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
  return m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[1][0] * m[2][1] * m[0][2] -
         m[0][2] * m[1][1] * m[2][0] - m[1][1] * m[1][0] * m[2][2] - m[0][0] * m[1][2] * m[2][1];
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

