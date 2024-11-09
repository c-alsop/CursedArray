CC = gcc
CFLAGS = -Wall -Wextra -pedantic

TARGET = cursedArray

SRC = main.c cursedArray.c print.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET).exe

.PHONY: all clean

