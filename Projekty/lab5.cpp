#include <iostream>
#include <time.h>
using namespace std;

// klasa przedmiot
class Przedmiot {
private:
  string nazwa;
  int atak, obrona;

public:
  Przedmiot();
  Przedmiot(string n, int a);
  Przedmiot(const Przedmiot &wzor, int o);
  void wyswietlPrzedmiot();
  string getNazwa() { return nazwa; }
  int getObrona() { return obrona; }
  void setNazwa(string n) { nazwa = n; }
  void setAtak(int a) { atak = a; }
};

// klasa bohater
class Bohater {
private:
  string imie, klasa;
  int punkty_zycia;
  Przedmiot **ekwipunek = new Przedmiot *[3];
  int licznik = 0;

public:
  Bohater(const Bohater &wzor);
  Bohater(string n, string k, int p);
  ~Bohater() { delete[] ekwipunek; }

  void usunPrzedmiot(string n);
  string zwrocNajwiekszaObrone();

  void dodajPrzedmiot(Przedmiot p);
  void wyswietlBohatera();

  // settery
  void setImie(string i) { imie = i; }
  void setKlasa(string k) { klasa = k; }
};

int main() {
  srand(time(NULL));

  // a)
  cout << "a)\n";
  Przedmiot p1;
  p1.setNazwa("klinga");
  p1.setAtak(78);
  Przedmiot *p2 = new Przedmiot("miecz", 97);
  Przedmiot p3 = Przedmiot(*p2, 40);

  p1.wyswietlPrzedmiot();
  p2->wyswietlPrzedmiot();
  p3.wyswietlPrzedmiot();

  // b)
  cout << "\nb)\n";
  Przedmiot arr[2] = {Przedmiot("dzida", 65), Przedmiot("widly", 22)};
  arr[0].wyswietlPrzedmiot();
  arr[1].wyswietlPrzedmiot();

  // c)
  cout << "\nc)\n";
  Bohater b1("Alojzy", "Wojownik", 1000);
  b1.dodajPrzedmiot(p1);
  b1.dodajPrzedmiot(*p2);
  b1.dodajPrzedmiot(p3);
  b1.wyswietlBohatera();

  // d)
  cout << "\nd)\n";
  Bohater b2 = Bohater(b1);
  b2.setImie("Karol");
  b2.setKlasa("Paladyn");
  b2.usunPrzedmiot("miecz");

  b2.dodajPrzedmiot(arr[0]);
  b2.dodajPrzedmiot(arr[1]);

  b2.wyswietlBohatera();

  // e)
  cout << "\ne)\n";
  cout << "Przedmiot o najwiekszej obronie gracza 1: "
       << b1.zwrocNajwiekszaObrone() << endl;
  cout << "Przedmiot o najwiekszej obronie gracza 2: "
       << b2.zwrocNajwiekszaObrone() << endl;

  delete p2;
  return 0;
}

Przedmiot::Przedmiot() {
  nazwa = "brak";
  atak = 0;
  obrona = rand() % 81 + 20;
}
Przedmiot::Przedmiot(string n, int a = 0) {
  nazwa = n;
  atak = a;
  obrona = rand() % 81 + 20;
}

Przedmiot::Przedmiot(const Przedmiot &wzor, int o) {
  nazwa = wzor.nazwa;
  atak = wzor.atak;
  obrona = o;
}

void Przedmiot::wyswietlPrzedmiot() {
  cout << "Nazwa: " << nazwa << ", atak: " << atak << ", obrona: " << obrona
       << endl;
}

// bohater
Bohater::Bohater(string n, string k, int p) {
  imie = n;
  klasa = k;
  punkty_zycia = p;
}

Bohater::Bohater(const Bohater &wzor) {
  imie = wzor.imie;
  klasa = wzor.klasa;
  punkty_zycia = wzor.punkty_zycia;
  licznik = wzor.licznik;

  for (int i = 0; i < licznik; i++) {
    ekwipunek[i] = new Przedmiot;
    *ekwipunek[i] = *wzor.ekwipunek[i];
  }
}

void Bohater::dodajPrzedmiot(Przedmiot p) {
  ekwipunek[licznik] = &p;
  licznik++;
}

void Bohater::wyswietlBohatera() {
  cout << "Nazwa: " << imie << ", klasa: " << klasa
       << ", punkty zycia: " << punkty_zycia << ", ekwipunek:" << endl;

  for (int i = 0; i < licznik; i++) {
    if (ekwipunek[i] != nullptr) {
      ekwipunek[i]->wyswietlPrzedmiot();
    }
  }
}

void Bohater::usunPrzedmiot(string n) {
  for (int i = 0; i < 3; i++) {
    if (ekwipunek[i]->getNazwa() == n) {
      ekwipunek[i] = nullptr;
      licznik--;
    }
  }
}

string Bohater::zwrocNajwiekszaObrone() {
  int max = ekwipunek[0]->getObrona();
  int index;
  for (int i = 0; i < licznik; i++) {
    if (ekwipunek[i]->getObrona() >= max && ekwipunek[i] != nullptr) {
      max = ekwipunek[i]->getObrona();
      index = i;
    }
  }
  return (ekwipunek[index]->getNazwa());
}
