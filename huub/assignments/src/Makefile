
CC=gcc
CFLAGS=-Wall -std=c2x

C_SOURCES := $(wildcard *.c)

C_EXECS := $(C_SOURCES:.c=) 
C_OBJS := $(C_SOURCES:.c=.o) 
C_ASMS := $(C_SOURCES:.c=.s) 

C_CLEAN_TARGETS := $(C_OBJS) $(C_EXECS) $(C_ASMS) a.out

%.s : %.c
	$(CC) -S -O0 $(CFLAGS) $(CPPFLAGS) $<

what:
	@echo "But what do you want me to make?" >&2

exs.o: exs.c #muls.h
exi.o: exi.c #muli.h
exd.o: exd.c #muld.h

exs: exs.o muls.o
	$(CC) $(CFLAGS) $^ -o $@

exi: exi.o muli.o
	$(CC) $(CFLAGS) $^ -o $@

exd: exd.o muld.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(C_CLEAN_TARGETS)

tell:
	@echo "C_SOURCES =" $(C_SOURCES)
	@echo "C_OBJS =" $(C_OBJS)
	@echo "C_EXECS =" $(C_EXECS)
	@echo "C_ASMS =" $(C_ASMS)
	@echo "C_CLEAN_TARGETS =" $(C_CLEAN_TARGETS)
