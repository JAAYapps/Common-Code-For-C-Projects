# Makefile
CC        :=gcc
CFLAGS    :=-Wall -Werror -m64 -mabi=ms -ffreestanding -DPRINT
LINKFLAGS :=-Wall -Werror -m64
UNAME_S   :=$(shell uname -s)
ext		  :=.exe
remove	  :=del *.o *$(ext)

ifeq ($(UNAME_S),Linux)
CFLAGS    :=-Wall -Werror -ffreestanding -DPRINT
ext		  :=.out
remove	  :=rm -f *.o *$(ext)
endif

all: example$(ext)

obj 	  := $(patsubst %.c,%.o,$(wildcard *.c))

%.o: %.c
	@ echo !====== COMPILING $<
	$(CC) $(CFLAGS) -c $< -o $@

example$(ext): $(obj)
	$(CC) $(LINKFLAGS) $^ -o example$(ext)

clean:
	@echo "Cleaning files...."
	$(remove)
	@echo "Done."

run:
	./example$(ext) example.txt

.PHONY: clean
