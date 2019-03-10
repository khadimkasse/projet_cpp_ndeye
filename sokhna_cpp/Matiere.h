#ifndef DEF_MATIERE
#define DEF_MATIERE

#include <string>

class Matiere
{
	public : 
	Matiere(std::string nomMatiere, int coefficient);
	Matiere();
	std::string getNomMatiere(); 
	void setNomMatiere(std::string nomMatiere); 
	int getCoefficient(); 
	void setCoefficient(int coefficient);

	~Matiere();

	private : 
	std::string nomMatiere; 
	int coefficient;
};
#endif