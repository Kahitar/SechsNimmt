#ifndef REIHEN_HPP_INCLUDED
#define REIHEN_HPP_INCLUDED

#include <iostream>

#include "card.hpp"

class Reihen{
	public:
		Reihen();
		~Reihen();

        int anlegen(card &play);

		void printReihen();

        void getReihen(card MultiArr[4*5], int arr[4]);

        void setFirst(card ErsteSpalte[4]);

        void update();
        void handle(sf::Event *event);
        void render(sf::RenderWindow *rw);

        sf::Vector2f GetCardPosition(int CardRow, int CardPosition);
        void         setRowCardPositions();

	private:
		card *ReihenKarten;
		int Reihenlaenge[4];
};

#endif // REIHEN_HPP_INCLUDED
