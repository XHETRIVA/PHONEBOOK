#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<Windows.h>
#include<sstream>
using namespace std;
void correction(string filename);
int checkunino(string num,string &pname,string filename);
void checkno(string num,int &flag);
void showdata(string filename);
string stoupper(string s);
void searchn(int &h,string sname,int q);
void showqa();
int strtoint(string a);
void addcontacts();
void calc();
void sort();
int noline=0,nodata=0,alphaN=0;
const int size=nodata;
struct contacts
{
    string name,number,email,ad,dob,doa,notes,rel,label,qa;
};
string path1="C:/PHONEBOOK/phonebook.csv",path2="C:/PHONEBOOK/junk.csv",path3="C:/PHONEBOOK/searchresults.csv",path4="C:/PHONEBOOK/selection.csv",path5="C:/PHONEBOOK/copied.csv",path6="C:/PHONEBOOK/accounts.txt",path7="C:/PHONEBOOK/accountchecker.txt";
int main()
{
    int flag=0,x=1;
    searchn(x,"NULL",0);
    string adqa,name,number,email,ad,dob,doa,notes,rel,label,qa,junk,qaf="";
    cout<<"Enter the serial no. you want to add to quickaccess or type \"exit\" to exit the fuction.";
    getline(cin,adqa);
    ifstream open(path1.c_str());
    getline(open,junk,'\n');
    qaf+=junk;
    while(!open.eof())
    {
        getline(open,number,',');
        getline(open,name,',');
        getline(open,email,',');
        getline(open,ad,',');
        getline(open,dob,',');
        getline(open,doa,',');
        getline(open,notes,',');
        getline(open,rel,',');
        getline(open,label,',');
        getline(open,qa,'\n');
        if(adqa==number||adqa==name||adqa==email||adqa==ad||adqa==dob||adqa==doa||adqa==rel)
        qaf+='\n'+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+"1";
        else
        {
            qaf+='\n'+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+qa;
        }
        
    }
    open.close();
    ofstream op(path1.c_str());
    op<<qaf;
    op.close();
}
void showqa()
{
    int data=0;
    ifstream yrr(path1.c_str());
    while (!yrr.eof())
    {
        string number,name,email,ad,dob,doa,notes,rel,label,qa;
        getline(yrr,number,',');
        getline(yrr,name,',');
        getline(yrr,email,',');
        getline(yrr,ad,',');
        getline(yrr,dob,',');
        getline(yrr,doa,',');
        getline(yrr,notes,',');
        getline(yrr,rel,',');
        getline(yrr,label,',');
        getline(yrr,qa,'\n');
        if(qa=="1")
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14 | FOREGROUND_INTENSITY);
            cout<<"\n\nNAME: "<<left<<name<<"\nPHONE NUMBER: "<<number<<"\nDATE OF BIRTH: ";
            if(dob=="")
            cout<<" - ";
            cout<<dob<<"\nDATE OF ANNIVERSARY: ";
            if(doa=="")
            cout<<" - ";
            cout<<doa<<"\nRELATION: ";
            if(rel=="")
            cout<<" - ";
            cout<<rel<<"\nLABEL: ";
            if(label=="")
            cout<<" - ";
            cout<<label<<"\nNOTES: ";
            if(notes=="")
            cout<<" - ";
            cout<<notes<<"\nEMAIL: ";
            if(email=="")
            cout<<" - ";
            cout<<email<<"\nADDRESS: ";
            if(ad=="")
            cout<<" - ";
            cout<<ad<<"\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            data++;
        }
    }
    if(data==0)
    cout<<"There is no contacts saved in quickaccess!";
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
            getline(cin,dob);
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
    calc();
    sort();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11 | FOREGROUND_INTENSITY);
    showdata(path1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void showdata(string filename)
{
    ifstream search(filename.c_str());
    string junk;
    getline(search,junk,'\n');
    while(!search.eof())
    {
        string name, number, email, address, dob, doa, notes, relation,label,qa;
        getline(search,number,',');
        getline(search,name,',');
        getline(search,email,',');
        getline(search,address,',');
        getline(search,dob,',');
        getline(search,doa,',');
        getline(search,notes,',');
        getline(search,relation,',');
        getline(search,label,',');
        getline(search,qa,'\n');
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14 | FOREGROUND_INTENSITY);
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    }
    search.close();
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
    ofstream checked(filename,ios::app);
    checked.close();
    ifstream correct;
    correct.open(filename.c_str());
    string corrected="",junk="";
    getline(correct,junk,'\n');
    corrected=corrected+junk;
    while(!correct.eof())
    {
        getline(correct,junk,'\n');
        if(junk!=""||junk!=",,,,,,,,,")
        corrected=corrected+'\n'+junk;
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
            cout<<"\n"<<obj[i].number<<","<<obj[i].name<<","<<obj[i].email<<","<<obj[i].ad<<","<<obj[i].dob<<","<<obj[i].doa<<","<<obj[i].notes<<","<<obj[i].rel<<","<<obj[i].label<<","<<obj[i].qa;
            i++;
    }
    for(i=0;i<nodata-1;i++)
    {
        for(j=0;j<nodata-i-1;j++)
        if(obj[j].name>obj[j+1].name)
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
    for(i=0;i<nodata;i++)
    {
        cout<<obj[i].number<<","<<obj[i].name<<","<<obj[i].email<<","<<obj[i].ad<<","<<obj[i].dob<<","<<obj[i].doa<<","<<obj[i].notes<<","<<obj[i].rel<<","<<obj[i].label<<","<<obj[i].qa<<"\n";
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
void searchn(int &h,string sname,int q)
{
    string junk;
    s:
    cin.ignore(1,'\n');
    if(sname=="NULL")
    {
        cout<<"Enter the name/number/email/address/dob/doa/relation to be searched:\t";
        if(q==0)
        cout<<"\nor type \"exit\" to exit search\n\nYOUR CHOICE:\t";
        getline(cin,sname);
    }
    sname=stoupper(sname);
    int x,y,f=0;
    x=sname.size();
    if(sname!="EXIT")
    {
        ifstream search;
        ofstream searchr;
        search.open(path1);
        searchr.open(path3);
        getline(search,junk,'\n');
        searchr<<"SR. NO.,PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
        while(!search.eof())
        {
            string name, number, email, address, dob, doa, notes, relation,label,qa,temp,temp1,temp2,temp3,temp4;
            getline(search,number,',');
            getline(search,name,',');
            getline(search,email,',');
            getline(search,address,',');
            getline(search,dob,',');
            getline(search,doa,',');
            getline(search,notes,',');
            getline(search,relation,',');
            getline(search,label,',');
            getline(search,qa,'\n');
            temp1=stoupper(name);
            temp2=stoupper(email);
            temp3=stoupper(address);
            temp4=stoupper(relation);
            for(int j=0;j<7;j++)
            {
                if(j==0&&number[0]==sname[0])
                {
                    temp=stoupper(number);
                    f=1;
                }
                else if(j==1&&temp1[0]==sname[0])
                {
                    temp=temp1;
                    f=1;
                }
                else if(j==2&&temp2[0]==sname[0])
                {
                    temp=temp2;
                    f=1;
                }
                else if(j==3&&temp3[0]==sname[0])
                {
                    temp=temp3;
                    f=1;
                }
                else if(j==4&&dob[0]==sname[0])
                {
                    temp=stoupper(dob);
                    f=1;
                }
                else if(j==5&&doa[0]==sname[0])
                {
                    temp=stoupper(doa);
                    f=1;
                }
                else if(j==6&&temp4[0]==sname[0])
                {
                    temp=temp4;
                    f=1;
                }
            }
            y=temp.size();
                if(x<=y&&f==1)
                {
                    int flag=0;
                    for(int j=0;sname[j]!='\0';j++)
                    {
                        if(temp[j]==sname[j])
                        {
                            flag=1;
                        }
                        else
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1)
                    {
                        searchr<<'\n'<<h<<","<<number<<","<<name<<","<<email<<","<<address<<","<<dob<<","<<doa<<','<<notes<<","<<relation<<","<<label<<","<<qa;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14 | FOREGROUND_INTENSITY);
        	            cout<<"\n\n"<<h<<". NAME: "<<left<<name<<"\nPHONE NUMBER: "<<number<<"\nDATE OF BIRTH: ";
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
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                        h++;
                    }
                }
        }
        h=1;
        if(f==0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12 | FOREGROUND_INTENSITY);
            cout<<"NO RESULTS FOUND!\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            h=1;
            if(q==1||q==2)
            {
                int k;
                cout<<"Do you want to search again to ";
                if(q==1)
                cout<<"edit?";
                else if(q==2)
                cout<<"delete?";
                else if(q==3)
                cout<<"add to quick access?";
                cout<<"\nPRESS:\n1:YES\n2:NO(default)\nYOUR CHOICE: ";
                cin>>k;
                if(k==1)
                {
                    search.close();
                    searchr.close();
                    sname="NULL";
                    goto s;
                }
                else
                {
                    search.close();
                    searchr.close();
                    h=-187928;
                    q=0;
                    sname="EXIT";
                    goto s;
                }
            }
        }
        search.close();
        searchr.close();
        if(q==0)
        {
            sname="NULL";
            goto s;
        }
    }
    else
    cout<<"\nEXITING SEARCH\n";
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