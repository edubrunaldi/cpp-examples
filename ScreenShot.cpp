//
// Created by xima on 16/07/19.
//

#include "ScreenShot.hpp"

ScreenShot::ScreenShot() {
  this->display = XOpenDisplay(nullptr);
  this->root = DefaultRootWindow(display);

}

void ScreenShot::take(int x, int y, int width, int height, cv::Mat &cvImg) {
  img = XGetImage(this->display, this->root, x, y, width, height, AllPlanes, ZPixmap);

  cvImg = cv::Mat(height, width, CV_8UC4, img->data);
}

cv::Mat* ScreenShot::take(int x, int y, int width, int height) {
  cv::Mat *cvImg = new cv::Mat();
  img = XGetImage(this->display, this->root, x, y, width, height, AllPlanes, ZPixmap);

  *cvImg = cv::Mat(height, width, CV_8UC4, img->data);

  return cvImg;
}