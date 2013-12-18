#pragma once

#include "Scene.h"

class Window
{
  private:
    Scene scene;
    Mouse mouse;
    Vector3 center_of_bounding_box;
    double radius_of_bounding_box;
    bool visible;

    double start_time;
    int frame_count;
    double frame_count_start_time;
    double frame_rate;

  public:
    virtual void idle_function(void);
    virtual void visibility_function(int state);
    virtual void mouse_function(int button, int state, int x, int y) = 0;
    virtual void motion_function(int x, int y) = 0;
    virtual void keyboard_function(unsigned char c, int x, int y) = 0;
    virtual void special_function(int key, int x, int y) = 0;

    void setup_OpenGL(void);
    void draw(void) { scene.draw() };
};

