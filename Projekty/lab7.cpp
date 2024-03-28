#include <iostream>
#include <math.h>
using namespace std;

// gcd
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
  friend Ulamek podziel(Ulamek, Ulamek);
  friend ostream &operator<<(ostream &, Ulamek &);
  friend void ileNieskracalnych(int);

private:
  int licznik;
  int mianownik;

public:
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

  void liczbaMieszana() {
    if (licznik > mianownik) {
      int c, nowy_l;
      c = licznik / mianownik;
      nowy_l = licznik % mianownik;
      cout << c << " i " << nowy_l << "/" << mianownik;
    }
  }
  void wypisz() { cout << licznik << "/" << mianownik << endl; }
};

// b)
Ulamek podziel(Ulamek u1, Ulamek u2) {
  int l = u1.licznik * u2.mianownik;
  int m = u1.mianownik * u2.licznik;
  Ulamek wynik(l, m);
  return wynik;
}

// d)
double pierwiastkuj(double liczba) { return (pow(liczba, 2)); }

// f)
void ileNieskracalnych(int liczba) {
  int counter = 0;
  Ulamek tab [liczba];
  for (int i = 1; i < liczba; i++) {

    // Ulamek u(i, liczba);
    if (GCD(i, liczba) == 1) {
      tab[counter] = Ulamek(i, liczba);
      counter++;
    }
  }
  cout << "\nDla liczby " << liczba << " istnieja " << counter
       << " ulamki nieskracalne:";
  for (int i = 0; i < counter; i++) {
    cout << tab[i] << endl;
  }
}

// przeciazenie operatora <<
ostream &operator<<(ostream &res, Ulamek &u) {
  res << u.licznik << "/" << u.mianownik;
  return res;
}

int main() {
  // a)
  Ulamek u1(2, 3);
  Ulamek u2(3, 4);
  u1.wypisz();
  u2.wypisz();

  // b)
  Ulamek wynikb = podziel(u1, u2);
  cout << wynikb << endl;

  // c)
  Ulamek wynikc = podziel(u1, 4);
  cout << wynikc << endl;

  // d)
  cout << pierwiastkuj(u1) << endl;

  // e)
  Ulamek u3(53, 12);
  u3.liczbaMieszana();
  cout << endl;

  // f)
  ileNieskracalnych(7);
  ileNieskracalnych(25);
  ileNieskracalnych(54);

  return 0;
}