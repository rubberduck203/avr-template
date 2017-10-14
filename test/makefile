CC = gcc
CXX = g++

CPPFLAGS += $(shell pkg-config --cflags cpputest)
CXXFLAGS += -include CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include CppUTest/MemoryLeakDetectorMallocMacros.h
LD_LIBRARIES = $(shell pkg-config --libs cpputest)

CPPFLAGS += -Wall -Imocks

OBJ = obj
BIN = bin
SRC = ../src

# Build the test executable
testSource := $(wildcard *.cpp)

# Include all the source from src, except the entry point
srcFiles := $(filter-out $(SRC)/Demo.c, $(wildcard $(SRC)/*.c*))
objects := $(patsubst $(SRC)/%.c,$(OBJ)/%.o, $(srcFiles))
objects := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(objects))

all: check

### Compile code under test
include ../rules.mk

### Create test runner executable
$(BIN)/AllTests: $(objects) $(testSource)
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $^ -o $@ $(LD_LIBRARIES)

.PHONY: check
check: $(BIN)/AllTests
	$< -c -v 



### Make predefined variable cheatsheet
# $^ - all prereqs
# $@ - target
# $< - first prereq