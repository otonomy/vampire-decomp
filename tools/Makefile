# vd: the project's tools (byte gate, rule checker, renamer). Plain C99; build with MinGW-w64 gcc or MSVC.
#   make            (MinGW-w64)
#   cl /O2 /Fe:vd.exe *.c   (MSVC)

CC      ?= gcc
CFLAGS  ?= -std=c99 -O2 -Wall -Wextra -Wno-unused-parameter
SRCS     = main.c util.c pecoff.c symbols.c source.c check.c gate.c rules.c rename.c names.c
OUT      = ../build/vd.exe

all: $(OUT)

$(OUT): $(SRCS) vd.h
	mkdir -p ../build
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(OUT)

.PHONY: all clean
