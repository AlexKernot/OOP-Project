# Pokemon Showdown Remake

## Description

This project aims to be a recreation of a generation 1 Pokémon battle simulator akin to Pokémon showdown for entertainment-purposes. It will be a turn-based player versus computer game where players either construct a team of 6 Pokémon, each with 4 moves , or they will be randomly assigned Pokémon according to constraints that will depend on the game mode played.

## Game Modes

Game Modes can be chosen on the Main Menu accordingly:

Normal Mode: Player has a team of 6 Pokemon chosen to battle against an enemy team (either random or team-selected).

Mayhem battle: 6 Pokemon for the player that are given 4 random moves. Typing will be decided by the first two moves. Type Matchups are reversed.

Broken Cup: 6 random Pokemon assigned random moves and typings to battle enemy team.

## Running

To run the program, download the correct executable for your operating system and run it.

## Build

### **Windows & Mac**

All the required dependancies are packaged with sfml. Run the following commands to build:

```cmake -S. -Bbuild```

```cmake --build build```

### Linux

To build from source, the following dependancies are required:

- freetype
- x11
- xrandr
- udev
- opengl
- flac
- ogg
- vorbis
- vorbisenc
- vorbisfile
- openal
- pthread

#### Ubuntu

  The following command can be used to install all required dependancies
  
  ```sudo apt-get install libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libjpeg8-dev libsndfile1-dev libopenal-dev libudev-dev libxcb-image0-dev libjpeg-dev libflac-dev```
