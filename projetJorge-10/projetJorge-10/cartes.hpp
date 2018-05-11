/* La classe cartes répresente toutes les caractéristiques des cartes du jeu de poker.
La hauteur de la carte est represente par des nombres car c'est plus simple à niveaude codage,pour les cartes
dont l'hauteur n'est pas reprenté avec un nombre de 2 à 14, on fait l'équivalence dans l'opérateur de affichage
"<<" avec son nom dans le jeu (ex: le 14 est un as).
La couleur de la carte est representé par une chaine de caracteres: piques ,coeur, trèfles ou carreaux.
Cette classe suit la forme canonique de Coplien, et n'a pas de fonctions supplémentaires appart les gettes ou les
setters, et une fonction de affichage qui affiche la carte selectionnée.
Le choix de faire la classe avec la forme canonique de Coplien est pour unifier la forme des différentes classes
du programme, et rendre le code plus prope.
Les 2 premières lignes correspondent à la défense contre l'inclusion multiple, ainsi que la dernière.
*/

#ifndef _cartes_h
#define _cartes_h

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

class Cartes{
	private:
		int _hauteur;
		string _couleur;

	public:
		Cartes();
		Cartes(const Cartes& c);
		~Cartes();

		string getCouleur() const;
		int getHauteur() const;

		void setCouleur(string couleur);
		void setHauteur(int hauteur);

		void afficherCartes();
		Cartes operator=(Cartes const& c);
		friend class Deck;
};

ostream& operator<<(ostream &flux, Cartes const &c);

#endif
