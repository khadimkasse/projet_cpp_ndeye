#include "Etudiant.h"
#include "Note.h"
using namespace std;

Etudiant::Etudiant(string prenom, string nom, int identifiant, string numeroTelephone,
string dateDeNaissance, string adresse, string formation, Note *notesEtudiant) : Personne(prenom, nom,
identifiant, numeroTelephone, dateDeNaissance, adresse){
	this->formation = formation; 
    this->notesEtudiant = notesEtudiant;
} 

Etudiant::Etudiant(std::string prenom, std::string nom, int identifiant, string numeroTelephone,
std::string dateDeNaissance, std::string adresse, std::string formation):
    Personne(prenom, nom, identifiant, numeroTelephone, dateDeNaissance, adresse){
    this->formation = formation;
    /*Note defaultNotesEtudiant[10];
    this->notesEtudiant = defaultNotesEtudiant;*/
}
Etudiant::Etudiant() : Personne() {
    this->formation = "";
    /*Note defaultNotesEtudiant[10];
    this->notesEtudiant = defaultNotesEtudiant;*/
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
 
void Etudiant::updateInfos(string prenom, string nom, int identifiant,
                              string numeroTelephone, string dateDeNaissance, string adresse,
                              string formation) {
        Personne::updateInfos(prenom, nom, identifiant, numeroTelephone, dateDeNaissance, adresse);
        this -> setFormation(formation);
}




