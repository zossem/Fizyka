#include <iostream>
#include "grawitacja.h"
#include <stdio.h>
#include<cstdlib>



using namespace std;


int main()
{
    int wybor;
    double wynik;
    cWektor Wektor;
    cMasaKulistoSymetryczna ObiektGowny;
    cMasaKulistoSymetryczna MasaProbna;
    for(;;)
    {
        printf("Gowny obiekt obecnie to: ");
        ObiektGowny.Wypisz();
        printf("Co mam zrobic?\n");
        printf("1. Zmien obiekt gowny\n");
        printf("2. Oblicz sile grawitacji dzialajaca na cialo\n");
        printf("3. Natezenie pola grawitacyjnego\n");
        printf("4. Oblicz energie potencjalna\n");
        printf("5. Oblicz potencjal grawitacyjny\n");
        printf("6. Oblicz pierwsza predkosc kosmiczna\n");
        printf("7. Oblicz druga predkosc kosmiczna\n");
        printf("8. Oblicz predkosc orbitowania\n");
        printf("9. Oblicz predkosc orbitowania planet wokol siebie\n");
        scanf("%d", &wybor);

        switch(wybor)
        {
            case 1:
            {
                system("cls");
                ObiektGowny.Wpisz();
                break;
            }
            case 2:
            {
                system("cls");
                printf("Podaj parametry masy probnej:\n");
                MasaProbna.Wpisz();
                Wektor=ObiektGowny.SilaGrawitacji(MasaProbna);
                Wektor.Wypisz();
                break;
            }
            case 3:
            {
                system("cls");
                printf("Podaj parametry masy probnej:\n");
                MasaProbna.Wpisz();
                Wektor=ObiektGowny.NatezeniePolaGrawitacyjnego(MasaProbna);
                Wektor.Wypisz();
                break;
            }
            case 4:
            {
                system("cls");
                printf("Podaj parametry masy probnej:\n");
                MasaProbna.Wpisz();
                wynik=ObiektGowny.EnergiaPotencjalna(MasaProbna);
                printf("%e", wynik);
                break;
            }
            case 5:
            {
                system("cls");
                printf("Podaj parametry masy probnej:\n");
                MasaProbna.Wpisz();
                wynik=ObiektGowny.PotencjalGrawitacyjny(MasaProbna);
                printf("%e", wynik);
                break;
            }
            case 6:
            {
                system("cls");
                wynik=ObiektGowny.PierwszaPredkoscKosmiczna();
                printf("%e", wynik);
                break;
            }
            case 7:
            {
                system("cls");
                wynik=ObiektGowny.DrugaPredkoscKosmiczna();
                printf("%e", wynik);
                break;
            }
            case 8:
            {
                system("cls");
                printf("Podaj parametry masy probnej:\n");
                MasaProbna.Wpisz();
                wynik=ObiektGowny.SzybkoscOrbitowania(MasaProbna);
                printf("%e", wynik);
                break;
            }
            case 9:
            {
                system("cls");
                printf("Podaj parametry masy probnej:\n");
                MasaProbna.Wpisz();
                wynik=ObiektGowny.SzybkoscOrbitowaniaPlanety(MasaProbna);
                printf("%e", wynik);
                break;
            }
            default:
            {
                printf("Nie mam takiej opcji\n");
                break;
            }

        }

        getchar();
        getchar();
        system("cls");
    }

    return 0;
}
