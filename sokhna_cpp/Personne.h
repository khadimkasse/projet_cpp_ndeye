#ifndef DEF_PERSONNE
#define DEF_PERSONNE

#include <string>

class Personne
{
//méthodes
	public:

	Personne(std::string prenom, std::string nom, int identifiant, 
	std::string dateDeNaissance, std::string adresse); 
    Personne();

	std::string getPrenom(); 
	void setPrenom(std::string prenom); 
	std::string getNom(); 
	void setNom(std::string nom); 
	int getIdentifiant(); 
	void setIdentifiant(int identifiant); 
	std::string getDateDeNaissance(); 
	void setDateDeNaissance(std::string); 
	std::string getAdresse();
	void setAdresse(std::string adresse);

	~Personne();

// attributs
	private:

	std::string prenom;
	std::string nom;
	int identifiant;
	std::string dateDeNaissance; 
	std::string adresse; 
};

#endif

