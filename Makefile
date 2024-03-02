
SRC = $(wildcard src/*.c)
BIN = $(SRC:src/%.c=bin/%.o)

INCLUDE = -Iinclude

ifeq ($(DEV), Y)
	DEV_OPTION = -g #-Wall #-Wextra #-pedantic
	TO_CLEAN = bin
endif

#

.PHONY : all clean
.DEFAULT : all

all : GenericLinkedList

GenericLinkedList : $(BIN)
	gcc -std=c17 $(DEV_OPTION) $^ -o bin/$@

bin/%.o : src/%.c
	gcc -std=c17 $(DEV_OPTION) $(INCLUDE) -c $< -o $@

clean :
	rm -f $(TO_CLEAN)/*
