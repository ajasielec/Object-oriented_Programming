#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

class Kwadrat;
class Okrag;
class Punkt{
    private:
        friend class Kwadrat;
        friend ostream& operator<<(ostream&,const Okrag&);
        friend ostream& operator<<(ostream&, const Kwadrat&);
        //zadanie tego nie przewiduje, ale nie mam po co tworzyc getterow i setterow skoro istnieje lepsze rozwiazanie
        //klasa Punkt nie zawiera nic oprocz x,y a przyjaznie nie sa przechodnie - nie ma niebezpieczenstwa
        friend class Okrag;
        int x, y;

};

class Kwadrat{
    friend ostream& operator<<(ostream&, const Kwadrat&);
    private:
        Punkt start,end;
        double d, a, pole;
    public: 
        Kwadrat(int sx, int sy, int ex, int ey){
            start.x = sx;
            start.y = sy;
            end.x = ex;
            end.y = ey;
        }
        
        double Pole_kwadratu(){
           // cout << "x1: " << start.x << ", x2: " << end.x << ", y1: " << start.y << ", y2: " << end.y << endl;
           //oblicz przekatna d
           d = sqrt(pow(end.x-start.x, 2) + pow(end.y - start.y,2));
           //oblicz bok kwadratu a
           a = d/sqrt(2);
           //oblicz pole
           pole = pow(a,2);

        //    cout << "d: " << d << endl;
        //    cout << "a: " << a << endl;
           return pole;

        };
};
class Okrag{
    private:
        friend ostream& operator<<(ostream&,const Okrag&);
        Punkt center;
        int radius;
        int rZewn;
        int rWewn;
    public:
        Okrag(int x, int y, int r): rZewn(0), rWewn(0){
            center.x = x;
            center.y = y;
            radius = r;
        }
        void test(){
            //tylko dla dowodu ze losowanie działa
            printf("Srodek : (%d, %d), radius: %d\n", center.x, center.y, radius);
        }
        void Rozlacznosc(Okrag o){
            double SOdl = sqrt(pow(o.center.x-center.x, 2) + pow(o.center.y - center.y,2));
            double Rsubstr = abs(o.radius - radius);
            double Rsum = o.radius + radius;
            if(SOdl < Rsubstr){
                rWewn +=1; 
                return;
            }
            if(SOdl > Rsum){
                rZewn += 1;
                return;
            }
        }
        int get_rZewn(){
            return rZewn;
        }
        int get_rWewn(){
            return rWewn;
        }
};
ostream& operator<<(ostream& os, const Okrag& okr){
    os << "Srodek okregu: [ " << okr.center.x << ", " << okr.center.y << "], radius: " << okr.radius << "\n";
    return os;
}
ostream& operator<<(ostream& os, const Kwadrat& kw){
    os << "Pole: " << kw.pole << " przekatna d: " << kw.d << "\n";
    return os;
}
int main(){
    srand(time(NULL));

    // a)
    Kwadrat kwadraty[2] ={{0,0,3,3},{-8,8,-1,1}};
    // b)
    cout << "Pole kwadratu [0]: " << kwadraty[0].Pole_kwadratu() << endl;
    cout << "Pole kwadratu [1]: " << kwadraty[1].Pole_kwadratu() << endl;

    // c)
    Okrag okregi[500] = Okrag(rand()%21 - 10, rand()%21, rand()%6+1);
    okregi[0].test();
    okregi[1].test();

    // d)
    for(int i = 1; i < 500; i++){
        okregi[0].Rozlacznosc(okregi[i]);
    }
    cout << "z iloma okrag [0] jest rozlaczny zewnetrznie: " << okregi[0].get_rZewn() << endl;
    cout << "z iloma okrag [0] jest rozlaczny wewnetrznie: " << okregi[0].get_rWewn() << endl;

    // e)
    cout << okregi[0];
    cout << kwadraty[0];
    return 0;
}