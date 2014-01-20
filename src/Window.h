#pragma once

#include <time.h>

#include "Scene.h"
#include "Mouse.h"

class Window
{
  private:
    Mouse mouse;
    Vector3 center_of_bounding_box;
    double radius_of_bounding_box;
    bool visible;

    time_t start_time;
    int frame_count;
    time_t frame_count_start_time;
    double frame_rate;

  public:
    static void display_function(void);
    static void idle_function(void);
    static void visibility_function(int state);
    static void mouse_function(int button, int state, int x, int y);
    static void motion_function(int x, int y);
    static void keyboard_function(unsigned char c, int x, int y);
    static void special_function(int key, int x, int y);

    void run_scene(Scene *scene, int width, int height);
};

