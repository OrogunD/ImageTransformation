#pragma once

#include "uiuc/PNG.h"
using namespace uiuc;

PNG grayscale(const PNG& image);
PNG createSpotlight(PNG image, int centerX, int centerY);
PNG illinify(const PNG& image);
PNG watermark(const PNG& firstImage, const PNG& secondImage);
