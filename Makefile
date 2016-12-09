#Build environment
CC=g++

#Directory for files
DIRS = src/ $(filter %/,$(wildcard src/*/))
#Source files
SRC = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.cpp))
#Includes
INCL := $(foreach dir,$(wildcard $(DIRS)),-I$(dir))

all:
	-mkdir -p builds
	g++ $(SRC) -o ./builds/makeme $(INCL) -Wall -std=c++11 -lcrypt
