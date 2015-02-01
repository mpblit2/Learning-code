//Adapter kolejki priorytetowej
//Kolejka priorytetowa jest to struktura danych, w której dostêp do danych jest mo¿liwy tylko do pierwszego elementu, a dane w niej s¹ uporz¹dkowane nierosn¹co (lub niemalej¹co).

#include <queue>
#include <iostream>
#include <conio.h>

int main()
{
	int liczba;		//do przechowywania pobranej wartoœci
	//Tworzenie obiektu kolejki priorytetowej
	std::priority_queue<int> kolejkaLiczb;
	std::cout << "Podaj liczbe: ";
	std::cin >> liczba;

	//Umieszczanie nowych elementów na koñcu kolejki priorytetowej
	kolejkaLiczb.push(liczba);
	kolejkaLiczb.push(222);
	kolejkaLiczb.push(555);

	//Wyœwietlona zostanie najwiêksza wartoœæ, poniewa¿ domyœlnie dane s¹ uporz¹dkowane rosn¹co 
	//metoda top() to odczytanie wartoœci umieszczonej na pocz¹tku kolejki priorytetowej
	std::cout << "Pierwsza liczba w kolejce priorytetowej to: " << kolejkaLiczb.top() <<std::endl;

	kolejkaLiczb.push(kolejkaLiczb.top() + 55);
	std::cout << "Pierwsza liczba w kolejce priorytetowej to: " << kolejkaLiczb.top() << std::endl;

	getch();
	return 0;
}