//#ifndef CONSTANT_H
//#define CONSTANT_H
#pragma once
#include "Misc.h"
using namespace std;

const double PI = 3.14159265358979;
// M_PI


const Color RED = {255, 0, 0};
const Color GREEN = {0, 255, 0};
const Color BLUE = {0, 0, 255};
const Color WHITE = {255, 255, 255};
const Color BLACK = {0, 0, 0};

//testing
const double X = 512;
const double Y = 512;
const double ASPECT = Y/X;
const double FOV = PI/2;
const Vec3 CAMPOS = {0, 0.5, 0};
const Vec3 CAMFORWARD = {0, 0, 1};
const Vec3 CAMUP = {0, 1, 0};
const Vec3 CAMRIGHT = {1, 0, 0};
const bool ANTI_ALIASING = false;
const int CYCLES = 40;
const double BLUR = 5; //greater is less blur
//#endif