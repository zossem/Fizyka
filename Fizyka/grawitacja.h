#include <iostream>
#include "wektor.h"
#define STALA_GRAWITACJI 6.67E-11

using namespace std;

#if !defined(_GRAWITACJA_H_)
#define _GRAWITACJA_H_

class cMasaKulistoSymetryczna
{
public:

    cMasaKulistoSymetryczna(double Masa=5.98E24, double RPromien=6.37E6, double WspX=0.0, double WspY=0.0, double WspZ=0.0);

    cWektor SilaGrawitacji(cMasaKulistoSymetryczna Masa);
    cWektor NatezeniePolaGrawitacyjnego(cMasaKulistoSymetryczna Masa);
    double EnergiaPotencjalna(cMasaKulistoSymetryczna Masa);
    double PotencjalGrawitacyjny(cMasaKulistoSymetryczna Masa);
    double PierwszaPredkoscKosmiczna();
    double DrugaPredkoscKosmiczna();
    double SzybkoscOrbitowaniaPlanety(cMasaKulistoSymetryczna Masa);
    double SzybkoscOrbitowania(cMasaKulistoSymetryczna Masa);

    void Wpisz();
    void Wypisz();

    double Masa();
    double RPromien();
    double WspX();
    double WspY();
    double WspZ();
private:
    double m_Masa, m_RPromien, m_WspX, m_WspY, m_WspZ;
};
#endif //_GRAWITACJA_H_
