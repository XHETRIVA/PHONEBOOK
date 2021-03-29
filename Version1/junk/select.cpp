#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<Windows.h>
#include<sstream>
using namespace std;
void welcome();
void colour(int c);
void correction(string filename);
int checkunino(string num,string &pname,string filename);
void checkno(string num,int &flag);
string inttostr(int x);
string strrev(string str);
void showdata(string filename);
string stoupper(string s);
void searchn(int &h,string sname,int q);
string valueofsr(string sr,int x);
int comparestring(string a,string b);
void showqa();
void addqa();
void remqa();
void option();
void del(string pno,string filename);
int checker(string str1,string str2);
void select();
void deselect();
void edit();
int strtoint(string a);
void addcontacts();
void calc();
void scalc();
void sort();
string returnnum(string sr);
int noline=0,nodata=0,alphaN=0,snoline=0,snodata=0,salphaN=0;
struct contacts
{
    string name,number,email,ad,dob,doa,notes,rel,label,qa,temp;
};
string path1="C:/PHONEBOOK/phonebook.csv",path2="C:/PHONEBOOK/junk.csv",path3="C:/PHONEBOOK/searchresults.csv",path4="C:/PHONEBOOK/selection.csv",path5="C:/PHONEBOOK/copied.csv",path6="C:/PHONEBOOK/accounts.txt",path7="C:/PHONEBOOK/accountchecker.txt";
int main()
{
    option();
}
void option() //all functions
{
    string x,y;
    welcome();
    wapis:
    showqa();
    cout<<"\n\n-------------------------------------------------------------------------------------------------------------------\n";
    colour(143);
    cout<<"PRESS:\n";
    colour(7);
    cout<<"\n1: All Contacts (Displays all contacts)\n2: Add A New Contact\n3: Delete A Contact\n4: Edit A Contact\n5: Add A Contact To Quick Access (The contacts you add here will appear first without having you to search for it)";
    cout<<"\n6: Remove From Quick Access\n7: Dialpad(Search a contact with name, number, address, email etc.)\n8: Select Multiple Contacts(To perform one operation on multiple contacts simultaneously)\n9: Exit (Default)";
    cout<<"\n-------------------------------------------------------------------------------------------------------------------\n";
    cout<<"YOUR CHOICE: ";
    colour(78);
    getline(cin,x);
    colour(7);
    system("cls");
    if(x=="1")
    {
        sort();
        colour(143);
        cout<<"ALL CONTACTS\n\n";
        colour(7);
        showdata(path1.c_str());
        system("pause");
        system("cls");
        goto wapis;
    }
    if(x=="2")
    {
        addcontacts();
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    if(x=="3")
    {
        del("NULL",path2);
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    if(x=="4")
    {
        edit();
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    if(x=="5")
    {
        addqa();
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    if(x=="6")
    {
        remqa();
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    if(x=="7")
    {
        int f=1;
        searchn(f,"NULL",0);
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    if(x=="8")
    {
        select();
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
}
void colour(int c) //adds colour
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void correction(string filename) //removes extra spaces in file
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
int checkunino(string num,string &pname,string filename) //checks for unique numbers and removes duplicate ones
{
    int flag=1;
    ifstream check;
    check.open(filename.c_str());
    string junk;
    getline(check,junk,'\n');
    while(!check.eof())
    {
        string number,name,junk;
        getline(check,number,',');
        getline(check,name,',');
        getline(check,junk,'\n');
        if(checker(num,number)==1)
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
string strrev(string str) //reverses a string
{
    int j=str.size();
    string temp;
    for(int i=0,k=j-1;i<j;i++,k--)
    temp[k]=str[i];
    return temp;
}
int checker(string str1,string str2) //checks the number is valid or not
{
    int flag=1;
    string a=strrev(str1),b=strrev(str2);
    for(int i=0;i<10;i++)
    {
        if(a[i]!=b[i])
        {
            flag=0;
            break;
        }
    }
    return flag;
}
void checkno(string num,int &flag) //checks if it is a number or not
{
    int i;
    char x;
    for(i=0;num[i]!='\0';i++)
    {
        x=num[0];
        if(x=='+'||isdigit(num[i]));
        else
        {
            flag=1;
            break;
        }
    }
    if(i<10||i>13)
    flag=1;
    else if((i>=10&&i<=13)&&flag==0)
    flag=0;
}
string inttostr(int x) //converts integer to string
{
    stringstream ss;
    string s;
    ss<<x;
    ss>>s;
    return s;
}
void showdata(string filename) //displays the data in a file
{
    colour(14);
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
    colour(7);
}
string stoupper(string s) //converts string to upper case
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
void searchn(int &h,string sname,int q) //searches a contact
{
    string junk;
    s:
    if(sname=="NULL")
    {
        cout<<"Enter the name/number/email/address/dob/doa/relation to be searched:\t";
        if(q==0)
        cout<<"\nor type \"exit\" to exit search\n\nYOUR CHOICE:\t";
        colour(78);
        getline(cin,sname);
        colour(7);
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
            string name, number, email, address, dob, doa, notes, relation,label,qa,temp,temp1,temp2,temp3,temp4,temp5,temp6;
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
            temp5=stoupper(doa);
            temp6=stoupper(dob);
            int flag=0;
            if(comparestring(sname,temp1)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp2)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp3)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp4)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp5)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,temp6)==1)
            {
                flag=1;
                goto idharaa;
            }
            if(comparestring(sname,number)==1)
            {
                flag=1;
                goto idharaa;
            }
            idharaa:
            if(flag==1)
            {
                searchr<<'\n'<<h<<","<<number<<","<<name<<","<<email<<","<<address<<","<<dob<<","<<doa<<','<<notes<<","<<relation<<","<<label<<","<<qa;
                colour(14);
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
                colour(7);
                h++;
                f=1;
            }    
        }
        if(f==0)
        {
            colour(64);
            cout<<"NO RESULTS FOUND!\n\n";
            colour(7);
            h=1;
            if(q==1||q==2||q==3||q==4)
            {
                string k;
                cout<<"Do you want to search again to ";
                if(q==1)
                cout<<"edit?";
                else if(q==2)
                cout<<"delete?";
                else if(q==3)
                cout<<"add to quick access?";
                else if(q==4)
                cout<<"select?";
                colour(143);
                cout<<"\nPRESS:";
                colour(7);
                cout<<"\n1: YES\n2: NO(default)\nYOUR CHOICE: ";
                colour(78);
                getline(cin,k);
                colour(7);
                if(k=="1")
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
    {
        colour(4);
        cout<<"\nEXITING SEARCH\n";
        colour(7);
    }
}
int comparestring(string a,string b)
{
    int x=a.size(),y=b.size(),flag=0;
    if(x<=y)
    {
        for(int j=0;a[j]!='\0';j++)
        {
            if(b[j]==a[j])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
        }
    }
    else 
    flag=0;
    return flag;
}
void showqa() //displays data in quickaccess
{
    int data=0;
    colour(143);
    cout<<"QUICK ACCESS\n";
    colour(7);
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
            colour(14);
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
            colour(7);
            data++;
        }
    }
    if(data==0)
    {
        colour(64);
        cout<<"OOPS! There is no contacts saved in quickaccess!";
        colour(7);
    }
}
void addqa() //adds data to quickaccess
{
    int x=1;
    searchn(x,"NULL",2);
    string adqa,name,number,email,ad,dob,doa,notes,rel,label,qa,junk,qaf="";
    cout<<"Enter the serial no. you want to add to quickaccess or type \"exit\" to exit the fuction: ";
    colour(78);
    getline(cin,adqa);
    colour(7);
    if(adqa!="exit")
    {
        string xstr=inttostr(x);
        if(adqa>=xstr||adqa<"1")
        adqa="1";
        string editno=returnnum(adqa);
        ifstream open(path2);
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
            if(editno==number)
            {
                qaf+='\n'+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+'1';
                colour(64);
                cout<<"Added Successfully!\n";
                colour(7);
            }
            else
            {
                qaf+='\n'+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+qa;
            }
        }
        open.close();
        ofstream op(path2);
        op<<qaf;
        op.close();
        sort();
    }
}
void remqa() //removes data form quick access
{
    int x=1;
    searchn(x,"NULL",2);
    string remqa,name,number,email,ad,dob,doa,notes,rel,label,qa,junk,qaf="";
    cout<<"Enter the serial no. you want to remove from quickaccess or type \"exit\" to exit the fuction: ";
    colour(78);
    getline(cin,remqa);
    colour(7);
    if(remqa!="exit")
    {
        string xstr=inttostr(x);
        if(remqa>=xstr||remqa<"1")
        remqa="1";
        string editno=returnnum(remqa);
        ifstream ohno(path2);
        getline(ohno,junk,'\n');
        qaf+=junk;
        while(!ohno.eof())
        {
            getline(ohno,number,',');
            getline(ohno,name,',');
            getline(ohno,email,',');
            getline(ohno,ad,',');
            getline(ohno,dob,',');
            getline(ohno,doa,',');
            getline(ohno,notes,',');
            getline(ohno,rel,',');
            getline(ohno,label,',');
            getline(ohno,qa,'\n');
            if(editno==number)
            {
                qaf+='\n'+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+'0';
                colour(64);
                cout<<"Removed Successfully!\n";
                colour(7);
            }
            else
            {
                qaf+='\n'+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+qa;
            }
        }
        ohno.close();
        ofstream oh(path2);
        oh<<qaf;
        oh.close();
        sort();
    }
}
string valueofsr(string sr,int x)
{
    int flag=0;
    for(int i=1;i<x;i++)
    {
        if(sr==inttostr(i))
        {
            flag=1;
            break;
        }
        else
        flag=0;
    }
    if(flag==0)
    sr="-187928";
    return sr;
}
void edit() //edits the data
{
    sort();
    int x=1;
    string sr="",editno="",temp1="",temp2="",temp3="",fname="",fno="",fad="",fem="",temp="",fdoa="",fdob="",fnote="",frel="",flabel="",fqa="",z,y;
    searchn(x,"NULL",1);
    e1:
    if(x!=-187928)
    {
        if(x!=2)
        {
            cout<<"\n\nWhich sr. number do you want to edit?\n(NOTE: If the sr. number entered is not present then by default the option would be selected as sr. number 1.)\n\nYOUR CHOICE:\t";
            colour(78);
            getline(cin,y);
            colour(7);
        }
        else
        y="1";
        sr=y;
        editno=returnnum(sr);
        ifstream editin(path2);
        int d=0;
        while(!editin.eof())
        {
            string name,number,email,ad,dob,doa,notes,rel,label,qa,i;
            getline(editin,number,',');
            getline(editin,name,',');
            getline(editin,email,',');
            getline(editin,ad,',');
            getline(editin,dob,',');
            getline(editin,doa,',');
            getline(editin,notes,',');
            getline(editin,rel,',');
            getline(editin,label,',');
            getline(editin,qa,'\n');
            if(editno==number)
            {
                fname=name;
                fno=number;
                fem=email;
                fad=ad;
                fdob=dob;
                fdoa=doa;
                fnote=notes;
                frel=rel;
                flabel=label;
                fqa=qa;
                d=1;
            }
            else if(d==0)
            temp1=temp1+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+qa+'\n';
            else if(d==1)
            temp3=temp3+'\n'+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+qa;
        }
        e:
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1. Change Name\n2. Change Number\n3. Change Email\n4. Change Address\n5. Change Date Of Birth\n6. Change Date Of Anniversary";
        cout<<"\n7. Change Notes\n8. Change Relation\n9. Change Label\n10. To Stop Editing(default)\n\nYOUR CHOICE:";
        colour(78);
        getline(cin,z);
        colour(7);
        if(z=="1")
        {
            cout<<"\n\nOLD NAME: "<<fname<<"\n\nEnter the new name: ";
            colour(78);
            getline(cin,fname);
            colour(7);
        }
        else if(z=="2")
        {
            cout<<"\n\nOLD NUMBER: "<<fno<<"\n\nEnter the new number: ";
            colour(78);
            getline(cin,fno);
            colour(7);
        }
        else if(z=="3")
        {
            cout<<"\n\nOLD EMAIL: "<<fem<<"\n\nEnter the new email: ";
            colour(78);
            getline(cin,fem);
            colour(7);
        }
        else if(z=="4")
        {
            cout<<"\n\nOLD ADDRESS: "<<fad<<"\n\nEnter the new address: ";
            colour(78);
            getline(cin,fad);
            colour(7);
        }
        else if(z=="5")
        {
            cout<<"\n\nOLD DATE OF BIRTH: "<<fdob<<"\n\nEnter the new date of birth: ";
            colour(78);
            getline(cin,fdob);
            colour(7);
        }
        else if(z=="6")
        {
            cout<<"\n\nOLD DATE OF ANNIVERSARY: "<<fdoa<<"\n\nEnter the new date of anniversary: ";
            colour(78);
            getline(cin,fdoa);
            colour(7);
        }
        else if(z=="7")
        {
            cout<<"\n\nOLD NOTE: "<<fnote<<"\n\nEnter the new note: ";
            colour(78);
            getline(cin,fnote);
            colour(7);
        }
        else if(z=="8")
        {
            cout<<"\n\nOLD RELATION: "<<frel<<"\n\nEnter the new relation: ";
            colour(78);
            getline(cin,frel);
            colour(7);
        }
        else if(z=="9")
        {
            cout<<"\n\nOLD LABEL: "<<flabel<<"\n\nEnter the new label: ";
            colour(78);
            getline(cin,flabel);
            colour(7);
        }
        else
        {
            x=-187928;
            goto e1;
        }
        temp2=fno+','+fname+','+fem+','+fad+','+fdob+','+fdoa+','+fnote+','+frel+','+flabel+','+fqa;
        temp=temp1+temp2+temp3;
        ofstream edited(path2);
        edited<<temp;
        edited.close();
        sort();
        int g=remove(path3.c_str());
    }
    else
    {
        colour(64);
        cout<<"\n\nEDITING CANCELLED\n\n";
        colour(7);
    }
}
string returnnum(string sr) //assigns the ph.no. from the sr.no.
{
    string editno;
    ifstream obtsr(path3);
        while(!obtsr.eof())
        {
            string i,number,junk;
            getline(obtsr,i,',');
            getline(obtsr,number,',');
            getline(obtsr,junk,'\n');
            if(sr==i)
            {
                editno=number;
                break;
            }
        }
        obtsr.close();
        return editno;
}
int strtoint(string a) //converts string to integer
{
    int x=0;
    stringstream as(a);
    as>>x;
    return x;
}
void addcontacts() //adds contacts to the file
{
    correction(path2);
    correction(path1);
    sort();
    ofstream file(path2.c_str(),ios::app);
    string name,no,email="",ad="",dob="",doa="",notes="",rel="",label="",qa="0",l="1";
    if(noline>0&&alphaN==0)
    file<<"PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
    reno:
    int flag=0;
    cout<<"Enter the phone number: ";
    colour(78);
    getline(cin,no);
    colour(7);
    checkno(no,flag);
    if(flag==1)
    {
        colour(64);
        cout<<"\nERROR:: Wrong format for phone number!\n\n";
        colour(7);
        goto reno;
    }
    int c=checkunino(no,name,path2);
    if(c==0)
    {
        colour(64);
        cout<<"ERROR:Two person cannot have same phone number.";
        colour(7);
        cout<<"\n\nThe phone number "<<no<<" already belongs to "<<name;
        colour(143);
        cout<<"\nPRESS:";
        colour(7);
        cout<<"\n1:To re-enter phone number\n2:To skip adding(default)\n\nYOUR CHOICE: ";
        colour(78);
        getline(cin,l);
        colour(7);
        if(l=="1")
        goto reno;
    }
    if(l=="1")
    {
        cout<<"Do you want to enter the name?";
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1-YES\n2-NO\nYOUR CHOICE: ";
        string a;
        colour(78);
        getline(cin,a);
        colour(7);
        if(a=="1")
        {
            cout<<"\nEnter the name: ";
            colour(78);
            getline(cin,name);
            colour(7);
        }
        else
        {
            name=no;
        }
        cout<<"\nDo you want to enter the e-mail?";
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1-YES\n2-NO\nYOUR CHOICE: ";
        colour(78);
        getline(cin,a);
        colour(7);
        if(a=="1")
        {
            cout<<"\nEnter the e-mail: ";
            colour(78);
            getline(cin,email);
            colour(7);
        }
        cout<<"\nDo you want to enter the address?";
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1-YES\n2-NO\nYOUR CHOICE: ";
        colour(78);
        getline(cin,a);
        colour(7);
        if(a=="1")
        {
            cout<<"\nEnter the address: ";
            colour(78);
            getline(cin,ad);
            colour(7);
        }
        cout<<"\nDo you want to enter the date of birth?";
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1-YES\n2-NO\nYOUR CHOICE: ";
        colour(78);
        getline(cin,a);
        colour(7);
        if(a=="1")
        {
            cout<<"\nEnter the date of birth: ";
            colour(78);
            getline(cin,dob);
            colour(7);
        }
        cout<<"\nDo you want to enter the date of anniversary?";
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1-YES\n2-NO\nYOUR CHOICE: ";
        colour(78);
        getline(cin,a);
        colour(7);
        if(a=="1")
        {
            cout<<"\nEnter the date of anniversary: ";
            colour(78);
            getline(cin,doa);
            colour(7);
        }
        cout<<"\nDo you want to enter any notes?";
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1-YES\n2-NO\nYOUR CHOICE: ";
        colour(78);
        getline(cin,a);
        colour(7);
        if(a=="1")
        {
            cout<<"\nEnter the notes: ";
            colour(78);
            getline(cin,notes);
            colour(7);
        }
        cout<<"\nDo you want to enter the relation?";
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1-YES\n2-NO\nYOUR CHOICE: ";
        colour(78);
        getline(cin,a);
        colour(7);
        if(a=="1")
        {
            cout<<"\nEnter the relation: ";
            colour(78);
            getline(cin,rel);
            colour(7);
        }
        cout<<"\nDo you want to enter any label?";
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1-YES\n2-NO\nYOUR CHOICE: ";
        colour(78);
        getline(cin,a);
        colour(7);
        if(a=="1")
        {
            cout<<"\nEnter the label: ";
            colour(78);
            getline(cin,label);
            colour(7);
        }
        file<<'\n'<<no<<","<<name<<","<<email<<","<<ad<<","<<dob<<","<<doa<<','<<notes<<","<<rel<<","<<label<<","<<qa;
    }
    file.close();
    correction(path2);
    sort();
    showdata(path1);
}
void scalc() //calculates no of data selected
{
    salphaN=0;
    snodata=0;
    snoline=0;
    string cd,junk;
    ifstream cal(path4.c_str());
    while(!cal.eof())
    {
        getline(cal,cd,',');
        getline(cal,junk,'\n');
        if(isdigit(cd[0])||cd[0]=='+')
        snodata++;
        if(cd[0]=='P')
        salphaN=1;
        snoline++;
    }
    cal.close();
}
void calc() //calculates total no of data
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
void sort() //sorts data in acsending order
{
    scalc();
    calc();
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
void welcome() //welcome page
{
    system("cls");
    colour(8);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n                    P P P P P  H       H  O O O O O  N       N  E E E E E  B B B B    O O O O O  O O O O O  K     K\n";
    Sleep(150);
    cout<<"                    P       P  H       H  O       O  N N     N  E          B       B  O       O  O       O  K    K\n";
    Sleep(150);
    cout<<"                    P       P  H       H  O       O  N  N    N  E          B      B   O       O  O       O  K   K\n";
    Sleep(150);
    cout<<"                    P P P P P  H H H H H  O       O  N   N   N  E E E      B B B B    O       O  O       O  K K\n";
    colour(12);
    Sleep(150);
    cout<<"                    P          H       H  O       O  N    N  N  E          B      B   O       O  O       O  K   K\n";
    Sleep(150);
    cout<<"                    P          H       H  O       O  N     N N  E          B       B  O       O  O       O  K    K\n";
    Sleep(150);
    cout<<"                    P          H       H  O O O O O  N       N  E E E E E  B B B B    O O O O O  O O O O O  K      K\n";
    colour(7);
    Sleep(2000);
    cout<<"\a";
    system("cls");
}
void del(string pno,string filename) //deletes data
{
    correction(path2);
    correction(path1);
    correction(path4);
    sort();
    string sr,y;
    if(pno=="NULL")
    {
        yahan:
        int x=1;
        searchn(x,"NULL",2);
        if(x!=-187928)
        {
            cout<<"\n\nWhich sr. number do you want to select? Or type \"exit\" to exit selecting. Or type \"again\" to search again\n\nYOUR CHOICE: ";
            colour(78);
            getline(cin,y);
            colour(7);
            if(stoupper(y)=="EXIT")
            {
                goto nikal;
            }
            else if(stoupper(y)=="AGAIN")
            {
                system("cls");
                goto yahan;
            }
            else
            {
                y=valueofsr(y,x);
                if(y=="-187928")
                {
                    system("cls");
                    colour(64);
                    cout<<"\nInvalid Sr. No.!";
                    colour(7);
                    Sleep(2000);
                    system("cls");
                    colour(14);
                    cout<<"\nEnter again:\n\n";
                    colour(7);
                    goto yahan;
                }
            }
            sr=y;
            pno=returnnum(sr);
        }
        else
        {
            nikal:
            colour(7);
        }
    }
    ifstream file(filename.c_str());
    string fdata,jun;
    getline(file,jun,'\n');
    fdata=jun;
    while(!file.eof())
    {
        string number,junk;
        getline(file,number,',');
        getline(file,junk,'\n');
        if(pno!=number)
        {
            fdata+='\n'+number+','+junk;
        }
    }
    file.close();
    ofstream file1(filename.c_str());
    file1<<fdata;
    file1.close();
    sort();
}
void select() //adds contacts to the file
{
    correction(path2);
    correction(path1);
    correction(path4);
    sort();
    string name,k,no,email,ad,dob,doa,notes,rel,label,qa,l="1",seleno,sr,y,z,junk;
    ofstream file(path4.c_str());
    scalc();
    if(snoline>0&&salphaN==0)
    file<<"PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
    file.close();
    again:
    int x=1;
    searchn(x,"NULL",4);
    if(x!=-187928)
    {
        cout<<"\n\nWhich sr. number do you want to select? Or type \"exit\" to exit selecting. Or type \"again\" to search again\n\nYOUR CHOICE: ";
        colour(78);
        getline(cin,y);
        colour(7);
        if(stoupper(y)=="EXIT")
        {
            goto exiting;
        }
        else if(stoupper(y)=="AGAIN")
        {
            system("cls");
            goto again;
        }
        else
        y=valueofsr(y,x);
        if(y=="-187928")
        {
            system("cls");
            colour(64);
            cout<<"\nInvalid Sr. No.!";
            colour(7);
            Sleep(2000);
            system("cls");
            colour(14);
            cout<<"\nEnter again:\n\n";
            colour(7);
            goto again;
        }
        sr=y;
        seleno=returnnum(sr);
        int c=checkunino(seleno,name,path4);
        if(c==0)
        {
            yo:
            colour(64);
            cout<<"ERROR:The contact is already selected!";
            colour(143);
            cout<<"\nPRESS:";
            colour(7);
            cout<<"\n1:To search again\n2:To skip selecting\n\nYOUR CHOICE: ";
            colour(78);
            getline(cin,l);
            colour(7);
            if(l=="1")
            {
                system("cls");
                goto again;
            }
            else if(l=="2")
            {
                goto exiting;
            }
            else
            {
                colour(4);
                cout<<"ERROR: Enter again!";
                colour(7);
                Sleep(2000);
                system("cls");
                goto yo;
            }
        }
        else
        {
            ifstream selec(path2);
            ofstream sel(path4, ios::app);
            getline(selec,junk,'\n');
            while(!selec.eof())
            {
                string name,number,email,ad,dob,doa,notes,rel,label,qa,i;
                getline(selec,number,',');
                getline(selec,name,',');
                getline(selec,email,',');
                getline(selec,ad,',');
                getline(selec,dob,',');
                getline(selec,doa,',');
                getline(selec,notes,',');
                getline(selec,rel,',');
                getline(selec,label,',');
                getline(selec,qa,'\n');
                if(seleno==number)
                {
                    sel<<'\n'<<number<<","<<name<<","<<email<<","<<ad<<","<<dob<<","<<doa<<','<<notes<<","<<rel<<","<<label<<","<<qa;
                    colour(64);
                    cout<<"\nSelected Successfully!\n";
                    colour(7);
                }
            }
            sel.close();
            selec.close();            
            yoy:
            cout<<"\nDo you want to select more contacts?";
            colour(143);
            cout<<"\n\nPRESS:";
            colour(7);
            cout<<"\n1: YES\n2: NO\nYOUR CHOICE: ";
            colour(78);
            getline(cin,z);
            colour(7);
            if(z=="1")
            goto again;
            else if(z=="2")
            {
                system("cls");
                colour(143);
                cout<<"\nSelected Contacts\n\n";
                colour(7);
                showdata(path4.c_str());
                scalc();
                deselect();
                kyahbey:
                scalc();
                if(snodata==1)
                {
                    yoyo:
                    cout<<"Do you want to edit or delete the contact?";
                    colour(143);
                    cout<<"\n\nPRESS:";
                    colour(7);
                    cout<<"\n1: Edit\n2: Delete\n3:Deselect\n4: Exit\nYOUR CHOICE: ";
                    colour(78);
                    getline(cin,k);
                    colour(7);
                    if(k=="1")
                    {
                        edit();
                        colour(64);
                        cout<<"Edited Successfully";
                        colour(7);
                    }
                    else if(k=="2")
                    {
                        string junkk,number;
                        ifstream file2(path4);
                        while(!file2.eof())
                        {
                            getline(file2,number,',');
                            getline(file2,junkk,'\n');
                            del(number,path2);
                        }
                        colour(64);
                        cout<<"Deleted Successfully";
                        colour(7);
                        file2.close();
                    }
                    else if(k=="3")
                    {
                        deselect();
                        goto kyahbey;
                    }
                    else if(k=="4")
                    {
                        goto exiting;
                    }
                    else
                    {
                        colour(4);
                        cout<<"ERROR: Enter again!";
                        colour(7);
                        Sleep(2000);
                        system("cls");
                        goto yoyo;
                    }
                }
                else if(snodata>1)
                {
                    yoyoy:
                    cout<<"Do you want to delete the contacts?";
                    colour(143);
                    cout<<"\n\nPRESS:";
                    colour(7);
                    cout<<"\n1: Delete\n2: Exit\nYOUR CHOICE: ";
                    colour(78);
                    getline(cin,k);
                    colour(7);
                    if(k=="1")
                    {
                        string junkk,number;
                        ifstream file4(path4);
                        while(!file4.eof())
                        {
                            getline(file4,number,',');
                            getline(file4,junkk,'\n');
                            del(number,path2);
                        }
                        colour(64);
                        cout<<"Deleted Successfully";
                        colour(7);
                        file4.close();
                    }
                    else if(k=="2")
                    {
                        goto exiting;
                    }
                    else
                    {
                        colour(4);
                        cout<<"ERROR: Enter again!";
                        colour(7);
                        Sleep(2000);
                        system("cls");
                        goto yoyoy;
                    }
                    
                }
            }
            else
            {
                colour(4);
                cout<<"ERROR: Enter again!";
                colour(7);
                Sleep(2000);
                system("cls");
                goto yoy;
            }
        }
        correction(path4);
        sort();
    }
    else
    {
        exiting:
        colour(7);
    }
}
void deselect()
{
    phu:
    string k;
    cout<<"Do you want to deselect any contact?";
    colour(143);
    cout<<"\n\nPRESS:";
    colour(7);
    cout<<"\n1: Yes\n2: No\nYOUR CHOICE: ";
    colour(78);
    getline(cin,k);
    colour(7);
    if(k=="1")
    {
        int flag=0;
        string pr,no,junk;;
        cout<<"\nEnter which phone no. you want to deselect: ";
        colour(78);
        getline(cin,pr);
        colour(7);
        ifstream fix(path4.c_str());
        while(!fix.eof())
        {
            getline(fix, no,',');
            getline(fix,junk,'\n');
            if(comparestring(pr,no)==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            del(no,path4);
            colour(64);
            cout<<"Removed Successfully\n\n";
            colour(7);
            phuu:
            sort();
        }
        fix.close();
    }
    else if(k=="2");
    else
    {
        colour(4);
        cout<<"ERROR: Enter again!";
        colour(7);
        Sleep(2000);
        system("cls");
        goto phu;
    }
}