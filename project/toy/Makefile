COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: project.elf

project.elf: ${COMMON_OBJECTS} buzzer.o led.o main.o p2_interrupt_handler.o stateMachines.o switches.o ../lib/libtimer.a
	${CC} ${CFLAGS} -o $@ $^

load: project.elf
	msp430loader.sh $^
clean: $^
	rm -f *.o *.elf

