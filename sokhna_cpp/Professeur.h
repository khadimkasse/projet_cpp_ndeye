#ifndef DEF_PROFESSEUR
#define DEF_PROFESSEUR
 
#include <iostream>
#include <string>
#include "Personne.h"
#include "Matiere.h"
class Professeur  : public Personne

{
	public:
	Professeur(std::string prenom, std::string nom, int identifiant, 
	std::string dateDeNaissance, std::string adresse, Matiere matiere, bool PaiementOk);
	Matiere getMatiere();
	void setMatiere(Matiere matiere);
	bool getPaiementOk();
	void setPaiementOk(bool paiementOk);
	~Professeur();
	
	private:
	Matiere matiere; 
	bool paiementOk;
	

};
 
#endif
