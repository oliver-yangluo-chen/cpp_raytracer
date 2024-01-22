#include "Image.h"

 
Image::Image(int width_, int height_, Color c):
  width(width_), height(height_) {
  pic = std::vector<std::vector<Color>>(height, std::vector<Color>(width, c));
}

void Image::setPixel(int w, int h, Color c){
  pic[h][w] = c;
}

Color Image::getPixel(int w, int h){
  return pic[h][w];
}

void Image::writeToFile(std::string filename){
  std::ofstream fout(filename);

  fout << "P3" << std::endl;
  fout << height << " " << width << std::endl; 
  fout << 255 << std::endl; //maximum color value

  for(int i = height-1; i >= 0; --i){
    for(int j = 0; j < width; ++j){
      fout << (int)pic[i][j].red << " ";
      fout << (int)pic[i][j].green << " ";
      fout << (int)pic[i][j].blue << std::endl;
    }
  }
  return;
}

void Image::drawSquare(int x, int y, int s, Color c){
  for(int i = x - s/2; i <= x + s/2; ++i){
    setPixel(i, y + s/2, c);
    setPixel(i, y - s/2, c);
  }
  for(int i = y - s/2; i <= y + s/2; ++i){
    setPixel(x + s/2, i, c);
    setPixel(x - s/2, i, c);
  }
  return;
}
void Image::drawCircle(int x, int y, int r, Color c){
  for(double angle = 0; angle < 360; angle += 0.1){
    double dx = r * cos(angle * PI/180);
    double dy = r * sin(angle * PI/180);
    setPixel(x + dx, y + dy, c);
  }
  return;
}
void Image::fill(int x, int y, Color c){
  Color start = getPixel(x, y);//fill everything this color
  if(c == start) return;
  std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  std::queue<std::pair<int, int>> q;
  q.push({x, y});
  while(!q.empty()){
    std::pair<int, int> cur = q.front();
    q.pop();

    setPixel(cur.first, cur.second, c);

    for(const auto &d: dirs){
      std::pair<int, int> neighbor = {cur.first + d.first, cur.second + d.second};
      if(getPixel(neighbor.first, neighbor.second) == start){
        q.push(neighbor);
      }
    }
  }
  return;
}