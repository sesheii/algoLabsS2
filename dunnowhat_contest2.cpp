#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

double calculatePrice(double height, double main_radius, double shell_thickness, double shell_price) {
    if (height <= 0) {
        return 0;
    } else if (height >= 2 * main_radius) {
        return (4.0 / 3.0) * M_PI * main_radius * main_radius * main_radius + (4.0 / 3.0) * M_PI * (main_radius + shell_thickness) * (main_radius + shell_thickness) * (main_radius + shell_thickness) * shell_price;
    } else if (height < main_radius) {
        double a = height;
        double b = main_radius - sqrt(main_radius * main_radius - a * a);
        double volume = (4.0 / 3.0) * M_PI * a * a * a + (4.0 / 3.0) * M_PI * (a + b) * (a + b) * (a + b);
        return volume * shell_price;
    } else {
        double a = main_radius - height + main_radius - shell_thickness;
        double b = main_radius - sqrt(main_radius * main_radius - a * a);
        double volume = (4.0 / 3.0) * M_PI * (main_radius - a) * (main_radius - a) * (main_radius - a) - (4.0 / 3.0) * M_PI * (main_radius - b) * (main_radius - b) * (main_radius - b);
        return volume * shell_price;
    }
}



int main() {

    int main_radius, shell_thickness, shell_price, slice_price;
    std::cin >> main_radius >> shell_thickness >> shell_price >> slice_price;

    double high = main_radius*2;
    double low = 0;

    for (int i = 0; i < 128; ++i) {
        double mid = (low + high) / 2;

        if (slice_price < calculatePrice(mid, main_radius, shell_thickness, shell_price))
            high = mid;
        else
            low = mid;
    }

    std::cout << std::fixed << std::setprecision(7) << main_radius - low;

}
