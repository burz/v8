#pragma once

#include "Shape.h"
#include "Matrix.h"

class Group : public Shape
{
  protected:
    int number_of_shapes;
    Shape** shapes;
  public:
    Group(void);
    ~Group(void);

    void add_shape(Shape* shape);
    int size(void) const;
    virtual BoundingBox3 set_bounding_box(void);
    virtual Matrix4 get_matrix(void) = 0;
    virtual Matrix4 get_inverse_matrix(void) = 0;
    virtual Matrix4 get_normal_matrix(void) = 0;

    virtual void setup_OpenGL(void) = 0;
    virtual int draw(int last_material);
};

class StaticGroup : public Group
{
  private:
    Matrix4 transformation;
    Matrix4 inverse;
    Matrix4 normal;
  public:
    StaticGroup(void);

    Matrix4 get_matrix(void);
    Matrix4 get_inverse_matrix(void);
    Matrix4 get_normal_matrix(void);

    bool is_static(void);

    void setup_OpenGL(void);
    int draw(int last_material);
};

