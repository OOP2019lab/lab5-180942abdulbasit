#include "Q1_180942_header.h"
#include <iostream>
using namespace std;
 
bankAccount::bankAccount()
{
	string n;
	int a;
	cout<<"Enter name: "<<endl;
	cin>>n;
	name=n;
	cout<<"Enter id: "<<endl;
	cin>>a;
	number=a;
	balance=0;
	bal_limit=200000;
	trans_limit=10;
	no_of_trans=0;
	transaction=nullptr;
	transaction=new float[trans_limit];
}
bankAccount::bankAccount(string str, int n)
{
	name=str;
	if (n>0)
	    number=n;
	else
		number=-1;
	balance=0;
	bal_limit=200000;
	no_of_trans=0;
	trans_limit=10;
	transaction=nullptr;
	transaction=new float[trans_limit];
}
void bankAccount::print()  //prints 
{
	if (name!="")
		cout<<"Name: "<<name<<endl;
	if (number>0)
		cout<<"Account Number: "<<number<<endl;
	cout<<"Balance: "<<balance<<endl;
	cout<<"No of transactions: "<<no_of_trans<<endl;
	if (no_of_trans>0)
	{
		cout<<"Transactions: ";
		for(int i=0; i<no_of_trans;i++)
			cout<<transaction[i]<<" , ";
		cout<<endl;
	}
}
void bankAccount::withDraw(float a) //withdraw and changes the balance and transaction array accordingly
{
	if(a<balance)
	{
		changeBalance(-a);
		addTransaction(-a);
		cout<<"Transaction Successful"<<endl;
	}
	else
		cout<<"Transaction Unsuccessful: Insufficient Balance"<<endl;


}
void bankAccount::changeBalance(float a) //chnage balance amount
{

	balance=balance+a;
}
void bankAccount::addTransaction(float a) //add values to transaction array
{
	if(no_of_trans<trans_limit)
	{
		transaction[no_of_trans]=a;
		no_of_trans++;
	}
	else
	{
		 increaseTranCapacity();
		 addTransaction(a);
	}

}
void bankAccount::increaseTranCapacity()  //increase size of dynamic array
{
	trans_limit=trans_limit*2;
	float *temp;
	temp=new float[trans_limit];
	for (int i=0; i<no_of_trans;i++)
		temp[i]=transaction[i];
	delete[] transaction;
	transaction=temp;
}
void bankAccount::deposit(float a) //deposits and changes the balance and transaction array accordingly
{
	if(a+balance<=bal_limit)
	{
		changeBalance(a);
		addTransaction(a);
		cout<<"Transaction Successful"<<endl;
	}
	else
		cout<<"Transaction Unsuccessful:Balance Limit Reached"<<endl;
}
void bankAccount::changeBalanceLimit(float a) //changes the balance limit
{
	if(a>bal_limit)
		bal_limit=a;
}
bankAccount::~bankAccount()
{
	delete[] transaction;
}
