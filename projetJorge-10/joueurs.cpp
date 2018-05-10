#include"joueurs.hpp"

//Constructeur par défaut: on initialise les attributs à des valeurs arbitraires
Joueurs::Joueurs(){
	for (int i=0;i<2;i++){
		_cartesJoueurs[i] = NULL;
	}

	_numJoueur = 0;
}
//-----------------------------------------------------------------
// Destructeur de la classe
Joueurs::Joueurs(const Joueurs& j){
	for (int i=0; i < 2; i++){
		_cartesJoueurs[i] = j._cartesJoueurs[i];
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
//Getter de l'attribut cartes du joueur: on retourne le tableau des cartes du joueur
Cartes Joueurs::obtenirCarte(int posCarte) const{
	return (*_cartesJoueurs[posCarte]);
}
//-----------------------------------------------------------------
//Setter de l'attribut numéro de joueur: on donne un numéro de joueur au nouveau joueur
void Joueurs::setNum(int num){
	_numJoueur = num;
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
void Joueurs::afficherJoueurs(){
	cout<<*this<<endl;
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
	while(i<2 && (j.obtenirCarte(i).getHauteur() != -1)){
		j.obtenirCarte(i).afficherCartes();
		i=i+1;
	}

	cout<<endl;
	return flux;

}
