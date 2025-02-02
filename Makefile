# Variables
CC = gcc            # Change to g++ for C++
CFLAGS = -Wall -Wextra -O2
SRC = main.c        # Change to main.cpp for C++
OUT = fienc

# Default target
all: $(OUT)

# Compile the program
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

# Run the program
run: all
	./$(OUT)

# Clean generated files
clean:
	rm -f $(OUT)
