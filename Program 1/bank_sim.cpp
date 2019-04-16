//Landon Volkmann
//Student Num: 16221373
//CS 201
//Program 1
//02/04/18


#include<iostream>
#include<string>
using namespace std;

//variable declarations
double acct_balance = 1000000.00;
double house_cost, deposit_amnt;
int choice, credit_score;
bool running = true;
bool check;

//Menu
string menu = "\
Please choose a service : \n \
1: Withdraw\n \
2: Deposit\n \
3: Apply for a loan\n \
0: Exit System\n" ;

//Function declarations
double withdraw_func(double balance);
//Precondition: Pass in double balance
//Postcondition: Return double new balance (original balance minus withdraw amount (where 0 < withdraw < balance))
double deposit_func(double balance);
//Precondition: Pass in double balance
//Postcondition: Return double new balance (original balance plus deposit amount (where deposit > 0))
void credit_score_func();
//Precondition: No parameters taken
//Postcondition: No return; Outputs monthly payment plan based on internal input of user (credit score, loan size, and payment period))

//Main Program
int main()
{
	//Set precision
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Welcome to Volkmann and Volkman Banking Services\n";
	while (running)
	{
		//Menu
		cout << "\n";
		cout << "Account Balance: $" << acct_balance << endl;
		cout << menu;
		cin >> choice;
		check = cin.fail();

		//Function calls & Data validation
		if (check)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid selection. Please try again.\n";
		}
		else if (choice == 1)
			acct_balance = withdraw_func(acct_balance);
		else if (choice == 2)
			acct_balance = deposit_func(acct_balance);
		else if (choice == 3)
			credit_score_func();
		else if (choice == 0)
		{
			cout << "Please come again!" << endl;
			running = false;
		}
		else
			cout << "Invalid selection. Please try again.\n";
	}

	system("Pause");
	return 0;
}

//Function Definitions

double withdraw_func(double balance)
{
	//Variable Declarations
	bool valid_prop;
	double withdraw_prop, new_balance;

	//Input
	cout << "How much would you like to withdraw?" << endl;
	cin >> withdraw_prop;
	
	//Validate
	while ((withdraw_prop > balance) || (withdraw_prop <0))
	{
		cout << "Withdraw request invalid. Please try again." << endl;
		cin >> withdraw_prop;
	}

	//New balance calc
	new_balance = balance - withdraw_prop;

	//Output results
	cout << "Beginning Balance: $" << balance << endl;
	cout << "Withdrawn Amount: $" << withdraw_prop << endl;
	cout << "New Balance: $" << new_balance << endl;

	return new_balance;
}
double deposit_func(double balance)
{
	//Variable declarations
	bool valid_prop;
	double deposit_prop, new_balance;

	//Input
	cout << "How much would you like to deposit?" << endl;
	cin >> deposit_prop;

	//Validate
	while (deposit_prop < 0)
	{
		cout << "Deposit amount invalid. Please try again." << endl;
		cin >> deposit_prop;
	}

	//New balance calc
	new_balance = balance + deposit_prop;

	//Output results
	cout << "Beginning Balance: $" << balance << endl;
	cout << "Deposit Amount: $" << deposit_prop << endl;
	cout << "New Balance: $" << new_balance << endl;

	//Return
	return new_balance;
}
void credit_score_func()
{
	//Variable declarations
	int credit_score, payment_period;
	double loan, rate, monthly_payment;

	//Inputs
	cout << "Please enter credit score: ";
	cin >> credit_score;
	cout << "Please enter loan size: ";
	cin >> loan;
	cout << "Please enter how many months you will pay the loan back in: ";
	cin >> payment_period;
	cout << "\n";

	//Get rate
	if (credit_score <= 500)
		rate = .05;
	else if ((credit_score >= 501) && (credit_score <= 700))
		rate = .02;
	else
		rate = .01;

	//Calculate monthly payment
	monthly_payment = (loan * pow((1 + rate), (payment_period / 12))) / payment_period;

	//Output
	cout << "Your monthly payment will be $" << monthly_payment << endl;


}