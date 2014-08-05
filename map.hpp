#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

#include <string>
#include <map>
#include <vector>

#include "tile.hpp"

class Map
{
    private:

    void depthfirstsearch(std::vector<TileType>& whitelist,
        sf::Vector2i pos, int label, int type);

    public:

    unsigned int width;
    unsigned int height;

    std::vector<Tile> tiles;

    /* Resource map */
    std::vector<int> resources;

    unsigned int tileSize;

    unsigned int numRegions[1];

	/* 0 = Deselected, 1 = Selected, 2 = Invalid */
	std::vector<char> selected;
	unsigned int numSelected;

	/* Select the tiles within the bounds */
	void select(sf::Vector2i start, sf::Vector2i end, std::vector<TileType> blacklist);

	/* Deselect all tiles */
	void clearSelected();

    /* Load map from disk */
    void load(const std::string& filename, unsigned int width, unsigned int height,
        std::map<std::string, Tile>& tileAtlas);

    /* Save map to disk */
    void save(const std::string& filename);

    /* Draw the map */    
    void draw(sf::RenderWindow& window, float dt);

    /* Checks if one position in the map is connected to another by
     * only traversing tiles in the whitelist */
    void findConnectedRegions(std::vector<TileType> whitelist, int type);

    /* Update the direction of directional tiles so that they face the correct
     * way. Used to orient roads, pylons, rivers etc */
    void updateDirection(TileType tileType);
    
	/* Blank map constructor */
	Map()
	{
		this->numSelected = 0;
		this->tileSize = 8;
		this->width = 0;
		this->height = 0;
		this->numRegions[0] = 1;
	}
	/* Load map from file constructor */
	Map(const std::string& filename, unsigned int width, unsigned int height,
		std::map<std::string, Tile>& tileAtlas)
	{
		this->numSelected = 0;
		this->tileSize = 8;
		load(filename, width, height, tileAtlas);
	}
};

#endif /* MAP_HPP */
