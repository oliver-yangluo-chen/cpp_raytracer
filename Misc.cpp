#include "Misc.h"

/*
Color::Color(double red_, double green_, double blue_){
  red = red_;
  green = green_;
  blue = blue_;
} 
*/

Color operator+(const Color a, const Color b){
  return {a.red+b.red, a.green+b.green, a.blue+b.blue};
}
Color operator/(const Color a, const double b){
  return {a.red/b, a.green/b, a.blue/b};
}
bool operator==(const Color a, const Color b){
  return a.red == b.red && a.green == b.green && a.blue == b.blue;
}


/*
Vec3::Vec3(double x_, double y_, double z_): 
    x(x_), y(y_), z(z_) {}
*/

Vec3 operator-(const Vec3 a, const Vec3 b){
  return {a.x-b.x, a.y-b.y, a.z-b.z};
}
Vec3 operator+(const Vec3 a, const Vec3 b){
  return {a.x+b.x, a.y+b.y, a.z+b.z};
}
Vec3 operator*(const Vec3 a, const Vec3 b){
  return {a.x*b.x, a.y*b.y, a.z*b.z};
}
Vec3 operator/(const Vec3 a, const Vec3 b){
  return {a.x/b.x, a.y/b.y, a.z/b.z};
}

Vec3 operator*(const Vec3 a, const double b){
  return {a.x*b, a.y*b, a.z*b};
}
Vec3 operator/(const Vec3 a, const double b){
  return {a.x/b, a.y/b, a.z/b};
}

Vec3 operator*(const Vec3 a, const Color b){
  return {a.x * b.red, a.y * b.green, a.z * b.blue};
}


double dot(Vec3 a, Vec3 b){
  return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec3 cross(Vec3 a, Vec3 b) {
  return {
    a.y*b.z - a.z*b.y,
    a.z*b.x - a.x*b.z,
    a.x*b.y - a.y*b.x};
};

/*
Ray::Ray(Vec3 start_, Vec3 dir_):
  start(start_), dir(dir_) {}
*/

double lerp(double a, double b, double t){
  //return (t-1)*a + t*b;
  return a + (b-a)*t;
}

double length(Vec3 v){
  return sqrt(dot(v, v)); //dot squares coords
}

Vec3 normalize(Vec3 v){ //turn magnitude into direction
  //calculate length
  //make length 1
  return v * (1/length(v));
}