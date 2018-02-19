CC = gcc
CFLAGS = -std=c99 -Wall -pedantic -g
LDLIBS = -lreadline
OBJS := $(addprefix build/,main.o)

.DEFAULT: all

.PHONY: all

all: build/esh

build:
	mkdir -p build

$(OBJS): | build

build/%.o: src/%.c
	$(CC) $(CFLAGS)  -c $< -o $@ $(LDLIBS)

build/esh: $(OBJS) build/main.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

.PHONY: clean

clean:
	rm -rf ./build/

