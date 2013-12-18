#pragma once

#include "libs.h"
#include "BoundingBox.h"

class Shape
{
  protected:
    BoundingBox3 bounding_box;

    GLuint call_list_id;
  public:
    virtual BoundingBox3 set_bounding_box(void) = 0;
    virtual bool is_static(void) { return 1; }

    virtual void setup_OpenGL(void) = 0;
    virtual void draw(void) = 0;
};

