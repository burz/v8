#pragma once

#include "Vector.h"

class Camera
{
  private:
    double height_angle;
    double aspect_ratio;
    Vector3 position;
    Vector3 direction;
    Vector3 up;
    Vector3 right;
  public:
    void rotate_forward(double angle);
    void rotate_up(double angle);
    void rotate_right(double angle);
    void move_forward(double distance);
    void move_up(double distance);
    void move_right(double distance);
};

