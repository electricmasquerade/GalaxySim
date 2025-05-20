# GalaxySim

This project simulates the motion of stars and solar systems in a galaxy. Uses basic
laws of universal gravitation and Newton's laws of motion to calculate the positions and velocities. Uses
Euler's method for integration (maybe?) to update positions and ImGui/SFML3.0 for rendering. Plans include 
exporting to Blender, either a csv or mesh or something. 

## Structure
The project is structured into three main modules:

- **src**: Contains the main application code, including the GUI and simulation logic.
  - **Sim**: folder for most simulation code
    - **main.cpp**: The entry point of the application.
    - **Galaxy.h/.cpp**: Contains the class for the galaxy, holding lists of stars and galactic properties
    - **Star.h/.cpp**: Contains the class for the stars, holding their position, velocity, mass, etc.
    - **GalaxySim.h/.cpp**: Contains the class for the simulation, handling the physics and updating positions.
  - **Render**: folder for rendering code
    - **RenderLayer.h/.cpp**: Contains the class for rendering the galaxy and stars using SFML.

## Roadmap
- [x] Basic setup with GUI and class definitions
- [ ] Create a star / system class
- [ ] Create a galaxy class to hold stars
- [ ] Add render layer
- [ ] Add physics layer and actually simulate
- [ ] Add more controls and stuff to the GUI
- [ ] Optimize, probably with multithreading
- [ ] Export to Blender/csv
- [ ] Add more features, like a black hole or something, maybe

## References
- https://en.wikipedia.org/wiki/Galaxy_rotation_curve
- http://www.astronomynotes.com/galaxy/s5.htm