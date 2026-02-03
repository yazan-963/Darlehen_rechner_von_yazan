#include<iostream>
using namespace std;

struct stFaelligkeitsdarlehen
{
	double Darlehen;
	int jahre;
	double zinssatz;
};
struct stRatendarlehen
{
	double Darlehen;
	int jahre;
	double zinssatz;
};
enum enmenue
{
	Ratendarlehen = 1, Faelligkeitsdarlehen
};


void darlehenartenmenu()
{
	cout << "************************************\n\n";
	cout << "      Darlehensarten Menue              \n\n";
	cout << "************************************\n";
	cout << "(1) Ratendarlehen\n";
	cout << "(2) Faelligkeitsdarlehen\n";
	cout << "************************************" << endl;
}


short DarlehensartVonBenutzerLesen()
{
	short x;
	do {
		cout << "Geben Sie bitte ein, welche Darlehensart Sie berechnen wollen: \n";
		cin >> x;
		if (x <= 0 || x > 2) {
			cout << "Falsche Zahl, versuchen Sie bitte noch einmal\n";
		}
	} while (x <= 0 || x > 2);

	return x;
}
enmenue benutzerEingabe(short x)
{

	if (x == enmenue::Ratendarlehen)
		return enmenue::Ratendarlehen;

	else
		return enmenue::Faelligkeitsdarlehen;

}


stRatendarlehen RatenVonBenutzerLesen()
{
	stRatendarlehen x;
	cout << "************************************\n\n";
	cout << "Wie hoch ist das Darlehen: ";
	cin >> x.Darlehen;
	cout << "Wie hoch ist der Zinssatz: ";
	cin >> x.zinssatz;
	cout << "Wie viele Jahre: ";
	cin >> x.jahre;
	cout << "************************************\n\n";
	return x;
}
double RatenTilgung(stRatendarlehen c)
{
	return c.Darlehen / c.jahre;
}
void printRatenDarlehen()
{
	stRatendarlehen berechnen = RatenVonBenutzerLesen();
	int x = 1;
	double Darlehenjahresanfang = berechnen.Darlehen;

	while (x <= berechnen.jahre)
	{
		double zinsen = Darlehenjahresanfang * berechnen.zinssatz / 100;
		double GesamtZahlungimJahr = RatenTilgung(berechnen) + zinsen;
		cout << "********************\n";
		cout << "Jahr: " << x << endl;
		cout << "Darlehenjahresanfang: " << Darlehenjahresanfang << "\n";
		cout << "Tilgung: " << RatenTilgung(berechnen) << "\n";
		cout << "Zinsen: " << zinsen << "\n";
		cout << "Gesamtzahlung im Jahr: " << GesamtZahlungimJahr << endl;
		x++;
		Darlehenjahresanfang = Darlehenjahresanfang - RatenTilgung(berechnen);
	}



}


stFaelligkeitsdarlehen faelligkeitVonBenutzerLesen()
{
	stFaelligkeitsdarlehen v;
	cout << "************************************\n\n";
	cout << "Wie hoch ist das Darlehen: ";
	cin >> v.Darlehen;
	cout << "Wie hoch ist der Zinssatz: ";
	cin >> v.zinssatz;
	cout << "Wie viele Jahre: ";
	cin >> v.jahre;
	cout << "************************************\n\n";
	return v;

}
double faelligkeitsDarlehenZinsen(stFaelligkeitsdarlehen zinsen)
{
	return zinsen.Darlehen * zinsen.zinssatz / 100;
}
void printFaelligkeitsDarlehen()
{
	int x = 1;
	stFaelligkeitsdarlehen FaelligkeitsDarlehenBerechnen = faelligkeitVonBenutzerLesen();

	while (x <= FaelligkeitsDarlehenBerechnen.jahre)
	{
		cout << "********************\n";
		cout << "Jahr: " << x << endl;
		cout << "Darlehenjahresanfang: " << FaelligkeitsDarlehenBerechnen.Darlehen << "\n";
		cout << "Tilgung: " << 0 << "\n";
		cout << "Zinsen: " << faelligkeitsDarlehenZinsen(FaelligkeitsDarlehenBerechnen) << "\n";
		cout << "Gesamtzahlung im Jahr: " << faelligkeitsDarlehenZinsen(FaelligkeitsDarlehenBerechnen) << endl;
		x++;
		if (x == FaelligkeitsDarlehenBerechnen.jahre)
			break;
	}
	cout << "********************\n";
	cout << "Jahr: " << FaelligkeitsDarlehenBerechnen.jahre << endl;
	cout << "Darlehenjahresanfang: " << FaelligkeitsDarlehenBerechnen.Darlehen << "\n";
	cout << "Tilgung: " << FaelligkeitsDarlehenBerechnen.Darlehen << "\n";
	cout << "Zinsen: " << faelligkeitsDarlehenZinsen(FaelligkeitsDarlehenBerechnen) << "\n";
	cout << "Gesamtzahlung im Jahr: " << faelligkeitsDarlehenZinsen(FaelligkeitsDarlehenBerechnen) + FaelligkeitsDarlehenBerechnen.Darlehen << endl;
	cout << "Darlehenjahresende: " << 0 << endl;
}



void Program()
{
	darlehenartenmenu();

	switch (benutzerEingabe(DarlehensartVonBenutzerLesen())) {
	case enmenue::Ratendarlehen:
		printRatenDarlehen();
		break;
	case enmenue::Faelligkeitsdarlehen:
		printFaelligkeitsDarlehen();
		break;
	}

}


int main()
{
	Program();
}