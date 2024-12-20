#include <iostream>
#include <cmath>

int main() {
    double a = 1.7, b = 2.3;
    double hx = 0.9, hy = 1.0;
    double x_min = -1, x_max = 1;
    double y_min = -2, y_max = 2;

    for (double x = x_min; x <= x_max; x += hx) {
        for (double y = y_min; y <= y_max; y += hy) {
            double z;
            if (x * y > 0) {
                z = log(sqrt(a * pow(x, 2) + b * pow(y, 3)));
            }
            else {
                z = pow(a, x) + pow(b, y);
            }

            std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
        }
    }

    return 0;
}