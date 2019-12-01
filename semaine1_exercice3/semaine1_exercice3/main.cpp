// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Point3D.h"

using namespace std;

int main()
{
	Point3D point1, point2, point3;

	point1.init(1.0, 2.0, -0.1);
	point2.init(2.6, 3.5, 4.1);
	point3 = point2;

	cout << "Point 1 :";
	point1.affiche();
	cout << "Point 2 :";
	point2.affiche();
	cout << "Point 3 :";
	point3.affiche();
	cout << "Le point 1 est ";
	if (point1.compare(point2)) {
		cout << "identique au";
	}
	else {
		cout << "different du";
	}
	cout << " point 2." << endl;
	cout << "Le point 2 est ";
	if (point2.compare(point3)) {
		cout << "identique au";
	}
	else {
		cout << "different du";
	}
	cout << " point 3." << endl;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
