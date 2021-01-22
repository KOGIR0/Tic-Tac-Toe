cmake_minimum_required(VERSION 3.2)
project(TicTacToe.exe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Button.cpp src/Field.cpp src/Sprite.cpp src/Text.cpp src/TicTacToe.cpp)
add_executable(TicTacToe.exe ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR} include)
    target_link_libraries(TicTacToe.exe ${SFML_LIBRARIES})
endif()