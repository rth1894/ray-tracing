#include <fstream>
#include <vector>

using namespace std;
struct Pixel {
    unsigned char r, g, b;
};

int main() {
    const int HEIGHT = 200, WIDTH = 200;

    const int CENTER_X = WIDTH / 2;
    const int CENTER_Y = HEIGHT / 2;
    const int RADIUS = 75;
    int x_minus_h_squared, y_minus_k_squared;

    vector<vector<Pixel>> image(HEIGHT, vector<Pixel>(WIDTH));

    for (int i=0; i<HEIGHT; i++)
        for (int j=0; j<WIDTH; j++)
            image[j][i] = {255, 255, 255};

    //(x-h)^2 + (y-k)^2 = r^2
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            x_minus_h_squared = (j - CENTER_X) * (j - CENTER_X);
            y_minus_k_squared = (i - CENTER_Y) * (i - CENTER_Y);

            if (x_minus_h_squared + y_minus_k_squared <= RADIUS * RADIUS)
                image[j][i] = {0, 0, 0};
        }
    }

    ofstream image_file("image_circle.ppm");

    image_file << "P3\n"
               << WIDTH << " " << HEIGHT << "\n"
               << "255" // max rgb val
               << "\n";

    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            image_file << static_cast<int> (image[j][i].r) << " "
                       << static_cast<int> (image[j][i].g) << " "
                       << static_cast<int> (image[j][i].b) << " ";
        }
        image_file << "\n";
    } 

    image_file.close();
    return 0;
}
