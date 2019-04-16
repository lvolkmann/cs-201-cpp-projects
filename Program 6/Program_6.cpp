//Landon Volkmann
//04-16-18
//CS 201
//Program 6

#include<iostream>
using namespace std;

void main()
{
	//Function declarations
	int iter_induction(int n);
	//Precondition: n >= 1
	//Postcondition: Return 1^2 + 2^2 + 3^2 + ... + n^2
	int rec_induction(int n);
	//Precondition: n >= 1
	//Postcondition: Return Q(n-1) + n^2
	void rec_reverse(int *a, int size);
	//Precondition: Initialized array of type int where size == size of the array
	//Postcondition: Elements of array are ordered in reverse

	//Variables for input
	int n;
	int a[100];
	int size;

	//Induction section
	cout << "Part A" << endl;
	cout << "Q(n) = 1^2 + 2^2 + 3^2 + ... + n^2 = Q(n-1) + n^2" << endl;
	cout << "n = ";
	cin >> n;
	cout << endl << "Calculating..." << endl;

	//Call iterative for LHS and recursive for RHS
	if (n >= 1)
		cout << iter_induction(n) << " = " << rec_induction(n) << endl;
	else
		cout << "n must be greater than or equal to 1" << endl;

	cout << endl;

	//Reverse section
	cout << "Part B" << endl;
	cout << "Size of the array: ";
	cin >> size;
	cout << endl << "Enter each value on it's own line..." << endl;

	for (int i = 0; i < size; i++)
		cin >> a[i];

	cout << endl;
	cout << "Array before recursive reverse..." << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;

	//Recursive reverse call
	rec_reverse(a, size);

	cout << "Array after recursive reverse..." << endl;
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;

	system("pause");
}

//Function Definitions
int iter_induction(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += (i * i);
	return sum;
}

int rec_induction(int n)
{
	if (n <= 1)
		return 1;
	else
		return (n * n) + rec_induction(n - 1);
}

void rec_reverse(int *a, int size)
{

	if (size <= 1)
		return;
	else
	{
		int temp = a[0];
		a[0] = a[size - 1];
		a[size - 1] = temp;

		rec_reverse((a + 1), size - 2);
	}
}