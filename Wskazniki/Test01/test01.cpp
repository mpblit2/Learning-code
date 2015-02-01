#include<iostream>

using std::cout;
using std::endl;

void funkcja1(int* pint);

int main(void)
{
	int liczba = 0;

	cout<<endl
		<<"Zmienna o adresie: "<<&liczba
		<<" ma wartosc: "<<liczba;

	funkcja1(&liczba);

	cout<<endl
		<<"Teraz zmienna o adresie: "<<&liczba<<" ma wartosc: "<<liczba;

	getchar();
	return 0;
}

void funkcja1(int* pint)
{
	cout<<endl
		<< "Adres zmiennej przekazanej do funkcji to: "<<pint;
	*pint = 10;
	return;
}