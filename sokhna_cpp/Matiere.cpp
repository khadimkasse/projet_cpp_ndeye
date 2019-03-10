#include "Matiere.h"

using namespace std; 

Matiere::Matiere(std::string nomMatiere, int coefficient) {
	this->nomMatiere = nomMatiere; 
	this->coefficient = coefficient;
}

Matiere::Matiere() {}

Matiere::~Matiere(){}

string Matiere::getNomMatiere() {
	return nomMatiere; 
} 

void Matiere::setNomMatiere(string nomMatiere) {
	this->nomMatiere = nomMatiere;
} 

int Matiere::getCoefficient() {
	return coefficient;
}

void Matiere::setCoefficient(int coefficient) {
	this->coefficient = coefficient;
}

