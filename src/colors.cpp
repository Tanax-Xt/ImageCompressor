#include "colors.h"

uint8_t colorToGrayscale(const ColorRGB& color) {
    /*
        return the average of the three color components
    */
    return (color.r + color.g + color.b) / 3;
}

ColorRGB readFromFileStream(std::fstream& stream) {
    /*
     * The color is stored as three bytes in the order R, G, B.
     * We read the bytes from the stream and return the color as ColorRGB structure.
     */
    ColorRGB color;
    stream.read(reinterpret_cast<char*>(&color.r), sizeof(color.r));
    stream.read(reinterpret_cast<char*>(&color.g), sizeof(color.g));
    stream.read(reinterpret_cast<char*>(&color.b), sizeof(color.b));
    return color;
}

int64_t colorDistanceSq(const ColorRGB& color1, const ColorRGB& color2) {
    /*
     * The distance between two colors is defined as the square of the Euclidean distance between
     * them. The Euclidean distance between two points (x1, y1, z1) and (x2, y2, z2) is defined as
     * sqrt((x1 - x2)^2 + (y1 - y2)^2 + (z1 - z2)^2).
     * Since the square root is a monotonic function, we can compare the distances without taking
     * the square root. The distance between two colors (r1, g1, b1) and (r2, g2, b2) is defined as
     * (r1 - r2)^2 + (g1 - g2)^2 + (b1 - b2)^2.
     */
    return std::sqrt(
        (color1.r - color2.r) * (color1.r - color2.r)
        + (color1.g - color2.g) * (color1.g - color2.g)
        + (color1.b - color2.b) * (color1.b - color2.b));
}
