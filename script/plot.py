import numpy as np
import matplotlib.pyplot as plt

states = np.load("./states.npy")

time = np.linspace(0, 10, 1000)

plt.figure(1)
plt.plot(time, states)
plt.xlabel("time (sec)")
plt.ylabel("amp [1]")
plt.title("Runge-Kutta C++ Solver with xtensor on 2nd order ODE")
plt.show()