#include "Personne.h"
using namespace std;

Personne::Personne(std::string prenom, std::string nom, int identifiant, 
std::string dateDeNaissance, std::string adresse) {
	this->prenom = prenom; 
	this->nom = nom; 
	this->identifiant = identifiant;
	this->dateDeNaissance = dateDeNaissance;
	this->adresse = adresse;	
} 

Personne::~Personne() {}

string Personne::getPrenom() {
	return prenom;
}

void Personne::setPrenom(string prenom) {
	this->prenom = prenom; 
}

string Personne::getNom(){
	return nom;
}

void Personne::setNom(string nom){
	this->nom = nom;
}

int Personne::getIdentifiant(){
	return identifiant;
}

void Personne::setIdentifiant(int identifiant){
	this->identifiant = identifiant;
}

string Personne::getDateDeNaissance(){
	return dateDeNaissance;
}

void Personne::setDateDeNaissance(string dateDeNaissance){
	this->dateDeNaissance = dateDeNaissance; 
}

string Personne::getAdresse() {
	return adresse; 
}

void Personne::setAdresse(string adresse) {
	this->adresse = adresse; 
}


