#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

class Ulamek{
    private:
        friend ostream& operator << (ostream&, Ulamek&);
        friend Ulamek dodaj(Ulamek a, Ulamek b);
        int licznik, mianownik;

        int NWD(int a, int b){
            int aux;

            while(b!=0){
                aux = b;
                b = a%b;
                a = aux;
            }
            return a;
        }
    public:
        Ulamek(int l, int m){
            licznik = l;
            mianownik = m;
        }
        //konstr konwertujący
        Ulamek(int l): licznik(l), mianownik(1){}
        //operator konwersji
        operator double(){
            return static_cast<double>(licznik)/static_cast<double>(mianownik);
        }
        // useless
        void wyswietlUlamek(){
            cout << licznik <<"/"<<mianownik << endl;
        }

        void skrocUlamek(){
            // największy wspólny dzielnik?
            while (NWD(licznik,mianownik)!=1){
                int nwd = NWD(licznik,mianownik);
                licznik /= nwd;
                mianownik /= nwd;
            }

        }
};
ostream& operator << (ostream& os, Ulamek& u){
    os << u.licznik << "/" << u.mianownik;
    return os;
}
Ulamek dodaj(Ulamek a, Ulamek b){
    int l = a.licznik * b.mianownik + b.licznik * a.mianownik;
    int m = a.mianownik * b.mianownik;

    Ulamek dodany(l,m);

    return dodany;
}
double kwadratLiczby(double liczba){
    double toReturn = pow(liczba,2);
    return toReturn;
}
int main(){
    srand(unsigned(time(NULL)));
    string odstep = "----------------------------------\n";
    // a)
    cout << odstep;
    Ulamek ulamki[3] = {{1,2},{5,8},{7,9}};
    // ulamki[0].wyswietlUlamek();
    // ulamki[1].wyswietlUlamek();
    // ulamki[2].wyswietlUlamek();
    cout << ulamki[0] << endl;
    cout << ulamki[1] << endl;
    cout << ulamki[2] << endl;
    // b)
    //wychodzi na to że nie mogę "w biegu" wypisać wyniku funkcji 
    cout << odstep;
    Ulamek out = dodaj(ulamki[0], ulamki[1]);
    cout << "1/2 + 5/8 = " << out << endl;

    // c)
    cout << odstep;
    Ulamek out2 = dodaj(ulamki[0], 7);
    cout << "1/2 + 7 = " << out2 << endl;

    // d)
    cout <<odstep;
    double out3 = kwadratLiczby(ulamki[2]);
    cout << "(7/9)^2 = " << out3 << endl;
    
    // e)
    cout << odstep;
    Ulamek out4(88,22);
    out4.skrocUlamek();
    cout << out4 << endl;

    // f)
    cout << odstep;
    int n = 10;
    Ulamek losowe_Ulamki[n] = Ulamek(rand()%2001 - 1000, rand()%1001 - 1000);
    for (int index = 0; index < n; index++){
        cout << "[" << index << "]: " << losowe_Ulamki[index] << endl;
    }
    //convert them to double and compare 
    double max = losowe_Ulamki[0];  //decimal fraction
    int biggestIndex = 0;   //fraction
    for(int j = 1; j < n; j++ ){
        double toCompare = losowe_Ulamki[j];
        if(toCompare> max){
            max = toCompare;
            biggestIndex = j;
        }
         
    }
    cout << "Biggest value: " << losowe_Ulamki[biggestIndex] << " (" << max << ")\n";
    return 0;
}