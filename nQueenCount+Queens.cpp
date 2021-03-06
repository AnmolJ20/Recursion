#include <iostream>
using namespace std;

void clearBoard(char board[][100], int m, int n);
bool canPlace(char board[][100], int N, int r, int c);
void solveNQueen(char board[][100], int N, int r, bool flag);
void count(bool flag);
void printQueens(char board[][100], int N);

int main(){
    char board[100][100];
    int N;
    cin >> N;
    clearBoard(board, N, N);

    solveNQueen(board, N, 0, false);
    count(true);
    cout << endl;
    solveNQueen(board, N, 0, true);
}

void clearBoard(char board[][100], int m, int n){
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            board[r][c] = 'X';
        }
    }
}

bool canPlace(char board[][100], int N, int r, int c){
    for(int x = 0; x < N; ++x){
        if (board[x][c] == 'Q') return false;
    }

    int rowDir[] = {-1, -1};
    int colDir[] = {-1, +1};
    for(int dir = 0; dir < 2; ++dir){
        for(int dist = 1; dist < N; ++dist){
            int nextRow = r + dist * rowDir[dir];
            int nextCol = c + dist * colDir[dir];
            if ((nextRow < 0 or nextRow >= N) or (nextCol < 0 or nextCol >= N)){
                break;
            }
            // now i can check safely, huhhh!
            if (board[nextRow][nextCol] == 'Q') return false;
        }
    }
    return true;
}

void solveNQueen(char board[][100], int N, int r, bool flag){
    if (r == N){
        count(false);
        if (flag)
            printQueens(board, N);
        return;
    }
    // lets try to place a queen in row r
    bool result = false;
    for(int c = 0; c < N; ++c){
        bool check = canPlace(board, N, r, c);
        if (check == true){
            board[r][c] = 'Q';  // place the queen
            solveNQueen(board, N, r + 1, flag);
            board[r][c] = 'X';  // reset the cell    
        }
    }
    return;
}

void count(bool flag) {
    static int count = 0;
    if (flag)
        cout << count;
    else
        count++;
}

void printQueens(char board[][100], int N) {
    for (int i = 0; i < N; i++) {
        cout << "{";
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'Q')
                cout << i+1 << "-" << j+1;
        }

        cout << "} ";
    }

    cout << " ";
}