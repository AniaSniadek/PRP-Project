#include "Mieszkancy.h"
#include "Przerwa.h"
#include <Windows.h>
#include <iostream>
#include <thread>
using namespace std;

void zapis(Mieszkancy* m, Przerwa* p)
{
	time_t czasAktualny;
	tm *czasLokalny;
	int wynikMinut = 0;
	wstring info = L"";

	while (true)
	{
		czasAktualny = time(0);
		czasLokalny = localtime(&czasAktualny);

		if (czasLokalny->tm_sec >= 30.0 && czasLokalny->tm_sec < 31) // zapis co 30-sta sekunde
		{
			m->zapisDoPliku();
		}
		else if (czasLokalny->tm_sec >= 0.0 && czasLokalny->tm_sec < 1.0) // zapis co 0-owa sekunde
		{
			m->zapisDoPliku();
			p->czasAktualny = czasLokalny;
			
			if (p->sprawdzCzas(wynikMinut) == true)
			{
				info = to_wstring(wynikMinut) + L" minut pozosta³o do koñca przerwy";
				MessageBoxW(NULL, info.c_str(), L"INFO", MB_OK | MB_ICONINFORMATION); 
			}
			else
			{
				info = to_wstring(wynikMinut) + L" minut pozosta³o do koñca zajêæ";
				MessageBoxW(NULL, info.c_str(), L"INFO", MB_OK | MB_ICONINFORMATION);
			}
		}
	}
}

int main()
{
	Mieszkancy *m = new Mieszkancy();
	Przerwa *p = new Przerwa();
	p->dodajPrzerwe();
	thread obiektZapis(zapis, m, p);

	int ilosc;
	cout << "Wpisz ile osob chcesz dodac do systemu: ";
	cin >> ilosc;

	Osoba *o = new Osoba[ilosc];

	for (int i = 0; i < ilosc; i++)
	{
		o[i].wpiszOsobe();

		if (o[i].sprawdzPesel() == true)
		{
			m->dodajOsobe(&o[i]);
		}
		else
		{
			cout << "Bledny numer pesel! Sprobuj ponownie.\n";
			i--;
		}
	}

	cout << '\n' << "Wyswietlam liste osob w systemie:\n";
	m->wyswietlListe();

	getchar();
	getchar();
	return 0;
}