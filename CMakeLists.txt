cmake_minimum_required(VERSION 3.2)
project(TicTacToe.exe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    GameUI.cpp
    UI/Menu.cpp
    UI/Button.cpp
    Field.cpp
    UI/Sprite.cpp
    UI/Text.cpp
    TicTacToe.cpp
    GameResources.cpp
)
list(TRANSFORM SOURCE_FILES PREPEND "src/")

add_executable(TicTacToe.exe ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
find_package( Threads )
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR} include include/UI)
    target_link_libraries(TicTacToe.exe ${SFML_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif()