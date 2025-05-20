#pragma once

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
    explicit Galaxy(const int numStars):m_numStars(numStars){}

    ~Galaxy() = default;

    //useful functions
    void initStars();
    void reset();

private:
    int m_numStars;
    std::vector<Star> m_stars;


};
