
#include <vector>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <algorithm>
#include <string>

using namespace std;

#pragma region KlasaCz³owiek
class Czlowiek
{
public:
	string imie;
	string nazwisko;
	string numer;

	Czlowiek(string imie, string nazwisko, string numer);

};
#pragma endregion


int main()
{
	//Umieszczanie wartoœæi w vectorze
#pragma region Example01
#if FALSE
	std::vector<int> tab;

	int x = 0;
	for (int i = 0; i < 10; i++)
	{
		tab.push_back(x);
		x += 2;
	}

	for (int i = 0; i < tab.size(); i++)
		std::cout << tab[i] << std::endl;
#endif	
#pragma endregion
	//Zapisywanie danych do pojemnika przy u¿yciu funkcji insert
#pragma region Example02
#if FALSE
	std::vector<int> tab;
	srand(time(NULL));

	tab.push_back(0);
	tab.push_back(1);
	for (int i = 5; i < 7; i++)
	{
		int gdzie = rand();
		std::cout << "Gdzie = " << gdzie;
		gdzie %= tab.size();
		std::cout << " Rozmiar = " << tab.size() << " Gdzie = " << gdzie << std::endl;
		tab.insert(tab.begin() + gdzie, i);
	}

	for (int i = 0; i < tab.size(); i++)
	{
		std::cout << "tab[" << i << "] = " << tab[i] << std::endl;
	}
#endif
#pragma endregion
	//Zapisywanie danych do pojemnika - metoda Insert
#pragma region Example03
#if FALSE
	
	std::vector<int> tab;
	tab.push_back(0);
	tab.push_back(1);
	tab.push_back(2);
	tab.push_back(3);
	tab.push_back(4);
	tab.insert(tab.end(), 5);
	//tab.insert(tab.begin() + 1, 6);

	for (int i = 0; i < tab.size(); i++)
	{
		std::cout << "tab[" << i <<"] = " << tab[i] << std::endl;
	}
#endif
#pragma endregion
	//Sortowanie zawartoœci vector'a przy u¿yciu algorithm
#pragma region Example04
#if FALSE
	std::vector<int> tab;

	tab.push_back(0);
	for (int i = 1; i < 10; i++)
	{
		int gdzie = rand() % tab.size();
		tab.insert(tab.begin() + gdzie, i);
	}
	
	//sortowanie vector'a
	sort(tab.begin(), tab.end());
	for (int i = 0; i < tab.size(); i++)
		std::cout << tab[i] << std::endl;
#endif
#pragma endregion
	//Tworzenie tablicy obiektów w³asnej klasy
#pragma region Example05
#if FALSE
	vector<Czlowiek> osoba;
	char odp;
	

	do
	{
		string odpImie = "", odpNazwisko = "", odpNumer = "";
		cout << "\nBaza Osob\n1.-Lista osob\n2.-Dodaj osobe\n3.-Wyjscie";
		cout << "\n\nOpcja: ";


		odp = _getch();
		switch (odp)
		{
		case '1':
			cout << "\n\n\nLista osob:\n";
			for (int i = 0; i < osoba.size(); i++)
			{
				cout << endl;
				cout << "Imie: " << osoba[i].imie << endl;
				cout << "Nazwisko: " << osoba[i].nazwisko << endl;
				cout << "Numer tel.: " << osoba[i].numer << endl;
			}
			break;
			
		case '2':
			cout << "\n\n\n|----DODAWANIE_OSOBY_DO_LISTY------|";
			cout << "\nPodaj imie: ";
			cin >> odpImie;
			cout << "\nPodaj nazwisko: ";
			cin >> odpNazwisko;
			cout << "\nPodaj numer telefonu: ";
			cin >> odpNumer;
			osoba.push_back(Czlowiek(odpImie, odpNazwisko, odpNumer));
			break;
		}
	} while (odp != '3');
#endif
#pragma endregion
	//Inne funkcje vector'a
#pragma region Example06
#if FALSE
	vector<int> tab;
	//zape³nianie vectora przypadkowymi liczbami
	cout << "----Uzupe³nianie vectora----" << endl;
	for (int i = 0; i < 12; i++)
		tab.push_back(rand() % 100);

	for (int i = 0; i < tab.size(); i++)
		cout << tab[i] << endl;
	//sortowanie zawartoœci vectora
#pragma region sort
	cout << "----Sortowanie----" << endl;
	sort(tab.begin(), tab.end());
	for (int i = 0; i < tab.size(); i++)
		cout << tab[i] << endl;
#pragma endregion
	//œci¹ganie ostatniej wartoœci z vectora
#pragma region pop_back
	cout << "----Sciaganie ostatniej wartosci z vectora----" << endl;
	tab.pop_back();
	for (int i = 0; i < tab.size(); i++)
		cout << tab[i] << endl;
#pragma endregion
	//Zmiana rozmiaru vectora
#pragma region resize
	cout << "----Zmiana rozmiaru vectora----" << endl;
	tab.resize(8);
	for (int i = 0; i < tab.size(); i++)
		cout << tab[i] << endl;
#pragma endregion
	//Usuwanie wybranego elementu vectora
#pragma region erase
	cout << "----Usuwanie wybranych elementow vectora----" << endl;
	//usuwanie pierwszego elementu
	tab.erase(tab.begin());
	//usuwanie elementów od 3 i 4
	tab.erase(tab.begin() + 2, tab.begin() + 4);
	for (int i = 0; i < tab.size(); i++)
		cout << tab[i] << endl;
#pragma endregion
	//Czyszczenie ca³ego vectora
#pragma region clear
	cout << "----Czyszczenie vectora----" << endl;
	tab.clear();
	for (int i = 0; i < tab.size(); i++)
		cout << tab[i] << endl;
#pragma endregion
#endif
#pragma endregion
	//Uzycie iteratora
#pragma region Example07
	vector<int> tab;
	for (int i = 0; i < 10; i++)
		tab.push_back(i);

	for (vector<int>::iterator itr = tab.begin(); itr != tab.end();)
	{
		if (!(*itr % 2))
			itr = tab.erase(itr);
		else
			++itr;
	}
	
	for (vector<int>::iterator itr = tab.begin(); itr != tab.end(); ++itr)
		cout << *itr << endl;

#pragma endregion

	_getch();
	return 0;
}

#pragma region KlasaCz³owiek
Czlowiek::Czlowiek(string imie, string nazwisko, string numer)
	: imie(imie)
	, nazwisko(nazwisko)
	, numer(numer)
{}
#pragma endregion


