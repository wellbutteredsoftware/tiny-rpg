CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O1 -flto -funroll-loops
RAYLIBL = /opt/homebrew/lib
RAYLIBI = /opt/homebrew/include
LDFLAGS = -L$(RAYLIBL) -lraylib -lm -ldl -lpthread -framework OpenGL \
-framework Cocoa -framework IOKit -framework CoreVideo

INCLUDES = -I$(RAYLIBI) -I./include
SRC = src/main.c
OUT = build/tiny-rpg

all: mac

mac:
	mkdir -p build
	$(CC) $(SRC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $(OUT)

clean:
	rm -rf build

# todo: create a Windows build rule