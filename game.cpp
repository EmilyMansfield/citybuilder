#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"
#include "texture_manager.hpp"
#include "animation_handler.hpp"
#include "tile.hpp"

void Game::loadTiles()
{
    Animation staticAnim(0, 0, 1.0f);
    this->tileAtlas["grass"] =
        Tile(this->tileSize, 1, texmgr.getRef("grass"),
            { staticAnim },
            TileType::GRASS, 50, 0, 1);
    tileAtlas["forest"] =
        Tile(this->tileSize, 1, texmgr.getRef("forest"),
            { staticAnim },
            TileType::FOREST, 100, 0, 1);    
    tileAtlas["water"] =
        Tile(this->tileSize, 1, texmgr.getRef("water"),
            { Animation(0, 3, 0.5f),
            Animation(0, 3, 0.5f),
            Animation(0, 3, 0.5f) },
            TileType::WATER, 0, 0, 1);
    tileAtlas["residential"] =
        Tile(this->tileSize, 2, texmgr.getRef("residential"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim },
            TileType::RESIDENTIAL, 300, 50, 6);
    tileAtlas["commercial"] =
        Tile(this->tileSize, 2, texmgr.getRef("commercial"),
            { staticAnim, staticAnim, staticAnim, staticAnim},
            TileType::COMMERCIAL, 300, 50, 4);
    tileAtlas["industrial"] =
        Tile(this->tileSize, 2, texmgr.getRef("industrial"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim },
            TileType::INDUSTRIAL, 300, 50, 4);
    tileAtlas["road"] =
        Tile(this->tileSize, 1, texmgr.getRef("road"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim },
            TileType::ROAD, 100, 0, 1);

    return;
}

void Game::loadTextures()
{
    texmgr.loadTexture("grass",         "media/grass.png");
    texmgr.loadTexture("forest",        "media/forest.png");
    texmgr.loadTexture("water",         "media/water.png");
    texmgr.loadTexture("residential",   "media/residential.png");
    texmgr.loadTexture("commercial",    "media/commercial.png");
    texmgr.loadTexture("industrial",    "media/industrial.png");
    texmgr.loadTexture("road",          "media/road.png");

    texmgr.loadTexture("background",    "media/background.png");
}

void Game::loadFonts()
{
    sf::Font font;
    font.loadFromFile("media/font.ttf");
    this->fonts["main_font"] = font;

    return;
}

void Game::loadStylesheets()
{
    this->stylesheets["button"] = GuiStyle(&this->fonts.at("main_font"), 1,
        sf::Color(0xc6,0xc6,0xc6), sf::Color(0x94,0x94,0x94), sf::Color(0x00,0x00,0x00),
        sf::Color(0x61,0x61,0x61), sf::Color(0x94,0x94,0x94), sf::Color(0x00,0x00,0x00));
    this->stylesheets["text"] = GuiStyle(&this->fonts.at("main_font"), 0,
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0xff,0xff,0xff),
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0xff,0x00,0x00));

    return;
}

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

    while(this->window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

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
    this->loadTextures();
    this->loadTiles();
	this->loadFonts();
	this->loadStylesheets();
	
    this->window.create(sf::VideoMode(800, 600), "City Builder");
    this->window.setFramerateLimit(60);

    this->background.setTexture(this->texmgr.getRef("background"));
}

Game::~Game()
{
    while(!this->states.empty()) popState();
}
