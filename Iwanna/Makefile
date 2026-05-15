CC ?= gcc
PKG_CONFIG ?= pkg-config

CFLAGS ?= -std=gnu99 -Wall -Wextra -g
SDL_CFLAGS := $(shell $(PKG_CONFIG) --cflags sdl2 SDL2_ttf)
SDL_LIBS := $(shell $(PKG_CONFIG) --libs sdl2 SDL2_ttf)

SRC := main.c player.c input.c map.c menu.c renderer.c collision.c state.c preprocess.c
OBJ := $(SRC:.c=.o)

TARGET := Iwanna
ifeq ($(OS),Windows_NT)
TARGET := Iwanna.exe
endif

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(SDL_LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(TARGET)

