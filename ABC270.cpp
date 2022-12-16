#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

// A問題
/*int main(){
    int A, B; cin >> A >> B;
    vector<bool> question(8, false);
    if(A==1) question[1] = true;
    if(A==2) question[2] = true;
    if(A==4) question[4] = true;
    if(A==3) {
        question[1] = true;
        question[2] = true;
    }
    if(A==5) {
        question[1] = true;
        question[4] = true;
    }
    if(A==6) {
        question[2] = true;
        question[4] = true;
    }
    if(A==7) {
        question[1] = true;
        question[2] = true;
        question[4] = true;
    }
    if(B==1) question[1] = true;
    if(B==2) question[2] = true;
    if(B==4) question[4] = true;
    if(B==3) {
        question[1] = true;
        question[2] = true;
    }
    if(B==5) {
        question[1] = true;
        question[4] = true;
    }
    if(B==6) {
        question[2] = true;
        question[4] = true;
    }
    if(B==7) {
        question[1] = true;
        question[2] = true;
        question[4] = true;
    }
    int ans = 0;
    rep(i, 8){
        if(question[i]) ans+=i;
    }
    cout << ans << endl;
}*/

// B問題
/*int main(){
    int X, Y, Z; cin >> X >> Y >> Z;
    int ans = 0;
    if(Y>0){
        if(X<Y){
            cout << abs(X) << endl;
            return 0;
        } else {
            if(Y<Z){
                cout << "-1" << endl;
                return 0;
            }
            cout << abs(Z)+abs(Y-Z)+abs(Y-X) << endl;
            return 0;
        }
    }
    if(Y<0){
        if(Y<X){
            cout << abs(X) << endl;
            return 0;
        } else {
            if(Z<Y){
                cout << "-1" << endl;
                return 0;
            }
            cout << abs(Z)+abs(Y-Z)+abs(Y-X) << endl;
            return 0;
        }
    }
}*/

// C問題
/*vector<int> ans;

void dfs(Graph &G, int p, int y, vector<bool> &used){
    if(p==y){
        rep(i, ans.size()){
            cout << ans[i]+1 << " ";
        }
        cout << endl;
        return;
    }
    
    used[p] = true;

    for(auto next: G[p]){
        ans.push_back(next);
        if(!used[next]){
            dfs(G, next, y, used);
        }
        ans.pop_back();

    }

    return;
}

int main(){
    int N, x, y; cin >> N >> x >> y;
    x--; y--;
    Graph G(N);
    rep(i, N-1){
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ans.push_back(x);
    vector<bool> used(N, false);

    dfs(G, x, y, used);

    return 0;
}*/

// D問題
int main(){
    int N; cin >> N;
    int K; cin >> K;
    vector<int> A(K);
    rep(i, K) cin >> A[i];

    // 石が n 個残っている状態からゲームを始めたとき、先手が取ることのできる石の個数の最大値
    vector<int> dp(N+1, 0);



    for(int i=0; i<=N; i++){
        if(i==1){
            dp[i] = 1;
            continue;
        }
        rep(j, K){
            int temp = A[j];
            if(i-temp<0) break;
            dp[i] = max(dp[i], (i-temp) - dp[i-temp] + temp);
        }

    }

    cout << dp[N] << endl;

    
}


 






