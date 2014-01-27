#pragma once

#include "libs.h"
#include "Light.h"
#include "Group.h"
#include "Camera.h"

class Vertex
{
  public:
    int handle;
    Vector3 position;
    Vector3 normal;
    Vector3 texture_coordinate;
};

class Material
{
  private:
    static unsigned int new_handle;
  public:
    unsigned int handle;
    Vector3 ambient;
    Vector3 diffuse;
    Vector3 specular;
    Vector3 emissive;
    Vector3 transparent;
    double specular_fall_off;
    double refraction_index;

    Material(void);

    void draw(void);
};

class Texture
{
  private:
    GLuint gl_handle;
  public:
    ~Texture(void);

    void setup_OpenGL(void);
};

class Scene
{
  public:
    int number_of_vertices;
    int number_of_materials;
    int number_of_textures;
    int number_of_lights;
    Vertex* vertices;
    Material* materials;
    Texture* textures;
    Light** lights;
    Vector3 ambient;
    Vector3 background;
    Camera* camera;
    Shape* scene_graph;

    Scene(void);
    ~Scene(void);

    void setup_OpenGL(void);
    void draw(void);
};

