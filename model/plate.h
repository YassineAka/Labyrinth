#ifndef PLATE_H
#define PLATE_H
#include <vector>
#include <list>
#include "case.h"
#include "casel.h"
#include "casei.h"
#include "caset.h"
#include "position.h"
#include <ostream>
#include <string>
using namespace std;
/**
 * @brief class Plate ou sera gerer le plateau.
 */
class Plate{
private:
    vector<vector<Case>> plate_;
    vector<Objective> objectives_;
    Case remainCase_;
    Case * remainCasePtr_;

public:
    /**
     * @brief constructeur qui va creer un plateau.
     */
    Plate();
    /**
     * @brief insertCase insere une case ds le plateau.
     * @param position position de la case
     */
    void insertCase(Position position);
    /**
     * @brief getPlate permert d avoir le plateau
     * @return le plate.
     */
     inline vector<vector<Case>>* getPlate();
    /**
     * @brief moveIsValid verifie si un deplacemetn est valide.
     * @param pos position du deplacement
     * @return boolean pour valider le deplacement
     */
    bool moveIsValid(vector<vector<int>> tab,Position start, Position destination);
    /**
     * @brief initListObjective initialise les objectif
     */
    void initListObjective();
    /**
     * @brief randomObjective donne les objective au hasard
     * @return un objectif selectionner.
     */
    Objective randomObjective();
    /**
     * @brief getObjectivePlate affiche les objectif du plate
     */
    inline void getObjectivePlate();
    /**
     * @brief accede a la RemainCase
     * @return
     */
    inline Case getRemainCase();
    /**
     * @brief rotation de la remainCase
     */
    void rotateRemainCase();
};
    inline Case Plate::getRemainCase()
    {
        return remainCase_;
    }


    inline vector<vector<Case>>* Plate::getPlate(){
    return &plate_;
}
    inline void Plate::getObjectivePlate(){
        for (unsigned int i = 0; i < plate_.size() ; ++i) {
                for (unsigned int j = 0; j < plate_.size(); ++j) {
                    if (((plate_.at(i)).at(j)).isI()) {
                        cout << static_cast<CaseI>((plate_.at(i)).at(j)).getObjective() << "    ";
                    } else if (((plate_.at(i)).at(j)).isL()){
                        cout << static_cast<CaseL>((plate_.at(i)).at(j)).getObjective() << "    ";
                    }else{
                        cout << static_cast<CaseT>((plate_.at(i)).at(j)).getObjective() << "    " ;
                    }

                    cout<< " | ";

                }
                cout << endl;
                cout << "-----------------------------------------------------------------------------------"<<endl;
            }
    }



inline std::ostream& operator<<(ostream& os, Plate  plate){
for (unsigned int i = 0; i < plate.getPlate()->size() ; ++i) {
        for (unsigned int j = 0; j < plate.getPlate()->size(); ++j) {
            if (((plate.getPlate()->at(i)).at(j)).isI()) {
                os << static_cast<CaseI>((plate.getPlate()->at(i)).at(j)) << "    ";
            } else if (((plate.getPlate()->at(i)).at(j)).isL()){
                os << static_cast<CaseL>((plate.getPlate()->at(i)).at(j)) << "    ";
            }else{
                os << static_cast<CaseT>((plate.getPlate()->at(i)).at(j)) << "    " ;
            }

        }
        os << endl;
        os << endl;
    }
    return os;
}


#endif // PLATE_H
