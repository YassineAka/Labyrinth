#include "casel.h"
#include<ostream>

using namespace std;
CaseL::CaseL(Objective obj, bool isMovible, int number) : Case(obj, isMovible, number),cpt_(0)
{
 setUp(true);
 setDown(false);
 setRight(true);
 setLeft(false);
}
CaseL::CaseL(Case& myCase):Case(myCase.getObjective(), myCase.getIsMovible(), myCase.getNumber()),cpt_(0)
{
    up_ = myCase.getUp();
    down_ = myCase.getDown();
    right_ = myCase.getRight();
    left_ = myCase.getLeft();
}

void CaseL::rotateCase()
{
    if ((this->getCpt() % 2) ==0) {
        if (getUp()== true) {
            up_=false;
            down_=true;
        }else{
            up_= true;
            down_=false;
        }
    }else{
        if (getRight()== true) {
            right_=false;
            left_=true;
        }else{
            right_= true;
            left_=false;
        }
    }
    cpt_++;
}
