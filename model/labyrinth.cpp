#include "labyrinth.h"
#include <algorithm>
#include "player.h"
#include "time.h"
#include <stack>
#include <list>

static vector<Objective> objectives_;
void initObjectives(){

    objectives_.push_back(Objective::GHOST);
    objectives_.push_back(Objective::GNOME);
    objectives_.push_back(Objective::DRAGON);
    objectives_.push_back(Objective::FAIRY);
    objectives_.push_back(Objective::GENIUS);
    objectives_.push_back(Objective::BAT);
    objectives_.push_back(Objective::BEETLE);
    objectives_.push_back(Objective::OWLS);
    objectives_.push_back(Objective::RAT);
    objectives_.push_back(Objective::SPIDER);
    objectives_.push_back(Objective::BUTTERFLY);
    objectives_.push_back(Objective::LIZARD);
    objectives_.push_back(Objective::GRIMOIRE);
    objectives_.push_back(Objective::GOLD_PURSE);
    objectives_.push_back(Objective::MAP);
    objectives_.push_back(Objective::CROWN);
    objectives_.push_back(Objective::KEYS);
    objectives_.push_back(Objective::BONES);
    objectives_.push_back(Objective::RING);
    objectives_.push_back(Objective::EMERALD);
    objectives_.push_back(Objective::TREASURE_CHEST);
    objectives_.push_back(Objective::SWORD);
    objectives_.push_back(Objective::CUNDLESTICK);
    objectives_.push_back(Objective::HELM);
    objectives_.push_back(Objective::WIZZARDY);

    std::srand (time(0));
    std::random_shuffle(objectives_.begin(), objectives_.end());
}

stack<Objective> initDeckPlayer()
{
    stack<Objective> deck;
    for (int i = 0; i < 6; i++) {
        Objective obj = objectives_.back();
        objectives_.pop_back();
        deck.push(obj);
    }
    return deck;

}

Labyrinth::Labyrinth(Plate plate): plate_(plate)
{
    initObjectives();
    Player blue(Color::BLUE,Position(0,0),initDeckPlayer(),0);
    Player green(Color::GREEN,Position(0,6),initDeckPlayer(),1);
    Player yellow(Color::YELLOW,Position(6,6),initDeckPlayer(),2);
    Player red(Color::RED,Position(6,0),initDeckPlayer(),3);
    players_.push_back(blue);
    players_.push_back(green);
    players_.push_back(yellow);
    players_.push_back(red);
    static_cast<CaseL>((plate_.getPlate()->at(0)).at(0)).addPlayer(blue);
    static_cast<CaseL>((plate_.getPlate()->at(0)).at(0)).addPlayer(green);
    static_cast<CaseL>((plate_.getPlate()->at(0)).at(0)).addPlayer(yellow);
    static_cast<CaseL>((plate_.getPlate()->at(0)).at(0)).addPlayer(red);
    CurrentPlayer_ = &players_[0];

}
void Labyrinth::start(){

}
bool Labyrinth::isOver() {
        if (CurrentPlayer_->hasWon()) {
            if (CurrentPlayer_->getColor() == Color::BLUE) {
                if ((CurrentPlayer_->getPosition().getX() == 0) && ((CurrentPlayer_->getPosition().getY() == 0))) {
                    return true;
                }
            }else if (CurrentPlayer_->getColor() == Color::RED) {
                if ((CurrentPlayer_->getPosition().getX() == 0) && ((CurrentPlayer_->getPosition().getY() == 6))) {
                    return true;
                }
            }else if (CurrentPlayer_->getColor() == Color::GREEN) {
                if ((CurrentPlayer_->getPosition().getX() == 6) && ((CurrentPlayer_->getPosition().getY() == 6))) {
                    return true;
                }
             }else{
                    if ((CurrentPlayer_->getPosition().getX() == 6) && ((CurrentPlayer_->getPosition().getY() == 0))) {
                        return true;
                    }
             }
        }


    return false;

}
Player Labyrinth::getWinner(){
    if (CurrentPlayer_->getStock().empty()) {
        if (CurrentPlayer_->getColor() == Color::BLUE) {
            if ((CurrentPlayer_->getPosition().getX() == 0) && ((CurrentPlayer_->getPosition().getY() == 0))) {
                return *CurrentPlayer_;
            }
        }else if (CurrentPlayer_->getColor() == Color::RED) {
            if ((CurrentPlayer_->getPosition().getX() == 0) && ((CurrentPlayer_->getPosition().getY() == 6))) {
                return *CurrentPlayer_;
            }
        }else if (CurrentPlayer_->getColor() == Color::GREEN) {
            if ((CurrentPlayer_->getPosition().getX() == 6) && ((CurrentPlayer_->getPosition().getY() == 6))) {
                return *CurrentPlayer_;
            }
         }else{
                if ((CurrentPlayer_->getPosition().getX() == 6) && ((CurrentPlayer_->getPosition().getY() == 0))) {
                    return *CurrentPlayer_;
                }
         }
    }
}

void Labyrinth:: nextPlayer(){

    CurrentPlayer_ = &(players_[(CurrentPlayer_->getIndex()+1) % static_cast<int>(players_.size())]);
    notifyObservers();

}
void Labyrinth::placeNewCase(Position pos){
    plate_.insertCase(pos);
    notifyObservers();

}
void Labyrinth::rotateRemainCase()
{
    plate_.rotateRemainCase();
    notifyObservers();
}

void Labyrinth:: move(Position pos){
    CurrentPlayer_->move(pos);
    if (CurrentPlayer_->getObjective() == ((Case)(this->getPlate().getPlate()->at(pos.getX())).at(pos.getY())).getObjective()) {
        (*CurrentPlayer_).getNextObjective();
    }
    if ((*CurrentPlayer_).hasWon() && this->isOver()) {
        gameIsOver_ = true;
    }
    notifyObservers();
}
list<Player> Labyrinth::getPlayersAt(Position pos){
    list<Player>  players;
    for (Player player : players_) {
        if (player.getPosition() == pos) {
            players.push_back(player);
        }
    }
    return players;
}
QString* getStringFromColor(Color color)
{
    QString  * stringColor;
    switch(color){
    case Color::BLUE:
        stringColor->append("BLUE")  ;
        break;
    case Color::RED:
        stringColor->append("RED");
        break;
    case Color::GREEN:
        stringColor->append("GREEN");
        break;
    case Color::YELLOW:
        stringColor->append("YELLOW");
        break;
    default:
        ;
    }
    return stringColor;
}
