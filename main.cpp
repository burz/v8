#include <stdio.h>

#include "Window.h"
#include "Scene.h"

int main(int argc, char* argv[])
{
  Window w;
  Scene s;

  w.run_scene(&s, 800, 800);

  return 0;
}

