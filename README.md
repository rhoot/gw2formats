gw2formats
==========

Library used for reading Guild Wars 2's files in a type-safe manner. It is not the intention of 
this library to help you identify the data contained in the files. This library works best if you
know what data you are after and just want to get to it.

The library is entirely type-safe, meaning you will get a compile-time error if you try to read a
chunk of a type that is unsupported by the file you have loaded. Such as loading a DX9S chunk from
a model file.

Usage
-----

As an example, maybe you are writing a map viewer and want to get to the height map:

    gw2f::pf::MapPackFile mapFile(filename);
    auto terrainChunk = mapFile.chunk<gw2f::pf::MapChunks::Terrain>();
    auto& heightMap   = terrainChunk.heightMapArray;

See the samples folder for other examples.

Restrictions
------------

Gw2formats uses C++11 features available in modern compilers. While it should compile under both 
GCC and clang, neither has been tested. It does however compile perfectly well under MSVC10+.

Contributing
------------

For contributions, please go to [this project's page on GitHub](https://github.com/rhoot/gw2formats).