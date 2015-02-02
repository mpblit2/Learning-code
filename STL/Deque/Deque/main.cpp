#include <iostream>
#include <conio.h>
#include <deque>
#define TRUE	1
#define FALSE	0

int main()
{
	std::deque<int> deq;
	//Wypelnianie kolejki
#pragma region Wypelnianie
	for(int i = 0; i < 10; i++)
		deq.push_back(i);
#pragma endregion
	//Dodanie elementu na koniec
#pragma region Push_back
	deq.push_back(10);
#pragma endregion
	//Dodanie elementu na pocz¹tek
#pragma region Push_front
	deq.push_front(-1);
#pragma endregion
	//Usuwanie danych z kontenera a nastepnie kopiowanie do niego okreslonych wartosci
#pragma region Assign
#if FALSE
	std::deque<int> deq1;
	deq1.assign(deq.begin() + 2, deq.begin() + 5);
	//Wypelnienie kontenera 5-oma elementami o wartosci 234
	deq1.assign(5, 234);
#endif
#pragma endregion
	//Zwracanie referencji na ostatni element kontenera
#pragma region Back
	std::cout <<"deq["<< deq.size() - 1 <<"] = "<< deq.back() << std::endl;
#pragma endregion
	//Zwracanie referencji na pierwsyz element kontenera
#pragma region Front
	std::cout << "deq[0] = " << deq.front() << std::endl;
#pragma endregion
	//Zwracanie referencji na dowolnej pozycji
#pragma region At
	std::cout << "deq[4] = " << deq.at(4) << std::endl;
#pragma endregion
	//Usuwanie wszystkich elementow z kontenera
#pragma region Clear
#if 0
	deq.clear();
#endif
#pragma endregion
	//Usuwanie wybranych elementow
#pragma region Erase
	deq.erase(deq.begin() + 3);
	//Usuwanie elementow od 3 do konca
#if FALSE
	deq.erase(deq.begin() + 3, deq.end());
#endif
#pragma endregion
	//Wstawianie elementu w dowolnym miejscu
#pragma region Insert
	deq.insert(deq.begin() + 3, 3, 5);
#pragma endregion
	//Sprawdzenie czy kontener jest pusty
#pragma region Empty
	if(deq.empty())
		std::cout << "Kontener jest pusty!" << std::endl;
	else
	{
		std::cout << std::endl;
		for(int i = 0; i < deq.size(); i++)
			std::cout << "deq[" << i << "] = " << deq.at(i) << std::endl;
	}
#pragma endregion

	_getch();
	return 0;
}