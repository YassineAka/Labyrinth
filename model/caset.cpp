#include "caset.h"

CaseT::CaseT(Objective obj, bool isMovible, int number ) : Case(obj, isMovible, number)
{
 setUp(false);
 setDown(true);
 setRight(true);
 setLeft(true);
}
CaseT::CaseT(Case& myCase):Case(myCase.getObjective(), myCase.getIsMovible(), myCase.getNumber()){
    up_ = myCase.getUp();
    down_ = myCase.getDown();
    right_ = myCase.getRight();
    left_ = myCase.getLeft();
}

void CaseT::rotateCase()
{
    if (up_ == false && down_ == true && right_ == true && left_ == true) {
        up_ = true;
        down_ = true;
        right_ = false;
        left_ = true;

    } else if (up_ == true && down_ == true && right_ == false && left_ == true) {
        up_ = true;
        down_ = false;
        right_ = true;
        left_ = true;

    } else if (up_ == true && down_ == false && right_ == true && left_ == true) {
        up_ = true;
        down_ = true;
        right_ = true;
        left_ = false;
    } else if(up_ == true && down_ == true && right_ == true && left_ == false ){
        up_ = false;
        down_ = true;
        right_ = true;
        left_ = true;
    }
}
