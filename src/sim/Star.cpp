#include "Star.h"

// /**
//  * Updates the star's position and velocity using Euler integration.
//  * This method updates the acceleration based on the net force acting on the star
//  * and calculates the new velocity and position over the time step.
//  * Note: Ensure that the force acting on the star is updated before calling this method.
//  *
//  * @param deltaT The time increment over which to update the position and velocity.
//  */
// void Star::updateEuler(const float deltaT) {
//     //update acceleration based on the forces, basic F=ma
//     m_acceleration = m_force / m_mass;
//
//     //update kinematic quantities with Euler integration
//     m_velocity += m_acceleration * deltaT;
//     m_position += m_velocity * deltaT;
// }
