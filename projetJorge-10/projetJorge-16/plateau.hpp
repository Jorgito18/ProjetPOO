/* La classe plateau répresente le deck du jeu de poker, la table où tout se déroule.
Les attributs de la classe sont le tour de jeu, la table de cartes publiques et le tableau qui represente le pioche.
Le tour est un entier de 1 à 5.
Le pioche est un tableau de Cartes de taille 52 qui represente l'ensemble de toutes les cartes du jeu.
Les cartes publiques sont representes par uiun tableau de Cartes de taille 5.
Cette classe suit la forme canonique de Coplien. Elle contient en plus des méthodes pour gérer le don de cartes
dans chaque tour et comment gérer le pioche.
Le choix de faire la classe avec la forme canonique de Coplien est pour unifier la forme des différentes classes
du programme, et rendre le code plus prope.
Les 2 premières lignes correspondent à la défense contre l'inclusion multiple, ainsi que la dernière.
*/
#ifndef _plateau_h
#define _plateau_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
#include "joueurs.hpp"

using namespace std;

class Deck{
	private:
		Cartes _carte;
		bool _utilise;
	public:
		Deck();
		~Deck();
		Cartes getCarte() const;
		bool getUtilise() const;
		void setCarte(Cartes c);
		void setUtilise(bool etat);
		friend void remplirDeck(Deck deck[]);

};

class Plateau{
	private:
		  Cartes * _board[5];
		  int _tour;
			Joueurs * _joueurs[10];
			int _nbJoueurs;

	public:
    	Plateau();
    	Plateau(const Plateau& p);
    	~Plateau();
    	int getTours() const;
			int getNbJoueurs() const;
    	Cartes* const* getBoard() const;
			Joueurs* const* getJoueurs() const;
      void setTours(int tour);
      void setBoard(Cartes * c);
			void setJoueurs(Joueurs * j, int nbJoueurs);
			void afficherBoard();
		  void afficherPlateau();
			void ajouterCarteBoard(Cartes c);
			Cartes* retourBoard(int pos);
			Cartes choixDeck(Deck deck[]);
			friend class Deck;
};

#endif
