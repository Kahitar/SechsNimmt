#include <iostream>

#include <Reihen.hpp>

//Reihen::Reihen(card erste_Spalte[4]){
//    for(int i=0;i<4;i++){
//        Reihenlaenge[i] = 1;
//        reihen_karten[i][0] = erste_Spalte[i];
//    }
//}

void Reihen::printReihen(){
    for(int i = 0;i<4;i++){
        std::cout << "Row " << i+1 << ": ";

        for(int j=0;j<Reihenlaenge[i];j++){
            std::cout << reihen_karten[i][j].value << "[" << reihen_karten[i][j].hornochsen << "]";
            if(j!=Reihenlaenge[i]-1){
                std::cout << ", ";
            } else {
                std::cout << std::endl;
            }
        }
        if(i == 3){
            std::cout << std::endl;
        }
    }
}

void Reihen::getReihen(card MultiArr[4][5], int arr[4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            MultiArr[i][j] = reihen_karten[i][j];
        }
        arr[i] = Reihenlaenge[i];
    }
}

int Reihen::anlegen(card play){
    int difference[4];
    int mindiff_index = 0;
    int mieseHornochsen = 0;

    for(int i=0;i<4;i++){
        difference[i] = play.value - this->reihen_karten[i][Reihenlaenge[i]-1].value;
    }

    //Abfrage, ob es eine positive Differenz gibt. Wenn nicht, welche Reihe genommen werden soll (gesamte Schleife)
    int i = 0;
    bool angelegt = false;
    while(true){
        if(difference[i] > 0){
            mindiff_index = i;
            break;
        }

        //Spieler muss Reihe nehmen:
        if(i == 3 && mindiff_index == 0 && play.SpielerNr == 1){
            int a;
            std::cout << "Your Card is to low to append to a row! Choose the row (by number) you want to take: \n\n";
            this->printReihen();
            std::cout << "Take Row number: "; std::cin >> a; std::cout << std::endl;

            //Hornochsen der Reihe ausrechnen, Reihe "löschen" und mit gespielter Karte neu starten
            for(int j=0;j<Reihenlaenge[a-1];j++){
                mieseHornochsen+= reihen_karten[a-1][j].hornochsen;
            }
            reihen_karten[a-1][0] = play;
            Reihenlaenge[a-1] = 1;
            angelegt = true;
            break;

        // KI muss Reihe nehmen
        } else if (i == 3 && mindiff_index == 0){
            //Auswahl einer Reihe von KI (in Zukunft von KI_Spieler Klasse erledigen lassen
            int HornochsenGesamt[4];
            for(int j = 0;j<4;j++){
                for(int k=0;k<Reihenlaenge[j];k++){
                    HornochsenGesamt[j] += reihen_karten[j][k].hornochsen;
                }
            }
            int minHornochsen = HornochsenGesamt[0];
            int minHornochsen_index = 0;
            for(int j = 0;j<4;j++){
                if(HornochsenGesamt[j]<minHornochsen){
                    minHornochsen = HornochsenGesamt[j];
                    minHornochsen_index = j;
                }
            }
            std::cout << "KI-" << play.SpielerNr-1 << " took Row " << minHornochsen_index+1 << "\n";

            //Hornochsen austeilen
            for(int j=0;j<Reihenlaenge[minHornochsen_index];j++){
                mieseHornochsen+= reihen_karten[minHornochsen_index][j].hornochsen;
            }
            reihen_karten[minHornochsen_index][0] = play;
            Reihenlaenge[minHornochsen_index] = 1;
            angelegt = true;
            break;
        }
        i++;
    }

    if(!angelegt){
        for(int i=0;i<4;i++){
            if(difference[i] < difference[mindiff_index] && difference[i] > 0){
                mindiff_index = i;
            }
        }
        if(Reihenlaenge[mindiff_index] != 5){
            reihen_karten[mindiff_index][Reihenlaenge[mindiff_index]++] = play;
        } else {
            for(int i=0;i<Reihenlaenge[mindiff_index];i++){
                mieseHornochsen+= reihen_karten[mindiff_index][i].hornochsen;
            }
            if(play.SpielerNr == 1){
                std::cout << "You had to take Row " << mindiff_index + 1 << std::endl << std::endl;
            } else {
                std::cout << "KI-" << play.SpielerNr - 1 << " had to take Row " << mindiff_index+1 << std::endl << std::endl;
            }
            reihen_karten[mindiff_index][0] = play;
            Reihenlaenge[mindiff_index] = 1;
        }
    }
    return mieseHornochsen;
}

void Reihen::setFirst(card ErsteSpalte[4]){
    for(int i=0;i<4;i++){
        Reihenlaenge[i] = 1;
        reihen_karten[i][0] = ErsteSpalte[i];
    }
}
