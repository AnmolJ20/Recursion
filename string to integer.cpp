#include <iostream>
#include <math.h>
#include <string.h>
#define size 11
using namespace std;

int toNumber(char string[]);

int main() {
	char string[size];
	cin >> string;
	cout << toNumber(string);
}

int toNumber(char string[]) {
	int number;
	if (string[1] == '\0')
		return (int)string[0] - '0';

	number = ((int)string[0] - '0');
	number *= pow(10, strlen(string)-1);
	number += toNumber(string+1);
	
	return number;
}