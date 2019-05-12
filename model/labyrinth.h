#ifndef LABYRINTH_H
#define LABYRINTH_H

#include "color.h"
#include "position.h"
#include "objective.h"
#include "player.h"
#include "plate.h"
#include <list>
#include <ostream>
#include "subject.h"
#include <QString>
/**
 * @brief class Labyrinth qui s'occupe du controle du jeu
 */
class Labyrinth : public nvs::Subject{

private:
    Plate plate_;
    std::vector<Player> players_;
    Player* CurrentPlayer_;
    bool gameIsOver_;

public:
    /**
     * @brief constructeur qui va creer une partie avec un plateau fournie.
     * @param plate le plateau ou se deroulera la partie.
     */
    Labyrinth(Plate plate);
    /**
     * @brief start lance le debut du jeu
     */
    void start();

    /**
     * @brief isOver controle la fin du jeu ou non.
     * @return boolean pour savoir si le jeu est fini ou non.
     */
        bool isOver();
    /**
     * @brief getWinner donne le gagnant
     * @return le joueur gagnant.
     */
    Player getWinner();
    /**
     * @brief nextPlayer passe au joueur suivant.
     */
    void nextPlayer();
    /**
     * @brief PlaceNewCase place la nouvelle case
     * @param pos position ou la place sera placer.
     */
    void  placeNewCase(Position pos);//demander si d accord avec bool
    /**
     * @brief move fais le deplacement d un joueur.
     * @param pos position ou le joueur veut se deplacer.
     */
    void move(Position pos);
    /**
     * @brief afficherPlayer
     */
    inline vector<Player> getAllPlayers()  ;
    inline Plate getPlate();
    inline Player getCurrentPlayer();
    list<Player> getPlayersAt(Position pos);
    inline bool isGameOver();
    void rotateRemainCase();

};

inline bool Labyrinth::isGameOver()
{
    return gameIsOver_;
}

inline vector<Player> Labyrinth::getAllPlayers()
{
    return players_;
}
inline Plate Labyrinth::getPlate(){
    return plate_;
}
inline Player Labyrinth::getCurrentPlayer(){
    return *CurrentPlayer_;
}

inline std::ostream& operator<<(ostream& os, Labyrinth  labyrinth){
        os << "the player " << labyrinth.getAllPlayers()[0] << " is in " << labyrinth.getAllPlayers().at(0).getPosition() << "\n"
              << "the player " << labyrinth.getAllPlayers().at(1) << " is in " << labyrinth.getAllPlayers().at(1).getPosition() << "\n"
                 << "the player " << labyrinth.getAllPlayers().at(2) << " is in " << labyrinth.getAllPlayers().at(2).getPosition() << "\n"
                    << "the player " << labyrinth.getAllPlayers().at(3) << " is in " << labyrinth.getAllPlayers().at(3).getPosition();
     return os;
}
#endif // LABYRINTH_H
