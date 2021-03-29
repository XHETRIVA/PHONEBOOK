#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
void correction(string filename);
int checkunino(string num,string &pname,string filename);
void checkno(string num,int &flag);
void showdata(string filename);
int strtoint(string a);
void addcontacts();
void calc();
void sort();
string stoupper(string s);
int noline=0,nodata=0,alphaN=0;
const int size=nodata;
struct contacts
{
    string name,number,email,ad,dob,doa,notes,rel,label,qa;
};
string path1="C:/PHONEBOOK/phonebook.csv",path2="C:/PHONEBOOK/junk.csv",path3="C:/PHONEBOOK/searchresults.csv",path4="C:/PHONEBOOK/selection.csv",path5="C:/PHONEBOOK/copied.csv";
int main()
{
    addcontacts();
}
void addcontacts()
{
    correction(path2);
    correction(path1);
    calc();
    ofstream file(path2.c_str(),ios::app);
    string name,no,email="",ad="",dob="",doa="",notes="",rel="",label="",qa="0";
    if(noline>0&&alphaN==0)
    file<<"PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
    reno:
    int l=1,flag=0;
    cout<<"Enter the phone number: ";
    getline(cin,no);
    checkno(no,flag);
    if(flag==1)
    {
        cout<<"ERROR:: Wrong format for phone number!\n";
        goto reno;
    }
    int c=checkunino(no,name,path2);
    if(c==0)
    {
        cout<<"ERROR:Two person cannot have same phone number.\nThe phone number "<<no<<" already belongs to "<<name<<"\nPRESS:\n1:To re-enter phone number\n2:To skip adding(default)\n\nYOUR CHOICE: ";
        cin>>l;
        cin.ignore(1,'\n');
        if(l==1)
        goto reno;
    }
    if(l==1)
    {
        cout<<"Do you want to enter the name?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        string a;
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the name: ";
            getline(cin,name);
        }
        else
        {
            name=no;
        }
        cout<<"\nDo you want to enter the e-mail?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the e-mail: ";
            getline(cin,email);
        }
        cout<<"\nDo you want to enter the address?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the address: ";
            getline(cin,ad);
        }
        cout<<"\nDo you want to enter the date of birth?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the date of birth: ";
            getline(cin,dob);
        }
        cout<<"\nDo you want to enter the date of anniversary?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the date of anniversary: ";
            getline(cin,doa);
        }
        cout<<"\nDo you want to enter any notes?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the notes: ";
            getline(cin,notes);
        }
        cout<<"\nDo you want to enter the relation?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the relation: ";
            getline(cin,rel);
        }
        cout<<"\nDo you want to enter any label?\n\nPRESS\n1-YES\n2-NO\nYOUR CHOICE: ";
        cin>>a;
        cin.ignore(1,'\n');
        if(a=="1")
        {
            cout<<"\nEnter the label: ";
            getline(cin,label);
        }
        file<<'\n'<<no<<","<<name<<","<<email<<","<<ad<<","<<dob<<","<<doa<<','<<notes<<","<<rel<<","<<label<<","<<qa;
    }
    file.close();
    correction(path2);
    calc();
    sort();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11 | FOREGROUND_INTENSITY);
    showdata(path1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
string stoupper(string s)
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            s[i]-=32;
        }
        i++;
    }
    return s;
}
void showdata(string filename)
{
    ifstream csvi(filename.c_str());
    string junk;
    getline(csvi,junk,'\n');
    while(!csvi.eof())
    {
        string name, number, email, address, dob, doa, notes, relation,label,qa;
        getline(csvi,number,',');
        getline(csvi,name,',');
        getline(csvi,email,',');
        getline(csvi,address,',');
        getline(csvi,dob,',');
        getline(csvi,doa,',');
        getline(csvi,notes,',');
        getline(csvi,relation,',');
        getline(csvi,label,',');
        getline(csvi,qa,'\n');
        cout<<"\n\nNAME: "<<left<<name<<"\nPHONE NUMBER: "<<number<<"\nDATE OF BIRTH: ";
        if(dob=="")
        cout<<" - ";
        cout<<dob<<"\nDATE OF ANNIVERSARY: ";
        if(doa=="")
        cout<<" - ";
        cout<<doa<<"\nRELATION: ";
        if(relation=="")
        cout<<" - ";
        cout<<relation<<"\nLABEL: ";
        if(label=="")
        cout<<" - ";
        cout<<label<<"\nNOTES: ";
        if(notes=="")
        cout<<" - ";
        cout<<notes<<"\nEMAIL: ";
        if(email=="")
        cout<<" - ";
        cout<<email<<"\nADDRESS: ";
        if(address=="")
        cout<<" - ";
        cout<<address<<"\n";
    }
    csvi.close();
}
int checkunino(string num,string &pname,string filename)
{
    int flag=1;
    ifstream check;
    check.open(filename.c_str());
    while(!check.eof())
    {
        string number,name,junk;
        getline(check,number,',');
        getline(check,name,',');
        getline(check,junk,'\n');
        if(number==num)
        {
            flag=0;
            pname=name;
            break;
        }
        else
        {
            flag=1;
            pname="";
        }
    }
    check.close();
    return flag;
}
void correction(string filename)
{
    ofstream checked0(filename,ios::app);
    checked0.close();
    ifstream correct0;
    correct0.open(filename.c_str());
    string corrected0="",junk0="";
    getline(correct0,junk0,'\n');
    corrected0=corrected0+junk0;
    while(!correct0.eof())
    {
        string junk1;
        getline(correct0,junk1,'\n');
        if(junk1!="")
        corrected0=corrected0+'\n'+junk1;
    }
    correct0.close();
    ofstream crcting0;
    crcting0.open(filename.c_str());
    crcting0<<corrected0;
    crcting0.close();
    /*****/
    ofstream checked(filename,ios::app);
    checked.close();
    ifstream correct;
    correct.open(filename.c_str());
    string corrected="",junk="";
    getline(correct,junk,'\n');
    corrected=corrected+junk;
    while(!correct.eof())
    {
        string name, number, email, address, dob, doa, notes, relation,label,qa;
        getline(correct,number,',');
        getline(correct,name,',');
        getline(correct,email,',');
        getline(correct,address,',');
        getline(correct,dob,',');
        getline(correct,doa,',');
        getline(correct,notes,',');
        getline(correct,relation,',');
        getline(correct,label,',');
        getline(correct,qa,'\n');
        if(name=="")
        name=number;
        if(qa=="")
        qa="0";
        if(number!="")
        corrected=corrected+'\n'+number+','+name+','+email+','+address+','+dob+','+doa+','+notes+','+relation+','+label+','+qa;
    }
    correct.close();
    ofstream crcting;
    crcting.open(filename.c_str());
    crcting<<corrected;
    crcting.close();
}
void checkno(string num,int &flag)
{
    char x;
    for(int i=0;num[i]!='\0';i++)
    {
        x=num[0];
        if(x=='+'||isdigit(num[i]));
        else
        {
            flag=1;
            break;
        }
    }
}
int strtoint(string a)
{
    int x=0;
    stringstream as(a);
    as>>x;
    return x;
}
void sort()
{
    contacts obj[1000];
    int i=0,j;
    ifstream please(path2);
    string junk,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10;
    getline(please,junk,'\n');
    while(!please.eof())
    {
        getline(please,obj[i].number,',');
        getline(please,obj[i].name,',');
        getline(please,obj[i].email,',');
        getline(please,obj[i].ad,',');
        getline(please,obj[i].dob,',');
        getline(please,obj[i].doa,',');
        getline(please,obj[i].notes,',');
        getline(please,obj[i].rel,',');
        getline(please,obj[i].label,',');
        getline(please,obj[i].qa,'\n');
        i++;
    }
    for(i=0;i<nodata-1;i++)
    {
        for(j=0;j<nodata-i-1;j++)
        if(stoupper(obj[j].name)>stoupper(obj[j+1].name))
        {
            temp1=obj[j].number;
            temp2=obj[j].name;
            temp3=obj[j].email;
            temp4=obj[j].ad;
            temp5=obj[j].dob;
            temp6=obj[j].doa;
            temp7=obj[j].notes;
            temp8=obj[j].rel;
            temp9=obj[j].label;
            temp10=obj[j].qa;
            obj[j].number=obj[j+1].number;
            obj[j].name=obj[j+1].name;
            obj[j].email=obj[j+1].email;
            obj[j].ad=obj[j+1].ad;
            obj[j].dob=obj[j+1].dob;
            obj[j].doa=obj[j+1].doa;
            obj[j].notes=obj[j+1].notes;
            obj[j].rel=obj[j+1].rel;
            obj[j].label=obj[j+1].label;
            obj[j].qa=obj[j+1].qa;
            obj[j+1].number=temp1;
            obj[j+1].name=temp2;
            obj[j+1].email=temp3;
            obj[j+1].ad=temp4;
            obj[j+1].dob=temp5;
            obj[j+1].doa=temp6;
            obj[j+1].notes=temp7;
            obj[j+1].rel=temp8;
            obj[j+1].label=temp9;
            obj[j+1].qa=temp10;
        }
    }
    please.close();
    ofstream fil(path1);
    fil<<junk;
    for(i=0;i<nodata;i++)
    {
        fil<<'\n'<<obj[i].number<<','<<obj[i].name<<','<<obj[i].email<<','<<obj[i].ad<<','<<obj[i].dob<<','<<obj[i].doa<<','<<obj[i].notes<<','<<obj[i].rel<<','<<obj[i].label<<','<<obj[i].qa;
    }
    fil.close();
}
void calc()
{
    alphaN=0;
    noline=0;
    nodata=0;
    string cd,junk;
    ifstream csvr(path2.c_str());
    while(!csvr.eof())
    {
        getline(csvr,cd,',');
        getline(csvr,junk,'\n');
        if(isdigit(cd[0])||cd[0]=='+')
        nodata++;
        if(cd[0]=='P')
        alphaN=1;
        noline++;
    }
    csvr.close();
}