#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
(Begin multi-line comment...)

Write your name and email address in the comment space here:

Name: Orogun Daniel
Email:  orogund10@gmail.com

(...end multi-line comment.)
******************** */

using uiuc::HSLAPixel;
using uiuc::PNG;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(const PNG &image)
{
    /// This function is already written for you so you can see how to
    /// interact with our PNG class.
    for (unsigned x = 0; x < image.width(); x++)
    {
        for (unsigned y = 0; y < image.height(); y++)
        {
            HSLAPixel &pixel = image.getPixel(x, y);

            // `pixel` is a reference to the memory stored inside the PNG `image`,
            // which means you're changing the image directly. No need to `set`
            // the pixel since you're directly changing the memory of the image.
            pixel.s = 0;
        }
    }
    return image;
}
/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 *
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */

PNG createSpotlight(const PNG &image, int centerX, int centerY)
{
    const double MIN_L_MULTIPLIER = 0.20;
    const double MAX_DISTANCE = (1 - MIN_L_MULTIPLIER) / 0.005;
    for (unsigned x = 0; x < image.width(); x++)
    {
        for (unsigned y = 0; y < image.height(); y++)
        {
            const int deltaX = (int)x - centerX, deltaY = (int)y - centerY;
            const double distance = sqrt((deltaX * deltaX) + (deltaY * deltaY));

            double lMultiplier = MIN_L_MULTIPLIER;
            if (distance < MAX_DISTANCE)
            {
                lMultiplier = 1.0 - (distance * 0.005);
            }

            HSLAPixel &pixel = image.getPixel(x, y);
            pixel.l *= lMultiplier;
        }
    }
    return image;
}

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
 **/
PNG illinify(const PNG &image)
{
    const double midpoint = (11 + 216) / 2.0;

    for (unsigned x = 0; x < image.width(); x++)
    {
        for (unsigned y = 0; y < image.height(); y++)
        {
            HSLAPixel &pixel = image.getPixel(x, y);

            if (pixel.h < midpoint || pixel.h > (midpoint + 180.0))
            {
                pixel.h = 11.0;
            }
            else
            {
                pixel.h = 216.0;
            }
        }
    }
    return image;
}

/**
 * Returns an image that has been watermarked by another image.
 *
 * The luminance of every pixel of the second image is checked, if that
 * pixel's luminance is 1 (100%), then the pixel at the same location on
 * the first image has its luminance increased by 0.2.
 * @param firstImage  The first of the two PNGs, which is the base image.
 * @param secondImage The second of the two PNGs, which acts as the stencil.
 *
 * @return The watermarked image.
 */
PNG watermark(const PNG &firstImage, const PNG &secondImage)
{
    for (unsigned x = 0; x < firstImage.width(); x++)
    {
        for (unsigned y = 0; y < firstImage.height(); y++)
        {
            HSLAPixel &secondPixel = secondImage.getPixel(x, y);
            if (secondPixel.l == 1.0)
            {
                HSLAPixel &firstPixel = firstImage.getPixel(x, y);
                firstPixel.l += 0.2;
            }
        }
    }
    return firstImage;
}
