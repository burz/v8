#pragma once

#include "Vector.h"

class Mouse
{
  public:
    int shift;
    int ctrl;
    int alt;
    int left_button;
    int middle_button;
    int right_button;
    int scroll_button;
    int starting_x;
    int starting_y;
    int ending_x;
    int ending_y;

    Mouse(void);

    void update(int button, int state, int x, int y);
    Vector2 move(int x, int y);
};

