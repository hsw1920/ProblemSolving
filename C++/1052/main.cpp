//
//  main.cpp
//  1052
//
//  Created by 홍승완 on 2022/03/21.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;

    if (k >= n)
        cout << 0;
    
    else {
        int res = 0;

        while (1) {
            int cnt = 0;
            int tmp = n;
            
            while (tmp > 0) {
                if (tmp % 2 == 0)
                    tmp /= 2;
                else {
                    tmp /= 2;
                    cnt++;
                }
            }
            
            if (k >= cnt)
                break;
            n++;
            res++;
        }
        cout << res;
    }
    
    return 0;
}
