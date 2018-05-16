#include"cartes.hpp"

//Constructeur par défaut: on initialise les attributs à des valeurs arbitraires
Cartes::Cartes(){
	_couleur = "pique";
	_hauteur = 14;
}
//-----------------------------------------------------------------
// Destructeur de la classe
Cartes::~Cartes(){

}
//-----------------------------------------------------------------
//Constructeur par recopie: on utilise une instance de Carte comme réference pour créer une nouvelle carte
Cartes::Cartes(const Cartes& c){

	_couleur = c.getCouleur();
	_hauteur = c.getHauteur();
}
//-----------------------------------------------------------------
//Getter de l'attribut couleur: on retourne la couleur de la carte
string Cartes::getCouleur()const{

	return (this->_couleur);
}
//-----------------------------------------------------------------
//Getter de l'attribut hauteur: on retourne la hauteur de la carte
int Cartes::getHauteur()const{

	return (this->_hauteur);
}
//-----------------------------------------------------------------
//Setter de l'attribut couleur: on donne une couleur à la carte
void Cartes::setCouleur(string couleur){

	if ((couleur == "coeur") || (couleur == "pique") || (couleur == "carreau") || (couleur == "trèfle")){

		this->_couleur = couleur;

	}else{

  this->_couleur = "";

	}
}
//-----------------------------------------------------------------
//Setter de l'attribut hauteur: on donne une hauteur à la carte
void Cartes::setHauteur(int hauteur){

if ((hauteur >= 2) && (hauteur <= 14)){

		this->_hauteur = hauteur;

	}else{

  this->_hauteur = 0;

	}
}
//-----------------------------------------------------------------
//Je pense que c'est inutile cette fonction
void Cartes::afficherCartes(){

	cout<< '\t' <<*this;

}
//-----------------------------------------------------------------
/*Rédefinition de l'operateur de affichage: pour une carte donnée,on vérifie d'abord si elle est valide.
On affiche sa couleur, et puis pour l'affichage de sa hauteur, on fait l'équivalence entre son nombre dans
le programme et son nom dans le jeu. J'ai choisi de faire ça ac c'est plus simple à niveaude codage, le 14
c'est l'as car c'est plus simple pour faire la condition de vérification de la carte(premier if de la fonction).
*/
ostream& operator<<( ostream &flux, Cartes const& c){

if (c.getHauteur()<2 or c.getHauteur()>14 or c.getCouleur() == "") {

	cout<< "carte non valide";

}else if (c.getHauteur()<11){

	cout<<c.getHauteur();
	cout<<"_de_";
	cout<<c.getCouleur()<<" ";

}else if (c.getHauteur()==11){

	cout<<"Valet_de_";
	cout<<c.getCouleur()<<" ";

}else if (c.getHauteur()==12){

	cout<<"Dame_de_";
	cout<<c.getCouleur()<<" ";

}else if (c.getHauteur()==13){

	cout<<"Roi_de_";
	cout<<c.getCouleur()<<" ";

}else if (c.getHauteur()==14){

	cout<<"As_de_";
	cout<<c.getCouleur()<<" ";
}

	return flux;

}

//-----------------------------------------------------------------
/*Redefinition de l'opérateur de affectation: on modifie cet opérateur pour le adapter à son usage dasn spécial
dans le programme. On rentre en paramètre la carte qu'on veux copier, et on affecte la hauteur et couleur à la
nouvelle carte.
*/
Cartes Cartes::operator=(Cartes const& c){

	this->_hauteur=c._hauteur;
	this->_couleur=c._couleur;

	return(*this);
}
