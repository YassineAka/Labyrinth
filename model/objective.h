#ifndef OBJECTIVE_H
#define OBJECTIVE_H

#include <iostream>
#include <QPixmap>
enum  Objective{
    GHOST,
    GNOME,
    DRAGON,
    FAIRY,
    GENIUS,
    BAT,
    BEETLE,
    OWLS,
    RAT,
    SPIDER,
    BUTTERFLY,
    LIZARD,
    GRIMOIRE,
    GOLD_PURSE,
    MAP,
    CROWN,
    KEYS,
    BONES,
    RING,
    EMERALD,
    TREASURE_CHEST,
    SWORD,
    CUNDLESTICK,
    HELM,
    WIZZARDY,
    NONE
};




inline std::ostream& operator<<(std::ostream &os ,  Objective const& o){
    switch (o) {
    case Objective::GHOST:
        os << "GHOST";

        break;
    case Objective::GNOME:
        os << "GNOME";
        break;
    case Objective::DRAGON:
        os << "DRAGON";
        break;
    case Objective::FAIRY:
        os << "FAIRY";
        break;
    case Objective::GENIUS:
        os << "GENIUS";
        break;
    case Objective::BAT:
        os << "BAT";
        break;
    case Objective::BEETLE:
        os << "BEETLE";
        break;
    case Objective::OWLS:
        os << "OWLS";
        break;
    case Objective::RAT:
        os << "RAT";
        break;
    case Objective::SPIDER:
        os << "SPIDER";
        break;
    case Objective::BUTTERFLY:
        os << "BUTTERFLY";
        break;
    case Objective::LIZARD:
        os << "LIZARD";
        break;
    case Objective::GRIMOIRE:
        os << "GRIMOIRE";
        break;
    case Objective::GOLD_PURSE:
        os << "GOLD_PURSE";
        break;
    case Objective::MAP:
        os << "MAP";
        break;
    case Objective::CROWN:
        os << "CROWN";
        break;
    case Objective::KEYS:
        os << "KEYS";
        break;
    case Objective::BONES:
        os << "BONES";
        break;
    case Objective::RING:
        os << "RING";
        break;
    case Objective::EMERALD:
        os << "EMERALD";
        break;
    case Objective::TREASURE_CHEST:
        os << "TREASURE_CHEST";
        break;
    case Objective::SWORD:
        os << "SWORD";
        break;
    case Objective::CUNDLESTICK:
        os << "CUNDLESTICK";
        break;
    case Objective::HELM:
        os << "HELM";
        break;
    case Objective::WIZZARDY:
        os << "WIZZARDY";
        break;
    default:
        os << "NONE";  // pour éviter de mettre null vu que ca génère une erreur.

    }
    return os;
}

#endif // OBJECTIVE_H
