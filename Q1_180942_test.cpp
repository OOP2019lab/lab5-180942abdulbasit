#include "Q1_180942_header.h"
#include <iostream>
using namespace std;
void test()
{
	bankAccount myAccount("John Doe",549002);
	myAccount.print();

	myAccount.withDraw(2000);
	myAccount.print();
	
	myAccount.deposit(250000);
	myAccount.print();
	
	myAccount.deposit(50000);
	myAccount.print();
	
	myAccount.deposit(500);
	myAccount.withDraw(50);
	myAccount.deposit(200);
	myAccount.withDraw(70);
    myAccount.deposit(5000);
	myAccount.withDraw(55);
    myAccount.deposit(500);
	myAccount.withDraw(50);
	myAccount.deposit(500);
	myAccount.withDraw(50);
    myAccount.print();
	
	myAccount.changeBalanceLimit(1000000);
	myAccount.deposit(250000);
	myAccount.print();
}
int main()
{
	test();

	return 0;
}
