#include <iostream>
#include <math.h>
using namespace std;

class Kwadrat;
class Okrag;

// klasa punkt
class Punkt {
  friend class Kwadrat;
  friend class Okrag;
  friend void wypisz(Kwadrat k);
  friend void wypisz(Okrag o);

private:
  int x;
  int y;

public:
  Punkt();
  Punkt(int, int);
};

// klasa kwadrart
class Kwadrat {
  friend void wypisz(Kwadrat k);

private:
  Punkt poczatek_przekatnej;
  Punkt koniec_przekatnej;

public:
  Kwadrat();
  Kwadrat(Punkt, Punkt);

  double poleKwadratu();
};

// klasa okrag
class Okrag {
  friend void wypisz(Okrag o);

private:
  Punkt srodek;
  int promien;

public:
  Okrag();
  Okrag(Punkt, int);
  void setSrodek(Punkt S) { srodek = S; }
  void setPromien(int r) { promien = r; }
  Punkt getSrodek() { return srodek; }
  void rozlacznosc(Okrag tab_okr[]);
};

// e)
void wypisz(Kwadrat);
void wypisz(Okrag);

int main() {
  srand(time(NULL));

  // a
  Kwadrat tab[2] = {{Punkt(0, 0), Punkt(3, 3)}, {Punkt(-8, 8), Punkt(-1, 1)}};

  // b
  cout << "b) P1 = " << tab[0].poleKwadratu()
       << ", P2 = " << tab[1].poleKwadratu() << endl;

  // c
  Okrag o1(Punkt(10, 10), 5);
  Okrag tab_okr[500];
  for (int i = 0; i < 500; i++) {
    tab_okr[i].setSrodek(Punkt(rand() % 31 - 10, rand() % 21));
    tab_okr[i].setPromien(rand() % 6 + 1);
  }

  // d
  cout << "d) ";
  o1.rozlacznosc(tab_okr);

  // e
  cout << "e) okrag: ";
  wypisz(o1);
  cout << ", kwadrat: ";
  wypisz(tab[0]);

  return 0;
}

// konstruktory klasy punkt
Punkt::Punkt() {
  x = 0;
  y = 0;
}
Punkt::Punkt(int x, int y) {
  this->x = x;
  this->y = y;
}

// konstruktory klasy kwadrat
Kwadrat::Kwadrat() {}
Kwadrat::Kwadrat(Punkt p, Punkt k) {
  poczatek_przekatnej = p;
  koniec_przekatnej = k;
}
// metody klasy kwadrat
double Kwadrat::poleKwadratu() {
  double d, a, pole;
  d = sqrt(pow(koniec_przekatnej.x - poczatek_przekatnej.x, 2) +
           pow(koniec_przekatnej.y - poczatek_przekatnej.y, 2));
  a = d / sqrt(2);
  pole = pow(a, 2);
  return pole;
}

// konstruktory klasy okrag
Okrag::Okrag() {}
Okrag::Okrag(Punkt S, int r) {
  srodek = S;
  promien = r;
}

void Okrag::rozlacznosc(Okrag tab[]) {
  int dl, rozl_wew = 0, rozl_zew = 0;
  for (int i = 0; i < 500; i++) {
    dl = sqrt(pow(srodek.x - tab[i].srodek.x, 2) +
              pow(srodek.y - tab[i].srodek.y, 2));
    if (abs(promien - tab[i].promien) > dl) {
      rozl_wew++;
    }
    if (promien + tab[i].promien < dl) {
      rozl_zew++;
    }
  }
  cout << "Rozlaczne wewnetrznie: " << rozl_wew << ", rozlaczne zewnetrznie: " << rozl_zew
       << endl;
}

// e)
void wypisz(Kwadrat k) {
  cout << "Poczatek przekatnej: (" << k.poczatek_przekatnej.x << ","
       << k.poczatek_przekatnej.y << "), koniec: (" << k.koniec_przekatnej.x
       << "," << k.koniec_przekatnej.y << ")\n";
}

void wypisz(Okrag o) {
  cout << "S(" << o.srodek.x << "," << o.srodek.y << "), r=" << o.promien
       << endl;
}