#ifndef DEF_PERSONNE
#define DEF_PERSONNE

#include <string>

class Personne
{
//méthodes
	public:

    Personne(std::string prenom, std::string nom, int identifiant, std::string numeroTelephone,
	std::string dateDeNaissance, std::string adresse); 
    Personne();

	std::string getPrenom(); 
	void setPrenom(std::string prenom); 
	std::string getNom(); 
	void setNom(std::string nom); 
	int getIdentifiant(); 
    std::string getNumeroTelephone();
    void setNumeroTelephone(std::string prenom);
	void setIdentifiant(int identifiant); 
	std::string getDateDeNaissance(); 
	void setDateDeNaissance(std::string); 
	std::string getAdresse();
	void setAdresse(std::string adresse);
    void updateInfos(std::string prenom, std::string nom, int identifiant, std::string numeroTelephone,
                        std::string dateDeNaissance, std::string adresse);

	~Personne();

// attributs
	private:

	std::string prenom;
	std::string nom;
	int identifiant;
    std::string numeroTelephone;
	std::string dateDeNaissance; 
	std::string adresse; 
};

#endif

