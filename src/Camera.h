#pragma once

#include "Vector.h"

class Camera
{
  private:
    Vector3 position;
    Vector3 direction;
    Vector3 up;
  public:
    void move(double x, double y, double z);
    void move(const Vector3& v);
    void rotate(double x, double y, double z);
    void rotate(const Vector3& r);
};

