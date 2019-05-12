#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QWidget>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <observer.h>
#include <model/labyrinth.h>
#include "board.h"
#include "subject.h"
#include <list>
#include <QMessageBox>
#include "model/color.h"
#include "model/case.h"
#include "model/caset.h"
#include "model/casei.h"
#include "model/casel.h"
class Window : public QWidget, nvs::Observer
{
private:
    QSpinBox * xCase_;
    QSpinBox * yCase_;
    QSpinBox * xPosition_;
    QSpinBox * yPosition_;
    QPushButton * place_;
    QPushButton * go_;
    QPushButton * rotateButton_;
    Board * board_;
    Labyrinth  * game_;
    QWidget * taggerBox_;
    QLabel * playerName_;
    QLabel * objectiveBlue_;
    QLabel * objectiveGreen_;
    QLabel * objectiveYellow_;
    QLabel * objectiveRed_;
    Box * remainBox_;
    QLabel * currentPlayer_;
public:
    Window(Labyrinth  * game);
    inline QWidget* getWindow();
    inline QSpinBox* getYPosition();
    inline QSpinBox* getXPosition();
    inline QSpinBox* getXCase();
    inline QSpinBox* getYCase();
    inline QPushButton* getButtonGo();
    inline QPushButton* getButtonPlace();
    void update(const nvs::Subject * subject) override;
    void placeCase();
    void go();
    void rotateCase();

};

inline QSpinBox* Window::getYPosition()
{
    return yPosition_;
}
inline QSpinBox* Window::getXPosition()
{
    return xPosition_;
}inline QSpinBox* Window::getYCase()
{
    return yCase_;
}inline QSpinBox* Window::getXCase()
{
    return xCase_;
}inline QPushButton* Window::getButtonGo()
{
    return go_;
}inline QPushButton* Window::getButtonPlace()
{
    return place_;
}

#endif // CONTROLLER_H
