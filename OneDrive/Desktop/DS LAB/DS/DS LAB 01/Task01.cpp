#include <iostream>

using namespace std;

class BankAccount{
    private:
        string accName;
        double accBalance;
    public:
    // Default construcor
    BankAccount(){
        accBalance=0;
        accName="Account Name Not Specified";
    };
    
    // Parameterized construcor
    BankAccount(string _accName,double _accBalance) : accName(_accName),accBalance(_accBalance) {};
    
    // Copy construcor
    BankAccount(BankAccount &obj) : accName(obj.getAccName()), accBalance(obj.getAccBalance()){};

    // getters/setters
    void setAccBalance(double accBalance){
        this->accBalance=accBalance;
    }
    double getAccBalance(void){
        return accBalance;
    }

    void setAccName(string accName){
        this->accName=accName;
    }
    string getAccName(void){
        return accName;
    }

    // dedeuction function
    void deductAccBalance(double amount){
        accBalance-=amount;
    }

    // display function
    void displayAccBalance(void){
        cout<<endl<<"Account Name: "<<accName<<endl;
        cout<<"Current Account Balance: "<<accBalance<<endl;
    }

    //destructor
    ~BankAccount(){
        //no dynamic variable
    }
};


int main(){

    BankAccount account1;
    account1.setAccName("Account 01");
    account1.displayAccBalance();
    
    BankAccount account2("Account 02",1000);
    account2.displayAccBalance();
    
    
    BankAccount account3(account2);
    account3.setAccName("Account 03");
    account3.deductAccBalance(200);
    
    account3.displayAccBalance();
    cout<<"Checking if any abnormalities in Account 2";
    account2.displayAccBalance();

    return 0;
}