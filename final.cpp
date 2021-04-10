#include<bits/stdc++.h>
using namespace std;

class client        
{
  private:
      string username;
      string client_name;
      string password;
  public:
      void getdata(string uname);
      void showdata();
      string return_username();
      int search(string nm);
};
client cl;

void client::getdata(string uname)
{
    cout<<"\n Enter name: ";
	cin>>cl.client_name;
	cout<<"\n Enter password: ";
    cin>>cl.password;
    cl.username=uname;
}

void client::showdata()
{
    cout<<"show client details";
}

string client::return_username()
{
  return cl.username;
}

int client::search(string nm)
{
    client c;
    fstream fin;
    fin.open("Client.dat",ios::in|ios::out|ios::binary|ios::app);
    while(!fin.eof())
    {
        fin.read((char*)&c,sizeof(c));
        if(c.return_username()==nm)
        {
            cout<<"Username already exists!\n";
            return 1;
            break;
        }
        else
        {
            c.getdata(nm);
            fin.write((char*)&c,sizeof(c));
            break;
        }
    }
    fin.close();
}

void clregaccept()    //client registration
{
  string uname;
  int t;
  do
  {
        t=0;
        cout<<"\nEnter username: ";
        cin>>uname;
        t=cl.search(uname);
  }while(t==1);
}

void client_page()  //if user chooses client
{
	int choice;
	cout<<"\n Enter 1 to register";
	cout<<"\n Existing user? Enter 2 to login";
	cin>>choice;
	switch(choice)
	{
		case 1: clregaccept();
            break;
		case 2: 
            break;
        default:
            cout<<"Enter valid choice!";
            break;
        }		
}


int main()
{
	cout<<"\n\t\t <SITE NAME>";
	cout<<"\n\t\t 1. Client\n";
    cout<<"\n\t\t 2. Server\n";
    cout<<"\n\t\t 3. Admin\n";
	int a;
    cin>>a;
	switch(a)
	{
		case 1: client_page();
				break;
		case 2: server_page();
				break;
		case 3: admin_page();
				break;
		default:
      cout<<"Enter valid option!";
      break;
	}
	return 0;
}
