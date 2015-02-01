// zad2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <map>
#include <algorithm>
#include <list>
#include <vector>


class DataBase
{
public:

	struct Record
	{
		int id;
		std::string name;
		std::string lastName;
		unsigned int age;

		//Record trzyma dane
		//Konstruktor domyœlny
		Record()
			:id(GenerateId())
			,age(0)
		{}
		
		//To jest konstruktor konwertuj¹cy, poniewa¿ zawiera tylko jeden argument
		//explicit zabrania niejewnaje konwersji typów
		explicit Record(int id)
			:id(id)
			, age(0)
		{

		}

		//Construktor kopiuj¹cy
		Record(const Record & rec)
		{
			id = rec.id;
			name = rec.name;
			lastName = rec.lastName;
			age = rec.age;
			
			//Ten zapis robi to samo co powy¿ej
			//*this = rec;
		}
		
		//Przeci¹¿enie operatora przypisania. Tworzyæ zawsze przy konsturktorze kopiuj¹cym
		Record& operator=(const Record& rec)
		{
			//alternatywny zapis do konstruktora powy¿ej
			return *this;
		}


	};
	
	//const daje mozliwosæ przyjmowania przez funkcjê sta³ych
	void add(const Record& rec)
	{
		//m_data[rec.id] = rec;
		m_data.insert(std::pair<const int, const Record>(rec.id, rec));
	}

	//Tworzymy funktor
	struct funct
	{
		int id;

		funct(int id)
			:id(id)
		{}

		//przeci¹¿enie operatora ()
		//Musimy zwrócic true dla pary, która ma oczekiwany przez nas id
		bool operator()(const std::pair<const int, Record>& rec)
		{
			return rec.first == id;
		}
	};

	void remove(int id)
	{
		//std::remove_if(m_data.begin(), m_data.end(), funct(id));	
		/*std::map<int, Record>::iterator it = m_data.find(id);
		if(it != m_data.end())
		{
			m_data.erase(it);
		}*/
	}

	void remove(const std::string& lastname)
	{
		for(std::map<int, Record>::iterator it = m_data.begin(); it != m_data.end();/*brak iteratora*/)
		{
			const Record& rec = it->second;
			if(rec.lastName == rec.lastName)
			{
				//erase zwraca iterator, który wskazuje na element nastêpny
				it = m_data.erase(it);
			}else
			{
				//tutaj robimy zwiekszenie iteratora
				//wtedy gdy bedziemy na ostatnim elemencie to for zakonczy dzialanie
				++it;
			}
		}
	}

	//Funkcja zwraca wskaŸnik do sta³ego obiektu, a nie referencjê gdy¿ w przypadku gdy nie znajdziemy elementu to mo¿emy zwrócic NULL (referencja nam na to nie pozwala)
	//Na tym obiekcie mo¿na bêdzie wykonaæ tylko te metody, które s¹ metodami const
	//finkcja jest const gdy¿ chcemy jedynie odczytywaæ z bazy danych
	const Record* find(const std::string& lastName) const
	{
		//Zwracamy const_iterator bo nie chcemy zmieniaæ stanu elementów na które 
		//wskazuje iterator
		for(std::map<int, Record>::const_iterator it = m_data.begin(); it != m_data.end(); ++it)
		{
			//Tam gdzie nie chcê modyfikowaæ tam lepiej uzywaæ const
			const Record& rec = it->second;

			if(rec.lastName == lastName)
			{
				return &rec;
			}

			return NULL;
		}
	}
	
	//Ta metoda zwraca wskaŸnik obiektu, który mo¿na zmieniaæ
	Record* find(const std::string& lastName)
	{
		//Zwracamy const_iterator bo nie chcemy zmieniaæ stanu elementów na które 
		//wskazuje iterator
		for(std::map<int, Record>::iterator it = m_data.begin(); it != m_data.end(); ++it)
		{
			//Tam gdzie nie chcê modyfikowaæ tam lepiej uzywaæ const
			Record& rec = it->second;

			if(rec.lastName == lastName)
			{
				return &rec;
			}

			return NULL;
		}
	}

private:
	//<typ klucza, typ danych>
	//w mapie i w secie klucze s¹ unikalne,
	std::map<int, Record> m_data;

	static int GenerateId()
	{
		static int id = 0;
		return id++;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int d[] = {3, 4, 5};
	std::list<int> l(d, d+3);
	std::vector<int> v;
	
	//back_inserter bedzie dodawa³ skopiowane wartoœci na koniec vectora
	std::copy(l.begin(), l.end(), std::back_inserter(v));

	return 0;
}

