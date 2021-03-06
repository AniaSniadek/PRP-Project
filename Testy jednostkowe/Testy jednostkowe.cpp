// Testy jednostkowe.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//#include "pch.h"
#include <iostream>
#include "gtest/gtest.h"
#include "Osoba.h"
#include "Przerwa.h"

TEST(PESELTest1, PESEL_poprawny)
{
	Osoba o;
	o.pesel = "97030604528";

	EXPECT_TRUE(o.sprawdzPesel()); //spodziwamy sie ze funkcja sprawdz pesel zwroci true
}

TEST(PESELTest2, PESEL_niepoprawny)
{
	Osoba o;
	o.pesel = "44051401358";

	EXPECT_FALSE(o.sprawdzPesel()); 
}

TEST(PrzerwaTest1, czyJestPrzerwa)
{
	Przerwa p;
	p.dodajPrzerwe();
	time_t czasAktualny;
	tm *czasLokalny;
	int minuty = 0;
	czasAktualny = time(0);
	czasLokalny = localtime(&czasAktualny);
	czasLokalny->tm_hour = 18;
	czasLokalny->tm_min = 50;
	p.czasAktualny = czasLokalny;

	EXPECT_TRUE(p.sprawdzCzas(minuty));
}

TEST(PrzerwaTest2, czyNieMaPrzerwy)
{
	Przerwa p;
	p.dodajPrzerwe();
	time_t czasAktualny;
	tm *czasLokalny;
	int minuty = 0;
	czasAktualny = time(0);
	czasLokalny = localtime(&czasAktualny);
	czasLokalny->tm_hour = 18;
	czasLokalny->tm_min = 15;
	p.czasAktualny = czasLokalny;

	EXPECT_FALSE(p.sprawdzCzas(minuty));
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
