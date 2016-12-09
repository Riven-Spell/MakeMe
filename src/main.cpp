#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

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
	o.close();

	system("mkdir src");
	system("mkdir builds");

	return 0;
}
