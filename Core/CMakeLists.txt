
set(ExeName ${PROJECT_NAME})
set(SFML_LINK sfml-system sfml-window sfml-graphics sfml-audio)
add_executable(ExeName main.cpp)
target_link_libraries(ExeName PUBLIC IMGUI GUI SERIAL GL ${SFML_LINK})