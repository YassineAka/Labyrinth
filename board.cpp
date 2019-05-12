#include "board.h"
#include "box.h"
#include "model/labyrinth.h"

Board::Board(Labyrinth *laby) : game_(laby)
{
    for (int x = 0; x < 7; ++x) {
        for (int y = 0; y <  7; ++y) {

            Position boxPosition = Position(x,y);
            Box * box = new Box(((Case)game_->getPlate().getPlate()->at(x).at(y)), game_->getPlayersAt(boxPosition));

            this->addLayout(box,x,y);
        }
    }
}

void Board::update()
{
    for (int x = 0; x < 7; ++x) {
        for (int y = 0; y <  7; ++y) {
            Position  boxPosition(x,y);
            Plate plate = game_->getPlate();
            vector<vector<Case>>* cases = plate.getPlate();
            vector<vector<Case>> casess = *cases;
            ((Box*)(this->itemAtPosition(x,y)))->updateBoxes(((vector<Case>)casess.at(x)).at(y),game_->getPlayersAt(boxPosition));

        }
    }
}


