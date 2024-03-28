#include <iostream>
#include <math.h>
using namespace std;

int GCD(int a, int b) {
  int aux;

  while (b != 0) {
    aux = b;
    b = a % b;
    a = aux;
  }
  return a;
}
class Ulamek {
  friend ostream &operator<<(ostream &, Ulamek &);
  friend void generuj(int);

private:
  int licznik;
  int mianownik;

public:
  friend Ulamek dodaj(Ulamek u1, Ulamek u2);
  Ulamek() {}
  Ulamek(int l, int m) {
    licznik = l;
    mianownik = m;
  }
  // konstr konwertujący
  Ulamek(int l) : licznik(l), mianownik(1) {}

  // operator konwersji
  operator double() {
    return static_cast<double>(licznik) / static_cast<double>(mianownik);
  }

  void wypisz() { cout << licznik << "/" << mianownik << endl; }

  void skrocUlamek() {
    while (GCD(licznik, mianownik) != 1) {
      int gcd = GCD(licznik, mianownik);
      licznik /= gcd;
      mianownik /= gcd;
    }
  }
};

// b)
Ulamek dodaj(Ulamek u1, Ulamek u2) {
  Ulamek wynik;
  wynik.licznik = u1.licznik * u2.mianownik + u2.licznik * u1.mianownik;
  wynik.mianownik = u2.mianownik * u1.mianownik;
  return wynik;
}

// d)
double kwadratLiczby(double x) { return (x * x); }

ostream &operator<<(ostream &res, Ulamek &u) {
  res << u.licznik << "/" << u.mianownik;
  return res;
}

// f
void generuj(int n) {
  Ulamek *tab = new Ulamek[n];
  for (int i = 0; i < n; i++) {
    tab[i].licznik = rand() % 2001 - 1000;
    tab[i].mianownik = rand() % 2001 - 1000;
    cout << tab[i] << endl;
  }
  double max = tab[0].licznik / tab[0].mianownik;
  int index;
  for (int i = 0; i < n; i++) {
    if (tab[i].licznik / tab[i].mianownik >= max) {
      max = tab[i].licznik / tab[i].mianownik;
      index = i;
    }
  }
  cout << "max =" << tab[index];
}

int main() {
  srand(time(NULL));

  // a
  Ulamek tab[3] = {Ulamek(1, 2), Ulamek(5, 8), Ulamek(7, 9)};
  tab[0].wypisz();
  tab[1].wypisz();
  tab[2].wypisz();

  // b)
  Ulamek suma = dodaj(tab[0], tab[1]);
  cout << tab[0] << " + " << tab[1] << " = " << suma << endl;

  // c)
  Ulamek res = dodaj(tab[0], 7);
  cout << res << endl;

  // d)
  cout << kwadratLiczby(tab[2]) << endl;

  // e)
  Ulamek u(88, 22);
  u.skrocUlamek();
  cout << u;

  // f)
  generuj(4);
}
