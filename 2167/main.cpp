//
//  main.cpp
//  2167
//
//  Created by 홍승완 on 2022/04/17.
//

#include <iostream>

using namespace std;

int sum[301][301];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    int a, b, c, d,k;
    cin >> n>>m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> sum[i][j];
            sum[i][j] += sum[i][j-1] +sum[i-1][j]-sum[i-1][j-1];
        }
    }
 
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c >> d;
        cout << sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1]<<'\n';
    }

    return 0;
}
