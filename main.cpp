#include "representations.hpp"

#include <iostream>
#include <string>

using namespace on_sets;

void debug(const std::string &mesg) {
	std::cout << mesg << std::endl;
}

int main(int, char**) {
	debug("hey");
	
	symbol_list test;
	test.push_back(RED);
	test.push_back(GREEN);
	test.push_back(NOT);
	test.push_back(UNIVERSE);
	test.push_back(EQUALS);
	
	for (auto ss : test) 
		std::cout << (char)ss << ", ";
	std::cout << std::endl;
	
	return 0;
}
