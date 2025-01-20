#include "image_transforms.h"
#include "error_handlers.h"

void fillGapPixels(UncompressedImage& img, std::vector<std::vector<bool>>& is_gap_pixel) {
    // fill the gaps with nearest neighbour interpolation
    // in particular, for each pixel that is a gap pixel, replace it with the average of its neighbours
    // that are not gap pixels
}

void rotate(UncompressedImage& img, int angle, ColorRGB fill_color, bool smart_gap_interpolation) {
    /*
    * Rotates the image by the given angle
    * fill_color is the color of the pixels that are not covered by the original image
    * if smart_gap_interpolation flag is up, then the function should fill the gaps with nearest neighbour interpolation
    */
}

void applyKernel(UncompressedImage& img, const std::vector<std::vector<int>>& kernel, int divisor) {
    /*
    * Applies kernel to the image
    * Mind the edge cases and their handling (how to handle pixels that are out of bounds)
    */

    // read about std::clamp and think about how it can be used for edge cases here

}

// refer to https://en.wikipedia.org/wiki/Kernel_(image_processing)#Details
// for exact kernel

void sharpen(UncompressedImage& img) {
}

void gaussianBlurApprox(UncompressedImage& img, bool hard_blur) {
}

void edgeDetect(UncompressedImage& img) {
}

void negative(UncompressedImage& img) {
    // change the color of each id to its negative
    // negative of a color is 255 - color for each channel
    for (long long y = 0; y < img.height; ++y) {
        for (long long x = 0; x < img.width; ++x) {
            ColorRGB& pixel = img.image_data[y][x];
            pixel.r = 255 - pixel.r;
            pixel.g = 255 - pixel.g;
            pixel.b = 255 - pixel.b;
        }
    }
}

void negative(CompressedImage& img) {
}

void toGrayscale(UncompressedImage& img) {
    // convert the image to grayscale
    // so, for each pixel, change its color to grayscale
    // if it is already grayscale, do nothing
}

void toGrayscale(CompressedImage& img) {
    // convert the image to grayscale
    // so, for each id, change its color to grayscale
}