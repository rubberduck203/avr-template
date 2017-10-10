# avr-template

This project is a bare bones directory structure and makefiles for working with [avr-gcc][avr-gcc] and [CppUTest][cpputest]. 

It's designed to work with the [rubberduck/avr docker image][avr-docker], but should work on any *nix (or Mac) system, given you've installed avr-gcc, CppUTest, and pkg-config.
I've not tested on Windows, but I suspect a little bit of work would need to be done in order to make everything work correctly for that OS. (Pull Requests welcome!)

As of now, the makefiles only support C for the AVR code, but I'd like to add full support for C++ in the future. 

[avr-gcc]: http://www.atmel.com/webdoc/avrlibcreferencemanual/overview_1overview_gcc.html
[cpputest]: http://cpputest.github.io/
[avr-docker]: https://hub.docker.com/r/rubberduck/avr/

## Getting Started
To use, clone this project and copy into a new repository.

```bash
mkdir newProject
git clone https://github.com/rubberduck203/avr-template.git
cd $_
```

In `src/makefile` modify the following lines as appropriate for your device.

```bash
# name of the resulting program/hex file
PROGNAME = demo
# Valid avr-gcc device from this list: 
# http://www.atmel.com/webdoc/avrlibcreferencemanual/index_1supp_devices.html
DEVICE = atxmega128a1
# Processor speed (check your datasheet)
F_CPU = 32000000UL
```

And in `test/makefile` modify this line to create the list of objects under test.

```bash
objects := $(OBJ)/LedDriver.o
```

Running `make` will build and run the tests, then, if successful, compile, link, and generate the *.hex file for your avr device.
`obj` and `bin` directories are created automatically.

## Supported Make targets

- all: Run tests, build hex file, display size
- avr: Build hex file, display size
- size: Display the AVR Memory Usage
- check: Run tests
- clean: Delete all files in all `bin` and `obj` directories

### Targets I'd Like to Support, but Don't Yet

- upload: Use avrdude to upload the hex to the microcontroller
- install: standard target alias for upload

## License

The template and makefiles are licensed under the [MIT License](LICENSE) so you're free to include the template in your own projects. The MIT License is used in order to limit the licensing restrictions that other licenses would impose on your project. I want you to be free to use this in your own work without worrying about the implications of viral licenses. Just give credit where credit is due and pay it forward.