//
// Created by lorenzo on 21/04/21.
//

#ifndef ARDUINOSERIALREADER_LOG_HPP
#define ARDUINOSERIALREADER_LOG_HPP

#include "../ImGui/headers/imgui.h"

struct LogApp {
    // Thanks to the code into imgui_demo.cpp that explains how to do a logging app
    ImGuiTextBuffer buffer;
    ImVector<int>   lineOffset;
    bool autoScroll;

    LogApp() {
        autoScroll = true;
    }

    void clear() {
        buffer.clear();
        lineOffset.clear();
        lineOffset.push_back(0);
    }

    void addLog(const char* item, ...) IM_FMTARGS(2)
    {
        // The Text Buffer is filled with all the logging info
        int oldSize = buffer.size();
        va_list args; // Hold all the argument passed into ...
        va_start(args, item);
        buffer.appendfv(item, args);
        va_end(args);

        //if we encounter a newline, add a new line
        for(std::size_t newSize = buffer.size(); oldSize < newSize; oldSize++) {
            if(buffer[oldSize] == '\n') {
                lineOffset.push_back(oldSize + 1);
            }
        }
    }

    void show(const char* label, bool* p_open = nullptr) const {
        if(!ImGui::Begin(label, p_open)) {
            ImGui::End();
            return;
        }

        ImGui::BeginChild("scrolling", ImVec2(0,0), false, ImGuiWindowFlags_HorizontalScrollbar);
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0,0));
        auto bufferStart = buffer.begin();
        auto bufferEnd = buffer.end();

        ImGui::TextUnformatted(bufferStart, bufferEnd);
        ImGui::PopStyleVar();

        if(autoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) {
            ImGui::SetScrollHereY(1.0f);
        }

        ImGui::EndChild();
        ImGui::End();
    }
};

#endif //ARDUINOSERIALREADER_LOG_HPP
