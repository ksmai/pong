CXX=g++
INCPATH=-I/usr/include/SDL2
CXXFLAGS=-std=c++14 -Wall -Werror -pedantic $(INCPATH)
LIBS=-lSDL2 -lSDL2_ttf -lSDL2_gfx
MAKEFILE=Makefile
EXE=pong

SRCS=$(shell find -name '*.cpp')
OBJS=$(subst .cpp,.o,$(SRCS))

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) $(LIBS)

%.o: %.cpp $(MAKEFILE)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cpp constants.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(EXE)
