#pragma once

#ifdef __APPLE__
  #include <GLUT/glut.h>
  #define glBindVertexArray glBindVertexArrayAPPLE 
  #define glGenVertexArrays glGenVertexArraysAPPLE
  #define glGenerateMipmap glGenerateMipmapEXT
  #define glDeleteVertexArrays glDeleteVertexArraysAPPLE
#else
  #include <GL/glut.h>
#endif

