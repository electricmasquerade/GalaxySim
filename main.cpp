#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Window/Event.hpp>
#include "RenderLayer.h"
#include "Galaxy.h"
#include "Simulation.h"


int main() {
    // Create the main window
    constexpr unsigned windowWidth = 1000;
    constexpr unsigned windowHeight = windowWidth * 0.8;
    sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "Maze Algorithms");
    window.setFramerateLimit(120);
    // ReSharper disable once CppNoDiscardExpression
    ImGui::SFML::Init(window);
    sf::Clock deltaClock;

    //render layer stuff here
    int numStars = 3000;


    Galaxy galaxy(numStars);
    Simulation simulation(galaxy);

    galaxy.initStars();

    RenderLayer render(window, galaxy);



    while (window.isOpen()) {
        // Process events, including window close
        while (const auto event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event);

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (const auto *resized = event->getIf<sf::Event::Resized>()) {
                // Update the view to the new size of the window
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }
        }
        sf::Time deltaTime = deltaClock.restart();
        ImGui::SFML::Update(window, deltaTime);

        //handle render stuff, split to a side window
        window.clear(sf::Color::Black);

        sf::View galaxyView = window.getDefaultView();
        galaxyView.setViewport(sf::FloatRect{{0.2f, 0.0f}, {0.8f, 1.0f}});
        window.setView(galaxyView);
        // Put render and sim code here

        simulation.updateForces(deltaTime.asSeconds());
        simulation.updateEuler(deltaTime.asSeconds());
        render.buildStars();
        render.renderStars();


        //split controls back to the left of screen
        window.setView(window.getDefaultView());
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
        ImGui::SetNextWindowSize({window.getSize().x * 0.2f, windowHeight * 0.2}, ImGuiCond_Always);
        ImGui::SetNextWindowBgAlpha(0.5f);
        ImGui::Begin("Controls", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
        ImGui::Text("Controls");
        if (ImGui::Button("Test")) {
            //generate some test stars
            galaxy.initStars();
            render.buildStars();
            //render.renderStars();
        }
        const ImVec2 settingsPos = ImGui::GetWindowSize();


        ImGui::End();

        ImGui::SetNextWindowPos(ImVec2(0, settingsPos.y), ImGuiCond_Always);
        ImGui::SetNextWindowSize({window.getSize().x * 0.2f, windowHeight * 0.1}, ImGuiCond_Always);
        ImGui::SetNextWindowBgAlpha(0.5f);
        //ImGui::SetNextWindowSize(ImVec2(200, 100));
        ImGui::Begin("Simulation Data", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
        ImGui::Text("Frame Rate: %.1f FPS", 1.0f / ImGui::GetIO().DeltaTime);
        ImGui::End();


        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
