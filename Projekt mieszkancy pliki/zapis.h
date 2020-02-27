#pragma once

void zapis(Mieszkancy* m)
{
	time_t czasAktualny;
	tm *czasLokalny;

	while (true)
	{
		czasAktualny = time(0);
		czasLokalny = localtime(&czasAktualny);


		if (czasLokalny->tm_sec >= 30.0 && czasLokalny->tm_sec < 31)
		{
			m->zapisDoPliku();
		}
		else if (czasLokalny->tm_sec >= 0.0 && czasLokalny->tm_sec < 1.0)
		{
			m->zapisDoPliku();
			//ile minut do konca zajec (klase oddzielna stworzyc)
		}
	}
}
