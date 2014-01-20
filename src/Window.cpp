#include <stdlib.h>

#include "libs.h"
#include "Window.h"

#define ESCAPE_KEY '\033'

Mouse Window::mouse;
Vector3 Window::center_of_bounding_box;
double Window::radius_of_bounding_box;
bool Window::visible;
time_t Window::start_time;
int Window::frame_count;
time_t Window::frame_count_start_time;
double Window::frame_rate;

void Window::idle_function(void)
{
}

void Window::visibility_function(int state)
{
}

void Window::display_function(void)
{
}

void Window::mouse_function(int button, int state, int x, int y)
{
  mouse.update(button, state, x, y);
}

void Window::motion_function(int x, int y)
{
}

void Window::passive_motion_function(int x, int y)
{
  mouse.move(x, y);

  glutPostRedisplay();
}

void Window::keyboard_function(unsigned char c, int x, int y)
{
  switch(c) {
    case ESCAPE_KEY:
      exit(0);
      break;
    default:
      break;
  }
}

void Window::special_function(int key, int x, int y)
{
  switch(key) {
    case GLUT_KEY_F1:
      break;
    case GLUT_KEY_F2:
      break;
    case GLUT_KEY_F3:
      break;
    case GLUT_KEY_F4:
      break;
    case GLUT_KEY_F5:
      break;
    case GLUT_KEY_F6:
      break;
    case GLUT_KEY_F7:
      break;
    case GLUT_KEY_F8:
      break;
    case GLUT_KEY_F9:
      break;
    case GLUT_KEY_F10:
      break;
    case GLUT_KEY_F11:
      break;
    case GLUT_KEY_F12:
      break;
    case GLUT_KEY_UP:
      break;
    case GLUT_KEY_DOWN:
      break;
    case GLUT_KEY_LEFT:
      break;
    case GLUT_KEY_RIGHT:
      break;
    case GLUT_KEY_PAGE_UP:
      break;
    case GLUT_KEY_PAGE_DOWN:
      break;
    case GLUT_KEY_HOME:
      break;
    case GLUT_KEY_END:
      break;
    case GLUT_KEY_INSERT:
      break;
  }

  glutPostRedisplay();
}

void Window::run_scene(Scene* scene, int width, int height)
{
  int argc = 1;
  char* argv[] = { (char*) "a" };

  time(&start_time);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

  glutCreateWindow("v8");
  glutInitWindowSize(width, height);
  glutInitWindowPosition(0, 0);

  glClearColor(scene->background[0], scene->background[1],
               scene->background[2], 1.0);

  glutReshapeWindow(width, height);

  glutDisplayFunc(display_function);
  glutKeyboardFunc(keyboard_function);
  glutSpecialFunc(special_function);
  glutMouseFunc(mouse_function);
  glutMotionFunc(motion_function);
  glutPassiveMotionFunc(passive_motion_function);
  glutVisibilityFunc(visibility_function);
  glutIdleFunc(idle_function);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glDepthMask(GL_TRUE);
  glDisable(GL_BLEND);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);

  scene->setup_OpenGL();

  glutMainLoop();
}

