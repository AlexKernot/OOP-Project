# Pokemon
## Running
To run the program, download the correct executable for your operating system and run it.
## Build

### **Windows & Mac**
All the required dependancies are packaged with sfml. Run the following commands to build:


```cmake -S. -Bbuild``` </br>
```cmake -build build```

### **Linux**
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
- pthread </br></br>
### Ubuntu
  The following command can be used to install all required dependancies
  
  ```sudo apt-get install libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libjpeg8-dev libsndfile1-dev libopenal-dev libudev-dev libxcb-image0-dev libjpeg-dev libflac-dev```