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
int checkunino(string num,string &pname,string filename,int q);
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
void deselect(string deselectno);
void edit(string editno);
int strtoint(string a);
void addcontacts();
void calc();
void scalc();
void sort();
void settings();
string returnnum(string sr,string filename);
void change(int q);
void masterdelete();
void accdelete();
int checkpass(string pass);
void logout();
string returnpass();
int availofid(string enteredid,string &passcheck);
int checkid(string id);
void storemode(string shutup,int q);
void createfile(string filename);
void correctionaccd(string filename);
int loginfunc(int q);
void codedstorage(int q,string &value);
void makeorremovefilename(int q);
void openpathfile(string file);
void codedstoragetot(int q,string &a,string &b,string &c,string &d,string &e,string &f,string &g,string &h);
int noline=0,nodata=0,alphaN=0,snoline=0,snodata=0,salphaN=0,nooftrials=0,loggedin=1;
string loginid="rudra33333",loginpass="",login;
struct contacts
{
    string name,number,email,ad,dob,doa,notes,rel,label,qa,temp;
};
string basepath="C:/PHONEBOOK/",path1="",path2="",path3="C:/PHONEBOOK/searchresults.csv",path4="C:/PHONEBOOK/selection.csv",path5="C:/PHONEBOOK/copied.csv",path6="C:/PHONEBOOK/accounts.txt";
int main()
{
    makeorremovefilename(0);
    option();
}
void option() //all functions
{
    string x,y;
    welcome();
    wapis:
    showqa();
    colour(159);
    cout<<"\n\n================================================== ";
    colour(144);
    cout<<"SELECT ";
    colour(159);
    cout<<"=============================================================\n\n";
    colour(143);
    cout<<"PRESS:\n";
    colour(7);
    cout<<"\n1: All Contacts (Displays all contacts)\n2: Add A New Contact\n3: Delete A Contact\n4: Edit A Contact\n5: Add A Contact To Quick Access (The contacts you add here will appear first without having you to search for it)";
    cout<<"\n6: Remove From Quick Access\n7: Dialpad(Search a contact with name, number, address, email etc.)\n8: Select Multiple Contacts(To perform one operation on multiple contacts simultaneously)\n9: Settings";
    colour(159);
    cout<<"\n\n=======================================================================================================================\n";
    colour(7);
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
    else if(x=="2")
    {
        addcontacts();
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    else if(x=="3")
    {
        del("NULL",path2);
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    else if(x=="4")
    {
        edit("NULL");
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    else if(x=="5")
    {
        addqa();
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    else if(x=="6")
    {
        remqa();
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    else if(x=="7")
    {
        int f=1;
        searchn(f,"NULL",0);
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    else if(x=="8")
    {
        select();
        system("pause");
        int b=remove(path4.c_str());
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    else if(x=="9")
    {
        settings();
        if(loggedin!=0)
        goto wapis;
    }
    else
    {
        colour(4);
        cout<<"ERROR: Enter again!";
        colour(7);
        Sleep(2000);
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
int checkunino(string num,string &pname,string filename,int q) //checks for unique numbers and removes duplicate ones
{
    int flag=1;
    ifstream check;
    check.open(filename.c_str());
    string junk;
    getline(check,junk,'\n');
    while(!check.eof())
    {
        string sr,number,name,junk;
        if(q==1)
        getline(check,sr,',');
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
        codedstoragetot(1,name,email,address,dob,doa,notes,relation,label);
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
            codedstoragetot(1,name,email,address,relation,doa,dob,label,notes);
            temp1=stoupper(name);
            temp2=stoupper(email);
            temp3=stoupper(address);
            temp4=stoupper(relation);
            temp5=stoupper(doa);
            temp6=stoupper(dob);
            //if statement for remove qa(checker ki qa mein h yah nhi..)(changes using q factor)
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
                codedstoragetot(0,name,email,address,dob,doa,notes,relation,label);
                searchr<<'\n'<<h<<","<<number<<","<<name<<","<<email<<","<<address<<","<<dob<<","<<doa<<','<<notes<<","<<relation<<","<<label<<","<<qa;
                colour(14);
                codedstoragetot(1,name,email,address,dob,doa,notes,relation,label);
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
                r:
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
                else if(k=="2")
                {
                    search.close();
                    searchr.close();
                    h=-187928;
                    q=0;
                    sname="EXIT";
                    goto s;
                }
                else
                {
                    colour(4);
                    cout<<"ERROR: Enter again!";
                    colour(7);
                    Sleep(2000);
                    system("cls");
                    goto r;
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
        colour(64);
        cout<<"\nEXITING SEARCH\n";
        colour(7);
    }
}
int comparestring(string a,string b) //compares 2 strings
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
        cout<<"OOPS! There are no contacts saved in quickaccess!";
        colour(7);
    }
}
void addqa() //adds data to quickaccess
{
    int x=1;
    searchn(x,"NULL",3);
    string adqa,name,number,email,ad,dob,doa,notes,rel,label,qa,junk,qaf="";
    cout<<"Enter the serial no. you want to add to quickaccess or type \"exit\" to exit the fuction: ";
    colour(78);
    getline(cin,adqa);
    colour(7);
    if(stoupper(adqa)!="EXIT")
    {
        string xstr=inttostr(x);
        if(adqa>=xstr||adqa<"1")
        adqa="1";
        string editno=returnnum(adqa,path3);
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
                cout<<"\nAdded Successfully!\n";
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
    searchn(x,"NULL",3);
    string remqa,name,number,email,ad,dob,doa,notes,rel,label,qa,junk,qaf="";
    cout<<"Enter the serial no. you want to remove from quickaccess or type \"exit\" to exit the fuction: ";
    colour(78);
    getline(cin,remqa);
    colour(7);
    if(stoupper(remqa)!="EXIT")
    {
        string xstr=inttostr(x);
        if(remqa>=xstr||remqa<"1")
        remqa="1";
        string editno=returnnum(remqa,path3);
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
string valueofsr(string sr,int x) //returns the value of sr
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
void edit(string editno) //edits the data
{
    
        ru:
        sort();
        int x=1;
        string sr="",temp1="",temp2="",temp3="",fname="",fno="",fad="",fem="",temp="",fdoa="",fdob="",fnote="",frel="",flabel="",fqa="",z,y;
        if(editno=="NULL")
        searchn(x,"NULL",1);
        e1:
        if(x!=-187928)
        {
            if(editno=="NULL")
            {
            cout<<"\n\nWhich sr. number do you want to edit?\n\nYOUR CHOICE:  ";//////////////fucking needs an exit button//////////////////////
            colour(78);
            getline(cin,y);
            colour(7);
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
                goto ru;
            }
            sr=y;
            editno=returnnum(sr,path3);
            }
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
                codedstoragetot(1,fname,fem,fad,fdob,fdoa,fnote,frel,flabel);
            }
            else if(d==0)
            temp1=temp1+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+qa+'\n';
            else if(d==1)
            temp3=temp3+'\n'+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+qa;
        }
        e:
        system("cls");
        colour(14);
        cout<<"\n\nNAME: "<<left<<fname<<"\nPHONE NUMBER: "<<fno<<"\nDATE OF BIRTH: ";
        if(fdob=="")
        cout<<" - ";
        cout<<fdob<<"\nDATE OF ANNIVERSARY: ";
        if(fdoa=="")
        cout<<" - ";
        cout<<fdoa<<"\nRELATION: ";
        if(frel=="")
        cout<<" - ";
        cout<<frel<<"\nLABEL: ";
        if(flabel=="")
        cout<<" - ";
        cout<<flabel<<"\nNOTES: ";
        if(fnote=="")
        cout<<" - ";
        cout<<fnote<<"\nEMAIL: ";
        if(fem=="")
        cout<<" - ";
        cout<<fem<<"\nADDRESS: ";
        if(fad=="")
        cout<<" - ";
        cout<<fad<<"\n";
        colour(143);
        cout<<"\n\nPRESS:";
        colour(7);
        cout<<"\n1. Change Name\n2. Change Number\n3. Change Email\n4. Change Address\n5. Change Date Of Birth\n6. Change Date Of Anniversary";
        cout<<"\n7. Change Notes\n8. Change Relation\n9. Change Label\nOR\nTYPE:\n\"stop\": To Stop Editing\n\nYOUR CHOICE:";
        colour(78);
        getline(cin,z);
        colour(7);
        if(z=="1")
        {
            cout<<"\n\nOLD NAME: "<<fname<<"\n\nEnter the new name: ";
            colour(78);
            getline(cin,fname);
            colour(7);
            goto e;
        }
        else if(z=="2")
        {
            cout<<"\n\nOLD NUMBER: "<<fno<<"\n\nEnter the new number: ";
            colour(78);
            getline(cin,fno);
            colour(7);
            goto e;
        }
        else if(z=="3")
        {
            cout<<"\n\nOLD EMAIL: "<<fem<<"\n\nEnter the new email: ";
            colour(78);
            getline(cin,fem);
            colour(7);
            goto e;
        }
        else if(z=="4")
        {
            cout<<"\n\nOLD ADDRESS: "<<fad<<"\n\nEnter the new address: ";
            colour(78);
            getline(cin,fad);
            colour(7);
            goto e;
        }
        else if(z=="5")
        {
            cout<<"\n\nOLD DATE OF BIRTH: "<<fdob<<"\n\nEnter the new date of birth: ";
            colour(78);
            getline(cin,fdob);
            colour(7);
            goto e;
        }
        else if(z=="6")
        {
            cout<<"\n\nOLD DATE OF ANNIVERSARY: "<<fdoa<<"\n\nEnter the new date of anniversary: ";
            colour(78);
            getline(cin,fdoa);
            colour(7);
            goto e;
        }
        else if(z=="7")
        {
            cout<<"\n\nOLD NOTE: "<<fnote<<"\n\nEnter the new note: ";
            colour(78);
            getline(cin,fnote);
            colour(7);
            goto e;
        }
        else if(z=="8")
        {
            cout<<"\n\nOLD RELATION: "<<frel<<"\n\nEnter the new relation: ";
            colour(78);
            getline(cin,frel);
            colour(7);
            goto e;
        }
        else if(z=="9")
        {
            cout<<"\n\nOLD LABEL: "<<flabel<<"\n\nEnter the new label: ";
            colour(78);
            getline(cin,flabel);
            colour(7);
            goto e;
        }
        else if(stoupper(z)=="STOP")
        {
            x=-187928;
        }
        else
        {
            colour(4);
            cout<<"ERROR: Enter again!";
            colour(7);
            Sleep(2000);
            system("cls");
            goto e;
        }
        codedstoragetot(0,fname,fem,fad,fdob,fdoa,fnote,frel,flabel);
        temp2=fno+','+fname+','+fem+','+fad+','+fdob+','+fdoa+','+fnote+','+frel+','+flabel+','+fqa;
        temp=temp1+temp2+temp3;
        ofstream edited(path2);
        edited<<temp;
        colour(64);
        cout<<"\nEdited Successfully!\n";
        colour(7);
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
string returnnum(string sr,string filename) //assigns the ph.no. from the sr.no.
{
    string editno;
    ifstream obtsr(filename.c_str());
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
    int c=checkunino(no,name,path2,0);
    if(c==0)
    {
        colour(64);
        cout<<"ERROR:Two person cannot have same phone number.";
        colour(7);
        rud:
        cout<<"\n\nThe phone number "<<no<<" already belongs to "<<name;
        colour(143);
        cout<<"\nPRESS:";
        colour(7);
        cout<<"\n1:To re-enter phone number\n2:To skip adding\n\nYOUR CHOICE: ";
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
        codedstoragetot(0,name,email,ad,dob,doa,notes,rel,label);
        file<<'\n'<<no<<","<<name<<","<<email<<","<<ad<<","<<dob<<","<<doa<<','<<notes<<","<<rel<<","<<label<<","<<qa;
    }
    else if(l=="2");
    else
    {
        colour(4);
        cout<<"ERROR: Enter again!";
        colour(7);
        Sleep(2000);
        system("cls");
        goto rud;
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
        codedstorage(1,obj[i].name);
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
        codedstorage(0,obj[i].name);
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
            pno=returnnum(sr,path3);
        }
        else
        {
            nikal:
            colour(7);
        }
    }
    if(filename.c_str()==path2)
    {
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
    else if(filename.c_str()==path4)
    {
        ifstream file5(filename.c_str());
        string fdata,jun;
        getline(file5,jun,'\n');
        fdata=jun;
        while(!file5.eof())
        {
            string number,i,junk;
            getline(file5,i,',');
            getline(file5,number,',');
            getline(file5,junk,'\n');
            if(pno!=number)
            {
                fdata+='\n'+i+','+number+','+junk;
            }
        }
        file5.close();
        ofstream file11(filename.c_str());
        file11<<fdata;
        file11.close();
        sort();
    }
}
void select() //adds contacts to the file
{
    correction(path2);
    correction(path1);
    correction(path4);
    sort();
    string name,k,no,email,ad,dob,doa,notes,rel,label,qa,l="1",seleno,sr,y,z,junk;
    int h=1;
    ofstream file(path4.c_str(),ios::app);
    scalc();
    if(snoline>0&&salphaN==0)
    file<<"SR. NO.,PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
    file.close();
    again:
    int x=1,c=1;
    searchn(x,"NULL",4);
    if(x!=-187928||x!=1)
    {
        cout<<"\n\nWhich sr. number do you want to select? OR\n";
        colour(143);
        cout<<"TYPE:";
        colour(7);
        cout<<"\n\"exit\": To exit selecting and go to main menu.\n\"cancel\": To exit selecting and show the selected contacts.\n\"again\": To search again\n\nYOUR CHOICE: ";
        colour(78);
        getline(cin,y);
        colour(7);
        if(stoupper(y)=="EXIT");
        else if(stoupper(y)=="AGAIN")
        {
            system("cls");
            goto again;
        }
        else if(stoupper(y)!="EXIT"&&stoupper(y)!="AGAIN")
        {
            if(stoupper(y)!="CANCEL")
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
                    goto again;
                }
                sr=y;
                seleno=returnnum(sr,path3);
                c=checkunino(seleno,name,path4,1);
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
                        string name,number,email,ad,dob,doa,notes,rel,label,qa;
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
                            sel<<'\n'<<h<<','<<number<<","<<name<<","<<email<<","<<ad<<","<<dob<<","<<doa<<','<<notes<<","<<rel<<","<<label<<","<<qa;
                            h++;
                            colour(64);
                            cout<<"\nSelected Successfully!\n";
                            colour(7);
                        }
                    }
                    sel.close();
                    selec.close();            
                }
                yoy:
                cout<<"\nDo you want to select more contacts?";
                colour(143);
                cout<<"\n\nPRESS:";
                colour(7);
                cout<<"\n1: YES\n2: NO\nYOUR CHOICE: ";
                colour(78);
                getline(cin,z);
                colour(7);
            }
            else
            z="2";
            if(z=="1")
            goto again;
            else if(z=="2")
            {
                scalc();
                if(snodata!=0)
                {
                    yoyo:
                    system("cls");
                    colour(143);
                    cout<<"\nSelected Contacts\n\n";
                    colour(7);
                    ifstream file8(path4);
                    string bakwas;
                    getline(file8,bakwas,'\n');
                    while(!file8.eof())
                    {
                        string name,number,dob,doa,relation,label,notes,email,address,pr;
                        getline(file8,pr,',');
                        getline(file8,number,',');
                        getline(file8,name,',');
                        getline(file8,email,',');
                        getline(file8,address,',');
                        getline(file8,dob,',');
                        getline(file8,doa,',');
                        getline(file8,notes,',');
                        getline(file8,relation,',');
                        getline(file8,label,',');
                        getline(file8,qa,'\n');
                        colour(14);
    	                cout<<"\n\n"<<pr<<". NAME: "<<left<<name<<"\nPHONE NUMBER: "<<number<<"\nDATE OF BIRTH: ";
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
                    }
                    file8.close();
                    scalc();
                    if(snodata==1)
                    {
                        colour(143);
                        cout<<"\n\nPRESS:";
                        colour(7);
                        cout<<"\n1: Edit\n2: Delete\n3: To deselect the data selected\n4: To select more data\nOR\n";
                        colour(143);
                        cout<<"TYPE:";
                        colour(7);
                        cout<<"\n\"exit\": To go to main menu\nYOUR CHOICE: ";
                        colour(78);
                        getline(cin,k);
                        colour(7);
                        if(k=="1")
                        {
                            string junkk,number,i,junkkk;
                            ifstream file6(path4);
                            getline(file6,junkkk,'\n');
                            getline(file6,i,',');
                            getline(file6,number,',');
                            getline(file6,junkk,'\n');
                            edit(number);
                            file6.close();
                        }
                        else if(k=="2")
                        {
                            string i,junkk,number;
                            ifstream file2(path4);  
                            while(!file2.eof())
                            {
                                getline(file2,i,',');
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
                            string i,junkk,number;
                            ifstream file9(path4);  
                            while(!file9.eof())
                            {
                                getline(file9,i,',');
                                getline(file9,number,',');
                                getline(file9,junkk,'\n');
                                del(number,path4);
                            }
                            colour(64);
                            cout<<"Deselected Successfully";
                            colour(7);
                            file9.close();
                        }
                        else if(k=="4")
                        select();
                        else if(stoupper(k)=="EXIT")
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
                        cout<<"\n1: Delete\n2: Deselect\n3: Exit\nYOUR CHOICE: ";
                        colour(78);
                        getline(cin,k);
                        colour(7);
                        if(k=="1")
                        {
                            string junkk,number,i;
                            ifstream file4(path4);
                            while(!file4.eof())
                            {
                                getline(file4,i,',');
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
                            annhh:
                            string pr,no,junk,deselno,k;
                            cout<<"Enter the sr. no. you want to deselect:\nOR\n";
                            colour(143);
                            cout<<"Type:";
                            colour(7);
                            cout<<"\"exit\": To go to main menu\n\"cancel\": To cancel deselecting\nYour Choice:  ";
                            colour(78);
                            getline(cin,pr);
                            colour(7);
                            if(stoupper(pr)=="EXIT");
                            if(stoupper(pr)!="CANCEL")
                            {
                                pr=valueofsr(pr,h);
                                if(pr=="-187928")
                                {
                                    system("cls");
                                    colour(64);
                                    cout<<"\nInvalid Sr. No.!";
                                    colour(7);
                                    Sleep(2000);
                                    colour(14);
                                    cout<<"\nEnter again:\n\n";
                                    colour(7);
                                    goto annhh;
                                }
                                deselno=returnnum(pr,path4);
                                string i,junkk,number;
                                ifstream file7(path4);  
                                while(!file7.eof())
                                {
                                    getline(file7,i,',');
                                    getline(file7,number,',');
                                    getline(file7,junkk,'\n');
                                    if(deselno==number)
                                    {
                                        del(number,path4);
                                        colour(64);
                                        cout<<"Deselected Successfully";
                                        colour(7);
                                    }
                                }
                                file7.close();
                                sort();
                                hatt:
                                cout<<"Do you want to deselect more contacts?";
                                colour(143);
                                cout<<"\n\nPRESS:";
                                colour(7);
                                cout<<"\n1: Yes\n2: No\nYOUR CHOICE: ";
                                colour(78);
                                getline(cin,k);
                                colour(7);
                                if(k=="1")
                                goto yoyo;
                                else if(k=="2")
                                {
                                }
                                else
                                {
                                    colour(4);
                                    cout<<"ERROR: Enter again!";
                                    colour(7);
                                    Sleep(2000);
                                    system("cls");
                                    goto hatt;
                                }
                            }
                            goto yoyo;
                        }
                        else if(k=="3");
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
                    nodataselkuppar:
                    system("cls");
                    colour(4);
                    cout<<"\n\nNO DATA SELECTED!\n\n";
                    Sleep(1000);
                    colour(143);
                    cout<<"PRESS:";
                    colour(7);
                    cout<<"\n1: TO SELECT DATA\nOR\n";
                    colour(143);
                    cout<<"TYPE:";
                    colour(7);
                    cout<<"\n\"exit\": TO GO TO MAIN MENU\n\nYOUR CHOICE:";
                    string choice;
                    colour(78);
                    getline(cin,choice);
                    colour(7);
                    if(choice=="1")
                    {
                        system("cls");
                        select();
                    }
                    else if(stoupper(choice)=="EXIT")
                    goto exiting;
                    else
                    {
                        colour(4);
                        cout<<"ERROR: Enter again!";
                        colour(7);
                        Sleep(2000);
                        system("cls");
                        goto nodataselkuppar;
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
            correction(path4);
            sort();
        }
    }
    else
    {
        exiting:
        colour(7);
    }
}
void settings()
{
    wapiss:
    system("cls");
    string choice;
    colour(159);
    cout<<"\n\n================================================== ";
    colour(144);
    cout<<"SETTINGS";
    colour(159);
    cout<<"=============================================================\n\n";
    colour(143);
    cout<<"PRESS:\n";
    colour(7);
    cout<<"1: Change PASSWORD\n2: Change USER ID\n3: Master delete(delete all data)\n4: Delete Phonebook account\n5: Logout\nOR\nTYPE:\n\"exit\": To return to main menu\n";
    colour(159);
    cout<<"\n=======================================================================================================================\n";
    colour(7);
    cout<<"YOUR CHOICE: ";
    colour(78);
    getline(cin,choice);
    colour(7);
    if(choice=="1")
    {
        change(1);
    }
    else if(choice=="2")
    {
        change(0);
    }
    else if(choice=="3")
    {
        masterdelete();
    }
    else if(choice=="4")
    {
        accdelete();
    }
    else if(choice=="5")
    {
        logout();
    }
    else if(stoupper(choice)=="EXIT")
    {
        cout<<'\a';
        system("cls");
    }
    else
    {
        goto wapiss;
    }
}
int checkpass(string pass)
{
    int i,special=0,number=0,chars=0,flag=0;
    for(i=0;pass[i];i++)
    {
        if(pass[i]!=',')
        {
            if(isalpha(pass[i])!=0)
            chars++;
            else if(isdigit(pass[i])!=0)
            number++;
            else
            special++;
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(i<8||flag==1||number<2||chars<2||special<1)
    {
        flag=1;
        return flag;
    }
    else if(i>=8&&i<12&&chars>2&&number>2&&special>1)
    cout<<"\n\n*WEAK PASSWORD*\n\n";
    else if(i>=12&&i<16&&chars>4&&number>3&&special>2)
    cout<<"\n\n*GOOD PASSWORD*\n\n";
    else if(i>=16&&i<24&&chars>6&&number>5&&special>2)
    cout<<"\n\n*STRONG PASSWORD*\n\n";
    else if(i>=24&&chars>12&&number>9&&special>8)
    cout<<"\n\n*VERY STRONG PASSWORD*\n\n";
    return flag; 
}
void logout()
{
    system("cls");
    colour(31);
    cout<<"\n\n\n\n\n\n\n\n\n==================================================";
    colour(16);
    cout<<" LOGGING OUT ";
    makeorremovefilename(1);
    colour(31);
    cout<<"==================================================";
    colour(7);
    loggedin=0;
    loginid="";
    Sleep(3000);
    system("cls");
}
void change(int q)
{
    
    if(loginfunc(1)==1)
    {
        if(q==0)
        {
            idgalath:
            system("cls");
            string junk;
            cout<<"\nTYPE:\n\"exit\":To go back to settings\nOR ENTER\nNEW USER ID: ";
            getline(cin,junk);
            if(stoupper(junk)!="EXIT")
            {
                if(checkid(junk)==1)
                {
                    cout<<"ERROR:  The USER ID entered by you was not accepted!\nThe user id:\n~SHOULD HAVE A MINIMUM OF 6 CHARACTERS\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
                    Sleep(1500);
                    goto idgalath;
                }
                else 
                {
                    string passcheck;
                    if(availofid(junk,passcheck)==1)
                    {
                        cout<<"SORRY:  The USER ID already exists!Please try a different selection!\nThe user id:\n~SHOULD HAVE A MINIMUM OF 6 CHARACTERS\n~SHOULD NOT CONTAIN ANY SPACES\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
                        Sleep(1500);
                        goto idgalath;
                    }
                }
                storemode(junk,1);
                loginid=junk;
                system("cls");
                cout<<"USER ID SUCCESSFULLY CHANGED!";
            }
        }
        else if(q==1)
        {
            unconfirmed:
            system("cls");
            string junk="",junk1="";
            cout<<"\nTYPE:\n\"exit\":To go back to settings\nOR ENTER\nNEW PASSWORD: ";
            getline(cin,junk);
            system("cls");
            if(stoupper(junk)!="EXIT")
            {
                if(checkpass(junk)==1)
                {
                    cout<<"ERROR:  The PASSWORD entered by you was not accepted!\nThe password:\n~SHOULD HAVE A MINIMUM OF 8 CHARACTERS\n~SHOULD CONTAIN ATLEAST 2 NUMBERS\n~SHOULD CONTAIN ATLEAST 2 ALPHABETS\n~SHOULD CONTAIN ATLEAST 1 SPECIAL CHARACTER\n~SHOULD NOT CONTAIN ANY SPACES\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
                    Sleep(2000);
                    system("cls");
                    goto unconfirmed;
                }
                cout<<"CONFIRM PASSWORD:  ";
                getline(cin,junk1);
                if(junk==junk1)
                {
                    storemode(junk,0);
                    junk=junk1="";
                    system("cls");
                    cout<<"USER ID SUCCESSFULLY CHANGED!";
                }
                else
                {
                    system("cls");
                    cout<<"PASSWORD CONFIRMATION DOES NOT MATCH!";
                    Sleep(1000);
                    system("cls");
                    cout<<"RE-ENTER";
                    Sleep(1000);
                    system("cls");
                    goto unconfirmed;
                }
            }
        }
    }
}
string returnpass()
{
    ifstream cpass(path6);
    string id,pass;
    int flag=0;
    while(!cpass.eof())
    {
        getline(cpass,id,',');
        getline(cpass,pass,'\n');
        if(loginid==id)
        {
            break;
        }
    }
    cpass.close();
    return pass;
}
void storemode(string shutup,int q)
{
    int part=0,ppart;
    string junk1="",junk2="",junk3="";
    ifstream editacc(path6);
    while(!editacc.eof())
    {
        ppart=part;
        string id,pass;
        getline(editacc,id,',');
        getline(editacc,pass,'\n');
        if(loginid==id)
        {
            if(q==0)
            junk2=id+','+shutup;
            else if(q==1)
            junk2=shutup+','+pass;
            part=1;
        }
        else if(part==0)
        {
            junk1=junk1+id+','+pass+'\n';
        }
        else if(part==1)
        {
            junk3=junk3+'\n'+id+','+pass;
        }
    }
    string junk=junk1+junk2+junk3;
    editacc.close();
    ofstream storeedit(path6);
    storeedit<<junk;
    storeedit.close();
}
int availofid(string enteredid,string &passcheck)
{
    int flag=0;
    ofstream op(path6,ios::app);
    op.close();
    ifstream avail(path6);
    while(!avail.eof())
    {
        string id,pass;
        getline(avail,id,',');
        getline(avail,pass,'\n');
        if(id==enteredid)
        {
            passcheck=pass;
            flag=1;
            break;
        }
    }
    return flag;
}
int checkid(string id)
{
    int i,flag=0;
    for(i=0;id[i]!='\0';i++)
    {
        if(id[i]==',')
        {
            flag=1;
            break;
        }
    }
    if(i<6||i>30)
    flag=1;
    return flag;
}
void masterdelete()
{
    if(loginfunc(1)==1)
    {
        int b1=remove(path1.c_str());
        int b2=remove(path2.c_str());
        createfile(path1);
        createfile(path2);
    }
}
void createfile(string filename)
{
    ofstream create(filename,ios::out);
    create.close();
}
void correctionaccd(string filename) //removes extra spaces in file
{
    ofstream checked0(filename,ios::app);
    checked0.close();
    ifstream correct0;
    correct0.open(filename.c_str());
    int ic1=0;
    string corrected0="",junk0="";
    while(!correct0.eof())
    {
        string junk1;
        getline(correct0,junk1,'\n');
        if(junk1!=""&&junk1!=","||junk1!="")
        {
            if(ic1==0)
            corrected0=junk1;
            else
            corrected0=corrected0+'\n'+junk1;
            ic1++;
        }
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
    int ic=0;
    string corrected="";
    while(!correct.eof())
    {
        string id,pass;
        getline(correct,id,',');
        getline(correct,pass,'\n');
        if(id!=""&&pass!="")
        {
            if(ic==0)
            corrected=corrected+id+','+pass;
            else
            corrected=corrected+'\n'+id+','+pass;
            ic++;
        }
    }
    correct.close();
    ofstream crcting;
    crcting.open(filename.c_str());
    crcting<<corrected;
    crcting.close();
}
void accdelete()
{
    if(loginfunc(1)==1)
    {
        string id="",pass="",junk="";
        int flag=0;
        ifstream accdelr(path6);
        getline(accdelr,id,',');
        getline(accdelr,pass,'\n');
        if(id==loginid);
        else
        junk=id+','+pass+'\n';
        id="";pass="";
        while(!accdelr.eof())
        {
            if(flag==1)
            junk=junk+'\n';
            getline(accdelr,id,',');
            getline(accdelr,pass,'\n');
            if(id!=loginid)
            {
                junk=junk+id+','+pass;
                flag=1;
            }
            else
            flag=0;
            pass="";id="";
        }
        accdelr.close();
        ofstream accdelw(path6,ios::out);
        accdelw<<junk;
        accdelw.close();
        correctionaccd(path6);
        int b1=remove(path1.c_str()),b2=remove(path2.c_str());
        logout();
    }
}
int loginfunc(int q) //verifies user id and pass(can also be used for login purpose)
{
    wronglogin:
    int successq1=0;
    string obtainpass="";
    system("cls");
    if(q==0)
    {
        loginid="";
        loginpass="";
        int flag1=0;
        cout<<"USER ID:  ";
        getline(cin,loginid);
    }
    int idavail=availofid(loginid,obtainpass);
    if(idavail==1)
    {
        wrongpass:
        loginpass="";
        if(q==1)
        {
            system("cls");
            cout<<"USER ID:  "<<loginid<<'\n';
            cout<<"CONFIRM ";
        }
        cout<<"PASSWORD:  ";
        getline(cin,loginpass);
        if(loginpass==obtainpass)
        {
            loginpass="";
            if(q==0)
            {
                loggedin=1;
                system("cls");
                Sleep(2000);
                Sleep(1000);
                cout<<"# CONGRATS!  YOU HAVE BEEN SUCCESSFULLY LOGGED IN TO "<<loginid<<" #";
                Sleep(2000);
                system("cls");
            }
            else
            successq1=1;
        }
        else
        {
            incorrectpass:
            system("cls");
            cout<<"USER ID:  "<<loginid<<"\nINCORRECT PASSWORD!\nPRESS:\n1: RE-ENTER PASSWORD";
            if(q==0)
            cout<<"\n2: RE-ENTER USER ID";
            cout<<"\nOR\nTYPE:\n\"exit\"";
            if(q==0)
            cout<<":TO EXIT PHONEBOOK";
            else if(q==1)
            cout<<":TO GO BACK TO SETTINGS";
            cout<<"\nYOUR CHOICE:  ";
            string choice;
            getline(cin,choice);
            if(choice=="1")
            {
                loginpass="";
                system("cls");
                cout<<"USER ID:  "<<loginid<<"\n";
                goto wrongpass;
            }
            else if(choice=="2"&&q==0)
            {
                loginid="";
                loginpass="";
                goto wronglogin;
            }
            else if(stoupper(choice)=="EXIT")
            {
                Sleep(500);
                loggedin=0;
                system("cls");
                Sleep(500);
            }
            else
            {
                system("cls");
                cout<<"USER ID: "<<loginid<<"\nERROR: Enter again!";
                Sleep(2000);
                system("cls");
                goto incorrectpass;
            }                    
        }
    }
    else
    {
        incorrectuserid:
        system("cls");
        cout<<"INCORRECT USER ID!\nPRESS:\n1: RE-ENTER USER ID\nOR\nTYPE:\n\"exit\"";
        if(q==0)
        cout<<":TO EXIT PHONEBOOK";
        else if(q==1)
        cout<<":TO GO BACK TO SETTINGS";
        cout<<"\nYOUR CHOICE:  ";
        string choice="";
        getline(cin,choice);
        if(choice=="1")
        {
            system("cls");
            goto wronglogin;
        }
        else if(stoupper(choice)=="EXIT")
        {
            Sleep(500);
            loggedin=0;
            system("cls");
            Sleep(500);
        }
        else
        {
            system("cls");
            cout<<"ERROR: Enter again!";
            Sleep(2000);
            system("cls");
            goto incorrectuserid;
        }
    }
    return successq1;
}
void codedstorage(int q,string &value)
{
    if(q==0)
    {
        int i=0;
        while(value[i]!='\0')
        {
            if(value[i]==',')
            value[i]='^';
            i++;
        }
    }
    if(q==1)
    {
        int i=0;
        while(value[i]!='\0')
        {
            if(value[i]=='^')
            value[i]=',';
            i++;
        }
    }
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
void openpathfile(string file) //opens a file in ofstream append mode
{
    ofstream open(file.c_str(),ios::app);
    open.close();
}
void codedstoragetot(int q,string &a,string &b,string &c,string &d,string &e,string &f,string &g,string &h)
{
    codedstorage(q,a);
    codedstorage(q,b);
    codedstorage(q,c);
    codedstorage(q,d);
    codedstorage(q,e);
    codedstorage(q,f);
    codedstorage(q,g);
    codedstorage(q,h);
}