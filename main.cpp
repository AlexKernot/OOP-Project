#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "window.hpp"
#include "player.hpp"
#include "pokemon.hpp"


int main() {
    Window window;
		vector<Pokemon*> pokemon;

		Player p("Camille",pokemon);


    while (window.sfWindow->isOpen()) {
        sf::Event event;
        while (window.PollEvent(&event)) {
            if (event.type == sf::Event::Closed) {
                window.~Window();
            }
            // Handle other events
						p.make_choice(window.sfWindow);
        }

        window.RenderWindow();
    }


		
    return 0;
}
