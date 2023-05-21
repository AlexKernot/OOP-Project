/*****************************************************************************/
/*                                                                           */
/*         █████  ██████  ███████ ██       █████  ██ ██████  ███████         */
/*        ██   ██ ██   ██ ██      ██      ██   ██ ██ ██   ██ ██              */
/*        ███████ ██   ██ █████   ██      ███████ ██ ██   ██ █████           */
/*        ██   ██ ██   ██ ██      ██      ██   ██ ██ ██   ██ ██              */
/*        ██   ██ ██████  ███████ ███████ ██   ██ ██ ██████  ███████         */
/*                                                                           */
/*        ██    ██ ███    ██ ██    |                            |            */
/*        ██    ██ ████   ██ ██    |   OOP Semester 1 2023      |            */
/*        ██    ██ ██ ██  ██ ██    |   Camille, Rose, Alex      |            */
/*        ██    ██ ██  ██ ██ ██    |   Pokemon Showdown remake  |            */
/*         ██████  ██   ████ ██    |                            |            */
/*                                                                           */
/*        This is the main menu class that displays the menu with               */
/*         the corresponding choices to start and play the game                 */
/* source code for UI taken from: https://github.com/terroo/menu-sfml/tree/main */
/*                                                                              */
/*****************************************************************************/

#include "menu.hpp"

Menu::Menu(){
  Draw(sf::RenderWindow *window);
  winclose = Renderable::add_sprite(sf::RectangleShape());
  font = Renderable::add_sprite(sf::Font(), "./resources/Minecraft.ttf");
  image = Renderable::add_sprite(sf::Texture(), "./resources/TitleScreen2.png");
  bg = Renderable::add_sprite(sf::Sprite(), *image); //ok this idk

  set_values();
}

Menu::~Menu(){
  delete winclose;
  delete font;
  delete image;
  delete bg;
}

void Menu::set_values(){
  Draw();
  Renderable::set_position(sf::Vector2i(0,0));

  pos = 0;
  pressed = theselect = false;
  //font->loadFromFile("./resources/Minecraft.ttf");
  //image->loadFromFile("./resources/TitleScreen2.png");

  //bg->setTexture(*image);

  pos_mouse = {0,0};
  mouse_coord = {0, 0};

  options = {"Normal Mode", "Mayhem Mode", "Broken Cup", "Quit"};
  texts.resize(4);
  coords = {{320,260},{320,340},{320,422},{350,500}};
  sizes = {24, 24, 24 ,24};

  for (std::size_t i{}; i < texts.size(); ++i){
   texts[i].setFont(*font); 
   texts[i].setString(options[i]); 
   texts[i].setCharacterSize(sizes[i]);
   texts[i].setOutlineColor(sf::Color::Black);
   texts[i].setPosition(coords[i]);
  }
  texts[1].setOutlineThickness(4);
  pos = 0;

  winclose->setSize(sf::Vector2f(23,26));
  winclose->setPosition(1178,39); //ehr
  winclose->setFillColor(sf::Color::Transparent);

}

int Menu::loop_events(){
  sf::Event event;
  while(window->pollEvent(event)){
    if( event.type == sf::Event::Closed){
      window->close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
      if( pos < 3){
        ++pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos - 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
      if( pos >= 0){
        --pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos + 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 3){
        window->close();
      }
      std::cout << options[pos] << '\n';
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 0){
        return (1);
      }
      std::cout << options[pos] << '\n';
    }

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 1){
        return (2);
      }
      std::cout << options[pos] << '\n';
    }

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 2){
        return (3);
      }
      std::cout << options[pos] << '\n';
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      if(winclose->getGlobalBounds().contains(mouse_coord)){
        std::cout << "Closing Window :)" << '\n';
        window->close();
      }
    }
  }
  return (0);
}

void Menu::draw_all(){
  window->clear();
  window->draw(*bg);
  for(auto t : texts){
   window->draw(t); 
  }
  window->display();
}

void Menu::run_menu(){
  while(window->isOpen()){
    loop_events();
    draw_all();
  }
}

void Menu::Draw(sf::RenderWindow *window)
{
  window->draw(Sprites);
}