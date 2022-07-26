//
//  main.cpp
//  13913
//
//  Created by 홍승완 on 2022/04/11.
//

//#include <iostream>
//#include <queue>
//#include <stack>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n,k;
//int vis[100001]={0,};
//int route[100001]={0,};
//queue<int>q;
//int t=0,cnt;
//void bfs(){
//    q.push(n);
//    vis[n]=1;
//    int w=1;
//    while (!q.empty()) {
//        cnt=0;
//        for(int i=0;i<w;i++){
//            int now=q.front();
//            q.pop();
//            if(now==k)
//                return;
//            if (now - 1 >= 0 && vis[now - 1] == 0) {
//                q.push(now - 1);
//                vis[now - 1] = 1;
//                route[now - 1] = now;
//                cnt++;
//            }
//            if (now + 1 <= 100000 && vis[now + 1] == 0) {
//                q.push(now + 1);
//                vis[now + 1] = 1;
//                route[now + 1] = now;
//                cnt++;
//            }
//            if (now * 2 <= 100000 && vis[now * 2] == 0) {
//                q.push(now * 2);
//                vis[now * 2] = 1;
//                route[now * 2] = now;
//                cnt++;
//            }
//        }
//        w=cnt;
//        if(cnt!=0)
//            t++;
//    }
//}
//int main() {
//    //n, k, 10만
//    // x+1, x-1, 2*x로 이동
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cin>>n>>k;
//    bfs();
//    cout<<t<<"\n";
//    int now=k;
//    int prev;
//    stack<int>st;
//    while(now!=n){
//        st.push(now);
//        prev=route[now];
//        now=prev;
//    }
//    cout<<n<<" ";
//    while(!st.empty()){
//        cout<<st.top()<<" ";
//        st.pop();
//    }
//    return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int n,k;
int t,cnt=0;
int visited[100001];
int _prev[100001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>k;
    queue<pair<int,int>>q;
    queue<int>tmp;
    q.push({n,0});
    visited[n]=1;
    while(q.size()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==k&&cnt==0){
            cnt=1;
            cout<<y<<"\n";
            stack<int>st;
            st.push(x);
            int cur=x;
            while(1){
                if(cur==n)break;
                cur=_prev[cur];
                st.push(cur);
            }
            int w;
            while(st.size()){
                w=st.top();
                cout<<w<<" ";
                st.pop();
            }
            break;
        }
        
        if(x-1>=0&&visited[x-1]==0){
            _prev[x-1]=x;
            visited[x-1]=1;
            q.push({x-1,y+1});
        }
        if(x+1<=100000&&visited[x+1]==0){
            _prev[x+1]=x;
            visited[x+1]=1;
            q.push({x+1,y+1});
        }
        if(x*2<=100000&&visited[x*2]==0){
            _prev[x*2]=x;
            visited[x*2]=1;
            q.push({x*2,y+1});
        }
    }

    return 0;
}
