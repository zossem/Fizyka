#include <iostream>
#include <vector>

using namespace std;

#if !defined(_WEKTOR_H_)
#define _WEKTOR_H_

class cWektor
{
public:
    cWektor(double WspPunktuX=0.0, double WspPunktuY=0.0, double WspPunktuZ=0.0, double WspWektoraX=0.0, double WspWektoraY=0.0, double WspWektoraZ=0.0, double Wartosc=0.0);
    cWektor DodawanieWektorow(vector <cWektor> Skladowe);

    void Wypisz();

    double WspPunktuX();
    double WspPunktuY();
    double WspPunktuZ();
    double WspWektoraX();
    double WspWektoraY();
    double WspWektoraZ();
    double Wartosc();
private:
    double m_WspPunktuX, m_WspPunktuY, m_WspPunktuZ, m_WspWektoraX, m_WspWektoraY, m_WspWektoraZ, m_Wartosc;
};

#endif //_WEKTOR_H_
