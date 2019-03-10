#include <iostream>
#include "Personne.h"
#include "Etudiant.h"
#include "Professeur.h"
#include "Note.h"
#include "Matiere.h"
using namespace std;

int main()
{
	Matiere matiere1("Systeme Embarqué", 3);
	Matiere matiere2("Antenne", 6);
	Note note1Etudiant1();
	Note note2Etudiant1();
	Note note1Etudiant2();
	Note note2Etudiant2();
	Note notesEtudiant1[10]; 
	notesEtudiant1[0] = note1Etudiant1;
	/*notesEtudiant1[1] = note2Etudiant1;
	Note notesEtudiant2[10]; 
	notesEtudiant2[0] = note1Etudiant2;
	notesEtudiant2[1] = note2Etudiant2;*/
	/*Etudiant etudiant1("Ndeye Sokhna", "NDIAYE", 21613234, "20/02/1993", 
	"73 Avenue S V", "M2 ESTel", note1Etudiant1);*/
	/*Etudiant etudiant2("cheikh", "KASSÉ", 25854521, "08/02/1994", "73 Avenue S V", 
	"M2 ESTel", note1Etudiant2);*/
	//Professeur professeur("Alioune", "KASSÉ", 22427589, "13/08/1989", "Marseille");
	//Note notesEtudiant()
  	//cout << produit << endl;
	//Matiere matiere; 
	// cout << "Voci le coefficient de la matière" << endl;
	//  cout << matiere.getCoefficient() << endl;
  return 0;
}
 