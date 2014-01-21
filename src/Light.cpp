#include "Light.h"

void DirectionalLight::draw(GLuint light_handle)
{
  GLfloat gl_direction[4] = { direction[0], direction[1], direction[2], 0.0 };
  GLfloat gl_diffuse[4] = { diffuse[0], diffuse[1], diffuse[2], 1.0 };
  GLfloat gl_specular[4] = { specular[0], specular[1], specular[2], 1.0 };

  glLightfv(GL_LIGHT0 + light_handle, GL_POSITION, gl_direction);
  glLightfv(GL_LIGHT0 + light_handle, GL_DIFFUSE, gl_diffuse);
  glLightfv(GL_LIGHT0 + light_handle, GL_SPECULAR, gl_specular);

  glEnable(GL_LIGHT0 + light_handle);
}

void PointLight::draw(GLuint light_handle)
{
  GLfloat gl_location[4] = { location[0], location[1], location[2], 1.0 };
  GLfloat gl_diffuse[4] = { diffuse[0], diffuse[1], diffuse[2], 1.0 };
  GLfloat gl_specular[4] = { specular[0], specular[1], specular[2], 1.0 };

  glLightfv(GL_LIGHT0 + light_handle, GL_POSITION, gl_location);
  glLightfv(GL_LIGHT0 + light_handle, GL_DIFFUSE, gl_diffuse);
  glLightfv(GL_LIGHT0 + light_handle, GL_SPECULAR, gl_specular);
  glLightf(GL_LIGHT0 + light_handle, GL_CONSTANT_ATTENUATION, constant_attenuation);
  glLightf(GL_LIGHT0 + light_handle, GL_LINEAR_ATTENUATION, linear_attenuation);
  glLightf(GL_LIGHT0 + light_handle, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);

  glEnable(GL_LIGHT0 + light_handle);
}

void SpotLight::draw(GLuint light_handle)
{
  GLfloat gl_location[4] = { location[0], location[1], location[2], 1.0 };
  GLfloat gl_diffuse[4] = { diffuse[0], diffuse[1], diffuse[2], 1.0 };
  GLfloat gl_specular[4] = { specular[0], specular[1], specular[2], 1.0 };
  GLfloat gl_direction[3] = { direction[0], direction[1], direction[2] };

  glLightfv(GL_LIGHT0 + light_handle, GL_POSITION, gl_location);
  glLightfv(GL_LIGHT0 + light_handle, GL_DIFFUSE, gl_diffuse);
  glLightfv(GL_LIGHT0 + light_handle, GL_SPECULAR, gl_specular);
  glLightfv(GL_LIGHT0 + light_handle, GL_SPOT_DIRECTION, gl_direction);
  glLightf(GL_LIGHT0 + light_handle, GL_SPOT_EXPONENT, drop_off_rate);
  glLightf(GL_LIGHT0 + light_handle, GL_SPOT_CUTOFF, cut_off_angle);
  glLightf(GL_LIGHT0 + light_handle, GL_CONSTANT_ATTENUATION, constant_attenuation);
  glLightf(GL_LIGHT0 + light_handle, GL_LINEAR_ATTENUATION, linear_attenuation);
  glLightf(GL_LIGHT0 + light_handle, GL_QUADRATIC_ATTENUATION, quadratic_attenuation);

  glEnable(GL_LIGHT0 + light_handle);
}

