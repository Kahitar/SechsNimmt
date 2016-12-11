#include "ResourceCache.hpp"

ResourceCache::ResourceCache()
{
    //ctor
}

ResourceCache::~ResourceCache()
{
    //dtor
}


sf::Texture ResourceCache::getTexture(std::string TexturePath)
{
    //lookup the texture and see if its in the map
    auto it = mTextureMap.find(TexturePath);

    //Check if its not in the map
    if(it == mTextureMap.end()){
        //Load the texture
        sf::Texture newTexture;
        newTexture.loadFromFile(TexturePath);

        //Insert it into the map
        mTextureMap.insert(make_pair(TexturePath, newTexture));

        return newTexture;
    }

    return it->second;
}
