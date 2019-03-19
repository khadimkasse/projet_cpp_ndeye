#ifndef DEF_NOTE
#define DEF_NOTE
#include "Matiere.h"
#include <string>

class Note
{
	public : 
    Note(float noteSurVingt, Matiere* matiere);
	Note();

	float getNoteSurVingt(); 
	void setNoteSurVingt(int noteSurVingt); 
    Matiere* getMatiere();
    void setMatiere(Matiere* matiere);

	~Note();

	private : 
	float noteSurVingt; 
    Matiere* matiere;
};

#endif
