//
//  main.cpp
//  1922
//
//  Created by 홍승완 on 2023/04/16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,a,b,c;
vector<pair<int,pair<int,int>>>edge;
int arr[1001];
int find(int x){
    if(arr[x]==x)return x;
    return arr[x]=find(arr[x]);
}
void Union(int x, int y){
    int xx=find(x);
    int yy=find(y);
    if(xx>yy)arr[xx]=yy;
    else arr[yy]=xx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(),edge.end());
    for(int i=0;i<=n;i++)arr[i]=i;
    int sum=0;
    for(int i=0;i<m;i++){
        int x=find(edge[i].second.first);
        int y=find(edge[i].second.second);
        if(x!=y){
            Union(x, y);
            sum+=edge[i].first;
        }
    }
    cout<<sum<<"\n";
    return 0;
}
