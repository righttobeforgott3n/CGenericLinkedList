
SRC := $(wildcard src/*.c)
BIN = $(SRC:src/%.c=bin/%.o)

INCLUDE = -Iinclude

TO_CLEAN := bin

ifeq ($(DEV), Y)
	BUILD_OPTION = -g -Wall -Wextra -pedantic
	LINK_OPTION =
else ifeq ($(AR), Y)
	BUILD_OPTION = -Wall -Wextra -pedantic
	SRC := $(filter-out src/main.c, $(SRC))
endif

#

.PHONY : all clean main
.DEFAULT : all

bin/%.o : src/%.c
	gcc -std=c17 $(BUILD_OPTION) $(INCLUDE) -c $< -o $@

clean :
	rm -f $(TO_CLEAN)/*

libLinkedList.a : $(BIN)
	ar rcs bin/$@ $^

main : $(BIN)
	gcc -std=c17 $^ -o bin/$@

all : main

leak : clean all bin/main
	valgrind bin/main