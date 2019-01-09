/*
Print the following Pattern using recursion
if n input is 3
*
*	*
*	*	*

*/

#include <iostream>
using namespace std;

void print_triangle(int number);

int main() {
	int number;
	cin >> number;
	print_triangle(number);
}

void print_triangle(int number) {
	if (number <= 0)
		return;
	print_triangle(number-1);
	for (int i = 0; i< number; i++)
		cout << "*\t";
	cout  << "\n";
}