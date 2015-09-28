#
# Makefile ADRC
#

CC= gcc
TARGET= main
CFLAGS= -g -Wall -ansi

SRCFILES= main.c file.c tree.c
INCFILES= file.h tree.h
OBJFILES= main.o file.o tree.o

default: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(TARGET) $(OBJFILES) core.* #*

main.o: main.c

file.o: file.c file.h

tree.o: tree.c tree.h
