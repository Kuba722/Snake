cmake_minimum_required(VERSION 3.10)

project(Snake)

set(CMAKE_CXX_STANDARD 17)

add_executable(Snake
    src/main.cpp
    src/game.cpp
    src/button.cpp
    src/map.cpp
    src/snake.cpp
    src/food.cpp
    src/textbox.cpp
    src/playState.cpp
    src/endState.cpp     
    src/menuState.cpp    
    src/nameState.cpp     
    src/rankingState.cpp  
)

target_include_directories(Snake PRIVATE include)

set(SFML_DIR "SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_link_libraries(Snake sfml-graphics sfml-window sfml-system)