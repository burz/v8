#pragma once

#include <time.h>

#include "Scene.h"
#include "Mouse.h"

class Window
{
  private:
    static Mouse mouse;
    static Vector3 center_of_bounding_box;
    static double radius_of_bounding_box;
    static bool visible;

    static time_t start_time;
    static int frame_count;
    static time_t frame_count_start_time;
    static double frame_rate;

  public:
    static void display_function(void);
    static void idle_function(void);
    static void visibility_function(int state);
    static void mouse_function(int button, int state, int x, int y);
    static void motion_function(int x, int y);
    static void passive_motion_function(int x, int y);
    static void keyboard_function(unsigned char c, int x, int y);
    static void special_function(int key, int x, int y);

    static void run_scene(Scene *scene, int width, int height);
};

