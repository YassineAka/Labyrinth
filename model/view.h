#ifndef VIEW_H
#define VIEW_H
#include "labyrinth.h"

class View
{
public:
    /**
     * @brief constructeur de la View
     * @param labyrinth
     */
    View(Labyrinth * labyrinth);
    /**
     * @brief affichePlateau sur lequel on joue
     */
    void affichePlateau();
    /**
     * @brief demanderDeplacement demander la position pour le deplacement.
     * @return
     */
    Position demanderPositionPourCase();
    /**
     * @brief ajouterJoueur demande si il faut ajouter des joueurs a la partie.
     * @return
     */
    Position demanderPositionPourMove();
    bool ajouterJoueur();
    /**
     * @brief demanderJouer demande a l utilisateur si il veut jouer.
     * @return
     */
    bool demanderJouer();
    /**
     * @brief View::erreurChemin affiche une erreur si le chemin est mauvais a la pos donnée.
     * @return
     */
    bool erreurChemin();
    /**
     * @brief accede au Labyrinth fournie a la vue
     * @return labyrinthe trouver
     */
    Labyrinth& getLabyrinth();
    /**
     * @brief affichePlateauObjective
     */
    void affichePlateauObjective();
private:
    Labyrinth& labyrinth_;

};

inline Labyrinth& View::getLabyrinth(){
    return labyrinth_;
}

#endif // VIEW_H
