#ifndef POSITION_H
#define POSITION_H
#include <ostream>
/**
 * @brief class Position qui va gerer les positions des joueurs.
 */
class Position
{
    unsigned int x_;
    unsigned int y_;
public:
    /**
     *@brief constructeur par defaut
     */
    Position() = default;
    /**
     * @brief constructeur de Position.
     * @param x abscisse d'une position.
     * @param y ordonner de la position.
     */
    Position(int x, int y);
    /**
     * @brief Position
     * @param pos
     */
    Position(const Position& pos);
    /**
     * @brief getter de l attribut X.
     * @return le X trouver.
     */
    inline int getX() const;
    /**
     * @brief getter de l'attribut Y.
     * @return le Y trouver
     */
    inline int getY() const;
    /**
     * @brief setter de l'attribut X
     * @param valeur fournie de x a changer
     */
    inline void setX(int x);
    /**
     * @brief setter de l'attribut Y
     * @param valeur fournie de y a changer
     */
    inline void setY(int y);
};
inline Position::getX() const
{
    return this->x_;
}

inline Position::getY() const
{
    return this->y_;
}

inline void Position::setX(int x)
{
     this->x_ = x;
}

inline void Position::setY(int y)
{
     this->y_ = y;
}
inline std::ostream& operator<<(std::ostream& os, Position  pos){
   os << "( " << pos.getX() << " , " << pos.getY() << " ) ";
    return os;
}
inline bool operator==(Position const& a, Position const& b)
{
    if(a.getX() == b.getX() && a.getY() == b.getY() ){
        return true;
    }
    else{
        return false;
    }
}

#endif // POSITION_H
