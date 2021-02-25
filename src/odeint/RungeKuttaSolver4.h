//
// Created by ldade on 25/02/2021.
//

#ifndef INC_2021___CSOLVER_RUNGEKUTTASOLVER4_H
#define INC_2021___CSOLVER_RUNGEKUTTASOLVER4_H

#include <xtensor/xarray.hpp>
#include <xtensor/xaccessible.hpp>


typedef xt::xarray<double> state_t;

typedef state_t (*diff_state_func_t)(state_t, double);

// TODO optimize data copy/storage (pointers ...)
class RungeKuttaSolver4 {

public:
    diff_state_func_t derivs;
    state_t s0;

    RungeKuttaSolver4(diff_state_func_t derivs, state_t s0);

    state_t solve(xt::xarray<double> t);

protected:
    state_t rk4_ds(state_t s, double t, double dt) const;
};


#endif //INC_2021___CSOLVER_RUNGEKUTTASOLVER4_H
