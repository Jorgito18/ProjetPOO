#include"joueurs.hpp"

//Constructeur par défaut: on initialise les attributs à des valeurs arbitraires
Joueurs::Joueurs(){
	for (int i=0;i<2;i++){
		_cartesJoueurs[i] = NULL;
	}

	for (int i=0;i<7;i++){

		_combinaison[i] = NULL;

	}

	_numJoueur = 0;
}
//-----------------------------------------------------------------
// Destructeur de la classe
Joueurs::Joueurs(const Joueurs& j){
	for (int i=0; i < 2; i++){
		_cartesJoueurs[i] = j._cartesJoueurs[i];
	}
	for (int i=0;i<7;i++){
    this->_combinaison[i] = j._combinaison[i];
  }
	_numJoueur = j._numJoueur;
}
//-----------------------------------------------------------------
//Constructeur par recopie: on utilise une instance de Joueur comme réference pour créer un nouveau joueur
Joueurs::~Joueurs(){

}
//-----------------------------------------------------------------
//Getter de l'attribut numéro de joueur: on retourne le numéro de joueur de la carte
int Joueurs::getNum() const{
	return (_numJoueur);
}
//-----------------------------------------------------------------
//Getter de l'attribut des cartes publiques: on retourne les cartes présentes au centre du plateau
Cartes* const* Joueurs::getCombinaison() const{
	return (_combinaison);
}
//-----------------------------------------------------------------
//Getter de l'attribut cartes du joueur: on retourne le tableau des cartes du joueur
Cartes* Joueurs::obtenirCarte(int posCarte) const{
	return (_cartesJoueurs[posCarte]);
}
//-----------------------------------------------------------------
//Setter de l'attribut numéro de joueur: on donne un numéro de joueur au nouveau joueur
void Joueurs::setNum(int num){
	_numJoueur = num;
}
//-----------------------------------------------------------------
//Setter de l'attribut des cartes publiques: on donne les cartes présentes au centre du plateau
void Joueurs::setCombinaison(Cartes* c){
	int i = 0;
	while (i < 7){
		if (_combinaison[i] == NULL) {
			break;
		}
			i++;
	}
  if (i != 7) {
  	_combinaison[i] = c;
  }
}

//-----------------------------------------------------------------
//Setter de l'attribut cartes de joueur: on donne une carte au joueur
void Joueurs::nouvelleCarte(Cartes c){

	if (this->_cartesJoueurs[0]==NULL){
		this->_cartesJoueurs[0] = &c;

	}else if(this->_cartesJoueurs[1]==NULL){
		this->_cartesJoueurs[1] = &c;

	}else{
		cout<<"Le joueur a déjà le nombre maximum de cartes, il ne peut en avoir une autre."<<endl;
	}
}
//-----------------------------------------------------------------
//Je pense que c'est inutile cette fonction
void Joueurs::afficherTabComb(int tour){
	cout << "Ensemble de cartes: ";
	if(tour == 0){
	    int i = 0;

	    while (i < 2 && _combinaison[i] != NULL){
	       cout << *_combinaison[i] ;
	       i++;
	    }
	  }
	if(tour == 1){
	    int i = 0;

	    while (i < 5 && _combinaison[i] != NULL){
	       cout << *_combinaison[i] ;
	       i++;
	    }
	  }

	  if(tour == 2){
	    int i = 0;

	    while (i < 6 && _combinaison[i] != NULL){
	        cout << *_combinaison[i] ;
	        i++;
	     }
	   }

	  if(tour == 3){
	    int i = 0;

	    while (i < 7 && _combinaison[i] != NULL){
	        cout << *_combinaison[i] ;
	        i++;
	     }
	  }
	cout << '\n' << '\n' ;
}
//-----------------------------------------------------------------
//Je pense que c'est inutile cette fonction
void Joueurs::afficherJoueurs(){
	cout<<*this<<endl;
}
//-----------------------------------------------------------------
//Je pense que c'est inutile cette fonction
void Joueurs::determinerComb(){
	int i = 0;
	int comptage = 0;
	bool test = false;

	while (i<7 && _combinaison[i] != NULL) {
		i++;
	}

	if(i = 2 && _combinaison[0]->getHauteur() == _combinaison[1]->getHauteur()){
		cout << '\t' << "Paire de ";
	  afficherComb(_combinaison[0]);

	}else if(i = 2){
		if(_combinaison[0]->getHauteur() > _combinaison[1]->getHauteur()){
			cout << '\t' << "Hauteur ";
			afficherComb(_combinaison[0]);
		}
		else{
			cout << '\t' << "Hauteur ";
			afficherComb(_combinaison[1]);
		}
	}
}
//Je pense que c'est inutile cette fonction
void Joueurs::afficherComb(Cartes* c){
	if (c->getHauteur()<11){

		cout <<c->getHauteur() <<'\n';

	}else if (c->getHauteur()==11){

		cout <<"Valet " << '\n';

	}else if (c->getHauteur()==12){

		cout <<"Dame" << '\n';

	}else if (c->getHauteur()==13){

		cout <<"Roi" << '\n';

	}else if (c->getHauteur()==14){

		cout <<"As" << '\n';

	}
}
//-----------------------------------------------------------------
/*Rédefinition de l'operateur de affichage: pour un joueur donnée.
On affiche son numéro, et puis pour l'affichage de ses cartes, on fait appel aux getters
des attributs et à la fonction afficherJoueurs pour arriver à faire un affichage comme
celui qui est demandé.
*/
ostream& operator<<( ostream &flux, Joueurs const& j){

	int i=0;
	cout<<"Joueur "<<j.getNum()<<" :"<< '\n'<< '\n';
	while(i<2 && (j.obtenirCarte(i)->getHauteur() != -1)){
		j.obtenirCarte(i)->afficherCartes();
		i=i+1;
	}

	cout<<endl;
	return flux;

}
