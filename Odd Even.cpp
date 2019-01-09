#include <iostream>
using namespace std;

void oddEven(int number);

int main() {
	int number;
	cin >> number;
	oddEven(number);
}

void oddEven(int number) {
	int number_ = number;
	if (number < 1)
		return;
	if (number % 2 == 0)
		number--;

	cout << number << endl;
	oddEven(number - 2);
	if (number > 1)
		cout << number-1 << endl;
	if (number == number_-1)
		cout << number_ << endl;
}