set(EXECUTABLE_OUTPUT_PATH "../../")
set(CMAKE_EXECUTABLE_SUFFIX "")

add_executable(jsonTest ../json.cpp jsonTest.cpp)
target_link_libraries(jsonTest 
                      PRIVATE nlohmann_json::nlohmann_json
                      sfml-system
                      sfml-window
                      sfml-graphics)

add_test(NAME jsonTest COMMAND ../../jsonTest)