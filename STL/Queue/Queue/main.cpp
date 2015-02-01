//Adapter kolejki priorytetowej
//Kolejka priorytetowa jest to struktura danych, w kt�rej dost�p do danych jest mo�liwy tylko do pierwszego elementu, a dane w niej s� uporz�dkowane nierosn�co (lub niemalej�co).

#include <queue>
#include <iostream>
#include <conio.h>

int main()
{
	int liczba;		//do przechowywania pobranej warto�ci
	//Tworzenie obiektu kolejki priorytetowej
	std::priority_queue<int> kolejkaLiczb;
	std::cout << "Podaj liczbe: ";
	std::cin >> liczba;

	//Umieszczanie nowych element�w na ko�cu kolejki priorytetowej
	kolejkaLiczb.push(liczba);
	kolejkaLiczb.push(222);
	kolejkaLiczb.push(555);

	//Wy�wietlona zostanie najwi�ksza warto��, poniewa� domy�lnie dane s� uporz�dkowane rosn�co 
	//metoda top() to odczytanie warto�ci umieszczonej na pocz�tku kolejki priorytetowej
	std::cout << "Pierwsza liczba w kolejce priorytetowej to: " << kolejkaLiczb.top() <<std::endl;

	kolejkaLiczb.push(kolejkaLiczb.top() + 55);
	std::cout << "Pierwsza liczba w kolejce priorytetowej to: " << kolejkaLiczb.top() << std::endl;

	getch();
	return 0;
}