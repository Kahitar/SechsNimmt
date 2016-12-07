#ifndef RESOURCECACHE_HPP
#define RESOURCECACHE_HPP

#include <iostream>
#include <map>
#include <string>
#include "SFML/Graphics.hpp"

class ResourceCache
{
    public:
        ResourceCache();
        ~ResourceCache();

        sf::Texture getTexture(std::string TexturePath);
//        sf::Sprite  getSprite(std::string SpriteName);

    private:
        std::map<std::string, sf::Texture> mTextureMap;
//        std::map<std::string, sf::Sprite>  mSpriteMap;

};

#endif // RESOURCECACHE_HPP
