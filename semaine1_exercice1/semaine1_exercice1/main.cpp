// semaine1_exercice1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Cercle.h"

int main()
{
	Cercle cercle1, cercle2;

	cercle1.setRayon(5.0);
	cercle1.setCentre(Point(1.0, 2.0));

	cercle2.setRayon(4.0);
	cercle2.setCentre(0.9, 1.9);

    std::cout << "Cercle1: rayon " << cercle1.getRayon() << " centre (x=" << cercle1.getCentre().getX() << ", y=" << cercle1.getCentre().getY() << ") surface: " << cercle1.surface() << " "
		      << "\nCercle2: rayon " << cercle2.getRayon() << " centre (x=" << cercle2.getCentre().getX() << ", y=" << cercle2.getCentre().getY() << ") surface: " << cercle2.surface() << "\n";

	std::cout << "Le point p(0.9, 1.9) est interieur au cercle1: " << cercle1.estInterieur(Point(0.9, 1.9)) << "\n";
	std::cout << "Le point p(2.0, 1.9) est interieur au cercle1: " << cercle1.estInterieur(Point(2.0, 1.9)) << "\n";
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
