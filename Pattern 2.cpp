/*
Print the following Pattern using Recursions. If input is 3 print
*	*	*
*	*
*

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
	for (int i = 0; i< number; i++)
		cout << "*\t";
	cout  << "\n";
	print_triangle(number-1);
}