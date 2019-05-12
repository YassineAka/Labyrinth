#ifndef BOX_H
#define BOX_H

#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <qgridlayout.h>
#include "model/case.h"
#include "model/caset.h"
#include "model/casei.h"
#include "model/casel.h"
#include <list>
#include "model/objective.h"

class Box : public QGridLayout
{
private:
    QLabel * playerBlue_;
    QLabel * playerGreen_;
    QLabel * playerYellow_;
    QLabel * playerRed_;
    QLabel * road_;
    QLabel * objective_;
    int  xIndex_;
    int  yIndex_;
    QPixmap  path_;
    Objective obj_;

public:
    Box(Case  myCase);
    /**
     * @brief constructeur Box qui instancie un carre du plateau
     * @param myCase
     * @param players
     */
    Box(Case  myCase, list<Player> players);
    /**
     * @brief getter de l attribut X.
     * @return le X trouver.
     */
    inline int getX() const;
    /**
     * @brief getter de l'attribut Y.
     * @return le Y trouver
     */
    inline int getY() const;
    /**
     * @brief setter de l'attribut X
     * @param valeur fournie de x a changé
     */
    inline void setX(int x);
    /**
     * @brief setter de l'attribut Y
     * @param valeur fournie de y a changé
     */
    inline void setY(int y);
    /**
     * @brief road chemin pour avoir le box
     * @return
     */
    inline QLabel * road() ;
    /**
     * @brief accede a l Objective ds le box
     * @return
     */
    inline Objective getObjective() const;

    /**
     * @brief objective du box
     * @return
     */
    inline QLabel * objective() const;
    /**
     * @brief playerBlue joueur bleu
     * @return un label
     */
    inline QLabel * playerBlue() const;
    /**
     * @brief playerGreen joueur vert
     * @return un label
     */
    inline QLabel * playerGreen() const;
    /**
     * @brief playerYellow joueur jaune
     * @return un label
     */
    inline QLabel * playerYellow() const;
    /**
     * @brief playerRed joueur rouge
     * @return un label
     */
    inline QLabel * playerRed() const;
    /**
     * @brief verifie les Objective
     * @param obj
     * @return
     */
    QPixmap checkObjective(Objective obj);
    /**
     * @brief mets a jour les Boxes
     * @param myCase
     * @param players
     */
    void updateBoxes(Case  myCase, list<Player> players);
    /**
     * @brief updateBox
     * @param myCase
     */
    void updateBox(Case myCase);

};

inline Box::getX() const
{
    return xIndex_;
}
inline Box::getY() const
{
    return yIndex_;
}

inline void Box::setX(int x)
{
    this->xIndex_ = x;
}
inline void Box::setY(int y)
{
    this->yIndex_ = y;
}

inline QLabel* Box::road()
{
    return road_;
}
inline QLabel * Box::objective() const
{
    return objective_;
}
inline Objective Box::getObjective() const
{
    return obj_;
}
inline QLabel * Box::playerBlue() const
{
    return playerBlue_;
}
inline QLabel * Box::playerGreen() const
{
    return playerGreen_;
}
inline QLabel * Box::playerYellow() const
{
    return playerYellow_;
}
inline QLabel * Box::playerRed() const
{
    return playerRed_;
}


#endif // BOX_H
