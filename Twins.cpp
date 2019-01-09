#include <iostream>
#define size 1000

using namespace std;

int twins(char string[], int count);

int main() {
	char string[size];
	int count = 0;
	cin.getline(string, size);
	count = twins(string, count);
	cout << count;
}

int twins(char string[], int count) {
	if (string[2] == '\0')
		return count;
	if (string[0] == string[2])
		count++;
	count = twins(string+1, count);
	return count;
}