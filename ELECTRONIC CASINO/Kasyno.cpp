#include <iostream>
#include <windows.h>
#include "Oczko.cpp"
#include "Ruletka.cpp"

using namespace std;

int main()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    system("COLOR 0F");
    string czyChceDodacZetony, koniecGry = "nie";
    int ilZetonowDodac;
    bool GraczWin = false;
    int ilZetonow = 2147483646;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "!!Witaj w Electronic Casino!!" << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "||Twoje zetony : 2147483646$|| " << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "Podaj ilosc zetonow ktorych chcesz uzyc w grze: ";
    cin >> ilZetonow;

    int IdGry;


    cout << endl;
    do
    {


        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu żółty
        cout << endl << "Wpisz 1 by zagrac w oczko\nWpisz 2 by zagrac w ruletke"/*\nWpisz 3 by zagrac na automacie"*/ << endl;
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie białego koloru napisu

        cin >> IdGry;
        cout << endl << endl;

        if (IdGry == 1)
        {
            ilZetonow -= 20;
            GraczWin = Gramy_w_Oczko();
            if (GraczWin == true)
            {
                cout << "Twoja wygrana: " << 30 << " zetonow" << endl;
            }
            else if (GraczWin == false) {
                SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);// Kolor textu żółty
                cout << "Przegrales 20 zetonow \nSprobuj ponownie" << endl;
                SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie białego koloru napisu
            }
            Sleep(5000);
        }
        else if (IdGry == 2)
        {
            ilZetonow -= 30;
            Gramy_w_ruletke();

        }
        else if (IdGry == 3)
        {
            ilZetonow -= 10;
            //      Gramy_na_Automacie();
        }
        else
        {
            cout << "Nie masz wystarzajacej ilosci zetonow" << endl;
        }
        system("cls");
        system("COLOR 0F");

        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY); //Czerwony Napis
        cout << "Czy chcesz skonczyc grac(Tak/tak/Nie/nie)?" << endl;
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //Powrót do białego napisu
        cin >> koniecGry;
    } while ((koniecGry == "Nie") || (koniecGry == "nie"));

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);//Ustawienie zielonego  koloru napisu
    cout << "Dziekujemy za gre w naszym kasynie i zapraszamy ponownie" << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Ustawienie białego koloru napisu

    return 0;
}
