#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Galaxy.h"

class RenderLayer {
    //this class handles drawing all the layers of the city
public:
    explicit RenderLayer(sf::RenderWindow &window, const Galaxy &galaxy)
        : m_window(window), m_galaxy(galaxy) {
    }

    void buildStars();
    void renderStars() const;

private:
    sf::RenderWindow &m_window;
    const Galaxy &m_galaxy;
    sf::VertexArray m_stars;
};
