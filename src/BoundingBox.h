#pragma once

#include "Vector.h"
#include "Matrix.h"
#include "Camera.h"

class BoundingBox3
{
  private:
    Vector3 p[2];
  public:
    BoundingBox3(void);
    BoundingBox3(const Vector3& u, const Vector3& v);
    BoundingBox3(const Vector3* points, int n);

    BoundingBox3 operator+(const BoundingBox3& box) const;
    BoundingBox3 operator+=(const BoundingBox3& box);

    BoundingBox3 transform(const Matrix4& matrix) const;

    bool intersect(const Camera& camera) const;
};

