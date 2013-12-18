#include <assert.h>
#include <math.h>

#include "Vector.h"

Vector2::Vector2(void)
{
  v[0] = 0;
  v[1] = 0;
}

Vector2::Vector2(double x, double y)
{
  v[0] = x;
  v[1] = y;
}

double& Vector2::operator[](int index)
{
  assert(!(index < 0 || index >= 2));

  return v[index];
}

double Vector2::operator[](int index) const
{
  assert(!(index < 0 || index >= 2));

  return v[index];
}

Vector2 Vector2::operator-(void) const
{
  return Vector2(-v[0], -v[1]);
}

Vector2 Vector2::operator+(const Vector2& u) const
{
  return Vector2(v[0] + u[0], v[1] + u[1]);
}

Vector2& Vector2::operator+=(const Vector2& u)
{
  v[0] += u[0];
  v[1] += u[1];

  return *this;
}

Vector2 Vector2::operator-(const Vector2& u) const
{
  return Vector2(v[0] - u[0], v[1] - u[1]);
}

Vector2& Vector2::operator-=(const Vector2& u)
{
  v[0] -= u[0];
  v[1] -= u[1];

  return *this;
}

Vector2 Vector2::operator*(double k) const
{
  return Vector2(v[0] * k, v[1] * k);
}

Vector2& Vector2::operator*=(double k)
{
  v[0] *= k;
  v[1] *= k;

  return *this;
}

Vector2 Vector2::operator*(const Vector2& u) const
{
  return Vector2(v[0] * u[0], v[1] * u[1]);
}

Vector2& Vector2::operator*=(const Vector2& u)
{
  v[0] *= u[0];
  v[1] *= u[1];

  return *this;
}

Vector2 Vector2::operator/(double k) const
{
  return Vector2(v[0] / k, v[1] / k);
}

Vector2& Vector2::operator/=(double k)
{
  v[0] /= k;
  v[1] /= k;

  return *this;
}

Vector2 Vector2::operator/(const Vector2& u) const
{
  return Vector2(v[0] / u[0], v[1] / u[1]);
}

Vector2& Vector2::operator/=(const Vector2& u)
{
  v[0] /= u[0];
  v[1] /= u[1];

  return *this;
}

double Vector2::length(void) const
{
  return sqrt(v[0] * v[0] + v[1] * v[1]);
}

Vector2 Vector2::unit(void) const
{
  double l = length();

  return Vector2(v[0] / l, v[1] / l);
}

double Vector2::dot(const Vector2& u) const
{
  return v[0] * u[0] + v[1] * u[1];
}

Vector3::Vector3(void)
{
  v[0] = 0;
  v[1] = 0;
  v[2] = 0;
}

Vector3::Vector3(double x, double y, double z)
{
  v[0] = x;
  v[1] = y;
  v[2] = z;
}

double& Vector3::operator[](int index)
{
  assert(!(index < 0 || index >= 3));

  return v[index];
}

double Vector3::operator[](int index) const
{
  assert(!(index < 0 || index >= 3));

  return v[index];
}

Vector3 Vector3::operator-(void) const
{
  return Vector3(-v[0], -v[1], -v[2]);
}

Vector3 Vector3::operator+(const Vector3& u) const
{
  return Vector3(v[0] + u[0], v[1] + u[1], v[2] + u[2]);
}

Vector3& Vector3::operator+=(const Vector3& u)
{
  v[0] += u[0];
  v[1] += u[1];
  v[2] += u[2];

  return *this;
}

Vector3 Vector3::operator-(const Vector3& u) const
{
  return Vector3(v[0] - u[0], v[1] - u[1], v[2] - u[2]);
}

Vector3& Vector3::operator-=(const Vector3& u)
{
  v[0] -= u[0];
  v[1] -= u[1];
  v[2] -= u[2];

  return *this;
}

Vector3 Vector3::operator*(double k) const
{
  return Vector3(v[0] * k, v[1] * k, v[2] * k);
}

Vector3& Vector3::operator*=(double k)
{
  v[0] *= k;
  v[1] *= k;
  v[2] *= k;

  return *this;
}

Vector3 Vector3::operator*(const Vector3& u) const
{
  return Vector3(v[0] * u[0], v[1] * u[1], v[2] * u[2]);
}

Vector3& Vector3::operator*=(const Vector3& u)
{
  v[0] *= u[0];
  v[1] *= u[1];
  v[2] *= u[2];

  return *this;
}

Vector3 Vector3::operator/(double k) const
{
  return Vector3(v[0] / k, v[1] / k, v[2] / k);
}

Vector3& Vector3::operator/=(double k)
{
  v[0] /= k;
  v[1] /= k;
  v[2] /= k;

  return *this;
}

Vector3 Vector3::operator/(const Vector3& u) const
{
  return Vector3(v[0] / u[0], v[1] / u[1], v[2] / u[2]);
}

Vector3& Vector3::operator/=(const Vector3& u)
{
  v[0] /= u[0];
  v[1] /= u[1];
  v[2] /= u[2];

  return *this;
}

double Vector3::length(void) const
{
  return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

Vector3 Vector3::unit(void) const
{
  double l = length();

  return Vector3(v[0] / l, v[1] / l, v[2] / l);
}

double Vector3::dot(const Vector3& u) const
{
  return v[0] * u[0] + v[1] * u[1] + v[2] * u[2];
}

Vector3 Vector3::cross(const Vector3& u) const
{
  return Vector3(v[1] * u[2] - v[2] * u[1],
                 v[2] * u[0] - v[0] * u[2],
                 v[0] * u[1] - v[1] * u[0]);
}

