//
//  main.cpp
//  1935
//
//  Created by 홍승완 on 2022/10/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;
double arr[27];
string str;
char op;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<double>nums;
    
    for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z'){
            nums.push(arr[str[i]-'A']);
        }
        else{
            if(nums.size()){
                double res;
                double target = nums.top();
                nums.pop();
                
                if(str[i]=='+'){
                    res = nums.top() + target;
                } else if(str[i]=='-'){
                    res = nums.top() - target;
                } else if(str[i]=='*'){
                    res = nums.top() * target;
                } else if(str[i]=='/'){
                    res = nums.top() / target;
                }
                nums.pop();
                nums.push(res);
            }
        }
    }
    cout<<fixed;
    cout.precision(2);
    
    cout << nums.top()<<"\n";
    
    
    
        
    
    
    
    return 0;
}
