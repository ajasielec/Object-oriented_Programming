#include <iostream>
using namespace std;

// Stworz klase pasazer
class Pasazer {
private:
  string imie, nazwisko;
  int rok_urodzenia;
  static int licznik;

public:
  Pasazer();
  Pasazer(string i, string n, int r);
  Pasazer(const Pasazer &wzor);

  // settery, gettery
  void set_imie(string i) { imie = i; }
  void set_nazwisko(string n) { nazwisko = n; }
  void set_rok(int r) { rok_urodzenia = r; }
  int get_licznik() { return licznik; }

  void wyswietl_Pasazera();
};
int Pasazer::licznik = 0;

// stworz klase Autokar
class Autokar {
private:
  string miejsce_docelowe;
  int predkosc_maksymalna;
  const int calkowita_ilosc_miejsc = 20;
  Pasazer **lista_pasazerow = new Pasazer *[calkowita_ilosc_miejsc];
  int licznik = 0;

public:
  Autokar(string md, int pm);
  Autokar(const Autokar &wzor); 
  ~Autokar(){delete[] lista_pasazerow;}

  void dodaj_pasazera(Pasazer p);
  void dodaj_pasazera(Pasazer ludzie[], int rozmiar);
  void usun_pasazerow();
  void wyswietl_autokar();
};

int main() {

  // a)
  cout << "a)\n";
  Pasazer p1;
  p1.set_imie("Andrzej");
  p1.set_nazwisko("Klocek");
  p1.set_rok(2002);

  Pasazer p2("Artur", "Nowak", 1969);
  Pasazer p3 = Pasazer(p2);

  p1.wyswietl_Pasazera();
  p2.wyswietl_Pasazera();
  p3.wyswietl_Pasazera();

  // b)
  cout << "\nb)\n";
  int rozmiar = 100;
  Pasazer *pasazerowie = new Pasazer[rozmiar];

  cout << "Licznik = " << p1.get_licznik() << endl;

  // c)
  cout << "\nc)\n";
  Autokar a1("Krakow", 300);

  a1.dodaj_pasazera(p1);
  a1.dodaj_pasazera(p2);
  a1.dodaj_pasazera(p3);
  a1.dodaj_pasazera(pasazerowie, rozmiar);

  a1.wyswietl_autokar();

  // d)
  cout << "\nd)\n";
  Autokar a2 = Autokar(a1);
  a2.usun_pasazerow();
  a2.wyswietl_autokar();

  // e)
  cout << "\ne)\n";
  delete[] pasazerowie;
  cout << "Licznik = " << p3.get_licznik();

  return 0;
}

// pasazer
Pasazer::Pasazer() { licznik++; }
Pasazer::Pasazer(string i, string n, int r) {
  imie = i;
  nazwisko = n;
  rok_urodzenia = r;
  licznik++;
}
Pasazer::Pasazer(const Pasazer &wzor) {
  imie = wzor.imie;
  nazwisko = wzor.nazwisko;
  rok_urodzenia = wzor.rok_urodzenia;
  licznik++;
}

void Pasazer::wyswietl_Pasazera() {
  cout << "Imie: " << imie << ", nazwisko: " << nazwisko
       << ", rok urodzenia: " << rok_urodzenia << endl;
}

// autokar
Autokar::Autokar(string md, int pm) {
  miejsce_docelowe = md;
  predkosc_maksymalna = pm;
}
Autokar::Autokar(const Autokar &wzor) {
  miejsce_docelowe = wzor.miejsce_docelowe;
  predkosc_maksymalna = wzor.predkosc_maksymalna;
  licznik = wzor.licznik;
  for (int i = 0; i < licznik; i++) {
    lista_pasazerow[i] = new Pasazer;
    *lista_pasazerow[i] = *wzor.lista_pasazerow[i];
  }
}

void Autokar::dodaj_pasazera(Pasazer p) {
  if (licznik < calkowita_ilosc_miejsc) {
    lista_pasazerow[licznik] = &p;
    licznik++;
  }
}

void Autokar::dodaj_pasazera(Pasazer ludzie[], int rozmiar) {
  for (int i = 0; i < rozmiar; i++) {
    if (licznik < calkowita_ilosc_miejsc) {
      lista_pasazerow[licznik] = &ludzie[0];
      licznik++;
    }
  }
}

void Autokar::usun_pasazerow() {
  for (int i = 0; i < 3; i++) {
    lista_pasazerow[i] = nullptr;
  }
}

void Autokar::wyswietl_autokar() {
  cout << "Miejsce docelowe: " << miejsce_docelowe
       << ", predkosc maksymalna: " << predkosc_maksymalna
       << ", lista pasazerow:\n";

  for (int i = 0; i < licznik; i++) {
    if (lista_pasazerow[i] != nullptr) {
      cout << i + 1 << ": ";
      lista_pasazerow[i]->wyswietl_Pasazera();
    }
  }
}