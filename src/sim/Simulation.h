#pragma once

#include "Galaxy.h"

class Simulation {
public:

    explicit Simulation(Galaxy &galaxy) : m_galaxy(galaxy) {
    }

    ~Simulation() = default;

    //useful stuff
    void updateEuler(float deltaT) const;
    void updateForces(float deltaT) const;
private:
    Galaxy &m_galaxy;
    float m_gravityConstant{0.00000000006674f}; // Gravitational constant
};
