#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
 // Chaines de caractères à utiliser pour les affichages:
 /*

 été jeté

 d'un

 n'est

 L'oeuvre

 bibliothèque

 détruit

 */
class Auteur {
public:
	Auteur(string const& nom, bool prix = false);
	Auteur(Auteur const&) = delete;

	string const& getNom() const;
	bool getPrix() const;
private:
	string nom;
	bool prix;
};

Auteur::Auteur(string const& nom, bool prix)
	: nom(nom), prix(prix)
{
}

string const& Auteur::getNom() const
{
	return nom;
}

bool Auteur::getPrix() const
{
	return prix;
}
// fin Auteur

class Oeuvre {
public:
	Oeuvre(string const& titre, Auteur const& auteur, string const& langue);
	Oeuvre(Oeuvre const&) = delete; // impossible de copier une oeuvre
	~Oeuvre();

	string const& getTitre() const;
	Auteur const& getAuteur() const;
	string const& getLangue() const;

	void affiche() const;

private:
	string titre;
	Auteur const& auteur;
	string langue;
};

Oeuvre::Oeuvre(string const& titre, Auteur const& auteur, string const& langue)
	: titre(titre), auteur(auteur), langue(langue)
{
}

Oeuvre::~Oeuvre()
{
	cout << "L'oeuvre \"";
	affiche();
	cout << "\" n'est plus disponible.\n";
}

string const& Oeuvre::getTitre() const
{
	return titre;
}

Auteur const& Oeuvre::getAuteur() const
{
	return auteur;
}

string const& Oeuvre::getLangue() const
{
	return langue;
}

void Oeuvre::affiche() const
{
	cout << titre << ", " << auteur.getNom() << ", en " << langue; // sans retour (choix)
}
// fin Oeuvre

class Exemplaire {
public:
	Exemplaire(Oeuvre const& oeuvre);
	Exemplaire(Exemplaire const& autre);
	~Exemplaire();

	Oeuvre const& getOeuvre() const;
	void affiche() const;

private:
	Oeuvre const& exemplaire;
};

Exemplaire::Exemplaire(Oeuvre const& oeuvre)
	: exemplaire(oeuvre)
{
	cout << "Nouvel exemplaire de : ";
	exemplaire.affiche();
	cout << "\n";
}

Exemplaire::Exemplaire(Exemplaire const& autre)
	: exemplaire(autre.exemplaire)
{
	cout << "Copie d'un exemplaire de : ";
	exemplaire.affiche();
	cout << endl;
}

Exemplaire::~Exemplaire()
{
	cout << "Un exemplaire de \"";
	exemplaire.affiche();
	cout << "\" a été jeté !\n";
}

Oeuvre const& Exemplaire::getOeuvre() const
{
	return exemplaire;
}

void Exemplaire::affiche() const
{
	cout << "Exemplaire de : ";
	exemplaire.affiche();
	cout << endl;
}

// fin Exemplaire

class Bibliotheque {
public:
	Bibliotheque(string const& nom);
	~Bibliotheque();

	string const& getNom() const;
	void stocker(Oeuvre const& oeuvre, unsigned int nombre = 1);
	void lister_exemplaires(const string langue = "") const;
	unsigned int compter_exemplaires(Oeuvre const& oeuvre) const;
	void afficher_auteurs(bool a_prix = false) const;

private:
	string nom;
	vector<Exemplaire*> exemplaires;
};


Bibliotheque::Bibliotheque(string const& nom)
	: nom(nom)
{
	cout << "La bibliothèque " << nom << " est ouverte !\n";
}

Bibliotheque::~Bibliotheque()
{
	cout << "La bibliothèque " << nom << " ferme ses portes,\net détruit ses exemplaires : \n";


	for (auto const& ex : exemplaires) {
		delete ex;
	}

	exemplaires.clear(); // vider le vector

}

string const& Bibliotheque::getNom() const
{
	return nom;
}

void Bibliotheque::stocker(Oeuvre const& oeuvre, unsigned int nombre)
{
	for (size_t i = 0; i < nombre; i++)
	{
		exemplaires.push_back(new Exemplaire(oeuvre));
	}
}

void Bibliotheque::lister_exemplaires(const string langue) const
{
	if (langue == "") {
		for (auto const& ex : exemplaires) {
			ex->affiche();
		}
	}
	else {
		for (auto const& ex : exemplaires) {
			if (ex->getOeuvre().getLangue() == langue) {
				ex->affiche();
			}
		}
	}
}

unsigned int Bibliotheque::compter_exemplaires(Oeuvre const& oeuvre) const
{
	unsigned int nombre(0);
	for (auto const& ex : exemplaires) {
		if ( (ex->getOeuvre().getTitre() == oeuvre.getTitre()) and
			(ex->getOeuvre().getAuteur().getNom() == oeuvre.getAuteur().getNom()) and
			(ex->getOeuvre().getLangue() == oeuvre.getLangue()) ) ++nombre;
	}
	return nombre;
}

void Bibliotheque::afficher_auteurs(bool a_prix) const
{
	if (a_prix) {
		// uniquement a prix
		for (auto const& ex : exemplaires) {
			if (ex->getOeuvre().getAuteur().getPrix()) cout << ex->getOeuvre().getAuteur().getNom() << endl;
		}
	}
	else
	{
		for (auto const& ex : exemplaires) {
			cout << ex->getOeuvre().getAuteur().getNom() << endl;
		}
	}
}
// fin Bibliotheque

/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
	Auteur a1("Victor Hugo"),
		a2("Alexandre Dumas"),
		a3("Raymond Queneau", true);

	Oeuvre o1("Les Misérables", a1, "français"),
		o2("L'Homme qui rit", a1, "français"),
		o3("Le Comte de Monte-Cristo", a2, "français"),
		o4("Zazie dans le métro", a3, "français"),
		o5("The Count of Monte-Cristo", a2, "anglais");

	Bibliotheque biblio("municipale");
	biblio.stocker(o1, 2);
	biblio.stocker(o2);
	biblio.stocker(o3, 3);
	biblio.stocker(o4);
	biblio.stocker(o5);

	cout << "La bibliothèque " << biblio.getNom()
		<< " offre les exemplaires suivants :" << endl;
	biblio.lister_exemplaires();

	const string langue("anglais");
	cout << " Les exemplaires en " << langue << " sont :" << endl;
	biblio.lister_exemplaires(langue);

	cout << " Les auteurs à succès sont :" << endl;
	biblio.afficher_auteurs(true);

	cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
		<< o3.getTitre() << endl;

	return 0;
}
