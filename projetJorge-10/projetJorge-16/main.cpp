#include "cartes.hpp"
#include "joueurs.hpp"
#include "plateau.hpp"
//DOXYGEN

int main(){
  srand(time(NULL));
  int nombreJ = 0;
  int tour = 0;
  Deck dec[52];
  remplirDeck(dec);
/*
  cout << "Nombre de joueurs desirée(entre 2 et 10)" << '\n';
  if()
  cin>>nombreJ;
*/
  Joueurs pipe[2];
  Plateau p;
//  p.setJoueurs(pipe, nombreJ)
  Joueurs miko;
  Joueurs reim;

//cartes de joueurs à aojuter avnat le switch
  miko.nouvelleCarte(p.choixDeck(dec));
  miko.nouvelleCarte(p.choixDeck(dec));
  miko.setCombinaison(miko.obtenirCarte(0));
  miko.setCombinaison(miko.obtenirCarte(1));
  reim.nouvelleCarte(p.choixDeck(dec));
  reim.nouvelleCarte(p.choixDeck(dec));
  reim.setCombinaison(reim.obtenirCarte(0));
  reim.setCombinaison(reim.obtenirCarte(1));




//attribution des cartes au board et on mets ces cartes dans le tableau de combianison
p.ajouterCarteBoard(p.choixDeck(dec));
p.ajouterCarteBoard(p.choixDeck(dec));
p.ajouterCarteBoard(p.choixDeck(dec));

for(int j = 0; j < 3; j++){
  miko.setCombinaison(p.retourBoard(j));
  reim.setCombinaison(p.retourBoard(j));
}

p.ajouterCarteBoard(p.choixDeck(dec));
miko.setCombinaison(p.retourBoard(3));
reim.setCombinaison(p.retourBoard(3));

p.ajouterCarteBoard(p.choixDeck(dec));
miko.setCombinaison(p.retourBoard(4));
reim.setCombinaison(p.retourBoard(4));

//--------------------------------------------------------------------

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
      p.afficherPlateau();
      p.setTours(p.getTours() + 1);
      break;
    case 2:
      p.afficherPlateau();
      p.setTours(p.getTours() + 1);
      break;
    case 3:
      p.afficherPlateau();
      p.setTours(p.getTours() + 1);
      break;
    default:
      cout<<"problème de jeu"<<endl;
      break;
    }
  }
}
