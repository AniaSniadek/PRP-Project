#include "Przerwa.h"
using namespace std;

void Przerwa::dodajPrzerwe()
{
	Przerwy* p1 = new Przerwy();
	p1->godzinaStart = 9;
	p1->minutaStart = 45;
	p1->dlugosc = 15;
	przerwy.push_back(p1);

	Przerwy* p2 = new Przerwy();
	p2->godzinaStart = 11;
	p2->minutaStart = 30;
	p2->dlugosc = 15;
	przerwy.push_back(p2);

	Przerwy* p3 = new Przerwy();
	p3->godzinaStart = 13;
	p3->minutaStart = 15;
	p3->dlugosc = 30;
	przerwy.push_back(p3);

	Przerwy* p4 = new Przerwy();
	p4->godzinaStart = 15;
	p4->minutaStart = 15;
	p4->dlugosc = 15;
	przerwy.push_back(p4);

	Przerwy* p5 = new Przerwy();
	p5->godzinaStart = 17;
	p5->minutaStart = 0;
	p5->dlugosc = 15;
	przerwy.push_back(p5);

	Przerwy* p6 = new Przerwy();
	p6->godzinaStart = 18;
	p6->minutaStart = 45;
	p6->dlugosc = 15;
	przerwy.push_back(p6);

	Przerwy* p7 = new Przerwy();
	p7->godzinaStart = 20;
	p7->minutaStart = 30;
	p7->dlugosc = 0;
	przerwy.push_back(p7);
}

bool Przerwa::sprawdzCzas(int &iloscMinut)
{
	tm *czas = czasAktualny;
	int minuty = 0;

	if (czas->tm_hour <= 8 && czas->tm_min < 15)
		return false;
	
	if (czas->tm_hour >= 20 && czas->tm_min >= 30)
		return false;

	for (auto p : przerwy)
	{
		if (czas->tm_hour < p->godzinaStart) //zajecia
		{
			minuty = 60 - czas->tm_min;
			minuty = minuty + p->minutaStart;
			minuty = minuty + ((p->godzinaStart - czas->tm_hour - 1) * 60);
			iloscMinut = minuty;
			return false;
		}

		if (p->godzinaStart == czas->tm_hour && czas->tm_min < p->minutaStart) //zajecia
		{
			minuty = p->minutaStart - czas->tm_min;
			iloscMinut = minuty;
			return false;
		}

		if (p->godzinaStart == czas->tm_hour && czas->tm_min >= p->minutaStart && czas->tm_min < p->minutaStart + p->dlugosc) //przerwa
		{
			minuty = p->minutaStart + p->dlugosc - czas->tm_min;
			iloscMinut = minuty;
			return true;
		}
	}
}


