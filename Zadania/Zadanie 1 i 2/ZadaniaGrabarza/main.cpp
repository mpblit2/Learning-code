#include <vector>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

enum kierunekSortowania
{
	rosnaco, 
	malejaco
};

void Sortuj(vector<int>::iterator begin, vector<int>::iterator end, kierunekSortowania kierunek);

int main()
{
	int rozmiarVectora = 0;
	int wartosc = 0;
	char rodzajSorotowania;
	std::vector<int> tab;

	cout<<"Podaj ilosc elementow vectora: ";
	cin >> rozmiarVectora;

	for(int i = 0; i < rozmiarVectora; i++)
	{
		cout<< endl << "Podaj " << i + 1 << " wartosc: ";
		cin >> wartosc;
		
		tab.push_back(wartosc);
	}

	cout << " r - aby posorotowac rosnaco" << endl;
	cout << " m - aby posortowac malejaco" << endl;
	cout << "Podaj rodzaj: ";
	cin >> rodzajSorotowania;

	switch(rodzajSorotowania)
	{
	case 'r':
		Sortuj(tab.begin(), tab.end(), rosnaco);
		break;
	case 'm':
		Sortuj(tab.begin(), tab.end(), malejaco);
	}

	for(int i = 0; i < tab.size(); i++)
	{		
		cout << tab[i] << endl;
	}
	
	getchar();

	getchar();
	return 0;
}

void Sortuj(vector<int>::iterator begin, vector<int>::iterator end, kierunekSortowania kierunek)
{
	switch(kierunek)
	{
	case rosnaco:
		for(vector<int>::iterator i = begin + 1; i != end; i++)
				for(vector<int>::iterator j = i; j > begin && *j < *(j -1); --j)
					std::iter_swap((j-1), j);
		break;

	case malejaco:
		for(vector<int>::iterator i = begin + 1; i != end; i++)
		for(vector<int>::iterator j = i; j > begin && *j > *(j -1); --j)
			std::iter_swap((j-1), j);
		break;
	}
}