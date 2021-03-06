#pragma once

#include "libs.h"
#include "Vector.h"

class Light
{
  public:
    Vector3 diffuse;
    Vector3 specular;

    virtual void draw(GLuint light_handle) = 0;
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
    double cut_off_angle;
    double drop_off_rate;

    void draw(GLuint light_handle);
};

