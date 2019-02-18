#include<string>
using namespace std;

class bankAccount
{
	string name;
	int number;
	float balance;
	float bal_limit;
	float *transaction;
	int trans_limit;
	int no_of_trans;
	void increaseTranCapacity();
public:
	bankAccount();
	~bankAccount();
	bankAccount(string, int);
	void print();
	void withDraw(float);
	void changeBalance(float);
	void addTransaction(float);
	void deposit(float);
	void changeBalanceLimit(float);

};

