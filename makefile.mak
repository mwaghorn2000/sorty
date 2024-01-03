# Compiler and Compiler flags
CC = gcc
CFLAGS = -Wall -g
INCLUDES = -Iinclude

# Define the source (.c) and header (.h) files
SRCS = src/main.c src/file_sorter.c src/file_reader.c src/sort_algorithm.c
OBJS = $(SRC:.c=.o)
HEADERS = include/file_sorter.h include/file_reader.h include/sort_algorithm.h

MAIN = sorty

.PHONY: all clean

all: $(MAIN)
	@echo Simple compiler named mycc has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) src/*.o *~ $(MAIN)
