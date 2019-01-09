#include <iostream>
#include <cstring>
using namespace std;

void subSQ(string input, string output);
int countSubSQ(string input, string output);

int main() {
	string input;
	cin >> input;
	cout << countSubSQ(input, "") << endl;
	subSQ(input, "");
}

void subSQ(string input, string output) {
	if (input.size() == 0) {
		cout << output << " ";
		return;
	}

	subSQ(input.substr(1), output);
	subSQ(input.substr(1), output + input[0]);
}

int countSubSQ(string input, string output) {
	static int count = 0;
	if (input.size() == 0) {
		count++;
		return count;
	}

	countSubSQ(input.substr(1), output);
	countSubSQ(input.substr(1), output + input[0]);
	return count;
}