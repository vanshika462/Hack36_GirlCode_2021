#include<bits/stdc++.h>
#include<string.h>
using namespace std;

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
    if(c.front()==4)
    cout<<"Visa Card\n";
    else if(c.front()==5) 
    cout<<"Mastercard\n";
    else if(c.front()==3 && (c.at(1)==3 || c.at(1)==7))
    cout<<"American Express\n";
    else if(c.front()==6)
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
int main()      // make sure to go back to payment portal if check=1
{
    int a,check=0;
    cout<<"Choose your method of payment.";
    cout<<"Enter 1 for cash\n";
    cout<<"Enter 2 for card\n";
    cin>>a;
    switch(a)
    {
        case 1: cout<<"Your amount is \n";
                cout<<"Thank you for your order!\n";
        break;
        case 2: payment();
                check=0;
        break;
        default: cout<<"Please enter a valid option";
                check=1;
        break;
    }
}
