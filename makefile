PROJECT_NAME= Game

BUILD = build

SRC= main.cpp\
src\Profile.cpp\
src\Enemy.cpp
INC= include\Profile.h\
include\Enemy.h
CFLAGS= -w -I./include
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).exe
# Default target built
$(PROJECT_NAME):all
cc=g++

.PHONY: all
all:  $(SRC) $(BUILD)
	$(cc) $(CFLAGS) $(SRC) $(INC) -o  $(PROJECT_OUTPUT)
# Create new build folder if not present
$(BUILD):
	mkdir $(BUILD)