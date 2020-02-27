#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Przerwy
{
	int godzinaStart;
	int minutaStart;
	int dlugosc;
};

class Przerwa
{
public:
	vector <Przerwy*> przerwy;
	tm *czasAktualny;

	void dodajPrzerwe();
	bool sprawdzCzas(int &iloscMinut);
};