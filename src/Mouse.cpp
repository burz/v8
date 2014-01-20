#include "libs.h"
#include "Mouse.h"

Mouse::Mouse(void)
{
  starting_x = starting_y = ending_x = ending_y = -1;
  scroll_button = left_button = middle_button = right_button = 0;
  shift = ctrl = alt = 0;
}

void Mouse::update(int button, int state, int x, int y)
{
  int modifiers;

  if(state == GLUT_DOWN) {
    starting_x = ending_x = x;
    starting_y = ending_y = y;

    if(button == GLUT_LEFT_BUTTON)
      left_button = 1;
    if(button == GLUT_MIDDLE_BUTTON)
      middle_button = 1;
    if(button == GLUT_RIGHT_BUTTON)
      right_button = 1;
#ifdef GLUT_SCROLL_WHEEL
    if(button == GLUT_SCROLL_WHEEL)
      scroll_button = 1;
#endif

  modifiers = glutGetModifiers();

  if(modifiers & GLUT_ACTIVE_SHIFT)
    shift = 1;
  else
    shift = 0;

  if(modifiers & GLUT_ACTIVE_CTRL)
    ctrl = 1;
  else
    ctrl = 0;

  if(modifiers & GLUT_ACTIVE_ALT)
    alt = 1;
  else
    alt = 0;
  }
  else if(state == GLUT_UP) {
    ending_x = x;
    ending_y = y;

    if(button == GLUT_LEFT_BUTTON)
      left_button = 0;
    if(button == GLUT_MIDDLE_BUTTON)
      middle_button = 0;
    if(button == GLUT_RIGHT_BUTTON)
      right_button = 0;
#ifdef GLUT_SCROLL_WHEEL
    if(button == GLUT_SCROLL_WHEEL)
      scroll_button = 0;
#endif
  }
}

Vector2 Mouse::move(int x, int y)
{
  Vector2 distance;

  distance[0] = x - ending_x;
  distance[1] = y - ending_y;

  ending_x = x;
  ending_y = y;

  return distance;
}

