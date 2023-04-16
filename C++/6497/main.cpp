//
//  main.cpp
//  6497
//
//  Created by 홍승완 on 2023/04/16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,x,y,z;
vector<int>arr(200001,0);
vector<pair<int,pair<int,int>>>edge;

int find(int x){
    if(arr[x]==x)return x;
    return arr[x]=find(arr[x]);
}

void Union(int a, int b){
    int x=find(a);
    int y=find(b);
    if(x>y)arr[x]=y;
    else arr[y]=x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(1){
        arr.clear();
        edge.clear();
        cin>>m>>n; // 집의수 m, 길의수 n;
        if(m==0&&n==0)break;
        for(int i=0;i<n;i++){
            cin>>x>>y>>z;
            edge.push_back({z,{x,y}});
        }
        sort(edge.begin(),edge.end());
        for(int i=0;i<=m;i++)arr[i]=i;
        int sum=0;
        // 불이 켜져있지 않은 길을 반드시 지난다면 위험함
        // 두집싸엥 대해 불이 켜진 길만으로 왕래할 수 있음
        
        // 불을 끌수있는 최대?
        // -> 두 집사이 최소거리 + 불 켜는것 최소
        // 최소스패닝트리 여집합
        int res=0;
        for(int i=0;i<edge.size();i++){
            int x=find(edge[i].second.first);
            int y=find(edge[i].second.second);
            sum+=edge[i].first;
            if(x!=y){
                Union(x,y);
                res+=edge[i].first;
            }
        }
        cout<<sum-res<<"\n";
    }

    return 0;
}
