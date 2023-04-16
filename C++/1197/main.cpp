//
//  main.cpp
//  1197
//
//  Created by 홍승완 on 2023/04/16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v,e,a,b,c;

typedef struct Tree{
    int a;
    int b;
    int w;
}Tree;
bool cmp(Tree x, Tree y){
    return x.w<y.w;
}
int arr[10001];
Tree tree[100001];
int getFind(int x){
    if(arr[x]==x)return x;
    return arr[x]=getFind(arr[x]);
}

void getUnion(int x, int y){
    int xx=getFind(x);
    int yy=getFind(y);
    if(xx>yy)arr[xx]=yy;
    else arr[yy]=xx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>tree[i].a>>tree[i].b>>tree[i].w;
    }
    
    sort(tree,tree+e,cmp);
    
    for(int i=0;i<=v;i++)arr[i]=i;
    int res=0;
    
    for(int i=0;i<e;i++){
        int x=getFind(tree[i].a);
        int y=getFind(tree[i].b);
        if(x!=y){
            getUnion(x, y);
            res+=tree[i].w;
        }
        else{
            continue;
        }
    }
    cout<<res<<"\n";
    
    return 0;
}
