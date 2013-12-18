#pragma once

#include "Group.h"
#include "Camera.h"

class Scene
{
  private:
    StaticGroup scene_graph;
    Camera camera;
  public:
    void setup_OpenGL(void);
    void draw(void);
};

