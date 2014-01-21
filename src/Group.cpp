#include <stdlib.h>
#include <stdio.h>

#include "Group.h"
#include "Shape.h"

Group::Group(void)
{
  number_of_shapes = 0;
  shapes = NULL;
}

Group::~Group(void)
{
  for(int i = 0; i < number_of_shapes; i++)
    if(shapes[i])
      delete shapes[i];
  if(shapes)
    delete[] shapes;

  call_list_id = 0;
}

void Group::add_shape(Shape* shape)
{
  Shape **old_shapes = shapes;

  shapes = new Shape*[number_of_shapes + 1];
  if(shapes == NULL)
    fprintf(stderr, "Could not allocate space for %i shapes\n", number_of_shapes + 1);

  for(int i = 0; i < number_of_shapes; i++)
    shapes[i] = old_shapes[i];

  shapes[number_of_shapes++] = shape;
}

int Group::size(void) const
{
  return number_of_shapes;
}

BoundingBox3 Group::set_bounding_box(void)
{
  Vector3* list = new Vector3[number_of_shapes * 2];
  BoundingBox3 result;

  for(int i = 0; i < number_of_shapes; i++) {
    result = shapes[i]->set_bounding_box();

    list[2 * i] = result.p[0];
    list[2 * i + 1] = result.p[1];
  }

  bounding_box = BoundingBox3(list, number_of_shapes * 2);

  delete[] list;

  return bounding_box;
}

int Group::draw(int last_material)
{
  glPushMatrix();
  glMultMatrixd((const GLdouble*) get_matrix().m);

  for(int i = 0; i < number_of_shapes; i++)
    last_material = shapes[i]->draw(last_material);

  glPopMatrix();

  return last_material;
}

StaticGroup::StaticGroup(void)
  : Group()
{
  transformation = Matrix4::Identity();
}

Matrix4 StaticGroup::get_matrix(void)
{
  return transformation;
}

Matrix4 StaticGroup::get_inverse_matrix(void)
{
  return inverse;
}

Matrix4 StaticGroup::get_normal_matrix(void)
{
  return normal;
}

bool StaticGroup::is_static(void)
{
  for(int i = 0; i < number_of_shapes; i++)
    if(!shapes[i]->is_static())
      return false;

  return true;
}

void StaticGroup::setup_OpenGL(void)
{
  // set up inverse and normal matrix

  for(int i = 0; i < number_of_shapes; i++)
    shapes[i]->setup_OpenGL();
}

int StaticGroup::draw(int last_material)
{
  if(is_static() && call_list_id != 0) {
    glCallList(call_list_id);

    return -1;
  }

  return Group::draw(last_material);
}

