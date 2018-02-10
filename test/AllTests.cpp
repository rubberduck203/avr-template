#include "CppUTest/CommandLineTestRunner.h"
#include <avr/io.h>
int main(int ac, char** av)
{
   return CommandLineTestRunner::RunAllTests(ac, av);
}