#include "position.h"

Position::Position(int x, int y): x_(x),y_(y)
{

}
Position::Position(const Position &pos): x_(pos.getX()),y_(pos.getY())
{

}

