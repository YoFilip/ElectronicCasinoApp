#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

bool czyJuzWygral = false;

int dobierzKarte()
{
    int x;
    x = rand() % 13;

    return x;
}

bool Lose(int pktGracza, int pktPC)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//Inicjalizacja hOut;


    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);//Ustawienie czerwonego koloru napisu
    cout << endl << "   Przegrales :(";
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu
    cout << endl;

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);//Ustawienie zielonego koloru napisu
    cout << "Suma punktow gracza :" << pktGracza << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie niebieskiego koloru napisu
    cout << "Suma punktow komputera : " << pktPC << endl; \
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

    czyJuzWygral = true;
    bool GraczWin = false;
    return GraczWin;
}

bool Win(int pktGracza, int pktPC)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//Inicjalizacja hOut;

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);//Ustawienie zielonego koloru napisu
    cout << endl << "   Wygrales rozdanie";
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

    cout << endl;

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);//Ustawienie zielonego koloru napisu
    cout << "Suma punktow gracza : " << pktGracza << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie niebieskiego koloru napisu
    cout << "Suma punktow komputera : " << pktPC << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu



    czyJuzWygral = true;
    bool GraczWin = true;
    return GraczWin;
}

bool WinOrLose(int pktGracza, int pktPC)
{
    bool GraczWin = false;
    if (((pktPC >= pktGracza) && (pktPC <= 21)) || (pktGracza > 21))
    {
        GraczWin = Lose(pktGracza, pktPC);
    }
    else if (((pktGracza > pktPC) && (pktGracza <= 21)) || (pktPC > 21))
    {
        GraczWin = Win(pktGracza, pktPC);
    }
    return GraczWin;
}

bool Gramy_w_Oczko()
{
    srand(time(NULL));
    int WartosciKart[13] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 2, 3, 4 }, a = 2, IdDobranejKarty, sumaKartGracza = 0, sumaKartPC = 0, i = 0;
    string znakKarty[13] = { " 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 "," 10"," AS"," J "," Q "," K " }, decyzja;
    bool GraczWin = false; {}


    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//Inicjalizacja hOut;

    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
    cout << "Wartosci kart" << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu


    for (int j = 0; j < 13; j++, a++)
    {
        if (a == 12)
        {
            a = 2;
        }
        WartosciKart[j] = a;
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie cyjanowego koloru napisu
        cout << znakKarty[j] << " = " << WartosciKart[j] << endl;
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu
    }
    cout << endl << endl;

    // DOBRANIE DWOCH STARTOWYCH KART

    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);// Kolor textu niebieski
    cout << endl << "Karta komputera" << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

    IdDobranejKarty = dobierzKarte();
    Sleep(1500);
    cout << "+--------+\n|" << znakKarty[IdDobranejKarty] << "     |\n|        |\n|        |\n|        |\n|     " << znakKarty[IdDobranejKarty] << "|\n+--------+" << endl;
    sumaKartPC += WartosciKart[IdDobranejKarty];
    Sleep(1500);

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu zielony
    cout << endl << "Karty gracza" << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

    IdDobranejKarty = dobierzKarte();
    Sleep(1500);
    cout << "+--------+\n|" << znakKarty[IdDobranejKarty] << "     |\n|        |\n|        |\n|        |\n|     " << znakKarty[IdDobranejKarty] << "|\n+--------+" << endl;
    sumaKartGracza += WartosciKart[IdDobranejKarty];
    Sleep(500);

    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);// Kolor textu czerwony
    cout << "Suma: " << sumaKartGracza << endl << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

    IdDobranejKarty = dobierzKarte();
    Sleep(500);
    cout << "+--------+\n|" << znakKarty[IdDobranejKarty] << "     |\n|        |\n|        |\n|        |\n|     " << znakKarty[IdDobranejKarty] << "|\n+--------+" << endl;
    sumaKartGracza += WartosciKart[IdDobranejKarty];
    Sleep(500);

    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);// Kolor textu czerwony
    cout << "Suma: " << sumaKartGracza << endl << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

    // KARTY GRACZA
    do {
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu ��ty
        cout << "Wpisz Tak, aby dobrac karte\nWpisz Nie by spasowac" << endl;
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu
        cin >> decyzja;


        if ((decyzja == ("Tak")) || (decyzja == ("tak")))
        {
            Sleep(1500);
            IdDobranejKarty = dobierzKarte();
            cout << "+--------+\n|" << znakKarty[IdDobranejKarty] << "     |\n|        |\n|        |\n|        |\n|     " << znakKarty[IdDobranejKarty] << "|\n+--------+" << endl;
            sumaKartGracza += WartosciKart[IdDobranejKarty];

            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Suma: " << sumaKartGracza << endl << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

            Sleep(1500);
        }

        else if ((decyzja == ("Nie")) || (decyzja == ("nie")))
        {

            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);// Kolor textu ��ty
            cout << "Suma twoich punktow: " << sumaKartGracza;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);// Kolor textu niebieski
            cout << endl << "Teraz kolej komputera" << endl << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

            IdDobranejKarty = dobierzKarte();
            cout << "+--------+\n|" << znakKarty[IdDobranejKarty] << "     |\n|        |\n|        |\n|        |\n|     " << znakKarty[IdDobranejKarty] << "|\n+--------+" << endl;
            sumaKartPC += WartosciKart[IdDobranejKarty];
            Sleep(1500);

            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);//Ustawienie koloru czerwonego
            cout << "Suma: " << sumaKartPC << endl << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

            if (sumaKartPC == 22)
            {
                Lose(sumaKartGracza, sumaKartPC);
            }
            else if ((sumaKartGracza == 22) && (i == 0))
            {
                cout << "Perskie oczko!" << endl;
                Win(sumaKartGracza, sumaKartPC);
                break;

            }
            else
            {
                while (sumaKartPC < sumaKartGracza)
                {
                    IdDobranejKarty = dobierzKarte();
                    cout << "+--------+\n|" << znakKarty[IdDobranejKarty] << "     |\n|        |\n|        |\n|        |\n|     " << znakKarty[IdDobranejKarty] << "|\n+--------+" << endl;
                    sumaKartPC += WartosciKart[IdDobranejKarty];

                    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu
                    cout << "Suma: " << sumaKartPC << endl << endl;
                    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu

                    Sleep(3000);

                }
            }

            break;
        }

        else
        {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//Ustawienie majenta jebana kurwa pierdolona
            cout << "Przestan! To powazna gra >:(" << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie bia�ego koloru napisu
        }
        i++;
    } while (sumaKartGracza <= 21);

    if (czyJuzWygral == false)
    {
        GraczWin = WinOrLose(sumaKartGracza, sumaKartPC);
    }

    return GraczWin;
}
