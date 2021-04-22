//
// Created by lorenzo on 18/04/21.
//

#ifndef ARDUINOSERIALREADER_WINDOW_HANDLER_HPP
#define ARDUINOSERIALREADER_WINDOW_HANDLER_HPP

#include <imgui.h>
#include <imgui-SFML.h>

#include "../Serial/Log.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>



#include "../Serial/SerialInterface.hpp"

class WindowHandler {
public:
    explicit WindowHandler() {
        winFlags |= ImGuiWindowFlags_NoMove;
        winFlags |= ImGuiWindowFlags_NoResize;
        winFlags |= ImGuiWindowFlags_NoCollapse;
        winFlags |= ImGuiWindowFlags_MenuBar;
    }

    explicit WindowHandler(const unsigned int width, const unsigned int height)
        : windowHeight(width)
        , windowWidth(height)
    {
        winFlags |= ImGuiWindowFlags_NoMove;
        winFlags |= ImGuiWindowFlags_NoResize;
        winFlags |= ImGuiWindowFlags_NoCollapse;
        winFlags |= ImGuiWindowFlags_MenuBar;
    }


    void mainLoop();

private:
    void scene();
    void debugConsole();

    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 600;
    ImGuiWindowFlags winFlags{};
    Interface serialHandler{};
    LogApp logApp;
};

#endif //ARDUINOSERIALREADER_WINDOW_HANDLER_HPP
