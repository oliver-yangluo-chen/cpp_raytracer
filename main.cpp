#include "Constants.h"
#include "Misc.h"
#include "Shapes.h"
#include "Image.h"
#include "Camera.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

Color getcolor(const Ray &ray, vector<Shape*> shapes){
  Color c = BLACK;
  double mintime = -1;
  for(int i = 0; i < shapes.size(); ++i){
    double time = shapes[i]->intersection(ray).t;
    if(time > 0 && (time < mintime || mintime == -1)){
      mintime = time;
      c = shapes[i]->color;
    }
  }
  return c;
}

int main() {
  srand(time(NULL));

  Camera Cam(CAMPOS, CAMFORWARD, CAMUP, CAMRIGHT, FOV, ASPECT);

  Image image(X, Y);

  Sphere sphere({0, 0, 50}, 30, RED);
  Sphere sphere2({70, 70, 70}, 80, BLUE);
  Plane plane({3.0/5.0, 4.0/5.0, 0}, 0, GREEN);
  vector<Shape*> shapes = {&sphere, &sphere2, &plane};

  cerr << "finished initial calcs" << endl;
  for(double i = 0; i < X; ++i){
    for(double j = 0; j < Y; ++j){
      double lX = lerp(-1, 1, i/(X-1)); //lerped X
      double lY = lerp(-1, 1, j/(Y-1)); //lerped Y

      Vec3 dest = Cam.view(lX, lY);
      Ray ray = {CAMPOS, dest - CAMPOS};
      ray.dir = normalize(ray.dir);
      Color c = BLACK;

      if(ANTI_ALIASING){
        for(int k = 0; k < CYCLES; ++k){
          Vec3 deviation = {(double)rand()/RAND_MAX, (double)rand()/RAND_MAX, (double)rand()/RAND_MAX};
          c = c + getcolor({ray.start, ray.dir + deviation/200}, shapes);
        }
        c = c/CYCLES;
      }
      else{
        c = getcolor(ray, shapes);
      }
      
      image.setPixel(i, j, c);
    }
  }
  image.writeToFile("circle.ppm");
  cerr << "finished drawing" << endl;
}