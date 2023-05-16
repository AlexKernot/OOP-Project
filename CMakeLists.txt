cmake_minimum_required(VERSION 3.22.1)
project(pokemon)
set(CMAKE_CXX_STANDARD 11)
add_executable(pokemon sprites.cpp window.cpp)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(pokemon PRIVATE nlohmann_json::nlohmann_json)

