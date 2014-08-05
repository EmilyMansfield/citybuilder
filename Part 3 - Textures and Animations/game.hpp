#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"

class GameState;

class Game
{
	private:

	void loadTextures();
	
    public:

    std::stack<GameState*> states;

    sf::RenderWindow window;
	TextureManager texmgr;
	sf::Sprite background;
	
    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

    void gameLoop();

    Game();
    ~Game();
};

#endif /* GAME_HPP */
