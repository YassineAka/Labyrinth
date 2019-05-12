#ifndef CASEI_H
#define CASEI_H
#include "case.h"
#include <ostream>
#include <vector>

using namespace std;
/**
 * @brief  class CaseI pour la case de type I.
 */
class CaseI : public Case
{
private:
    vector<Player> players;


public:
    /**
     * @brief constructeur qui creee une case de type I
     * @param obj est une objectif de la case
     * @param isMovible si il est deplacable ou non
     * @param number le numero de la case
     */
    CaseI(Objective obj, bool isMovible, int number = 0 );
    /**
     * @brief CaseI constructeur a 1 parametre
     * @param myCase
     */
    CaseI(Case& myCase);
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
inline void CaseI::addPlayer(Player player) {
    players.push_back(player);
}
inline vector<Player> CaseI::getPlayers(){
   return players;
}

inline ostream& operator<<(ostream& os, CaseI casei){
    if ((casei.getUp()== true) && (casei.getDown()== true))  {
        os << (char) 186 ;
    } else {
        os << (char) 205;
    }
    return os;
}

#endif // CASEI_H
