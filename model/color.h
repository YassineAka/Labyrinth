 #ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <string>
#include <QString>


 enum Color {
    BLUE,
    GREEN,
    YELLOW,
    RED
};



inline std::ostream& operator<<(std::ostream& os, Color color){
    switch(color){
    case Color::BLUE:
        os << "blue";
        break;
    case Color::RED:
        os << "red";
        break;
    case Color::GREEN:
        os << "green";
        break;
    case Color::YELLOW:
        os << "yellow";
        break;
    default:
        os << "unknow";
    }
    return os;
}

#endif // COLOR_H
