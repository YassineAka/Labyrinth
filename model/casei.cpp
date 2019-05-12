#include "casei.h"

CaseI::CaseI(Objective obj, bool isMovible, int number) : Case(obj, isMovible, number)
{
    up_ = true;
    down_ = true;
    right_ = false ;
    left_ = false ;

}
CaseI::CaseI(Case& myCase):Case(myCase.getObjective(), myCase.getIsMovible(), myCase.getNumber()){
    up_ = myCase.getUp();
    down_ = myCase.getDown();
    right_ = myCase.getRight();
    left_ = myCase.getLeft();
}


void CaseI::rotateCase(){
    up_ = !up_;
    down_ = !down_;
    right_ = !right_;
    left_ = !left_;
}
