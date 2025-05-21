#include "Galaxy.h"

void Galaxy::initStars() {
    m_stars.clear();
    m_stars.reserve(m_numStars);
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    float Rd = 0.3f; //length scale for disk
    float Rz = 0.1f; //length scale for z
    for (int i = 0; i < m_numStars; i++) {
        //Position3 pos = {static_cast<float>(rand() % static_cast<int>(m_lengthScale)),
        //static_cast<float>(rand() % static_cast<int>(m_lengthScale)), 0};
        //const Vec3 velocity = {0, 0, 0};
        //pos /= m_lengthScale; // Scale position to the length scale
        //randomly generate a mass centered around 2e30
        float mass = 2e30 * (rand() % 1000) / 1000;
        mass /= m_solarMass; // Scale mass to the solar mass

        const float x = dist(rng);
        const float R = -Rd * std::log(1 - x);
        const float theta = 2 * M_PI * dist(rng);
        const float y = dist(rng);
        const float z = -Rz * std::log(1 - y);
        Vec3 pos{R * std::cos(theta), R * std::sin(theta), z};
        float velocity = dist(rng);
        Vec3 vel{-velocity * std::cos(theta), velocity * std::sin(theta), 0};
        pos += {0.5f, 0.5f, 0}; // Center the galaxy
        auto star = Star(i, pos, vel, mass);
        m_stars.push_back(star);
    }
}


void Galaxy::reset() {
    m_stars.clear();
    currentStarID = 0;
    m_numStars = 0;
}
