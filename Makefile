CXX = g++
CXXFLAGS = -Wall -Werror -Wpedantic -g

NAMES = representations
NAMES_CPP = $(foreach name, $(NAMES), $(name).cpp)
NAMES_HPP = $(foreach name, $(NAMES), $(name).hpp)

main: main.cpp $(NAMES_CPP) $(NAMES_HPP)
	$(CXX) $(CXXFLAGS) $< -o $@
