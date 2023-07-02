//
//  main.cpp
//  1067-C
//
//  Created by 홍승완 on 2023/07/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <tuple>
#include <map>
#include <iomanip>
#include <numeric>
#define init cin.tie(0)->ios_base::sync_with_stdio(0);

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;
typedef tuple<int,int,int> iii;
typedef pair<ll, ll> pll;

int n,x,y,r;
vector<pair<pint,int>>edge;
vector<pair<pint,int>>edges[1001];
int sets[1001];

int find(int x){
    if(x==sets[x])return x;
    return sets[x]=find(sets[x]);
}

void Union(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x<y)sets[y]=x;
    else sets[x]=y;
}

double distances(int x1,int x2,int y1,int y2){
    return sqrt(abs((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}

int main() {
    init;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>r;
        edge.push_back({{x,y},r});
        edges[i].push_back({{x,y},r});
        sets[i]=i;
    }
    
    double ans=0;
    for(int i=0;i<n-1;i++){
        double minNum=1e9;
        int idx=i+1;
        double r1=edge[i].second;
        for(int j=i+1;j<n;j++){
            double r2=edge[j].second;
            double d=distances(edge[i].first.first, edge[j].first.first,edge[i].first.second, edge[j].first.second);
            double theta=asin(abs(r1-r2)/d);
            double cur=0;
            if(d>r1+r2){
                if(r1==r2){
                    cur=2*d+2*r1*M_PI;
                }else{
                    cur=2*sqrt(d*d-(r1-r2)*(r1-r2))+r2*(M_PI-2*theta)+r1*(M_PI+2*theta);
                }
            }
            else{
                cur=0;
            }
            if(minNum>cur){
                minNum=cur;
                idx=j;
            }
        }
        int xx=find(i+1);
        int yy=find(idx+1);
        if(xx!=yy){
            Union(xx, yy);
            if(xx<yy)edges[xx].push_back(edge[yy]);
            else edges[yy].push_back(edge[xx]);
            ans+=minNum;
        }
    }
    
    
    cout<<ans<<"\n";
    
    return 0;
}
