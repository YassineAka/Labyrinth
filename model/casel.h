#ifndef CASEL_H
#define CASEL_H
#include "case.h"
#include <ostream>
#include <vector>

using namespace std;
/**
 * @brief la CaseL class CaseI pour la case de type L.
 */
class CaseL : public Case
{
public:
    /**
     * @brief constructeur qui creee une case de type L
     * @param obj est une objectif de la case
     * @param isMovible si il est deplacable ou non
     * @param number le numero de la case
     */
    CaseL(Objective obj, bool isMovible, int number = 0);
    /**
     * @brief CaseL
     * @param myCase
     */
    CaseL(Case& myCase);

    /**
     * @brief getCpt
     * @return le compteur
     */

    inline int getCpt();
    /**
     * @brief rotateCase permet de faire la rotation d une case.
     */
    void rotateCase();
    inline void addPlayer(Player player);
    inline vector<Player> getPlayers();
private:
     int cpt_;
     vector<Player> players;

};
inline void CaseL::addPlayer(Player player) {
    players.push_back(player);
}
int CaseL::getCpt()
{
    return cpt_;
}
inline vector<Player> CaseL::getPlayers(){
   return players;
}
inline ostream& operator<<(ostream& os, CaseL casel){
    if ((casel.getUp()== true) && (casel.getRight()== true))  {
        os << (char) 200;
    } else if((casel.getDown()== true) && (casel.getRight()== true)){
        os << (char) 201;
    }else if((casel.getDown()== true) && (casel.getLeft()== true)) {
        os << (char) 187;
    }else if((casel.getUp()== true) && (casel.getLeft()== true)) {
        os << (char) 188;
    }
    return os;
}

#endif // CASEL_H
