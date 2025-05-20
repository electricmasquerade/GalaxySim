
#include "RenderLayer.h"

void RenderLayer::buildStars() {
    //loop through the galaxy stars to add them to the vertex array
    m_stars.clear();
    m_stars.setPrimitiveType(sf::PrimitiveType::Points);
    m_stars.resize(m_galaxy.getNumStars());

    for (int i = 0; i < m_galaxy.getNumStars(); i++) {
        const auto &star = m_galaxy.getStar(i);
        // Create a point for the star
        sf::Vertex starVertex;
        starVertex.position = {star.getPosition().x(), star.getPosition().y()};
        starVertex.color = sf::Color::White; // Set color for the star
        m_stars[i] = starVertex;
    }

}

void RenderLayer::renderStars() const {
    m_window.draw(m_stars);
}
