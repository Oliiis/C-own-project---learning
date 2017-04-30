#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

    //global variables

void world_to_nether(long long a,long long b,long long c)
{
    long long a_after,b_after,c_after;

    a_after=a/8;
    b_after=b;
    c_after=c/8;
    system("cls");
    cout<<"----------------------------------------------"<<endl;
    cout<<"   # WYNIK"<<endl;
    cout<<"      * Normalny —wiat"<<endl;
    cout <<"        X: "<<a<<" / Y: "<<b<<" / Z: "<<c<<endl;
    cout<<"      * Nether"<<endl;
    cout <<"        X: "<<a_after<<" / Y: "<<b_after<<" / Z: "<<c_after<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"* Nacisnij dowolny klawisz aby przejsc dalej... ";
    getch();
}

void nether_to_world(long double a,long double b,long double c)
{
    long long a_after,b_after,c_after;

    a_after=a*8;
    b_after=b;
    c_after=c*8;
    system("cls");
    cout<<"----------------------------------------------"<<endl;
    cout<<"   # WYNIK"<<endl;
    cout<<"      * Nether"<<endl;
    cout <<"        X: "<<a<<" / Y: "<<b<<" / Z: "<<c<<endl;
    cout<<"      * Normalny —wiat"<<endl;
    cout <<"        X: "<<a_after<<" / Y: "<<b_after<<" / Z: "<<c_after<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"* Nacisnij dowolny klawisz aby przejsc dalej... ";
    getch();
}

void convertion_error()
{
    cout<<"(!!!) Podano bˆ©dne dane - liter©, znak specjalny lub zbyt du¾¥ liczbe."<<endl;
    cout<<"(!!!) Program zostanie WY¤CZONY. Mo¾esz uruchomi† go po tym ponownie."<<endl;
    cout<<"(!!!) Nacisnij dowolny klawisz aby przej˜† dalej... ";
    getch();
    exit(0);
}

void switch_default_information()
{
    cout<<"(!!!) Nie ma opcji o takim numerze!"<<endl;
    cout<<"(!!!) Nacisnij dowolny klawisz aby przej˜† dalej... ";
    getch();
}

void y_less_zero_information()
{
    cerr<<"(!!!) Koordynat Y: nie mo¾e by† mniejszy od zera. U¾yj poprawnych danych!"<<endl;
    cerr<<"(!!!) Nacisnij dowolny klawisz aby przejsc dalej... ";
    getch();
}

void menu_display()
{
    cout<<endl;
    cout << "~~ World/Nether Coordinates Converter *"<<endl;
    cout << "~~ by Oliiis"<<endl<<endl;
    cout << "# WYBIERZ OPCJE"<<endl;
    cout << "  1. Konwersja koordynat¢w."<<endl;
    cout << "  2. Wyj˜cie."<<endl;
}

int main()
{
    //Variables
    char choose,choose_calculate;
    long long x,y,z;


    //Main - infinity
    for(;;)
    {
        system("cls");

        menu_display();
        choose=getch();
        //Basic menu
        switch(choose)
        {
        case '1':
            {
            //Convertion menu
                cout << "# WYBRANO: 1. Konwersja koordynat¢w."<<endl;

                cout << "* Podaj prosz© koordynaty."<<endl;
                cout << "  X:";
                //Var x in
                    if (!(cin >> x))
                    {
                        convertion_error();
                    }
                cout << "  Y:";
                //Var y in
                    if (!(cin >> y))
                    {
                        convertion_error();
                    }
                if (y<0)
                {
                    y_less_zero_information();
                }
                else
                {
                    cout << "  Z:";
                    //Var z in
                    if (!(cin >> z))
                    {
                        convertion_error();
                    }

                    cout << "* Podane przez Ciebie koordynaty: "<<endl;
                    cout <<"   X: "<<x<<" / Y: "<<y<<" / Z: "<<z<<endl;

                    cout << "* Wybierz rodzaj konwersji (1 lub 2):"<<endl;
                    cout << "   1. Normalny —wiat --> Nether"<<endl;
                    cout << "   2. Nether         --> Normalny —wiat."<<endl;

                    choose_calculate=getch();

                    switch(choose_calculate)
                    {
                    case '1':
                        {
                        world_to_nether(x,y,z);
                        }
                        break;
                    case '2':
                        {
                            nether_to_world(x,y,z);
                        }
                        break;
                    default:
                        {
                            switch_default_information();
                        }
                    }
                }
            }
            break;
        case '2':
            {
                exit(0);
            }
            break;
        default:
                {
                    switch_default_information();
                }
        }
    }

    return 0;
}
