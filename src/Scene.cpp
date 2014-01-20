#include "Scene.h"

unsigned int Material::new_handle = 0;

Material::Material(void)
{
  handle = new_handle++;

  specular_fall_off = 0;
  refraction_index = 0;
}

void Material::draw(void)
{
  GLfloat gl_ambient[3] = { ambient[0], ambient[1], ambient[2] };
  GLfloat gl_diffuse[3] = { diffuse[0], diffuse[1], diffuse[2] };
  GLfloat gl_specular[3] = { specular[0], specular[1], specular[2] };
  GLfloat gl_emissive[3] = { emissive[0], emissive[1], emissive[2] };

  glMaterialfv(GL_FRONT, GL_AMBIENT, gl_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, gl_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, gl_specular);
  glMaterialfv(GL_FRONT, GL_EMISSION, gl_emissive);
  glMaterialf(GL_FRONT, GL_SHININESS, (GLfloat) specular_fall_off);
}

Texture::Texture(void)
{
}

Texture::~Texture(void)
{
}

void Texture::setup_OpenGL(void)
{
}

Scene::Scene(void)
{
}

Scene::~Scene(void)
{
}

void Scene::setup_OpenGL(void)
{
}

void Scene::draw(void)
{
}

