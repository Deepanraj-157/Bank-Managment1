#include<iostream>
using namespace std;
int i=0;
class BankAccount{
	private:
		int acno;
		string name;
		double balance;
	public:
		void createaccount(long int no)
		{
			acno=no;
			cout<<"enter account holder name:";
			cin>>name;
			balance=0;
			
		}
		void credit(double c)
		{
			
			cout<<"----------------------------------"<<endl;
			cout<<"your account is credited "<<c;
			balance+=c;
			cout<<"\navailabe balance "<<balance<<endl;
			cout<<"----------------------------------"<<endl<<"\n";
		}
		void debit(double d)
		{
			if(d>balance)
			{
				cout<<"----------------------------------"<<endl;
				cout<<"insufficient amount!\n";
				cout<<"----------------------------------"<<endl<<"\n";
				
			}
			else{
			cout<<"----------------------------------"<<endl;
			cout<<"your account is debited "<<d;
			balance-=d;
			cout<<"\navailabe balance "<<balance<<endl;
			cout<<"----------------------------------"<<endl<<"\n";
		    }
		}
		void viewdetails()
		{
			cout<<"----------------------------------"<<endl;
			cout<<"Account Number: "<<acno<<endl;
			cout<<"Holder Name:"<<name<<endl;
			cout<<"Balance:"<<balance<<endl;						
			cout<<"----------------------------------"<<endl<<"\n";

		}
//		void checkbalance(long int a)
//		{
//			for(int j=0;j<i;j++)
//			{
//				if(BankAccount.j acno == a)
//				{
//					BankAccount[j].viewdetails();
//				}	
//			}	
//		}
};
int main()
{
	BankAccount a[100];
	int loop=1,x,ac,j=0;
	int an=125793200;
	double amount=0;
	while(loop == 1)
	{
		cout<<"1.Create New Account"<<endl;
		cout<<"2.Check Bank balance"<<endl;
		cout<<"3.Credit Amount"<<endl;
		cout<<"4.Debit Amount"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your option(1,2,3,4,5):";
		cin>>x;
		if(x == 1)
		{
			a[i].createaccount(an+i);
			cout<<"New account is created "<<endl;
			a[i].viewdetails();
			i++;
		}
		else if(x == 2)
		{
			cout<<"Enter your Account Number:";
			cin>>ac;
			for(j=0;j<i;j++)
			{
				if(an+j == ac)
				{
					a[j].viewdetails();
					break;
				}
			}
			if(j == i)
			{
				cout<<"----------------------------------"<<endl;
				cout<<"Your Account Number is invalid"<<endl;
				cout<<"----------------------------------"<<endl<<"\n";
			}

			
		}
		else if(x == 3)
		{
			cout<<"Enter your Account Number:";
			cin>>ac;
			for(int j=0;j<i;j++)
			{
				if(an+j == ac)
				{
					cout<<"Enter your credit amount:";
					cin>>amount;
					a[j].credit(amount);
					break;
				}
			}
			if(j == i)
			{
				cout<<"----------------------------------"<<endl;
				cout<<"Your Account Number is invalid"<<endl;
				cout<<"----------------------------------"<<endl<<"\n";
			}
		}
		else if(x == 4)
		{
			cout<<"Enter your Account Number:";
			cin>>ac;
			for(int j=0;j<i;j++)
			{
				if(an+j == ac)
				{
					cout<<"Enter your debit amount:";
					cin>>amount;
					a[j].debit(amount);
					break;
				}
			}
			if(j == i)
			{
				cout<<"----------------------------------"<<endl;
				cout<<"Your Account Number is invalid"<<endl;
				cout<<"----------------------------------"<<endl<<"\n";
			}
		}
		else if(x == 5)
		{
			loop=0;
		}
	}
}