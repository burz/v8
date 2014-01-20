#include "libs.h"
#include "Camera.h"

void Camera::rotate_forward(double angle)
{
}

void Camera::rotate_up(double angle)
{
}

void Camera::rotate_right(double angle)
{
}

void Camera::move_forward(double distance)
{
  position += direction * distance;
}

void Camera::move_up(double distance)
{
  position += up * distance;
}

void Camera::move_right(double distance)
{
  position += right * distance;
}

void Camera::draw(void)
{
  gluLookAt(position[0], position[1], position[2],
            direction[0], direction[1], direction[2],
            up[0], up[1], up[2]);
}

