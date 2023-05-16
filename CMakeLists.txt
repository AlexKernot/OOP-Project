cmake_minimum_required(VERSION 3.22.1)
project(pokemon LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ../)
set(RUNTIME_OUTPUT_DIRECTORY ./bin)
set(CMAKE_EXECUTABLE_SUFFIX ".out")
set(COMPILE_OPTIONS -Wall; -Wextra; -Wpedantic; -Werror)
add_executable(pokemon sprites.cpp window.cpp main.cpp)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)
set(SFML_BUILD_EXAMPLES OFF)
set(BUILD_SHARED_LIBS OFF)
set(SFML_DEPENDENCIES  
        opengl32 # window, graphics  
        winmm # window, system  
        gdi32 # window  
        freetype # graphics  
# Audio dependencies
#        openal32
#        FLAC
#        vorbis
#        vorbisfile
#        vorbisenc
#        ogg
# Network dependencies
#        ws2_32
)
FetchContent_Declare(sfml 
                      GIT GIT_REPOSITORY https://github.com/SFML/SFML.git 
                      GIT_TAG 2.5.1 )
FetchContent_MakeAvailable(sfml)

target_link_libraries(pokemon 
                      PRIVATE nlohmann_json::nlohmann_json
                      SFML_DEPENDENCIES
                      sfml-system
                      sfml-window
                      sfml-graphics)

