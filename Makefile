CC=g++
BUILD_DIR=build
BIN=game
CXX_FLAGS=-Wall -Wextra
SRCS=src/main.cpp \
	src/AssetManager.cpp \
	src/Bat.cpp \
	src/Collision.cpp \
	src/Game.cpp \
	src/GameOverState.cpp \
	src/GameState.cpp \
	src/InputManager.cpp \
	src/Land.cpp \
	src/MainMenuState.cpp \
	src/Pipe.cpp \
	src/SplashState.cpp \
	src/StateMachine.cpp \
	src/HUD.cpp

LINK=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run: build
	./$(BUILD_DIR)/$(BIN)

.PHONY: build
build: $(SRCS)
	@mkdir -p build
	$(CC) $(CXX_FLAGS) $^ -o $(BUILD_DIR)/$(BIN) $(LINK)
	@echo "Copying resources"
#	@cp -r assets build/assets

clean:
	rm -rf build
