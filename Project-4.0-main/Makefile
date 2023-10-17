CC=g++
BUILD_DIR=build
BIN=game
CXX_FLAGS=-Wall -Wextra
SRCS=src/main.cpp \
	src/Assets.cpp \
	src/Bat.cpp \
	src/Collision.cpp \
	src/Game.cpp \
	src/GameEnd.cpp \
	src/GameBody.cpp \
	src/ButtonInputs.cpp \
	src/Ground.cpp \
	src/MenuBody.cpp \
	src/Pipe.cpp \
	src/BackgroundImg.cpp \
	src/StateHandler.cpp \
	src/UserInterface.cpp

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
