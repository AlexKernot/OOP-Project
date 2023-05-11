GXX=g++
CXXFLAGS=-c -g -Wall -Wextra -Wpedantic

NAME=pokemon

FILES=./*.cpp
BINARIES=./*.o
CPPLIB=cppJson-Library/jsoncpp.cpp
CPPJSONOBJ=cppJson-Library/jsoncpp.o

%.o: %.c
	$(GXX) $(CXXFLAGS) @< -o @$

$(CPPJSONOBJ):
	$(GXX) -c $(CPPLIB) -o $(CPPJSONOBJ)

$(NAME): $(BINARIES) $(CPPJSONOBJ)

all: $(NAME)