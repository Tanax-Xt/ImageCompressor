#pragma once

#include <cstdint>
#include <fstream>
#include <functional>
#include <cmath>

struct ColorRGB {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    bool operator==(const ColorRGB& other) const {
        return r == other.r && g == other.g && b == other.b;
    }

    bool operator!=(const ColorRGB& other) const { return !(*this == other); }
};

inline std::ostream& operator<<(std::ostream& os, const ColorRGB& color) {
    os << "ColorRGB(" << static_cast<int>(color.r) << ", " << static_cast<int>(color.g) << ", "
       << static_cast<int>(color.b) << ")";
    return os;
}

struct ColorHash {
    size_t operator()(const ColorRGB& color) const {
        return (std::hash<uint8_t>()(color.r) << 16) ^ (std::hash<uint8_t>()(color.g) << 8)
               ^ std::hash<uint8_t>()(color.b);
    }

    bool operator()(const ColorRGB& color_1, const ColorRGB& color_2) const {
        return color_1 == color_2;
    }
};

int64_t colorDistanceSq(const ColorRGB& color1, const ColorRGB& color2);

uint8_t colorToGrayscale(const ColorRGB& color);

ColorRGB readFromFileStream(std::fstream& stream);
