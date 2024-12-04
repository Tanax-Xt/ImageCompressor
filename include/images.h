#pragma once

#include <map>
#include <vector>
#include <cstdint>

#include "colors.h"

struct UncompressedImage {
    uint32_t width = 0;
    uint32_t height = 0;
    bool is_grayscale = false;
    std::vector<std::vector<ColorRGB>> image_data;
};

struct CompressedImage {
    uint32_t width = 0;
    uint32_t height = 0;
    std::map<uint8_t, ColorRGB> id_to_color;             // pallette
    std::unordered_map<ColorRGB, uint8_t, ColorHash> color_to_id;  // inverse pallette
    std::vector<std::vector<uint8_t>> image_data;
};

bool matchUncompressedImages(const UncompressedImage& img1, const UncompressedImage& img2, bool verbose = true);