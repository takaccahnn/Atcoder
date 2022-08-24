#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<(b);i++)
static const int MAX = 1000000;

/*vector<bool> used;
void dfs(const Graph &G, int v){
    used[v] = true;

    for(auto next_v: G[v]){
        if(used[next_v]) continue;
        DFS(G, next_v);
    }
}*/


/*int main(){

    Graph G(NULL);
    queue<int> que;
    vector<int> dist(NULL, -1);
    dist[0] = 1;
    
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(auto nv: G[v]){
            if(dist[nv] != -1) continue;
            que.push(nv);
            dist[nv] = dist[v]+1;
        }
    }

    return 0;
}*/

/*struct graph{
    int to;
    int cost;
};
using Graph =  vector<vector<graph>>;

using node = pair<int, int> ;
// 頂点とその頂点までの最短経路を収納

void dijkstra(Graph &G, int s, vecotr<int> &dist){
    int N = G.size();
    dist.resize(N, NULL);
    // resize関数 配列の要素数をNに直す 配列の要素数が足りない時はNULLで値を保管、元の要素数より小さい時は値を消去する
    dist[s] = 0;
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.insert(dist[s], s);

    while(!pq.empty()){
        node p = pq.front();
        pq.pop();
        int v = p.second;
        if(dist[v]<p.first) continue;
        // 上記でvまでの最短経路がこれであるかを確かめている
        // 複数経路が考えられる場合、最小経路の値を変わっている可能性があるため

        for(auto nv: G[v]){
            if(dist[nv.to]>dist[v]+nv.cost){
                dist[nv.to] = dist[v] + nv.cost;
                pq.push(dist[dist[nv.to], nv.to]);
            }
        }
        // 最短経路からpqに収納されている頂点が最短経路であるかを調べていく
        
    }

}*/

/*struct student{
    int number;
    int score;
};

int main(){
    set<int> in;
    in.insert(1);
    in.insert(2);
    in.insert(1);
    in.erase(1);
    for(auto i=in.begin(); i!=in.end(); i++){
        cout << *i << endl;
    }
    map<int, int> count;
    count[1] = 2;
    count[1]++;
    cout << count[1] << endl;
    cout << count[0] << endl;


    return 0;
}*/

int main(){
    vector<int> a={-1};
    int i = 100;
    int j = i&(-i);
    cout << j << endl;
    i -= i&(-i);
    cout << i << endl;
    return 0;
}