#include <iostream>
#include <cmath>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

class Tirelire {

public:
	double getMontant() const { return montant; }
	void afficher() const {
		cout << "Vous ";
		if (montant == 0.0) cout << "etes sans le sou.\n";
		else cout << "avez : " << montant << " euros dans votre tirelire.\n";
	}

	void secouer() const {
		if (montant > 0.0) cout << "Bing bing\n";
	}

	void remplir(double mt) {
		if (mt > 0.0) montant += mt;
	}

	void vider() { montant = 0.0; }

	void puiser(double apuiser) {
		if (apuiser < 0.0) return;
		else if (apuiser > montant) vider();
		else montant -= apuiser;
	}

	bool montant_suffisant(double budget, double& solde) {
		if (budget <= 0.0) {
			solde = montant;
			return true;
		}
		else if (montant >= budget) {
			solde = montant - budget;
			return true;
		}

		solde = abs(montant - budget);
		return false;
	}

	double calculerSolde(double budget) const {
		if (budget <= 0.0) return montant;

		return montant - budget;
	}

private:
	double montant;
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
