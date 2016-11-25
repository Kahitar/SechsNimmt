#ifndef REIHEN_HPP_INCLUDED
#define REIHEN_HPP_INCLUDED

#include <iostream>

#include <card.hpp>


class Reihen{
	public:
		//Reihen(card erste_Spalte[4]);
		Reihen(){};
		~Reihen(){};

        int anlegen(card play);

		void printReihen();

        void getReihen(card MultiArr[4][5], int arr[4]);

        void setFirst(card ErsteSpalte[4]);

	private:
		card reihen_karten[4][5];
		int Reihenlaenge[4];
};

#endif // REIHEN_HPP_INCLUDED
