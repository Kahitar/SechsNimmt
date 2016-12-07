#include "DataCache.hpp"

DataCache::DataCache()
{
    spGameDeck = std::shared_ptr<deck> (new deck);

    // Deck will be shuffled on being requested (getNewDeckPTR)
    std::cout << "Deck loaded" << std::endl;
}

DataCache::~DataCache()
{

}

std::shared_ptr<deck> DataCache::getNewDeckPTR()
{
    spGameDeck->mischen();
    return spGameDeck;
}
