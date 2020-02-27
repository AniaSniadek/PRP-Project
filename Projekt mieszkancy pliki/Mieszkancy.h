#pragma once
#include "Osoba.h"
#include <vector>
#include <string>
using namespace std;

struct Sortuj
{
	bool operator() (Osoba* &o1, Osoba* &o2)
	{
		return (o1->miasto < o2->miasto);
	}
};

class Mieszkancy
{
public:
	vector <Osoba*> lista;

	void dodajOsobe(Osoba *osob);
	void wyswietlListe();
	void sortujListe();
	void zapisDoPliku();
};

