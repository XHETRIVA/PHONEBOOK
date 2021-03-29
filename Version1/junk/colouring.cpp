#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
int main()
{
    for(int i=0;i<256;i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
        cout<<i<<"-TESTING....\n";
    }
}