//
// Created by xima on 07/07/19.
//

#ifndef CPP_EXAMPLE_SCREENSHOT_H
#define CPP_EXAMPLE_SCREENSHOT_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "opencv4/opencv2/highgui.hpp"

struct ScreenShot {
  ScreenShot(int x, int y, int width, int height) :
          x(x),
          y(y),
          width(width),
          height(height) {
    display = XOpenDisplay(nullptr);
    root = DefaultRootWindow(display);

    init = true;
  }

  void operator()(cv::Mat &cvImg) {
    if (init)
      init = false;
    else
      XDestroyImage(img);

    img = XGetImage(display, root, x, y, width, height, AllPlanes, ZPixmap);

    cvImg = cv::Mat(height, width, CV_8UC4, img->data);
  }

  ~ScreenShot() {
    if (!init)
      XDestroyImage(img);

    XCloseDisplay(display);
  }

  Display *display;
  Window root;
  int x, y, width, height;
  XImage *img;

  bool init;
};


#endif //CPP_EXAMPLE_SCREENSHOT_H
