#include<iostream>
using namespace std;

int Factorial(int a)
{
	if (a <= 1)
	{
		return 1;
	}

	return a * Factorial(a - 1);
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << Factorial(a) / (Factorial(b) * Factorial(a - b)) << endl;

	return 0;
}