/**
 * @file HSLAPixel.h
 *
 * @author University of Illinois CS 225 Course Staff
 * @version 2018r1-lab1 - Updated for CS 400
 */

#pragma once

#include <iostream>
#include <sstream>

namespace uiuc
{
  class HSLAPixel
  {
  public:
    double h; // hue of the pixel
    double s; // saturation of the pixel
    double l; // Luminance of the pixel
    double a; // alpha channel
  };
  // Put your HSLAPixel class definition here.
  // (Remember to end it with a semicolon!)
}
