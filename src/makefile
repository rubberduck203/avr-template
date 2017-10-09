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
objects := $(patsubst %.c,$(OBJ)/%.o,$(wildcard *.c))
$(BIN)/%.elf: $(objects)
	@mkdir -p $(BIN)
	avr-gcc $(CFLAGS) $^ -o $@

# obj <- c
.PRECIOUS: $(OBJ)/%.o
$(OBJ)/%.o: %.c
	@mkdir -p $(OBJ)
	avr-gcc -c $(CFLAGS) $^ -o $@

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