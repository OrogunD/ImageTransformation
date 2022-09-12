#pragma once

#include "uiuc/PNG.h"
using uiuc::PNG;

PNG grayscale(const PNG &image);
PNG createSpotlight(const PNG &image, int centerX, int centerY);
PNG illinify(const PNG &image);
PNG watermark(const PNG &firstImage, const PNG &secondImage);
