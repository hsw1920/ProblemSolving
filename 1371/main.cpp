//
//  main.cpp
//  1371
//
//  Created by 홍승완 on 2022/04/26.
//

#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;


int Alphabet[26];
int val = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string t;
    while (cin >> t) {
        for (int i = 0; i < t.size(); i++) {
            if (t[i] >= 'a' && t[i] <= 'z')
                Alphabet[t[i] - 'a']++;
        }
        t.clear();
    }
    for (int i = 0; i < 26; i++)
        val = max(val, Alphabet[i]);

    for (int i = 0; i < 26; i++)
        if (Alphabet[i] == val) {
            char alpha = 'a' + i;
            cout << alpha;
        }
    return 0;
}
