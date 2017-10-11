# MIT License

# Copyright (c) 2017 Christopher J. McClellan

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

CPPFLAGS += $(shell pkg-config --cflags cpputest)
CXXFLAGS += -include CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include CppUTest/MemoryLeakDetectorMallocMacros.h
LD_LIBRARIES = $(shell pkg-config --libs cpputest)

CPPFLAGS += -Imocks

OBJ = obj
BIN = bin
SRC = ../src

# Build the test executable
testSource := $(wildcard *.cpp)
# Include all the source from src, except the entry point
objects := $(patsubst $(SRC)/%.c,$(OBJ)/%.o, $(filter-out $(SRC)/Demo.c, $(wildcard $(SRC)/*.c)))

all: check

### Compile code under test
$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	gcc -Wall -c $(CFLAGS) $(CPPFLAGS) $^ -o $@

### Create test runner executable
$(BIN)/AllTests: $(objects) $(testSource)
	@mkdir -p $(BIN)
	g++ -Wall $(CXXFLAGS) $(CPPFLAGS) $^ -o $@ $(LD_LIBRARIES)

.PHONY: check
check: $(BIN)/AllTests
	$< -c -v 

.PHONY: clean
clean:
	$(RM) $(BIN)/* $(OBJ)/*

### Make predefined variable cheatsheet
# $^ - all prereqs
# $@ - target
# $< - first prereq