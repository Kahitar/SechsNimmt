#ifndef REIHEN_HPP_INCLUDED
#define REIHEN_HPP_INCLUDED

#include <iostream>

#include "card.hpp"

class Reihen{
	public:
		Reihen();
		~Reihen();

        int anlegen(const card &play); //TODO: Ist "const" und pass-by-reference hier nötig/richtig/gut???

		void printReihen();

        void getReihen(card MultiArr[4*5], int arr[4]);

        void setFirst(card ErsteSpalte[4]);

        void update();
        void handle(sf::Event *event);
        void render(sf::RenderWindow *rw);

        sf::Vector2f CalculateCardPosition(int CardRow, int CardPosition);
        void         setRowCardPositions();

	private:
		card *ReihenKarten;
		int Reihenlaenge[4];
};

#endif // REIHEN_HPP_INCLUDED
