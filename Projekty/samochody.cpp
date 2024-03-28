#include <iostream>
using namespace std;

// stwórz klasę Samochod:
class Samochod {
  friend class Garaz;
  // pola
private:
  string marka = "brak";
  string model = "brak";
  float cena = 0;

  // metody
public:
  Samochod(string mar, string mod, float c) {
    marka = mar;
    model = mod;
    cena = c;
  }

  Samochod(){}
  void przypisz(string mar, string mod, float c) {
    marka = mar;
    model = mod;
    cena = c;
  }
  void wyswietlSamochod() {
    cout << "Marka: " << marka << ", model: " << model << ", cena: " << cena
         << endl;
  }
};

// Stworz klase garaz
class Garaz {
  friend class Samochod;
  // pola
private:
  string nazwa;
  Samochod * samochody[15];
  int licznik=0;

  // metody
public:
  // konstruktor wieloargumentowy() – ma wyświetlać nazwę tworzonego garażu
  Garaz(string n) {
    nazwa = n;
    cout << "Nazwa utworzonego garazu: " << nazwa << endl;
  }

void dodajSamochod(Samochod s[], int ilosc){
  if (licznik+ilosc <= 15){
  licznik += ilosc;
    for (int i=0; i<ilosc; i++){
      samochody[licznik-i-1] = &s[i];
    }
  }
  else {
    cout << "Brak miejsc w garażu "<< nazwa<< endl;
   return;
  }
}

void wyswietlGaraz(){
  cout << "Nazwa: " << nazwa << ", samochody: " << endl;
  
  for (int i=0; i<licznik; i++){
    cout << i+1 << ": ";
   samochody[i]->wyswietlSamochod();
  }
}

  // wartoscAut() – zwraca wartość samochodów z garażu
  float wartoscAut() {
    float wartosc = 0;
    for (int i = 0; i < licznik; i++) {
      wartosc += samochody[i]->cena;
    }
    return wartosc;
  }
};

int main() {
  Samochod s1("Toyota", "Yaris", 2137.69);
  Samochod s2("Toyota2", "Yaris", 2137.69);
  Samochod s3("Toyota3", "Yaris", 2137.69);
  Samochod s4("Toyota4", "Yaris", 2137.69);
  Samochod s5("Toyota5", "Yaris", 2137.69);

  // a)
  cout<<"a)\n";
  // Utwórz dwie tablice obiektów klasy Samochod o dowolnych polach. Wielkość
  // pierwszej tablicy to 2. Wielkość drugiej tablicy to 3.
  Samochod t_dwoch_sam[2] = {s1, s2};
  Samochod t_trzech_sam[3] = {s3, s4, s5};

  t_dwoch_sam[0].wyswietlSamochod();
  t_dwoch_sam[1].wyswietlSamochod();
  t_trzech_sam[0].wyswietlSamochod();
  t_trzech_sam[1].wyswietlSamochod();
  t_trzech_sam[2].wyswietlSamochod();

  // b)
  cout<<"\nb)\n";
  // Utwórz dwa obiekty klasy Garaz przy użyciu konstruktora wieloargumentowego.
  Garaz garaz1("Garaz 1");
  Garaz garaz2("Garaz 2");

//c)
  cout<<"\nc)\n";
  // Do pierwszego garażu dodaj samochody z tablicy 2-elementowej.
  garaz1.dodajSamochod(t_dwoch_sam, 2);
  //Do drugiego garażu dodaj samochody z obu tablic.
  garaz2.dodajSamochod(t_dwoch_sam, 2);
  garaz2.dodajSamochod(t_trzech_sam, 3);



//Wyświetl dane garażów, wraz z samochodami, jakie się w nich znajdują.
  garaz1.wyswietlGaraz();
  garaz2.wyswietlGaraz();
  
  //d)
  cout<<"\nd)\n";
  //Wyświetl wartość obu garaży
  cout << "Wartosc aut w garazu 1: " << garaz1.wartoscAut() << endl;
  cout << "Wartosc aut w garazu 2: " << garaz2.wartoscAut() << endl;

}