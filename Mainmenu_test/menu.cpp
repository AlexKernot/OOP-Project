#include "menu.hpp"

Menu::Menu(){
  window = new sf::RenderWindow();
  winclose = new sf::RectangleShape();
  font = new sf::Font();
  image = new sf::Texture();
  bg = new sf::Sprite();

  set_values();
}

Menu::~Menu(){
  delete window;
  delete winclose;
  delete font;
  delete image;
  delete bg;
}

void Menu::set_values(){
  window->create(sf::VideoMode(800,600), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
  window->setPosition(sf::Vector2i(0,0));

  pos = 0;
  pressed = theselect = false;
  font->loadFromFile("./Minecraft.ttf");
  image->loadFromFile("./TitleScreen.png");

  bg->setTexture(*image);

  pos_mouse = {0,0};
  mouse_coord = {0, 0};

  options = {"Play", "Quit"};
  texts.resize(2); //amount of buttons
  coords = {{380,295},{380,420}};
  sizes = {25,24};

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
  winclose->setPosition(1178,39);
  winclose->setFillColor(sf::Color::Transparent);

}

void Menu::loop_events(){
  sf::Event event;
  while(window->pollEvent(event)){
    if( event.type == sf::Event::Closed){
      window->close();
    }

    pos_mouse = sf::Mouse::getPosition(*window);
    mouse_coord = window->mapPixelToCoords(pos_mouse);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
      if( pos == 0){
        pressed = true;
        texts[pos].setOutlineThickness(0);
        ++pos;
        texts[pos].setOutlineThickness(4);
        pressed = false;
        theselect = false;
        std::cout << "down pos == " << pos << std::endl;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
      if( pos == 1){
        pressed = true;
        texts[pos].setOutlineThickness(0);
        --pos;
        texts[pos].setOutlineThickness(4);
        pressed = false;
        theselect = false;
        std::cout << "up pos == " << pos << std::endl;


      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 1){
        window->close();
      }
      std::cout << options[pos] << '\n';
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      if(winclose->getGlobalBounds().contains(mouse_coord)){
        //std::cout << "Close the window!" << '\n';
        window->close();
      }
    }
  }
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
