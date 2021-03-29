#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int main()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8 | FOREGROUND_INTENSITY);
    cout<<"                    P P P P P  H       H  O O O O O  N       N  E E E E E  B B B B    O O O O O  O O O O O  K     K\n";
    Sleep(150);
    cout<<"                    P       P  H       H  O       O  N N     N  E          B       B  O       O  O       O  K    K\n";
    Sleep(150);
    cout<<"                    P       P  H       H  O       O  N  N    N  E          B      B   O       O  O       O  K   K\n";
    Sleep(150);
    cout<<"                    P P P P P  H H H H H  O       O  N   N   N  E E E      B B B B    O       O  O       O  K K\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12 | FOREGROUND_INTENSITY);
    Sleep(150);
    cout<<"                    P          H       H  O       O  N    N  N  E          B      B   O       O  O       O  K   K\n";
    Sleep(150);
    cout<<"                    P          H       H  O       O  N     N N  E          B       B  O       O  O       O  K    K\n";
    Sleep(150);
    cout<<"                    P          H       H  O O O O O  N       N  E E E E E  B B B B    O O O O O  O O O O O  K      K\n";
    Sleep(150);
    Sleep(2000);
    cout<<"\a";
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7 );
}