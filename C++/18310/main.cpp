//
//  main.cpp
//  18310
//
//  Created by 홍승완 on 2023/05/01.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cout << v[(n-1)/2];
}
