//
//  main.cpp
//  9020
//
//  Created by 홍승완 on 2023/04/24.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num, max = 0;
    cin >> num;
    int even[10001];
    for(int i = 0; i < num; i++) {
        cin >> even[i];
        if(even[i] > max)
            max = even[i];
    }
    bool prime[10001];
    fill_n(prime, max + 1, 1);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= sqrt(max); i++)
        if(prime[i] == true)
            for(int j = i*2; j <= (max); j += i)
                prime[j] = false;

    for(int t = 0; t < num; t++)
    {
        for(int j = even[t]/2; j > 0; j--)
        {
            if(prime[j] && prime[even[t]-j])
            {
                cout << j << ' ' << even[t]-j << '\n';
                break;
            }
        }
    }
}
