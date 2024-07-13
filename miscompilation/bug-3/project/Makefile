# Compiler
CC = clang-18

# Compiler flags
CFLAGS = -O3 -flto -march=znver4 -fno-strict-aliasing -save-temps

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
	$(CC) -O3 -flto -march=znver4 -o $(OUT) $(OBJ)

# Compilation target
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

# Clean target
clean:
	rm -f $(OUT) $(OBJ)

# Phony targets
.PHONY: all clean

