#include <iostream>

#include "../spike/solve_pendulum.cpp"

#include <xtensor/xarray.hpp>

int main() {
    std::cout << "===============" << std::endl;

    example::SolvePendulum(0.2, 1.2);

    std::cout << "===============" << std::endl;

    /***************************************************/

    // https://xtensor.readthedocs.io/en/latest/getting_started.html#first-example
    xt::xarray<double> arr
            {{1.0, 2.0, 3.0},
             {2.0, 5.0, 7.0},
             {2.0, 5.0, 7.0}};

    std::cout << arr << std::endl;
}
