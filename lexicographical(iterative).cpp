#include <iostream>
using namespace std;

void Test(int, int);

int main() {
    int n;
    cin >> n;
    cout << 0;
    Test(n, 1);
}

void Test(int N, int k)
{
    if (k > N) {return;}

    for (int i = 0; i < 10; i++)
    {
        if (k <= N)
        {
            cout << " " << k;

            k *= 10;
            Test(N, k);
            k /= 10;
            k++;
            if (k % 10 == 0) return;
        }
    }
}