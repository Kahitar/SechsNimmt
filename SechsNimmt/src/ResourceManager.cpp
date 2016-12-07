#include "ResourceManager.hpp"

ResourceCache ResourceManager::mResourceCache;
DataCache ResourceManager::mDataCache;
SettingsCache ResourceManager::mSettingsCache;

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


int ResourceManager::getKINumber()
{
    return mSettingsCache.getKINumber();
}

int ResourceManager::getStartCardsNumber()
{
    return mSettingsCache.getStartCardsNumber();
}

void ResourceManager::setKINumber(int NumberOfKIs)
{
    mSettingsCache.setKINumber(NumberOfKIs);
}

void ResourceManager::setStartCardsNumber(int NumberStartingCards)
{
    mSettingsCache.setKINumber(NumberStartingCards);
}
