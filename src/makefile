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

# name of the resulting program/hex file
PROGNAME = demo
# Valid avr-gcc device from this list: 
# http://www.atmel.com/webdoc/avrlibcreferencemanual/index_1supp_devices.html
DEVICE = atxmega128a1
# Processor speed (check your datasheet)
F_CPU = 32000000UL

### Shouldn't need to modify below this line ###

CFLAGS = -Wall -Os -mmcu=$(DEVICE) -DF_CPU=$(F_CPU)

OBJ = obj
BIN = bin

all: $(PROGNAME)
$(PROGNAME): $(BIN)/$(PROGNAME).hex size

# hex <- elf
$(BIN)/%.hex: $(BIN)/%.elf
	avr-objcopy -j .text -j .data -O ihex $^ $@

# elf <- [obj]
.PRECIOUS: $(BIN)/%.elf
objects := $(patsubst %.c,$(OBJ)/%.o,$(wildcard *.c*))
objects := $(patsubst %.cpp, $(OBJ)/%.o, $(objects))

$(BIN)/%.elf: $(objects)
	@mkdir -p $(BIN)
	avr-gcc $(CFLAGS) $^ -o $@

# obj <- c
.PRECIOUS: $(OBJ)/%.o
$(OBJ)/%.o: %.c
	@mkdir -p $(OBJ)
	avr-gcc -c $(CFLAGS) $^ -o $@

# obj <- cpp
$(OBJ)/%.o: %.cpp
	@mkdir -p $(OBJ)
	avr-g++ -c $(CFLAGS) $^ -o $@

.PHONY: size
size:
	avr-size --format=avr --mcu=$(DEVICE) $(BIN)/$(PROGNAME).elf

.PHONY: clean
clean:
	$(RM) $(BIN)/* $(OBJ)/*

### Make predefined variable cheatsheet
# $^ - all prereqs
# $@ - target
# $< - first prereq