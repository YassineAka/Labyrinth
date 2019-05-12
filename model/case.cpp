#include "case.h"

Case::Case(Objective obj, bool isMovible, int number): objective_(obj), isMovible_(isMovible), number_(number)
{



}
Case::Case(Objective obj): objective_(obj)
{
    up_ = true;
    down_ = true;
    right_ = false ;
    left_ = false ;
}

bool Case::getIsMovible() const{
    return isMovible_;
}
Objective Case::getObjective() const{
    return objective_;
}
bool Case::hasObjective() const{
    return !(objective_ == Objective::NONE);
}
int Case::getNumber()const{
    return number_;
}
bool Case::isI()
{
    return ((up_== true && down_== true && right_== false && left_== false) ||
            (up_== false && down_== false && right_== true && left_== true));
}
bool Case::isL()
{
    return ((up_== true && down_== false && right_== true && left_== false) ||
            (up_== false && down_== true && right_== true && left_== false) ||
            (up_== false && down_== true && right_== false && left_== true) ||
             (up_== true && down_== false && right_== false && left_== true));
}
void Case::rotateCase()
{

    if (this->isI()) {
        up_ = !up_;
        down_ = !down_;
        right_ = !right_;
        left_ = !left_;
    }else if (this->isL()) {
        if ((cpt_ % 2) ==0) {
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
    }else{
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
}
