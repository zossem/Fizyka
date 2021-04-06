#include <iostream>
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

void cMasaKulistoSymetryczna::wypisz()
{
    printf("Obiekt ma\nmase: %lf\npromien: %lf\nwspolrzedne xyz(%lf;%lf;%lf)\n", m_Masa, m_RPromien, m_WspX, m_WspY, m_WspZ);
}

double cMasaKulistoSymetryczna::Masa(){return m_Masa;}

double cMasaKulistoSymetryczna::RPromien(){return m_RPromien;}

double cMasaKulistoSymetryczna::WspX(){return m_WspX;}

double cMasaKulistoSymetryczna::WspY(){return m_WspY;}

double cMasaKulistoSymetryczna::WspZ(){return m_WspZ;}
