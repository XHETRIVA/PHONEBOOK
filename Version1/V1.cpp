#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<Windows.h>
#include<sstream>
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"
#define BOLD "\e[1m"
#define UNBOLD "\e[0m"
using namespace std;
void makee();	 //Creates The Default Folders If Not Present
void cheatcode();	  //Allows User To Change The Default Path
void Option();    //Main Menu
void Colour(int c);    //Adds Colour
void Correction(string filename);    //Removes The Extra Spaces
int CheckUniNo(string num,string &pname,string filename,int q);    //Checks For Repeatation Of Phone Numbers
string StrRev(string str);    //Reverses A String
int CheckNo(string num);	//Checks If The Entered String Is A Number Or Not
string IntToStr(int x);		//Converts A Integer To String
void ShowData(string filename);		//Displays All Data Present In Phonebook
string SToUpper(string &s);		//Converts Lower Case String To Upper Case String
void Search(int &h,string sname,int q);		//Uses Any Contact Detail To Search For The Contact In The File
int CmpStr(string a,string b);		//Compares Two Strings
int CheckPhoneNo(string &num,string &name,int q);	  //Allows User To Enter A Phone Number
void ShowQa();	  //Displays All Contacts Present Under Quick Access
void AddQa();	  //Adds A Contact To Quick Access
void RemQa();	  //Removes A Contact To Quick Access
string ValueOfSr(string sr,int x);	  //Returns The Value Of The Serial Number
void Edit(string editno);	  //Allows User To Edit A Contact's Details
string ReturnNum(string sr,string filename);	//Returns The Phone Number Belonging To The Serial Number
int StrToInt(string a);		//Converts A String To Integer
void AddContacts();		//Allows User To Add A New Contact
void SCalc();	 //Calculates No. Of Lines, Datas Present In Selection File
void Calc();	 //Calculates No. Of Lines, Datas Present In The File
void Sort();	 //Sorts The Contacts In Acsending Order
void Welcome();		//Displays The Welcome Page
void Del(string pno,string filename);	  //Allows User To Delete A Contact
void Select();		//Allows User To Select Multiple Contacts
void Settings();	//Displays The Settings Page
int CheckPass(string pass);		//Checks The Validity Of The Password
void LogOut();		//Logs Out Of The Phonebook
void Change(int q);		//Allows User To Change The UserID And Password
string ReturnPass();	 //Returns The Password For The Correct UserID
void StoreMode(string shutup,int q);	//Stores The UserID And Password
int CheckID(string id);		//Checks The UserID
void MasterDelete();	//Deletes All Data Present In The Account
void CreateFilef(string filename);		//Opens A New File
void CorrectionAccData(string filename);	//Correction For Accounts File
void AccDelete();	 //Deletes An Account
int LoginFunc(int q);	 //Allows The User To LogIn To An Account
void CodedStorage(int q,string &value);     //Converts ',' <-> '^'
void MakeOrRemoveFileName(int q);     //Creates And Deletes A File
void OpenPathFile(string file);     //Opens A File In Append Mode And Creates A New File If Not Present
void CodedStorageTot(int q,string &a,string &b,string &c,string &d,string &e,string &f,string &g,string &h);    //CodedStorage Summation
void CreateAcc();    //Creates An Account
int CheckAcc();     //Checks
int AvailOfID(string enteredid);
void ResetSpace(string &word,int q);
void TotalReset(string &a,string &b,string &c,string &d,string &e,string &f,string &g,string &h,int q);
void NewFileNameAndRenameExistingFile();
int PresenceInSelect(string no);
int noline=0,nodata=0,alphaN=0,snoline=0,snodata=0,salphaN=0,nooftrials=0,loggedin=0;
string loginid,login;
struct contacts
{
    string name,number,email,ad,dob,doa,notes,rel,label,qa,temp;
};
string basepath="C:/PROJECTS DATA/PHONEBOOK FILES/PHONEBOOK",path1="",path2="",path3="C:/PROJECTS DATA/PHONEBOOK FILES/PHONEBOOK/TgQDjQFuvmVtGqdJqfUVMvTtTtVmvuFQjDQgTvMVUfqJdqGt.csv",path4="C:/PROJECTS DATA/PHONEBOOK FILES/PHONEBOOK/VCmDfrJMqeGQknRwdN.csv",path5="C:/PROJECTS DATA/PHONEBOOK FILES/PHONEBOOK/eMRGgb.csv",path6="C:/PROJECTS DATA/PHONEBOOK FILES/PHONEBOOK/rPpdXeYZyDSqzaQERPxyZedPySzQeAQd.txt";
int main()
{
    account:
    makee();
    Welcome();
    CorrectionAccData(path6);
    if(CheckAcc()==0)
    {
        system("cls");
        Colour(192);
        cout<<"\n\nSORRY! YOU HAVE NOT CREATED ANY ACCOUNT IN PHONEBOOK!";
        Colour(7);
        cout<<"\n\nSIGN UP TO CONTINUE\n";
        Colour(143);
        cout<<"PRESS:";
        Colour(7);
        cout<<"\n1:SIGN UP\nOR TYPE:\n\"exit\": To Exit Phonebook.\n\n";
        Colour(78);
        cout<<"ENTER HERE:";
        Colour(7);
        cout<<"  ";
        string choice;
        getline(cin,choice);
        if(choice=="{~c:h:e:a:t~~c:o:d:e~}")
        {
            cheatcode();
            goto account;
        }
        SToUpper(choice);
        if(choice=="1")
        {
            CreateAcc();
            Sleep(2000);
            system("cls");
            goto account;
        }
        else if(SToUpper(choice)=="EXIT")
        {
            int bx=remove(path6.c_str());
            system("cls");
        }
        else
        {
            system("cls");
            Colour(192);
            cout<<"\nERROR: Enter again!";
            Colour(7);
            Sleep(2000);
            system("cls");
            goto account;
        }
    }
    else
    {
        system("cls");
        Colour(143);
        cout<<"\n\nPRESS:";
        Colour(7);
        cout<<"\n1:LOGIN\n2:SIGN UP\nOR TYPE:\n\"exit\":To Exit Phonebook.\n\n";
        Colour(78);
        cout<<"ENTER HERE:";
        Colour(7);
        cout<<"  ";
        string choice;
        getline(cin,choice);
        if(choice=="{~c:h:e:a:t~~c:o:d:e~}")
        {
            cheatcode();
            goto account;
        }
        SToUpper(choice);
        if(choice=="1")
        {
           LoginFunc(0);
           if(loggedin==1)
           {
               MakeOrRemoveFileName(0);
               Option();
           }
           if(loggedin==0)
           goto account;
        }
        else if(choice=="2")
        {
            CreateAcc();
            goto account;
        }
        else if(SToUpper(choice)=="EXIT")
        {
            system("cls");
        }
        else
        {
            system("cls");
            Colour(192);
            cout<<"\nERROR: Enter again!";
            Colour(7);
            Sleep(2000);
            system("cls");
            goto account;
        }
    }
}
void Option()
{
    string x,y;
    Welcome();
    wapis:
    Colour(159);
    cout<<"USER ID:";
    Colour(9);
    cout<<"\t"<<loginid;
    Colour(7);
    cout<<"\n\n";
    ShowQa();
    Colour(159);
    cout<<"\n\n=====================================================";
    Colour(9);
    cout<<" MAIN MENU ";
    Colour(159);
    cout<<"=======================================================";
    Colour(7);
    cout<<"\n                                                                                                                     ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n";
    Colour(143);
    cout<<"PRESS:";
    Colour(7);
    cout<<"                                                                                                               ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n                                                                                                                     ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n1: All Contacts (Displays all contacts)                                                                              ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n2: Add A New Contact                                                                                                 ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n3: Delete A Contact                                                                                                  ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n4: Edit A Contact                                                                                                    ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n5: Add A Contact To Quick Access (The contacts you add here will appear first without having you to search for it)   ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n6: Remove From Quick Access                                                                                          ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n7: Dialpad(Search a contact with name, number, address, email etc.)                                                  ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n8: Select Multiple Contacts(To perform one operation on multiple contacts simultaneously)                            ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n9: Settings                                                                                                          ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n                                                                                                                     ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n";
    Colour(159);
    cout<<"=======================================================================================================================\n";
    Colour(78);
    cout<<"ENTER HERE:";
    Colour(7);
    cout<<"  ";
    getline(cin,x);
    SToUpper(x);
    system("cls");
    if(x=="1")
    {
        Sort();
        Colour(143);
        cout<<"ALL CONTACTS\n\n";
        Colour(7);
        ShowData(path1.c_str());
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    else if(x=="2")
    {
        AddContacts();
        system("pause");
        cout<<"\a";
        system("cls");
        goto wapis;
    }
    else if(x=="3")
    {
        Del("NULL",path2);
        system("pause");
        cout<<"\a";
        int b=remove(path3.c_str());
        system("cls");
        goto wapis;
    }
    else if(x=="4")
    {
        Edit("NULL");
        system("pause");
        cout<<"\a";
        int b=remove(path3.c_str());
        system("cls");
        goto wapis;
    }
    else if(x=="5")
    {
        AddQa();
        system("pause");
        cout<<"\a";
        int b=remove(path3.c_str());
        system("cls");
        goto wapis;
    }
    else if(x=="6")
    {
        RemQa();
        system("pause");
        cout<<"\a";
        int b=remove(path3.c_str());
        system("cls");
        goto wapis;
    }
    else if(x=="7")
    {
        int f=1;
        Search(f,"NULL",0);
        system("pause");
        cout<<"\a";
        int b=remove(path3.c_str());
        system("cls");
        goto wapis;
    }
    else if(x=="8")
    {
        Select();
        system("pause");
        int b1=remove(path4.c_str());
        cout<<"\a";
        int b2=remove(path3.c_str());
        system("cls");
        goto wapis;
    }
    else if(x=="9")
    {
        Settings();
        if(loggedin!=0)
        goto wapis;
    }
    else
    {
        Colour(192);
        cout<<"ERROR: Enter again!";
        Colour(7);
        Sleep(2000);
        system("cls");
        goto wapis;
    }
}
void Colour(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void Correction(string filename)
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
int CheckUniNo(string num,string &pname,string filename,int q)
{
    int flag;
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
        if(num==number)
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
string StrRev(string str)
{
    int j=str.size();
    string temp;
    for(int i=0,k=j-1;i<j;i++,k--)
    temp[k]=str[i];
    return temp;
}
int CheckNo(string num)
{
    int i,flag=0;
    for(i=0;num[i]!='\0';i++)
    {
        if(num[0]=='+'||isdigit(num[i]));
        else
        {
            flag=1;
            break;
        }
    }
    return flag;
}
string IntToStr(int x)
{
    stringstream ss;
    string s;
    ss<<x;
    ss>>s;
    return s;
}
void ShowData(string filename)
{
    ifstream csvi(filename.c_str());
    Colour(192);
    Calc();
    if (nodata==0)
    cout<<"No Contacts Present!\n";
    else if(filename==path4)
    {
        SCalc();
        if(snodata>0)
        {
            Colour(143);
            cout<<"\nSelected Contacts\n\n";
        }
    }
    Colour(7);
    string junk;
    getline(csvi,junk,'\n');
    while(!csvi.eof())
    {
        string pr,name, number, email, address, dob, doa, notes, relation,label,qa;
        if(filename==path4||filename==path3)
        getline(csvi,pr,',');
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
        CodedStorageTot(1,name,email,address,dob,doa,notes,relation,label);
        Colour(8);
        cout<<"\n\n";
        if(filename==path4||filename==path3)
        cout<<pr<<".";
        cout<<"NAME:";
        Colour(7);
        cout<<left<<" "<<name;
        Colour(8);
        cout<<"\nPHONE NUMBER:";
        Colour(7);
        cout<<" "<<number;
        Colour(8);
        cout<<"\nDATE OF BIRTH:";
        Colour(7);
        cout<<" "<<dob;
        Colour(8);
        cout<<"\nDATE OF ANNIVERSARY:";
        Colour(7);
        cout<<" "<<doa;
        Colour(8);
        cout<<"\nRELATION:";
        Colour(7);
        cout<<" "<<relation;
        Colour(8);
        cout<<"\nLABEL:";
        Colour(7);
        cout<<" "<<label;
        Colour(8);
        cout<<"\nNOTES:";
        Colour(7);
        cout<<" "<<notes;
        Colour(8);
        cout<<"\nEMAIL:";
        Colour(7);
        cout<<" "<<email;
        Colour(8);
        cout<<"\nADDRESS:";
        Colour(7);
        cout<<" "<<address<<"\n";
    }
    csvi.close();
    Colour(7);
}
string SToUpper(string &x)
{
    int i=0;
    string s;
    TotalReset(x,x,x,x,x,x,x,x,0);
    s=x;
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
void Search(int &h,string sname,int q)
{
    string junk;
    s:
    system("cls");
    Colour(143);
    cout<<"SEARCHING FOR A CONTACT";
    if(q==0)
    cout<<"--\n\n";
    else if(q==1)
    cout<<" TO EDIT--\n\n";
    else if(q==2)
    cout<<" TO DELETE--\n\n";
    else if(q==3)
    cout<<" TO ADD TO QUICK ACCESS--\n\n";
    else if(q==4)
    cout<<" TO SELECT--\n\n";
    else if(q==5)
    cout<<" TO REMOVE FROM QUICK ACCESS--\n\n";
    Colour(7);
    if(q==4)
    {
        SCalc();
        cout<<"Number Of Data Selected:  "<<snodata<<'\n';
        ShowData(path4);
    }
    if(sname=="NULL")
    {
        cout<<"Enter any contact detail of the contact you want to search:\nOR TYPE:\n\"exit\": To Go Back To Main Menu.";
        if(q==4)
        cout<<"\n\"cancel\": To Cancel Searching And Go Back To See At The Selected Contacts.";
        if(q!=0)
        cout<<"\n\"allcon\": To Choose From All Contacts.";
        Colour(78);
        cout<<"\n\nENTER HERE:";
        Colour(7);
        cout<<" ";
        getline(cin,sname);
        if(sname==""||sname=="-")
        sname="--KHAALIHBRO--";
        SToUpper(sname);
    }
    sname=SToUpper(sname);
    int x,y,f=0;
    x=sname.size();
    if(q==4&&sname=="CANCEL")
    {
        h=-187925;
        goto cancelq4;
    }
    if(sname!="EXIT")
    {
        ifstream search;
        ofstream searchr;
        search.open(path1);
        searchr.open(path3);
        if(sname!="--KHAALIHBRO--")
        {
            getline(search,junk,'\n');
            searchr<<"SR. NO.,PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
            while(!search.eof())
            {
                string name, number, email, address, dob, doa, notes, relation,label,qa,temp,temp1,temp2,temp3,temp4,temp5,temp6,temp7;
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
                CodedStorageTot(1,name,email,address,relation,doa,dob,label,notes);
                temp1=SToUpper(name);
                temp2=SToUpper(email);
                temp3=SToUpper(address);
                temp4=SToUpper(relation);
                temp5=SToUpper(doa);
                temp6=SToUpper(dob);
                temp7=SToUpper(label);
                if((q==3&&qa=="0")||(q==5&&qa=="1")||(q==4&&PresenceInSelect(number)==0)||(q!=3&&q!=4&&q!=5))
                {
                    CodedStorageTot(1,name,email,address,dob,doa,notes,relation,label);
                    int flag=0;
                    if(sname!="ALLCON")
                    {
                        if(CmpStr(sname,temp1)==1)
                        {
                            flag=1;
                            goto idharaa;
                        }
                        if(CmpStr(sname,temp2)==1)
                        {
                            flag=1;
                            goto idharaa;
                        }
                        if(CmpStr(sname,temp3)==1)
                        {
                            flag=1;
                            goto idharaa;
                        }
                        if(CmpStr(sname,temp4)==1)
                        {
                            flag=1;
                            goto idharaa;
                        }
                        if(CmpStr(sname,temp5)==1)
                        {
                            flag=1;
                            goto idharaa;
                        }
                        if(CmpStr(sname,temp6)==1)
                        {
                            flag=1;
                            goto idharaa;
                        }
                        if(CmpStr(sname,temp7)==1)
                        {
                            flag=1;
                            goto idharaa;
                        }
                        if(CmpStr(sname,number)==1)
                        {
                            flag=1;
                            goto idharaa;
                        }
                    }
                    else
                    flag=1;
                    idharaa:
                    if(flag==1)
                    {
                        CodedStorageTot(0,name,email,address,dob,doa,notes,relation,label);
                        searchr<<'\n'<<h<<","<<number<<","<<name<<","<<email<<","<<address<<","<<dob<<","<<doa<<','<<notes<<","<<relation<<","<<label<<","<<qa;
                        Colour(14);
                        CodedStorageTot(1,name,email,address,dob,doa,notes,relation,label);
                        Colour(8);
        	            cout<<"\n\n"<<h<<". NAME:";
                        Colour(7);
                        cout<<left<<" "<<name;
                        Colour(8);
                        cout<<"\nPHONE NUMBER:";
                        Colour(7);
                        cout<<" "<<number;
                        Colour(8);
                        cout<<"\nDATE OF BIRTH:";
                        Colour(7);
                        cout<<" "<<dob;
                        Colour(8);
                        cout<<"\nDATE OF ANNIVERSARY:";
                        Colour(7);
                        cout<<" "<<doa;
                        Colour(8);
                        cout<<"\nRELATION:";
                        Colour(7);
                        cout<<" "<<relation;
                        Colour(8);
                        cout<<"\nLABEL:";
                        Colour(7);
                        cout<<" "<<label;
                        Colour(8);
                        cout<<"\nNOTES:";
                        Colour(7);
                        cout<<" "<<notes;
                        Colour(8);
                        cout<<"\nEMAIL:";
                        Colour(7);
                        cout<<" "<<email;
                        Colour(8);
                        cout<<"\nADDRESS:";
                        Colour(7);
                        cout<<" "<<address<<"\n";
                        h++;
                        f=1;
                    }
                }
            }
        }
        if(f==0)
        {
            bahar:
            system("cls");
            Colour(192);
            cout<<"NO RESULTS FOUND";
            if(q==5)
            cout<<" IN QUICK ACCESS!\n\n";
            else if(q==3)
            cout<<" IN THE CONTACTS WHICH ARE NOT IN QUICK ACCESS!\n\n";
            else if(q==4)
            cout<<" IN THE UNSELECTED DATA!\n\n";
            else
            cout<<"!\n\n";
            Colour(7);
            h=1;
            if(q==1||q==2||q==3||q==4||q==5)
            {
                r:
                Sleep(3000);
                system("cls");
                sname="NULL";
                goto s;
            }
        }
        search.close();
        searchr.close();
        if(q==0)
        {
            int b=remove(path3.c_str());
            h=1;
            if(f!=0)
            {
                Sleep(5000);
                system("pause");
            }
            else
            {
            Sleep(3000);
            system("cls");
            }
            sname="NULL";
            goto s;
        }
    }
    else
    {
        cancelq4:
        system("cls");
        if(q!=4&&sname!="CANCEL")
        h=-187928;
        if(q==0)
        {
            Colour(192);
            cout<<"\nSEARCH TERMINATED\n";
        }
        Colour(7);
    }
}
int CmpStr(string a,string b)
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
void ShowQa()
{
    int data=0;
    Colour(143);
    cout<<"QUICK ACCESS--\n";
    Colour(7);
    ifstream yrr(path2.c_str());
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
            CodedStorageTot(1,name,email,ad,dob,doa,notes,rel,label);
            Colour(8);
            cout<<"\n\nNAME:";
            Colour(7);
            cout<<left<<" "<<name;
            Colour(8);
            cout<<"\nPHONE NUMBER:";
            Colour(7);
            cout<<" "<<number;
            Colour(8);
            cout<<"\nDATE OF BIRTH:";
            Colour(7);
            cout<<" "<<dob;
            Colour(8);
            cout<<"\nDATE OF ANNIVERSARY:";
            Colour(7);
            cout<<" "<<doa;
            Colour(8);
            cout<<"\nRELATION:";
            Colour(7);
            cout<<" "<<rel;
            Colour(8);
            cout<<"\nLABEL:";
            Colour(7);
            cout<<" "<<label;
            Colour(8);
            cout<<"\nNOTES:";
            Colour(7);
            cout<<" "<<notes;
            Colour(8);
            cout<<"\nEMAIL:";
            Colour(7);
            cout<<" "<<email;
            Colour(8);
            cout<<"\nADDRESS:";
            Colour(7);
            cout<<" "<<ad<<"\n";
            data++;
        }
    }
    Calc();
    if(nodata==0)
    {
        Colour(192);
        cout<<"\nOOPS! There are no contacts saved in your account!\n";
        Colour(7);
    }
    else if(data==0)
    {
        Colour(192);
        cout<<"\nOOPS! There are no contacts saved in quickaccess!\n";
        Colour(7);
    }
}
void AddQa()
{
    adqaaa:
    int x=1;
    Search(x,"NULL",3);
    if(x!=-187928)
    {
        adqaa:
        system("cls");
        Colour(143);
        cout<<"ADDING A CONTACT TO QUICK ACCESS--";
        Colour(7);
        ShowData(path3);
        string adqa,name,number,email,ad,dob,doa,notes,rel,label,qa,junk,qaf="";
        cout<<"Choose the serial number you want to add to quickaccess:\nOR TYPE:\n\"exit\": To Exit Adding To Quick Access.\n\"again\": To search again.\n";
        Colour(78);
        cout<<" ENTER HERE:";
        Colour(7);
        cout<<"  ";
        getline(cin,adqa);
        SToUpper(adqa);
        if(SToUpper(adqa)=="AGAIN")
        goto adqaaa;
        else if(SToUpper(adqa)!="EXIT")
        {
            string xstr=IntToStr(x);
            adqa=ValueOfSr(adqa,x);
            if(adqa!="-187928")
            {
                string editno=ReturnNum(adqa,path3);
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
                        Colour(192);
                        cout<<"\nAdded Successfully!\n";
                        Colour(7);
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
                Sort();
            }
            else
            {
                system("cls");
                Colour(192);
                cout<<"\nInvalid Sr. No.!";
                Colour(7);
                Sleep(2000);
                cout<<"\nEnter again:\n\n";
                system("cls");
                goto adqaa;
            }
        }
    }
}
void RemQa()
{
    remqaaa:
    int x=1;
    Search(x,"NULL",5);
    if(x!=-187928)
    {
        remqaa:
        system("cls");
        Colour(143);
        cout<<"REMOVING A CONTACT FROM QUICK ACCESS--";
        Colour(7);
        ShowData(path3);
        string remqa,name,number,email,ad,dob,doa,notes,rel,label,qa,junk,qaf="";
        cout<<"Choose the serial number you want to remove from quickaccess:\nOR Type:\n\"exit\": To Exit The Fuction.\n\"again\": To search again.\n";
        Colour(78);
        cout<<"ENTER HERE:";
        Colour(7);
        cout<<"  ";
        getline(cin,remqa);
        SToUpper(remqa);
        if(SToUpper(remqa)=="AGAIN")
        goto remqaaa;
        else if(SToUpper(remqa)!="EXIT")
        {
            string xstr=IntToStr(x);
            remqa=ValueOfSr(remqa,x);
            if(remqa=="-187928")
            {
                string editno=ReturnNum(remqa,path3);
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
                    Colour(192);
                    cout<<"Removed Successfully!\n";
                    Colour(7);
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
            Sort();
            }
            else
            {
                system("cls");
                Colour(192);
                cout<<"\nInvalid Sr. No.!";
                Colour(7);
                Sleep(2000);
                cout<<"\nEnter again:\n\n";
                system("cls");
                goto remqaa;
            }
        }
    }
}
string ValueOfSr(string sr,int x)
{
    int flag=0;
    for(int i=1;i<x;i++)
    {
        if(sr==IntToStr(i))
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
string ReturnNum(string sr,string filename)
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
int StrToInt(string a)
{
    int x=0;
    stringstream as(a);
    as>>x;
    return x;
}
void AddContacts() 
{
    Correction(path2);
    Sort();
    string name,no,email="-",ad="-",dob="-",doa="-",notes="-",rel="-",label="-",qa="0",l="1";
    if(CheckPhoneNo(no,name,0))
    {
        readd:
        system("cls");
        Colour(143);
        cout<<"ADDING A NEW CONTACT--";
        Colour(7);
        string xdata="";
        TotalReset(name,email,ad,dob,doa,notes,rel,label,1);
        Colour(8);
        cout<<"\n\nNAME:";
        Colour(7);
        cout<<left<<" "<<name;
        Colour(8);
        cout<<"\nPHONE NUMBER:";
        Colour(7);
        cout<<" "<<no;
        Colour(8);
        cout<<"\nDATE OF BIRTH:";
        Colour(7);
        cout<<" "<<dob;
        Colour(8);
        cout<<"\nDATE OF ANNIVERSARY:";
        Colour(7);
        cout<<" "<<doa;
        Colour(8);
        cout<<"\nRELATION:";
        Colour(7);
        cout<<" "<<rel;
        Colour(8);
        cout<<"\nLABEL:";
        Colour(7);
        cout<<" "<<label;
        Colour(8);
        cout<<"\nNOTES:";
        Colour(7);
        cout<<" "<<notes;
        Colour(8);
        cout<<"\nEMAIL:";
        Colour(7);
        cout<<" "<<email;
        Colour(8);
        cout<<"\nADDRESS:";
        Colour(7);
        cout<<" "<<ad<<"\n";
        Colour(143);
        cout<<"\n\nPRESS:";
        Colour(7);
        cout<<"\n1. Change Name\n2. Change Number\n3. Change Date Of Birth\n4. Change Date Of Anniversary\n5. Change Relation\n6. Change Label"<<"\n7. Change Notes\n8. Change Email\n9. Change Address\nOR TYPE:\n\"save\": To Save Contact.\n\"cancel\": To Go Back To Main Menu.\n\n";
        Colour(78);
        cout<<"ENTER HERE:";
        Colour(7);
        cout<<"  ";
        string choice="";
        getline(cin,choice);
        SToUpper(choice);
        system("cls");
        if(choice=="1")
        {
            Colour(143);
            cout<<"NAME:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<name<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            name=xdata;
            goto readd;
        }
        else if(choice=="2")
        {
            if(CheckPhoneNo(no,name,1))
            goto readd;
        }
        else if(choice=="3")
        {
            Colour(143);
            cout<<"DATE OF BIRTH:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<dob<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            dob=xdata;
            goto readd;
        }
        else if(choice=="4")
        {
            Colour(143);
            cout<<"DATE OF ANNIVERSARY:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<doa<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            doa=xdata;
            goto readd;
        }
        else if(choice=="5")
        {
            Colour(143);
            cout<<"RELATION:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<rel<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            rel=xdata;
            goto readd;
        }
        else if(choice=="6")
        {
            Colour(143);
            cout<<"LABEL:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<label<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            label=xdata;
            goto readd;
        }
        else if(choice=="7")
        {
            Colour(143);
            cout<<"NOTES:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<notes<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            notes=xdata;
            goto readd;
        }
        else if(choice=="8")
        {
            Colour(143);
            cout<<"EMAIL:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<email<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            email=xdata;
            goto readd;
        }
        else if(choice=="9")
        {
            Colour(143);
            cout<<"ADDRESS:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<ad<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            ad=xdata;
            goto readd;
        }
        else if(SToUpper(choice)=="SAVE")
        {
            TotalReset(name,email,ad,dob,doa,notes,rel,label,1);
            CodedStorageTot(0,name,email,ad,dob,doa,notes,rel,label);
            ofstream file(path2.c_str(),ios::app);
            if(noline>0&&alphaN==0)
            file<<"PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
            file<<'\n'<<no<<","<<name<<","<<email<<","<<ad<<","<<dob<<","<<doa<<','<<notes<<","<<rel<<","<<label<<","<<qa;
            file.close();
            Correction(path2);
            Sort();
            system("cls");
            CodedStorageTot(1,name,email,ad,dob,doa,notes,rel,label);
            Colour(8);
            cout<<"\n\nNAME:";
            Colour(7);
            cout<<left<<" "<<name;
            Colour(8);
            cout<<"\nPHONE NUMBER:";
            Colour(7);
            cout<<" "<<no;
            Colour(8);
            cout<<"\nDATE OF BIRTH:";
            Colour(7);
            cout<<" "<<dob;
            Colour(8);
            cout<<"\nDATE OF ANNIVERSARY:";
            Colour(7);
            cout<<" "<<doa;
            Colour(8);
            cout<<"\nRELATION:";
            Colour(7);
            cout<<" "<<rel;
            Colour(8);
            cout<<"\nLABEL:";
            Colour(7);
            cout<<" "<<label;
            Colour(8);
            cout<<"\nNOTES:";
            Colour(7);
            cout<<" "<<notes;
            Colour(8);
            cout<<"\nEMAIL:";
            Colour(7);
            cout<<" "<<email;
            Colour(8);
            cout<<"\nADDRESS:";
            Colour(7);
            cout<<" "<<ad<<"\n";
        }
        else if(SToUpper(choice)=="CANCEL");
        else
        {
            Colour(192);
            cout<<"ERROR: Enter again!";
            Colour(7);
            Sleep(2000);
            system("cls");
            goto readd;
        }
    }
}
void SCalc()
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
        if(cd[0]=='S')
        salphaN=1;
        snoline++;
    }
    cal.close();
}
void Calc()
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
void Sort()
{
    Calc();
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
        CodedStorage(1,obj[i].name);
        i++;
    }
    for(i=0;i<nodata-1;i++)
    {
        for(j=0;j<nodata-i-1;j++)
        if(SToUpper(obj[j].name)>SToUpper(obj[j+1].name))
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
        CodedStorage(0,obj[i].name);
        fil<<'\n'<<obj[i].number<<','<<obj[i].name<<','<<obj[i].email<<','<<obj[i].ad<<','<<obj[i].dob<<','<<obj[i].doa<<','<<obj[i].notes<<','<<obj[i].rel<<','<<obj[i].label<<','<<obj[i].qa;
    }
    fil.close();
}
void Welcome()
{
    Colour(7);
    system("cls");
    Colour(8);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n                    P P P P P  H       H  O O O O O  N       N  E E E E E  B B B B    O O O O O  O O O O O  K     K\n";
    Sleep(150);
    cout<<"                    P       P  H       H  O       O  N N     N  E          B       B  O       O  O       O  K    K\n";
    Sleep(150);
    cout<<"                    P       P  H       H  O       O  N  N    N  E          B      B   O       O  O       O  K   K\n";
    Sleep(150);
    cout<<"                    P P P P P  H H H H H  O       O  N   N   N  E E E      B B B B    O       O  O       O  K K\n";
    Colour(12);
    Sleep(150);
    cout<<"                    P          H       H  O       O  N    N  N  E          B      B   O       O  O       O  K   K\n";
    Sleep(150);
    cout<<"                    P          H       H  O       O  N     N N  E          B       B  O       O  O       O  K    K\n";
    Sleep(150);
    cout<<"                    P          H       H  O O O O O  N       N  E E E E E  B B B B    O O O O O  O O O O O  K      K\n";
    Colour(7);
    Sleep(2000);
    cout<<"\a";
    system("cls");
}
void Del(string pno,string filename)
{
    Correction(path2);
    Correction(path1);
    Correction(path4);
    Sort();
    int success=0;
    string sr,y;
    if(pno=="NULL")
    {
        yahan:
        int x=1;
        Colour(143);
        cout<<"DELEING A CONTACT--";
        Colour(7);
        Search(x,"NULL",2);
        if(x!=-187928)
        {
            delpo:
            system("cls");
            Colour(143);
            cout<<"DELEING A CONTACT--";
            Colour(7);
            ShowData(path3);
            cout<<"\n\nChoose the serial number you want to select?\nOR TYPE:\n\"exit\": To Exit Selecting.\n\"again\": To Search Again.\n\n";
            Colour(78);
            cout<<"ENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,y);
            SToUpper(y);
            if(SToUpper(y)=="EXIT")
            {
                goto nikal;
            }
            else if(SToUpper(y)=="AGAIN")
            {
                system("cls");
                goto yahan;
            }
            else
            {
                y=ValueOfSr(y,x);
                if(y=="-187928")
                {
                    system("cls");
                    Colour(192);
                    cout<<"\nInvalid Sr. No.!";
                    Colour(7);
                    Sleep(2000);
                    cout<<"\nEnter again:\n\n";
                    system("cls");
                    goto delpo;
                }
                else
                {
                    sr=y;
                    pno=ReturnNum(sr,path3);
                    success=1;
                }
            }
        }
        else
        {
            nikal:
            Colour(7);
        }
    }
    else
    success=1;
    if(success==1)
    {
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
            Sort();
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
            Sort();
        }
    }
}
void Edit(string editno)
{    
    Sort();
    int success=0;
    string sr="",temp1="",temp2="",temp3="",fname="",fno="",fad="-",fem="-",temp="-",fdoa="-",fdob="-",fnote="-",frel="-",flabel="-",fqa="-",z,y;
    if(editno=="NULL")
    {
        ru:
        system("cls");
        Sort();
        int x=1;
        if(editno=="NULL")
        Search(x,"NULL",1);
        e1:
        if(x!=-187928)
        {
            editru:
            system("cls");
            Colour(143);
            cout<<"EDITING A CONTACT--";
            Colour(7);
            ShowData(path3);
            cout<<"\n\nChoose the serial number you want to edit?\nOR TYPE:\n\"again\": To Search Again.\n\"exit\": To Exit Editing.\n\n";
            Colour(78);
            cout<<"ENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,y);
            SToUpper(y);
            if(SToUpper(y)=="AGAIN")
            goto ru;
            else if(SToUpper(y)=="EXIT");
            else
            {
                y=ValueOfSr(y,x);
                if(y=="-187928")
                {
                    system("cls");
                    Colour(192);
                    cout<<"\nInvalid Sr. No.!";
                    Colour(7);
                    Sleep(2000);
                    cout<<"\nEnter again:\n\n";
                    system("cls");
                    goto editru;
                }
                else
                {
                    sr=y;
                    editno=ReturnNum(sr,path3);
                    success=1;
                }
            }
        }
        else
        {
            Colour(192);
            cout<<"\n\nEDITING TERMINATED!\n\n";
            Colour(7);
        }
    }
    else
    success=1;
    if(success==1)
    {
        ifstream editin(path2);
        int d=0,saveversion=0;
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
                CodedStorageTot(1,fname,fem,fad,fdob,fdoa,fnote,frel,flabel);
            }
            else if(d==0)
            temp1=temp1+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+qa+'\n';
            else if(d==1)
            temp3=temp3+'\n'+number+','+name+','+email+','+ad+','+dob+','+doa+','+notes+','+rel+','+label+','+qa;
        }
        e:
        system("cls");
        string xdata="";
        Colour(8);
        cout<<"\n\nNAME:";
        Colour(7);
        cout<<left<<" "<<fname;
        Colour(8);
        cout<<"\nPHONE NUMBER:";
        Colour(7);
        cout<<" "<<fno;
        Colour(8);
        cout<<"\nDATE OF BIRTH:";
        Colour(7);
        cout<<" "<<fdob;
        Colour(8);
        cout<<"\nDATE OF ANNIVERSARY:";
        Colour(7);
        cout<<" "<<fdoa;
        Colour(8);
        cout<<"\nRELATION:";
        Colour(7);
        cout<<" "<<frel;
        Colour(8);
        cout<<"\nLABEL:";
        Colour(7);
        cout<<" "<<flabel;
        Colour(8);
        cout<<"\nNOTES:";
        Colour(7);
        cout<<" "<<fnote;
        Colour(8);
        cout<<"\nEMAIL:";
        Colour(7);
        cout<<" "<<fem;
        Colour(8);
        cout<<"\nADDRESS:";
        Colour(7);
        cout<<" "<<fad;
        cout<<"\n";
        Colour(143);
        cout<<"\n\nPRESS:";
        Colour(7);
        cout<<"\n1. Change Name\n2. Change Number\n3. Change Date Of Birth\n4. Change Date Of Anniversary\n5. Change Relation\n6. Change Label\n7. Change Notes\n8. Change Email\n9. Change Address\nOR TYPE:\n\"save\": To Save The Current Data.\n\"cancel\": To Go Back To Main Menu Without Saving Changes.\n\"store\": To Save The Current Data And Return To Main Menu.\n\n";
        Colour(78);
        cout<<"ENTER HERE:";
        Colour(7);
        cout<<"  ";
        getline(cin,z);
        SToUpper(z);
        system("cls");
        if(z=="1")
        {
            Colour(143);
            cout<<"NAME:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<fname<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            fname=xdata;
            goto e;
        }
        else if(z=="2")
        {
            if(CheckPhoneNo(fno,fname,1))
            goto e;
        }
        else if(z=="3")
        {
            Colour(143);
            cout<<"DATE OF BIRTH:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<fdob<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            fdob=xdata;
            goto e;
        }
        else if(z=="4")
        {
            Colour(143);
            cout<<"DATE OF ANNIVERSARY:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<fdoa<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            fdoa=xdata;
            goto e;
        }
        else if(z=="5")
        {
            Colour(143);
            cout<<"RELATION:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<frel<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            frel=xdata;
            goto e;
        }
        else if(z=="6")
        {
            Colour(143);
            cout<<"LABEL:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<flabel<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            flabel=xdata;
            goto e;
        }
        else if(z=="7")
        {
            Colour(143);
            cout<<"NOTES:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<fnote<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            fnote=xdata;
            goto e;
        }
        else if(z=="8")
        {
            Colour(143);
            cout<<"EMAIL:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<fem<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            fem=xdata;
            goto e;
        }
        else if(z=="9")
        {
            Colour(143);
            cout<<"ADDRESS:";
            Colour(7);
            cout<<"\n\nOLD DATA: "<<fad<<"\n\nTYPE\n\"back\": To Continue With The Old Data Or Enter The New Data.";
            Colour(78);
            cout<<"\n\nENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,xdata);
            if(SToUpper(xdata)!="BACK")
            fad=xdata;
            goto e;
        }
        else if(SToUpper(z)=="CANCEL")
        saveversion=0;
        else if(SToUpper(z)=="SAVE")
        saveversion=1;
        else if(SToUpper(z)=="STORE")
        saveversion=2;
        else
        {
            Colour(192);
            cout<<"ERROR: Enter again!";
            Colour(7);
            Sleep(2000);
            system("cls");
            goto e;
        }
        if(saveversion!=0)
        {
            TotalReset(fname,fem,fad,fdob,fdoa,fnote,frel,flabel,1);
            CodedStorageTot(0,fname,fem,fad,fdob,fdoa,fnote,frel,flabel);
            temp2=fno+','+fname+','+fem+','+fad+','+fdob+','+fdoa+','+fnote+','+frel+','+flabel+','+fqa;
            temp=temp1+temp2+temp3;
            ofstream edited(path2);
            edited<<temp;
            Colour(192);
            cout<<"\nEdited Successfully!\n";
            Colour(7);
            Sleep(2000);
            edited.close();
            Sort();
            int g=remove(path3.c_str());
            system("cls");
            Colour(192);
            cout<<"THE DATA HAS BEEN SAVED SUCCESSFULLY!";
            Colour(7);
            Sleep(1500);
            if(saveversion==1)
            {
                temp2="";
                CodedStorageTot(1,fname,fem,fad,fdob,fdoa,fnote,frel,flabel);
                goto e;
            }
            Colour(7);
        }
    }
}
void Select()
{
    SelectKrPhirse:
    Correction(path2);
    Correction(path1);
    Correction(path4);
    Sort();
    string name,k,no,email,ad,dob,doa,notes,rel,label,qa,l="1",seleno,sr,y,z,junk;
    int h=1;
    ofstream file(path4.c_str(),ios::app);
    SCalc();
    if(snoline>0&&salphaN==0)
    file<<"SR. NO.,PHONE NO.,NAME,E-MAIL,ADDRESS,D.O.B.,D.O.A.,NOTES,RELATION,LABEL,QA";
    file.close();
    again:
    int x=1,c=1;
    Search(x,"NULL",4);
    if(x!=-187928&&x!=1)
    {
        enteragain:
        if(x!=-187925)
        {
            system("cls");
            Colour(143);
            cout<<"SELECTING A CONTACT--";
            Colour(7);
            ShowData(path3);
            cout<<"\n\nChoose the serial number you want to select?\nOR TYPE:\n\"exit\": To Exit Selecting And Go To Main Menu.\n\"cancel\": To Exit Selecting And Show The Selected Contacts.\n\"again\": To Search Again.\n\n";
            Colour(78);
            cout<<"ENTER HERE:";
            Colour(7);
            cout<<"  ";
            getline(cin,y);
        }
        else
        y="CANCEL";
        if(SToUpper(y)=="EXIT");
        else if(SToUpper(y)=="AGAIN")
        {
            system("cls");
            goto again;
        }
        else if(SToUpper(y)!="EXIT"&&SToUpper(y)!="AGAIN")
        {
            if(SToUpper(y)!="CANCEL")
            {
                y=ValueOfSr(y,x);
                if(y=="-187928")
                {
                    system("cls");
                    Colour(192);
                    cout<<"\nInvalid Sr. No.!";
                    Colour(7);
                    Sleep(2000);
                    cout<<"\nEnter again:\n\n";
                    system("cls");
                    goto enteragain;
                }
                else
                {
                    sr=y;
                    SCalc();
                    seleno=ReturnNum(sr,path3);
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
                            sel<<'\n'<<snodata+1<<','<<number<<","<<name<<","<<email<<","<<ad<<","<<dob<<","<<doa<<','<<notes<<","<<rel<<","<<label<<","<<qa;
                            h++;
                            Colour(192);
                            cout<<"\nSelected Successfully!\n";
                            Colour(7);
                        }
                    }
                    sel.close();
                    selec.close();            
                }
            }
            qwertyuiop:
            SCalc();
            if(snodata!=0)
            {
                yoyo:
                system("cls");
                ShowData(path4);
                SCalc();
                if(snodata>0)
                {
                    Colour(143);
                    cout<<"\n\nPRESS:";
                    Colour(7);
                    cout<<"\n1: To select more data\n2: To deselect any of the selected contacts\n3: Delete";
                    if(snodata==1)
                    cout<<"\n4: Edit";
                    cout<<"\nOR TYPE:\n\"exit\": To Go To Main Menu.\n";
                    Colour(78);
                    cout<<"ENTER HERE:";
                    Colour(7);
                    cout<<"  ";
                    getline(cin,k);
                    if(k=="1")
                    Select();
                    else if(k=="2")
                    {
                        string pr="";
                        if(snodata==1)
                        {
                            string i,junkk,number;
                            ifstream file9(path4);  
                            while(!file9.eof())
                            {
                                getline(file9,i,',');
                                getline(file9,number,',');
                                getline(file9,junkk,'\n');
                                Del(number,path4);
                            }
                            Colour(192);
                            cout<<"Deselected Successfully!";
                            Colour(7);
                            file9.close();
                            SCalc();
                        }
                        else
                        {
                            annhh:
                            system("cls");
                            ShowData(path4);
                            string no,junk,deselno,k;
                            cout<<"Choose the serial number you want to deselect:\nOR TYPE:\n\"exit\": To Go To Main Menu.\n\"cancel\": To Cancel Deselecting.\n";
                            Colour(78);
                            cout<<"ENTER HERE:";
                            Colour(7);
                            cout<<"  ";
                            getline(cin,pr);
                            if(SToUpper(pr)=="EXIT");
                            else if(SToUpper(pr)!="CANCEL")
                            {
                                SCalc();
                                h=snodata+1;
                                pr=ValueOfSr(pr,h);
                                if(pr=="-187928")
                                {
                                    system("cls");
                                    Colour(192);
                                    cout<<"\nInvalid Sr. No.!";
                                    Colour(7);
                                    Sleep(2000);
                                    cout<<"\nEnter again:";
                                    system("cls");
                                    goto annhh;
                                }
                                deselno=ReturnNum(pr,path4);
                                string i,junkk,number;
                                ifstream file7(path4);  
                                while(!file7.eof())
                                {
                                    getline(file7,i,',');
                                    getline(file7,number,',');
                                    getline(file7,junkk,'\n');
                                    if(deselno==number)
                                    {
                                        Del(number,path4);
                                        Colour(192);
                                        cout<<"Deselected Successfully!";
                                        Colour(7);
                                    }
                                }
                                file7.close();
                                Sort();
                            }
                        }
                        if(SToUpper(pr)!="EXIT")
                        goto qwertyuiop;
                    }
                    else if(k=="3")
                    {
                        string i,junkk,number;
                        ifstream file2(path4);  
                        while(!file2.eof())
                        {
                            getline(file2,i,',');
                            getline(file2,number,',');
                            getline(file2,junkk,'\n');
                            Del(number,path2);
                        }
                        Colour(192);
                        cout<<"Deleted Successfully!";
                        Colour(7);
                        file2.close();
                        CreateFilef(path4);//
                        goto qwertyuiop;//
                    }
                    else if(k=="4"&&snodata==1)
                    {
                        string junkk,number,i,junkkk;
                        ifstream file6(path4);
                        getline(file6,junkkk,'\n');
                        getline(file6,i,',');
                        getline(file6,number,',');
                        getline(file6,junkk,'\n');
                        Edit(number);
                        file6.close();
                        CreateFilef(path4);//
                        goto qwertyuiop;//
                    }
                    else if(SToUpper(k)=="EXIT");
                    else
                    {
                        Colour(192);
                        cout<<"ERROR: Enter again!";
                        Colour(7);
                        Sleep(2000);
                        system("cls");
                        goto yoyo;
                    }
                }
            }
            else
            {
                nodataselkuppar:
                system("cls");
                Colour(192);
                cout<<"\n\nNO DATA SELECTED!\n\n";
                Sleep(1000);
                Colour(143);
                cout<<"PRESS:";
                Colour(7);
                cout<<"\n1: TO SELECT DATA\nOR TYPE:\n\"exit\": To Go To Main Menu.\n\n";
                Colour(78);
                cout<<"ENTER HERE:";
                Colour(7);
                cout<<"  ";
                string choice;
                getline(cin,choice);
                if(choice=="1")
                {
                    system("cls");
                    Select();
                }
                else if(SToUpper(choice)=="EXIT");
                else
                {
                    Colour(192);
                    cout<<"ERROR: Enter again!";
                    Colour(7);
                    Sleep(2000);
                    system("cls");
                    goto nodataselkuppar;
                }
            }
            Sort();
        }
    }
    else
    {
        exiting:
        Colour(7);
    }
}
void Settings()
{
    wapiss:
    system("cls");
    Colour(159);
    cout<<"USER ID:";
    Colour(9);
    cout<<"\t"<<loginid;
    Colour(7);
    cout<<"\n\n";
    string choice;
    Colour(159);
    cout<<"\n\n========================================================";
    Colour(9);
    cout<<" SETTINGS ";
    Colour(159);
    cout<<"========================================================";
    Colour(7);
    cout<<"\n                                                                                                                        ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n";
    Colour(143);
    cout<<"PRESS:";
    Colour(7);
    cout<<"                                                                                                                  ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n                                                                                                                        ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n1: Change PASSWORD                                                                                                      ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n2: Change USER ID                                                                                                       ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n3: Master delete(delete all data)                                                                                       ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n4: Delete Phonebook account                                                                                             ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n5: Logout                                                                                                               ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\nOR TYPE:                                                                                                                ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n\"exit\": To Return To Main Menu.                                                                                         ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n                                                                                                                        ";
    Colour(159);
    cout<<"||";
    Colour(7);
    cout<<"\n";
    Colour(159);
    cout<<"==========================================================================================================================\n";
    Colour(78);
    cout<<"ENTER HERE:";
    Colour(7);
    cout<<"  ";
    getline(cin,choice);
    SToUpper(choice);
    if(choice=="1")
    {
        Change(1);
    }
    else if(choice=="2")
    {
        Change(0);
    }
    else if(choice=="3")
    {
        MasterDelete();
    }
    else if(choice=="4")
    {
        AccDelete();
    }
    else if(choice=="5")
    {
        LogOut();
    }
    else if(SToUpper(choice)=="EXIT")
    {
        cout<<'\a';
        system("cls");
    }
    else
    {
        goto wapiss;
    }
}
int CheckPass(string pass)
{
    Colour(192);
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
    Colour(7);
}
void LogOut()
{
    system("cls");
    Colour(159);
    cout<<"\n\n\n\n\n\n\n\n\n==================================================";
    Colour(9);
    cout<<" LOGGING OUT ";
    Colour(159);
    cout<<"==================================================";
    Colour(7);
    MakeOrRemoveFileName(1);
    loggedin=0;
    loginid="";
    Sleep(3000);
    system("cls");
}
void Change(int q)
{
    if(q==0&&LoginFunc(2)==1||q==1&&LoginFunc(1)==1)
    {
        if(q==0)
        {
            idgalath:
            system("cls");
            string junk;
            cout<<"\nTYPE:\n\"exit\": To Go Back To Settings.\nOR ENTER\n";
            Colour(78);
            cout<<"NEW USER ID:";
            Colour(7);
            cout<<"  ";
            getline(cin,junk);
            string junk2=junk;
            SToUpper(junk2);
            if(SToUpper(junk2)!="EXIT")
            {
                if(CheckID(junk)==1)
                {
                    Colour(192);
                    cout<<"ERROR: The USER ID entered by you was not accepted!\nThe user id:\n~SHOULD HAVE A MINIMUM OF 6 CHARACTERS\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
                    Colour(7);
                    Sleep(1500);
                    goto idgalath;
                }
                else 
                {
                    if(AvailOfID(junk))
                    {
                        Colour(192);
                        cout<<"SORRY: The USER ID already exists! Please try a different selection!";
                        Colour(7);
                        Sleep(1500);
                        goto idgalath;
                    }
                    else
                    {
                        StoreMode(junk,1);
                        loginid=junk;
                        NewFileNameAndRenameExistingFile();
                        system("cls");
                        Colour(192);
                        Sleep(1000);
                        cout<<"USER ID SUCCESSFULLY CHANGED!\n";
                        Sleep(1500);
                        system("cls");
                        Colour(7);
                    }
                }
            }
        }
        else if(q==1)
        {
            unconfirmed:
            system("cls");
            string junk="",junk1="";
            cout<<"\nTYPE:\n\"exit\": To Go Back To Settings.\nOR ENTER\n";
            Colour(78);
            cout<<"NEW PASSWORD:";
            Colour(7);
            cout<<"  ";
            getline(cin,junk);
            string junk2=junk;
            SToUpper(junk2);
            system("cls");
            if(SToUpper(junk2)!="EXIT")
            {
                if(CheckPass(junk)==1)
                {
                    cout<<"ERROR: The PASSWORD entered by you was not accepted!\nThe password:\n~SHOULD HAVE A MINIMUM OF 8 CHARACTERS\n~SHOULD CONTAIN ATLEAST 2 NUMBERS\n~SHOULD CONTAIN ATLEAST 2 ALPHABETS\n~SHOULD CONTAIN ATLEAST 1 SPECIAL CHARACTER\n~SHOULD NOT CONTAIN ANY SPACES\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
                    Sleep(2000);
                    system("cls");
                    goto unconfirmed;
                }
                Colour(78);
                cout<<"CONFIRM PASSWORD:";
                Colour(7);
                cout<<"  ";
                getline(cin,junk1);
                if(junk==junk1)
                {
                    StoreMode(junk,0);
                    junk=junk1="";
                    system("cls");
                    Colour(78);
                    Sleep(1000);
                    cout<<"PASSWORD SUCCESSFULLY CHANGED!";
                    Sleep(1500);
                    system("cls");
                    Colour(7);
                }
                else
                {
                    system("cls");
                    Colour(78);
                    cout<<"PASSWORD CONFIRMATION DOES NOT MATCH!";
                    Colour(7);
                    Sleep(1000);
                    cout<<"\nRE-ENTER";
                    Sleep(1000);
                    system("cls");
                    goto unconfirmed;
                }
            }
        }
    }
}
string ReturnPass()
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
void StoreMode(string shutup,int q)
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
int CheckID(string id)
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
void MasterDelete()
{
    int condit=LoginFunc(3);
    if(condit==1)
    {
        int b1=remove(path1.c_str());
        int b2=remove(path2.c_str());
        CreateFilef(path1);
        CreateFilef(path2);
    }
    else if(condit==2)
    {
        system("cls");
        Colour(192);
        cout<<"DATA DELETION HAS BEEN TERMINATED!";
        Colour(7);
        system("cls");
    }
    Sleep(1000);
    system("cls");
    Sleep(1000);
}
void CreateFilef(string filename)
{
    ofstream create(filename,ios::out);
    create.close();
}
void CorrectionAccData(string filename)
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
void AccDelete()
{
    int condit=LoginFunc(4);
    if(condit==1)
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
        CorrectionAccData(path6);
        int b1=remove(path1.c_str()),b2=remove(path2.c_str());
        LogOut();
    }
    else if(condit==2)
    {
        system("cls");
        Colour(192);
        cout<<"ACCOUNT DELETION HAS BEEN TERMINATED!";
        Colour(7);
        system("cls");
    }
}
int LoginFunc(int q)
{
    string xloginid="";
    wronglogin:
    int successq1=0;
    system("cls");
    if(q==0)
    {
        loginid="";
        int flag1=0;
        cout<<"\nTYPE:\n\"exit\": To Go Back To Settings.\nOR ENTER\n";
        Colour(78);
        cout<<"USER ID:";
        Colour(7);
        cout<<"  ";
        getline(cin,loginid);
        xloginid=loginid;
        SToUpper(xloginid);
    }
    exitfrompass:
    if(SToUpper(xloginid)!="EXIT")
    {
        if(AvailOfID(loginid))
        {
            wrongpass:
            string xlp="",loginpass="";
            if(q!=0)
            {
                system("cls");
                Colour(143);
                cout<<"VERIFY YOUR PASSWORD ";
                if(q==1)
                cout<<"TO GAIN ACCESS TO CHANGE PASSWORD";
                else if(q==2)
                cout<<"TO GAIN ACCESS TO CHANGE USER ID";
                else if(q==3)
                cout<<"TO GAIN ACCESS TO DELETE ALL DATA IN YOUR ACCOUNT";
                else if(q==4)
                cout<<"TO GAIN ACCESS TO PERMANENTLY DELETE YOUR ACCOUNT( YOU WILL LOSE ALL YOUR DATA PRESENT )";
                cout<<"--\n\n";
                Colour(7);
                cout<<"\nTYPE:\n\"exit\": To Go Back To Settings.\n\n";
                cout<<"USER ID:  "<<loginid<<'\n';
                Colour(78);
                cout<<"CONFIRM ";
            }
            else
            {
                system("cls");
                cout<<"\nTYPE:\n\"exit\": To Go Back To Settings.\n\"back\": To Re-Enter USER ID.\nOR ENTER PASSWORD--\n\n";
                cout<<"USER ID:  "<<loginid<<'\n';
            }
            Colour(78);
            cout<<"PASSWORD:";
            Colour(7);
            cout<<"  ";
            getline(cin,loginpass);
            xlp=loginpass;
            SToUpper(xlp);
            if(SToUpper(xlp)=="BACK"&&q==0)
            goto wronglogin;
            else if(SToUpper(xlp)!="EXIT")
            {
                if(loginpass==ReturnPass())
                {
                    loginpass="";
                    xlp="";
                    if(q==0)
                    {
                        loggedin=1;
                        system("cls");
                        Sleep(1000);
                        Colour(192);
                        cout<<"#";
                        Colour(192);
                        cout<<BOLD<<" YOU HAVE BEEN SUCCESSFULLY LOGGED IN TO"<<UNBOLD;
                        Colour(0);
                        cout<<" ";
                        Colour(12);
                        cout<<UNDERLINE<<loginid<<CLOSEUNDERLINE;
                        Colour(0);
                        cout<<" ";
                        Colour(192);
                        cout<<"#";
                        Colour(7);
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
                    cout<<"USER ID:  "<<loginid;
                    Colour(192);
                    cout<<"\nINCORRECT PASSWORD!";
                    Colour(7);
                    Sleep(3000);
                    goto wrongpass;
                }
            }
            else
            {
                xloginid="EXIT";
                if(q==0)
                {
                    loggedin=0;
                }
                goto exitfrompass;
            }
        }
        else
        {
            incorrectuserid:
            system("cls");
            Colour(192);
            cout<<"INCORRECT USER ID!";
            Colour(7);
            Sleep(3000);
            goto wronglogin;
        }
    }
    else
    {
        getout:
        Sleep(2000);
        if(q==0)
        {
            loginid="";
            loggedin=0;
        }
        if(q==1)
        successq1=2;
        else
        successq1=0;
        system("cls");
        Sleep(1500);
    }
    return successq1;
}
void CodedStorage(int q,string &value)
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
void MakeOrRemoveFileName(int q)
{
    if(q==0)
    {
        int i=0,j=48;
        char k;
        path1=basepath+"/";
        path2=basepath+"/";
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
            path2=path2+'B'+'$';
            if((i+1)%2!=0)
            path2=path2+'i'+'!';
            if((i+1)%3==0)
            path2=path2+'n'+'#';
            i++;
        }
        i=0;
        j=100;
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
            path1=path1+'N'+'$';
            if((i+1)%2!=0)
            path1=path1+'U'+'#';
            if((i+1)%3==0)
            path1=path1+'L'+'!';
            if((i+1)%5==0)
            path1=path1+'L'+'_';
            i++;
        }
        path1=path1+".csv";
        path2=path2+".csv";
        OpenPathFile(path1);
        OpenPathFile(path2);
        OpenPathFile(path3);
        OpenPathFile(path4);
        OpenPathFile(path5);
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
void OpenPathFile(string file)
{
    ofstream open(file.c_str(),ios::app);
    open.close();
}
void CodedStorageTot(int q,string &a,string &b,string &c,string &d,string &e,string &f,string &g,string &h)
{
    CodedStorage(q,a);
    CodedStorage(q,b);
    CodedStorage(q,c);
    CodedStorage(q,d);
    CodedStorage(q,e);
    CodedStorage(q,f);
    CodedStorage(q,g);
    CodedStorage(q,h);
}
void CreateAcc()
{
    system("cls");
    cout<<"To create an account:\n";
    system("pause");
    createid:
    system("cls");
    string xid="",id="";
    cout<<"\nTYPE:\n\"exit\": To Go Back To Settings.\nOR\nEnter the following requirements to create an account:\n\n";
    Colour(78);
    cout<<"USER ID:";
    Colour(7);
    cout<<"  ";
    getline(cin,id);
    xid=id;
    exitfrompass:
    SToUpper(xid);
    if(SToUpper(xid)!="EXIT")
    {
        if(CheckID(id)==1)
        {
            system("cls");
            Colour(192);
            cout<<"ERROR:  The USER ID entered by you was not accepted!\nThe user id:\n~SHOULD HAVE A MINIMUM OF 6 CHARACTERS\n~MAY HAVE A MAXIMUM OF 30 CHARACTERS\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
            Colour(7);
            goto createid;
        }
        else 
        {
            if(AvailOfID(id)==1)
            {
                system("cls");
                Colour(192);
                cout<<"SORRY:  The USER ID already exists! Please try a different selection!\nThe user id:\n~SHOULD HAVE A MINIMUM OF 6 CHARACTERS\n~SHOULD NOT CONTAIN ANY SPACES\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
                Colour(7);
                goto createid;
            }
            else
            {
                system("cls");
                createpass:
                string xp="",pass="";
                cout<<"\nTYPE:\n\"exit\": To Go Back To Settings.\n\"back\": To Re-Enter USER ID.\nOR ENTER PASSWORD--\n\n";
                cout<<"USER ID:  "<<id;
                Colour(78);
                cout<<"\n\nPASSWORD:";
                Colour(7);
                cout<<"  ";
                getline(cin,pass);
                xp=pass;
                SToUpper(xp);
                if(SToUpper(pass)=="BACK")
                goto createid;
                else if(SToUpper(pass)!="EXIT")
                {
                    xp="";
                    if(CheckPass(pass)==1)
                    {
                        system("cls");
                        Colour(192);
                        cout<<"ERROR:  The PASSWORD entered by you was not accepted!\nThe password:\n~SHOULD HAVE A MINIMUM OF 8 CHARACTERS\n~SHOULD CONTAIN ATLEAST 2 NUMBERS\n~SHOULD CONTAIN ATLEAST 2 ALPHABETS\n~SHOULD CONTAIN ATLEAST 1 SPECIAL CHARACTER\n~SHOULD NOT CONTAIN ANY SPACES\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
                        Colour(7);
                        goto createpass;
                    }
                    else
                    {
                        system("cls");
                        CorrectionAccData(path6);
                        ofstream storeacc(path6,ios::app);
                        if(CheckAcc())
                        storeacc<<'\n'<<id<<','<<pass;
                        else
                        storeacc<<id<<','<<pass;
                        Colour(192);
                        cout<<"\n\nHOORAY!  YOUR ACCOUNT HAS BEEN SUCCESSFULLY CREATED!\n\n";
                        Colour(7);
                        Sleep(1000);
                        storeacc.close();
                    }
                }
                else
                {
                    id="EXIT";
                    goto exitfrompass;
                }
            }
        }
    }
    else
    {
        system("cls");
        Colour(192);
        cout<<"SIGN-UP TERMINATED";
        Colour(7);
        Sleep(3000);
        system("cls");
    }
}
int CheckAcc()
{
    OpenPathFile(path6);
    string id="",pass="";
    int x;
    ifstream check1(path6);
    while(!check1.eof())
    {
        getline(check1,id,',');
        getline(check1,pass,'\n');
        if(id==""||pass==""||pass=="\n"||id==","||pass=="")
        {   
            x=0;
        }
        else
        x=1;
    }
    check1.close();
    return x;
}
int AvailOfID(string enteredid)
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
        pass="";
        if(id==enteredid)
        {
            flag=1;
            break;
        }
    }
    return flag;
}
int CheckPhoneNo(string &num,string &name,int q)
{
    int flag=0;
    string no,nam;
    reno:
    system("cls");
    Colour(143);
    cout<<"NUMBER:";
    Colour(7);
    if(q==1)
    cout<<"\n\nOLD DATA: "<<num;
    cout<<"\n\nTYPE\n\"back\": ";
    if(q==0)
    cout<<"To Go Back To Main Menu.";
    else
    cout<<"To Continue With The Old Data Or Enter The New Data.\n";
    Colour(78);
    cout<<"\nENTER HERE:";
    Colour(7);
    cout<<"  ";
    getline(cin,no);
    SToUpper(no);
    TotalReset(no,no,no,no,no,no,no,no,0);
    if(SToUpper(no)!="BACK")
    {
        if(CheckNo(no))
        {
            Colour(192);
            cout<<"\nERROR:  Wrong format for phone number!\n\n";
            Colour(7);
            goto reno;
        }
        else
        {
            if(CheckUniNo(no,nam,path2,0)==0)
            {
                Colour(192);
                cout<<"ERROR:  Two person cannot have same phone number!";
                Colour(7);
                rud:
                cout<<"\n\nThe phone number "<<no<<" already belongs to "<<nam;
                oops:
                Colour(143);
                cout<<"\nPRESS:";
                Colour(7);
                cout<<"\n1:To re-enter phone number\nOR TYPE\n\"back\": ";
                if(q==0)
                cout<<"To Go Back To Main Menu.";
                else
                cout<<"To Continue With The Old Data.";
                Colour(78);
                cout<<"\n\nENTER HERE:  ";
                Colour(7);
                string choice;
                getline(cin,choice);
                if(choice=="1")
                goto reno;
                else if(SToUpper(choice)=="BACK")
                {
                    if(q==1)
                    flag=1;
                }
                else
                {
                    Colour(192);
                    cout<<"ERROR:Enter again!";
                    Colour(7);
                    Sleep(2000);
                    system("cls");
                    goto oops;
                }
            }
            else
            {
                if(name==""||name==num)
                name=no;
                num=no;
                flag=1;
            }
        }
    }
    else
    if(q==1)
    flag=1;
    return flag;
}
void ResetSpace(string &word,int q)
{
    if(q==0)
    {
    string newword="";
        int i=1,length=word.length();
        if(word[0]==' ')
        {
            while(word[i]!='\0')
            {
                newword=newword+word[i];
                i++;
            }
            word=newword;
            length-=1;
            ResetSpace(word,0);
        }
        else
        {
        ResetSpace(word,1);
        }
    }
    else if(q==1)
    {
        int length=word.length(),x;
        if(word[length-1]==' ')
        {
            int i=0;
            
            string newword="";
            int c=0;
            for(x=length-1;x>=0;x--)
            {
                if(word[x]==' ')
                c++;
                else
                {
                    break;
                }
            }
            length-=c;
            for(i=0;i<length;i++)
            {
                newword=newword+word[i];
            }
            cout<<newword;
            word=newword;
        }
    }

}
void HyphenMaker(string &word)
{
    if(word=="")
    word="-";
}
void TotalReset(string &a,string &b,string &c,string &d,string &e,string &f,string &g,string &h,int q)
{
    if(q==0)
    {
        ResetSpace(a,0);
        HyphenMaker(a);
    }
    else if(q==1)
    {
        ResetSpace(a,0);
        ResetSpace(b,0);
        ResetSpace(c,0);
        ResetSpace(d,0);
        ResetSpace(e,0);
        ResetSpace(f,0);
        ResetSpace(g,0);
        ResetSpace(h,0);
        HyphenMaker(a);
        HyphenMaker(b);
        HyphenMaker(c);
        HyphenMaker(d);
        HyphenMaker(e);
        HyphenMaker(f);
        HyphenMaker(g);
        HyphenMaker(h);
    }
}
void NewFileNameAndRenameExistingFile()
{
    string oldname1="",oldname2="";
    oldname1=path1;
    oldname2=path2;
    MakeOrRemoveFileName(0);
    int xb1=rename(oldname1.c_str(),path1.c_str());
    int xb2=rename(oldname2.c_str(),path2.c_str());
}
int PresenceInSelect(string no)
{
    ifstream file0(path4);
    int x=0;
    string junk,sr;
    getline(file0,junk,'\n');
    while(!file0.eof())
    {
        string number,junk;
        getline(file0,sr,',');
        getline(file0,number,',');
        getline(file0,junk,'\n');
        if(no==number)
        {
            x=1;
            break;
        }
    }
    file0.close();
    return x;
}
void cheatcode()
{
    cheat:
    system("cls");
    cout<<"ENTER THE DRIVE IN WHICH YOU WANT TO STORE\nOR TYPE\n\"default\": TO CONTINUE WITH DEFAUT WINDOWS DRIVE(C)\nENTER HERE:";
    string drive,command="";
    getline(cin,drive);
    string d=drive;
    if(SToUpper(d)!="DEFAULT")
    {
        driveexists:
        command="cd \""+drive+":/\"";
        if(system(command.c_str())==0)
        {
            cout<<"DRIVE EXISTS!";
            Sleep(2000);
            cout<<"\nARE YOU SURE YOU WANT TO USE THIS DRIVE FOR CURRENT STORAGE? (Y/N)\n";
            string choice;
            getline(cin,choice);
            if(SToUpper(choice)=="Y")
            {
                string x1="",x2="",x3="",f1="PROJECTS DATA",f2="PHONEBOOK FILES",f3="PHONEBOOK",command="";
                x1=drive+":/"+f1;
                x2=x1+"/"+f2;
                x3=x2+"/"+f3;
                command="cd \""+x1+"\"";
                if(system(command.c_str())==1)
                {
                    command="mkdir \""+x1+"\"";
                    system(command.c_str());
                }
                for(int i=0;i<10;i++)
                {
                    string is=IntToStr(i),is1=IntToStr(i+1),prints;
                    prints="Found dir:/\t::/::://qwerty//\t:://accessing dir//\t{c:o:d:e}/"+is1+"/[P:~:R:~:O:~:J:~:E:~:C:~:T:~:S:~: :~:D:~:A:~:T:~:A]//\t:://completing access dir//\t:?:!:@//:://completed"+is+"\n";
                    for(int j=0;prints[j]!='\0';j++)
                    {
                        cout<<prints[j];
                        Sleep(0.9);
                    }
                }
                command="cd \""+x2+"\"";
                if(system(command.c_str())==1)
                {
                    command="mkdir \""+x2+"\"";
                    system(command.c_str());
                }
                for(int i=0;i<10;i++)
                {
                    string is=IntToStr(i),is1=IntToStr(i+1),prints;
                    prints="Found dir:/\t::/::://qwerty//\t:://accessing dir//\t{c:o:d:e}/"+is1+"/[P:~:H:~:O:~:N:~:E:~:B:~:O:~:O:~:K:~:F:~:I:~:L:~:E:~:S]//\t:://completing access dir//\t:?:!:@//:://completed"+is+"\n";
                    for(int j=0;prints[j]!='\0';j++)
                    {
                        cout<<prints[j];
                        Sleep(0.9);
                    }
                }
                command="cd \""+x3+"\"";
                if(system(command.c_str())==1)
                {
                    command="mkdir \""+x3+"\"";
                    system(command.c_str());
                }
                for(int i=0;i<10;i++)
                {
                    string is=IntToStr(i),is1=IntToStr(i+1),prints;
                    prints="Found dir:/\t::/::://qwerty//\t:://accessing dir//\t{c:o:d:e}/"+is1+"/[P:~:H:~:O:~:N:~:E:~:B:~:O:~:O:~:K]//\t:://completing access dir//\t:?:!:@//:://completed"+is+"\n";
                    for(int j=0;prints[j]!='\0';j++)
                    {
                        cout<<prints[j];
                        Sleep(0.9);
                    }
                }
                basepath=x3;
                path3=basepath+"/TgQDjQFuvmVtGqdJqfUVMvTtTtVmvuFQjDQgTvMVUfqJdqGt.csv";
                path4=basepath+"/VCmDfrJMqeGQknRwdN.csv";
                path5=basepath+"/eMRGgb.csv";
                path6=basepath+"/rPpdXeYZyDSqzaQERPxyZedPySzQeAQd.txt";
                for(int i=0;i<10;i++)
                {
                    string is=IntToStr(i),is1=IntToStr(i+1),prints;
                    prints="Generating filename:/\t::/::://qwerty//\t:://accessing filename//\t{c:o:d:e}/"+is1+"/[B:~:A:~:S:~:E:~:P:~:A:~:T:~:H]/[P:~:A:~:T:~:H:~:3]/[P:~:A:~:T:~:H:~:4]/[P:~:A:~:T:~:H:~:5]/[P:~:A:~:T:~:H:~:6]//\t:://completing access filename//\t:?:!:@//:://cre@teD"+is+"\n";
                    for(int j=0;prints[j]!='\0';j++)
                    {
                        cout<<prints[j];
                        Sleep(0.9);
                    }
                    Sleep(100);
                    cout<<"\n\t\t\t\t\t\t\t\t"<<basepath<<basepath<<"\t\t\t\t\t\t\t\t"<<"{p:a:t:h}//[L:~:O:~:C:~:A:~:T:~:I:~:O::N]\"A;`;C;`;C;`;E;`;S;`;S\"/:://://{g:r:a:n:t:e:d}\n";
                }
            }
            else if(SToUpper(choice)=="N")
            goto cheat;
            else
            {
                goto driveexists;
            }
        }
        else
        {
            Sleep(1000);
            system("pause");
            goto cheat;
        }
    }
    else
    {
        string x1="",x2="",x3="",f1="PROJECTS DATA",f2="PHONEBOOK FILES",f3="PHONEBOOK",command="";
        x1="C:/"+f1;
        x2=x1+"/"+f2;
        x3=x2+"/"+f3;
        basepath=x3;
        basepath="C:/PROJECTS DATA/PHONEBOOK FILES/PHONEBOOK";
        path3=basepath+"/TgQDjQFuvmVtGqdJqfUVMvTtTtVmvuFQjDQgTvMVUfqJdqGt.csv";
        path4=basepath+"/VCmDfrJMqeGQknRwdN.csv";
        path5=basepath+"/eMRGgb.csv";
        path6=basepath+"/rPpdXeYZyDSqzaQERPxyZedPySzQeAQd.txt";
        for(int i=0;i<10;i++)
        {
            string is=IntToStr(i),is1=IntToStr(i+1),prints;
            prints="Generating filename:/\t::/::://qwerty//\t:://accessing filename//\t{c:o:d:e}/"+is1+"/[B:~:A:~:S:~:E:~:P:~:A:~:T:~:H]/[P:~:A:~:T:~:H:~:3]/[P:~:A:~:T:~:H:~:4]/[P:~:A:~:T:~:H:~:5]/[P:~:A:~:T:~:H:~:6]//\t:://completing access filename//\t:?:!:@//:://cre@teD"+is+"\n";
            for(int j=0;prints[j]!='\0';j++)
            {
                cout<<prints[j];
                Sleep(0.9);
            }
            Sleep(100);
            cout<<"\n\t\t\t\t\t\t\t\t"<<basepath<<basepath<<"\t\t\t\t\t\t\t\t"<<"{p:a:t:h}//[L:~:O:~:C:~:A:~:T:~:I:~:O::N]\"A;`;C;`;C;`;E;`;S;`;S\"/:://://{g:r:a:n:t:e:d}\n";
        }
    }
}
void makee()
{
    string x1="",x2="",x3="",f1="PROJECTS DATA",f2="PHONEBOOK FILES",f3="PHONEBOOK",command="";
    x1="C:/"+f1;
    x2=x1+"/"+f2;
    x3=x2+"/"+f3;
    command="cd \""+x1+"\"";
    if(system(command.c_str())==1)
    {
        command="mkdir \""+x1+"\"";
        system(command.c_str());
    }
    command="cd \""+x2+"\"";
    if(system(command.c_str())==1)
    {
        command="mkdir \""+x2+"\"";
        system(command.c_str());
    }
    command="cd \""+x3+"\"";
    if(system(command.c_str())==1)
    {
        command="mkdir \""+x3+"\"";
        system(command.c_str());
    }
}