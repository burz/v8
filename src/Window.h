#pragma once

#include "Scene.h"

class Window
{
  private:
    Scene scene;
  public:
    void setup_OpenGL(void);
    void draw(void) { scene.draw() };
};

