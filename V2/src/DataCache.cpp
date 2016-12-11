#include "DataCache.hpp"

DataCache::DataCache()
{
    spGameDeck = std::shared_ptr<deck> (new deck);
}

DataCache::~DataCache()
{

}

std::shared_ptr<deck> DataCache::getNewDeckPTR()
{
    spGameDeck->mischen();
    return spGameDeck;
}
