//
// Created by ldade on 18/02/2021.
//
#include <iostream>
#include <cmath>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

namespace example {
    class SolvePendulum {
        public:

        double theta0;
        double w0;

        explicit SolvePendulum(double theta0 = 0.0, double w0 = 1.0) : theta0(theta0), w0(w0) {
            printf("Initial state parameters : theta0 = %f, w0 = %f\n", this->theta0, this->w0);
        }
    };
}

