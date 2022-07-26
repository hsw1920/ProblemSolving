//
//  main.cpp
//  9466
//
//  Created by 홍승완 on 2022/04/02.
//

// 시간초과

//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//#include <cstring>
//#include <stack>
//using namespace std;
//int T,n;
//int st[100001];
//bool vis[100001];
//bool vis2[100001];
////큐에 넣고 타겟이 다시한번 넣어지면?
////pop하면서 vis처리
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cin>>T;
//    for(int z=0;z<T;z++){
//        cin>>n;
//        memset(st,0,sizeof(st));
//        memset(vis,false,sizeof(vis));
//        for(int i=1;i<=n;i++){
//            cin>>st[i];
//        }
//        int cnt=0;
//
//        for(int i=1;i<=n;i++){
//            memset(vis2,false,sizeof(vis2));
//            if(i==st[i]){
//                vis[i]=1;
//                continue;
//            }
//
//            if(!vis[i]){
//                int target=i;
//                stack<int>s;
//                s.push(st[i]);
//                int flag=0;
//                while(s.top()!=target){
//                    if(vis[st[s.top()]]){
//                        flag=-1;
//                        break;
//                    }
//                    if(vis2[st[s.top()]]){
//                        int k=st[s.top()];
//                        vis[k]=1;
//                        while(s.top()!=k){
//                            vis[s.top()]=1;
//                            s.pop();
//                        }
//                        flag=-1;
//                        break;
//                    }
//
//                    s.push(st[s.top()]);
//                    vis2[s.top()]=true;
//                }
//
//                if(flag==0){
//                    while(!s.empty()){
//                        vis[s.top()]=1;
//                        s.pop();
//                    }
//                }
//                else{
//                    cnt++;
//                    vis[i]=1;
//                }
//            }
//        }
//        cout<<cnt<<"\n";
//    }
//
//    return 0;
//}



#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;

int t, n;
int graph[MAX];
bool visited[MAX];
bool done[MAX];
int cnt;
void hasCycle( int node) {

    visited[node] = true;
    int next = graph[node];

    
    if (!visited[next]) {
        hasCycle( next);
    }
    else if (!done[next]) {//방문은 했지만 아직 사이클이 아니라면 next까지 포함해서 사이클 완성
        //자기 자신을 포함한 팀의 멤버를 카운트
        for (int i = next; i != node; i = graph[i]) {
            cnt++;
        }
        cnt++;
    }
    done[node] = true;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> graph[i];
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                hasCycle(i);
            }
        }
        cout << n-cnt << '\n';
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
    }


    return 0;
}
