#include <bits/stdc++.h>

using namespace std;

int arr[101];

int find(int x){
    if(arr[x]==x)return x;
    return arr[x]=find(arr[x]);
}

void Union(int x,int y){
    int xx =find(x);
    int yy= find(y);
    if(xx>yy)arr[xx]=yy;
    else arr[yy]=xx;
}

bool compare(vector<int> a, vector<int> b){
    return a[2]<b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(),costs.end(),compare);
    for(int i=0;i<n;i++)arr[i]=i;
    
    for(int i=0;i<costs.size();i++){
        int x = find(costs[i][0]);
        int y = find(costs[i][1]);
        if(x!=y){
            Union(x,y);
            answer+=costs[i][2];
            cout<<costs[i][2]<<" ";
        }
    }
    
    return answer;
}