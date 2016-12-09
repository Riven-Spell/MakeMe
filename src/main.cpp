#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
	std::string name{""};
	if(argc != 2){
		std::cout << "What is the name of your project?" << std::endl;
		getline(std::cin, name);
	}

	std::string mfile = "CC=g++\nDIRS = src/ $(filter %/,$(wildcard src/*/))\nSRC = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.cpp))\nINCL := $(foreach dir,$(wildcard $(DIRS)),-I$(dir))\nall:\n	-mkdir -p builds\n	g++ $(SRC) -o ./builds/" + name + " $(INCL) -Wall -std=c++11 -lcrypt";

	std::ofstream o {"Makefile"};
	o << mfile;
	return 0;
}
