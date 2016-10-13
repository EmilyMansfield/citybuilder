#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"

void Game::pushState(GameState* state)
{
    this->states.push(state);

    return;
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState* state)
{
    if(!this->states.empty())
        popState();
    pushState(state);

    return;
}

GameState* Game::peekState()
{
    if(this->states.empty()) return nullptr;
    return this->states.top();
}

void Game::gameLoop()
{
    sf::Clock clock;
    float dt;

    while(this->window.isOpen())
    {
        dt = clock.restart().asSeconds();

        if(peekState() == nullptr) continue;
        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}

Game::Game()
{
    this->window.create(sf::VideoMode(800, 600), "City Builder");
    this->window.setFramerateLimit(60);
}

Game::~Game()
{
    while(!this->states.empty()) popState();
}
