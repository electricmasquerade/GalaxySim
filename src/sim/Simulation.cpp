
#include "Simulation.h"

void Simulation::updateEuler(const float deltaT) const {
    //update all the stars in the galaxy
    for (int i = 0; i < m_galaxy.getNumStars(); i++) {
        auto &star = m_galaxy.getStar(i);
        //perform euler integration
        star.setAcceleration(star.getForce() / star.getMass());
        star.setVelocity(star.getVelocity() + star.getAcceleration() * deltaT);
        star.setPosition(star.getPosition() + star.getVelocity() * deltaT);
        //reset force for next iteration
        star.setForce({0, 0, 0});
        std::cout << star.getAcceleration() << std::endl;
    }
}

void Simulation::updateForces(const float deltaT) const {
    //update forces acting on the stars
    for (int i = 0; i < m_galaxy.getNumStars(); i++) {
        auto &star = m_galaxy.getStar(i);
        //calculate forces acting on the star based on other stars
        for (int j = i+1; j < m_galaxy.getNumStars(); j++) {
            auto &star2 = m_galaxy.getStar(j);
            //use universal law of gravitation, force = G * m1 * m2 / r^2
            auto distance = m_galaxy.getStar(j).getPosition() - star.getPosition();
            auto distanceSqMagnitude = distance.lengthSquared();
            auto distanceSoftened = distanceSqMagnitude + 0.01f; //softening factor to avoid singularity
            if (distanceSqMagnitude > 0) {
                const auto forceMagnitude = (m_gravityConstant * star.getMass() * m_galaxy.getStar(j).getMass()) /
                                      (distanceSoftened);
                auto force = forceMagnitude * unitVector(distance);
                star.setForce(star.getForce() + force);
                //std::cout << star.getForce() << std::endl;
                star2.setForce(star2.getForce() - force);
            }
        }
    }
}