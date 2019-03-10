#include "Etudiant.h"
#include "Note.h"
using namespace std;

Etudiant::Etudiant(string prenom, string nom, int identifiant, string dateDeNaissance, 
string adresse, string formation, Note *notesEtudiant) : Personne(prenom, nom, 
identifiant, dateDeNaissance, adresse){
	this->formation = formation; 
	this->notesEtudiant = notesEtudiant; 	
} 

Etudiant::~Etudiant(){}

string Etudiant::getFormation() {
	return formation;
}

void Etudiant::setFormation(string formation) {
	this->formation = formation; 
}

Note* Etudiant::getNotesEtudiant() {
	return notesEtudiant;
}

void Etudiant::setNotesEtudiant(Note *notesEtudiant) {
	this->notesEtudiant = notesEtudiant; 
}
 




