#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include "model/player.h"
#include <vector>
#include <iostream>
#include "box.h"
#include "model/labyrinth.h"
#include "model/plate.h"
#include "model/case.h"
#include "model/casei.h"
#include "model/caset.h"
#include "model/casel.h"
#include "model/position.h"
#include <QLayout>
#include <QPushButton>
#include <iostream>
#include <QWidget>
#include <list>
#include <QPixmap>
#include "board.h"
#include "window.h"
#include "model/color.h"
#include <QSpinBox>
#include <QPushButton>
#include "window.h"

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Plate plate;
    Labyrinth * game = new Labyrinth(plate);
    Window * controller = new Window(game);
    controller->show();
    return a.exec();




}
