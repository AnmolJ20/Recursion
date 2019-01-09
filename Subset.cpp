#include <iostream>
using namespace std;

void count(bool flag);
bool SubsetSum(int array[], int size, int index, int SUM, int sum);

int main() {
	int array[100];
	int size;
	int sum;
	cin >> size;
	for (int i = 0; i < size; i++)
		cin >> array[i];
	cin >> sum;
	SubsetSum(array, size, 0, sum, 0);
	cout << endl;
	count(true);
}

bool SubsetSum(int array[], int size, int index, int SUM, int sum) {
	if (index >= size) {
		return false;
	}

	if (sum == SUM) {
		count(false);
		//cout << endl;
		return true;
	}

	bool res = false;
	for (int i = index; i < size; i++) {
		if (sum + array[i] <= SUM) {
			res = SubsetSum(array, size, index+1, SUM, sum+array[i]) || res;
			if (res) {
				//cout << array[i] << " ";
			}
		}
	}

	return res;
}

void count(bool flag) {
	static int count_ = 0;
	if (flag)
		cout << count_;
	else
		count_++;
}