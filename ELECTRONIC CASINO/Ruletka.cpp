#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int wylosowanyNumer;
int liczbaProcent;

int losowanieNumeru()
{
    int liczbaWylosowana;
    liczbaWylosowana = rand() % 37;

    return liczbaWylosowana;
}

int losowanieProcentowe()
{
    liczbaProcent = rand() % 100;

    return liczbaProcent;
}

int losowanieKoloru(int liczbaProcent)
{
    int wylosowanyKolor;
    if (liczbaProcent > 65)
    {
        wylosowanyKolor = 1;
    }
    else if ((liczbaProcent >= 60) && (liczbaProcent <= 65))
    {
        wylosowanyKolor = 0;
    }
    else if (liczbaProcent < 60)
    {
        wylosowanyKolor = 2;
    }

    return wylosowanyKolor;
}

int losowanieTrojki(int liczbaProcent)
{
    int wylosowanaTrojka = 0;

    if (liczbaProcent <= 9)
    {
        wylosowanaTrojka = 1;
    }
    else if (liczbaProcent <= 17)
    {
        wylosowanaTrojka = 2;
    }
    else if (liczbaProcent <= 25)
    {
        wylosowanaTrojka = 3;
    }
    else if (liczbaProcent <= 34)
    {
        wylosowanaTrojka = 4;
    }
    else if (liczbaProcent <= 42)
    {
        wylosowanaTrojka = 5;
    }
    else if (liczbaProcent <= 50)
    {
        wylosowanaTrojka = 6;
    }
    else if (liczbaProcent <= 58)
    {
        wylosowanaTrojka = 7;
    }
    else if (liczbaProcent <= 67)
    {
        wylosowanaTrojka = 8;
    }
    else if (liczbaProcent <= 75)
    {
        wylosowanaTrojka = 9;
    }
    else if (liczbaProcent <= 83)
    {
        wylosowanaTrojka = 10;
    }
    else if (liczbaProcent <= 92)
    {
        wylosowanaTrojka = 11;
    }
    else if (liczbaProcent <= 100)
    {
        wylosowanaTrojka = 12;
    }

    return wylosowanaTrojka;
}

int losowanieDwunastki(int liczbaProcent)
{
    int wylosowanaDwunastka = 0;

    if (liczbaProcent <= 34)
    {
        wylosowanaDwunastka = 1;
    }
    else if (liczbaProcent <= 67)
    {
        wylosowanaDwunastka = 2;
    }
    else if (liczbaProcent <= 100)
    {
        wylosowanaDwunastka = 3;
    }

    return wylosowanaDwunastka;
}

bool Gramy_w_ruletke()
{
    srand(time(NULL));
    int WartosciPol[37]{}, i = 0, wybranyNumer = 0, ilZetonow = 0, wybor = 0, wybranaTrojka = 0, wybranaDwunastka = 0;
    bool GraczWin = false;
    string KolorPol[37], wyborKolor = "", tablicaTrojek[12] = { "1-3", "4-6", "7-9", "10-12", "13-15", "16-18", "19-21", "22-24", "25-27", "28-30", "31-33", "34-36" };
    string tablicaDwunastek[3] = { "1-12", "13-24", "25-36" };
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    for (i; i < 37; i++)
    {
        if (((i % 2) == 1) && (i != 0))
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            WartosciPol[i] = { i };
            KolorPol[i] = { "czerwony" };
            cout << WartosciPol[i] << " - " << KolorPol[i] << endl;
        }
        else if (((i % 2) == 0) && (i != 0))
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            WartosciPol[i] = { i };
            KolorPol[i] = { "czarny" };
            cout << WartosciPol[i] << " - " << KolorPol[i] << endl;
        }
        else
        {
            SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_INTENSITY);
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
            WartosciPol[i] = { i };
            KolorPol[i] = { "zielony" };
            cout << WartosciPol[i] << " - " << KolorPol[i] << endl;
        }
        Sleep(50);
    }
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
    cout << endl;
    cout << "Wybierz:";
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu
    cout << endl;
    cout << "1 by obstawic kolor\n2 by obstawic liczbe\n3 by obstawic trojke\n4 by obstawic dwunastke" << endl;
    cin >> wybor;
    cout << endl;
    cout << endl;

    if (wybor == 1)
    {
        liczbaProcent = losowanieProcentowe();
        wylosowanyNumer = losowanieKoloru(liczbaProcent);

        do
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Wybierz kolor:";
            cout << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);// Kolor textu Czerwony
            cout << "- czerwony";  cout << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);// Kolor textu Bia�y
            cout << "- czarny";   cout << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Kolor textu Zielony
            cout << "- zielony";   cout << endl;

            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //Kolor Bia�y reszty textu
            cin >> wyborKolor;

        } while ((wyborKolor != "czerwony") && (wyborKolor != "czarny") && (wyborKolor != "zielony"));

        system("cls");
        if (wyborKolor == "czerwony")
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Kolor textu Zielony
            cout << "Wybrales kolor: czerwony" << endl << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);// Kolor textu Bia�y
        }
        else if (wyborKolor == "czarny")
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Kolor textu Zielony
            cout << "Wybrales kolor: czarny" << endl << endl;
        }
        else if (wyborKolor == "zielony")
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Kolor textu Zielony
            cout << "Wybrales kolor: zielony" << endl << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);// Kolor textu Bia�y
        }



        if (wyborKolor == KolorPol[wylosowanyNumer])
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);// Kolor textu Czerwony
            cout << "Wylosowany kolor to: " << wyborKolor << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Brawo! Twoj kolor wygral :)" << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu Bia�y
            cout << "Twoja nagroda to: " << "Obstawiona ilosc rzetonow * 1,5" << endl;
            GraczWin = true;
        }

        else
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY); // Kolor textu Czerwony
            cout << "Przegrales :(";
            cout << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Kolor wylosowanego numeru to: ";
            cout << KolorPol[wylosowanyNumer] << endl;
            GraczWin = false;
        }
    }
    else if (wybor == 2)
    {
        wylosowanyNumer = losowanieNumeru();
        do {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//Inicjalizacja hOut;

            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << endl << "Podaj numer ktory chcesz obstawic: ";
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu zielony


            cin >> wybranyNumer;
        } while ((wybranyNumer < 0) || (wybranyNumer > 36));

        system("cls");
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
        cout << "Wybrales numer: " << wybranyNumer << endl;
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu zielony

        Sleep(500);

        if (wybranyNumer == wylosowanyNumer)
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Wylosowany numer to: " << wylosowanyNumer << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu zielony
            cout << "Brawo! Twoj numer wygral." << endl;
            cout << "Twoja nagroda to: " << "Obstawiona ilosc rzetonow * 5" << endl;
            GraczWin = true;
        }
        else
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Przegrales :(";
            cout << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Wylosowany numer to : " << wylosowanyNumer << endl;
            GraczWin = false;
        }
    }
    else if (wybor == 3)
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//Inicjalizacja hOut;

        liczbaProcent = losowanieProcentowe();
        do {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Wybierz:";
            cout << endl;

            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie cyjanowego koloru napisu
            cout << " 1 by obstawic liczby 1 - 3\n 2 by obstawic liczby 4 - 6\n 3 by obstawic liczby 7 - 9\n 4 by obstawic liczby 10 - 12\n 5 by obstawic liczby 13 - 15\n 6 by obstawic liczby 16 - 18\n 7 by obstawic liczby 19 - 21\n 8 by obstawic liczby 22 - 24\n 9 by obstawic liczby 25 - 27\n 10 by obstawic liczby 28 - 30\n 11 by obstawic liczby 31 - 33\n 12 by obstawic liczby 34 - 36" << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

            cin >> wybranaTrojka;
        } while ((wybranaTrojka < 1) || (wybranaTrojka > 12));

        system("cls");
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
        cout << "Wybrana trojka to: " << wybranaTrojka << endl;
        wylosowanyNumer = losowanieTrojki(liczbaProcent);

        Sleep(500);

        if (wybranaTrojka == wylosowanyNumer)
        {
            wylosowanyNumer -= 1;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Wylosowana trojka to: " << tablicaTrojek[wylosowanyNumer] << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu zielony
            cout << "Brawo! Twoja trojka wygrala." << endl;
            cout << "Twoja nagroda to: " << "Obstawiona ilosc rzetonow * 5" << endl;
            GraczWin = true;
        }
        else
        {
            wylosowanyNumer -= 1;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Przegrales :(";
            cout << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Wylosowana trojka to: " << tablicaTrojek[wylosowanyNumer] << endl;
            GraczWin = false;
        }

    }
    else if (wybor == 4)
    {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//Inicjalizacja hOut;

        liczbaProcent = losowanieProcentowe();
        do {
            cout << "Wybierz";
            cout << endl;
            cout << "1 by obstawic liczby 1 - 12\n2 by obstawic liczby 13 - 24\n3 by obstawic liczby 25 - 36" << endl;
            cin >> wybranaDwunastka;
        } while ((wybranaDwunastka < 1) || (wybranaDwunastka > 3));

        system("cls");
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
        cout << "Wybrana dwunastka to: " << wybranaDwunastka << endl;
        wylosowanyNumer = losowanieDwunastki(liczbaProcent);

        Sleep(500);

        if (wybranaDwunastka == wylosowanyNumer)
        {
            wylosowanyNumer -= 1;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Wylosowana dwunastka to: " << tablicaDwunastek[wylosowanyNumer] << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Brawo! Twoja dwunastka wygrala." << endl;
            GraczWin = true;
        }
        else
        {
            wylosowanyNumer -= 1;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Przegrales :(";
            cout << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Wylosowana dwunastka to : " << tablicaDwunastek[wylosowanyNumer] << endl;
            GraczWin = false;
        }

    }
    system("pause");

    return GraczWin;
}
