/*
Print steps to compute Tower of Hanoi as well as number of steps to complete it
if disks = 2 and source = A, Destination = B, Helper = C it should print
A->C
A->B
C->B
3
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

void printTowerOfHanoi(int disks, int source, int destination, int helper);
int countTowerOfHanoi(int disks, int source, int destination, int helper, int count);

int main() {
	int disksNumber;
	cin >> disksNumber;
	printTowerOfHanoi(disksNumber, 1, 2, 3);
	int count = countTowerOfHanoi(disksNumber, 1, 2, 3, 0);
	cout << count;
}

void printTowerOfHanoi(int disks, int source, int destination, int helper) {
	if (disks == 0)
		return;
	printTowerOfHanoi(disks-1, source, helper, destination);
	cout << "Move " << disks << "th disc from T" << source << " to T" << destination << endl;
	printTowerOfHanoi(disks-1, helper, destination, source);
}

int countTowerOfHanoi(int disks, int source, int destination, int helper, int count) {
	if (disks == 0)
		return count;
	count = countTowerOfHanoi(disks-1, source, helper, destination, count);
	count++;
	count = countTowerOfHanoi(disks-1, helper, destination, source, count);
	return count;	
}