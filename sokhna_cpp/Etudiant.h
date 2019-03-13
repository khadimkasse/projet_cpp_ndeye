#ifndef DEF_ETUDIANT
#define DEF_ETUDIANT
 
#include <iostream>
#include <string>
#include <vector>
#include "Personne.h"
#include "Note.h"
//Ne pas oublier d'inclure Personne.h pour pouvoir en hériter !
 
class Etudiant : public Personne
//Signifie : créer une classe Etudiant qui hérite de la classe Personne
{
	public:
	Etudiant(std::string prenom, std::string nom, int identifiant, 
	std::string dateDeNaissance, std::string adresse, std::string formation, 
	Note *notesEtudiant);// A TESTER : tableau de notes OK ? //Etudiant(Personne personne, std::string formation, Note *notesEtudiant)
    Etudiant(std::string prenom, std::string nom, int identifiant,
    std::string dateDeNaissance, std::string adresse, std::string formation);
    std::string getFormation();
    Etudiant();
	void setFormation(std::string formation);
	Note *getNotesEtudiant(); // a tester le placement du *
	void setNotesEtudiant(Note *notesEtudiant);
	~Etudiant();

	private:
	std::string formation; 
	Note *notesEtudiant;
	

};
 
#endif
