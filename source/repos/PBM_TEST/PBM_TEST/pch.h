// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

#ifndef PCH_H
#define PCH_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Pixel.h"

using namespace std;

struct Point{
	int x;
	int y;
};
struct Field {
	Point LU; //left upper
	Point RB; //right bottom
};

//ostream & operator<<(ofstream & plik, Pixel &abc);
void MazeGenerator(std::vector <std::vector <int>> &maze, int H, int W);
	void GenerateBlankMaze(std::vector <std::vector <int>> &maze, int H, int W);
	void GenerateFirstWalls(std::vector <std::vector <int>> &maze);
	void GenerateFirstExits(std::vector <std::vector <int>> &maze);
	Field GenerateFirstWorkplace(int H, int W);


	void RecursiveMaze(std::vector <std::vector <int>> &maze, Field workPlace);
		bool FieldEnoughBig(Field &workPlace);
		void SearchForExitsInMaze(std::vector <std::vector <int>> &maze, std::vector <Point> &Exits, Field &workPlace);
		void GenerateNewWalls(std::vector <std::vector <int>> &maze, std::vector <Point> &Exits, Field &workPlace);
		void GenerateNewExits(std::vector <std::vector <int>> &maze, Field &workPlace);
		void GenerateNewWorkplaces(std::vector <std::vector <int>> &maze, Field workPlaces[4], Field orginal);
			Point WallsCrossing(std::vector <std::vector <int>> &maze, Field &workPlace);
			inline int FindHorizontalWall(std::vector <std::vector <int>> &maze, Field &workPlace);
			inline int FindVerticalWall(std::vector <std::vector <int>> &maze, Field &workPlace);	
		






// TODO: w tym miejscu dodaj nagłówki, które mają być wstępnie kompilowane

#endif //PCH_H
