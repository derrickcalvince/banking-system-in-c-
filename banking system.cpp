#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<ctime>
#include <cstdlib>
using namespace std;

// Base class
class bankAccount {
protected:
    int acno;
    char name[50];
    int deposit;
    char type;
public:
    // Pure virtual functions for polymorphism
    virtual void create_account() = 0;  // Abstraction
    virtual void show_account() const = 0;
    virtual void modify() = 0;
    virtual void dep(int) = 0;
    virtual void draw(int) = 0;
    virtual void report() const = 0;
    virtual int retacno() const = 0;
    virtual int retdeposit() const = 0;
    virtual char rettype() const = 0;
    virtual ~bankAccount() {}  // Virtual destructor
};

// Derived class for savings account
class savingsAccount : public bankAccount {
public:
    void create_account() override;	
    void show_account() const override;	
    void modify() override;	
    void dep(int) override;	
    void draw(int) override;	
    void report() const override;	
    int retacno() const override;	
    int retdeposit() const override;	
    char rettype() const override;	
};

void savingsAccount::create_account() {
    cout << "\nEnter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nEnter Type of The account (C/S) : ";
    cin >> type;
    type = toupper(type);

    srand(time(NULL)); 
    acno = 100000000000 + (rand() % 900000000000); 

    cout << "\nAccount Number : " << acno;
    cout << "\nAccount Holder Name : " << name;
    cout << "\nType of Account : " << type;

    cout << "\nEnter The Initial amount (>=500 for Saving and >=1000 for current) : ";
    cin >> deposit;
    cout << "\n\n\nAccount Created..";
}

void savingsAccount::show_account() const {
    cout<<"\nAccount No. : "<<acno;
    cout<<"\nAccount Holder Name : "<<name;
    cout<<"\nType of Account : "<<type;
    cout<<"\nBalance amount : "<<deposit;
}

void savingsAccount::modify() {
    cout<<"\nAccount No. : "<<acno;
    cout<<"\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nModify Type of Account : ";
    cin>>type;
    type=toupper(type);
    cout<<"\nModify Balance amount : ";
    cin>>deposit;
}
    
void savingsAccount::dep(int x) {
    deposit += x;
}

void savingsAccount::draw(int x) {
    deposit -= x;
}

void savingsAccount::report() const {
    cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

int savingsAccount::retacno() const {
    return acno;
}

int savingsAccount::retdeposit() const {
    return deposit;
}

char savingsAccount::rettype() const {
    return type;
}

// Derived class for current account
class currentAccount : public bankAccount {
public:
    void create_account() override;	
    void show_account() const override;	
    void modify() override;	
    void dep(int) override;	
    void draw(int) override;	
    void report() const override;	
    int retacno() const override;	
    int retdeposit() const override;	
    char rettype() const override;	
};

void currentAccount::create_account() {
    cout << "\nEnter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nEnter Type of The account (C/S) : ";
    cin >> type;
    type = toupper(type);

    srand(time(NULL)); 
    acno = 100000000000 + (rand() % 900000000000); 

    cout << "\nAccount Number : " << acno;
    cout << "\nAccount Holder Name : " << name;
    cout << "\nType of Account : " << type;

    cout << "\nEnter The Initial amount (>=500 for Saving and >=1000 for current) : ";
    cin >> deposit;
    cout << "\n\n\nAccount Created..";
}

void currentAccount::show_account() const {
    cout<<"\nAccount No. : "<<acno;
    cout<<"\nAccount Holder Name : "<<name;
    cout<<"\nType of Account : "<<type;
    cout<<"\nBalance amount : "<<deposit;
}

void currentAccount::modify() {
    cout<<"\nAccount No. : "<<acno;
    cout<<"\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"\nModify Type of Account : ";
    cin>>type;
    type=toupper(type);
    cout<<"\nModify Balance amount : ";
    cin>>deposit;
}
    
void currentAccount::dep(int x) {
    deposit += x;
}

void currentAccount::draw(int x) {
    deposit -= x;
}

void currentAccount::report() const {
    cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

int currentAccount::retacno() const {
    return acno;
}

int currentAccount::retdeposit() const {
    return deposit;
}

char currentAccount::rettype() const {
    return type;
}

void displayMenu() {
    cout << "\n\n";
    cout << "===============================================\n";
    cout << "|            BANK MANAGEMENT SYSTEM           |\n";
    cout << "|               MAIN MENU                     |\n";
    cout << "===============================================\n";
    cout << "| 1. NEW ACCOUNT                              |\n";
    cout << "| 2. DEPOSIT AMOUNT                           |\n";
    cout << "| 3. WITHDRAW AMOUNT                          |\n";
    cout << "| 4. BALANCE ENQUIRY                          |\n";
    cout << "| 5. ALL ACCOUNT HOLDER LIST                  |\n";
    cout << "| 6. CLOSE AN ACCOUNT                         |\n";
    cout << "| 7. MODIFY AN ACCOUNT                        |\n";
    cout << "| 8. EXIT                                     |\n";
    cout << "===============================================\n\n";
    cout << "Select Your Option (1-8): ";
}

void create_new_account(bankAccount* acc) {
    acc->create_account();  // Polymorphism
}

void deposit_amount(bankAccount* acc) {
    int acno, amount;
    cout << "\nEnter The account No. : "; 
    cin >> ac
