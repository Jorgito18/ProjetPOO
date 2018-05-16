#include"plateau.hpp"

//Constructeur par défaut: on initialise les attributs à des valeurs arbitraires
Plateau::Plateau(){

  _tour = 0;
	_nbJoueurs = 0;

	for (int i=0;i<5;i++){

		_board[i] = NULL;

	}
	for (int i=0;i<10;i++){

		_joueurs[i] = NULL;

	}

}
//-----------------------------------------------------------------
//Constructeur par recopie: on utilise une instance de Plateau comme réference pour créer un nouvel plateau
Plateau::Plateau(const Plateau& p){

	this->_tour = p._tour;
	this->_nbJoueurs= p._nbJoueurs;

	for (int i=0;i<5;i++){
		this->_board[i] = p._board[i];
	}
	for (int i=0;i<10;i++){
		this->_joueurs[i] = p._joueurs[i];
	}
}
//-----------------------------------------------------------------
// Destructeur de la classe
Plateau::~Plateau(){

}
//-----------------------------------------------------------------
//Getter de l'attribut tour: on retourne le tour de la partie
int Plateau::getTours() const{
	return (_tour);
}
//-----------------------------------------------------------------
//Getter de l'attribut tour: on retourne le tour de la partie
int Plateau::getNbJoueurs() const{
	return (_nbJoueurs);
}
//-----------------------------------------------------------------
//Getter de l'attribut des cartes publiques: on retourne les cartes présentes au centre du plateau
Cartes* const* Plateau::getBoard() const{
	return (_board);
}
//-----------------------------------------------------------------
//Getter de l'attribut des tableau de joueurs: on retourne les cartes présentes au centre du plateau
Joueurs* const* Plateau::getJoueurs() const{
	return (_joueurs);
}
//-----------------------------------------------------------------
//Setter de l'attribut tour: on donne le tour de la partie
void Plateau::setTours(int tour){
	_tour = tour;
}
//-----------------------------------------------------------------
//Setter de l'attribut des cartes publiques: on donne les cartes présentes au centre du plateau
void Plateau::setBoard(Cartes * c){
	for (int i = 0; i < 5; i++) {
		* _board[i] = c[i];
	}
}
//-----------------------------------------------------------------
//Setter de l'attribut du deck: on donne les cartes présentes au pioche
void Plateau::setJoueurs(Joueurs * j, int nbJoueurs){
	_nbJoueurs = nbJoueurs;
	for (int i = 0; i < _nbJoueurs ; i++) {
		_joueurs[i] = &j[i];
	}
}
//-----------------------------------------------------------------
void Plateau::afficherBoard(){
  if(_tour == 1){
    int i = 0;

	  while (i < 3 && _board[i] != NULL){
	     cout << *_board[i] ;
			 i++;
	  }
  }

  if(_tour == 2){
    int i = 0;

    while (i < 4 && _board[i] != NULL){
        cout << *_board[i] ;
        i++;
     }
   }

  if(_tour == 3){
    int i = 0;

    while (i < 5 && _board[i] != NULL){
        cout << *_board[i] ;
        i++;
     }
  }
}

//-----------------------------------------------------------------
/* Fonction pour afficher le déroulement de la parie. J'ai choisi de faire un switch car c'est plus
simple à niveau de codage comparé à un if, vu queon utilise des valeurs constantes pour designer le tour.
Suivant le numéro de tour, on va appeler différentes fonctions de affichage de Cartes ou de Joueurs.
Dans chaque cas du switch, on fait un break pour sortir après l'affichage de chaque tour, et un cas par
défaut pour éviter des bugs avec des cas qui ne sont pas nominales.
*/
void Plateau::afficherPlateau(){
	switch (_tour) {
		case 0:
			cout << "===========================" << '\n';
			cout << "    PREFLOP                " << '\n';
			cout << "===========================" << '\n';
			cout << "Board :" << '\n' << '\n';
			cout << "   aucune carte " << '\n' << '\n';
			for (int i = 0; i < getNbJoueurs(); i++) {
				getJoueurs()[i]->afficherJoueurs();
        getJoueurs()[i]->afficherTabComb(_tour);
        getJoueurs()[i]->determinerComb();
			}
			break;
		case 1:
			cout << "===========================" << '\n';
			cout << "    FLOP                   " << '\n';
			cout << "===========================" << '\n';
			cout << "Board :" << '\n' << '\n';
			cout << '\t';
			afficherBoard();
			cout << '\n' << '\n';
			for (int i = 0; i < getNbJoueurs(); i++) {
				getJoueurs()[i]->afficherJoueurs();
        getJoueurs()[i]->afficherTabComb(_tour);
			}
			break;
		case 2:
			cout << "===========================" << '\n';
			cout << "    TURN                   " << '\n';
			cout << "===========================" << '\n';
			cout << "Board :" << '\n' << '\n';
			cout << '\t';
			afficherBoard();
			cout << '\n' << '\n';
			for (int i = 0; i < getNbJoueurs(); i++) {
				getJoueurs()[i]->afficherJoueurs();
        getJoueurs()[i]->afficherTabComb(_tour);
			}
			break;
		case 3:
			cout << "===========================" << '\n';
			cout << "    RIVER                  " << '\n';
			cout << "===========================" << '\n';
			cout << "Board :" << '\n' << '\n';
			cout << '\t';
			afficherBoard();
			cout << '\n' << '\n';
			for (int i = 0; i < getNbJoueurs(); i++) {
				getJoueurs()[i]->afficherJoueurs();
        getJoueurs()[i]->afficherTabComb(_tour);
			}
			break;
		default:
		 	cout << "problème avec les tours" << '\n';
			break;
	}
}
//------------------------------------------------------------------
Cartes* Plateau::retourBoard(int pos){
  return(_board[pos]);
}
//------------------------------------------------------------------
/*Fonction auxiliaire qui sert à choisir une carte quelconque du pioche.
On utilise la fonction c rand pour choisir un nombre aleatoire entre 1 et 52,
avec srand(time(NULL)) pour que la fonction ne génére toujours les mêmes cartes.
*/
Cartes Plateau::choixDeck(Deck deck[]){
  bool utilisee = false;

	Cartes choisie;
  while (!utilisee) {
    int nbRandom = rand() % 52;
    if (!deck[nbRandom].getUtilise()) {
      choisie = deck[nbRandom].getCarte();
      deck[nbRandom].setUtilise(false);
      utilisee = true;
  }
}
  return (choisie);
}


//-----------------------------------------------------------------
//Fontion pour ajouter une carte au centre du plateau
void Plateau::ajouterCarteBoard(Cartes c){
	int i = 0;
	while (i < 5){
		if (_board[i] == NULL) {
			break;
		}
			i++;
	}
  if (i != 5) {
  	_board[i] = &c;
  }
}
//----------------------------------------------------------------
//----------------------------------------------------------------
Deck::Deck(){
	_carte._hauteur = 14;
	_carte._couleur = "pique";
	_utilise = false;
}
//----------------------------------------------------------------
Deck::~Deck(){
	//_carte->setHauteur(14);
	//_carte->setCouleur("pique");
	//_utilise = false;
}
//----------------------------------------------------------------
Cartes Deck::getCarte() const{
	return (_carte);
}
//----------------------------------------------------------------
bool Deck::getUtilise() const{
	return (_utilise);
}
//----------------------------------------------------------------
void Deck::setCarte(Cartes c){
	_carte._hauteur = c.getHauteur();
	_carte._couleur = c.getCouleur();
}
//----------------------------------------------------------------
void Deck::setUtilise(bool etat){
	_utilise = etat;
}


void remplirDeck(Deck deck[]){
int n = 0;
for (int i=0;i<4;i++){
	for (int j=2;j<15;j++){
		if (i==0){

			deck[n]._carte.setHauteur(j);
			deck[n]._carte.setCouleur("coeur");
			deck[n].setUtilise(false);
			n=n+1;

		}else if (i==1){

			deck[n]._carte.setHauteur(j);
			deck[n]._carte.setCouleur("pique");
      deck[n].setUtilise(false);
			n=n+1;

		}else if (i==2){

			deck[n]._carte.setHauteur(j);
			deck[n]._carte.setCouleur("carreau");
			deck[n].setUtilise(false);
			n=n+1;

		}else if (i==3){

			deck[n]._carte.setHauteur(j);
			deck[n]._carte.setCouleur("trèfle");
			deck[n].setUtilise(false);
			n=n+1;
		}
	}
 }
}
