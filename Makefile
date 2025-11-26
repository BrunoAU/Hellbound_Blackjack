CC = gcc
SRC = $(wildcard *.c)
OUT = jogo

ifeq ($(OS),Windows_NT)
	OUT := jogo.exe
	
	RAYLIB_PATH ?= C:/raylib-5.5_win64_mingw-w64
	
	CFLAGS = -I"$(RAYLIB_PATH)/include"
	LDFLAGS = -L"$(RAYLIB_PATH)/lib" -lraylib -lopengl32 -lgdi32 -lwinmm -lm
	
	RM = del /Q
else
	UNAME_S := $(shell uname -s)

	ifeq ($(UNAME_S),Linux)
		RAYLIB_ROOT = $(HOME)/dev_libs/raylib
		
		CFLAGS = -I$(RAYLIB_ROOT)/src

		LDFLAGS = -L$(RAYLIB_ROOT)/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
		
		RM = rm -f
	endif

	ifeq ($(UNAME_S),Darwin)
		UNAME_P := $(shell uname -m)
		
		ifeq ($(UNAME_P),x86_64)
			HB_PATH = /usr/local
		else
			HB_PATH = /opt/homebrew
		endif

		CFLAGS = -I$(HB_PATH)/include
		LDFLAGS = -L$(HB_PATH)/lib \
				  -lraylib \
				  -framework OpenGL \
				  -framework Cocoa \
				  -framework IOKit \
				  -framework CoreVideo
		RM = rm -f
	endif
endif

.PHONY: all clean deps deps-windows deps-linux deps-macos

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

deps:
	ifeq ($(OS),Windows_NT)
	$(MAKE) deps-windows
	else
	ifeq ($(UNAME_S),Linux)
	$(MAKE) deps-linux
	endif
	ifeq ($(UNAME_S),Darwin)
	$(MAKE) deps-macos
	endif
	endif

deps-windows:
	@echo "Instalando dependencias no Windows (MSYS2 / MinGW-w64)..."
	@echo "Certifique-se de estar usando o terminal MSYS2 MinGW 64-bit."
	pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-raylib

deps-linux:
	@echo "Instalando dependencias do sistema e preparando Raylib..."
	sudo apt install -y build-essential pkg-config libx11-dev libgl1-mesa-dev libxcursor-dev libxrandr-dev libxinerama-dev libxi-dev git
	
	cd ~
	mkdir -p dev_libs
	cd dev_libs
	rm -rf raylib
	git clone https://github.com/raysan5/raylib.git

deps-macos:
	@echo "Instalando dependencias no macOS (Homebrew)..."
	@echo "Certifique-se de que o Homebrew esta instalado."
	brew update
	brew install raylib

clean:
	$(RM) $(OUT)
