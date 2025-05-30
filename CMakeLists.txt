cmake_minimum_required(VERSION 3.30.5)
project(GalaxySim)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(IMGUI_VERSION "1.91.9b")
set(SFML_VERSION "3.0.0")

set (IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/imgui")

# Find SFML (assuming installed via Homebrew)
#find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)
include(FetchContent)

FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        imgui
        URL "https://github.com/ocornut/imgui/archive/v${IMGUI_VERSION}.zip"
)
FetchContent_MakeAvailable(imgui)


add_library(imgui STATIC
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp

)

set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_Declare(
        imgui-sfml
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
        GIT_TAG v3.0
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(imgui-sfml)

include_directories("src/utils"
        "src/sim"
        "src/render"
        "include"
        ${SFML_INCLUDE_DIRS}
        ${imgui_SOURCE_DIR}
        ${imgui-SFML_SOURCE_DIR}/include
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(GalaxySim main.cpp
        src/sim/Star.cpp
        src/sim/Star.h
        src/utils/Vec3.cpp
        src/utils/Vec3.h
        src/sim/Galaxy.cpp
        src/sim/Galaxy.h
        src/render/RenderLayer.cpp
        src/render/RenderLayer.h
        src/sim/Simulation.cpp
        src/sim/Simulation.h)


target_link_libraries(GalaxySim PRIVATE
        SFML::System
        SFML::Window
        SFML::Graphics
        SFML::Audio
        imgui
        ImGui-SFML::ImGui-SFML
)