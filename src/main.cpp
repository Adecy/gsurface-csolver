#include <iostream>

#include "../spike/solve_pendulum.cpp"

int main() {
    std::cout << "===============" << std::endl;

    example::SolvePendulum(0.2, 1.2);

    std::cout << "===============" << std::endl;
}
