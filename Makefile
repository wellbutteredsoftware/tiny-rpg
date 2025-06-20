CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O1 -flto -funroll-loops -ffast-math
INCLUDES = -I./include

# MacOS flags
RAYLIB_LIB_MACOS = /opt/homebrew/lib
RAYLIB_INC_MACOS = /opt/homebrew/include
LDFLAGS_MACOS    = -L$(RAYLIB_LIB_MACOS) -lraylib -lm -ldl -lpthread \
		-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Windows flags
RAYLIB_LIB_WINDOWS = C:/external_libs/raylib-5.5/lib
RAYLIB_INC_WINDOWS = C:/external_libs/raylib-5.5/include
LDFLAGS_WIN        = -L$(RAYLIB_LIB_WINDOWS) -lraylib -lopengl32 -lgdi32 \
		-lwinmm -luser32 -lkernel32 -lshell32 -lcomdlg32 -luuid \
		-fuse-ld=lld -Wl,/SUBSYSTEM:CONSOLE
# todo: replace SUBSYSTEM:CONSOLE with WINDOWS later in development

###

SRC = src/main.c
OUT_MAC = build/tiny-rpg
OUT_WIN = build/tiny-rpg.exe

mac:
	rm -rf build
	mkdir -p build
	$(CC) $(SRC) $(CFLAGS) -I$(RAYLIB_INC_MACOS) $(INCLUDES) $(LDFLAGS_MACOS) \
	-o $(OUT_MAC)

win:
	rm -rf build
	mkdir -p build
	$(CC) $(SRC) $(CFLAGS) -I$(RAYLIB_INC_WINDOWS) $(INCLUDES) $(LDFLAGS_WIN) \
	-o $(OUT_WIN)