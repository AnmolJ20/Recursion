#include <iostream>
using namespace std;

#if 0
	#define log(x, y) cout << x << y << endl;
#else
	#define log(x, y)
#endif

void inMat(char matrix[][1000], const int& r, const int& c);
void outMat(char matrix[][1000], const int& r, const int& c);
bool canMoveR(char maze[][1000], const int& r, const int& c, int x, int y);
bool canMoveD(char maze[][1000], const int& r, const int& c, int x, int y);
bool RatMaze(char maze[][1000], int r, int c, int x, int y);

int main() {
	int r, c;
	cin >> r >> c;
	char maze[1000][1000];
	inMat(maze, r, c);

	if (RatMaze(maze, r, c, 0, 0))
		outMat(maze, r, c);
	else
		cout << -1;
}

bool canMoveR(char maze[][1000], const int& r, const int& c, int x, int y) {
	if (y >= c || maze[x][y+1] == 'X')
		return false;
	else 
		return true;
}

bool canMoveD(char maze[][1000], const int& r, const int& c, int x, int y) {
	if (x >= r || maze[x+1][y] == 'X')
		return false;
	else
		return true;
}

bool RatMaze(char maze[][1000], int r, int c, int x, int y) {
	log("Yes","")
	if (x >= r) {
		return false;
	}

	if (x == r-1 && y == c-1) {
		maze[x][y] = 'W';
		return true;
	}

	if (canMoveR(maze, r, c, x, y)) {
		maze[x][y] = 'W';
		if(RatMaze(maze, r, c, x, y+1) == false) {
			maze[x][y] = 'O';
		}
		else 
			return true;
	}

	if (canMoveD(maze, r, c, x, y)) {
		maze[x][y] = 'W';
		if (RatMaze(maze, r, c, x+1, y) == false) {
			maze[x][y] = 'O';
		}
		else 
			return true;
	}

	return false;
}

void inMat(char matrix[][1000], const int& r, const int& c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}
}

void outMat(char matrix[][1000], const int& r, const int& c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (matrix[i][j] == 'W')
				cout << 1;
			else
				cout << 0;
			cout << " ";
		}
		cout << "\n";
	}
}