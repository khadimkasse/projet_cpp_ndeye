#include "Professeur.h"
using namespace std;

Professeur::Professeur(string prenom, string nom, int identifiant, string numeroTelephone,
string dateDeNaissance, string adresse, Matiere matiere, 
bool PaiementOk) : Personne(prenom, nom, identifiant, numeroTelephone, dateDeNaissance, adresse){
	this->matiere = matiere; 
	this->paiementOk = paiementOk; 
}

Professeur::~Professeur() {}	

Matiere Professeur::getMatiere() {
	return matiere;
}

void Professeur::setMatiere(Matiere Matiere) {
	this->matiere= matiere; 
}

bool Professeur::getPaiementOk() {
	return paiementOk;
}

void Professeur::setPaiementOk(bool PaiementOk) {
	this->paiementOk= paiementOk; 
}



 	
 
