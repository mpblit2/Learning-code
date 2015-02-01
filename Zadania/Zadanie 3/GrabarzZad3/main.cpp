#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using std::list;

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;


class Rekord
{
private:
	static int _iter;
	int _id;
	string _imie;
	string _nazwisko;
	int _wiek;

public:
	Rekord()
	{
		_id = _iter;
		_imie = "";
		_nazwisko = "";
		_wiek = 0;

		_iter++;
	}

	Rekord(string imie, string nazwisko, int wiek)
	{
		_id = _iter;
		_imie = imie;
		_nazwisko = nazwisko;
		_wiek = wiek;

		_iter++;
	}

	int getId()
	{
		return _id;
	}

	string getImie()
	{
		return _imie;
	}

	string getNazwisko()
	{
		return _nazwisko;
	}

	int getWiek()
	{
		return _wiek;
	}

	void Write()
	{
		cout<<endl<<"Id:        "<<_id<<endl;
		cout<<"Imie:      "<<_imie<<endl;
		cout<<"Nazwisko:  "<<_nazwisko<<endl;
		cout<<"Wiek:      "<<_wiek<<endl;
	}

};

class BazaDanych
{
private:
	list<Rekord> _lista;

	Rekord& getRekord(int id)
	{
		for(list<Rekord>::iterator itr = _lista.begin(); itr != _lista.end(); ++itr)
		{
			if( id == itr->getId())
			{
				return *itr;
			}

			//Rekord r;

			//return r;
		}
	}

public:
	BazaDanych()
	{
	}

	~BazaDanych()
	{
	}

	int getRozmiar()
	{
		return _lista.size();
	}

	void Write()
	{

		for(list<Rekord>::iterator i = _lista.begin(); i != _lista.end(); ++i)
		{
			cout<<setw(20);
			i->Write();
			cout<<endl;
		}
	}

	void Write(int id)
	{
		Rekord *r;
		r = &getRekord(id);
		r->Write();
	}

	void Dodaj(Rekord r)
	{
		_lista.push_back(r);
	}

	void Usun(int id)
	{
		for(list<Rekord>::iterator i = _lista.begin(); i != _lista.end(); ++i)
		{
			if(i->getId() == id)
			{
				_lista.erase(i);
					break;
			}
		}
	}

	void Znajdz(string nazwisko)
	{
		int licznik = 0;

		for(list<Rekord>::iterator itr = _lista.begin(); itr != _lista.end(); ++itr)
		{			
			if(itr->getNazwisko() == nazwisko)
			{
				int c;
				itr->Write();
				licznik++;				
			}
		}

		if(!licznik)
			cout<<"Brak wynikow."<< endl;
		
		getchar();
	}

};

class Interfejs
{
private:
	BazaDanych _baza;


	void DodajUzytkownika()
	{
		string imie, nazwisko;
		int wiek;

		cout<< "Podaj imie: ";
		cin >> imie;

		cout << "Podaj nazwisko: ";
		cin >> nazwisko;

		cout << "Podaj wiek: ";
		cin >> wiek;

		Rekord r(imie, nazwisko, wiek);
		_baza.Dodaj(r);
	}

	void UsunUzytkownika()
	{
		int id;

		cout << "Podaj id uzytkownika: ";
		cin >> id;

		_baza.Usun(id);
	}

	void ZnajdzUzytkownika()
	{
		string nazwisko;

		cout << "Podaj szukane nazwisko: ";
		cin >> nazwisko;
		_baza.Znajdz(nazwisko);
	}


public:
	Interfejs()
	{
		Uruchom();
	}

	void Uruchom()
	{
		int opcja = 0;
		int nrRekordu = 1;
		bool czysc = true;
		
		do
		{
			system("cls");
			
			cout << "BAZA DANYCH OSOBOWYCH" << endl << endl;
			cout << endl << "MENU" << endl << endl;
			cout << "1. Dodaj uzytkownika."<< endl;
			cout << "2. Usun uzytkownika." << endl;
			cout << "3. Znajdz uzytkownika. " << endl;
			cout << "4. Poprzedni rekord." << endl;
			cout << "5. Nastepny rekord. " << endl;
			cout << "6. Wyjdz." << endl << endl;			

			switch(opcja)
			{
			case 1:
				this->DodajUzytkownika();
				break;
			case 2:
				this->UsunUzytkownika();
				break;
			case 3:
				czysc = false;
				this->ZnajdzUzytkownika();
				break;
			case 4:
				if(nrRekordu > 1)
					//_baza.
					nrRekordu--;
				break;
			case 5:
				if(nrRekordu < _baza.getRozmiar())
					nrRekordu++;
				break;				
			}
			
			if(_baza.getRozmiar())
			{
				cout<<"Numer rekordu: "<<nrRekordu<<endl;
				_baza.Write(nrRekordu);
			}

			cout <<endl<< "Wybierz opcje 1 - 4: ";
			cin >> opcja;

		}while(opcja != 6);

	}
};

int Rekord::_iter = 1;

int main()
{	
	
	Interfejs us;

	return 0;
}