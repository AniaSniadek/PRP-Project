#include "Osoba.h"
#include <iostream>
using namespace std;

void Osoba::wpiszOsobe()
{
	cout << "Podaj miasto: ";
	cin >> miasto;
	cout << "Podaj imie, nazwisko i numer pesel: ";
	cin >> imie >> nazwisko >> pesel;
}

bool Osoba::sprawdzPesel()
{
	if (pesel.size() != 11)
		return false;

	int suma = (9 * ((pesel[0] - '0') + (pesel[4] - '0') + (pesel[8]) - '0')) + (7 * ((pesel[1] - '0') + (pesel[5] - '0') + (pesel[9] - '0'))) + (3 * ((pesel[2] - '0') + (pesel[6] - '0'))) + (pesel[3] - '0') + (pesel[7] - '0');
	int wynik = suma % 10;

	if (wynik == (pesel[10] - '0'))
		return true;
	return false;
}

