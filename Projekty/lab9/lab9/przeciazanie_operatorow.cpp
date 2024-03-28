#include <iostream>
#include <math.h>
using namespace std;

class LiczbaZespolona {
	friend ostream& operator << (ostream&, const LiczbaZespolona&);
private:
	float re, im;
public:
	LiczbaZespolona() {
		re = 0;
		im = 0;
	}
	LiczbaZespolona(float re, float im) {
		this->re = re;
		this->im = im;
	}

	LiczbaZespolona operator+(LiczbaZespolona l) {
		LiczbaZespolona res(re + l.re, im + l.im);
		return res;
	}

	LiczbaZespolona operator*(LiczbaZespolona l) {
		LiczbaZespolona res;
		res.re = (re * l.re) - (im * l.im);
		res.im = (im * l.re) + (re * l.im);
		return res;
	}

	LiczbaZespolona operator/(LiczbaZespolona l) {
		LiczbaZespolona sprezenie = l, res;
		sprezenie.im *= -1;
		res.re = (re * sprezenie.re) - (im * sprezenie.im);
		res.im = (im * sprezenie.re) + (re * sprezenie.im);
		res.re /= pow(l.re, 2) + pow(l.im, 2);
		res.im /= pow(l.re, 2) + pow(l.im, 2);
		return res;
	}
};


//przeciazenie <<
ostream& operator <<(ostream& os, const LiczbaZespolona& lz) {
	if (lz.im == 0) {
		os << lz.re;
	}

	else if (lz.im == 1) {
		os << lz.re << " + i";
	}
	else if (lz.im == -1) {
		os << lz.re << " - i";
	}

	else if (lz.im < 0) {
		os << lz.re << " - " << abs(lz.im) << "i";
	}

	else	os << lz.re << " + " << lz.im << "i";

	return os;
}

int main() {
	//a)
	LiczbaZespolona z1(2, 1), z2(-3, -7);
	cout << "z1 = " << z1 << "\nz2 = " << z2 << endl;

	//b)
	cout << "z1 + z2 = " << z1 + z2 << endl;

	//c)
	cout << "z1 * z2 = " << z1 * z2 << endl;

	//d)
	cout << "z1 / z2 = " << z1 / z2 << endl;

	return 0;
}