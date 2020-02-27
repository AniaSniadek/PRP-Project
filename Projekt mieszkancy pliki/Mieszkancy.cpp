#include "Mieszkancy.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;

void Mieszkancy::dodajOsobe(Osoba *osob)
{
	for (auto p : lista)
	{
		if (p->pesel == osob->pesel)
		{
			p->miasto = osob->miasto;
			p->imie = osob->imie;
			p->nazwisko = osob->nazwisko;
			return;
		}
	}
	lista.push_back(osob);
}

void Mieszkancy::wyswietlListe()
{
	for (auto p : lista)
		cout << p->miasto << " " << p->imie << " " << p->nazwisko << " " << " " << p->pesel << '\n';
}

void Mieszkancy::sortujListe()
{
	sort(lista.begin(), lista.end(), Sortuj());
}

void Mieszkancy::zapisDoPliku()
{
	sortujListe();
	fstream plik;
	plik.open("odp.txt", ios::out | ios::trunc);
	for (auto p : lista)
		plik << p->miasto << " " << p->imie << " " << p->nazwisko << " " << " " << p->pesel << '\n';
	plik.close();
}


