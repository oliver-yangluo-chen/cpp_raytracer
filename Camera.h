//#ifndef IMAGE_H
//#define IMAGE_H
#pragma once
#include <vector>
#include "Misc.h"
using namespace std;

class Camera{
private:
  Vec3 pos, forward, up, right;
  //aspect is y/x
  double fov, aspect, width, height;
public:
  Camera(Vec3 pos_, Vec3 forward_, Vec3 up_, Vec3 right_, double fov_, double aspect_);

  Vec3 view(double x, double y);
};