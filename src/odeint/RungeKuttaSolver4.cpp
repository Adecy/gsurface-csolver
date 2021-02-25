//
// Created by Lucas Dietrich on 25/02/2021.
//

#include "RungeKuttaSolver4.h"

#include <xtensor/xview.hpp>
#include <utility>

RungeKuttaSolver4::RungeKuttaSolver4(diff_state_func_t derivs, state_t s0) : derivs(derivs), s0(std::move(s0)) {

}

state_t RungeKuttaSolver4::solve(xt::xarray<double> t) {
    double ti, dt;
    xt::xarray<double> ds, si;

    // eval final states array dimension
    unsigned int epochs = t.shape(0);
    unsigned int width  = this->s0.shape(0);
    xt::xarray<double> states = xt::zeros<double>({epochs, width});

    // setup current state vector
    si = xt::view(this->s0, xt::all());

    // todo: simplify
    // write current state vector in states array
    for(int i = 0; i < width; i++)
        states(0, i) = si(i);

    for(int epoch = 0; epoch < epochs - 1; epoch++) {
        // eval next state
        ti = t[epoch];
        dt = t[epoch + 1] - ti;
        ds = rk4_ds(si, ti, dt);
        si += ds;

        // todo: simplify
        // write current state vector in states array
        for(int i = 0; i < width; i++)
            states(epoch + 1, i) = si(i);
    }

    return states;
}

state_t RungeKuttaSolver4::rk4_ds(state_t s, double t, double dt) const {
    state_t ds1, ds2, ds3, ds4;

    ds1 = this->derivs(s, t) * dt;
    ds2 = this->derivs(s + ds1 / 2, t + dt / 2) * dt;
    ds3 = this->derivs(s + ds2 / 2, t + dt / 2) * dt;
    ds4 = this->derivs(s + ds3, t + dt) * dt;

    return (ds1 + ds4)/6 + (ds2 + ds2)/3;
}
