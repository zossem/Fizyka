#include <iostream>
#include "grawitacja.h"
#include <stdio.h>
#include<cstdlib>



using namespace std;


int main()
{
    vector<cMasaKulistoSymetryczna> uklad;
    vector<cMasaKulistoSymetryczna> ::iterator iter, wskaznik;
    vector<cWektor> wektory_skladowe;
    int wybor, liczba_obiektow;
    double wynik;
    cWektor Wektor, Odpowiedz;
    cMasaKulistoSymetryczna ObiektGowny;
    cMasaKulistoSymetryczna MasaProbna;
    for(;;)
    {
        printf("Wybieraj co chcesz policzyc.\n");

        printf("Czy uklad sklada sie z maksymalnie dwuch cial(nie-0, tak-1)?\n");
        scanf("%d", &wybor);
        if(wybor==0)
        {
            printf("Co mam zrobic?\n");
            printf("1. Oblicz sile grawitacji dzialajaca na cialo\n");
            printf("2. Natezenie pola grawitacyjnego\n");
            printf("3. Oblicz energie potencjalna\n");
            printf("4. Oblicz potencjal grawitacyjny\n");
            scanf("%d", &wybor);

            switch(wybor)
           {
               case 1:
               {
                   system("cls");
                   printf("Podaj liczbe obiektow (bez obiektu wzglendem ktorego jest obliczane).\n");
                   scanf("%d", &liczba_obiektow);

                    for(int i=1; i<=liczba_obiektow; i++)
                    {
                        printf("Podaj %d element.\n", i);
                        ObiektGowny.Wpisz();
                        uklad.push_back(ObiektGowny);

                    }
                    printf("Podaj obiekt wzglendem, ktorego jest obliczane.\n");
                    MasaProbna.Wpisz();
                    for(iter=uklad.begin(); iter!=uklad.end(); iter++)
                    {
                        Wektor=iter->SilaGrawitacji(MasaProbna);
                        wektory_skladowe.push_back(Wektor);
                    }

                    Odpowiedz=Odpowiedz.DodawanieWektorow(wektory_skladowe);
                    Odpowiedz.Wypisz();

                    printf("Kliknij enter aby kontynuwac.\n");
                    wektory_skladowe.clear();
                    break;
               }
               case 2:
               {
                   system("cls");
                   printf("Podaj liczbe obiektow (bez obiektu wzglendem ktorego jest obliczane).\n");
                   scanf("%d", &liczba_obiektow);

                    for(int i=1; i<=liczba_obiektow; i++)
                    {
                        printf("Podaj %d element.\n", i);
                        ObiektGowny.Wpisz();
                        uklad.push_back(ObiektGowny);

                    }

                    printf("Podaj obiekt wzglendem, ktorego jest obliczane (wartosc masy jest nieistotna).\n");
                    MasaProbna.Wpisz();
                    for(iter=uklad.begin(); iter!=uklad.end(); iter++)
                    {
                        Wektor=iter->NatezeniePolaGrawitacyjnego(MasaProbna);
                        wektory_skladowe.push_back(Wektor);
                    }

                    Odpowiedz=Odpowiedz.DodawanieWektorow(wektory_skladowe);
                    Odpowiedz.Wypisz();

                    printf("Kliknij enter aby kontynuwac.\n");
                    wektory_skladowe.clear();
                    break;
               }
               case 3:
               {
                   system("cls");
                   printf("Podaj liczbe obiektow.\n");
                   scanf("%d", &liczba_obiektow);

                    for(int i=1; i<=liczba_obiektow; i++)
                    {
                        printf("Podaj %d element.\n", i);
                        ObiektGowny.Wpisz();
                        uklad.push_back(ObiektGowny);

                    }
                    wynik=0;
                    for(iter=uklad.begin(); iter!=uklad.end(); iter++)
                    {
                        for(wskaznik=iter; wskaznik!=uklad.end(); wskaznik++)
                        {
                            wynik+=iter->EnergiaPotencjalna(*wskaznik);
                        }
                    }
                    printf("Energia potencjalna ukladu to: %e\n", wynik);

                    printf("Kliknij enter aby kontynuwac.\n");
                    break;
               }
               case 4:
               {
                   system("cls");
                   printf("Podaj liczbe obiektow (bez obiektu wzglendem ktorego jest obliczane).\n");
                   scanf("%d", &liczba_obiektow);

                    for(int i=1; i<=liczba_obiektow; i++)
                    {
                        printf("Podaj %d element.\n", i);
                        ObiektGowny.Wpisz();
                        uklad.push_back(ObiektGowny);

                    }

                    printf("Podaj obiekt wzglendem, ktorego jest obliczane (wartosc masy jest nieistotna).\n");
                    MasaProbna.Wpisz();

                    wynik=0;

                    for(iter=uklad.begin(); iter!=uklad.end(); iter++)
                    {
                        wynik+=iter->PotencjalGrawitacyjny(MasaProbna);
                    }

                    printf("%e\n", wynik);
                    printf("Kliknij enter aby kontynuwac.\n");
                    break;
               }
               default:
               {
                   printf("Nie mam takiej opcji\n");
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }
           }

           uklad.clear();
           getchar();
           getchar();
           system("cls");
        }
        else
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
                   printf("Kliknij enter i kontynuwac.\n");
                   break;
               }
               case 2:
               {
                   system("cls");
                   printf("Podaj parametry masy probnej:\n");
                   MasaProbna.Wpisz();
                   Wektor=ObiektGowny.SilaGrawitacji(MasaProbna);
                   Wektor.Wypisz();
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }
               case 3:
               {
                   system("cls");
                   printf("Podaj parametry masy probnej (chodzi o polozenie w przestrzeni, bo masa sie skraca):\n");
                   MasaProbna.Wpisz();
                   Wektor=ObiektGowny.NatezeniePolaGrawitacyjnego(MasaProbna);
                   Wektor.Wypisz();
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }
               case 4:
               {
                   system("cls");
                   printf("Podaj parametry masy probnej:\n");
                   MasaProbna.Wpisz();
                   wynik=ObiektGowny.EnergiaPotencjalna(MasaProbna);
                   printf("%e", wynik);
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }
               case 5:
               {
                   system("cls");
                   printf("Podaj parametry masy probnej (chodzi o polozenie w przestrzeni, bo masa sie skraca):\n");
                   MasaProbna.Wpisz();
                   wynik=ObiektGowny.PotencjalGrawitacyjny(MasaProbna);
                   printf("%e", wynik);
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }
               case 6:
               {
                   system("cls");
                   wynik=ObiektGowny.PierwszaPredkoscKosmiczna();
                   printf("%e", wynik);
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }
               case 7:
               {
                   system("cls");
                   wynik=ObiektGowny.DrugaPredkoscKosmiczna();
                   printf("%e", wynik);
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }
               case 8:
               {
                   system("cls");
                   printf("Podaj parametry masy probnej:\n");
                   MasaProbna.Wpisz();
                   wynik=ObiektGowny.SzybkoscOrbitowania(MasaProbna);
                   printf("%e", wynik);
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }
               case 9:
               {
                   system("cls");
                   printf("Podaj parametry masy probnej:\n");
                   MasaProbna.Wpisz();
                   wynik=ObiektGowny.SzybkoscOrbitowaniaPlanety(MasaProbna);
                   printf("%e", wynik);
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }
               default:
               {
                   printf("Nie mam takiej opcji\n");
                   printf("Kliknij enter aby kontynuwac.\n");
                   break;
               }

           }

           getchar();
           getchar();
           system("cls");
        }
    }

    return 0;
}
