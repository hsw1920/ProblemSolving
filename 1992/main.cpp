//
//  main.cpp
//  1992
//
//  Created by 홍승완 on 2022/03/27.
//

#include <iostream>
#include <string>

using namespace std;

string video[64];

// 재귀함수
void print(int size, int y, int x)
{
    char curr = video[y][x];

    for (int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++)
            if (video[i][j] != curr)
            {
                cout << '(';
                print(size / 2, y, x);
                print(size / 2, y, x + size / 2);
                print(size / 2, y + size / 2, x);
                print(size / 2, y + size / 2, x + size / 2);
                cout << ')';
                return;
            }

    cout << curr;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> video[i];

    print(N, 0, 0);

    return 0;
}
