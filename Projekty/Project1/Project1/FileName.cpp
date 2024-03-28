#include <iostream>
using namespace std;

class Osoba {
	friend class Student;
	friend Osoba** MniejNiz30(Osoba* tab[]);
protected:
	string imie, nazwisko;
	int rok_ur;
public:
	Osoba() {
		imie = "brak";
		nazwisko = "brak";
		rok_ur = 0;
	}
	Osoba(string i, string n, int r) {
		imie = i;
		nazwisko = n;
		rok_ur = r;
	}
	virtual void wypisz() {
		cout << "imie: " << imie << ", nazwisko: " << nazwisko << ", rok urodzenia: " << rok_ur << endl;
	}
};

class Student : public Osoba {
private:
	string kierunek;
	int rok_studiow;
public:
	Student() {
		imie = "brak";
		nazwisko = "brak";
		rok_ur = 0;
		kierunek = "brak";
		rok_studiow = 0;
	}

	Student(string k, int r, Osoba o) {
		kierunek = k;
		rok_studiow = r;
		imie = o.imie;
		nazwisko = o.nazwisko;
		rok_ur = o.rok_ur;
	}

	void wypisz() override {
		cout << "imie: " << imie << ", nazwisko: " << nazwisko << ", rok urodzenia: " << rok_ur;
		cout << ", kierunek: " << kierunek << ", rok studiow: " << rok_studiow << endl;
	}
};

class Pracownik : public Osoba {
private:
	string miejsce_pracy, zawod;
public:
	Pracownik() {}

	Pracownik(string i, string n, int r, string m, string z) {
		miejsce_pracy = m;
		zawod = z;
		imie = i;
		nazwisko = n;
		rok_ur = r;
	}

	//konstruktor kopiujacy
	Pracownik(const Pracownik& p, string n, int r) {
		miejsce_pracy = p.miejsce_pracy;
		zawod = p.zawod;
		imie = p.imie;
		nazwisko = n;
		rok_ur = r;
	}

	void wypisz()  {
		cout << "imie: " << imie << ", nazwisko: " << nazwisko << ", rok urodzenia: " << rok_ur;
		cout << ", miejsce pracy: " << miejsce_pracy << ", zawod: " << zawod << endl;
	}
};


//e)
Osoba** MniejNiz30(Osoba* tab[]) {
	Osoba** nowa_tab = new Osoba * [4];
	int j = 0;
	for (int i = 0; i < 4; i++) {
		if (2023 - tab[i]->rok_ur < 30) {
			nowa_tab[j] = tab[i];
			j++;
		}
	}

	for (int i = j; i < 4; i++) {
		nowa_tab[i] = 0;

	}
	return nowa_tab;
}

int main() {

	//a)
	cout << "a)\n";
	Osoba* os1 = new Osoba("Anna", "Kowalska", 1975);
	os1->wypisz();

	//b)
	cout << "\nb)\n";
	Student student1("IT", 1, *os1);
	student1.wypisz();

	//c)
	cout << "\nc)\n";

	Pracownik pracownik1("Karol", "Nowak", 2003, "firma x", "Programista");
	Pracownik pracownik2(pracownik1, "Bialy", 1997);
	pracownik1.wypisz();
	pracownik2.wypisz();

	//d) 
	cout << "\nd) tablica:\n";
	Osoba** tab_wsk = new Osoba * [4];
	tab_wsk[0] = os1;
	tab_wsk[1] = &student1;
	tab_wsk[2] = &pracownik1;
	tab_wsk[3] = &pracownik2;

	for (int i = 0; i < 4; i++) {
		tab_wsk[i]->wypisz();
	}

	//e)
	cout << "\ne) osoby m³odsze niz 30 lat:\n";
	Osoba** tab2 = MniejNiz30(tab_wsk);
	for (int i = 0; i < 4; i++) {
		if (tab2[i] != 0)
			tab2[i]->wypisz();
	}

	//czyszczenie
	delete os1;
	delete[] tab_wsk;
	delete[] tab2;

	return 0;
}