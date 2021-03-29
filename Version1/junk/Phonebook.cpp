//project_by_ _the_twins_33
//pooja agarwal
//rudrashis kumar dutta
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<iomanip>                                  
#include<windows.h>
using namespace std;
void openpathfile(string file);
int checkacc();
void createacc();
int checkid(string id);
int availofid(string enteredid);
int checkpass(string pass);
int nooftrials=0,loggedin=0;
string loginid,loginpass,login;
string stoupper(string s);
void correctionaccd(string filename);
int loginfunc(int q);
void colour(int c);
string returnpass();
string basepath="C:/PHONEBOOK/",path1="",path2="",path3="C:/PHONEBOOK/searchresults.csv",path4="C:/PHONEBOOK/selection.csv",path5="C:/PHONEBOOK/copied.csv",path6="C:/PHONEBOOK/accounts.txt";
int main()
{
    account:
    correctionaccd(path6);
    if(checkacc()==0)
    {
        cout<<"\n\nSORRY: YOU HAVE NOT CREATED ANY ACCOUNT IN PHONEBOOK\nSIGN UP TO CONTINUE\nPRESS:\n1:SIGN UP\nOR\nTYPE:\n\"exit\":EXIT PHONEBOOK\n\nYOUR CHOICE:  ";
        string choice;
        getline(cin,choice);
        if(choice=="1")
        {
            createacc();
            Sleep(2000);
            system("cls");
            goto account;
        }
        else if(stoupper(choice)=="EXIT");
        else
        {
            system("cls");
            cout<<"\nERROR: Enter again!";
            Sleep(2000);
            system("cls");
            goto account;
        }
    }
    else
    {
        cout<<"\n\nPRESS:\n1:LOGIN\n2:SIGN UP\nOR\nTYPE:\n\"exit\":TO EXIT PHONEBOOK\n\nYOUR CHOICE:";
        string choice;
        getline(cin,choice);
        if(choice=="1")
        {
           loginfunc(0);
           if(loggedin==1)
           {
               cout<<"LOG IN HUA BC!";
           }
           if(loggedin==0)
           goto account;
        }
        else if(choice=="2")
        {
            createacc();
            goto account;
        }
        else if(stoupper(choice)=="EXIT");
        else
        {
            system("cls");
            cout<<"\nERROR: Enter again!";
            Sleep(2000);
            system("cls");
            goto account;
        }
    }
}
void openpathfile(string file) //opens a file in ofstream append mode
{
    ofstream open(file.c_str(),ios::app);
    open.close();
}
int checkacc() //checks the presence of any account
{
    openpathfile(path6);
    string id="",pass="";
    int x;
    ifstream check1(path6);
    while(!check1.eof())
    {
        getline(check1,id,',');
        getline(check1,pass,'\n');
        if(id==""||pass==""||pass=="\n"||id==","||pass=="")
        x=0;
        else
        x=1;
    }
    check1.close();
    return x;
}
void createacc() //creating a new account
{
    string id,pass;
    cout<<"To create an account:\n";
    system("pause");
    createid:
    cout<<"Enter the following requirements to create an account:\n\nUSER ID:\t";
    getline(cin,id);
    if(checkid(id)==1)
    {
        cout<<"ERROR:  The USER ID entered by you was not accepted!\nThe user id:\n~SHOULD HAVE A MINIMUM OF 6 CHARACTERS\nMAY HAVE A MAXIMUM OF 30 CHARACTERS\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
        goto createid;
    }
    else 
    {
        if(availofid(id)==1)
        {
            cout<<"SORRY:  The USER ID already exists!Please try a different selection!\nThe user id:\n~SHOULD HAVE A MINIMUM OF 6 CHARACTERS\n~SHOULD NOT CONTAIN ANY SPACES\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
            goto createid;
        }
    }
    createpass:
    cout<<"\n\nPASSWORD:\t";
    getline(cin,pass);
    if(checkpass(pass)==1)
    {
        cout<<"ERROR:  The PASSWORD entered by you was not accepted!\nThe password:\n~SHOULD HAVE A MINIMUM OF 8 CHARACTERS\n~SHOULD CONTAIN ATLEAST 2 NUMBERS\n~SHOULD CONTAIN ATLEAST 2 ALPHABETS\n~SHOULD CONTAIN ATLEAST 1 SPECIAL CHARACTER\n~SHOULD NOT CONTAIN ANY SPACES\n~SHOULD NOT CONTAIN ANY COMMAS(,)\n\n";
        goto createpass;
    }
    correctionaccd(path6);
    ofstream storeacc(path6,ios::app);
    if(checkacc())
    storeacc<<'\n'<<id<<','<<pass;
    else
    storeacc<<id<<','<<pass;
    cout<<"\n\nHOORAY!  YOUR ACCOUNT HAS BEEN SUCCESSFULLY CREATED!\n\n";
    storeacc.close();
}
int checkid(string id) //validity of id
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
int availofid(string enteredid) //availability of id
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
int checkpass(string pass) //checks the strength of the password
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
int loginfunc(int q) //verifies user id and pass(can also be used for login purpose)
{
    wronglogin:
    int successq1=0;
    system("cls");
    loginid="";
    loginpass="";
    int flag1=0;
    cout<<"USER ID:  ";
    getline(cin,loginid);
    if(availofid(loginid))
    {
        wrongpass:
        loginpass="";
        cout<<"PASSWORD:  ";
        getline(cin,loginpass);
        if(loginpass==returnpass())
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
            cout<<"USER ID:  "<<loginid<<"\nINCORRECT PASSWORD!\nPRESS:\n1: RE-ENTER PASSWORD\n2: RE-ENTER USER ID\nOR\nTYPE:\n\"exit\"";
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
            else if(choice=="2")
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
void colour(int c) //adds colour
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
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
/*void change(int q)
{
    change:
    string junk,oldpass="",newpass="",confirmpass="",newid;
    cout<<"USER ID:  "<<loginid;
    cout<<"TYPE:\n\"exit\":To go back to settings\nOR\nEnter the password to gain access: ";
    getline(cin,oldpass);
    if(oldpass==returnpass())
    {
        oldpass="";
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
}*/
