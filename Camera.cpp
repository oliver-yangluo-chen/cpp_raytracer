#include "Camera.h"

Camera::Camera(Vec3 pos_, Vec3 forward_, Vec3 up_, Vec3 right_, double fov_, double aspect_):
  pos(pos_),
  forward(normalize(forward_)),
  up(normalize(up_)),
  right(normalize(right_)),
  fov(fov_),
  aspect(aspect_),
  width(tan(fov/2)),
  height(tan(fov/2) * aspect) {}

Vec3 Camera::view(double x, double y){ //x, y are -1, 1
  //pic coords to world coords
  Vec3 center = pos + forward;
  Vec3 pic_x = center + right * (width/2);
  Vec3 pic_y = center - up * (width/2) * aspect;

  return center + right*x + up*y;
}