#include "Reihen.hpp"

Reihen::Reihen(){
    ReihenKarten = new card[4*5];
}

Reihen::~Reihen(){
    delete[] ReihenKarten;
}

void Reihen::printReihen(){
    for(int i = 0;i<4;i++){
        std::cout << "Row " << i+1 << ": ";

        for(int j=0;j<Reihenlaenge[i];j++){
            std::cout << ReihenKarten[i*5+j].getValue() << "[" << ReihenKarten[i*5+j].getHornochsen() << "]";
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

void Reihen::getReihen(card MultiArr[4*5], int arr[4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            MultiArr[i*5 + j] = ReihenKarten[i*5+j];
        }
        arr[i] = Reihenlaenge[i];
    }
}

int Reihen::anlegen(const card &play){
    int difference[4];
    int mindiff_index = 0;
    int mieseHornochsen = 0;

    for(int i=0;i<4;i++){
        difference[i] = play.getValue() - this->ReihenKarten[i*5+(Reihenlaenge[i]-1)].getValue();
    }

    //Abfrage, ob es eine positive Differenz gibt. Wenn nicht, welche Reihe genommen werden soll (gesamte Schleife)
    int i = 0;
    bool angelegt = false;
    while(true){
        if(difference[i] > 0){
            mindiff_index = i;
            break;
        }

/*        //Spieler muss Reihe nehmen:
        if(i == 3 && mindiff_index == 0 && play.getSpielerNr() == 1){
            int a;
            std::cout << "Your Card is to low to append to a row! Choose the row (by number) you want to take: \n\n";
            this->printReihen();
            std::cout << "Take Row number: 1\n"; //TODO: Let Player decide!
            a = 1;
//            std::cin >> a;
//            std::cout << std::endl;

            //Hornochsen der Reihe ausrechnen, Reihe "löschen" und mit gespielter Karte neu starten
            for(int j=0;j<Reihenlaenge[a-1];j++){
                mieseHornochsen+= ReihenKarten[(a-1)*5+j].getHornochsen();
            }
            ReihenKarten[(a-1)*5+0] = play;
            Reihenlaenge[a-1] = 1;
            angelegt = true;
            setRowCardPositions();
            break;

        // KI muss Reihe nehmen
        } else*/ if (i == 3 && mindiff_index == 0){
            //Auswahl einer Reihe von KI (in Zukunft von KI_Spieler Klasse erledigen lassen
            int HornochsenGesamt[4];
//            int minHornochsen = HornochsenGesamt[0];
            int minHornochsen_index = 0;
            for(int j = 0;j<4;j++){
                for(int k=0;k<Reihenlaenge[j];k++){
                    HornochsenGesamt[j] += ReihenKarten[j*5+k].getHornochsen();
                }
                if(HornochsenGesamt[j] < HornochsenGesamt[minHornochsen_index]){
                    minHornochsen_index = j;
                }
            }

            std::cout << "KI-" << play.getSpielerNr()-1 << " took Row " << minHornochsen_index+1 << "\n";

            //Hornochsen austeilen
            for(int j=0;j<Reihenlaenge[minHornochsen_index];j++){
                mieseHornochsen+= ReihenKarten[minHornochsen_index*5+j].getHornochsen();
            }
            ReihenKarten[minHornochsen_index*5+0] = play;
            Reihenlaenge[minHornochsen_index] = 1;
            setRowCardPositions();
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
            ReihenKarten[mindiff_index*5 + Reihenlaenge[mindiff_index]++] = play;
            setRowCardPositions();
        } else {
            for(int i=0;i<Reihenlaenge[mindiff_index];i++){
                mieseHornochsen+= ReihenKarten[mindiff_index*5+i].getHornochsen();
            }
            if(play.getSpielerNr() == 1){
                std::cout << "You had to take Row " << mindiff_index + 1 << std::endl << std::endl;
            } else {
                std::cout << "KI-" << play.getSpielerNr() - 1 << " had to take Row " << mindiff_index+1 << std::endl << std::endl;
            }
            ReihenKarten[mindiff_index*5+0] = play;
            Reihenlaenge[mindiff_index] = 1;
            setRowCardPositions();
        }
    }
    return mieseHornochsen;
}

void Reihen::setFirst(card ErsteSpalte[4]){
    for(int i=0;i<4;i++){
        Reihenlaenge[i] = 1;
        ReihenKarten[i*5+0] = ErsteSpalte[i];
    }
    setRowCardPositions();
}

void Reihen::update()
{

}

void Reihen::handle(sf::Event *event)
{

}

void Reihen::render(sf::RenderWindow *rw)
{
    //Reihenkarten zeichnen
    for(int i = 0;i<4;i++){
        for(int j = 0; j<Reihenlaenge[i];j++){
            ReihenKarten[i*5+j].render(rw);
        }
    }
}

sf::Vector2f Reihen::CalculateCardPosition(int CardRow, int CardColumn)
{
    float CardW = 134, CardH = 205, WindowW = 1600, WindowH = 800;
    float SpacingW = 1.5, SpacingH = 0.8;

    sf::Vector2f Position;
    Position.x = (WindowW-4.0*CardW*SpacingW)/2.0 + CardColumn*CardW*SpacingW;
    Position.y = (WindowH-4.0*CardH*SpacingH-CardH/2.0)/5.0 + CardRow*CardH*SpacingH;

    return Position;
}

void Reihen::setRowCardPositions(){
    for(int i = 0;i<4;i++){
        for(int j = 0; j<Reihenlaenge[i];j++){
            ReihenKarten[i*5+j].setPosition(CalculateCardPosition(i,j));
        }
    }
}
