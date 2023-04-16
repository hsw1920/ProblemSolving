//
//  main.cpp
//  11085
//
//  Created by 홍승완 on 2023/04/16.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pint;
int p,w,c,v,s,e,width[1001];
vector<pint>wse(1001,{0,0});
typedef struct line{
    int s;
    int e;
    int wid;
} line;
line Line[50001];

bool compare(line x, line y){
    return x.wid>y.wid;
}
int arr[1001];
// 두 나라, p개지점과 w개길, 양방향루트, 길마다 너비존재함
// 경로를 정하고 해당 경로로만 군사보냄
// 경로상 너비가 가장 좁은길의 너비를 최대화하는 경로를 택함
// 기록이 없어짐

// c,v는 두 나라의 수도임
// target : 경로상 길중 너비가 가장 좁은길의 너비를 출력

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
    cin>>p>>w; // p개지점 w개의 양방향간선, 1000, 50000
    cin>>c>>v; // 두 나라 수도 , 1000
    for(int i=0;i<w;i++){ // 1000
        cin>>Line[i].s>>Line[i].e>>Line[i].wid;
    }
    sort(Line,Line+w,compare);
    // 큰 순서로 정렬하여 순서대로 union하여 c,v가 한 집합인지 확인
    for(int i=0;i<=p;i++)arr[i]=i;
    for(int i=0;i<w;i++){
        int x=getFind(Line[i].s);
        int y=getFind(Line[i].e);
        if(x!=y){
            getUnion(x,y);
        }
        if(getFind(c)==getFind(v)){
            cout<<Line[i].wid<<"\n";
            break;
        }
    }
    
    return 0;
}
