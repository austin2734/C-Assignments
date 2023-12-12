#include<iostream>
#include<iomanip>
using namespace std;

struct Account
{
	string acct_num;
	double acct_bal{}, int_rate{}, avg_monthly_bal{};
};

int main(){

Account my_account = {"AZ42137", 4512.59, 4, 4217.07};


cout << "Account Number: " << my_account.acct_num << endl
     << "Account Balance: " << setprecision(2) << fixed << "$" << my_account.acct_bal << endl
     << "Interest rate: " << my_account.int_rate << "%" << endl
     << "Avgerage Monthly Balance: " << "$" << my_account.avg_monthly_bal;
return 0;
}