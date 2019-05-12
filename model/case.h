#ifndef CASE_H
#define CASE_H
#include "objective.h"
#include <ostream>
#include "player.h"
#include <list>
/*
 * Classe qui represente une case du labyrinthe.
 */
class Case
{
protected:
    bool isMovible_;
    Objective objective_;
    int number_;
    bool up_;
    bool down_;
    bool right_;
    bool left_;
    int cpt_;


public:

    /**
    * @brief constructeur qui crée une case avec les valeurs données en paramètre.
    *
    * @param Objective recoit un objectif parmis les 24.
    * @param isMovible permt de savoir si il est deplacable ou non.
    * @param number sera le numero de la case.
    */
    Case(Objective objective, bool isMovible, int number = 0 );
    /**
     * @brief Constructeur qui crée une case avec 1 parametres.
     *
     * @param Objective recoit un objectif parmis les 24.
     */
    Case(Objective objective);
    /**
     * @brief Crée une case par defaut sans parametres.
     */
    Case() = default ;
    //~Case();
    /**
     * @brief methode getter permet d acceder a l attribut concernée.
     */
    bool getIsMovible() const;
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    bool hasObjective() const;
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    int getNumber() const ;
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    bool isI();
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    bool isL();
    /**
     *@brief Constructeur qui cree une case a 2 parametres.
     * @param objectif  parmis les 24.
     * @param isMovible pour savoir si il est deplcable ou non.
     */
    Case(Objective objective, bool isMovible);
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    Objective getObjective() const;
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    inline int getNumber(int number) const ;
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    inline bool getUp() const;
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    inline bool getDown() const;
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    inline bool getRight() const;
    /**
     *@brief methode getter permet d acceder a l attribut concernée.
     */
    inline bool getLeft() const;
    /**
     *@brief methode setter permet de modifier l attribut concernée.
     * @param isAnEntrance savoir qu'elle sont les coter qui sont des entrees.
     */
    void setUp(bool isAnEntrance);
    /**
     *@brief methode setter permet de modifier l attribut concernée.
     * @param isAnEntrance savoir qu'elle sont les coter qui sont des entrees.
     */
    void setDown(bool isAnEntrance);
    /**
     *@brief methode setter permet de modifier l attribut concernée.
     * @param isAnEntrance savoir qu'elle sont les coter qui sont des entrees.
     */
    void setRight(bool isAnEntrance);
    /**
     *@brief methode setter permet de modifier l attribut concernée.
     * @param isAnEntrance savoir quelle sont les coter qui sont des entrees.
     */
    void setLeft(bool isAnEntrance);
    void addPlayer(Player player);
    void rotateCase();
    inline int getCpt();


};

int Case::getCpt()
{
    return cpt_;
}
inline bool Case::getUp() const
{
    return up_;
}
inline bool Case::getDown() const
{
    return down_;
}
inline bool Case::getRight() const
{
    return right_;
}
inline bool Case::getLeft() const
{
    return left_;
}

inline void Case::setUp(bool isAnEntrance)
{
    up_ = isAnEntrance;
}

inline void Case::setDown(bool isAnEntrance)
{
    down_ = isAnEntrance;
}

inline void Case::setRight(bool isAnEntrance)
{
    right_ = isAnEntrance;
}

inline void Case::setLeft(bool isAnEntrance)
{
    left_ = isAnEntrance;
}




#endif // CASE_H
