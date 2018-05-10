/* La classe joueurs répresente toutes les caractéristiques des joueurs de poker dans le programme.
Les attributs de la classe sont le nombre de joueur et un tableau de cartes répresenatnt la
main de chaque joueur.
Le numéro de joueur est un entier de 2 à 10.
La main est un tableau de taille 7 qui represente les cartes qui possède le joueur, il contient des pointeurs
 vers la classe Cartes.
Cette classe suit la forme canonique de Coplien, et n'a pas de fonctions supplémentaires appart les gettes ou les
setters, et une fonction de affichage qui affiche la carte selectionnée.
Le choix de faire la classe avec la forme canonique de Coplien est pour unifier la forme des différentes classes
du programme, et rendre le code plus prope.
Les 2 premières lignes correspondent à la défense contre l'inclusion multiple, ainsi que la dernière.
*/

#ifndef _joueurs_h
#define _joueurs_h

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include"cartes.hpp"
using namespace std;

class Joueurs{
	private:
		Cartes * _cartesJoueurs[2];
		Cartes * _combinaison[12];
		int _numJoueur;
	public:
		Joueurs();
		Joueurs(const Joueurs& j);
		~Joueurs();
		Cartes* const* getCombinaison() const;
		int getNum() const;
		Cartes obtenirCarte(int posCarte) const ;
		void setCombinaison(Cartes * c);
		void setNum(int num);
		void nouvelleCarte(Cartes c);
		void afficherJoueurs();

};

ostream& operator<<(ostream &flux, Joueurs const &j);

#endif
