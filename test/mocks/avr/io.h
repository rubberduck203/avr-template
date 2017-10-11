#ifndef _AVR_IO_H_
#define _AVR_IO_H_

#include <stdint.h>

typedef volatile uint8_t register8_t;

/* I/O Port: Define mock as appropriate for your device */
typedef struct PORT_struct
{
    register8_t DIR;  /* I/O Port Data Direction */
    register8_t DIRSET;  /* I/O Port Data Direction Set */
    register8_t DIRCLR;  /* I/O Port Data Direction Clear */
    register8_t DIRTGL;  /* I/O Port Data Direction Toggle */
    register8_t OUT;  /* I/O Port Output */
    register8_t OUTSET;  /* I/O Port Output Set */
    register8_t OUTCLR;  /* I/O Port Output Clear */
    register8_t OUTTGL;  /* I/O Port Output Toggle */
    register8_t IN;  /* I/O port Input */
    register8_t INTCTRL;  /* Interrupt Control Register */
    register8_t INT0MASK;  /* Port Interrupt 0 Mask */
    register8_t INT1MASK;  /* Port Interrupt 1 Mask */
    register8_t INTFLAGS;  /* Interrupt Flag Register */
    register8_t reserved_0x0D;
    register8_t reserved_0x0E;
    register8_t reserved_0x0F;
    register8_t PIN0CTRL;  /* Pin 0 Control Register */
    register8_t PIN1CTRL;  /* Pin 1 Control Register */
    register8_t PIN2CTRL;  /* Pin 2 Control Register */
    register8_t PIN3CTRL;  /* Pin 3 Control Register */
    register8_t PIN4CTRL;  /* Pin 4 Control Register */
    register8_t PIN5CTRL;  /* Pin 5 Control Register */
    register8_t PIN6CTRL;  /* Pin 6 Control Register */
    register8_t PIN7CTRL;  /* Pin 7 Control Register */
} PORT_t;

extern PORT_t FakePort;
#define PORTE (*(PORT_t *) &FakePort)

#endif