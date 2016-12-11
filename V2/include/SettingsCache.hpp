#ifndef SETTINGSCACHE_HPP
#define SETTINGSCACHE_HPP

class SettingsCache
{
    public:
        SettingsCache();
        ~SettingsCache();

        //// GETTER ////
        int getKINumber();
        int getStartCardsNumber();

        //// SETTER ////
        void setKINumber(int NumberKIs);
        void setStartCardsNumber(int NumberStartingCards);

    private:
        int mNumberKIs;
        int mNumberStartingCards;
};

#endif // SETTINGSCACHE_HPP
