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
#include <QPixmap>
#include "board.h"
#include "window.h"
#include "model/color.h"
#include <QSpinBox>
#include <QPushButton>
#include "window.h"
#include "observer.h"
#include "subject.h"
Window::Window(Labyrinth * game) : game_(game)
{



    //this->setStyleSheet("background-image: url(:/images/Objective/Labyrinth.png)");
    QBoxLayout * BigVBox = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout * hBox = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout * vBox = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout * littleHBox = new QBoxLayout(QBoxLayout::LeftToRight);
    QWidget * backgroundBoard = new QWidget();
    QGridLayout * grid = new QGridLayout();

    backgroundBoard->setStyleSheet(" border: 20px solid black;");
    board_ = new Board(game_);
    grid->addWidget(backgroundBoard,0,0);
    grid->addLayout(board_,0,0);
    QBoxLayout * eachPlayerB = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout * eachPlayerG = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout * eachPlayerY = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout * eachPlayerR = new QBoxLayout(QBoxLayout::LeftToRight);
    QLabel * blue = new QLabel();
    QLabel * green = new QLabel();
    QLabel * yellow = new QLabel();
    QLabel * red = new QLabel();
    for (Player player : game_->getAllPlayers()) {

        switch (player.getColor()) {
        case Color::BLUE :
            blue ->setText("blue: ");
            objectiveBlue_ = new QLabel();
            objectiveBlue_->setPixmap(player.getImage(player.getObjective()));

            eachPlayerB->addWidget(blue);
            eachPlayerB->addWidget(objectiveBlue_);
            vBox->addLayout(eachPlayerB);
//

            break;
        case Color::GREEN :
            green ->setText("green: ");
            objectiveGreen_ = new QLabel();

            objectiveGreen_->setPixmap(player.getImage(player.getObjective()));
            eachPlayerG->addWidget(green);
            eachPlayerG->addWidget(objectiveGreen_);
            vBox->addLayout(eachPlayerG);
//
            break;
        case Color::YELLOW :
            yellow->setText("yellow: ");
            objectiveYellow_ = new QLabel();
            objectiveYellow_->setPixmap(player.getImage(player.getObjective()));
            eachPlayerY->addWidget(yellow);
            eachPlayerY->addWidget(objectiveYellow_);
            vBox->addLayout(eachPlayerY);
//
            break;
        case Color::RED :
            red->setText("red: ");
            objectiveRed_ = new QLabel();
            objectiveRed_->setPixmap(player.getImage(player.getObjective()));
            eachPlayerR->addWidget(red);
            eachPlayerR->addWidget(objectiveRed_);
            vBox->addLayout(eachPlayerR);
//        defaut:
            ;
        }


   }


    this->setLayout(BigVBox);
    hBox->addLayout(vBox);
    QBoxLayout * remainBoxVBox = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout * remainBoxVBoxTwo = new QBoxLayout(QBoxLayout::TopToBottom);
    QBoxLayout * remainBoxHBox = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout * currentPlayerBox = new QBoxLayout(QBoxLayout::LeftToRight);
    QLabel * remainBoxLabel = new QLabel("The current case : ");
    remainBox_ = new Box(game_->getPlate().getRemainCase());
    rotateButton_ = new QPushButton("rotate remain box");
    remainBoxHBox->addWidget(remainBoxLabel);
    remainBoxHBox->addLayout(remainBox_);
    hBox->addLayout(remainBoxVBox);
    remainBoxVBox->addLayout(remainBoxVBoxTwo);
    remainBoxVBoxTwo->addLayout(remainBoxHBox);
    remainBoxVBoxTwo->addWidget(rotateButton_);
    remainBoxVBox->addLayout(currentPlayerBox);

    QLabel * currentPlayerLabel = new QLabel("The current player : ");
    currentPlayer_ = new QLabel();
    switch (game->getCurrentPlayer().getColor()) {
    case Color::BLUE :
       currentPlayer_->setPixmap(QPixmap(":/images/PlayerBlue.png"));
        break;
    case Color::GREEN :
      currentPlayer_->setPixmap(QPixmap(":/images/PlayerGreen.png"));
        break;
    case Color::YELLOW :
        currentPlayer_->setPixmap(QPixmap(":/images/PlayerYellow.png"));
        break;
    case Color::RED :
        currentPlayer_->setPixmap(QPixmap(":/images/PlayerRed.png"));
    default:
        ;
    }
    currentPlayerBox->addWidget(currentPlayerLabel);
    currentPlayerBox->addWidget(currentPlayer_);


    hBox->addLayout(grid);
    BigVBox->addLayout(hBox);
    BigVBox->addLayout(littleHBox);



    // Informations of play
    QLabel * infoCase = new QLabel("Where do Wanna Place the box ?");
    xCase_ = new QSpinBox();
    xCase_->setRange(0,6);
    yCase_ = new QSpinBox();
    yCase_ ->setRange(0,6);
    place_ = new QPushButton("Place !");
    QLabel * infoPos = new QLabel("Where do Wanna go ?");
    xPosition_ = new QSpinBox();
    xPosition_->setRange(0,6);
    yPosition_ = new QSpinBox();
    yPosition_->setRange(0,6);
    go_ = new QPushButton("Go !");
    littleHBox->addWidget(infoCase);
    littleHBox->addWidget(xCase_);
    littleHBox->addWidget(yCase_);
    littleHBox->addWidget(place_);
    littleHBox->addWidget(infoPos);
    littleHBox->addWidget(xPosition_);
    littleHBox->addWidget(yPosition_);
    littleHBox->addWidget(go_);
    connect(place_,&QPushButton::clicked,this,&Window::placeCase);
    connect(go_,&QPushButton::clicked,this,&Window::go);
    connect(rotateButton_,&QPushButton::clicked,this,&Window::rotateCase);
    game_->registerObserver(this);

    go_->setEnabled(false);
}



void Window::update(const nvs::Subject * subject)
{
    remainBox_->updateBox(((*game_).getPlate().getRemainCase()));
    board_->update();

    for (Player player : game_->getAllPlayers()) {

        switch (player.getColor()) {
        case Color::BLUE :
            if (player.getStock().empty()) {
                objectiveBlue_->setPixmap(QPixmap(":/images/Void.png"));
                QMessageBox endGame;
                endGame.setText(" THE GAME IS OVER ! ");
                QString * info = new QString(" CONGRATULATION PLAYER ");
                info->append("BLUE !!!");
                endGame.setInformativeText(*info);
                int ret = endGame.exec();
                this->setEnabled(false);
            }
            else
            {
                objectiveBlue_->setPixmap(player.getImage(player.getObjective()));
                currentPlayer_->setPixmap(QPixmap(":/images/PlayerBlue.png"));
            }



            break;
        case Color::GREEN :
            if (player.getStock().empty()) {
                objectiveBlue_->setPixmap(QPixmap(":/images/Void.png"));
                QMessageBox endGame;
                endGame.setText(" THE GAME IS OVER ! ");
                QString * info = new QString(" CONGRATULATION PLAYER ");
                info->append("GREEN !!!");
                endGame.setInformativeText(*info);
                int ret = endGame.exec();
                this->setEnabled(false);
            }
            else
            {
                objectiveGreen_->setPixmap(player.getImage(player.getObjective()));
                currentPlayer_->setPixmap(QPixmap(":/images/PlayerGreen.png"));
            }

            break;
        case Color::YELLOW :
                if (player.getStock().empty()) {
                    objectiveBlue_->setPixmap(QPixmap(":/images/Void.png"));
                    QMessageBox endGame;
                    endGame.setText(" THE GAME IS OVER ! ");
                    QString * info = new QString(" CONGRATULATION PLAYER ");
                    info->append("YELLOW !!!");
                    endGame.setInformativeText(*info);
                    int ret = endGame.exec();
                    this->setEnabled(false);
                }
                else
                {
                    objectiveYellow_->setPixmap(player.getImage(player.getObjective()));
                    currentPlayer_->setPixmap(QPixmap(":/images/PlayerYellow.png"));
                }

            break;
        case Color::RED :
                if (player.getStock().empty()) {
                    objectiveBlue_->setPixmap(QPixmap(":/images/Void.png"));
                    QMessageBox endGame;
                    endGame.setText(" THE GAME IS OVER ! ");
                    QString * info = new QString(" CONGRATULATION PLAYER ");
                    info->append("RED !!!");
                    endGame.setInformativeText(*info);
                    int ret = endGame.exec();
                    this->setEnabled(false);
                }
                else
                {
                    objectiveRed_->setPixmap(player.getImage(player.getObjective()));
                    currentPlayer_->setPixmap(QPixmap(":/images/PlayerRed.png"));
                }
            break;
        default:
            ;

           }

   }
    switch (game_->getCurrentPlayer().getColor()) {
    case Color::BLUE :
        currentPlayer_->setPixmap(QPixmap(":/images/PlayerBlue.png"));

        break;
    case Color::GREEN :
        //playerName->set
        currentPlayer_->setPixmap(QPixmap(":/images/PlayerGreen.png"));
        break;
    case Color::YELLOW :
        currentPlayer_->setPixmap(QPixmap(":/images/PlayerYellow.png"));
        break;
    case Color::RED :
        currentPlayer_->setPixmap(QPixmap(":/images/PlayerRed.png"));

    }



}
void Window::placeCase()
{
    if(((xCase_->value())%2==0 && (yCase_->value())%2==0) || ((xCase_->value())%2!=0 && (yCase_->value())%2!=0)){
        QMessageBox wrongPos;
        wrongPos.setText("You can't place here ! ");
        wrongPos.setInformativeText("Try an other pos");
        int ret = wrongPos.exec();
    }else{
        game_->placeNewCase(Position(xCase_->value(),yCase_->value()));
        place_->setEnabled(false);
        go_->setEnabled(true);
    }

}
void Window::go()
{

    vector<vector<int> > tab;
    for (int i = 0; i < 7; i++) {
       tab.push_back(vector<int>(7,0));
    }
    if (game_->getPlate().moveIsValid(tab,game_->getCurrentPlayer().getPosition(),Position(xPosition_->value(),yPosition_->value()))) {

        switch (game_->getCurrentPlayer().getColor()) {
        case Color::BLUE:
            ((Box*)board_->itemAtPosition(game_->getCurrentPlayer().getPosition().getX(),game_->getCurrentPlayer().getPosition().getY()))->playerBlue()->setPixmap(QPixmap(":/images/Void.png"));
            break;
        case Color::GREEN:
            ((Box*)board_->itemAtPosition(game_->getCurrentPlayer().getPosition().getX(),game_->getCurrentPlayer().getPosition().getY()))->playerGreen()->setPixmap(QPixmap(":/images/Void.png"));
            break;
        case Color::YELLOW:
            ((Box*)board_->itemAtPosition(game_->getCurrentPlayer().getPosition().getX(),game_->getCurrentPlayer().getPosition().getY()))->playerYellow()->setPixmap(QPixmap(":/images/Void.png"));
            break;
        case Color::RED:
            ((Box*)board_->itemAtPosition(game_->getCurrentPlayer().getPosition().getX(),game_->getCurrentPlayer().getPosition().getY()))->playerRed()->setPixmap(QPixmap(":/images/Void.png"));
            break;
        default:
            break;
        }
        game_->move(Position(xPosition_->value(),yPosition_->value()));
        game_->nextPlayer();
    }else {
       QMessageBox warning;
       warning.setText("You can't go there ! ");
       warning.setInformativeText("Try  an other path");
       int ret = warning.exec();
    }
    place_->setEnabled(true);
    go_->setEnabled(false);

}

void Window::rotateCase()
{
    game_->rotateRemainCase();
}
