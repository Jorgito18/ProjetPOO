#include "cartes.hpp"
#include "joueurs.hpp"
#include "plateau.hpp"
//DOXYGEN
/*
void afficherDeck(Deck deck[]){
  for (int i = 0; i < 52; i++) {
    cout<<deck[i].getCarte()<<endl;
  }
}
*/
int main(){
  srand(time(NULL));
  int nombreJ = 0;
  int tour = 0;
  Deck dec[52];
  remplirDeck(dec);
/*
  cout << "Nombre de joueurs desirée" << '\n';
  cin>>nombreJ;
*/
  Joueurs pipe[2];
  Plateau p;
//  p.setJoueurs(pipe, nombreJ)
  Joueurs miko;
  Joueurs reim;
//cartes de joueurs àaojuter avnat le switch
  miko.nouvelleCarte(p.choixDeck(dec));
  miko.nouvelleCarte(p.choixDeck(dec));
  reim.nouvelleCarte(p.choixDeck(dec));
  reim.nouvelleCarte(p.choixDeck(dec));
//creation de tableau et joueurs avant settab joueurs
  pipe[0] = miko;
  pipe[1] = reim;
  pipe[0].setNum(0);
  pipe[1].setNum(1);
  int nbJoueurs = 2;
  p.setJoueurs(pipe, nbJoueurs);
  for(int i = 0; i < 4;i++) {
  switch (i) {
    case 0:
      p.afficherPlateau();
      p.setTours(p.getTours() + 1);
      break;
    case 1:
      p.ajouterCarteBoard(p.choixDeck(dec));
      p.ajouterCarteBoard(p.choixDeck(dec));
      p.ajouterCarteBoard(p.choixDeck(dec));
      p.afficherPlateau();
      p.setTours(p.getTours() + 1);
      break;
    case 2:
      p.ajouterCarteBoard(p.choixDeck(dec));
      p.afficherPlateau();
      p.setTours(p.getTours() + 1);
      break;
    case 3:
      p.ajouterCarteBoard(p.choixDeck(dec));
      p.afficherPlateau();
      p.setTours(p.getTours() + 1);
      break;
    default:
      cout<<"problème de jeu"<<endl;
      break;
  }

  }
}
