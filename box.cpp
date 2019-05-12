#include "box.h"
#include "model/case.h"
#include "model/caset.h"
#include "model/casei.h"
#include "model/casel.h"
#include <vector>
#include "model/player.h"
#include <iterator>
#include <QPixmap>


Box::Box(Case myCase)
{

    road_ = new QLabel();

    playerBlue_ = NULL;
    playerGreen_= NULL;
    playerYellow_= NULL;
    playerRed_= NULL;

    if (myCase.isI()) {
        if ((myCase.getUp()== true) && (myCase.getDown()== true))  {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/HautBas.png"));
        } else {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/GaucheDroite.png"));
        }
    }else if(myCase.isL()){
        if ((myCase.getUp()== true) && (myCase.getRight()== true))  {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/DroiteHaut.png"));
        } else if((myCase.getDown()== true) && (myCase.getRight()== true)){
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/DroiteBas.png"));
        }else if((myCase.getDown()== true) && (myCase.getLeft()== true)) {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/GaucheBas.png"));
        }else if((myCase.getUp()== true) && (myCase.getLeft()== true)) {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/GaucheHaut.png"));
        }
    }else{
        if ((myCase.getUp() == false && myCase.getDown() == true && myCase.getRight() == true && myCase.getLeft() == true))  {
            //road_ = new QLabel();
             road_->setPixmap(QPixmap(":/images/GaucheDroiteBas.png"));
        } else if((myCase.getUp() == true && myCase.getDown() == true && myCase.getRight() == false && myCase.getLeft() == true)){
           //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/GaucheHautBas.png"));
        }else if((myCase.getUp() == true && myCase.getDown() == false && myCase.getRight() == true && myCase.getLeft() == true)) {
           //road_ = new QLabel();
           road_->setPixmap(QPixmap(":/images/GaucherDroiteHaut.png"));
        }else if((myCase.getUp() == true && myCase.getDown() == true && myCase.getRight() == true && myCase.getLeft() == false )) {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/DroiteHautBas.png"));
        }
    }


        switch (myCase.getObjective()) {
        case Objective::GHOST:
            objective_ = new QLabel();
            obj_ = Objective::GHOST;
            objective_->setPixmap(QPixmap(":/images/Objective/Ghost.png"));
            break;
        case Objective::GNOME:
            objective_ = new QLabel();
            obj_ = Objective::GNOME;
             objective_->setPixmap(QPixmap(":/images/Objective/Gnome.png"));
            break;
        case Objective::DRAGON:
            objective_ = new QLabel();
            obj_ = Objective::DRAGON;
             objective_->setPixmap(QPixmap(":/images/Objective/Dragon.png"));
            break;
        case Objective::FAIRY:
            objective_ = new QLabel();
            obj_ = Objective::FAIRY;
            objective_->setPixmap(QPixmap(":/images/Objective/Fairy.png"));
            break;
        case Objective::GENIUS:
            objective_ = new QLabel();
            obj_ = Objective::GENIUS;
            objective_->setPixmap(QPixmap(":/images/Objective/Genius.png"));
            break;
        case Objective::BAT:
            objective_ = new QLabel();
            obj_ = Objective::BAT;
            objective_->setPixmap(QPixmap(":/images/Objective/Bat.png"));
            break;
        case Objective::BEETLE:
            objective_ = new QLabel();
            obj_ = Objective::BEETLE;
            objective_->setPixmap(QPixmap(":/images/Objective/Beetle.png"));
            break;
        case Objective::OWLS:
            objective_ = new QLabel();
            obj_ = Objective::OWLS;
            objective_->setPixmap(QPixmap(":/images/Objective/Owls.png"));
            break;
        case Objective::RAT:
            objective_ = new QLabel();
            obj_ = Objective::RAT;
            objective_->setPixmap(QPixmap(":/images/Objective/Rat.png"));
            break;
        case Objective::SPIDER:
            objective_ = new QLabel();
            obj_ = Objective::SPIDER;
            objective_->setPixmap(QPixmap(":/images/Objective/Spider.png"));
            break;
        case Objective::BUTTERFLY:
            objective_ = new QLabel();
            obj_ = Objective::BUTTERFLY;
            objective_->setPixmap(QPixmap(":/images/Objective/Butterfly.png"));
            break;
        case Objective::LIZARD:
            objective_ = new QLabel();
            obj_ = Objective::LIZARD;
            objective_->setPixmap(QPixmap(":/images/Objective/Lizard.png"));
            break;
        case Objective::GRIMOIRE:
            objective_ = new QLabel();
            obj_ = Objective::GRIMOIRE;
            objective_->setPixmap(QPixmap(":/images/Objective/Grimoire.png"));
            break;
        case Objective::GOLD_PURSE:
            objective_ = new QLabel();
            obj_ = Objective::GOLD_PURSE;
            objective_->setPixmap(QPixmap(":/images/Objective/Gold_Purse.png"));
            break;
        case Objective::MAP:
            objective_ = new QLabel();
            obj_ = Objective::MAP;
            objective_->setPixmap(QPixmap(":/images/Objective/Map.png"));
            break;
        case Objective::CROWN:
            objective_ = new QLabel();
            obj_ = Objective::CROWN;
            objective_->setPixmap(QPixmap(":/images/Objective/Crown.png"));
            break;
        case Objective::KEYS:
            objective_ = new QLabel();
            obj_ = Objective::KEYS;
            objective_->setPixmap(QPixmap(":/images/Objective/Keys.png"));
            break;
        case Objective::BONES:
            objective_ = new QLabel();
            obj_ = Objective::BONES;
            objective_->setPixmap(QPixmap(":/images/Objective/Bones.png"));
            break;
        case Objective::RING:
            objective_ = new QLabel();
            obj_ = Objective::RING;
            objective_->setPixmap(QPixmap(":/images/Objective/Ring.png"));
            break;
        case Objective::EMERALD:
            objective_ = new QLabel();
            obj_ = Objective::EMERALD;
            objective_->setPixmap(QPixmap(":/images/Objective/Emerald.png"));
            break;
        case Objective::TREASURE_CHEST:
            objective_ = new QLabel();
            obj_ = Objective::TREASURE_CHEST;
            objective_->setPixmap(QPixmap(":/images/Objective/Treasure.png"));
            break;
        case Objective::SWORD:
            objective_ = new QLabel();
            obj_ = Objective::SWORD;
            objective_->setPixmap(QPixmap(":/images/Objective/Sword.png"));
            break;
        case Objective::CUNDLESTICK:
            objective_ = new QLabel();
            obj_ = Objective::CUNDLESTICK;
            objective_->setPixmap(QPixmap(":/images/Objective/Cundlestick.png"));
            break;
        case Objective::HELM:
            objective_ = new QLabel();
            obj_ = Objective::HELM;
            objective_->setPixmap(QPixmap(":/images/Objective/Helm.png"));
            break;
        case Objective::WIZZARDY:
            objective_ = new QLabel();
            obj_ = Objective::WIZZARDY;
            objective_->setPixmap(QPixmap(":/images/Objective/Wizzardry.png"));
            break;
        case Objective::NONE:
            objective_ = new QLabel();
            obj_ = Objective::NONE;
            objective_->setPixmap(QPixmap(":/images/Void.png"));
            break;
        default:
            ;//objective_= NULL;

        }

    this->addWidget(road_,0,0);


        if (objective_ != NULL) {
            if (myCase.getObjective() == Objective::MAP) {
                this->addWidget(objective_,0,0,Qt::AlignRight);
            }else{
                this->addWidget(objective_,0,0,Qt::AlignCenter);
            }

        }
        if (playerBlue_ != NULL) {
           this->addWidget(playerBlue_,0,0);
        }
        if (playerGreen_ != NULL) {
           this->addWidget(playerGreen_,0,0);
        }
        if (playerYellow_ != NULL) {
           this->addWidget(playerYellow_,0,0);
        }
        if (playerRed_ != NULL) {
           this->addWidget(playerRed_,0,0);
        }



}

Box::Box(Case myCase, list<Player> players)
{
    road_ = new QLabel();
    playerBlue_ =  new QLabel() ;
    playerGreen_=  new QLabel();
    playerYellow_=  new QLabel();
    playerRed_=  new QLabel();

    if (myCase.isI()) {
        if ((myCase.getUp()== true) && (myCase.getDown()== true))  {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/HautBas.png"));
        } else {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/GaucheDroite.png"));
        }
    }else if(myCase.isL()){
        if ((myCase.getUp()== true) && (myCase.getRight()== true))  {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/DroiteHaut.png"));
        } else if((myCase.getDown()== true) && (myCase.getRight()== true)){
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/DroiteBas.png"));
        }else if((myCase.getDown()== true) && (myCase.getLeft()== true)) {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/GaucheBas.png"));
        }else if((myCase.getUp()== true) && (myCase.getLeft()== true)) {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/GaucheHaut.png"));
        }
    }else{
        if ((myCase.getUp() == false && myCase.getDown() == true && myCase.getRight() == true && myCase.getLeft() == true))  {
            //road_ = new QLabel();
             road_->setPixmap(QPixmap(":/images/GaucheDroiteBas.png"));
        } else if((myCase.getUp() == true && myCase.getDown() == true && myCase.getRight() == false && myCase.getLeft() == true)){
           //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/GaucheHautBas.png"));
        }else if((myCase.getUp() == true && myCase.getDown() == false && myCase.getRight() == true && myCase.getLeft() == true)) {
           //road_ = new QLabel();
           road_->setPixmap(QPixmap(":/images/GaucherDroiteHaut.png"));
        }else if((myCase.getUp() == true && myCase.getDown() == true && myCase.getRight() == true && myCase.getLeft() == false )) {
            //road_ = new QLabel();
            road_->setPixmap(QPixmap(":/images/DroiteHautBas.png"));
        }
    }

        for (std::list<Player>::iterator it = players.begin(); it != players.end(); ++it) {
            switch (it->getColor()) {
            case Color::BLUE :
                 playerBlue_->setPixmap(QPixmap(":/images/PlayerBlue.png"));
                break;
            case Color::GREEN :
               playerGreen_->setPixmap(QPixmap(":/images/PlayerGreen.png"));
                break;
            case Color::YELLOW :
                 playerYellow_->setPixmap(QPixmap(":/images/PlayerYellow.png"));
                break;
            case Color::RED :
               playerRed_->setPixmap(QPixmap(":/images/PlayerRed.png"));
                break;
            default:
                break;
            }
        }


        switch (myCase.getObjective()) {
        case Objective::GHOST:
            objective_ = new QLabel();
            obj_ = Objective::GHOST;
            objective_->setPixmap(QPixmap(":/images/Objective/Ghost.png"));
            break;
        case Objective::GNOME:
            objective_ = new QLabel();
            obj_ = Objective::GNOME;
             objective_->setPixmap(QPixmap(":/images/Objective/Gnome.png"));
            break;
        case Objective::DRAGON:
            objective_ = new QLabel();
            obj_ = Objective::DRAGON;
             objective_->setPixmap(QPixmap(":/images/Objective/Dragon.png"));
            break;
        case Objective::FAIRY:
            objective_ = new QLabel();
            obj_ = Objective::FAIRY;
            objective_->setPixmap(QPixmap(":/images/Objective/Fairy.png"));
            break;
        case Objective::GENIUS:
            objective_ = new QLabel();
            obj_ = Objective::GENIUS;
            objective_->setPixmap(QPixmap(":/images/Objective/Genius.png"));
            break;
        case Objective::BAT:
            objective_ = new QLabel();
            obj_ = Objective::BAT;
            objective_->setPixmap(QPixmap(":/images/Objective/Bat.png"));
            break;
        case Objective::BEETLE:
            objective_ = new QLabel();
            obj_ = Objective::BEETLE;
            objective_->setPixmap(QPixmap(":/images/Objective/Beetle.png"));
            break;
        case Objective::OWLS:
            objective_ = new QLabel();
            obj_ = Objective::OWLS;
            objective_->setPixmap(QPixmap(":/images/Objective/Owls.png"));
            break;
        case Objective::RAT:
            objective_ = new QLabel();
            obj_ = Objective::RAT;
            objective_->setPixmap(QPixmap(":/images/Objective/Rat.png"));
            break;
        case Objective::SPIDER:
            objective_ = new QLabel();
            obj_ = Objective::SPIDER;
            objective_->setPixmap(QPixmap(":/images/Objective/Spider.png"));
            break;
        case Objective::BUTTERFLY:
            objective_ = new QLabel();
            obj_ = Objective::BUTTERFLY;
            objective_->setPixmap(QPixmap(":/images/Objective/Butterfly.png"));
            break;
        case Objective::LIZARD:
            objective_ = new QLabel();
            obj_ = Objective::LIZARD;
            objective_->setPixmap(QPixmap(":/images/Objective/Lizard.png"));
            break;
        case Objective::GRIMOIRE:
            objective_ = new QLabel();
            obj_ = Objective::GRIMOIRE;
            objective_->setPixmap(QPixmap(":/images/Objective/Grimoire.png"));
            break;
        case Objective::GOLD_PURSE:
            objective_ = new QLabel();
            obj_ = Objective::GOLD_PURSE;
            objective_->setPixmap(QPixmap(":/images/Objective/Gold_Purse.png"));
            break;
        case Objective::MAP:
            objective_ = new QLabel();
            obj_ = Objective::MAP;
            objective_->setPixmap(QPixmap(":/images/Objective/Map.png"));
            break;
        case Objective::CROWN:
            objective_ = new QLabel();
            obj_ = Objective::CROWN;
            objective_->setPixmap(QPixmap(":/images/Objective/Crown.png"));
            break;
        case Objective::KEYS:
            objective_ = new QLabel();
            obj_ = Objective::KEYS;
            objective_->setPixmap(QPixmap(":/images/Objective/Keys.png"));
            break;
        case Objective::BONES:
            objective_ = new QLabel();
            obj_ = Objective::BONES;
            objective_->setPixmap(QPixmap(":/images/Objective/Bones.png"));
            break;
        case Objective::RING:
            objective_ = new QLabel();
            obj_ = Objective::RING;
            objective_->setPixmap(QPixmap(":/images/Objective/Ring.png"));
            break;
        case Objective::EMERALD:
            objective_ = new QLabel();
            obj_ = Objective::EMERALD;
            objective_->setPixmap(QPixmap(":/images/Objective/Emerald.png"));
            break;
        case Objective::TREASURE_CHEST:
            objective_ = new QLabel();
            obj_ = Objective::TREASURE_CHEST;
            objective_->setPixmap(QPixmap(":/images/Objective/Treasure.png"));
            break;
        case Objective::SWORD:
            objective_ = new QLabel();
            obj_ = Objective::SWORD;
            objective_->setPixmap(QPixmap(":/images/Objective/Sword.png"));
            break;
        case Objective::CUNDLESTICK:
            objective_ = new QLabel();
            obj_ = Objective::CUNDLESTICK;
            objective_->setPixmap(QPixmap(":/images/Objective/Cundlestick.png"));
            break;
        case Objective::HELM:
            objective_ = new QLabel();
            obj_ = Objective::HELM;
            objective_->setPixmap(QPixmap(":/images/Objective/Helm.png"));
            break;
        case Objective::WIZZARDY:
            objective_ = new QLabel();
            obj_ = Objective::WIZZARDY;
            objective_->setPixmap(QPixmap(":/images/Objective/Wizzardry.png"));
            break;
        case Objective::NONE:
        objective_ = new QLabel();
        obj_ = Objective::NONE;
        objective_->setPixmap(QPixmap(":/images/Void.png"));
        break;
        default:
            ;
        }

    this->addWidget(road_,0,0);
    this->addWidget(objective_,0,0);






        if (playerBlue_ != NULL) {
           this->addWidget(playerBlue_,0,0);
        }
        if (playerGreen_ != NULL) {
           this->addWidget(playerGreen_,0,0);
        }
        if (playerYellow_ != NULL) {
           this->addWidget(playerYellow_,0,0);
        }
        if (playerRed_ != NULL) {
           this->addWidget(playerRed_,0,0);
        }
        //objective_->show();



}

void Box::updateBoxes(Case  myCase, list<Player> players)
{

    if (myCase.isI()) {
        if ((myCase.getUp()== true) && (myCase.getDown()== true))  {
            road_->setPixmap(QPixmap(":/images/HautBas.png"));
        } else {
            road_->setPixmap(QPixmap(":/images/GaucheDroite.png"));
        }
    }else if(myCase.isL()){
        if ((myCase.getUp()== true) && (myCase.getRight()== true))  {
            road_->setPixmap(QPixmap(":/images/DroiteHaut.png"));
        } else if((myCase.getDown()== true) && (myCase.getRight()== true)){
            road_->setPixmap(QPixmap(":/images/DroiteBas.png"));
        }else if((myCase.getDown()== true) && (myCase.getLeft()== true)) {
            road_->setPixmap(QPixmap(":/images/GaucheBas.png"));
        }else if((myCase.getUp()== true) && (myCase.getLeft()== true)) {
            road_->setPixmap(QPixmap(":/images/GaucheHaut.png"));
        }
    }else{
        if ((myCase.getUp() == false && myCase.getDown() == true && myCase.getRight() == true && myCase.getLeft() == true))  {
             road_->setPixmap(QPixmap(":/images/GaucheDroiteBas.png"));
        } else if((myCase.getUp() == true && myCase.getDown() == true && myCase.getRight() == false && myCase.getLeft() == true)){
            road_->setPixmap(QPixmap(":/images/GaucheHautBas.png"));
        }else if((myCase.getUp() == true && myCase.getDown() == false && myCase.getRight() == true && myCase.getLeft() == true)) {
           road_->setPixmap(QPixmap(":/images/GaucherDroiteHaut.png"));
        }else if((myCase.getUp() == true && myCase.getDown() == true && myCase.getRight() == true && myCase.getLeft() == false )) {
            road_->setPixmap(QPixmap(":/images/DroiteHautBas.png"));
        }
    }


//    for (std::list<Player>::iterator it = players.begin(); it != players.end(); ++it) {
//        switch (it->getColor()) {
//        case Color::BLUE :
//             playerBlue_->setPixmap(QPixmap(":/images/PlayerBlue.png"));
//            break;
//        case Color::GREEN :
//           playerGreen_->setPixmap(QPixmap(":/images/PlayerGreen.png"));
//            break;
//        case Color::YELLOW :
//             playerYellow_->setPixmap(QPixmap(":/images/PlayerYellow.png"));
//            break;
//        case Color::RED :
//           playerRed_->setPixmap(QPixmap(":/images/PlayerRed.png"));
//            break;
//        default:
//            break;
//        }
//    }
    for (Player pl : players) {
        switch (pl.getColor()) {
        case Color::BLUE :
             playerBlue_->setPixmap(QPixmap(":/images/PlayerBlue.png"));
            break;
        case Color::GREEN :
           playerGreen_->setPixmap(QPixmap(":/images/PlayerGreen.png"));
            break;
        case Color::YELLOW :
             playerYellow_->setPixmap(QPixmap(":/images/PlayerYellow.png"));
            break;
        case Color::RED :
           playerRed_->setPixmap(QPixmap(":/images/PlayerRed.png"));
            break;
        default:
            break;
        }
    }


    switch (myCase.getObjective()) {
    case Objective::GHOST:
        objective_->setPixmap(QPixmap(":/images/Objective/Ghost.png"));
        break;
    case Objective::GNOME:
         objective_->setPixmap(QPixmap(":/images/Objective/Gnome.png"));
        break;
    case Objective::DRAGON:
         objective_->setPixmap(QPixmap(":/images/Objective/Dragon.png"));
        break;
    case Objective::FAIRY:
        objective_->setPixmap(QPixmap(":/images/Objective/Fairy.png"));
        break;
    case Objective::GENIUS:

        objective_->setPixmap(QPixmap(":/images/Objective/Genius.png"));
        break;
    case Objective::BAT:

        objective_->setPixmap(QPixmap(":/images/Objective/Bat.png"));
        break;
    case Objective::BEETLE:

        objective_->setPixmap(QPixmap(":/images/Objective/Beetle.png"));
        break;
    case Objective::OWLS:

        objective_->setPixmap(QPixmap(":/images/Objective/Owls.png"));
        break;
    case Objective::RAT:

        objective_->setPixmap(QPixmap(":/images/Objective/Rat.png"));
        break;
    case Objective::SPIDER:
        objective_ = new QLabel();
        objective_->setPixmap(QPixmap(":/images/Objective/Spider.png"));
        break;
    case Objective::BUTTERFLY:
        objective_->setPixmap(QPixmap(":/images/Objective/Butterfly.png"));
        break;
    case Objective::LIZARD:
        objective_->setPixmap(QPixmap(":/images/Objective/Lizard.png"));
        break;
    case Objective::GRIMOIRE:
        objective_->setPixmap(QPixmap(":/images/Objective/Grimoire.png"));
        break;
    case Objective::GOLD_PURSE:
        objective_->setPixmap(QPixmap(":/images/Objective/Gold_Purse.png"));
        break;
    case Objective::MAP:
        objective_->setPixmap(QPixmap(":/images/Objective/Map.png"));
        break;
    case Objective::CROWN:
        objective_->setPixmap(QPixmap(":/images/Objective/Crown.png"));
        break;
    case Objective::KEYS:
        objective_->setPixmap(QPixmap(":/images/Objective/Keys.png"));
        break;
    case Objective::BONES:
        objective_->setPixmap(QPixmap(":/images/Objective/Bones.png"));
        break;
    case Objective::RING:
        objective_->setPixmap(QPixmap(":/images/Objective/Ring.png"));
        break;
    case Objective::EMERALD:
        objective_->setPixmap(QPixmap(":/images/Objective/Emerald.png"));
        break;
    case Objective::TREASURE_CHEST:
        objective_->setPixmap(QPixmap(":/images/Objective/Treasure.png"));
        break;
    case Objective::SWORD:
        objective_->setPixmap(QPixmap(":/images/Objective/Sword.png"));
        break;
    case Objective::CUNDLESTICK:
        objective_->setPixmap(QPixmap(":/images/Objective/Cundlestick.png"));
        break;
    case Objective::HELM:
        objective_->setPixmap(QPixmap(":/images/Objective/Helm.png"));
        break;
    case Objective::WIZZARDY:
        objective_->setPixmap(QPixmap(":/images/Objective/Wizzardry.png"));
        break;
    case Objective::NONE:
        objective_->setPixmap(QPixmap(":/images/Void.png"));
        break;
    default:
        ;
    }

}

void Box::updateBox(Case  myCase)
{


    if (myCase.isI()) {
        if ((myCase.getUp()== true) && (myCase.getDown()== true))  {
            road_->setPixmap(QPixmap(":/images/HautBas.png"));
        } else {
            road_->setPixmap(QPixmap(":/images/GaucheDroite.png"));
        }
    }else if(myCase.isL()){
        if ((myCase.getUp()== true) && (myCase.getRight()== true))  {
            road_->setPixmap(QPixmap(":/images/DroiteHaut.png"));
        } else if((myCase.getDown()== true) && (myCase.getRight()== true)){
            road_->setPixmap(QPixmap(":/images/DroiteBas.png"));
        }else if((myCase.getDown()== true) && (myCase.getLeft()== true)) {
            road_->setPixmap(QPixmap(":/images/GaucheBas.png"));
        }else if((myCase.getUp()== true) && (myCase.getLeft()== true)) {
            road_->setPixmap(QPixmap(":/images/GaucheHaut.png"));
        }
    }else{
        if ((myCase.getUp() == false && myCase.getDown() == true && myCase.getRight() == true && myCase.getLeft() == true))  {
             road_->setPixmap(QPixmap(":/images/GaucheDroiteBas.png"));
        } else if((myCase.getUp() == true && myCase.getDown() == true && myCase.getRight() == false && myCase.getLeft() == true)){
            road_->setPixmap(QPixmap(":/images/GaucheHautBas.png"));
        }else if((myCase.getUp() == true && myCase.getDown() == false && myCase.getRight() == true && myCase.getLeft() == true)) {
           road_->setPixmap(QPixmap(":/images/GaucherDroiteHaut.png"));
        }else if((myCase.getUp() == true && myCase.getDown() == true && myCase.getRight() == true && myCase.getLeft() == false )) {
            road_->setPixmap(QPixmap(":/images/DroiteHautBas.png"));
        }

    }



    switch (myCase.getObjective()) {

    case Objective::GHOST:
        objective_->setPixmap(QPixmap(":/images/Objective/Ghost.png"));
        break;
    case Objective::GNOME:
         objective_->setPixmap(QPixmap(":/images/Objective/Gnome.png"));
        break;
    case Objective::DRAGON:
         objective_->setPixmap(QPixmap(":/images/Objective/Dragon.png"));
        break;
    case Objective::FAIRY:
        objective_->setPixmap(QPixmap(":/images/Objective/Fairy.png"));
        break;
    case Objective::GENIUS:

        objective_->setPixmap(QPixmap(":/images/Objective/Genius.png"));
        break;
    case Objective::BAT:

        objective_->setPixmap(QPixmap(":/images/Objective/Bat.png"));
        break;
    case Objective::BEETLE:

        objective_->setPixmap(QPixmap(":/images/Objective/Beetle.png"));
        break;
    case Objective::OWLS:

        objective_->setPixmap(QPixmap(":/images/Objective/Owls.png"));
        break;
    case Objective::RAT:

        objective_->setPixmap(QPixmap(":/images/Objective/Rat.png"));
        break;
    case Objective::SPIDER:
        objective_ = new QLabel();
        objective_->setPixmap(QPixmap(":/images/Objective/Spider.png"));
        break;
    case Objective::BUTTERFLY:
        objective_->setPixmap(QPixmap(":/images/Objective/Butterfly.png"));
        break;
    case Objective::LIZARD:
        objective_->setPixmap(QPixmap(":/images/Objective/Lizard.png"));
        break;
    case Objective::GRIMOIRE:
        objective_->setPixmap(QPixmap(":/images/Objective/Grimoire.png"));
        break;
    case Objective::GOLD_PURSE:
        objective_->setPixmap(QPixmap(":/images/Objective/Gold_Purse.png"));
        break;
    case Objective::MAP:
        objective_->setPixmap(QPixmap(":/images/Objective/Map.png"));
        break;
    case Objective::CROWN:
        objective_->setPixmap(QPixmap(":/images/Objective/Crown.png"));
        break;
    case Objective::KEYS:
        objective_->setPixmap(QPixmap(":/images/Objective/Keys.png"));
        break;
    case Objective::BONES:
        objective_->setPixmap(QPixmap(":/images/Objective/Bones.png"));
        break;
    case Objective::RING:
        objective_->setPixmap(QPixmap(":/images/Objective/Ring.png"));
        break;
    case Objective::EMERALD:
        objective_->setPixmap(QPixmap(":/images/Objective/Emerald.png"));
        break;
    case Objective::TREASURE_CHEST:
        objective_->setPixmap(QPixmap(":/images/Objective/Treasure.png"));
        break;
    case Objective::SWORD:
        objective_->setPixmap(QPixmap(":/images/Objective/Sword.png"));
        break;
    case Objective::CUNDLESTICK:
        objective_->setPixmap(QPixmap(":/images/Objective/Cundlestick.png"));
        break;
    case Objective::HELM:
        objective_->setPixmap(QPixmap(":/images/Objective/Helm.png"));
        break;
    case Objective::WIZZARDY:
        objective_->setPixmap(QPixmap(":/images/Objective/Wizzardry.png"));
        break;
    case Objective::NONE:
        objective_->setPixmap(QPixmap(":/images/Objective/Void.png"));
        break;
     default:

        ;

    }




}
