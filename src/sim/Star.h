#pragma once
#include "Vec3.h"

/**
 * @class Star
 *
 * @brief Represents a celestial star with a position, velocity, mass, force, and acceleration.
 *
 * The Star class models a star in a 3D space with physical properties and dynamics.
 * It supports updating kinematic properties using Euler integration and provides
 * methods to get or set various physical attributes.
 * Only basic physics is implemented, no collision detection or other advanced features.
 */
class Star {
public:
    Star(const int starID, const Position3 position, const Vec3 velocity, const float mass)
        :m_starID(starID), m_position(position), m_velocity(velocity), m_mass(mass) {
    }

    ~Star() = default;

    //update/step functions
    void updateEuler(float deltaT);

    //getters
    [[nodiscard]] const Position3 &getPosition() const { return m_position; }
    [[nodiscard]] const Vec3 &getVelocity() const { return m_velocity; }
    [[nodiscard]] float getMass() const { return m_mass; }
    [[nodiscard]] Vec3 getAcceleration() const { return m_acceleration; }
    [[nodiscard]] Vec3 getForce() const { return m_acceleration * m_mass; }


    //setters
    void setForce(const Vec3 &force) { m_force = force; }
    void setPosition(const Position3 &position) { m_position = position; }
    void setVelocity(const Vec3 &velocity) { m_velocity = velocity; }
    void setMass(const float mass) { m_mass = mass; }
    void setAcceleration(const Vec3 &acceleration) { m_acceleration = acceleration; }

private:
    int m_starID{0};
    Vec3 m_force{0, 0, 0}; //force acting on the star
    Position3 m_position{0, 0, 0}; //position of the star
    Vec3 m_velocity{0, 0, 0};
    Vec3 m_acceleration{0, 0, 0};
    float m_mass{0};
};
