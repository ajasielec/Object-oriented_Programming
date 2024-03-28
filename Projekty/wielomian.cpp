#include <iostream>

using namespace std;

class Wielomian {
private:
    int stopien_wielomianu;
    double* wspolczynniki_wielomianu;

public:
    Wielomian(int st, double* wsp) {
        stopien_wielomianu = st;
        wspolczynniki_wielomianu = new double[stopien_wielomianu + 1];
        for (int i = 0; i <= stopien_wielomianu; i++) {
            wspolczynniki_wielomianu[i] = wsp[i];
        }
    }

    ~Wielomian() {
       // delete[] wspolczynniki_wielomianu;
    }

    // Wariant 2
    friend ostream& operator<<(ostream& ostr, const Wielomian& wielomian) {
        bool firstTerm = true;
        for (int i = wielomian.stopien_wielomianu; i >= 0; i--) {
            if (wielomian.wspolczynniki_wielomianu[i] != 0) {
                if (!firstTerm && wielomian.wspolczynniki_wielomianu[i] > 0) {
                    ostr << "+ ";
                }

                if (wielomian.wspolczynniki_wielomianu[i] != 1 || i == 0) {
                    ostr << wielomian.wspolczynniki_wielomianu[i];
                }

                if (i > 0) {
                    ostr << "x";
                    if (i > 1) {
                        ostr << "^" << i;
                    }
                }

                firstTerm = false;
            }
        }

        return ostr;
    }
    //przeciazanie +
    Wielomian operator+(const Wielomian& o) const {
        int najwStopien = max(stopien_wielomianu, o.stopien_wielomianu);
        double* sumaWsp = new double[najwStopien + 1];

        for (int i = 0; i <= najwStopien; i++) {
            double wsp1 = (i <= stopien_wielomianu) ? wspolczynniki_wielomianu[i] : 0.0;
            double wsp2 = (i <= o.stopien_wielomianu) ? o.wspolczynniki_wielomianu[i] : 0.0;

            sumaWsp[i] = wsp1 + wsp2;
        }

        Wielomian suma(najwStopien, sumaWsp);

        delete[] sumaWsp;
        return suma;
    }
    Wielomian operator*(double liczba) const {
        double* mnozWsp = new double[stopien_wielomianu + 1];

        for (int i = 0; i <= stopien_wielomianu; i++) {
            mnozWsp[i] = wspolczynniki_wielomianu[i] * liczba;
        }

        Wielomian result(stopien_wielomianu, mnozWsp);
        delete[] mnozWsp;
        return result;
    }

};


int main() {
    cout<<"a) Wariant 2\n";
    double wspolczynniki_w1[] = { -5, 1 };
    Wielomian w1(1, wspolczynniki_w1);

    double wspolczynniki_w2[] = { 1, 0, -7, -3.4 };
    Wielomian w2(3, wspolczynniki_w2);

    double wspolczynniki_w3[]={0,0,0,-7,0,7.8};
    Wielomian w3(5, wspolczynniki_w3);

    cout << w1 << endl;
    cout << w2 << endl;
    cout << w3 << endl;

    cout<<"b)\n";
    cout<<"w1 + w2 + w3 = "<<w1+w2+w3<<endl;

    cout<<"c)\n";
    cout<<"w3*3= "<<w3*3;


    return 0;
}
