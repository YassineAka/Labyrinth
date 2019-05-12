#ifndef CASET_H
#define CASET_H
#include "case.h"
#include<ostream>
#include <vector>

using namespace std;

class CaseT : public Case
{
private:
    vector<Player> players;

public:
    /**
     * @brief constructeur qui creee une case de type T
     * @param obj est une objectif de la case
     * @param isMovible si il est deplacable ou non
     * @param number le numero de la case
     */
    CaseT(Objective obj, bool isMovible, int number = 0 );
    /**
     * @brief CaseT
     * @param myCase
     */
    CaseT(Case& myCase);

    /**
     * @brief rotateCase permet de faire la rotation d une case.
     */
    void rotateCase();
    /**
     * @brief addPlayer rajoute un joueur a la partie
     * @param player le joueur qu 'il faut rajouter
     */
    inline void addPlayer(Player player);
    /**
     * @brief getPlayers permet d avoir les joueurs
     * @return tableau de joueur.
     */
    inline vector<Player> getPlayers();
};
inline void CaseT::addPlayer(Player player) {
    players.push_back(player);
}
inline vector<Player> CaseT::getPlayers(){
   return players;
}
inline ostream& operator<<(ostream& os, CaseT caset){
    if ((caset.getUp() == false && caset.getDown() == true && caset.getRight() == true && caset.getLeft() == true))  {
        os << (char) 203;
    } else if((caset.getUp() == true && caset.getDown() == true && caset.getRight() == false && caset.getLeft() == true)){
        os << (char) 185;
    }else if((caset.getUp() == true && caset.getDown() == false && caset.getRight() == true && caset.getLeft() == true)) {
        os << (char) 202;
    }else if((caset.getUp() == true && caset.getDown() == true && caset.getRight() == true && caset.getLeft() == false )) {
        os << (char) 204;
    }
    return os;
}
#endif // CASET_H
