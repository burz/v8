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
  public:
    int handle;
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

class Intersection
{
  public:
    Material *material;
    Vector3 coordinates;
    Vector3 normal;
    Vector3 texture_coordinate;
};

class Texture
{
  public:
    int handle;
    GLuint gl_handle;

    Texture(void);
    ~Texture(void);

    void setup_OpenGL(void);
};

class Scene
{
  private:
    int number_of_vertices;
    int number_of_materials;
    int number_of_textures;
    int number_of_lights;
    Vertex* vertices;
    Material* materials;
    Texture* textures;
    Light* lights;
    Vector3 ambient;
    Vector3 background;
    Camera* camera;
    StaticGroup scene_graph;
  public:
    Scene(void);
    ~Scene(void);

    void setup_OpenGL(void);
    void draw(void);
};

