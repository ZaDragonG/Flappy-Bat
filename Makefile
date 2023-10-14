CC=g++
CXX_FLAGS=-Wall -Wextra
SRCS=main.cpp \
    AssetManager.cpp \
    Bird.cpp \
    Collision.cpp \
    Flash.cpp \
    Game.cpp \
    GameOverState.cpp \
    GameState.cpp \
    InputManager.cpp \
    Land.cpp \
    MainMenuState.cpp \
    Pipe.cpp \
    SplashState.cpp \
    StateMachine.cpp \
    HUD.cpp

LINK=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

game: $(SRCS)
	$(CC) $(CXX_FLAGS) $^ -o $@ $(LINK)

.PHONY: run
run: game
	./game

.PHONY: clean
clean:
	rm -f game
