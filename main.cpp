#include <iostream>
#include "ScreenShot.hpp"

int main() {
  int pointX = 0;
  int pointY = 0;
  int width = 500;
  int heigth = 500;

  cv::Mat img;
  ScreenShot screen(pointX, pointY, width, heigth);
  screen(img);
  cv::imshow("image", img);
  cv::waitKey(0);
  return 0;
}