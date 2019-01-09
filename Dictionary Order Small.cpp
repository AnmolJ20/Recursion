#include <iostream>
#include <string>
using namespace std;

bool canSmall(string str);
void dictSmall(string str);

int main() {
	string str;
	getline(cin, str);
	dictSmall(str);
}

void dictSmall(string str) {
	if (!canSmall(string str))
		return;

	
	if (canSmall(str))
		cout << str << endl;
}

bool canSmall(string str) {

}