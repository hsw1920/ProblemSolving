#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long answer;
vector<long long> num;
vector<char> op;
vector<char> priority;
int vis[3];
void setting(string str){
    string number="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'){
            op.push_back(str[i]);
            num.push_back(stoll(number));
            number="";
        } else {
            number+=str[i];
        }
    }
    num.push_back(stoll(number));
}

long long calc(long long a, long long b, char op){
    if(op=='+') return a+b;
    else if(op=='-') return a-b;
    else return a*b;
}
   
void res(){
    //num  op   우선순위
    //n개, n-1개, 6개
    
    vector<long long> tmpArr = num;
    vector<char> tmpOp = op;
    for(int k=0;k<3;k++){
        for(int i=0;i<tmpOp.size();i++){
            if(tmpOp[i]==priority[k]) { // 해당 우선순위의 연산자라면 계산
                tmpArr[i]=calc(tmpArr[i],tmpArr[i+1],tmpOp[i]);
                tmpArr.erase(tmpArr.begin()+i+1);
                tmpOp.erase(tmpOp.begin()+i);
                i--;
            }
        }
    }
    answer = max(answer, abs(tmpArr[0]));
}

void dfs(int cnt){
    if(cnt==3){
        res();
        return ;
    }
    for(int i=0;i<3;i++){
        if(vis[i]==1)continue;
        if(i==0){
            priority.push_back('+');
            vis[i]=1;
        } else if(i==1){
            priority.push_back('-');
            vis[i]=1;
        } else if(i==2){
            priority.push_back('*');
            vis[i]=1;
        }
        dfs(cnt+1);
        vis[i]=0;
        priority.pop_back();
    }
}

long long solution(string expression) {
    answer = 0;
    setting(expression);
    dfs(0);
    return answer;
}