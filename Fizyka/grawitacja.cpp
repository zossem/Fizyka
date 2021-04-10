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
    double Odleglosc=sqrt((m_WspZ-Masa.WspZ())*(m_WspZ-Masa.WspZ())+((m_WspX-Masa.WspX())*(m_WspX-Masa.WspX())+(m_WspY-Masa.WspY())*(m_WspY-Masa.WspY())));
    double EnergiaPotencjalna;
    EnergiaPotencjalna=(-1)*STALA_GRAWITACJI*m_Masa*Masa.Masa()/Odleglosc;
    return EnergiaPotencjalna;
}

double cMasaKulistoSymetryczna::PotencjalGrawitacyjny(cMasaKulistoSymetryczna Masa)
{
    double Ep=EnergiaPotencjalna(Masa);
    double Potencjal=Ep/Masa.Masa();
    return Potencjal;
}

double cMasaKulistoSymetryczna::PierwszaPredkoscKosmiczna()
{
    if(m_RPromien>0)
    {
        double PierwszaPredkoscKosmiczna=sqrt(STALA_GRAWITACJI*m_Masa/m_RPromien);
        return PierwszaPredkoscKosmiczna;
    }
    else
    {
        return -1;
    }
}

double cMasaKulistoSymetryczna::DrugaPredkoscKosmiczna()
{
    double DrugaPredkoscKosmiczna=PierwszaPredkoscKosmiczna()*sqrt(2);
    if(DrugaPredkoscKosmiczna>0)
    {
        return DrugaPredkoscKosmiczna;
    }
    else
    {
        return -1;
    }
}

double cMasaKulistoSymetryczna::SzybkoscOrbitowaniaPlanety(cMasaKulistoSymetryczna Masa)
{
    double Odleglosc=sqrt((m_WspZ-Masa.WspZ())*(m_WspZ-Masa.WspZ())+((m_WspX-Masa.WspX())*(m_WspX-Masa.WspX())+(m_WspY-Masa.WspY())*(m_WspY-Masa.WspY())));
    double XSrodkaMasy=Odleglosc*m_Masa/(m_Masa+Masa.Masa());
    double Predkosc=sqrt(m_Masa*STALA_GRAWITACJI*(Odleglosc-XSrodkaMasy)/(Odleglosc*Odleglosc));
    return Predkosc;
}

double cMasaKulistoSymetryczna::SzybkoscOrbitowania(cMasaKulistoSymetryczna Masa)
{
    double Odleglosc=sqrt((m_WspZ-Masa.WspZ())*(m_WspZ-Masa.WspZ())+((m_WspX-Masa.WspX())*(m_WspX-Masa.WspX())+(m_WspY-Masa.WspY())*(m_WspY-Masa.WspY())));
    if(m_RPromien>0)
    {
        double Predkosc=sqrt(STALA_GRAWITACJI*m_Masa/Odleglosc);
        return Predkosc;
    }
    else
    {
        return -1;
    }
}

void cMasaKulistoSymetryczna::Wpisz()
{
    double Masa, RPromien, WspX, WspY, WspZ;
    printf("Podaj mase obiektu: ");
    scanf("%lf", &Masa);
    printf("\nPodaj promien obiektu: ");
    scanf("%lf", &RPromien);
    printf("\nPodaj wspolzedna x obiektu: ");
    scanf("%lf", &WspX);
    printf("\nPodaj wspolzedna y obiektu: ");
    scanf("%lf", &WspY);
    printf("\nPodaj wspolzedna z obiektu: ");
    scanf("%lf", &WspZ);
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

void cMasaKulistoSymetryczna::Wypisz()
{
    printf("Obiekt ma\nmase: %le\npromien: %le\nwspolrzedne xyz(%le;%le;%le)\n", m_Masa, m_RPromien, m_WspX, m_WspY, m_WspZ);
}

double cMasaKulistoSymetryczna::Masa(){return m_Masa;}

double cMasaKulistoSymetryczna::RPromien(){return m_RPromien;}

double cMasaKulistoSymetryczna::WspX(){return m_WspX;}

double cMasaKulistoSymetryczna::WspY(){return m_WspY;}

double cMasaKulistoSymetryczna::WspZ(){return m_WspZ;}
