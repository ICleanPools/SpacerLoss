CXXFLAGS=$(shell root-config --cflags)
GLIBS=$(shell root-config --glibs)

SRCS:=$(wildcard *.C)

all: SpacerLoss 

SpacerLoss: $(SRCS)
	g++ $(CXXFLAGS) $(SRCS) -o $@ -I. $(GLIBS)
