#include "Light.h"

void DirectionalLight::draw(GLuint light_handle)
{
  GLfloat gl_direction[4] = { direction[0], direction[1], direction[2], 0.0 };
  GLfloat gl_color[4] = { color[0], color[1], color[2], 1.0 };

  glLightfv(GL_LIGHT0 + light_handle, GL_POSITION, gl_direction);
  glLightfv(GL_LIGHT0 + light_handle, GL_DIFFUSE, gl_color);
  glLightfv(GL_LIGHT0 + light_handle, GL_SPECULAR, gl_color);

  glEnable(GL_LIGHT0 + index);
}

void PointLight::draw(GLuint light_handle)
{
  GLfloat gl_location[4] = { location[0], location[1], location[2], 1.0 };
  GLfloat gl_color[4] = { color[0], color[1], color[2], 1.0 };

  glLightfv(GL_LIGHT0 + index, GL_POSITION, location);
  glLightfv(GL_LIGHT0 + index, GL_DIFFUSE, gl_color);
  glLightfv(GL_LIGHT0 + index, GL_SPECULAR, gl_color);
  glLightf(GL_LIGHT0 + index, GL_CONSTANT_ATTENUATION, constAtten);
  glLightf(GL_LIGHT0 + index, GL_LINEAR_ATTENUATION, linearAtten);
  glLightf(GL_LIGHT0 + index, GL_QUADRATIC_ATTENUATION, quadAtten);

  glEnable(GL_LIGHT0 + index);
}

void SpotLight::draw(GLuint light_handle)
{
}

