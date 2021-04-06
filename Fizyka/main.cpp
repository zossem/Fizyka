#include <iostream>
#include "grawitacja.h"
#include "wektor.h"


using namespace std;


int main()
{
    cMasaKulistoSymetryczna Ksiezyc(7.347673E22, 1737000, 384399000, 0, 0);
    cMasaKulistoSymetryczna Ziemia;
    cWektor SilaG;
    SilaG=Ziemia.SilaGrawitacji(Ksiezyc);
    SilaG.Wypisz();

    return 0;
}
