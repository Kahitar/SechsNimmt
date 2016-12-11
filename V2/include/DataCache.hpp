#ifndef DATACACHE_H
#define DATACACHE_H

#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "deck.hpp"

class DataCache
{
    public:
        DataCache();
        ~DataCache();

        std::shared_ptr<deck> getNewDeckPTR();
    private:
        std::shared_ptr<deck> spGameDeck;

};

#endif // DATACACHE_H
