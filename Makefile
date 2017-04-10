CXXFLAGS=$(shell root-config --cflags)
GLIBS=$(shell root-config --glibs)

SRCS:=$(wildcard *.C)

all: SpacerLoss 

SpacerLoss: $(SRCS)
	g++ -std=c++0x $(CXXFLAGS) $(SRCS) -o $@ -I. $(GLIBS)
