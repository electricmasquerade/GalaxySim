#pragma once

#include "Galaxy.h"

class Simulation {
public:

    explicit Simulation(Galaxy &galaxy) : m_galaxy(galaxy) {
    }

    ~Simulation() = default;

    //useful stuff
    void updateEuler(float deltaT) const;
    void updateForces() const;
    void reset() const { m_galaxy.reset(); }

    void setTimeScale(const float timeStep) { m_timeStep = timeStep; }
private:
    Galaxy &m_galaxy;
    float m_gravityConstant{1.0f}; // Gravitational constant
    float m_timeStep{0.00005}; // Time scale
};
