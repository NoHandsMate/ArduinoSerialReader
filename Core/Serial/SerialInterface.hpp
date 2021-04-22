//
// Created by lorenzo on 20/04/21.
//

#ifndef ARDUINOSERIALREADER_SERIALINTERFACE_HPP
#define ARDUINOSERIALREADER_SERIALINTERFACE_HPP

#include <CppLinuxSerial/SerialPort.hpp>
#include <string>
#include <filesystem>
#include <chrono>
#include <thread>
#include "Log.hpp"

using namespace mn::CppLinuxSerial;


struct settings {
    std::string deviceName{};
    speed_t customRate = 0;
    std::filesystem::path path{};
    bool outputToFile = false;
};

class Interface {

public:
    settings m_settings{};

    Interface() = default;

    void startListen(LogApp& app, settings& setting) {
        app.addLog("Started listening %s with [%d] baud rate\n", setting.deviceName.c_str(), setting.customRate);

        auto deviceName = setting.deviceName;
        auto rate = setting.customRate;

        SerialPort port(deviceName, rate);
        port.SetTimeout(-1);
        port.Open();
        std::string data;
        using namespace std::chrono_literals;

       // for(int i = 0; i < 1000; i++) {
           // std::this_thread::sleep_for(500ms);
            port.Read(data);
       // }
            app.addLog("[RECEIVED:] %s\n", data.c_str());



        port.Close();
        app.addLog("Stopped listening %s\n", setting.deviceName.c_str());
    }
private:

    void read(auto& time1, auto& time2, SerialPort& port, std::string& data) {

    }
};

#endif //ARDUINOSERIALREADER_SERIALINTERFACE_HPP
