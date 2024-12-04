#include "images.h"
#include <iostream>

bool matchUncompressedImages(const UncompressedImage& img1, const UncompressedImage& img2, bool verbose) {
    for (size_t i = 0; i < img1.height; ++i) {
        for (size_t j = 0; j < img1.width; ++j) {
            if (img1.image_data[i][j] != img2.image_data[i][j]) {
                if (verbose) {
                    printf("Mismatch at coordinates (%zu, %zu) expected (%d, %d, %d) got (%d, %d, %d)\n",
                           i, j, img1.image_data[i][j].r, img1.image_data[i][j].g, img1.image_data[i][j].b,
                           img2.image_data[i][j].r, img2.image_data[i][j].g, img2.image_data[i][j].b);
                }
                return false;
            }
        }
    }
    return true;
}
