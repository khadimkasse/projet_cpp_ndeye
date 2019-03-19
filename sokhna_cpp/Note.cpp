#include "Note.h"

using namespace std;

Note::Note(float noteSurVingt, Matiere* matiere) {
	this->noteSurVingt = noteSurVingt; 
	this->matiere = matiere;
}

Note::Note() {}

Note::~Note() {}

float Note::getNoteSurVingt() {
	return noteSurVingt; 
}
void Note::setNoteSurVingt(int noteSurVingt) {
	this->noteSurVingt = noteSurVingt; 
}
Matiere* Note::getMatiere() {
	return matiere; 
} 
void Note::setMatiere(Matiere* matiere) {
	this->matiere = matiere; 
}
