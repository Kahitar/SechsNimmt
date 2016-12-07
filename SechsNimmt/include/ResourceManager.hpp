#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <string>
#include <memory>
#include "ResourceCache.hpp"
#include "DataCache.hpp"
#include "deck.hpp"

class ResourceManager
{
    public:
         ResourceManager();
        ~ResourceManager();

        static sf::Texture           getTexture(std::string TexturePath);
        static std::shared_ptr<deck> getNewDeckPTR();

    private:
        static ResourceCache mResourceCache;
        static DataCache     mDataCache;
};

#endif // RESOURCEMANAGER_HPP
