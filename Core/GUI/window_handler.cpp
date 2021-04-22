//
// Created by lorenzo on 18/04/21.
//

#include <iostream>
#include <array>
#include <string>
#include "window_handler.hpp"


void WindowHandler::mainLoop() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Arduino Serial Reader");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);


    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        scene();
        debugConsole();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}

void WindowHandler::scene() {
    const ImGuiViewport *mainViewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(mainViewport->WorkPos.x + 400, mainViewport->WorkPos.y),
                            ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(550, 660), ImGuiCond_FirstUseEver);

    static char deviceName[128]{};
    static char filepath[128]{};
    static int baudRate = 0;
    static bool outputFileCheck = false;

    if (!ImGui::Begin("Menu", nullptr, winFlags)) {
        ImGui::End();
        return;
    }

    if(ImGui::TreeNode("Settings")) {
        ImGui::Text("Insert Device Name (Ex. /dev/ttyACM0): ");
        ImGui::SameLine();
        ImGui::InputText(" ", deviceName, IM_ARRAYSIZE(deviceName));

        if(ImGui::IsItemDeactivated())
            logApp.addLog("Set the device name to: %s\n", deviceName);

        ImGui::Separator();
        ImGui::Text("Baud Rate:");
        ImGui::SameLine();
        ImGui::InputInt(".",  &baudRate);

        if(ImGui::IsItemDeactivated())
            logApp.addLog("Set BaudRate to: %d\n", baudRate);

        ImGui::Separator();
        ImGui::Checkbox("Output the data to file", &serialHandler.m_settings.outputToFile);

        if(serialHandler.m_settings.outputToFile) {
            ImGui::Text("Filepath: ");
            ImGui::SameLine();

            ImGui::InputText("_", filepath, IM_ARRAYSIZE(filepath));

            if(ImGui::IsItemDeactivated()) {
                logApp.addLog("Set %s as output path\n", filepath);
            }


        }

        ImGui::TreePop();
    }

    serialHandler.m_settings.path = filepath;
    serialHandler.m_settings.deviceName = deviceName;
    serialHandler.m_settings.customRate = baudRate;

    if(ImGui::Button("Start Listening", ImVec2(300, 50))) {
        serialHandler.startListen(logApp, serialHandler.m_settings);
    }
    ImGui::End();
}

void WindowHandler::debugConsole() {

    const ImGuiViewport *mainViewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(ImVec2(mainViewport->WorkPos.x, mainViewport->WorkPos.y),
                            ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(550, 660), ImGuiCond_FirstUseEver);
    const char* label = "Console";

    ImGui::Begin(label, nullptr, winFlags);
    logApp.show(label);
    ImGui::End();
}


