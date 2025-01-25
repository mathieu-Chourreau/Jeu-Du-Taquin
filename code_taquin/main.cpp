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

int main(void)
{
    // VARIABLES
    unsigned int short posCaseVideLig;   // Ligne où se situe la case vide
    unsigned int short posCaseVideCol;   // Colonne ou se situe la case vide
    unsigned short int alea;             // Nombre aléatoire qui détermine dans quel coin de la grille il faut positionner la case vide
    unsigned int short valCase;          // valeur d’une case de la grille qui se modifie à chaque itération de la boucle
    unsigned short int nbMouvGrille;     // nombre aléatoire qui détermine le nombre de mouvements que va faire le programme pour mélanger la grille
    unsigned short int direction;        // nombre aléatoire qui détermine quelle est la direction de l’échange qui va être fait pour mélanger la grille
    unsigned short int valCaseVide;      // la valeur de la case vide (0)
    bool modeDebug;                      // stock si le joueur a activé ou non le mode débug
    char repDebug;                       // réponse du joueur à l’activation du mode débug
    char verifMouv;                      // dernier mouvement qui a été réalisé, existe pour éviter que la grille se mélange mal
    string solGrilleTaquin;              // solution de la grille du taquin, visible si le joueur a décidé de l'activer
    string mouvJoueur;                   // mouvement que souhaite faire le joueur
    unsigned short int tailleMouvJoueur; // taille de la chaîne de caractère que le joueur a rentré
    char dernierCar;                     // dernier caractère du mouvement souhaité par le joueur
    string caseSelectJoueur;             // case que souhaite échanger la joueur avec la case vide
    bool verifMouvDebug;                 // boolean qui permet de sortir des boucles de saisie verif erreur.
    unsigned short int posCaseActLig;    // Indique la position de la case actuelle de la ligne quand on vérifie si le joueur a gagné.
    unsigned short int posCaseActCol;    // Indique la position de la case actuelle de la colonne quand on vérifie si le joueur a gagné.

    // TRAITEMENTS

    // Initialiser la partie

    // initialiser Grille Taquin

    // initialisation des valeurs

    // initialiser les variables

    alea = static_cast<unsigned short int>(2);
    valCase = 1;

    // initialiser le tableau

    Grille grilleTaquin = {0}; // la grille du jeu du taquin

    // determiner où positioner la case vide
    switch (alea)
    {
    case 1:
        // Positionner la case vide en haut à gauche
        posCaseVideCol = 0;
        posCaseVideLig = 0;
        break;
    case 2:
        // Positionner la case vide en bas à gauche
        posCaseVideCol = 0;
        posCaseVideLig = NB_LIGNE - 1;
        break;

    case 3:
        //  Positionner la case vide en haut à droite
        posCaseVideCol = NB_COLONNE - 1;
        posCaseVideLig = 0;
        break;

    case 4:
        // Positionner la case vide en bas à droite
        posCaseVideCol = NB_COLONNE - 1;
        posCaseVideLig = NB_LIGNE - 1;
        break;
    }

    // Creer la grille
    creerLaGrilleTaquin(posCaseVideLig, posCaseVideCol, grilleTaquin, NB_COLONNE, NB_LIGNE, valCase);

    // Preparer Parametrage Mode Debug

    // Saisie Verif Erreur

    // recuperer et analyser repDebug
    while (verifMouvDebug == false)
    {

        // Afficher la question
        afficherTexteEnCouleur("-- JEU DU TAQUIN --", bleu, true);
        cout << endl
             << "Voulez-vous activer le mode debug (o/n) ? ";

        // recuperer repDebug
        cin >> repDebug;

        // analyser repDebug
        switch (repDebug)
        {
        case 'o':
            // mode debug est activé
            modeDebug = true;
            verifMouvDebug = true;

            // effacer l'écran
            effacer();
            break;
        case 'n':
            // mode debug est désactivé
            modeDebug = false;
            verifMouvDebug = true;

            // effacer l'écran
            effacer();
            break;
        default:
            // gerer le cas d'erreur

            // afficher message d'erreur
            cout << endl;
            afficherTexteEnCouleur("Saisie incorrecte. Recommencez... ", rouge, false);

            // attendre 2s
            pause(2);
            effacer();
        }
    }

    // Melange Grille Taquin

    // Initialiser les valeur
    verifMouv = ' ';
    solGrilleTaquin = "";
    valCaseVide = 0;
    nbMouvGrille = static_cast<unsigned short int>(10);

    // Melanger grilleTaquin
    for (unsigned int short i = 0; i < nbMouvGrille; i++)
    {
        // Vérifier si le mouvement est possible à faire
        direction = static_cast<unsigned short int>(random(1, 4));
        switch (direction)
        {
        case 1:
            verifierMouvementVersLeHaut(verifMouv, posCaseVideCol, posCaseVideLig);
            break;

        case 2:
            verifierMouvementVersLeBas(verifMouv, posCaseVideCol, posCaseVideLig, NB_LIGNE, NB_COLONNE);
            break;

        case 3:
            verifierMouvementVersLaGauche(verifMouv, posCaseVideCol, posCaseVideLig);
            break;

        case 4:
            verifierMouvementVersLaDroite(verifMouv, posCaseVideCol, posCaseVideLig, NB_LIGNE, NB_COLONNE);
            break;
        }

        // echanger les cases
        switch (verifMouv)
        {
        case 'h':
            // échanger la case vers le haut et completer solGrilleTaquin
            echangerCaseVersLeHaut(grilleTaquin, valCaseVide, posCaseVideCol, posCaseVideLig);
            solGrilleTaquin = to_string(grilleTaquin[posCaseVideLig + 1][posCaseVideCol]) + 'h' + ' ' + solGrilleTaquin;
            break;

        case 'b':
            // échanger la case vers le bas et completer solGrilleTaquin
            echangerCaseVersLeBas(grilleTaquin, valCaseVide, posCaseVideCol, posCaseVideLig);
            solGrilleTaquin = to_string(grilleTaquin[posCaseVideLig - 1][posCaseVideCol]) + 'b' + ' ' + solGrilleTaquin;
            break;

        case 'g':
            // échanger la case vers la gauche et completer solGrilleTaquin
            echangerCaseVersLaGauche(grilleTaquin, valCaseVide, posCaseVideCol, posCaseVideLig);
            solGrilleTaquin = to_string(grilleTaquin[posCaseVideLig][posCaseVideCol + 1]) + 'g' + ' ' + solGrilleTaquin;
            break;

        case 'd':
            // échanger la case vers la droite et completer solGrilleTaquin
            echangerCaseVersLaDroite(grilleTaquin, valCaseVide, posCaseVideCol, posCaseVideLig);
            solGrilleTaquin = to_string(grilleTaquin[posCaseVideLig][posCaseVideCol - 1]) + 'd' + ' ' + solGrilleTaquin;
            break;
        }
    }

    // jouer la partie
    posCaseActLig = 0;
    posCaseActCol = 0;
    while (true)
    {
        // Afficher le titre
        afficherTexteEnCouleur("-- JEU DU TAQUIN --", bleu, true);
        cout << endl;

        // grilleTaquin >>afficher grille taquin
        afficherGrilleTaquin(grilleTaquin, NB_LIGNE, NB_COLONNE);
        cout << endl;

        // Vérifier si le mode debug est activé
        if (modeDebug)
        {
            afficherTexteEnCouleur("Solution pour gagner : ", vert, false);
            afficherTexteEnCouleur(solGrilleTaquin, vert, true);
        }

        // Saisie verif mouvJoueur
        cout << "Quel mouvement souhaitez-vous faire (a pour abandonner) ? ";
        verifMouvDebug = true;

        // recuperer et analyser mouvJoueur
        while (verifMouvDebug)
        {
            // recuperer mouvJoueur
            cin >> mouvJoueur;

            // initialiser les valeurs
            tailleMouvJoueur = static_cast<unsigned short int>(mouvJoueur.size());
            dernierCar = mouvJoueur[tailleMouvJoueur - 1];

            // creer caseSelectJoueur
            caseSelectJoueur = "";

            for (int short i = 0; i < tailleMouvJoueur - 1; i++)
            {
                caseSelectJoueur = caseSelectJoueur + mouvJoueur[i];
            }

            // analyser mouvJoueur
            switch (dernierCar)
            {
            case 'h':
                // Verifier si la réponse de l'utilisateur est cohérente pour un mouvement vers le bas de la case vide
                verifMouvVersBas(grilleTaquin, posCaseVideCol, posCaseVideLig, caseSelectJoueur, verifMouvDebug);
                break;

            case 'b':
                // Verifier si la réponse de l'utilisateur est cohérente pour un mouvement vers le haut de la case vide
                verifMouvVersHaut(grilleTaquin, posCaseVideCol, posCaseVideLig, caseSelectJoueur, verifMouvDebug);
                break;

            case 'd':
                // Verifier si la réponse de l'utilisateur est cohérente pour un mouvement vers la gauche de la case vide
                verifMouvVersGauche(grilleTaquin, posCaseVideCol, posCaseVideLig, caseSelectJoueur, verifMouvDebug);
                break;

            case 'g':
                // Verifier si la réponse de l'utilisateur est cohérente pour un mouvement vers la droite de la case vide
                verifMouvVersDroite(grilleTaquin, posCaseVideCol, posCaseVideLig, caseSelectJoueur, verifMouvDebug);
                break;

            case 'a':
                // le joueur veux abandonner

                // Modifier la valeur de verifMouvDebug
                verifMouvDebug = false;
                break;
            default:
                // gerer le cas d'erreurs

                // Afficher message d'erreur
                afficherTexteEnCouleur("Mouvement Invalide :-( ", rouge, false);

                // attendre 2s
                pause(2);
            }
        }

        // Cas ou le joueur veux abandonner
        if (dernierCar == 'a')
        {
            effacer();
            break;
        }

        // faire le mouvement sélectionné par le joueur
        switch (dernierCar)
        {
        case 'h':
            // echanger la case vers le bas
            echangerCaseVersLeBas(grilleTaquin, valCaseVide, posCaseVideCol, posCaseVideLig);
            effacer();
            break;

        case 'b':
            // echanger la case vers le haut
            echangerCaseVersLeHaut(grilleTaquin, valCaseVide, posCaseVideCol, posCaseVideLig);
            effacer();
            break;

        case 'g':
            // echanger la case vers la droite
            echangerCaseVersLaDroite(grilleTaquin, valCaseVide, posCaseVideCol, posCaseVideLig);
            effacer();
            break;

        case 'd':

            // echanger la case vers la gauche
            echangerCaseVersLaGauche(grilleTaquin, valCaseVide, posCaseVideCol, posCaseVideLig);
            effacer();
            break;
        }

        // verifier si le joueur a gagné
        verifVictoire(verifMouvDebug, posCaseActLig, posCaseActCol, NB_LIGNE, NB_COLONNE, grilleTaquin);

        // verifier si l'on peut sorti de la boucle
        if (verifMouvDebug == false)
        {
            break;
        }
    }

    // finaliser la partie
    afficherGrilleTaquin(grilleTaquin, NB_LIGNE, NB_COLONNE);
    cout << endl;
    if (dernierCar == 'a')
    {
        // afficher message d'abandon
        afficherTexteEnCouleur("Perdu par abandon :-( ", rouge, false);
    }
    else
    {
        // afficher message de réussite
        afficherTexteEnCouleur("Felicitation, vous avez gagne", vert, false);
    }
    return 0;
}