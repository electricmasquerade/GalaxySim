#include "Galaxy.h"

void Galaxy::initStars() {
    m_stars.clear();
    m_stars.reserve(m_numStars);
    for (int i = 0; i < m_numStars; i++) {
        auto star = Star(i, {static_cast<float>(rand() % 1000), static_cast<float>(rand() % 1000), 0},
                         {0, 0, 0},
                         2e12f);
        m_stars.push_back(star);
    }
}

void Galaxy::reset() {
    m_stars.clear();
    currentStarID = 0;
    m_numStars = 0;
}
