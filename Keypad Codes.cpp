#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void keypadCodes(int number, string code, int alpha[2][9], bool flag);
void count(bool flag);
int curNumber(int &number);

int main() {
	int number;
	int alpha[2][9] = {3, 3, 3, 3, 3, 4, 3, 2, 2,
					   0, 3, 6, 9, 12, 15, 19, 22, 24};
	cin >> number;
	keypadCodes(number, "", alpha, false);
	count(true);
	cout << endl;
	keypadCodes(number, "", alpha, true);
}

void keypadCodes(int number, string code, int alpha[2][9], bool flag) {
	if (number == 0)
		return;
	int curNumber_ = curNumber(number);
	for (int i = 0; i < alpha[0][curNumber_ - 1]; i++) {
		if (number == 0 && flag)
			cout << code << char(alpha[1][curNumber_ - 1] + i + 97);
		keypadCodes(number, code + (char(alpha[1][curNumber_ - 1] + i + 97)), alpha, flag);
		if (number == 0) {
			if (flag)
				cout << " ";
			count(false);
		}
	}
}

int curNumber(int &number) {
	int firstDigit;
	int copy = number;
	int count = 0;

	while(copy > 0) {
		copy /= 10;
		count++;
	}

	copy = number;
	for (int i = 0; i < count-1; i++) {
		copy /= 10;
	}

	firstDigit = copy;
	copy = firstDigit;
	copy *= pow(10, count-1);
	number %= copy;
	return firstDigit;
}

void count(bool flag) {
	static int count_ = 0;
	if (flag)
		cout << count_;
	else
		count_++;
}