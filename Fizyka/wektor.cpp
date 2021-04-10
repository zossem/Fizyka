#include <iostream>
#include <math.h>
#include <vector>
#include "wektor.h"

using namespace std;

cWektor::cWektor(double WspPunktuX, double WspPunktuY, double WspPunktuZ, double WspWektoraX, double WspWektoraY, double WspWektoraZ, double Wartosc)
{
    m_WspPunktuX=WspPunktuX;
    m_WspPunktuY=WspPunktuY;
    m_WspPunktuZ=WspPunktuZ;
    m_WspWektoraX=WspWektoraX;
    m_WspWektoraY=WspWektoraY;
    m_WspWektoraZ=WspWektoraZ;
    m_Wartosc=Wartosc;
}

cWektor cWektor::DodawanieWektorow(vector <cWektor> Skladowe)
{
    vector<cWektor>::iterator wsk=Skladowe.begin();
    double WspWekX=0, WspWekY=0, WspWekZ=0, Wartosc;
    cWektor WekSkladowy=*wsk;
    double WspPunktuX=WekSkladowy.WspPunktuX();
    double WspPunktuY=WekSkladowy.WspPunktuY();
    double WspPunktuZ=WekSkladowy.WspPunktuZ();

    while(wsk!=Skladowe.end())
    {
        WekSkladowy=*wsk;
        WspWekX+=WekSkladowy.WspWektoraX();
        WspWekY+=WekSkladowy.WspWektoraY();
        WspWekZ+=WekSkladowy.WspWektoraZ();
        wsk++;
    }

    Wartosc=sqrt(WspWekZ*WspWekZ+(WspWekX*WspWekX+WspWekY*WspWekY));

    cWektor rezultat(WspPunktuX, WspPunktuY, WspPunktuZ, WspWekX, WspWekY, WspWekZ, Wartosc);
    return rezultat;
}

cWektor cWektor::Dzielenie(double dzielnik)
{
    double Wartosc=m_Wartosc/dzielnik;
    double WspWektoraX=m_WspWektoraX/dzielnik;
    double WspWektoraY=m_WspWektoraY/dzielnik;
    double WspWektoraZ=m_WspWektoraZ/dzielnik;

    cWektor rezultat(m_WspPunktuX, m_WspPunktuY, m_WspPunktuZ, WspWektoraX, WspWektoraY, WspWektoraZ, Wartosc);
    return rezultat;
}

void cWektor::Wypisz()
{
    printf("Wektor [%le;%le;%le]\nzaczepiony w punkcie xyz(%le;%le;%le)\no wartosci:%le\n", m_WspWektoraX, m_WspWektoraY, m_WspWektoraZ, m_WspPunktuX, m_WspPunktuY, m_WspPunktuZ, m_Wartosc);
}

double cWektor::WspPunktuX(){return m_WspPunktuX;}

double cWektor::WspPunktuY(){return m_WspPunktuY;}

double cWektor::WspPunktuZ(){return m_WspPunktuZ;}

double cWektor::WspWektoraX(){return m_WspWektoraX;}

double cWektor::WspWektoraY(){return m_WspWektoraY;}

double cWektor::WspWektoraZ(){return m_WspWektoraZ;}

double cWektor::Wartosc(){return m_Wartosc;}
