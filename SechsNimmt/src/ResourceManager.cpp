#include "ResourceManager.hpp"

ResourceCache ResourceManager::mResourceCache;
DataCache ResourceManager::mDataCache;

ResourceManager::ResourceManager()
{
    //ctor
}

ResourceManager::~ResourceManager()
{
    //dtor
}

sf::Texture ResourceManager::getTexture(std::string TexturePath)
{
    return mResourceCache.getTexture(TexturePath);
}

std::shared_ptr<deck> ResourceManager::getNewDeckPTR()
{
    return mDataCache.getNewDeckPTR();
}
