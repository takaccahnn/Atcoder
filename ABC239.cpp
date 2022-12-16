#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)

// A問題
/*int main(){
    ll H;
    cin >> H;
    cout << fixed << setprecision(10) << sqrt((double)H*(12800000+H)) << endl;

    return 0;
}*/

// B問題
/*int main(){
    ll X;
    cin >> X;

    // あまりを計算
    ll r = X % 10;

    if(X<0 and r!=0) cout << X/10-1 << endl;
    else cout << X/10 << endl;

    

    return 0;

}*/

// C問題
/*int main(){
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<pair<ll, ll>> ans;
    bool exist = false;

    for(int i=-2; i<3; i++){
        for(int j=-2; j<3; j++){
            ll temp;
            ll x, y;
            x = x1+i; y = y1+j;
            if((x-x1)*(x-x1)+(y-y1)*(y-y1)==5 and
                (x-x2)*(x-x2)+(y-y2)*(y-y2)==5){
                    cout << "Yes" << endl;
                    return 0;
                }
        }   
    }

    cout << "No" << endl;

    return 0;
}*/

// D問題
/*bool isprime(int x){
    if(x==2) return true;
    if(x==1) return false;
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;

}
int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // Aokiの出した数字に対して、Takahashiが出せるかどうかを調べる
    // 一つでもTakahashiが出せなければ、Aokiの勝ちが決まる
    for(int i=A; i<=B; i++){
        // Aokiが勝てる数字の数を入れる(1以上ならAokiの勝ちなのでok)
        int jud = 0;
        for(int j=C; j<=D; j++){
            int sum = i+j;
            if(isprime(sum)) jud++;
        }
        if(!jud){
            cout << "Takahashi" << endl;
            return 0;
        }
    }

    cout << "Aoki" << endl;

    return 0;
}*/

// E問題

void bfs(ll parent, vector<vector<ll>> &G, vector<ll> &X, vector<vector<ll>> &partialSet){

    for(auto next : G[parent]){
        bfs(next, G, X, partialSet);
        rep(i, partialSet[next].size()){
            if(i>=20) break;
            partialSet[parent].push_back(partialSet[next][i]);
        }
    }

    partialSet[parent].push_back(X[parent]);
    sort(partialSet[parent].begin(), partialSet[parent].end(), greater<ll>());

    return;
}

int main(){
    int N, Q; cin >> N >> Q;
    vector<vector<ll>> G(N, vector<ll>());
    // グラフの頂点を表す
    vector<ll> X(N);
    // 各頂点に入っている値を表す
    vector<vector<ll>>  partialSet(N, vector<ll>());
    // 各頂点を親とした時の子の要素を収納
    vector<vector<ll>> a(N, vector<ll>());
    vector<bool> used(N, false);
    
    rep(i, N) cin >> X[i];
    rep(i, N-1){
        ll A, B; cin >> A >> B;
        A--; B--;
        a[A].push_back(B); a[B].push_back(A);
    }
    queue<ll> nxt;
    nxt.push(0);
    used[0] = true;

    while(!nxt.empty()){
        ll x = nxt.front(); nxt.pop();
        used[x] = true;
        rep(j, a[x].size()){
            if(used[a[x][j]]) continue;
            G[x].push_back(a[x][j]);
            nxt.push(a[x][j]);
        }
    }
    

    bfs(0, G, X, partialSet);

    rep(i, Q){
        int V, K; cin >> V >> K;
        cout << partialSet[V-1][K-1] << endl;
    }

    return 0;
}