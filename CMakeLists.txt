cmake_minimum_required(VERSION 3.22.1)
project(pokemon LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ../)
set(RUNTIME_OUTPUT_DIRECTORY ./bin)
set(CMAKE_EXECUTABLE_SUFFIX ".out")
add_executable(pokemon button.cpp move.cpp pokemon.cpp stats.cpp type.cpp renderable.cpp sprites.cpp window.cpp menu.cpp game_state.cpp player.cpp bot.cpp game_container.cpp main.cpp)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)
set(SFML_BUILD_EXAMPLES OFF)
set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(sfml 
                      GIT GIT_REPOSITORY https://github.com/SFML/SFML.git 
                      GIT_TAG 2.5.1 )
FetchContent_MakeAvailable(sfml)

include(CTest)

enable_testing()
add_subdirectory(Tests)
target_compile_options(pokemon PRIVATE -Wall; -Wextra; -g)
target_link_libraries(pokemon 
                      PRIVATE nlohmann_json::nlohmann_json
                      sfml-system
                      sfml-window
                      sfml-graphics)