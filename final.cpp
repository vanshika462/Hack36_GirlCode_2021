#include<bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
//--------Structure for date and function for checking correct date---
//--------------------------------------------------------------------
struct dates
{
	int dd;
	int mm;
	int yyyy;
};
void checkdate(dates &d)
{
	if(d.yyyy<1900 || d.yyyy>2020 || d.mm<1 || d.mm>12)
	{
		cout<<"\n Invalid date entered!"
		    <<"\n Re-enter";
		cin>>d.dd>>d.mm>>d.yyyy;
	}
	if(d.mm==2)
	{
		if(d.yyyy%4==0)
		{
			if(d.dd<1 || d.dd>29)
			{
				cout<<"\n Invalid date entered!"
				    <<"\n Re-enter";
				cin>>d.dd>>d.mm>>d.yyyy;
			}
		}
	}
	else if(d.mm==4 || d.mm==6 || d.mm==9 || d.mm==11)
	{
		if(d.dd<1 || d.dd>30)
		{
			cout<<"\n Invalid date entered!"
			    <<"\n Re-enter";
			cin>>d.dd>>d.mm>>d.yyyy;
		}
	}
	else if(d.dd<1 || d.dd>31)
	{
		cout<<"\n Invalid date entered!"
		    <<"\n Re-enter";
		cin>>d.dd>>d.mm>>d.yyyy;
	}
}

//-------------------------------------------------------------------
//-----------------Structure for username credentials-----------------
//--------------------------------------------------------------------
struct user_creds
{
	int usercode;
	char username[20];
	char password[15];
};


//--------------------------------------------------------------------
//----------------Class for the basic details of client---------------
//--------------------------------------------------------------------
class client
{
	char name[50];
	char email[30];
	char phone[15];
	public: user_creds clcreds;
		int d;
		int code;
		//--------------Member Functions--------------
		void get_cl();
		void show_cl();
		void clcode()
		{
			rand();
			code=rand()%1000;
		}
		int returncode()
		{
			return code;
		}
		void get_cl_creds();
};
void client::get_cl_creds()
{
	clcreds.usercode=returncode();
	cout<<"\n Create username: ";
	cin>>clcreds.username;
	cout<<"\n Create password: ";
	cin>>clcreds.password;
	d=strlen(clcreds.password);
}
void client::get_cl()
{
	clcode();
	cout<<"\n Name of Client: ";
	cin>>name;
	cout<<"\n Phone Number: ";
	cin>>phone;
	cout<<"\n Email ID: ";
	cin>>email;
	cout<<"\n Your client CODE: ";
	cout<<code;
	get_cl_creds();
	cout<<"\n--------------------------\n";
}
void client::show_cl()
{
	cout<<"\n Code: "<<code;
	cout<<"\n Client Name: ";
	puts(name);
	cout<<"\n Email ID: ";
	puts(email);
	cout<<"\n Phone: ";
	puts(phone);
}
//--------------------------------------------------------------------
//-----------------Class for the basic details of the server----------
//--------------------------------------------------------------------
class server
{
	public:
		char name[30];
		int code;
		int d;
		int job;
		user_creds screds;
		//-----------Member Functions-----------
		void get_ser();
		void show_ser();
		void scode()
		{
			rand();
			code=rand()%1000;
		}
		int return_scode()
		{
			return code;
		}
		void get_s_creds();
};
void server::get_s_creds()
{
	screds.usercode=return_scode();
	cout<<"\n Create Username: ";
	cin>>screds.username;
	cout<<"\n Create Password: ";
	cin>>screds.password;
	d=strlen(screds.password);
}
void server::get_ser()
{
	scode();
    char med;
	cout<<"\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
	cout<<"\n Name of Server: ";
	cin>>name;
	cout<<"\n Are you a Nurse or a Doctor? [Y for Yes , N for No]: ";
	cin>>med;
    if (med=='Y')
    job=1;
    else
    job=2;
	get_s_creds();
	cout<<"\n Your Server CODE: ";
	cout<<code;
}
void server::show_ser()
{
	cout<<"\n Code: "<<code;
	cout<<"\n Name of Server: ";
	puts(name);
}

//--------------------------------------------------------------------
//----------------------CLASS FOR APPOINTMENTS------------------------
//--------------------------------------------------------------------

class appnt
{

    char client_name[25];
	dates date; 
	char server_name[25];
	int conf;

	public: char service[10];
			void getdata_cl();
			void getdata_se();
			int confirm();
            int price;
			void serdef(int);
		int code;
        int scode;
		int med;
		char status[15];
		//-------------Member Functions-----------
		void getapt();
		void showapt();
		void showapply();
		appnt()
		{
			strcpy(status,"OPEN");
		}
		void aptcode()
		{
			rand();
			code=rand()%1000;
		}
		int returncode()
		{
			return code;
		}
};

void appnt::serdef(int ch)
{
	switch(ch)
	{
		case 1: strcpy(service,"Test");
                med=1;
                price=250;
				break;
		case 2: strcpy(service,"Vaccine");
                med=1;
                price=1500;
				break;
		case 3: strcpy(service,"Sanitise");
                price=3000;
                med=0;
				break;
		default: break;
	}
}

void appnt::getdata_cl()
{
	cout<<"\n Client Name: ";
	cin>>client_name;
	int ch;
	cout<<"\n 1. Book Covid-19 test."
		<<"\n 2. Book Covid-19 vaccine."
		<<"\n 3. Sanitise your home."
		<<"\n Choose service: ";
	cin>>ch;
	serdef(ch);
}

void appnt::getdata_se()
{
    char medical;
	cout<<"\n Enter Name: ";
	cin>>server_name;
    cout<<"\nEnter Code: ";
    cin>>scode;
    cout<<"\n Are you in the medical field? [Y/N]";
    cin>>medical;
    if(medical=='Y')
    med=1;
    else
    med=0;
}

int appnt::confirm()
{
	char c;
	cout<<"\n Confirm? [Y/N] ";
	cin>>c;
	if(c=='y' || c=='Y')
		return 1;
	else
		return 0;
}

void appnt::getapt()
{
    aptcode();
    cout<<"Appointment Code: ";
    cout<<code;
    getdata_cl();
    cout<<"Enter date for appointment[dd/mm/yyyy]: ";
    cin>>date.dd>>date.mm>>date.yyyy;
}

void appnt::showapt()
{
    cout<<"Appointment Code: "<<code<<"\n";
    cout<<"Service: "<<service<<"\n";
    cout<<"Client Name: "<<client_name<<"\n";
    cout<<"Server Name: "<<server_name<<"\n";
}

void ser_register()
{
	server s;
	ofstream fout("servers.dat",ios::out|ios::app|ios::binary);
	if(!fout)
	{
		cout<<"\n Error in opening Database of servers!";
		exit(0);
	}
	s.get_ser();
	fout.write((char*)&s,sizeof(s));
	fout.close();
}

void add_cl()
{
	client c;
	ofstream fout("clients.dat",ios::out|ios::app|ios::binary);
	if(!fout)
	{
		cout<<"\n Error in opening Database of clients!";
		exit(0);
	}
	c.get_cl();
	fout.write((char*)&c,sizeof(c));
	fout.close();
}
//--------------------------------------------------------------------
//--------------------------Register Function-------------------------
//--------------------------------------------------------------------
void register_user()
{
	cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
	int ch;
	do
	{
		cout<<"\n Register as: "
		    <<"\n\t [1] Server"
		    <<"\n\t [2] Client"
		    <<"\n\t [3] Exit"
		    <<"\n\t     Enter your choice [1-3]: ";
		cin>>ch;
		cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
		switch(ch)
		{
			case 1: ser_register();
				break;
			case 2: add_cl();
				break;
			case 3: break;
			default: cout<<"\n Invalid choice!";
		}
    break;
	}
	while(ch!=3);
}

int login_ser()
{
	cout<<"\n -SERVER LOGIN-";
	int p=0;
	int code;
	cout<<"\n Enter your Server CODE: ";
	cin>>code;
	server a;
	ifstream fin("servers.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n Error in opening server database!";
		exit(0);
	}
	while(!fin.eof())
	{
		fin.read((char*)&a,sizeof(a));
		cout<<a.screds.usercode;
		if(a.screds.usercode==code)
		{
			char usern[20], pass[15];
            int i;
			cout<<"\n Username: ";
			cin>>usern;
			cout<<"\n Password: ";
			cin>>pass;
			if(strcmp(usern,a.screds.username)!=0)
				cout<<"\n Incorrect Username!";
			else if(strcmp(pass,a.screds.password)!=0)
				cout<<"\n Incorrect Password!";
			else if(strcmp(usern,a.screds.username)!=0 && strcmp(pass,a.screds.password)!=0)
			{
				cout<<"\n Incorrect credentials!";
				break;
			}
			else if(strcmp(usern,a.screds.username)==0 && strcmp(pass,a.screds.password)==0)
			{
				cout<<"\n Login Successful!";
				p=1;
				break;
			}
		}
	}
	fin.clear();
	fin.close();
	return p;
}


int login_cl()
{
	cout<<"\n -CLIENT LOGIN-";
	int l=0;
	int code;
	cout<<"\n Enter your Client Code: ";
	cin>>code;
	client e;
	ifstream fin("clients.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n Error in opening client database!";
		exit(0);
	}
	while(!fin.eof())
	{
		fin.read((char*)&e,sizeof(e));
		if(e.clcreds.usercode==code)
		{
			char usern[20], pass[15];
            int i;
			cout<<"\n Username: ";
			cin>>usern;
			cout<<"\n Password: ";
			cin>>pass;
			if(strcmp(usern,e.clcreds.username)!=0)
				cout<<"\n Incorrect Username!";
			else if(strcmp(pass,e.clcreds.password)!=0)
				cout<<"\n Incorrect Password!";
			else if(strcmp(usern,e.clcreds.username)!=0 && strcmp(pass,e.clcreds.password)!=0)
			{
				cout<<"\n Incorrect credentials!";
				break;
			}
			else if(strcmp(usern,e.clcreds.username)==0 && strcmp(pass,e.clcreds.password)==0)
			{
				cout<<"\n Login Successful!";
				l=1;
				break;
			}
		}
	}
	fin.clear();
	fin.close();
	return l;

}

void dispapt(appnt a)
{
	ifstream fin("appointments.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n Error in opening Database!";
		exit(0);
	}
	while(!fin.eof())
	{
		fin.read((char*)&a,sizeof(a));
		a.showapt();
	}
	fin.clear();
	fin.close();
}

//--------------------------------------------------------------------
//------------------------------Function to search Job----------------
//--------------------------------------------------------------------
void search_apt()
{
	int ch;
	appnt j;
	ifstream f("appointments.dat",ios::in|ios::binary);
	if(!f)
	{
		cout<<"\n Error in Opening Appointments Database!";
		exit(0);
	}
	cout<<"\n Are you in the Medical Field? [Enter 1 for yes and 0 for no]: ";
	cin>>ch;
	while(!f.eof())
    {
         f.read((char*)&j,sizeof(j));
		if(j.med==ch)
		{
			cout<<"\n Searching.. \n\n";
            dispapt(j);
        }	
	}
	f.clear();
	f.close();
}
//--------------------------------------------------------------------
//-------------------------Function to apply for job------------------
//--------------------------------------------------------------------
int apply_apt()
{
	appnt j;
	fstream fj("appointments.dat",ios::in|ios::out|ios::app|ios::binary);
	if(!fj)
	{
		cout<<"\n Error opening Appointments Database.";
		exit(0);
	}
	int acode, jcode;
	cout<<"\n Enter your code: ";
	cin>>acode;
	cout<<"\n Enter appointment code you wish to apply for: ";
	cin>>jcode;
	int f=0;
	while(!fj.eof())
	{
		fj.read((char*)&j,sizeof(j));
		if(j.code==jcode)
		{
			f=1;
			j.showapt();
		}
	}
	if(f==1)
	{
        int k;
		char ch;
		cout<<"\n Apply for an appointment? [Y/N]: ";
		cin>>ch;
		if(ch=='y' || ch=='Y')
		{
			while(fj.read((char*)&j,sizeof(j)))
			{
				if(j.code==jcode)
				{
					k=j.confirm();
					cout<<"\n Applied.";
				}
			}
		}
		else if (ch=='n' || ch=='N')
			cout<<"\n Not applied.";
	}
	else if(f==0)
		cout<<"\n Not Found!";
	fj.close();
	return 0;
}

void delete_apt()
{
	appnt j;
	ifstream fin("appointments.dat",ios::in|ios::binary);
	ofstream fout("temp.dat",ios::out|ios::binary);
	if(!fin || !fout)
	{
		cout<<"\n Error in opening files!";
		exit(0);
	}
	int code;
	cout<<"\n Enter the Appointment code: ";
	cin>>code;
	int found=0;
	while(!fin.eof())
	{
		fin.read((char*)&j,sizeof(j));
		if(j.returncode()!=code)
		{
			fout.write((char*)&j,sizeof(j));
		}
		else if(j.returncode()==code)
		{
			char ch;
			cout<<"\n Cancel Appointment? [Y/N]: ";
			cin>>ch;
			if(ch=='y' || ch=='Y')
				found=1;
			else if(ch=='n' || ch=='N')
			{
				cout<<"\n Appointment Not Deleted!";
				break;
			}
		}
	}
	fin.clear();
	fin.close();
	if(found==0)
	{
		cout<<"\n Appointment not found!";
	}
	else
	{
		cout<<"\n Record deleted!";
		remove("appointments.dat");
		rename("temp.dat","appointments.dat");
	}
}

void print_ser(server s)
{
	ifstream fin("servers.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n Error in opening Databases of servers!";
		exit(0);
	}
	while(fin.read((char*)&s,sizeof(s)))
	{
		s.show_ser();
	}
	fin.clear();
	fin.close();
}

void print_cl(client c)
{
	ifstream fin("clients.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n Error in opening database of clients!";
		exit(0);
	}
	while(fin.read((char*)&c,sizeof(c)))
		c.show_cl();
	fin.clear();
	fin.close();
}

void searchcl()
{
	client e;
	int code;
	int f=0;
	cout<<"\n Enter Code: ";
	cin>>code;
	ifstream fin("clients.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n Error in Opening Client Database!";
		exit(0);
	}
	while(!fin.eof())
	{
		fin.read((char*)&e,sizeof(e));
		if(e.code==code)
		{
			e.show_cl();
			f=1;
		}
	}
	fin.clear();
	fin.close();
	if(f==0)
		cout<<"\n No Record Found!";
}


void check_apt()
{
    appnt j;
    int code;
    ifstream f("appointments.dat",ios::in|ios::binary);
    if(!f)
	{
		cout<<"\n Error in Opening Appointment Database!";
		exit(0);
	}
    cout<<"\nEnter code: ";
    cin>>code;
    while(!f.eof())
    {
        f.read((char*)&j,sizeof(j));
        if(code==j.scode)
        {
            dispapt(j);
        }
    }
    f.clear();
    f.close();
}

void ser_menu()
{
	cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
	server a;
	int ch;
	do
	{
		cout<<"\n\t\t SERVER MENU"
		    <<"\n\t [1] Read Database"
		    <<"\n\t [2] Search for Appointments"
		    <<"\n\t [3] Apply for Appointments"
		    <<"\n\t [4] Check all Appointments"
		    <<"\n\t [5] Delete your account"
		    <<"\n\t [6] Exit"
		    <<"\n\t     Enter your choice [1-6]: ";
		cin>>ch;
		switch(ch)
		{
			case 1: print_ser(a);
				break;
			case 2: search_apt();
				break;
			case 3: apply_apt();
				break;
			case 4: check_apt();
                break;
            case 5: delete_apt();
				break;
			case 6: break;
			default: cout<<"\n Invalid choice!";
		}
	}
	while(ch!=6);
}

//--------------------------------------------------------------------
//---------------------Function to check job servers------------------
//--------------------------------------------------------------------
void checkser()
{
	appnt j;
	int code;
	cout<<"\n Enter Appointment code: ";
	cin>>code;
	ifstream fin("appointments.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n Error in opening Appointment Database!";
		exit(0);
	}
	while(!fin.eof())
	{
		fin.read((char*)&j,sizeof(j));
		if(j.code==code)
		{
			if(strcmp(j.status,"OPEN")==0)
			{
				j.showapply();
			}
		}
		else
			cout<<"\n Not found!";
	}
	fin.clear();
	fin.close();
}

bool isNumberString(const string& cc) {
    int len = cc.length();
    for (int i = 0; i < len; i++) {
        if (cc[i] < '0' || cc[i] > '9')
            return false;
    }
    return true;
}
void site(string c)
{
    cout<<"Issuing Network is ";
    if(c.front()=='4')
    cout<<"Visa Card\n";
    else if(c.front()=='5') 
    cout<<"Mastercard\n";
    else if(c.front()=='3' && (c.at(1)=='4' || c.at(1)=='7'))
    cout<<"American Express\n";
    else if(c.front()=='6')
    cout<<"Discover\n";
    else
    cout<<"not identified\n";
    
}
void payment()
{
    string ccNumber;
    while (true) 
    {
        cout <<"You can enter 'exit' anytime to quit." << endl;
        cout<<"Enter your credit card number ";
        cin >> ccNumber;
        if (ccNumber == "exit")
            break;
        else if (!isNumberString(ccNumber)) 
        {
            cout << "Bad input! ";
            continue;
        }
    
        int len = ccNumber.length();
        int doubleEvenSum = 0;
        for (int i = len - 2; i >= 0; i = i - 2) 
        {
            int dbl = ((ccNumber[i] - 48) * 2);
            if (dbl > 9) 
            {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }
        for (int i = len - 1; i >= 0; i = i - 2) 
        {
            doubleEvenSum += (ccNumber[i] - 48);
        }
        if(doubleEvenSum % 10 == 0)
        {
            cout <<"Valid!";
            site(ccNumber);
            break;
        }
        else
        {
            cout<<"Invalid!" << endl;
            continue;
        }
    }
        
}
void pay(int p)     
{
    int a,check=0;
    do{
    cout<<"Choose your method of payment.\n";
    cout<<"Enter 1 for cash\n";
    cout<<"Enter 2 for card\n";
    cin>>a;
    switch(a)
    {
        case 1: cout<<"Your amount is: "<<p;
                cout<<"\n\nThank you for your order!\n\n";
        break;
        case 2: cout<<"Your amount is: "<<p;
                payment();
                check=0;
        break;
        default: cout<<"Please enter a valid option\n";
                check=1;
        break;
    }
    }while(check==1);
}
void addapts()
{
	appnt a;
	ofstream fout("appointments.dat",ios::out|ios::app|ios::binary);
	if(!fout)
	{
		cout<<"\n Error in Opening Database!";
		exit(0);
	}
	a.getapt();
	fout.write((char*)&a,sizeof(a));
	fout.close();
    pay(a.price);
}

//--------------------------------------------------------------------

void delete_ser()
{
	server a;
	ifstream fin("servers.dat",ios::in|ios::binary);
	ofstream fout("temp.dat",ios::out|ios::binary);
	if(!fin || !fout)
	{
		cout<<"\n Error in opening files!";
		exit(0);
	}
	int code;
	cout<<"\n Enter the Server code: ";
	cin>>code;
	int found=0;
	while(!fin.eof())
	{
		fin.read((char*)&a,sizeof(a));
		if(a.return_scode()!=code)
		{
			fout.write((char*)&a,sizeof(a));
		}
		else if(a.return_scode()==code)
		{
			char ch;
			cout<<"\n Delete Record? [Y/N]: ";
			cin>>ch;
			if(ch=='y' || ch=='Y')
				found=1;
			else if(ch=='n' || ch=='N')
			{
				cout<<"\n Server Record Not Deleted!";
				break;
			}
		}
	}
	fin.clear();
	fin.close();
	if(found==0)
	{
		cout<<"\n Server not found!";
	}
	else
	{
		cout<<"\n Record deleted!";
		remove("servers.dat");
		rename("temp.dat","servers.dat");
	}
}
void delete_cl()
{
	client e;
	ifstream fin("clients.dat",ios::in|ios::binary);
	ofstream fout("temp.dat",ios::out|ios::binary);
	if(!fin || !fout)
	{
		cout<<"\n Error in opening files!";
		exit(0);
	}
	int code;
	cout<<"\n Enter the Client code: ";
	cin>>code;
	int found=0;
	while(!fin.eof())
	{
		fin.read((char*)&e,sizeof(e));
		if(e.returncode()!=code)
		{
			fout.write((char*)&e,sizeof(e));
		}
		else if(e.returncode()==code)
		{
			char ch;
			cout<<"\n Delete Record? [Y/N]: ";
			cin>>ch;
			if(ch=='y' || ch=='Y')
				found=1;
			else if(ch=='n' || ch=='N')
			{
				cout<<"\n Client Record Not Deleted!";
				break;
			}
		}
	}
	fin.clear();
	fin.close();
	if(found==0)
	{
		cout<<"\n client not found!";
	}
	else
	{
		cout<<"\n Record deleted!";
		remove("clients.dat");
		rename("temp.dat","clients.dat");
	}
}

void cl_menu()
{
	cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
	client e;
	int ch;
	do
	{
		cout<<"\n\t\t CLIENT MENU"
		    <<"\n\t [1] Read database"
		    <<"\n\t [2] Check Servers"
		    <<"\n\t [3] Book an Appointment"
		    <<"\n\t [4] Cancel Appointment"
		    <<"\n\t [5] Delete Account"
		    <<"\n\t [6] Exit"
		    <<"\n\t     Enter your choice [1-6]: ";
		cin>>ch;
		switch(ch)
		{
			case 1: print_cl(e);
				break;
			case 2: checkser();
				break;
			case 3: addapts();
				break;
			case 4: delete_apt();
				break;
			case 5: delete_cl();
				break;
			case 6: break;
			default: cout<<"\n Invalid choice!";
		}
    }while(ch!=6);
}
//--------------------------------------------------------------------
//------------------------------Login for User------------------------
//--------------------------------------------------------------------
void loginuser()
{
	int ch;
    int m,k;
	cout<<"\n [1] Login as server"
	    <<"\n [2] Login as client"
	    <<"\n [3] Exit"
	    <<"\n     Enter your choice [1-3]: ";
	cin>>ch;
	switch(ch)
	{
		case 1:k=login_ser();
			if(k==1)
				ser_menu();
			break;
		case 2:m=login_cl();
			if(m==1)
				cl_menu();
			break;
		case 3: break;
		default: cout<<"\n Invalid choice!";
	}
}




void searchs()
{
	server a;
	int code;
	int f=0;
	cout<<"\n Enter server Code: ";
	cin>>code;
	ifstream fin("servers.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n Error in Opening Server Database!";
		exit(0);
	}
	while(!fin.eof())
	{
		fin.read((char*)&a,sizeof(a));
		if(a.code==code)
		{
			a.show_ser();
			f=1;
		}
	}
	fin.clear();
	fin.close();
	if(f==0)
		cout<<"\n No Record Found!";
}
void searchapt()
{
	appnt j;
	int code;
	int f=0;
	cout<<"\n Enter Appointment Code: ";
	cin>>code;
	ifstream fin("appointments.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"\n Error in Opening Database!";
		exit(0);
	}
	while(!fin.eof())
	{
		fin.read((char*)&j,sizeof(j));
		if(j.code==code)
		{
			j.showapt();
			f=1;
		}
	}
	fin.clear();
	fin.close();
	if(f==0)
		cout<<"\n No Record Found!";
}


void appnt::showapply()
{
	cout<<"\n Details of the server are shown: ";

}

//********************************************************************
//------------------------ADMIN USERNAME & PASSWORD-------------------
char adminuser[20]="admin";
char adminpass[15]="passadmin";
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//------------------------------Login for Admin-----------------------
//--------------------------------------------------------------------
int enter_admin()
{
	int log=0;
	char user[20], pass[15];
	cout<<"\n Username: ";
	cin>>user;
	cout<<"\n Password: ";
	cin>>pass;
	if(strcmp(user,adminuser)!=0)
		cout<<"\n Incorrect Username!";
	else if(strcmp(pass,adminpass)!=0)
		cout<<"\n Incorrect Password!";
	else if(strcmp(user,adminuser)==0 && strcmp(pass,adminpass)==0)
	{
		cout<<"\n Admin Login successful!";
		log=1;
	}
	if(log==1)
		return log;
	else
		return 0;
}


//--------------------------------------------------------------------
//---------------------Functions for Admin Menu-----------------------
//--------------------------------------------------------------------
void admin_menu()
{
	cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
	int ch;
	do
	{
		cout<<"\n\t ADMIN MENU"
		    <<"\n [1] Delete Server Database"
		    <<"\n [2] Delete Client Database"
		    <<"\n [3] Delete Appointment Database"
		    <<"\n [4] Display All Server Records"
		    <<"\n [5] Display All Client Records"
		    <<"\n [6] Display All Appointment Records"
		    <<"\n [7] Search for an Server"
		    <<"\n [8] Search for an Client"
		    <<"\n [9] Search for a Appointment"
		    <<"\n [10] Exit"
		    <<"\n     Enter your choice [1-10]: ";
		cin>>ch;
		server a;
		client e;
		appnt j;
		switch(ch)
		{
			case 1: delete_ser();
				break;
			case 2: delete_cl();
				break;
			case 3: delete_apt();
				break;
			case 4: print_ser(a);
				break;
			case 5: print_cl(e);
				break;
			case 6: dispapt(j);
				break;
			case 7: searchs();
				break;
			case 8: searchcl();
				break;
			case 9: searchapt();
				break;
			case 10: break;
			default: cout<<"\n Invalid Choice!";
		}
	}
	while(ch!=10);
}

//--------------------------------------------------------------------
//--------------------------------MAIN MENU---------------------------
//--------------------------------------------------------------------
void main_menu()
{
	int ch;
	do
	{
	    cout<<"\n=====================================================";
        cout<<"\n\t\t\t\t ROKOVID || रोकोVID";
        cout<<"\n=====================================================";
		cout<<"\n\t\t\t MAIN MENU";
        cout<<"\n\t\t [1] Enter as User";
        cout<<"\n\t\t [2] Enter as Admin";
        cout<<"\n\t\t [3] Exit.";
        cout<<"\n\t\t     Enter your choice [1-3]: ";
		cin>>ch;
		if(ch==1)
		{
			int c;
			cout<<"\n\t [1] Register"
			    <<"\n\t [2] Login to your account"
			    <<"\n\t [3] Back to Main Menu"
			    <<"\n\t   Enter your choice [1-3]: ";
			cin>>c;
			switch(c)
			{
				case 1: register_user();
					break;
				case 2: loginuser();
					break;
				case 3: break;
				default: cout<<"\n Invalid choice!";
			}
		}
		else if(ch==2)
		{
			int d=enter_admin();
			if(d==1)
				admin_menu();
		}
		else if(ch==3)
			exit(0);
	}
	while(ch!=3);
}

//--------------------------------------------------------------------
//------------------------------Main Function-------------------------
//--------------------------------------------------------------------
int main()
{
	cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
	main_menu();
	return 0;
}
