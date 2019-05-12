#include "plate.h"
#include "case.h"
#include <list>
#include "caset.h"
#include "casel.h"
#include "casei.h"
#include "objective.h"
#include <algorithm>
#include "time.h"

Plate::Plate()
{
    vector<vector<Case>> tab2D;
    plate_ = tab2D;
    vector<Case> tab1D(7);

    vector<Case> caseAmovible;
    vector<Case> caseMobile;
    for(int i=0;i<7;i++)
        {
            plate_.push_back(tab1D);
        }
    /*case amovible  depart*/
    CaseL caseDepartFour(Objective::NONE,false,4);
    CaseL caseDepartThree(Objective::NONE,false,3);
    CaseL caseDepartTwo(Objective::NONE,false,2);
    CaseL caseDepartOne(Objective::NONE,false,1);
    /*-case inamovible de type T.
      -Attention ils ont tous des objectif voir le schema du jeu.
    */


    initListObjective();
    CaseT caseRowZeroOne(randomObjective(),false,6);
    CaseT caseRowZeroTwo(randomObjective(),false,6);
    CaseT caseRowTwoOne(randomObjective(),false,6);
    caseRowTwoOne.rotateCase();
    caseRowTwoOne.rotateCase();
    caseRowTwoOne.rotateCase();
    CaseT caseRowTwoTwo(randomObjective(),false,6);
    caseRowTwoTwo.rotateCase();
    caseRowTwoTwo.rotateCase();
    caseRowTwoTwo.rotateCase();
    CaseT caseRowTwoThree(randomObjective(),false,6);
    CaseT caseRowTwoFour(randomObjective(),false,6);
    caseRowTwoFour.rotateCase();
    CaseT caseRowFourOne(randomObjective(),false,6);
    caseRowFourOne.rotateCase();
    caseRowFourOne.rotateCase();
    caseRowFourOne.rotateCase();
    CaseT caseRowFourTwo(randomObjective(),false,6);
    caseRowFourTwo.rotateCase();
    caseRowFourTwo.rotateCase();
    CaseT caseRowFourThree(randomObjective(),false,6);
    caseRowFourThree.rotateCase();
    CaseT caseRowFourFour(randomObjective(),false,6);
    caseRowFourFour.rotateCase();
    CaseT caseRowSixOne(randomObjective(),false,6);
    caseRowSixOne.rotateCase();
    caseRowSixOne.rotateCase();
    CaseT caseRowSixTwo(randomObjective(),false,6);
    caseRowSixTwo.rotateCase();
    caseRowSixTwo.rotateCase();


    caseAmovible.push_back(caseRowZeroOne);
    caseAmovible.push_back(caseRowZeroTwo);
    caseAmovible.push_back(caseRowTwoOne);
    caseAmovible.push_back(caseRowTwoTwo);
    caseAmovible.push_back(caseRowTwoThree);
    caseAmovible.push_back(caseRowTwoFour);
    caseAmovible.push_back(caseRowFourOne);
    caseAmovible.push_back(caseRowFourTwo);
    caseAmovible.push_back(caseRowFourThree);
    caseAmovible.push_back(caseRowFourFour);
    caseAmovible.push_back(caseRowSixOne);
    caseAmovible.push_back(caseRowSixTwo);
    /*case mobile de typeT  6 toute marqué d un objectif*/
    caseMobile.push_back(CaseT (randomObjective(),true,22));
    caseMobile.push_back(CaseT (randomObjective(),true,24));
    caseMobile.push_back(CaseT (randomObjective(),true,25));
    caseMobile.push_back(CaseT (randomObjective(),true,26));
    caseMobile.push_back(CaseT (randomObjective(),true,27));
    caseMobile.push_back(CaseT (randomObjective(),true,28));
    caseMobile.push_back(CaseL (randomObjective(),true,28));
    caseMobile.push_back(CaseL (randomObjective(),true,28));
    caseMobile.push_back(CaseL (randomObjective(),true,28));
    caseMobile.push_back(CaseL (randomObjective(),true,28));
    caseMobile.push_back(CaseL (randomObjective(),true,28));
    caseMobile.push_back(CaseL (randomObjective(),true,28));
    /* case type L non marquee*/
    caseMobile.push_back(CaseL (Objective::NONE,true,28));
    caseMobile.push_back(CaseL (Objective::NONE,true,28));
    caseMobile.push_back(CaseL (Objective::NONE,true,28));
    caseMobile.push_back(CaseL (Objective::NONE,true,28));
    caseMobile.push_back(CaseL (Objective::NONE,true,28));
    caseMobile.push_back(CaseL (Objective::NONE,true,28));
    caseMobile.push_back(CaseL (Objective::NONE,true,28));
    caseMobile.push_back(CaseL (Objective::NONE,true,28));
    caseMobile.push_back(CaseL (Objective::NONE,true,28));
    caseMobile.push_back(CaseL (Objective::NONE,true,28));

    /*case mobile de type I non marquées*/
    caseMobile.push_back(CaseI (Objective::NONE,true,5));
    caseMobile.push_back(CaseI (Objective::NONE,true,7));
    caseMobile.push_back(CaseI (Objective::NONE,true,9));
    caseMobile.push_back(CaseI (Objective::NONE,true,10));
    caseMobile.push_back(CaseI (Objective::NONE,true,11));
    caseMobile.push_back(CaseI (Objective::NONE,true,12));
    caseMobile.push_back(CaseI (Objective::NONE,true,13));
    caseMobile.push_back(CaseI (Objective::NONE,true,14));
    caseMobile.push_back(CaseI (Objective::NONE,true,15));
    caseMobile.push_back(CaseI (Objective::NONE,true,16));
    caseMobile.push_back(CaseI (Objective::NONE,true,18));

    //MOVING BOX
    remainCase_ = (CaseI (Objective::NONE,true,20));
    std::srand (time(0));
    std::random_shuffle(caseMobile.begin(), caseMobile.end());
    int x = 0;
    int y = 0;
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if(i==0 && j==0){
                caseDepartOne.rotateCase();
                plate_[i][j] = caseDepartOne;
            }
            if(i==0 && j==6){
                caseDepartTwo.rotateCase();
                caseDepartTwo.rotateCase();
                plate_[i][j] = caseDepartTwo;
            }
            if(i==6 && j==6){
                caseDepartThree.rotateCase();
                caseDepartThree.rotateCase();
                caseDepartThree.rotateCase();
               plate_[i][j] = caseDepartThree;
            }
            if(i==6 && j==0){
                plate_[i][j] = caseDepartFour;
            }
            if((i%2==0 && j%2==0)){
                if((i!=0 || j!=0) && (i!=0 || j!=6) && (i!=6 || j!=0) && (i!=6 || j!=6)){
                        plate_[i][j] = caseAmovible[x];
                        x++;


                }
            }

            if(i%2!=0 || j%2!=0){
                plate_[i][j] = caseMobile[y];
                y++;
            }
        }
    }



}


Objective Plate::randomObjective()
{
    std::srand (time(0));
    std::random_shuffle(objectives_.begin(), objectives_.end());
    Objective obj = objectives_.back();
    objectives_.pop_back();
    return obj;
}



void Plate::initListObjective()
{
    objectives_.push_back(Objective::GHOST);
    objectives_.push_back(Objective::GNOME);
    objectives_.push_back(Objective::DRAGON);
    objectives_.push_back(Objective::FAIRY);
    objectives_.push_back(Objective::GENIUS);
    objectives_.push_back(Objective::BAT);
    objectives_.push_back(Objective::BEETLE);
    objectives_.push_back(Objective::OWLS);
    objectives_.push_back(Objective::RAT);
    objectives_.push_back(Objective::SPIDER);
    objectives_.push_back(Objective::BUTTERFLY);
    objectives_.push_back(Objective::LIZARD);
    objectives_.push_back(Objective::GRIMOIRE);
    objectives_.push_back(Objective::GOLD_PURSE);
    objectives_.push_back(Objective::MAP);
    objectives_.push_back(Objective::CROWN);
    objectives_.push_back(Objective::KEYS);
    objectives_.push_back(Objective::BONES);
    objectives_.push_back(Objective::RING);
    objectives_.push_back(Objective::EMERALD);
    objectives_.push_back(Objective::TREASURE_CHEST);
    objectives_.push_back(Objective::SWORD);
    objectives_.push_back(Objective::CUNDLESTICK);
    objectives_.push_back(Objective::HELM);
    objectives_.push_back(Objective::WIZZARDY);


}
void Plate::insertCase(Position pos){
    int x = pos.getX();
    int y = pos.getY();
    std::vector<Case> tabCase;


    //vertical BAS->HAUT
    if(x==6){
        int indice = 0;
        tabCase.push_back(remainCase_);
        for (int i = plate_.size()-1; i >=0 ; i--) {
            tabCase.push_back(plate_[i][y]);
        }
        remainCase_ = tabCase.back();
        tabCase.pop_back();
        for (int j = plate_.size()-1; j >= 0; j--) {
            plate_[j][y] = tabCase[indice];
            indice++;
        }
        tabCase.clear();
    }

    //Horizontal DROITE->GAUCHE
    if(y==6){
        int indice = 0;
        tabCase.push_back(remainCase_);
        for (int i = plate_.size()-1; i >=0 ; i--) {
            tabCase.push_back(plate_[x][i]);
        }
        remainCase_ = tabCase.back();
        tabCase.pop_back();
        for (int j = plate_.size()-1; j >= 0; j--) {
            plate_[x][j] = tabCase[indice];
            indice++;
        }
        tabCase.clear();
    }
    //vertical HAUT->BAS
    if(x==0){
        int indice = 0;
        tabCase.push_back(remainCase_);
        for (int i = 0; i < 7; i++) {
            tabCase.push_back(plate_[i][y]);
        }
        remainCase_ = tabCase.back();
        tabCase.pop_back();
        for (int j = 0; j < 7; j++) {
            plate_[j][y] = tabCase[indice];
            indice++;
        }
        tabCase.clear();
    }

    //horizontal GAUCHE->DROITE
    if(y==0){
        int indice = 0;
        tabCase.push_back(remainCase_);
        for (int i = 0; i < 7; i++) {
            tabCase.push_back(plate_[x][i]);
        }
        remainCase_ = tabCase.back();
        tabCase.pop_back();
        for (int j = 0; j < 7; j++) {
            plate_[x][j] = tabCase[indice];
            indice++;
        }
        tabCase.clear();
    }
}

bool Plate::moveIsValid(vector<vector<int>> possiblePath,Position currentPos, Position destination){
    if ((currentPos.getX() == destination.getX()) && (currentPos.getY() == destination.getY())) {
        return true;
    }
    if ((currentPos.getX() < plate_.size()) &&(currentPos.getY() < plate_.size())) {
        possiblePath[currentPos.getX()][currentPos.getY()] = 1;

        if (((((plate_[currentPos.getX()][currentPos.getY()]).getDown())== true) && (((plate_[currentPos.getX()+1][currentPos.getY()]).getUp())== true))
                && ((possiblePath[currentPos.getX()+1][currentPos.getY()] != 1) ))
        {
            if (moveIsValid(possiblePath, Position(currentPos.getX()+1,currentPos.getY()),destination)) {
                return true;
            }
        }
        if (((((plate_[currentPos.getX()][currentPos.getY()]).getUp())== true) && (((plate_[currentPos.getX()-1][currentPos.getY()]).getDown())== true))
                && ((possiblePath[currentPos.getX()-1][currentPos.getY()] != 1) ))
        {
            if (moveIsValid(possiblePath, Position(currentPos.getX()-1,currentPos.getY()),destination)) {
                return true;
            }
        }
        if (((((plate_[currentPos.getX()][currentPos.getY()]).getRight())== true) && (((plate_[currentPos.getX()][currentPos.getY()+1]).getLeft())== true))
                && ((possiblePath[currentPos.getX()][currentPos.getY()+1] != 1) ))
        {
            if (moveIsValid(possiblePath, Position(currentPos.getX(),currentPos.getY()+1),destination)) {
                return true;
            }
        }
        if (((((plate_[currentPos.getX()][currentPos.getY()]).getLeft())== true) && (((plate_[currentPos.getX()][currentPos.getY()-1]).getRight())== true))
                && ((possiblePath[currentPos.getX()][currentPos.getY()-1] != 1) ))
        {
            if (moveIsValid(possiblePath, Position(currentPos.getX(),currentPos.getY()-1),destination)) {
                return true;
            }
        }
        possiblePath[currentPos.getX()][currentPos.getY()] =0;
        return false;



    }
}
void Plate::rotateRemainCase()
{
    remainCase_.rotateCase();
}
