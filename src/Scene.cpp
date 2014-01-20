#include <stdlib.h>

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

Texture::~Texture(void)
{
  glDeleteTextures(1, &gl_handle);
}

void Texture::setup_OpenGL(void)
{
  glGenTextures(1, &gl_handle);
}

Scene::Scene(void)
{
  vertices = NULL;
  number_of_vertices = 0;
  materials = NULL;
  number_of_materials = 0;
  textures = NULL;
  number_of_textures = 0;
  lights = NULL;
  number_of_lights = 0;

  camera = NULL;
}

Scene::~Scene(void)
{
  for(int i = 0; i < number_of_lights; i++)
    delete lights[i];

  if(number_of_vertices > 0)
    delete[] vertices;
  if(number_of_materials > 0)
    delete[] materials;
  if(number_of_textures > 0)
    delete[] textures;
  if(number_of_lights > 0)
    delete[] lights;

  if(camera)
    delete camera;
}

void Scene::setup_OpenGL(void)
{
  for(int i = 0; i < number_of_textures; i++)
    textures[i].setup_OpenGL();
}

void Scene::draw(void)
{
  camera->draw();

  glEnable(GL_LIGHTING);
  for(int i = 0; i < number_of_lights; i++)
    lights[i]->draw(i);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

