/*
 Programme : Jeu du Taquin

 But :  créer un jeu complet, dans le cadre de la SAE "Comparaison d'approches algorithiques"
 Date de dernière modification : 20/01/2023
 Auteur : Nathan Piel, Mathieu Chourreau
          Nous certifions être les auteurs de ce code source et attestons ne pas avoir utilisé d'extraits de code
          provenant d'internet. Ce code source s'appuie uniquement sur les notions de programmation vues dans le
          cadre du module R1.01 - Initiation au développement partie 1 et 2.
*/

#include <iostream>
#include "jeuTaquin.h"
#include "../game-tools.h"
using namespace std;

void afficherGrilleTaquin(Grille grilleTaquin, const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE)
{
    for (int short i = 0; i < NB_LIGNE; i++)
    {
        for (int short j = 0; j < NB_COLONNE; j++)
        {
            if (grilleTaquin[i][j] == 0)
            {
                cout << "    ";
            }
            else if (grilleTaquin[i][j] < 10)
            {
                cout << '0' << grilleTaquin[i][j] << "  ";
            }
            else
            {
                cout << grilleTaquin[i][j] << "  ";
            }
        }
        cout << endl;
    }
}


void creerLaGrilleTaquin(unsigned int short posCaseVideLig, unsigned int short posCaseVideCol, Grille grilleTaquin,
                         const unsigned short int NB_COLONNE, const unsigned short int NB_LIGNE, unsigned short int valCase)
{
    for (short int i = 0; i < NB_LIGNE; i++)
    {
        // Remplir le tableau
        for (short int j = 0; j < NB_COLONNE; j++)
        {
            // Placer les valeurs dans les cases et la case vide
            if (i == posCaseVideLig && j == posCaseVideCol)
            {
                // Placer la case vide
                grilleTaquin[i][j] = 0;
            }
            else
            {
                // Placer la Case
                grilleTaquin[i][j] = valCase;
                valCase = static_cast<unsigned short int>(valCase + 1);
            }
        }
    }
}

char verifierMouvementVersLeHaut(char &verifMouv, unsigned short int posCaseVideCol, unsigned short int posCaseVideLig)
{
    if (verifMouv != 'b' && posCaseVideLig != 0)
    {
        // Modifier la valeur de verifMouv
        verifMouv = 'h';
    }
    else
    {
        // Faire un autre mouvement car vers le haut est impossible
        if (verifMouv != 'd' && posCaseVideCol != 0)
        {
            // Modifier la valeur de verifMouv
            verifMouv = 'g';
        }
        else
        {
            // Modifier la valeur de verifMouv
            if (verifMouv != 'g' && posCaseVideCol != NB_COLONNE - 1)
            {
                // Modifier la valeur de verifMouv
                verifMouv = 'd';
            }
            else
            {
                if (verifMouv != 'h' && posCaseVideLig != NB_LIGNE - 1)
                {
                    // Modifier la valeur de verifMouv
                    verifMouv = 'b';
                }
            }
        }
    }
    return verifMouv;
}

char verifierMouvementVersLeBas(char &verifMouv, unsigned short int posCaseVideCol, unsigned short int posCaseVideLig,
                                const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE)
{
    if (verifMouv != 'h' && posCaseVideLig != NB_LIGNE - 1)
    {
        // Modifier la valeur de verifMouv
        verifMouv = 'b';
    }
    else
    {
        // Faire un autre mouvement car vers le bas est impossible
        if (verifMouv != 'g' && posCaseVideCol != NB_COLONNE - 1)
        {
            // Modifier la valeur de verifMouv
            verifMouv = 'd';
        }
        else
        {
            // Modifier la valeur de verifMouv
            if (verifMouv != 'd' && posCaseVideCol != 0)
            {
                // Modifier la valeur de verifMouv
                verifMouv = 'g';
            }
            else
            {
                if (verifMouv != 'b' && posCaseVideLig != 0)
                {
                    // Modifier la valeur de verifMouv
                    verifMouv = 'h';
                }
            }
        }
    }
    return verifMouv;
}

char verifierMouvementVersLaDroite(char &verifMouv, unsigned short int posCaseVideCol, unsigned short int posCaseVideLig,
                                   const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE)
{
    if (verifMouv != 'g' && posCaseVideCol != NB_COLONNE - 1)
    {
        // Modifier la valeur de verifMouv
        verifMouv = 'd';
    }
    else
    {
        // Faire un autre mouvement car vers la droite est impossible
        if (verifMouv != 'h' && posCaseVideLig != NB_LIGNE - 1)
        {
            // Modifier la valeur de verifMouv
            verifMouv = 'b';
        }
        else
        {
            // Modifier la valeur de verifMouv
            if (verifMouv != 'b' && posCaseVideLig != 0)
            {
                // Modifier la valeur de verifMouv
                verifMouv = 'h';
            }
            else
            {
                if (verifMouv != 'd' && posCaseVideCol != 0)
                {
                    // Modifier la valeur de verifMouv
                    verifMouv = 'g';
                }
            }
        }
    }
    return verifMouv;
}

char verifierMouvementVersLaGauche(char &verifMouv, unsigned short int posCaseVideCol, unsigned short int posCaseVideLig)
{
    if (verifMouv != 'd' && posCaseVideCol != 0)
    {
        // Modifier la valeur de verifMouv
        verifMouv = 'g';
    }
    else
    {
        // Faire un autre mouvement car vers la gauche est impossible
        if (verifMouv != 'b' && posCaseVideLig != 0)
        {
            // Modifier la valeur de verifMouv
            verifMouv = 'h';
        }
        else
        {
            // Modifier la valeur de verifMouv
            if (verifMouv != 'h' && posCaseVideLig != NB_LIGNE - 1)
            {
                // Modifier la valeur de verifMouv
                verifMouv = 'b';
            }
            else
            {
                if (verifMouv != 'g' && posCaseVideCol != NB_COLONNE - 1)
                {
                    // Modifier la valeur de verifMouv
                    verifMouv = 'd';
                }
            }
        }
    }
    return verifMouv;
}
void echangerCaseVersLeHaut(Grille grilleTaquin, unsigned short int valCaseVide, unsigned int short posCaseVideCol,
                            unsigned int short &posCaseVideLig)
{
    // remplacer la case actuelle par la valeur de la case du haut
    grilleTaquin[posCaseVideLig][posCaseVideCol] = grilleTaquin[posCaseVideLig - 1][posCaseVideCol];

    // remplacer la case du haut par la valeur de la case vide
    grilleTaquin[posCaseVideLig - 1][posCaseVideCol] = valCaseVide;

    // mettre a jour posCaseVideLig
    posCaseVideLig = static_cast<unsigned short int>(posCaseVideLig - 1);
}
void echangerCaseVersLeBas(Grille grilleTaquin, unsigned short int valCaseVide, unsigned int short posCaseVideCol,
                           unsigned int short &posCaseVideLig)
{
    // remplacer la case actuelle par la valeur de la case du bas
    grilleTaquin[posCaseVideLig][posCaseVideCol] = grilleTaquin[posCaseVideLig + 1][posCaseVideCol];

    // remplacer la case du bas parla valeur de la case vide
    grilleTaquin[posCaseVideLig + 1][posCaseVideCol] = valCaseVide;

    // mettre a jour posCaseVideLig
    posCaseVideLig = static_cast<unsigned short int>(posCaseVideLig + 1);
}

void echangerCaseVersLaGauche(Grille grilleTaquin, unsigned short int valCaseVide, unsigned int short &posCaseVideCol,
                              unsigned int short posCaseVideLig)
{
    // remplacer la case actuelle par la valeur de la case de gauche
    grilleTaquin[posCaseVideLig][posCaseVideCol] = grilleTaquin[posCaseVideLig][posCaseVideCol - 1];

    // remplacer la case de gauche par la valeur de la case vide
    grilleTaquin[posCaseVideLig][posCaseVideCol - 1] = valCaseVide;

    // mettre a jour posCaseVideCol
    posCaseVideCol = static_cast<unsigned short int>(posCaseVideCol - 1);
}

void echangerCaseVersLaDroite(Grille grilleTaquin, unsigned short int valCaseVide, unsigned int short &posCaseVideCol,
                              unsigned int short posCaseVideLig)
{
    // remplacer la case actuelle par la valeur de la case de droite
    grilleTaquin[posCaseVideLig][posCaseVideCol] = grilleTaquin[posCaseVideLig][posCaseVideCol + 1];

    // remplacer la case de droite par la valeur de la case vide
    grilleTaquin[posCaseVideLig][posCaseVideCol + 1] = valCaseVide;

    // mettre a jour posCaseVideCol
    posCaseVideCol = static_cast<unsigned short int>(posCaseVideCol + 1);
}

bool verifMouvVersBas(Grille grilleTaquin, unsigned int short &posCaseVideCol, unsigned int short &posCaseVideLig, string caseSelectJoueur, bool &verifMouvDebug)
{
    if (stoi(caseSelectJoueur) == grilleTaquin[posCaseVideLig + 1][posCaseVideCol])
    {
        // Modifier la valeur de verifMouvDebug
        return verifMouvDebug = false;
    }
    else
    {
        // gerer le cas d'erreurs

        // afficher message d'erreur
        afficherTexteEnCouleur("Mouvement Invalide :-( ", rouge, false);

        // attendre 2s
        pause(2);
        return 0;
    }
}
bool verifMouvVersHaut(Grille grilleTaquin, unsigned int short &posCaseVideCol, unsigned int short &posCaseVideLig, string caseSelectJoueur, bool &verifMouvDebug)
{
    if (stoi(caseSelectJoueur) == grilleTaquin[posCaseVideLig - 1][posCaseVideCol])
    {
        // Modifier la valeur de verifMouvDebug
        return verifMouvDebug = false;
    }
    else
    {
        // gerer le cas d'erreurs

        // Afficher message d'erreur
        afficherTexteEnCouleur("Mouvement Invalide :-( ", rouge, false);

        // attendre 2s
        pause(2);
        return 0;
    }
}
bool verifMouvVersGauche(Grille grilleTaquin, unsigned int short &posCaseVideCol, unsigned int short &posCaseVideLig, string caseSelectJoueur, bool &verifMouvDebug)
{
    if (stoi(caseSelectJoueur) == grilleTaquin[posCaseVideLig][posCaseVideCol - 1] && posCaseVideCol != 0)
    {
        // Modifier la valeur de verifMouvDebug
        return verifMouvDebug = false;
    }
    else
    {
        // gerer le cas d'erreurs

        // Afficher message d'erreur
        afficherTexteEnCouleur("Mouvement Invalide :-( ", rouge, false);

        // attendre 2s
        pause(2);
        return 0;
    }
}

bool verifMouvVersDroite(Grille grilleTaquin, unsigned int short &posCaseVideCol, unsigned int short &posCaseVideLig, string caseSelectJoueur, bool &verifMouvDebug)
{
    if (stoi(caseSelectJoueur) == grilleTaquin[posCaseVideLig][posCaseVideCol + 1] && posCaseVideCol != NB_COLONNE - 1)
    {
        // Modifier la valeur de verifMouvDebug
        return verifMouvDebug = false;
    }
    else
    {
        // gerer le cas d'erreurs

        // Afficher message d'erreur
        afficherTexteEnCouleur("Mouvement Invalide :-( ", rouge, false);

        // attendre 2s
        pause(2);
        return 0;
    }
}

bool verifVictoire(bool &verifMouvDebug, unsigned short int posCaseActLig, unsigned short int posCaseActCol,
                   const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE, Grille grilleTaquin)
{

    // initialiser les variables
    verifMouvDebug = true;
    posCaseActLig = 0;
    posCaseActCol = 0;

    // parcourir la grille de taquin
    while (true)
    {
        // Verifier si on est situé à la fin de la grille
        if (posCaseActLig == NB_LIGNE - 1 && posCaseActCol == NB_COLONNE - 1)
        {
            // Modifier verifMouvDebug
            verifMouvDebug = false;
            break;
        }

        // Vérifier si la case vide n'est pas dans un des 4 coins de la grille
        if (grilleTaquin[0][0] != 0 && grilleTaquin[0][NB_COLONNE - 1] != 0 && grilleTaquin[NB_LIGNE - 1][0] != 0 && grilleTaquin[NB_LIGNE - 1][NB_COLONNE - 1] != 0)
        {
            break;
        }

        if (posCaseActLig == NB_LIGNE - 1 && posCaseActCol == NB_LIGNE - 2 && grilleTaquin[posCaseActLig][posCaseActCol + 1] == 0)
        {
            // on est situé à l'avant dernière case de la grille
            // Modifier verifMouvDebug
            verifMouvDebug = false;
            break;
        }

        else if (posCaseActCol == NB_COLONNE - 1)
        {
            // on est situé dans la dernière colonne de la grille
            if (grilleTaquin[posCaseActLig + 1][0] == 0)
            {
                // la case suivante est la case vide
                //  Déplacer la case actuelle
                posCaseActLig = static_cast<unsigned short int>(posCaseActLig + 1);
                posCaseActCol = 1;
            }

            else if (grilleTaquin[posCaseActLig][posCaseActCol] + 1 != grilleTaquin[posCaseActLig + 1][0])
            {
                // la case suivante n'est pas en équation avec la grille
                break;
            }
        }

        else
        {
            // Cas où on n'est pas situé dans la dernière colonne
            if (grilleTaquin[posCaseActLig][posCaseActCol + 1] == 0)
            {
                // la case suivante est la case vide
                // Déplacer la case actuelle
                posCaseActCol = static_cast<unsigned short int>(posCaseActCol + 2);

                // Déplacer la case actuelle si elle est situé hors de la grille
                if (posCaseActCol > NB_COLONNE - 1)
                {
                    posCaseActLig = static_cast<unsigned short int>(posCaseActLig + 1);
                    posCaseActCol = 1;
                }
            }

            else if (grilleTaquin[posCaseActLig][posCaseActCol] + 1 != grilleTaquin[posCaseActLig][posCaseActCol + 1])
            {
                // la case suivante n'est pas en équation avec la grille
                break;
            }
        }

        // Passer a la position suivante
        if (posCaseActCol == NB_COLONNE - 1)
        {
            posCaseActLig = static_cast<unsigned short int>(posCaseActLig + 1);
            posCaseActCol = 0;
        }
        posCaseActCol = static_cast<unsigned short int>(posCaseActCol + 1);
    }
    return verifMouvDebug;
}
