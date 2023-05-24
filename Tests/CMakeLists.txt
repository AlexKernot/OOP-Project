set(EXECUTABLE_OUTPUT_PATH "../../")
set(CMAKE_EXECUTABLE_SUFFIX "")

add_executable(jsonTest jsonTest.cpp ../json.cpp ../pokemon.cpp
                        ../move.cpp ../type.cpp ../stats.cpp
                        ../readPokemonTeam.cpp)
target_compile_options(jsonTest PRIVATE -Wall; -Wextra; -Werror; -g)
target_link_libraries(jsonTest 
                      PRIVATE nlohmann_json::nlohmann_json)

add_test(NAME jsonTest COMMAND ../../jsonTest)

add_executable(buttonTest buttonTest.cpp ../button.cpp ../renderable.cpp ../sprites.cpp)
target_compile_options(buttonTest PRIVATE -Wall; -Wextra; -Werror; -g)
target_link_libraries(buttonTest PRIVATE 
                      sfml-system
                      sfml-window
                      sfml-graphics)

add_executable(pokemonTest pokemonTest.cpp ../pokemon.cpp
                      ../move.cpp ../type.cpp ../stats.cpp)
target_compile_options(jsonTest PRIVATE -Wall; -Wextra; -Werror; -g)
target_link_libraries(pokemonTest
                    PRIVATE nlohmann_json::nlohmann_json
                    sfml-system
                    sfml-window
                    sfml-graphics
                    )

add_test(NAME jsonTest COMMAND ../../jsonTest)