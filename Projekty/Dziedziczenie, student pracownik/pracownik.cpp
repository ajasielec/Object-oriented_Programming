#include <iostream>
using namespace std;

class Osoba {
protected:
	string imie, nazwisko;
	int rokUr;
private:
	friend ostream& operator << (ostream&, Osoba&);
	
public:
	Osoba(string i, string n, int r) {
		imie = i;
		nazwisko = n;
		rokUr = r;
	}
	int getrokUr(){
		return rokUr;
	}
	
};
class Student : public Osoba {
private:
	string kierStud;
	int rokStud;
friend ostream& operator << (ostream&, Student);
public:	
	Student(string i, string n, int rU, string k, int rS) : Osoba(i, n, rU) {
		kierStud = k;
		rokStud = rS;
	}

};
class Pracownik : public Osoba {
private:
	string miejscePracy, zawod;
	friend ostream& operator << (ostream&, Pracownik);
public:
	Pracownik(string i, string n, int rU, string mp, string zaw): Osoba(i,n,rU){
		miejscePracy = mp;
		zawod = zaw;
	}
	Pracownik(Pracownik& p, string n, int r) : Osoba(p.imie, n, r){
		miejscePracy = p.miejscePracy;
		zawod = p.zawod;
	}
};

ostream& operator << (ostream& os, Osoba& o) {
	os << o.imie << " " << o.nazwisko << " " << o.rokUr;
	return os;
}
ostream& operator << (ostream& os, Student s){
	os << s.imie << " " << s.nazwisko << " " << s.rokUr << " ";
	os << s.kierStud << " " << s.rokStud; 
	return os;
}
ostream& operator << (ostream& os, Pracownik p){
	os << p.imie << " " << p.nazwisko << " " << p.rokUr << " ";
	os << p.miejscePracy << " " << p.zawod;
	return os;
}
//Size - zmienna do mniejNiz30() bo nie mam jak dostac sie do rozmiaru nowej tablicy;
static int Size = 0;
Osoba** mniejNiz30(Osoba* osoby[], int size){
	Size = 0;
	//int* indexes;
	for(int i = 0; i < size; i++){
		if(2023 - osoby[i]->getrokUr() > 30){
			Size++;
		}	
	}
	Osoba** newOsoby = new Osoba*[Size];

	for(int i = 0; i < size; i++){
		if(2023 - osoby[i]->getrokUr() > 30){
			newOsoby[i] = osoby[i];
		}	
	}

	return newOsoby;
}
int main() {
	string seperate = "-------------------\n";
	//a)
	Osoba* osoba = new Osoba("Andrzej", "Psikuta", 2000);
	cout << *osoba  << endl;
	cout << seperate;

	//b)
	Student student("Marek", "Towarek", 2003, "IT", 1);
	cout << student << endl;
	cout << seperate;

	//c)
	Pracownik pracownik1("ladny", "prosty", 1980, "hga", "fizyk");
	Pracownik pracownik2(pracownik1, "Woda", 1930);

	cout << pracownik1 << endl;
	cout << pracownik2 << endl;
	cout << seperate;

	//d)
	Osoba** osoby = new Osoba*[4];
	osoby[0] = osoba;
	osoby[1] = &student;
	osoby[2] = &pracownik1;
	osoby[3] = &pracownik2;

	cout << "d)\n";
	for(int i = 0; i < 4; i++){
		cout << *osoby[i] << endl; 
	}
	cout << "e)\n";

	//zadanie z pointerami nie byloby sobą gdyby jego wynik nie zwracałby szatanskich znakow, w razie potrzeby, usunąć i się nie martwić
	Osoba** osoby2 = mniejNiz30(osoby, 4);
	// for(int i = 0; i < Size; i++){
	// 	cout << *osoby2[i] << endl;
	// }
	delete osoba;
	delete[] osoby;
	return 0;
}