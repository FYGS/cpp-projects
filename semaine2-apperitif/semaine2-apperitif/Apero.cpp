#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Apero
{
public:
	Apero();
	~Apero();

	void bis() const;
private:

};

Apero::Apero()
{
	cout << "L'heure de l'apéro a sonné !\n";
}

Apero::~Apero()
{
	cout << "A table !\n";
}

void Apero::bis() const
{
	cout << "Encore une ?\n";
}

/* Fleur*/
class Fleur
{
public:
	Fleur(string const& n, string const& c);
	Fleur(Fleur const& autre);
	~Fleur();

	void eclore() const;

private:
	string nom_;
	string couleur_;

};


Fleur::Fleur(string const& n, string const& c)
: nom_(n), couleur_(c)
{
	cout << nom_ << " fraichement cueillie\n";
}

Fleur::Fleur(Fleur const& autre)
: nom_(autre.nom_), couleur_(autre.couleur_)
{
	cout << "Fragile corolle taillée\n";
}

Fleur::~Fleur()
{
	cout << "qu'un simple souffle ...\n";
}

void Fleur::eclore() const
{
	cout << "veine de bleu\n";
}

/* Banque */
class Compte
{
public:
	enum Intitule
	{
		COURANT, EPARGNE
	};
	Compte(Intitule nom = COURANT, double solde = 0.0);
	~Compte();

	void afficher() const;
	void crediter(double somme);
	void boucler();

	Intitule intitule() const;
	double solde() const;
	double taux() const;

private:
	Intitule intitule_;
	double solde_;
	double taux_;

};

Compte::Compte(Intitule nom, double solde)
: intitule_(nom), solde_(solde)
{
	intitule_ == COURANT ? taux_ = 0.01 : taux_ = 0.02;
}

Compte::~Compte()
{
}

void Compte::afficher() const
{
	cout << "    Compte ";
	(intitule_ == COURANT) ? cout << "courant : " : cout << "epargne : ";
	cout << solde_ << " francs\n";
}

void Compte::crediter(double somme)
{
	if (somme < 0.0) somme = 0.0;

	solde_ += somme;
}

void Compte::boucler()
{
	crediter(solde_ * taux_);
}

Compte::Intitule Compte::intitule() const
{
	return intitule_;
}

double Compte::solde() const
{
	return solde_;
}

double Compte::taux() const
{
	return taux_;
}

class Client
{
public:
	Client(string const& nom, string const& ville, bool sexe = true);
	~Client();

	void afficher() const;
	void ouvrir_compte(Compte::Intitule nom);

	void boucler();

	void crediter(Compte::Intitule nom, double somme);

	string const& nom() const;

private:
	string nom_;
	string ville_;
	bool masculin_;
	vector<Compte> comptes;

};

Client::Client(string const& nom, string const& ville, bool sexe)
: nom_(nom), ville_(ville), masculin_(sexe), comptes(1, Compte())
{
}

Client::~Client()
{
}

void Client::afficher() const
{
	cout << "Client";
	if (not masculin_) cout << "e ";
	else cout << " ";
	cout << nom_ << " de " << ville_ << "\n";
	for (auto const& compte : comptes) {
		compte.afficher();
	}
}

void Client::ouvrir_compte(Compte::Intitule nom)
{
	comptes.push_back(Compte(nom));
}

void Client::boucler()
{
	for (auto& compte : comptes) {
		compte.boucler();
	}
}

void Client::crediter(Compte::Intitule nom, double somme)
{
	for (auto& compte : comptes) {
		if (compte.intitule() == nom) {
			compte.crediter(somme);
			return;
		}
	}
}

string const& Client::nom() const
{
	return nom_;
}

class Banque
{
public:
	Banque();
	~Banque();

	void ajouter_client(Client& client);
	void boucler();
	void afficher() const;

private:
	vector<Client*> clients;
};

Banque::Banque()
{
}

Banque::~Banque()
{
}

void Banque::ajouter_client(Client& quidam)
{
	for (auto const& client : clients) {
		if (client->nom() == quidam.nom()) {
			cerr << "[ERREUR] " << quidam.nom() << " deja client\n";
			exit(EXIT_FAILURE);
		}
	}

	clients.push_back(&quidam);
}

void Banque::boucler()
{
	for (auto& client : clients) {
		client->boucler();
	}
}

void Banque::afficher() const
{
	for (auto const& client : clients) {
		client->afficher();
	}
}

/* Supermarche */
class Article
{
public:
	Article(string const& article, double prix, bool solde = false);
	~Article();

	void afficher() const;
	string const& nom() const;
	double prix() const;
	bool solde() const;

private:
	const string nom_;
	double prix_unitaire_;
	bool en_solde_;

};

Article::Article(string const& article, double prix, bool solde)
: nom_(article), prix_unitaire_(prix), en_solde_(solde)
{
}

Article::~Article()
{
}

void Article::afficher() const
{
	if(en_solde_) cout << " (en action)";
	cout << "\n";
}

string const& Article::nom() const
{
	return nom_;
}

double Article::prix() const
{
	return prix_unitaire_;
}

bool Article::solde() const
{
	return en_solde_;
}

class Achat
{
public:
	Achat(Article const& article, unsigned int quant = 1);
	~Achat();

	void afficher() const;
	double total_achat() const;

private:
	Article article_achat_;
	unsigned int quantite_achat_;
};

Achat::Achat(Article const& article, unsigned int quant)
: article_achat_(article), quantite_achat_(quant)
{
}

Achat::~Achat()
{
}

void Achat::afficher() const
{
	cout << article_achat_.nom() << " : " << article_achat_.prix() << " x " << quantite_achat_ << " = " << total_achat() << " Frs"; 
	article_achat_.afficher();
}

double Achat::total_achat() const
{
	double p(article_achat_.prix() * quantite_achat_);
	if (article_achat_.solde()) p *= 0.5;
	return p;
}

class Caddie
{
public:
	Caddie();
	~Caddie();

	void remplir(Article const& article, unsigned int quantite = 1);
	double total() const;
	//void afficher() const;

private:
	vector<Achat> achats_;
};

Caddie::Caddie()
{
}

Caddie::~Caddie()
{
}

void Caddie::remplir(Article const& article, unsigned int quantite)
{
	achats_.push_back(Achat(article, quantite));
}

double Caddie::total() const
{
	double somme(0.0);
	for(auto const& achat : achats_) {
		achat.afficher();
		somme += achat.total_achat();
	}
	return somme;
}

/*void Caddie::afficher() const
{
	for (auto const& achat : achats_) {
		achat.afficher();
	}
}*/

class Caisse
{
public:
	Caisse();
	~Caisse();

	void afficher() const;
	void scanner(Caddie const& caddie);

private:
	//unsigned int numero_;
	double montal_total_;
};

Caisse::Caisse()
: montal_total_(0.0)
{
}

Caisse::~Caisse()
{
}

void Caisse::afficher() const
{
	//cout << "La caisse " << numero_ << " a encaisse " << montal_total_ << " aujourd'hui.\n";
	cout << montal_total_ << " F\n";
}

void Caisse::scanner(Caddie const& caddie)
{
	//caddie.afficher();
	double montant_caddie(caddie.total());
	montal_total_ += montant_caddie;

	cout << "-----\nTotal a payer : " << montant_caddie << " F.\n";
}


/* Main Apero */
/*int main() {
	Apero bic;
	cout << "Super !" << endl;
	bic.bis();
	cout << "Non merci." << endl;
	return 0;
}*/

/* Main Fleur */
/*int main()
{
	Fleur f1("Violette", "bleu");
	Fleur f2(f1);
	cout << "dans un cristal ";
	f2.eclore();
	cout << "Donne un poème un peu fleur bleue" << endl
		<< "ne laissant plus ";
	return 0;
}*/


/* Main Banque */
/*int main()
{
	Banque fictive;

	Client pedro("Pedro", "Genève");
	fictive.ajouter_client(pedro);
	pedro.crediter(Compte::COURANT, 1000.0);
	pedro.ouvrir_compte(Compte::EPARGNE);
	pedro.crediter(Compte::EPARGNE, 2000.0);

	Client alexandra("Alexandra", "Lausanne", false);
	fictive.ajouter_client(alexandra);
	alexandra.crediter(Compte::COURANT, 3000.0);
	alexandra.ouvrir_compte(Compte::EPARGNE);
	alexandra.crediter(Compte::EPARGNE, 4000.0);

	cout << "Données avant le bouclement des comptes :" << endl;
	fictive.afficher();
	fictive.boucler();
	cout << "Données apres le bouclement des comptes :" << endl;
	fictive.afficher();
	return 0;
}*/

/* Main Supermarche */
int main()
{
	// Les articles vendus dans le supermarché
	Article choufleur("Chou-fleur extra", 3.50);
	Article roman("Les malheurs de Sophie", 16.50, true);
	Article camembert("Cremeux 100%MG", 5.80);
	Article cdrom("C++ en trois jours", 48.50);
	Article boisson("Petit-lait", 2.50, true);
	Article petitspois("Pois surgeles", 4.35);
	Article poisson("Sardines", 6.50);
	Article biscuits("Cookies de grand-mere", 3.20);
	Article poires("Poires Williams", 4.80);
	Article cafe("100% Arabica", 6.90, true);
	Article pain("Pain d'epautre", 6.90);

	// Les caddies du supermarché, disons 3 ici
	vector<Caddie> caddies(3);

	// Les caisses du supermarché, disons 2
	vector<Caisse> caisses(2);

	// Les clients font leurs achats :
	// le second argument de la méthode remplir correspond à une quantité

	// remplissage du 1er caddie
	caddies[0].remplir(choufleur, 2);
	caddies[0].remplir(cdrom);
	caddies[0].remplir(biscuits, 4);
	caddies[0].remplir(boisson, 6);
	caddies[0].remplir(poisson, 2);

	// remplissage du 2eme caddie
	caddies[1].remplir(roman);
	caddies[1].remplir(camembert);
	caddies[1].remplir(petitspois, 2);
	caddies[1].remplir(poires, 2);

	// remplissage du 3eme caddie
	caddies[2].remplir(cafe, 2);
	caddies[2].remplir(pain);
	caddies[2].remplir(camembert, 2);

	// Les clients passent à la caisse :
	caisses[0].scanner(caddies[0]);
	cout << "=========================================" << endl;
	caisses[0].scanner(caddies[1]);
	cout << "=========================================" << endl;
	caisses[1].scanner(caddies[2]);
	cout << "=========================================" << endl;

	// Affichage du résultat des caisses
	cout << "Résultats du jour :" << endl;
	for (size_t i(0); i < caisses.size(); ++i) {
		cout << "Caisse " << i + 1 << " : ";
		caisses[i].afficher();
		cout << endl;
	}

	return 0;
}