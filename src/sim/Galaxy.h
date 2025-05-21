#pragma once

#include <random>
#include <vector>
#include "Star.h"

/**
 * @class Galaxy
 *
 * @brief Represents a galaxy, which is a collection of stars bound by gravity.
 *
 * This class stores all the stars in a vector and also stores some galactic data that can be tuned from the
 * GUI.
 *
 */
class Galaxy {
public:
    explicit Galaxy(const int numStars, const float radius): m_numStars(numStars) {
        m_stars.reserve(numStars);
        rng.seed(std::random_device{}());
    }

    ~Galaxy() = default;

    //useful functions
    void initStars();

    void reset();


    //getters
    [[nodiscard]] const std::vector<Star> &getStars() const { return m_stars; }
    [[nodiscard]] int getNumStars() const { return m_numStars; }
    [[nodiscard]] const Star &getStar(const int index) const { return m_stars[index]; }
    [[nodiscard]] Star &getStar(const int index) { return m_stars[index]; }
    [[nodiscard]] int getCurrentStarID() const { return currentStarID; }
    [[nodiscard]] float getSolarMass() const { return m_solarMass; }
    [[nodiscard]] float getLengthScale() const { return m_lengthScale; }

    //setters and stuff
    void setNumStars(const int numStars) { m_numStars = numStars; }
    void setStar(const int index, const Star &star) { m_stars[index] = star; }

private:
    std::mt19937_64 rng;
    int m_numStars;
    int currentStarID{0}; // ID for the next star to be added
    std::vector<Star> m_stars;

    //constants for scaling to n-body dimensionless units
    float m_solarMass{2e30}; // total mass of the galaxy
    float m_lengthScale{1000}; // length scale converts based on window size.
};
