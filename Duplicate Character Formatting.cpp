#include <iostream>
using namespace std;

void separateDuplicate(char str[]);

int main() {
	char str[100];
	cin.getline(str, 100);
	separateDuplicate(str);
}

void separateDuplicate(char str[]) {
	if (str[0] == '\0')
		return;
	cout << str[0];
	if (str[0] == str[1])
		cout << "*";
	separateDuplicate(str+1);
}