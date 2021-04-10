#include <iostream>
#include <math.h>
#include "grawitacja.h"


using namespace std;

cMasaKulistoSymetryczna::cMasaKulistoSymetryczna(double Masa, double RPromien, double WspX, double WspY, double WspZ)
{
    if(Masa>0)
    {
        m_Masa=Masa;
    }
    else
    {
        printf("Masa obiektu musi byc wieksza od zera\n");
    }
    if(RPromien>=0)
    {
        m_RPromien=RPromien;
    }
    else
    {
        printf("Promien obiektu musi byc rowny lub wiekszy od zera\n");
        exit(2);
    }
    m_WspX=WspX;
    m_WspY=WspY;
    m_WspZ=WspZ;
}

cWektor cMasaKulistoSymetryczna::SilaGrawitacji(cMasaKulistoSymetryczna Masa)
{
    double Odleglosc=sqrt((m_WspZ-Masa.WspZ())*(m_WspZ-Masa.WspZ())+((m_WspX-Masa.WspX())*(m_WspX-Masa.WspX())+(m_WspY-Masa.WspY())*(m_WspY-Masa.WspY())));
    double Wartosc=STALA_GRAWITACJI*m_Masa*Masa.Masa()/(Odleglosc*Odleglosc);
    double WspPunktuX=Masa.WspX();
    double WspPunktuY=Masa.WspY();
    double WspPunktuZ=Masa.WspZ();

    double a, e; //y=ax+b z=cy+d z=ex+f
    a=(Masa.WspY()-m_WspY)/(Masa.WspX()-m_WspX);
    e=(Masa.WspZ()-m_WspZ)/(Masa.WspX()-m_WspX);

    double WspWektoraX=abs(Wartosc/sqrt(e*e+a*a+1));
    double WspWektoraY=abs(WspWektoraX*a);
    double WspWektoraZ=abs(WspWektoraX*e);

    if(Masa.WspX()>m_WspX)
        WspWektoraX*=(-1);
    if(Masa.WspY()>m_WspY)
        WspWektoraY*=(-1);
    if(Masa.WspZ()>m_WspZ)
        WspWektoraZ*=(-1);

    cWektor rezultat(WspPunktuX, WspPunktuY, WspPunktuZ, WspWektoraX, WspWektoraY, WspWektoraZ, Wartosc);
    return rezultat;
}

cWektor cMasaKulistoSymetryczna::NatezeniePolaGrawitacyjnego(cMasaKulistoSymetryczna Masa)
{
    cWektor Fg;
    Fg=SilaGrawitacji(Masa);
    cWektor rezultat;
    rezultat=Fg.Dzielenie(Masa.Masa());

    return rezultat;
}

double cMasaKulistoSymetryczna::EnergiaPotencjalna(cMasaKulistoSymetryczna Masa)
{

}

double cMasaKulistoSymetryczna::PotencjalGrawitacyjny(cMasaKulistoSymetryczna Masa)
{

}

double cMasaKulistoSymetryczna::PierwszaPredkoscKosmiczna()
{

}

double cMasaKulistoSymetryczna::DrugaPredkoscKosmiczna()
{

}

double cMasaKulistoSymetryczna::SzybkoscOrbitowania(cMasaKulistoSymetryczna Masa)
{

}


void cMasaKulistoSymetryczna::Wypisz()
{
    printf("Obiekt ma\nmase: %le\npromien: %le\nwspolrzedne xyz(%le;%le;%le)\n", m_Masa, m_RPromien, m_WspX, m_WspY, m_WspZ);
}

double cMasaKulistoSymetryczna::Masa(){return m_Masa;}

double cMasaKulistoSymetryczna::RPromien(){return m_RPromien;}

double cMasaKulistoSymetryczna::WspX(){return m_WspX;}

double cMasaKulistoSymetryczna::WspY(){return m_WspY;}

double cMasaKulistoSymetryczna::WspZ(){return m_WspZ;}
