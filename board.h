#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include <model/labyrinth.h>
#include "box.h"
#include "model/position.h"

class Board : public QGridLayout
{
public:
    Board(Labyrinth * game);
    void update();
private:
    Labyrinth * game_;
};

#endif // BOARD_H
