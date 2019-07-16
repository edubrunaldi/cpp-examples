#include <iostream>
#include "ScreenShot.hpp"

int main() {
  int pointX = 0;
  int pointY = 0;
  int width = 500;
  int height = 500;
  ScreenShot ss = ScreenShot();
  cv::Mat img1;
  ss.take(pointX, pointY, width, height, img1);
  cv::imshow("Image 1", img1);
  cv::waitKey(0);

  cv::Mat *img2 = ss.take(pointX, pointY, width, height);
  cv::imshow("Image 2", *img2);
  cv::waitKey(0);
  free(img2);

  return 0;
}