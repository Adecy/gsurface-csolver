#include <iostream>

#include "../spike/solve_pendulum.cpp"

#include "odeint/RungeKuttaSolver.h"

#include <xtensor/xnpy.hpp>

state_t ds(state_t S, double t) {
    state_t dS = xt::zeros<double>(S.shape());

    dS[0] = S[1];
    dS[1] = -S[0];

    return dS;
}

// https://xtensor.readthedocs.io/en/latest/getting_started.html#first-example
int main() {
    state_t s0 = {1.0, 0.0};

    xt::xarray<double> time = xt::linspace<double>(0.0, 10.0, 1000);

    RungeKuttaSolver rk4solver = RungeKuttaSolver(ds, s0);

    xt::xarray<double> states = rk4solver.solve(time);

    xt::dump_npy<xt::xarray<double>>("/home/adecy/states.npy", states);

    std::cout << "===============" << std::endl;
    std::cout << "s0 = " << rk4solver.s0 << std::endl;
    std::cout << "shape = " << states.shape(0) << "," << states.shape(1) << std::endl;
    std::cout << xt::view(states, xt::range(980, 1000), xt::all()) << std::endl;
    std::cout << "===============" << std::endl;
}
