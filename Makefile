# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Source and Output Paths
SRC = src/main.c src/rled.c  # Include rled.c
OUT = build/fienc.exe  # Windows executable

# Compile the program
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

# Run the program
run: $(OUT)
	$(OUT)

# Clean generated files
clean:
	if exist build rd /s /q build
