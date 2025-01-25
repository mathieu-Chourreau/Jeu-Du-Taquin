/*
 Programme : Jeu du Taquin

 But :  créer un jeu complet, dans le cadre de la SAE "Comparaison d'approches algorithiques"
 Date de dernière modification : 20/01/2023
 Auteur : Nathan Piel, Mathieu Chourreau
          Nous certifions être les auteurs de ce code source et attestons ne pas avoir utilisé d'extraits de code
          provenant d'internet. Ce code source s'appuie uniquement sur les notions de programmation vues dans le
          cadre du module R1.01 - Initiation au développement partie 1 et 2.
*/

#ifndef JEUTAQUIN_H
#define JEUTAQUIN_H
#include <iostream>
using namespace std;

const unsigned short int NB_COLONNE = 4; // Nombre de colonnes de la grille du taquin
const unsigned short int NB_LIGNE = 4;   // Nombre de lignes de la grille du taquin
typedef unsigned short int Grille[NB_LIGNE][NB_COLONNE];

void afficherGrilleTaquin(Grille grilleTaquin, const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE);
// But : afficher la grille de taquin avec un nombre de ligne qui equivaut à NB_LIGNE et un nombre de colonne qui equivaut à NB_COLONNE.

void creerLaGrilleTaquin(unsigned int short posCaseVideLig, unsigned int short posCaseVideCol, Grille grilleTaquin,
                         const unsigned short int NB_COLONNE, const unsigned short int NB_LIGNE, unsigned short int valCase);
/* But : creer la grille de taquin et positionner la case vide qui est située en posCaseVideLig pour les lignes et en posCaseVideCol pour les colonnes.
Chaque valeur de la grille aura au préalable était stocké dans valCase. La grille sera toujours de taille NB_LIGNE et NB_COLONNE.
*/

char verifierMouvementVersLeHaut(char &verifMouv, unsigned short int posCaseVideCol, unsigned short int posCaseVideLig);
// But : verifier si on peut faire le mouvement vers le haut et retourne verifMouv.

char verifierMouvementVersLeBas(char &verifMouv, unsigned short int posCaseVideCol, unsigned short int posCaseVideLig,
                                const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE);
// But : verifier si on peut faire le mouvement vers le bas et retourne verifMouv.

char verifierMouvementVersLaDroite(char &verifMouv, unsigned short int posCaseVideCol, unsigned short int posCaseVideLig,
                                   const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE);
// But : verifier si on peut faire le mouvement vers la droite et retourne verifMouv.

char verifierMouvementVersLaGauche(char &verifMouv, unsigned short int posCaseVideCol, unsigned short int posCaseVideLig);
// But : verifier si on peut faire le mouvement vers la gauche et retourne verifMouv.

void echangerCaseVersLeHaut(Grille grilleTaquin, unsigned short int valCaseVide,
                            unsigned int short posCaseVideCol, unsigned int short &posCaseVideLig);
// But : echanger la case vide ( de coordonnee posCaseVidLig, posCaseVideCol ) avec la case du haut de la grille du taquin.

void echangerCaseVersLeBas(Grille grilleTaquin, unsigned short int valCaseVide,
                           unsigned int short posCaseVideCol, unsigned int short &posCaseVideLig);
// But : echanger la case vide ( de coordonnee posCaseVidLig, posCaseVideCol ) avec la case du bas de la grille du taquin.

void echangerCaseVersLaGauche(Grille grilleTaquin, unsigned short int valCaseVide,
                              unsigned int short &posCaseVideCol, unsigned int short posCaseVideLig);
// But : echanger la case vide ( de coordonnee posCaseVidLig, posCaseVideCol ) avec la case de gauche de la grille du taquin.

void echangerCaseVersLaDroite(Grille grilleTaquin, unsigned short int valCaseVide,
                              unsigned int short &posCaseVideCol, unsigned int short posCaseVideLig);
// But : echanger la case vide ( de coordonnee posCaseVidLig, posCaseVideCol ) avec la case de droite de la grille du taquin.

bool verifMouvVersBas(Grille grilleTaquin, unsigned int short &posCaseVideCol, unsigned int short &posCaseVideLig,
                      string caseSelectJoueur, bool &verifMouvDebug);
/* But : verifier si l'on peut faire le mouvement vers le bas en fonction du placement de la case vide ( poseCaaseVideLig / posCaseVideLig )
et de ce qu'à rentré l'utilisateur (caseSelectJoueur).
*/
bool verifMouvVersHaut(Grille grilleTaquin, unsigned int short &posCaseVideCol, unsigned int short &posCaseVideLig,
                       string caseSelectJoueur, bool &verifMouvDebug);
/* But : verifier si l'on peut faire le mouvement vers le haut en fonction du placement de la case vide ( poseCaaseVideLig / posCaseVideLig )
et de ce qu'à rentré l'utilisateur (caseSelectJoueur). Retourne verifMouvDebug.
*/

bool verifMouvVersGauche(Grille grilleTaquin, unsigned int short &posCaseVideCol, unsigned int short &posCaseVideLig,
                         string caseSelectJoueur, bool &verifMouvDebug);
/* But : verifier si l'on peut faire le mouvement vers la gauche en fonction du placement de la case vide ( poseCaaseVideLig / posCaseVideLig )
et de ce qu'à rentré l'utilisateur (caseSelectJoueur). Retourne verifMouvDebug.
*/

bool verifMouvVersDroite(Grille grilleTaquin, unsigned int short &posCaseVideCol, unsigned int short &posCaseVideLig,
                         string caseSelectJoueur, bool &verifMouvDebug);
/* But : verifier si l'on peut faire le mouvement vers la droite en fonction du placement de la case vide ( poseCaaseVideLig / posCaseVideLig )
et de ce qu'à rentré l'utilisateur (caseSelectJoueur). Retourne verifMouvDebug.
*/

bool verifVictoire(bool &verifMouvDebug, unsigned short int posCaseActLig, unsigned short int posCaseActCol,
                   const unsigned short int NB_LIGNE, const unsigned short int NB_COLONNE, Grille grilleTaquin);
/* But : verifie si le joueur a gagné, si toutes les cases de la grille sont rangé dans le bon ordre
et si la case vide est située dans un des 4 angles. Retourne verifMouvDebug
*/

#endif