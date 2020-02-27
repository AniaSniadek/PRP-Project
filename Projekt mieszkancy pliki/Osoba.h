#pragma once
#include <string>
using namespace std;

class Osoba
{
public:
	string miasto, imie, nazwisko, pesel;

	void wpiszOsobe();
	bool sprawdzPesel();
};

