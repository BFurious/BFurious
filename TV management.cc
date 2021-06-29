#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>

using namespace std;
string local_day;
int local_hr,local_min;
char ch='y';
void login()
{   char name[10];
    int pin[10],i=0;
    int password[4]={49,50,51,52};
    cout<<"\n\n\n\n\n\n\t\t\t\t\t << LOG IN >>"<<endl<<endl;
    cout<<"\t\t\t\tUser Name: ";
    cin>>name;
    cout<<"\t\t\t\tPassword:  ";
    while(i<4)
    {
    pin[i]=getch();
    cout<<"*";
    i++;
    }
    if(strcmp(name,"ashuth")==0)
        for(i=0;i<4;i++)
         {
             if(pin[i]==password[i])
                {
                }
            else
            {  cout<<"\n\t\t\t !!!!! WRONG ID OR PIN !!!!!";
                getch();
                exit(0);
             }
         }
    else
     {  cout<<"\n!!!!! WRONG ID !!!!! ";
        getch();
        exit(0);
     }
     cout<<"\n\t\t\t\t\t ACCESS GRANTED"<<endl;
      cout<<"\n\t\t\t Press any key to proceed.........."<<endl;
     getch();

}
class trp_class{
    int target_people;
    int impression;
    int trp;
    int rate;
public:
    trp_class()
    {
        trp=0;
        rate=0;
    }
    void calculate_trp()
    {   cout<<"\n Enter the no. of targeted people (Max 1000): ";
        cin>>target_people;
        cout<<"\n Enter the impression got to the program (Max 1000): ";
        cin>>impression;
        trp=(impression*100/target_people);

    }
    void calculate_ratepersec()
    {
        if(trp<=20&&trp>=0)
                rate=1;
        else if(trp<=60&&trp>20)
                rate=10;
        else if(trp>60&&trp<=100)
                rate=50;

    }
    void output()
    {
        cout<<" TRP: "<<trp<<endl;
        cout<<" Rate: "<<rate<<endl;
        cout<<endl;
    }
    int return_rate()
    {
        return rate;
    }

};
class amount{
 float company_payable[4];
 float prog_worth;
int companies;
public:

    amount()
    {   companies=0;
        company_payable[4]=0;
        prog_worth=0;
    }
    void calculate_amount(int n,int rate,int *sec,int *days)
    {   companies=n;
        prog_worth=0;
        for(int i=0;i<n;i++)
        {
            company_payable[i]=rate**(sec+i)**(days+i);
            prog_worth+=company_payable[i];
        }

    }
    void output()
    {   int n=companies;
        cout<<"\n\t\t\t   <<ACCOUNTING DETAIL>>"<<endl;
        for(int i=0;n>0;i++)
        {
            cout<<" Net Payable company "<<i+1<<" : "<<company_payable[i]<<endl;
            --n;
        }
         cout<<"------------------------------------------------\n";
        cout<<" The program worth of: "<<prog_worth;
    }


};
class sponsor{//Max 4 sonsors
    int total_company;
    char company[4][30];
    long double contact[4];
    int ad_time[4];//lower than 60 sec
    int ad_day[4];//less than 30
public:
    sponsor()
    {
        total_company=0;
    }
    void input(int n)
    {   int i;
        total_company=n;
        for(i=0;i<n;i++)
        {
            cout<<"\t( COMPANY "<<i+1<<" DETAILS )";
            cout<<"\n Company Name: ";
            cin>>company[i];
            cout<<" Contact no.: ";
            cin>>contact[i];
            while(1)
            {
                cout<<" Ad_time (Max 60 sec): ";
                cin>>ad_time[i];
                if(ad_time[i]>60)
                    cout<<"\t LIMIT EXCEED";
                else
                break;
            }
            while(1)
            {
                cout<<" Ad_Days (Max 30 days): ";
                cin>>ad_day[i];
                if(ad_day[i]>60)
                    cout<<"\t LIMIT EXCEED";
                else
                    break;
            }
        }
    }
    void output()
    {
        int n=total_company;
        cout<<"\t\t\t\t <<SPONSOR DETAIL>>"<<endl<<endl;
        if(n==0)
            cout<<" No company sponsoring till now";
        else{
            cout<<" Total Companies sponsoring: ";
            cout<<total_company<<endl<<endl;
            for(int i=0;n>0;i++)
            {
                cout<<" Company No: "<<i+1<<endl;
                cout<<" Company Name: "<<company[i]<<endl;
                cout<<" Contact no.: "<<contact[i]<<endl;
                    cout<<" Ad_time (Max 60 sec): "<<ad_time[i]<<endl;
                cout<<" Ad_Days(Max 30 days): "<<ad_day[i]<<endl;
                cout<<"--------------------------\n";
                --n;
            }
        }
    }
    int *return_ad_time()
    {
        return ad_time;
    }
    int *return_ad_day()
    {
        return ad_day;
    }

};

class program: public trp_class,public amount,public sponsor
{
    char Name[10];
    int hr,min;
    char day[10];
public:
    program()
    {
        Name[10]=NULL;
        hr=0;
        min=0;
        day[10]=NULL;
    }
    void input()//take input in program class
    {
         cout<<" Enter the program name: ";
        cin>>Name;
        //input day and time
        cout<<" Enter the day of the program(eg. Monday): ";
        cin>>day;
        cout<<" Enter the timing of the program(hr min): ";
        cin>>hr;
        cin>>min;

    }


void output()
    {   cout<<"\n\t\t\t\t <<GENERAL DETAIL>>"<<endl;
        cout<<"\n Program Name: ";
        cout<<Name<<endl;
        cout<<" Day: "<<day<<endl;
        cout<<" Time: "<<hr<<":"<<min<<endl;
        trp_class::output();
        sponsor::output();
        amount::output();
        cout<<"\n\n========================================================================================================\n";
    }
    void general_detail()
    {
        cout<<"\n Program Name: ";
        cout<<Name<<endl;
        cout<<" Day: "<<day<<endl;
        cout<<" Time: "<<hr<<":"<<min<<endl;
    }
    void modify()
    {    char nm[10]=" ";
        char d[10];
         int h,m;
        cout<<"\n\t\t\t<<PREVIOUS DETAIL>> "<<endl;
        general_detail();
         cout<<"\n\t\t\t<<NEW DETAIL>> "<<endl;
        cout<<"\n Enter the program name (retain old one press'.'): ";
        cin>>nm;
        cout<<"\n Enter the day of the program (eg. Monday)(retain old one press'.'): ";
        cin>>d;
        cout<<"\n Enter the timing of the program(hr min) (retain old one press -1): ";
        cin>>h;
        cin>>m;
        if(strcmp(nm,".")!=0)
            strcpy(Name,nm);
        if(strcmp(d,".")!=0)
            strcpy(day,d);
        if(h!=-1)
            hr=h;
        if(m!=-1)
            min=m;

    }
    string return_day()
    {
        return day;
    }
    int return_hr()
    {
        return hr;
    }
    int return_min()
    {
        return min;
    }
}p1,temp;
//main Program
int main()
{   int choice,pos=0;
    login();

    while(1){
            system("cls");
            cout<<"\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"\t\t\t\tSTAR LIGHT PRODUCTION"<<endl;
            cout<<"\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
        cout<<"\t\t\t\t <<SELECT YOUR CHOICE>> "<<endl;
        cout<<"\n 1. Scheduled a program";
        cout<<"\n 2. Calculate TRP and Rates";
        cout<<"\n 3. Input Sponsor details";
        cout<<"\n 4. Search a scheduled program";
        cout<<"\n 5. Reschedule a program";
        cout<<"\n 6. Delete a program";
        cout<<"\n 7. Show all scheduled program";
        cout<<"\n\n Enter your choice: ";
        cin>>choice;
        system("cls");
        switch(choice)
        {   case 1:
            {
                    fstream file("TV1.dat",ios::out|ios::app|ios::binary);
                    file.seekg(0);
                    do
                    {   system("cls");
                        cout<<"\t\t\t<<SCHEDULE A PROGRAM>>"<<endl<<endl;
                        cout<<" NOTE: Search the program before scheduling to remove ambiguity."<<endl<<endl;
                        p1.input();
                          file.write((char*)&p1,sizeof(p1));
                            cout<<"\n\t PROGRAM SCHEDULED"<<endl;
                            cout<<"\n Do u want to Scheduled one more program(y/n): ";
                            cin>>ch;

                    }while(ch=='y'||ch=='Y');
                    file.close();

            }
            break;

    case 2: {
                bool flag=0;
                cout<<"\t\t\t<<CALCULATE TRP AND RATES>>"<<endl;
                cout<<"\n Enter the Program day and time (i.e. day hr min): ";
                cin>>local_day;
                cin>>local_hr;
                cin>>local_min;
                fstream file;
                file.open("TV1.dat",ios::in|ios::out|ios::binary);
                file.seekg(0);
                while(!file.eof())
                {   pos=file.tellg();
                    file.read((char*)&p1,sizeof(p1));
                    if(p1.return_day()==local_day)
                    {
                        if(p1.return_hr()==local_hr&&p1.return_min()==local_min)
                        {   flag=1;
                            p1.trp_class::calculate_trp();
                            p1.trp_class::calculate_ratepersec();
                            file.seekg(pos);
                            file.write((char*)&p1,sizeof(p1));
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    cout<<"\n\t NO RECORD FOUND";
                    getch();
                }
                else
                {
                    cout<<"\n\t RECORD UPDATED"<<endl;
                    getch();
                }
    }
    break;
    case 3:{
             bool flag=0;
                int n;
                int rate;
                int *sec,*days;
                cout<<"\t\t\t<<INPUT SPONSOR DETAIL>>"<<endl<<endl;
                cout<<" Enter the program day and time (i.e. day hr min) that company want to sponsor: ";
                cin>>local_day;
                cin>>local_hr;
                cin>>local_min;
                fstream file;
                file.open("TV1.dat",ios::in|ios::out|ios::binary);
                file.seekg(0);
                 while(!file.eof())
                {   pos=file.tellg();
                    file.read((char*)&p1,sizeof(p1));
                    if(p1.return_day()==local_day)
                    {
                        if(p1.return_hr()==local_hr&&p1.return_min()==local_min)
                        {   rate=p1.trp_class::return_rate();
                            if(rate==0)
                            {    flag=1;
                                cout<<" Record found but first CALCULATE THE TRP to proceed "<<endl;
                                break;
                            }
                            flag=1;
                            cout<<"\n How many companies are sponsoring (Max 4): ";
                            cin>>n;
                            p1.sponsor::input(n);
                            sec=p1.sponsor::return_ad_time();
                            days=p1.sponsor::return_ad_day();
                            p1.amount::calculate_amount(n,rate,sec,days);
                            file.seekg(pos);
                                file.write((char*)&p1,sizeof(p1));
                            break;

                        }

                    }
                }
                if(flag==0)
                {
                    cout<<"\n\t NO RECORD FOUND"<<endl;
                    getch();
                }
                else
                {
                    cout<<"\n\t  RECORD UPDATED ";
                    getch();
                }

                file.close();

        }break;
case 4:
            {
                bool flag=0;
                cout<<"\t\t\t<<SEARCH A SCHEDULED PROGRAM>>"<<endl<<endl;
                cout<<" Enter the program day and time(i.e. day hr min): ";
                cin>>local_day;
                cin>>local_hr;
                cin>>local_min;

                fstream file;
                file.open("TV1.dat",ios::in|ios::out|ios::binary);
                file.seekg(0);
                while(!file.eof())
                {   file.read((char*)&p1,sizeof(p1));
                    if(p1.return_day()==local_day)
                    {
                        if(p1.return_hr()==local_hr&&p1.return_min()==local_min)
                        {   flag=1;
                             p1.output();
                             getch();
                             break;
                        }
                    }
                }
                if(flag==0)
                {
                    cout<<" NO RECORD FOUND"<<endl;
                    getch();
                }
                file.close();
            }
                break;
 case 5:
            {
                bool flag=0;
                cout<<"\t\t\t<<RESCHEDULE A PROGRAM>>"<<endl<<endl;
                cout<<" Enter the program day and time (day hr min): ";
                cin>>local_day;
                cin>>local_hr;
                cin>>local_min;
                fstream file;

                file.open("TV1.dat",ios::in|ios::out|ios::binary);

                file.seekg(0);
                while(!file.eof())
                {   pos=file.tellg();
                    file.read((char*)&p1,sizeof(p1));
                    if(p1.return_day()==local_day)
                    {
                        if(p1.return_hr()==local_hr&&p1.return_min()==local_min)
                        {   flag=1;
                            p1.modify();
                            file.seekg(pos);
                            file.write((char*)&p1,sizeof(p1));

                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    cout<<" NO RECORD FOUND";
                    getch();
                }
                 else{
                    cout<<"\n\tRECORD UPDATED";
                    getch();
                }
                file.close();

            }
    break;
 case 6:
            {
                bool flag=0;
                cout<<"\t\t\t<<DELETE A SCHEDULED PROGRAM>>"<<endl<<endl;
                cout<<" Enter the program day and time (day hr min) u want to Delete: ";
                cin>>local_day;
                cin>>local_hr;
                cin>>local_min;
                //fstream infile,outfile;
                    ifstream infile;
                    ofstream outfile;
                infile.open("TV1.dat",ios::in|ios::binary);
                outfile.open("temp.dat",ios::out|ios::binary);
                infile.seekg(0);
                while(!infile.eof())
                {   pos=infile.tellg();
                    infile.read((char*)&p1,sizeof(p1));
                    if(p1.return_day()==local_day)
                    {
                        if(p1.return_hr()==local_hr&&p1.return_min()==local_min)
                        {   flag=1;

                        }
                         else
                            outfile.write((char*)&p1,sizeof(p1));
                    }
                     else
                            outfile.write((char*)&p1,sizeof(p1));
                }
                 if(flag==0)
                {
                    cout<<"\n\tNO RECORD FOUND";
                    getch();

                }
                else{
                    cout<<"\n\tRECORD DELETED";
                    getch();
                }
                  infile.close();
                outfile.close();
                remove("TV1.dat");
                rename("temp.dat","TV1.dat");
            }
        break;
  case 7:
            {       int i=1;
                   cout<<"\t\t\t<<SHOW ALL SCHEDULED PROGRAM>>"<<endl;
                    fstream file;
                    file.open("TV1.dat",ios::in|ios::binary);
                    file.seekg(0,ios::beg);
                    while(!file.eof())
                    {    cout<<"\n\t\t\t\t |||| PROGRAM "<<i<<" ||||"<<endl;
                        file.read((char*)&p1,sizeof(p1));

                        p1.output();
                        ++i;
                    }
                    file.close();
                getch();
            }

                break;
    default: exit(0);

    };
    }
    return 0;
}
