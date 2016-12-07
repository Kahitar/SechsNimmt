#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <string>
#include <memory>
#include "ResourceCache.hpp"
#include "DataCache.hpp"
#include "SettingsCache.hpp"
#include "deck.hpp"

class ResourceManager
{
    public:
         ResourceManager();
        ~ResourceManager();

        //// GETTER ////

        //ResourceCache
        static sf::Texture getTexture(std::string TexturePath);

        //DataCache
        static std::shared_ptr<deck> getNewDeckPTR();

        //SettingsCache
        static int getKINumber();
        static int getStartCardsNumber();

        //// SETTER ////

        //SettingsCache
        static void setKINumber(int NumberOfKIs);
        static void setStartCardsNumber(int nNmberStartingCards);


    private:
        static ResourceCache mResourceCache;
        static DataCache     mDataCache;
        static SettingsCache mSettingsCache;
};

#endif // RESOURCEMANAGER_HPP
