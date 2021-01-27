cmake_minimum_required(VERSION 3.2)
project(TicTacToe.exe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    GameUI.cpp
    Menu.cpp
    Button.cpp
    Field.cpp
    Sprite.cpp
    Text.cpp
    TicTacToe.cpp
    GameResources.cpp
    Client.cpp
    Server.cpp
)
list(TRANSFORM SOURCE_FILES PREPEND "src/")

add_executable(TicTacToe.exe ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR} include)
    target_link_libraries(TicTacToe.exe ${SFML_LIBRARIES})
endif()