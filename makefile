# Path to your raylib installation
RAYLIB_PATH = raylib
GAME = engine

CC = gcc
CFLAGS = -Wall -I$(RAYLIB_PATH) -Iinclude
LDFLAGS = -L$(RAYLIB_PATH) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = $(wildcard *.c include/*.h)

all: $(GAME)

$(GAME): $(SRCS)
	$(CC) *.c -o $(GAME) $(CFLAGS) $(LDFLAGS)
	./$(GAME)

play: $(GAME)
	./$(GAME)

clean:
	rm -f $(GAME)
