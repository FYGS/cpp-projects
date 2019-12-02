#include <iostream>
#include <string>
using namespace std;

class Souris
{
	/*****************************************************
	  Compléter le code �  partir d'ici
	*******************************************************/
public:


	Souris(double poids, string const& couleur, unsigned int age = 0, unsigned int esperance_vie = 36)
		:poids(poids), couleur(couleur), age(age), esperance_vie(esperance_vie), clonee(false)
	{
		cout << "Une nouvelle souris !\n";
	}

	Souris(Souris const& autre)
		: poids(autre.poids), couleur(autre.couleur), age(autre.age), esperance_vie((autre.esperance_vie * 4) / 5), clonee(true)
	{
		cout << "Clonage d'une souris !\n";
	}

	~Souris()
	{
		cout << "Fin d'une souris...\n";
	}

	void afficher() const
	{
		/*if (clonee) {
			if (age > (esperance_vie / 2)) {
				couleur = "verte";
			}
		}*/
		
		cout << "Une souris " << couleur;
		if (clonee) cout << ", clonee,";
		cout << " de " << age << " mois et pesant " << poids << " grammes\n";
	}

	void vieillir()
	{
		age += 1;
		if (clonee) {
			if (age > (esperance_vie / 2)) {
				couleur = "verte";
			}
		}

	}

	void evolue()
	{
		while (age < esperance_vie)
		{
			vieillir();
		}
	}

private:
	double poids;
	string couleur;
	unsigned int age;
	unsigned int esperance_vie;
	bool clonee;
	/*******************************************
	 * Ne rien modifier après cette ligne.
	 *******************************************/

}; // fin de la classe Souris

/*int main()
{
	Souris s1(50.0, "blanche", 2);
	Souris s2(45.0, "grise");
	Souris s3(s2);
	// ... un tableau peut-être...
	s1.afficher();
	s2.afficher();
	s3.afficher();
	s1.evolue();
	s2.evolue();
	s3.evolue();
	s1.afficher();
	s2.afficher();
	s3.afficher();
	return 0;
}*/