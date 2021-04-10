#include <iostream>
#include "grawitacja.h"



using namespace std;


int main()
{
    cMasaKulistoSymetryczna herbatniki(7.34, 0, 3E9, 4E9, 12E9);
    cMasaKulistoSymetryczna Ziemia;
    cWektor SilaG, NatezeniePola;
    SilaG=Ziemia.SilaGrawitacji(herbatniki);
    SilaG.Wypisz();

    NatezeniePola=Ziemia.NatezeniePolaGrawitacyjnego(herbatniki);
    NatezeniePola.Wypisz();

    return 0;
}
