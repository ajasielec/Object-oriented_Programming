#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string imie;
	string nazwisko;
	string kierunek;
	int rok_studiow;

public:
	void setName(string n) { imie = n;}
	void setSurname(string s) {nazwisko = s;}
	void setKierunek(string k) { kierunek = k;}
	void setRok(int r) { rok_studiow = r;}

	string getName() { return imie; }
	string getSurname() {return nazwisko;}
	string getKierunek() {return kierunek;}
	int getRok() {return rok_studiow;}

	void wypiszStudenta() {
		cout << imie << " " << nazwisko << " " << kierunek << " " << rok_studiow << endl;
	}
};

class Grupa {
private:
	int nr_grupy;
	const int limit_miejsc = 1;
	Student * tablica = new Student [limit_miejsc];
	int licznik = 0;
public:
	void setNrGrupy(int nr) { nr_grupy = nr; }

	//wypisz() – wypisuje dane grupy wraz z list¹ studentów
	void wypisz() {
		cout << "Numer grupy: " << nr_grupy << endl;
		cout << "Limit miejsc: " << limit_miejsc << endl;
		for (int i = 0; i < licznik; i++) {
			cout << "Student " << i + 1 << ": " << tablica[i].getName() << " " << tablica[i].getSurname() << " " << tablica[i].getKierunek() << " " << tablica[i].getRok() << endl;
		}
	}

	//dodajStudenta() – dodaje studenta do grupy
	void dodajStudenta(Student s) {
		if (licznik < limit_miejsc) {
			tablica[licznik] = s;
			licznik++;
		}
		else cout << "Limit miejsc zostal przekroczony.";
	}
	//dodaje studenta dynamicznego
/*	void dodajStudenta(Student* s) {
		if (licznik < limit_miejsc) {
			tablica[licznik] = *s;
		}
		else cout << "Limit miejsc zostal przekroczony.";
		licznik++;
	}
	*/

//przepiszStudenta - przenosi studenta o podanym imieniu i nazwisko z biezacej do innej grupy
	void przepiszStudenta(int index, Grupa *g) {
		Student kopia = tablica[index];
		g->dodajStudenta(kopia);
		tablica[index].setName("");
		tablica[index].setSurname("");
		tablica[index].setKierunek("");
		tablica[index].setRok(0);
	}
};

int main() {
	// a)
	cout << "a)" << endl;
	//Stwórz studenta (obiekt dynamiczny) oraz 2-elementow¹ tablicê studentów.
	Student* student1 = new Student;
	Student tab[2];

	//Uzupe³nij ich dane przy u¿yciu akcesorów.
	student1->setName("Anna");
	student1->setSurname("Jasielec");
	student1->setKierunek("Informatyka Techniczna");
	student1->setRok(1);

	tab[0].setName("Adam");
	tab[0].setSurname("Nowak");
	tab[0].setKierunek("Informatyka Techniczna");
	tab[0].setRok(1);
	tab[1].setName("Bozydar");
	tab[1].setSurname("Traba");
	tab[1].setKierunek("Informatyka Techniczna");
	tab[1].setRok(1);

	//Wypisz dane wszystkich utworzonych studentów
	student1->wypiszStudenta();
	tab[0].wypiszStudenta();
	tab[1].wypiszStudenta();

	//b)
	cout << "\nb)" << endl;
	//Stwórz grupê.
	Grupa grupa1;
	//Do grupy dodaj wszystkich utworzonych wczeœniej studentów
	grupa1.dodajStudenta(*student1);
	grupa1.dodajStudenta(tab[0]);
	grupa1.dodajStudenta(tab[1]);
	grupa1.setNrGrupy(1);

	//Wypisz dane grupy wraz z tablic¹ przypisanych do niej studentów.
	grupa1.wypisz();

	//c)
	//Stworz druga grupe
	Grupa grupa2;
	grupa2.setNrGrupy(2);

	//d)
	cout << "\nd) ";
	//przenies dowolnego studenta z pierwszej grupy do drugiej grupy
	grupa1.przepiszStudenta(1, &grupa2);
	
	

	//Wypisz dane obu grup.
	grupa1.wypisz();
	cout << endl;
	grupa2.wypisz();



	return 0;
}