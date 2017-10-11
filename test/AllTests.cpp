#include "CppUTest/CommandLineTestRunner.h"
#include <avr/io.h>
int main(int ac, char** av)
{
   return CommandLineTestRunner::RunAllTests(ac, av);
}

// Used by mock/avr/io.h to fake the PORT. 
// DO NOT DEFINE ELSEWHERE.
PORT_t FakePort;