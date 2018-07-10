Creating A City Building Game With SFML
===========

*This is an old tutorial written several years ago for a website which no longer exists. There are no guarantees that
it adheres to the modern best-practices, and it could do with several improvements, but I have migrated it here in
case people still find it useful.*

Code for each tutorial part is found in the corresponding folder, the
main code is the final version. The tutorial itself is now hosted inside
the `tutorial` folder.

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

