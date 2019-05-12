#include "player.h"



Player::Player(Color color ,Position pos, stack<Objective> stock, int index) :color_(color),pos_(pos),isFinish_(false),stock_(stock),index_(index)
{

}
bool Player::hasWon(){
    return isFinish_;
}
void Player::getNextObjective()
{
    this->getStock().pop();
    if (stock_.empty()) {
        isFinish_ = true;
    }
}
void Player::move(Position pos){
    pos_.setX(pos.getX());
    pos_.setY(pos.getY());

}

QPixmap Player::getImage(Objective obj){
    switch (obj) {
    case Objective::GHOST:
        return (QPixmap(":/images/Objective/Ghost.png"));

    case Objective::GNOME:
        return(QPixmap(":/images/Objective/Gnome.png"));

    case Objective::DRAGON:
        return(QPixmap(":/images/Objective/Dragon.png"));

    case Objective::FAIRY:
       return(QPixmap(":/images/Objective/Fairy.png"));

    case Objective::GENIUS:
        return(QPixmap(":/images/Objective/Genius.png"));

    case Objective::BAT:
        return(QPixmap(":/images/Objective/Bat.png"));

    case Objective::BEETLE:
        return(QPixmap(":/images/Objective/Beetle.png"));

    case Objective::OWLS:
        return(QPixmap(":/images/Objective/Owls.png"));

    case Objective::RAT:
        return(QPixmap(":/images/Objective/Rat.png"));

    case Objective::SPIDER:
        return(QPixmap(":/images/Objective/Spider.png"));

    case Objective::BUTTERFLY:
        return(QPixmap(":/images/Objective/Butterfly.png"));

    case Objective::LIZARD:
        return(QPixmap(":/images/Objective/Lizard.png"));

    case Objective::GRIMOIRE:
        return(QPixmap(":/images/Objective/Grimoire.png"));

    case Objective::GOLD_PURSE:
        return(QPixmap(":/images/Objective/Gold_Purse.png"));

    case Objective::MAP:
        return(QPixmap(":/images/Objective/Map.png"));

    case Objective::CROWN:
        return(QPixmap(":/images/Objective/Crown.png"));

    case Objective::KEYS:
        return(QPixmap(":/images/Objective/Keys.png"));

    case Objective::BONES:
       return(QPixmap(":/images/Objective/Bones.png"));

    case Objective::RING:
        return(QPixmap(":/images/Objective/Ring.png"));


    case Objective::EMERALD:
        return(QPixmap(":/images/Objective/Emerald.png"));

    case Objective::TREASURE_CHEST:
        return(QPixmap(":/images/Objective/Treasure.png"));

    case Objective::SWORD:
        return(QPixmap(":/images/Objective/Sword.png"));

    case Objective::CUNDLESTICK:
        return(QPixmap(":/images/Objective/Cundlestick.png"));

    case Objective::HELM:
        return(QPixmap(":/images/Objective/Helm.png"));

    case Objective::WIZZARDY:
        return(QPixmap(":/images/Objective/Wizzardry.png"));
    default:
        return(QPixmap(":/images/Void.png"));
    }
}
