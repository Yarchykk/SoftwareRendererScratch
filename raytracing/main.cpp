#include <algorithm>
#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

//Struct for storing a color value
struct Color { 
    int r; 
    int g; 
    int b; 
};

// Canvas Object 
    //Intakes w,h for initializing the canvas size

class Canvas {
public:
    Canvas(int w, int h) : 
    width(w), 
    height(h), 
    pixels(w * h * 3) //generate vector of size, #ofPixels (w*h) * 3 for each pixel's rgb values
    //each 
    {

    }

    void putPixel(int x, int y, Color c) {
        int sx = width / 2 + x;
        int sy = height / 2 - y;
        if (sx < 0 || sx >= width || sy < 0 || sy >= height) return;
        int i = 3 * (sy * width + sx);
        pixels[i]     = toByte(c.r);
        pixels[i + 1] = toByte(c.g);
        pixels[i + 2] = toByte(c.b);
    }

    void savePPM(const std::string& path) const {
        std::ofstream f(path, std::ios::binary);
        f << "P6\n" << width << " " << height << "\n255\n";
        f.write(reinterpret_cast<const char*>(pixels.data()), pixels.size());
    }

    const int width, height;

private:
    std::vector<uint8_t> pixels;
    static uint8_t toByte(double v) {
        return static_cast<uint8_t>(std::clamp(v, 0.0, 255.0));
    }
};

int main() {
    Canvas canvas(600, 600);
    for (int x = -canvas.width / 2; x < canvas.width / 2; ++x)
        for (int y = -canvas.height / 2; y < canvas.height / 2; ++y)
            canvas.putPixel(x, y, {(x + 300) * 255.0 / 600, (y + 300) * 255.0 / 600, 128});
            // c = 
            // canvas.putPixel(x,y,c);
    canvas.savePPM("outputSquare.ppm");
}