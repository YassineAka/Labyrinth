#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "labyrinth.h"
#include "view.h"

class Controller
{
public:
    Controller(View view ,Labyrinth labyrinth);
    void startGame();

private:
    View view_;
    Labyrinth labyrinth_;
};

#endif // CONTROLLER_H
