#include <iostream>
#define size 100

using namespace std;

void paranthesis(char string[], int flag);

int main() {
	char string[size];
	cin.getline(string, size);
	paranthesis(string, 0);
}

void paranthesis(char string[], int flag) {
	if (string[0] == ')')
		return;
	else if (string[0] == '(') {
		flag = 1;
		paranthesis(string+1, flag);
		return;
	}

	if (flag == 1)  {
		cout << string[0];
		paranthesis(string+1, flag);
	}

	else if (flag == 0)
		paranthesis(string+1, flag);
}