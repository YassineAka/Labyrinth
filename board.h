#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include <model/labyrinth.h>
#include "box.h"
#include "model/position.h"

class Board : public QGridLayout
{
public:
    /**
     * @brief constructeur Board
     * @param game
     */
    Board(Labyrinth * game);
    /**
     * @brief update mets a jour le board.
     */
    void update();
private:
    Labyrinth * game_;
};

#endif // BOARD_H
