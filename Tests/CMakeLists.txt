set(EXECUTABLE_OUTPUT_PATH "../../")
set(CMAKE_EXECUTABLE_SUFFIX "")

add_executable(jsonTest jsonTest.cpp ../json.cpp ../pokemon.cpp
                        ../move.cpp ../type.cpp ../stats.cpp)
target_compile_options(jsonTest PRIVATE -Wall; -Wextra; -Werror)
target_link_libraries(jsonTest 
                      PRIVATE nlohmann_json::nlohmann_json)

add_test(NAME jsonTest COMMAND ../../jsonTest)