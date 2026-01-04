#include<iostream>
#include<vector>
#include<string>
using namespace std;

class account {
	private:
		int accountNo;
		string name;
		double balance;
	public:
		account(int accNo, string accName, double bal=0.0){
			accountNo=accNo;
			name=accName;
			balance=bal;
		}
		int getAccountNo(){
			return accountNo;
		}
		string getName(){
			return name;
		}
		double getBalance(){
			return balance;
		}
		void credit(double amount){
			if(amount<0){
				cout<<"Invalid credit amount!"<<endl;
				return;
			}

			balance+=amount;
			cout<<"Amount credited successfuly."<<endl;
		}
		void debit(double amount){
			if(amount<=0 || amount>balance){
				cout<<"Invalid of insufficient balance!"<<endl;
				return;
			}
			balance-=amount;
			cout<<"Amount debited successfully. "<<endl;
			
		}
		void display(){
			cout<<"-----------------------------------------------"<<endl;
			cout<<"Account Number : "<<accountNo<<endl;
			cout<<"Account Holder : "<<name<<endl;
			cout<<"Balance : "<<balance<<endl;
			cout<<"-----------------------------------------------"<<endl;
		}
};

class bank {
	private:
		vector<account> accounts;
		int nextAccountNo;

		
		int findAccount(int accNo){
			for(int i=0;i<accounts.size();i++){
				if(accounts[i].getAccountNo() == accNo){
					return i;
				}
			}
			return -1;
		}
		
	public:
		bank() {
        	nextAccountNo = 125793200;
		}
		void createAccount(){
			string name;
			cout<<"Ente Account Holder Name : ";
			cin>>name;
			accounts.push_back(account(nextAccountNo++,name));
			cout<<"Account created successfully!"<<endl;
			accounts.back().display();
		}
		void checkBalance(){
			int accNo;
			cout<<"Ente Account Number : ";
			cin>>accNo;
			int index = findAccount(accNo);
			if(index == -1){
				cout<<"Account not found!"<<endl;
			}
			else{
				accounts[index].display();
			}
		}
		void creditAmount(){
			int accNo;
			double amount;
			cout<<"Ente Account Number : ";
			cin>>accNo;
			int index = findAccount(accNo);
			if(index == -1){
				cout<<"Account not found!"<<endl;
				return;
			}
			cout<<"Enter Credit Amount : ";
			cin>>amount;
			accounts[index].credit(amount);
		}
		void debitAmount(){
			int accNo;
			double amount;
			cout<<"Ente Account Number : ";
			cin>>accNo;
			int index = findAccount(accNo);
			if(index == -1){
				cout<<"Account not found!"<<endl;
				return;
			}
			cout<<"Enter Debit Amount : ";
			cin>>amount;
			accounts[index].debit(amount);
		}
		void menu(){
			int choice;
			do {
				cout<<"\n=======BANK MANAGEMENT SYSTEM======="<<endl;
				cout<<"1. Create new account "<<endl;
				cout<<"2. Check Balance "<<endl;
				cout<<"3. Credit Amount "<<endl;
				cout<<"4. Debit amount "<<endl;
				cout<<"5. Exit "<<endl;
				cout<<"Enter choice : ";
				cin>>choice;
				
				switch(choice){
					case 1:{
						createAccount();
						break;
					}
					case 2:{
						checkBalance();
						break;
					} 
					case 3:{
						creditAmount();
						break;
					}
					case 4:{
						debitAmount();
						break;
					}
					case 5:{
						cout<<"Thank you for using Bank System!"<<endl;
						break;
					}
					default: cout<<"Invalid choice!"<<endl;
				}
				
			}while(choice != 5);
		}
	
};

int main(){
	bank Bank;
	Bank.menu();
	
	return 0;
}
