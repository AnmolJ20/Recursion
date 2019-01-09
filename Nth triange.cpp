/*
print the nth triangle of the input.
if input is 3 print 1+2+3 i.e. 6
similarly, if input is 5 print 1+2+3+4+5  i.e. 15

*/

#include <iostream>
using namespace std;

int print_triangle(int number);

int main() {
	int number;
	cin >> number;
	cout << print_triangle(number);
}

int print_triangle(int number) {
	if (number <= 1)
		return 1;
	return number + print_triangle(number-1);
}