
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
#include<string>
class bank{
public:
    int r;//reference for balance
    int WITHDRAW(int ba){
        int wr;
        cout<<"ENTER THE AMOUNT TO BE WITHDRAWN:";
        cin>>wr;
        if (wr>ba){
            cout<<"NOT ENOUGH BALANCE"<<endl;
            r=ba;
            return ba;
            
        }
        else{
            ba=ba-wr;
            cout<<"THE AMOUNT IS WITHDRAWN "<<endl;
            r=ba;
            cout<<"THE BALANCE IS :"<<ba<<endl;
            return ba;
        }
    }
    int DEPOSIT(int ba){
        int dp;
        cout<<"ENTER THE AMOUNT TO BE DEPOSITED"<<endl;
        cin>>dp;
        r=r+dp;
        
        cout<<"THE BALANCE IS :"<<r<<endl;
        
        return r;
        
    }
    void DISPLAY(){
        cout<<"THE BALANCE IS "<<r<<endl;
    }
    
};

int main(){
    bank ban;
    string q="y";
    while (q=="y"){
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                 WELCOME                                                                 "<<endl;
        cout<<"                                   TO                                                                    "<<endl;
        cout<<"                              CENTRAL BANK                                                              "<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"MAIN MENU"<<endl;
        cout<<endl;
        cout<<"1. REGISTER"<<endl;
        cout<<endl;
        cout<<"2.LOGIN "<<endl;
        int a,b,c;
        
        cout<<"ENTER  YOUR CHOICE:"<<endl;
        cin>>a;
        
        if (a==1){
            
            string username, password;
            int balance;
            long long int accno;
            
            cout << "Registration: " << endl;
            cout << endl;
            accno=rand();
            cout<<"this is your account no:"<<accno<<endl;
            string acc=to_string(accno);
            
            
            
            cout << "Select a username: ";
            cin >> username;
            cout << "Select a password: ";
            cin >> password;
            cout<<"enter the amount to be deposit"<<endl;
            cin>>balance;
            ofstream file1;
            file1.open(username + ".txt");
            file1 << acc << endl << password<<endl<<username<<endl<<balance;
            file1.close();
            while (q=="y"){
                cout << "Welcome " << username  << endl;
                cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                
                cout<<endl;
                cout<<"1. WITHDRAW"<<endl;
                cout<<endl;
                cout<<"2. DEPOSIT"<<endl;
                cout<<endl;
                cout<<"3. CHECK BALANCE"<<endl;
                cout<<endl;
                cout<<"Enter your choice"<<endl;
                cin>>b;
                cout<<endl;
                if (b==1){
                    ban.WITHDRAW(balance);
                    cout<<endl;
                    cout<<"Do u want to continue(y/n)"<<endl;
                    cin>>q;
                }
                else if (b==2){
                    ban.DEPOSIT(balance);
                    cout<<endl;
                    cout<<"Do u want to continue(y/n)"<<endl;
                    cin>>q;
                }
                else{
                    ban.DISPLAY();
                    cout<<endl;
                    cout<<"Do u want to continue(y/n)"<<endl;
                    cin>>q;
                }}
        }
        else if(a==2){
            while(q=="y"){
                string username, password,vv;
                string un, pw,jj,qq;// comparison strings
                int ba;
                
                cout << "Enter a accno: ";
                cin >> username;
                cout<<"Enter username:";
                cin>>vv;
                cout << "Enter a password: ";
                cin >> password;
                
                ifstream read(vv + ".txt"); // ifstream reads a file
                getline(read, un); // reads the account no
                getline(read, pw);//reads the password
                getline(read,qq);//reads the username
                getline(read, jj);// reads the balance
                
                
                if(un != username && pw != password) // if both un & username and pw & password are not  same,
                    
                   
                {
                    system("clear");
                    cout << endl;
                    cout << "Invalid login!" << endl;
                    main();
                    return 0;
                    
                }
                else{
                    cout<<"LOGGED IN"<<endl;
                    cout << "Welcome " << qq  << endl;
                    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
                    
                    ba=stoi(jj);
                    }
                    while (q =="y"){
                        
                        cout<<endl;
                        cout<<"1. WITHDRAW"<<endl;
                        cout<<endl;
                        cout<<"2. DEPOSIT"<<endl;
                        cout<<endl;
                        cout<<"3. CHECK BALANCE"<<endl;
                        cout<<endl;
                        cout<<"Enter your choice"<<endl;
                        cin>>b;
                        if (b==1){
                            ban.WITHDRAW(ba);
                            cout<<"Do u want to continue(y/n)"<<endl;
                            cin>>q;
                        }
                        else if (b==2){
                            ban.DEPOSIT(ba);
                            cout<<"Do u want to continue(y/n)"<<endl;
                            cin>>q;
                        }
                        else{
                            ban.DISPLAY();
                            cout<<"Do u want to continue(y/n)"<<endl;
                            cin>>q;
                        }}
                    
                }
                
            }
            
            
            
            
            
        }
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                               THANK  YOU                                                                                 "<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    return 0;
        
    }
