#include "libs.h"
#include "Window.h"

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
}

void Window::motion_function(int x, int y)
{
}

void Window::keyboard_function(unsigned char c, int x, int y)
{
}

void Window::special_function(int key, int x, int y)
{
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

