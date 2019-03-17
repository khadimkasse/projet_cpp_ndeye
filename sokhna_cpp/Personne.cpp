#include "Personne.h"
using namespace std;

Personne::Personne(std::string prenom, std::string nom, int identifiant, string numeroTelephone,
std::string dateDeNaissance, std::string adresse) {
	this->prenom = prenom; 
	this->nom = nom; 
	this->identifiant = identifiant;
    this->numeroTelephone = numeroTelephone;
	this->dateDeNaissance = dateDeNaissance;
	this->adresse = adresse;	
} 

Personne::Personne() {
    this->prenom = "";
    this->nom = "";
    this->identifiant = 0;
    this->dateDeNaissance = "";
    this->adresse = "";
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

void Personne::updateInfos(string prenom, string nom, int identifiant,
                              string numeroTelephone, string dateDeNaissance, string adresse) {
    this -> setPrenom(prenom);
    this -> setNom(nom);
    this -> setIdentifiant(identifiant);
    this -> setNumeroTelephone(numeroTelephone);
    this -> setDateDeNaissance(dateDeNaissance);
    this -> setAdresse(adresse);
}

void Personne::setIdentifiant(int identifiant){
	this->identifiant = identifiant;
}

string Personne::getNumeroTelephone(){
    return numeroTelephone;
}

void Personne::setNumeroTelephone(string nom){
    this->numeroTelephone = nom;
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


