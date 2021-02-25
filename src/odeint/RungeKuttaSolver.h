//
// Created by ldade on 25/02/2021.
//

#ifndef INC_2021___CSOLVER_RUNGEKUTTASOLVER_H
#define INC_2021___CSOLVER_RUNGEKUTTASOLVER_H

#include <xtensor/xarray.hpp>
#include <xtensor/xaccessible.hpp>


// std::array<std::size_t, 2> sh1 = {2, 4};

typedef xt::xarray<double> state_t;

typedef state_t (*diff_state_func_t)(state_t, double);


class RungeKuttaSolver {

public:
    diff_state_func_t derivs;
    state_t s0;

public:
    RungeKuttaSolver(diff_state_func_t derivs, state_t s0);

    state_t rk4_ds(state_t s, double t, double dt) const;

    state_t solve(xt::xarray<double> t);
};


#endif //INC_2021___CSOLVER_RUNGEKUTTASOLVER_H
