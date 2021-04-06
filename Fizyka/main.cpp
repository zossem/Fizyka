#include <iostream>

using namespace std;

class Masa_punktowa
{
private:
    double M;
    string jednostki_M;

    double x;
    string jednostki_x;

    double y;
    string jednostki_y;

    double z;
    string jednostki_z;

    string nazwa;
public:

    Masa_punktowa(double masa, string jednostki_masy, double wspolrzendna_x, string jednostki_wspolrzendna_x, double wspolrzendna_y, string jednostki_wspolrzendna_y, double wspolrzendna_z, string jednostki_wspolrzendna_z, string name);
    void wypisz();


};
int main()
{
    Masa_punktowa herbatniki(0.005, 'kg',7.6, 'me', 4.7, 'm', 0.8, 'me','herbatniki');

    poczatek.wypisz();

    printf("suma=%d\n", poczatek.suma());
    return 0;
}


Masa_punktowa::Masa_punktowaMasa_punktowa(double masa, string jednostki_masy, double wspolrzendna_x, string jednostki_wspolrzendna_x, double wspolrzendna_y, string jednostki_wspolrzendna_y, double wspolrzendna_z, string jednostki_wspolrzendna_z, string name)
{
    this->M=masa;
    this->jednostki_M=jednostki_masy;
    this->x=wspolrzendna_x;
    this->jednostki_x=jednostki_wspolrzendna_x;
    this->y=wspolrzendna_y;
    this->jednostki_y=jednostki_wspolrzendna_y;
    this->y=wspolrzendna_z;
    this->jednostki_y=jednostki_wspolrzendna_z;
    this->nazwa=name;
}

void Masa_punktowa::wypisz()
{
    printf("%c(%d;%d)\n", this->nazwa,this->x, this->y);
}
