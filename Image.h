//#ifndef IMAGE_H
//#define IMAGE_H
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include "Misc.h"
#include "Constants.h"
using namespace std;

class Image{
private:
  int width, height; //const?
  vector<vector<Color>> pic;
public:
  // keep
  Image(int width_ = 640, int height_ = 480, Color c = WHITE);
  // keep
  void setPixel(int w, int h, Color c);
  Color getPixel(int w, int h);
  // keep
  void writeToFile(string filename);
  void drawSquare(int x, int y, int s, Color c);
  void drawCircle(int x, int y, int r, Color c);
  void fill(int x, int y, Color c);
};
//#endif