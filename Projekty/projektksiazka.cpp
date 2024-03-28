#include <iostream>
#include <string>
using namespace std;

//Stwórz funkcjê globaln¹, która posortuje tablicê ksi¹¿ek wzglêdem roku wydania malej¹co. Posortuj tablicê.Wyœwietl posortowan¹ tablicê.
void Posortuj(int n, Biblioteka::Ksiazka* k);

//przestrzeñ nazw
namespace Biblioteka {
	class Ksiazka {
	//pola
	private:
		string tytul;
		string autor;
		int rok_wydania;
		static int licznik; //pole statyczne, ma zliczaæ iloœæ istniej¹cych ksi¹¿ek

	//metody
	public:
		//konstruktor domyœlny() – wyœwietla informacjê o tym, ¿e ksi¹¿ka zosta³a utworzona
		Ksiazka() {
			cout << "Ksiazka zostala utworzona." << endl;
			licznik++;
		}
		void przypisz(string t, string a, int r) {
			tytul = t;
			autor = a;
			rok_wydania = r;
		}
		void wypisz() {
			cout << "Tytul: " << tytul << ", ";
			cout << "Autor: " << autor << ", ";
			cout << "Rok wydania: " << rok_wydania << endl;
		}
		string dajTytul() {
			return tytul;
		}
		int getYear() {
			return rok_wydania;
		}
		//czyXXwiek() – sprawdza czy ksi¹¿ka zosta³a wydana w dwudziestym wieku
		bool czyXXwiek() {
			if (rok_wydania > 1900 && rok_wydania <= 2000) {
				return true;
			}
			else return false;
		}
	};

	int Ksiazka::licznik = 0;
}

	int main() {
		//Stwórz ksi¹¿kê oraz 4-elementow¹ tablicê ksi¹¿ek.
		Biblioteka::Ksiazka ksiazka1;
		Biblioteka::Ksiazka tab_ksiazek[4];

		//Przypisz im dowolne dane.
	    ksiazka1.przypisz("Wiedzmin", "Andrzej Sapkowski", 1986);
		tab_ksiazek[0].przypisz("Neuromancer", "William Gibson", 1984);
		tab_ksiazek[1].przypisz("1984", "George Orwell", 1949);
		tab_ksiazek[2].przypisz("Lsnienie", "Stephen King", 1877);
		tab_ksiazek[3].przypisz("Harry Potter", "J.K. Rowling", 2097);

		// Wyœwietl dane utworzonych ksi¹¿ek (bez licznika).
		ksiazka1.wypisz();
		tab_ksiazek[0].wypisz();
		tab_ksiazek[1].wypisz();
		tab_ksiazek[2].wypisz();
		tab_ksiazek[3].wypisz();

		//SprawdŸ przy wykorzystaniu metody czyXXwiek() czy ksi¹¿ki z utworzonej tablicy zosta³y wydane w dwudziestym wieku.
		for (int i = 0; i < 4; i++) {
			if (tab_ksiazek[i].czyXXwiek()) {
				cout << "Ksi¹zka o tytule " << tab_ksiazek[i].dajTytul() << " zostala wydana w XX wieku." << endl;
			}
		}

		//sortowanie tablicy
		Posortuj(4, &tab_ksiazek);
		
	return 0;
}

	void Posortuj(Biblioteka::Ksiazka k[]) {
		
		int tab_rok[4];

		for (int i = 0; i < 4; i++) {
			tab_rok[i] = k[i].getYear();
		}
		int min = tab_rok[0];
		for (int i = 0; i < 4; i++) {
			if (tab_rok[i] < min) {
				min = tab_rok[i];
			}
		}

	}

