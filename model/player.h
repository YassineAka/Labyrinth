#ifndef PLAYER_H
#define PLAYER_H
#include <stack>

#include "color.h"
#include "position.h"
#include "objective.h"
#include <list>
#include <QPixmap>

using namespace std;
/**
 * @brief class Player va s'occuper des joueurs.
 */
class Player{
private:
    Color color_;
    bool isFinish_;
    Position pos_;
    stack<Objective> stock_;
    int index_;

public:
    /**
    * @brief constrcuteur par defaut.
    */
    Player() = default;
    /**
     * @brief constructeur avec les parametre d'un joueur.
     * @param color Couleur du joueur.
     * @param pos position d'un joueur.
     * @param list sa liste d'objective.
     */
    Player(Color color,Position pos, stack<Objective> list, int index);
    /**
     * @brief getter de l attribut color
     * @return la couleur
     */
    inline Color getColor()const ;
    /**
     * @brief setColor setter de l'attribut color
     * @param color couleur a changer
     */
    inline void  setColor(Color color);
    /**
     * @brief getter de l'attribut Objective
     * @return l obejctive trouver
     */
    inline Objective getObjective() const;
    /**
     * @brief getter du Stock d'objective.
     * @return
     */
    inline stack<Objective>& getStock();
    /**
     * @brief getter de Position
     * @return la positipon trouver.
     */
    inline Position getPosition() const;
    /**
     * @brief getter du NextObjective
     */
    void getNextObjective();
    /**
     * @brief move mouvement d'un player
     */
    void move(Position pos);
    /**
     * @brief hasWon savoir qui a gagner
     * @return
     */
    bool hasWon();
    /**
     * @brief chooseEntrance permet au joueurs de choisir une entree.
     * @param pos
     */
    void chooseEntrance(Position pos);
    int getIndex();
    QPixmap getImage(Objective obj);
    inline string getStringFromColor();

};

inline string Player::getStringFromColor()
{
    std::string name;
    switch(color_){
    case Color::BLUE:
         name =  "blue";
        break;
    case Color::RED:
        name =  "red";
        break;
    case Color::GREEN:
        name =  "green";
        break;
    case Color::YELLOW:
        name =  "yellow";
        break;
    default:
        ;
    }
    return name;
}

inline Color Player::getColor() const
{
    return color_;
}
inline Position Player::getPosition() const
{
    return pos_;
}

inline void Player::setColor(Color color)
{
     color_ = color;
}

inline Objective Player::getObjective() const
{
    return stock_.top();
}

inline stack<Objective>& Player::getStock()
{
    stack<Objective> * pi = &stock_;
    return *pi;
}
inline Player::getIndex(){
    return index_;
}

inline std::ostream& operator<<(ostream& os, Player const& player){
    if (player.getColor() ==Color::BLUE) {
        os << "B";
    }else if(player.getColor()==Color::RED){
        os << "R";
    }else if(player.getColor()==Color::GREEN){
        os << "G";
    }else{
        os << "Y";
    }
    return os;
}
#endif // PLAYER_H

