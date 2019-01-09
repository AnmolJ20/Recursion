#include <iostream>
#include <string>
using namespace std;

bool obedientString(string str, int index);

int main() {
	string str;
	cin >> str;
	if (obedientString(str, 0))
		cout << "true";
	else 
		cout << "false";
}

bool obedientString(string str, int index) {
	if (index == str.size())
		return true;

	if (str[index] == 'a' && (str[index+1] == 'a' || (str[index+1] == 'b' && str[index+2] == 'b') || index+1 == str.size()))
		return obedientString(str, index+1);

	else if ((str[index] == 'b' && str[index+1] == 'b') && /*index != 0*/ && (str[index+2] == 'a' || index+2 == str.size()))
		return obedientString(str, index+2);
	
	return false;
}