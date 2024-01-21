//#ifndef MISC_H
//#define MISC_H
#pragma once
#include <math.h>

struct Color{
  double red, green, blue;
  //int transparency, reflectiveness? store this kind of stuff in color?
  //Color(double red_, double green_, double blue_); 
};

Color operator+(const Color a, const Color b);
Color operator/(const Color a, const double b);
bool operator==(const Color a, const Color b);


struct Vec3{
  double x = 0;
  double y = 0;
  double z = 0;
  
  //Vec3(double x_, double y_, double z_);
};

Vec3 operator-(const Vec3 a, const Vec3 b);
Vec3 operator+(const Vec3 a, const Vec3 b);
Vec3 operator*(const Vec3 a, const Vec3 b);
Vec3 operator/(const Vec3 a, const Vec3 b);

Vec3 operator*(const Vec3 a, const double b);
inline Vec3 operator*(const double a, const Vec3 b) { return b*a; }
Vec3 operator/(const Vec3 a, const double b);
Vec3 operator*(const Vec3 a, const Color b);


double dot(Vec3 a, Vec3 b);

Vec3 cross(Vec3 a, Vec3 b);

struct Ray{
  Vec3 start, dir;
  //Ray(Vec3 start_, Vec3 dir_);

  Vec3 operator()(double t) const { return start + dir * t; }
};


double lerp(double a, double b, double t);

double length(Vec3 v);

Vec3 normalize(Vec3 v);
//#endif