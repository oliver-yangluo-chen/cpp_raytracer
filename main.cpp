#include "Constants.h"
#include "Misc.h"
#include "Shapes.h"
#include "Image.h"
#include "Camera.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
  srand(time(NULL));

  Camera Cam(CAMPOS, CAMFORWARD, CAMUP, CAMRIGHT, FOV, ASPECT);

  Image image(X, Y);

  Sphere sphere({0, 0, 50}, 30, RED);

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

          double time = sphere.intersection({ray.start, ray.dir + deviation/200}).t;
          if(time > 0) c = c + RED;
        }
        c = c/CYCLES;
      }
      else{
        double time = sphere.intersection(ray).t;
        if(time > 0) c = RED;
      }
      
      image.setPixel(i, j, c);
    }
  }
  image.writeToFile("circle.ppm");
  cerr << "finished drawing" << endl;
}