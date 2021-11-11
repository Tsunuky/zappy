project(zappy)
cmake_minimum_required(VERSION 3.10)

set(CPPFLAGS "-std=gnu++14 -O0 -g -W -Wall -Wextra
-fprofile-arcs -ftest-coverage -fPIC -I./includes")

set(CFLAGS "--coverage -lgcov -lsfml-graphics
-lsfml-window -lsfml-system")

set(TESTSFLAGS "-lcriterion -ggdb -g3 -lgcov --coverage")

set(SOURCES
    ./sources/Sprite.cpp
    ./sources/main.cpp
)

set(INCLUDES
    ./includes/device.hpp
    ./includes/include.hpp
    ./includes/Obj.hpp
    ./includes/Sprite.hpp
    ./includes/System.hpp
    ./includes/ZappyException.hpp
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")
find_package(SFML 2 REQUIRED CONPONENTS graphics window system)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
 
include_directories(./includes)
add_executable(zappy_ai ${SOURCES} ${INCLUDES})