# Compiler
CC = clang

# Compiler flags
CFLAGS = -Os -fno-strict-aliasing -save-temps

# Source file
SRC = main.c

# Object file
OBJ = main.o

# Output executable
OUT = main

# Default target
all: $(OUT)

# Build target
$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ)

# Compilation target
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# Clean target
clean:
	rm -f $(OUT) $(OBJ)

# Phony targets
.PHONY: all clean

