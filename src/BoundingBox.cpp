#include "BoundingBox.h"

BoundingBox3::BoundingBox3(void)
{
}

BoundingBox3::BoundingBox3(const Vector3& u, const Vector3& v)
{
  p[0] = Vector3(u[0] < v[0] ? u[0] : v[0],
                 u[1] < v[1] ? u[1] : v[1],
                 u[2] < v[2] ? u[2] : v[2]);
  p[1] = Vector3(u[0] > v[0] ? u[0] : v[0],
                 u[1] > v[1] ? u[1] : v[1],
                 u[2] > v[2] ? u[2] : v[2]);
}

BoundingBox3::BoundingBox3(const Vector3* points, int n)
{
  if(n <= 0)
    return;

  Vector3 min, max;

  min = max = points[0];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < 3; j++) {
      if(min[j] > points[i][j])
        min[j] = points[i][j];
      if(max[j] < points[i][j])
        max[j] = points[i][j];
    }

  p[0] = min;
  p[1] = max;
}

BoundingBox3 BoundingBox3::operator+(const BoundingBox3& box) const
{
  BoundingBox3 result;

  result.p[0] = result.p[1] = p[0];

  for(int i = 0; i < 3; i++) {
    if(result.p[0][i] < result.p[1][i])
      result.p[0][i] = result.p[1][i];
    if(result.p[1][i] > result.p[0][i])
      result.p[1][i] = result.p[0][i];
    for(int j = 0; j < 2; j++) {
      if(result.p[0][i] < box.p[j][i])
        result.p[0][i] = box.p[j][i];
      if(result.p[1][i] > box.p[j][i])
        result.p[1][i] = box.p[j][i];
    }
  }

  return result;
}

BoundingBox3& BoundingBox3::operator+=(const BoundingBox3& box)
{
  BoundingBox3 result;

  result.p[0] = result.p[1] = p[0];

  for(int i = 0; i < 3; i++) {
    if(result.p[0][i] < p[1][i])
      result.p[0][i] = p[1][i];
    if(result.p[1][i] > p[0][i])
      result.p[1][i] = p[0][i];
    for(int j = 0; j < 2; j++) {
      if(result.p[0][i] < box.p[j][i])
        result.p[0][i] = box.p[j][i];
      if(result.p[1][i] > box.p[j][i])
        result.p[1][i] = box.p[j][i];
    }
  }

  *this = result;

  return *this;
}

BoundingBox3 BoundingBox3::transform(const Matrix4& matrix) const
{
}

bool BoundingBox3::intersect(const Camera& camera) const
{
}

