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
    /**
     * @brief constructeur du Window
     * @param game
     */
    Window(Labyrinth  * game);
    /**
     * @brief getWindow
     * @return
     */
    inline QWidget* getWindow();
    /**
     * @brief accede a la Position y
     * @return
     */
    inline QSpinBox* getYPosition();
    /**
     * @brief accede a la Position x
     * @return
     */
    inline QSpinBox* getXPosition();
    /**
     * @brief accede a la case x
     * @return
     */
    inline QSpinBox* getXCase();
    /**
     * @brief accede a la case y
     * @return
     */
    inline QSpinBox* getYCase();
    /**
     * @brief accede au Button pour jouer
     * @return
     */
    inline QPushButton* getButtonGo();
    /**
     * @brief accede au ButtonPlace
     * @return
     */
    inline QPushButton* getButtonPlace();
    /**
     * @brief mise a jour du jeu
     * @param subject
     */
    void update(const nvs::Subject * subject) override;
    /**
     * @brief placer une case ds le labyrinthe
     */
    void placeCase();
    /**
     * @brief methode pour lancer le mouvement choisis
     */
    void go();
    /**
     * @brief rotateCase
     */
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
