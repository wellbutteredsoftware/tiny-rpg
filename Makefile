CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O3 -flto -funroll-loops -ffast-math -v
INCLUDES = -I./include

SRC_DIR = src
OBJ_DIR = build/obj
BIN_DIR = build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

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

OUT_MAC = build/tiny-rpg
OUT_WIN = build/tiny-rpg.exe

.PHONY: mac win clean

mac: $(OUT_MAC)

win: $(OUT_WIN)

$(OUT_MAC): $(OBJS)
	$(CC) $^ $(CFLAGS) -I$(RAYLIB_INC_MACOS) $(INCLUDES) $(LDFLAGS_MACOS) -o $@

$(OUT_WIN): $(OBJS)
	$(CC) $^ $(CFLAGS) -I$(RAYLIB_INC_WINDOWS) $(INCLUDES) $(LDFLAGS_WIN) -o $@

# Compile .c files to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -I$(RAYLIB_INC_WINDOWS) -c $< -o $@

clean:
	rm -rf build