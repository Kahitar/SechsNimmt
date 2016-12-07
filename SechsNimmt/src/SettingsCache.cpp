#include "SettingsCache.hpp"

SettingsCache::SettingsCache()
    :mNumberKIs(3),mNumberStartingCards(10)
{
    //ctor
}

SettingsCache::~SettingsCache()
{
    //dtor
}

int SettingsCache::getKINumber()
{
    return mNumberKIs;
}

int SettingsCache::getStartCardsNumber()
{
    return mNumberStartingCards;
}

void SettingsCache::setKINumber(int NumberOfKIs)
{
    mNumberKIs = NumberOfKIs;
}

void SettingsCache::setStartCardsNumber(int NumberStartingCards)
{
    mNumberStartingCards = NumberStartingCards;
}
