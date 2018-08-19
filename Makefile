CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror -pedantic
INCPATH=-I/usr/include/SDL2
LIBS=-lSDL2 -lSDL2_ttf -lSDL2_gfx
MAKEFILE=Makefile
EXE=pong

SRCS=$(shell find -name '*.cpp')
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) $(LIBS)

%.o: %.cpp constants.h MAKEFILE
	$(CXX) $(CXXFLAGS) $(INCPATH) -c -o $@ $<

clean:
	rm -f $(OBJS) $(EXE)
