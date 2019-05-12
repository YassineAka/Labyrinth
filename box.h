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
    Box(Case  myCase, list<Player> players);
    inline int getX() const;
    inline int getY() const;
    inline void setX(int x);
    inline void setY(int y);
    inline QLabel * road() ;
    inline Objective getObjective() const;
    inline QLabel * objective() const;
    inline QLabel * playerBlue() const;
    inline QLabel * playerGreen() const;
    inline QLabel * playerYellow() const;
    inline QLabel * playerRed() const;
    QPixmap checkObjective(Objective obj);
    void updateBoxes(Case  myCase, list<Player> players);
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
