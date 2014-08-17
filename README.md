Creating A City Building Game With SFML
===========

Source code for my SFML Citybuilder tutorial, hosted on [Binpress.com](http://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml/137).

Folders
=======

* Example code for "Part 1: State Manager", found here: <http://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-1-state-manager/123>
* Example code for "Part 2: The First State" found here: <https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-2-the-first-state/124>
* Example code for "Part 3: Textures and Animations" found here: <https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-3-textures-and-animations/125>
* Example code for "Part 4: Tiles" found here: <https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-4-tiles/126>
* Example code for "Part 5: The Game World" found here: <https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-5-the-game-world/127>
* Example code for "Part 6: Exploring the World" found here: <https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-6-exploring-the-world/128>
* Example code for "Part 7: Tile Selection" found here: <https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-7-tile-selection/129>
* Example code for "Part 8: GUI System" found here: <https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-8-gui-system/130>
* Example code for "Part 9: A Complete City" found here: <https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-9-a-complete-city/131>
* Example code for "Part 10: Putting it All Together" found here: <https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml-part-10-putting-it-all-together/132>

Compiling
=========

The source code (from within the main tree or each tutorial section) can be compiled using CMake (Version 3.0 or greater required)

*   [Optional] Set CMAKE_BUILD_TYPE to either Release or Debug depending which type you want to build for.
*   [Optional] Check SFML_STATIC_LIBS if you want to link SFML statically.
*   [Optional] Check CITYBUILDER_STATIC_STD_LIBS if you want to link the runtime libraries static. Note: SFML needs to be linked with the same option.
*    [Optional] Set CMAKE_INSTALL_PREFIX to the directory you want citybuilder to get installed to.
*    Set CMAKE_MODULE_PATH to SFML's directory SFML/cmake/Modules or install the FindSFML.cmake in your shared CMake directory.
*    Set SFML_ROOT to the directory SFML can be found in.
*    Generate a make or project file and use that to build citybuilder.

