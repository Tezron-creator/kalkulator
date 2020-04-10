#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <locale.h>
#include <tchar.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

const WCHAR PIERWIASTEK=8730;

void writeUnicode(PCWSTR sText)
{
    int bufferSize=WideCharToMultiByte(CP_UTF8, 0, sText, - 1, NULL, 0, NULL, NULL);
    char * m=new char[bufferSize];
    WideCharToMultiByte(CP_UTF8, 0, sText, - 1, m, bufferSize, NULL, NULL);
    wprintf(L"%S", m);
    delete[] m;
}

void writeUnicode(WCHAR cChar)
{
    WCHAR sText[2] = {cChar};
    writeUnicode(sText);
}

using namespace std;

int main()
{
    fstream plik;

    string historia[10000][5];
    string wybor;

    int64_t dl=0;
    int64_t i=0;

    char cos;

    long double x=0;
    long double y=0;
    long double suma=0;
    long double roznica=0;
    long double iloczyn=0;
    long double iloraz=0;
    long double potega_elementu=0;
    long double pierwiastek=0;


    HANDLE kolor;
    kolor=GetStdHandle(STD_OUTPUT_HANDLE);


    poczatek:;


    SetConsoleTextAttribute(kolor, 15);
    cout<<"=================================================="<<endl;
    SetConsoleTextAttribute(kolor, 4);
    cout<<"                    KALKULATOR                    "<<endl;
    SetConsoleTextAttribute(kolor, 15);
    cout<<"=================================================="<<endl;

    SetConsoleTextAttribute(kolor, 6);
    cout<<"0 - ";
    SetConsoleTextAttribute(kolor, 5);
    cout<<"Wy\210\245cz program"<<endl;

    SetConsoleTextAttribute(kolor, 6);
    cout<<"1 - ";
    SetConsoleTextAttribute(kolor, 5);
    cout<<"Dodawanie"<<endl;

    SetConsoleTextAttribute(kolor, 6);
    cout<<"2 - ";
    SetConsoleTextAttribute(kolor, 5);
    cout<<"Odejmowanie"<<endl;

    SetConsoleTextAttribute(kolor, 6);
    cout<<"3 - ";
    SetConsoleTextAttribute(kolor, 5);
    cout<<"Mno\276enie"<<endl;

    SetConsoleTextAttribute(kolor, 6);
    cout<<"4 - ";
    SetConsoleTextAttribute(kolor, 5);
    cout<<"Dzielenie"<<endl;

    SetConsoleTextAttribute(kolor, 6);
    cout<<"5 - ";
    SetConsoleTextAttribute(kolor, 5);
    cout<<"Pot\251gowanie"<<endl;

    SetConsoleTextAttribute(kolor, 6);
    cout<<"6 - ";
    SetConsoleTextAttribute(kolor, 5);
    cout<<"Pierwiastkowanie"<<endl;

    SetConsoleTextAttribute(kolor, 6);
    cout<<"7 - ";
    SetConsoleTextAttribute(kolor, 5);
    cout<<"Historia"<<endl;

    SetConsoleTextAttribute(kolor, 6);
    cout<<endl;
    SetConsoleTextAttribute(kolor, 11);
    cout<<"Wybierz opcj\251: ";
    SetConsoleTextAttribute(kolor, 6);
    cin>>wybor;
    SetConsoleTextAttribute(kolor, 15);
    cout<<"=================================================="<<endl;

    dl=wybor.size();

    if(dl>1)
    {
        SetConsoleTextAttribute(kolor, 4);
        cout<<"Nie ma takiej opcji"<<endl;
        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;
        Sleep(2000);
        system("cls");
        goto poczatek;
    }


    if(wybor[0]==48)
    {
        exit(0);
    }
    else if(wybor[0]==49)
    {
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj 1 liczb\251: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>x;
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj 2 liczb\251: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>y;
        suma=x+y;
        cout<<x;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" + ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<y;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" = ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<suma<<endl;
        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;

        plik.open("historia.txt",ios::out | ios::app);
        plik<<x<<" + "<<y<<" = "<<suma<<endl;
        plik.close();

        Sleep(5000);
        system("cls");
        goto poczatek;

    }
    else if(wybor[0]==50)
    {
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj 1 liczb\251: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>x;
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj 2 liczb\251: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>y;
        roznica=x-y;
        cout<<x;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" - ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<y;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" = ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<roznica<<endl;
        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;

        plik.open("historia.txt",ios::out | ios::app);
        plik<<x<<" - "<<y<<" = "<<roznica<<endl;
        plik.close();

        Sleep(5000);
        system("cls");
        goto poczatek;
    }
    else if(wybor[0]==51)
    {
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj 1 liczb\251: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>x;
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj 2 liczb\251: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>y;
        iloczyn=x*y;
        cout<<x;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" * ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<y;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" = ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<iloczyn<<endl;
        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;

        plik.open("historia.txt",ios::out | ios::app);
        plik<<x<<" * "<<y<<" = "<<iloczyn<<endl;
        plik.close();

        Sleep(5000);
        system("cls");
        goto poczatek;
    }
    else if(wybor[0]==52)
    {
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj 1 liczb\251: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>x;
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj 2 liczb\251: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>y;
        iloraz=x/y;
        cout<<x;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" / ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<y;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" = ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<iloraz<<endl;
        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;

        plik.open("historia.txt",ios::out | ios::app);
        plik<<x<<" / "<<y<<" = "<<iloraz<<endl;
        plik.close();

        Sleep(5000);
        system("cls");
        goto poczatek;
    }
    else if(wybor[0]==53)
    {
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj podstaw\251: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>x;
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj wyk\210adnik: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>y;
        potega_elementu=pow(x,y);
        cout<<x;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" ^ ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<y;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" = ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<potega_elementu<<endl;
        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;

        plik.open("historia.txt",ios::out | ios::app);
        plik<<x<<" ^ "<<y<<" = "<<potega_elementu<<endl;
        plik.close();

        Sleep(5000);
        system("cls");
        goto poczatek;
    }
    else if(wybor[0]==54)
    {
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj liczb\251 z kt\242rej chcesz wyznaczy\206 pierwiastek: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>x;
        SetConsoleTextAttribute(kolor, 5);
        cout<<"Podaj stopie\344 pierwiastka: ";
        SetConsoleTextAttribute(kolor, 10);
        cin>>y;
        pierwiastek=pow(x,1/y);
        cout<<y;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" ";
        UINT oldcp =::GetConsoleOutputCP();
        ::SetConsoleOutputCP( CP_UTF8 );
        writeUnicode(PIERWIASTEK);
        ::SetConsoleOutputCP( oldcp );
        cout<<" ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<x;
        SetConsoleTextAttribute(kolor, 4);
        cout<<" = ";
        SetConsoleTextAttribute(kolor, 10);
        cout<<pierwiastek<<endl;
        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;

        plik.open("historia.txt",ios::out | ios::app);
        plik<<y<<" √ "<<x<<" = "<<pierwiastek<<endl;
        plik.close();

        Sleep(5000);
        system("cls");
        goto poczatek;
    }
    else if(wybor[0]==55)
    {
        system("cls");
        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;
        SetConsoleTextAttribute(kolor, 4);
        cout<<"               HISTORIA KALKULATORA               "<<endl;
        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;
        plik.open("historia.txt");
        UINT oldcp =::GetConsoleOutputCP();
        ::SetConsoleOutputCP( CP_UTF8 );
        for(;;)
        {
            i++;
            plik>>historia[i][0];
            SetConsoleTextAttribute(kolor, 10);
            cout<<historia[i][0]<<" ";
            plik>>historia[i][1];
            SetConsoleTextAttribute(kolor, 4);
            cout<<historia[i][1]<<" ";
            plik>>historia[i][2];
            SetConsoleTextAttribute(kolor, 10);
            cout<<historia[i][2]<<" ";
            plik>>historia[i][3];
            SetConsoleTextAttribute(kolor, 4);
            cout<<historia[i][3]<<" ";
            plik>>historia[i][4];
            SetConsoleTextAttribute(kolor, 10);
            cout<<historia[i][4]<<" ";
            SetConsoleTextAttribute(kolor, 15);

            cos=historia[i][0][0];

            if(int(cos)==0)
            {
                cout<<endl;
                goto koniechistorii;
            }
            cout<<endl;
        }
        koniechistorii:;
        ::SetConsoleOutputCP( oldcp );
        plik.close();
        goto poczatek;
    }
    else
    {
        SetConsoleTextAttribute(kolor, 4);
        cout<<"Nie ma takiej opcji"<<endl;

        SetConsoleTextAttribute(kolor, 15);
        cout<<"=================================================="<<endl;

        Sleep(4000);
        system("cls");
        goto poczatek;
    }





    return 0;
}
