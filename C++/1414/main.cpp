//
//  main.cpp
//  1414
//
//  Created by 홍승완 on 2023/05/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 컴퓨터가 n개가 있음
// n개를 서로 모두 연결시켜줘야함

// 모든 컴퓨터가 연결되어있지 않으면 -> -1 출력
//

int n;
int maps[51][51];
int set[51];
vector<pair<int,pair<int,int>>>edge;

int find(int x){
    if(x==set[x])return x;
    return set[x]=find(set[x]);
}
void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x<y)set[y]=x;
    else set[x]=y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<n;j++){
            if(tmp[j]>='a'&&tmp[j]<='z'){
                maps[i][j]=tmp[j]-('a'-1);
            } else if(tmp[j]>='A'&&tmp[j]<='Z'){
                maps[i][j]=tmp[j]-('A'-1)+26;
            } else{
                maps[i][j]=0;
            }
            edge.push_back({maps[i][j],{i,j}});
        }
    }

    sort(edge.begin(),edge.end());
    for(int i=0;i<=n;i++)set[i]=i;
    int cnt=0;
    int res=0;
    for(int i=0;i<edge.size();i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y && edge[i].first!=0){
            Union(x, y);
            cnt++;
        }
        else{
            res+=edge[i].first;
        }
    }
    
    if(cnt!=n-1){
        cout<<-1<<'\n';
        return 0;
    }
    cout<<res<<"\n";
    
    return 0;
}
