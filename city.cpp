#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

#include "city.hpp"
#include "tile.hpp"

double City::distributePool(double& pool, Tile& tile, double rate = 0.0)
{
    const static int moveRate = 4;

    unsigned int maxPop = tile.maxPopPerLevel * (tile.tileVariant+1);

    /* If there is room in the zone, move up to 4 people from the
     * pool into the zone */
    if(pool > 0)
    {
        int moving = maxPop - tile.population;
        if(moving > moveRate) moving = moveRate;
        if(pool - moving < 0) moving = pool;
        pool -= moving;
        tile.population += moving;
    }

    /* Adjust the tile population for births and deaths */
    tile.population += tile.population * rate;

    /* Move population that cannot be sustained by the tile into
     * the pool */
    if(tile.population > maxPop)
    {
        pool += tile.population - maxPop;
        tile.population = maxPop;
    }

    return tile.population;
}

void City::bulldoze(const Tile& tile)
{
    /* Replace the selected tiles on the map with the tile and
     * update populations etc accordingly */
    for(int pos = 0; pos < this->map.width * this->map.height; ++pos)
    {
        if(this->map.selected[pos] == 1)
        {
            if(this->map.tiles[pos].tileType == TileType::RESIDENTIAL)
            {
                this->populationPool += this->map.tiles[pos].population;
            }
            else if(this->map.tiles[pos].tileType == TileType::COMMERCIAL)
            {
                this->employmentPool += this->map.tiles[pos].population;
            }
            else if(this->map.tiles[pos].tileType == TileType::INDUSTRIAL)
            {
                this->employmentPool += this->map.tiles[pos].population;
            }
            this->map.tiles[pos] = tile;
        }
    }

    return;
}

void City::shuffleTiles()
{
    while(this->shuffledTiles.size() < this->map.tiles.size())
    {
        this->shuffledTiles.push_back(0);
    }
    std::iota(shuffledTiles.begin(), shuffledTiles.end(), 1);
    std::random_shuffle(shuffledTiles.begin(), shuffledTiles.end());

    return;
}

void City::tileChanged()
{
    this->map.updateDirection(TileType::ROAD);
    this->map.findConnectedRegions(
    {
        TileType::ROAD, TileType::RESIDENTIAL,
        TileType::COMMERCIAL, TileType::INDUSTRIAL
    }, 0);

    return;
}
