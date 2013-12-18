#pragma once

#include "libs.h"

class Light
{
  public:
    Point3D color;

    virtual void draw(GLuint light_handle);
};

class DirectionalLight : public Light
{
  public:
    Vector3 direction;

    void draw(GLuint light_handle);
};

class PointLight : public Light
{
  public:
    Vector3 location;
    double constant_attenuation;
    double linear_attenuation;
    double quadratic_attenuation;

    void draw(GLuint light_handle);
};

class SpotLight : public Light
{
  public:
    Vector3 location;
    Vector3 direction;
    double constant_attenuation;
    double linear_attenuation;
    double quadratic_attenuation;
    double cut_off_rate;
    double drop_off_rate;

    void draw(GLuint light_handle);
};

