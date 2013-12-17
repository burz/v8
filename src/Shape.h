#pragma once

#include "libs.h"
#include "BoundingBox.h"

class Shape
{
  private:
    BoundingBox3 bounding_box;

    GLuint call_list_id;
  public:
    virtual BoundingBox3 set_bounding_box(void) = 0;
    virtual bool is_static(void) { return 1; }
};

