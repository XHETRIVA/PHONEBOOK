#include<iostream>
#include<fstream>
using namespace std;
string loginid="RudrashisKumarDutta333321Ratul";
string basepath="C:/PHONEBOOK/",path1="",path2="",path3="C:/PHONEBOOK/searchresults.csv",path4="C:/PHONEBOOK/selection.csv",path5="C:/PHONEBOOK/copied.csv",path6="C:/PHONEBOOK/accounts.txt";
void openpathfile(string file) //opens a file in ofstream append mode
{
    ofstream open(file.c_str(),ios::app);
    open.close();
}
void makeorremovefilename(int q)
{
    if(q==0)
    {
        int i=0,j=48;
        char k;
        path1=basepath;
        path2=basepath;
        while(loginid[i]!='\0')
        {
            k=j;
            path1=path1+loginid[i]+k+'-';
            if(j==57)
            j=65;
            else if(j==90)
            j=97;
            else if(j==122)
            j=48;
            else
            j++;
            k=j;
            path1=path1+k+'-';
            if(j==57)
            j=65;
            else if(j==90)
            j=97;
            else if(j==122)
            j=48;
            else
            j++;
            if((i+1)%2==0)
            path1=path1+'B'+'$';
            if((i+1)%2!=0)
            path1=path1+'i'+'!';
            if((i+1)%3==0)
            path1=path1+'n'+'#';
            i++;
        }
        i=0;
        j=100;
        while(loginid[i]!='\0')
        {
            k=j;
            path2=path2+loginid[i]+k+'-';
            if(j==57)
            j=65;
            else if(j==90)
            j=97;
            else if(j==122)
            j=48;
            else
            j++;
            k=j;
            path2=path2+k+'-';
            if(j==57)
            j=65;
            else if(j==90)
            j=97;
            else if(j==122)
            j=48;
            else
            j++;
            if((i+1)%2==0)
            path2=path2+'N'+'$';
            if((i+1)%2!=0)
            path2=path2+'U'+'#';
            if((i+1)%3==0)
            path2=path2+'L'+'!';
            if((i+1)%5==0)
            path2=path2+'L'+'_';
            i++;
        }
        path1=path1+".csv";
        path2=path2+".csv";
        openpathfile(path1);
        openpathfile(path2);
        openpathfile(path3);
        openpathfile(path4);
        openpathfile(path5);
    }
    if(q==1)
    {
        path1="";
        path2="";
        int b1=remove(path3.c_str());
        int b2=remove(path4.c_str());
        int b3=remove(path5.c_str());
    }
}
int main()
{
    int x;string y;
    makeorremovefilename(0);
    cout<<path1<<'\n'<<path2;
}