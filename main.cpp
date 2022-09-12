/**
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 *
 * @author University of Illinois CS 225 Course Staff
 * @author Updated by University of Illinois CS 400 Course Staff
 **/

#include "ImageTransform.h"
#include "uiuc/PNG.h"

int main()
{
  uiuc::PNG png, png2, result;

  png.readFromFile("alma.png");
  result = grayscale(png);
  result.writeToFile("out-grayscale.png");

  png.readFromFile("alma.png");
  result = illinify(png);
  result.writeToFile("out-illinify.png");

  png.readFromFile("alma.png");
  result = createSpotlight(png, 450, 150);
  result.writeToFile("out-spotlight.png");

  png.readFromFile("alma.png");
  png2.readFromFile("overlay.png");
  result = watermark(png, png2);
  result.writeToFile("out-watermark.png");

  return 0;
}
