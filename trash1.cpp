#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<long long, long long>;
using ll = long long;

// ABC264
// C問題がbit全探索でいけるとは気づかなかった。普通に10!*10!の計算量が必要だと思ったが、bit全探索を用いれば非常に計算量が節約された
/*int main(){
    int H1, W1; cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    rep(i, H1){
        rep(j, W1){
            cin >> A[i][j];
        }
    }

    int H2, W2; cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    rep(i, H2){
        rep(j, W2){
            cin >> B[i][j];
        }
    }

    rep(i, 1<<H1){
        vector<int> bitStandRow;
        rep(j, H1){
            if(i&1<<j) bitStandRow.push_back(j);
        }
        if(bitStandRow.size()!=H2) continue;
        rep(k, 1<<W1){
            vector<int> bitStandColum;
            rep(l, W1){
                if(k&1<<l) bitStandColum.push_back(l);
            }
            if(bitStandColum.size()!=W2) continue;
            vector<vector<int>> ans(bitStandRow.size(), vector<int>(bitStandColum.size()));
            rep(m, bitStandRow.size()){
                rep(n, bitStandColum.size()){
                    ans[m][n] = A[bitStandRow[m]][bitStandColum[n]];
                }
            }
            bool jud = true;
            if(ans!=B) jud = false;
            if(jud){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;

}*/

// D問題(転倒数を持いた方法)
/*int main(){
    string s; cin >> s;
    vector<int> order(7);
    rep(i, 7){
        if(s[i]=='a') order[i] = 1;
        if(s[i]=='t') order[i] = 2;
        if(s[i]=='c') order[i] = 3;
        if(s[i]=='o') order[i] = 4;
        if(s[i]=='d') order[i] = 5;
        if(s[i]=='e') order[i] = 6;
        if(s[i]=='r') order[i] = 7;
    }

    vector<int> inversion(8, 0);
    int ans = 0;
    rep(i, 7){
        int sum = 0;
        rep(j, order[i]+1) sum+=inversion[j];
        ans+=i-sum;

        inversion[order[i]] += 1;
    }

    cout << ans << endl;
    
    return 0;
}*/

// D問題(全探索を用いた解法)
/*int main(){
    string s; cin >> s;
    vector<int> order(7);
    rep(i, 7){
        if(s[i]=='a') order[i] = 0;
        if(s[i]=='t') order[i] = 1;
        if(s[i]=='c') order[i] = 2;
        if(s[i]=='o') order[i] = 3;
        if(s[i]=='d') order[i] = 4;
        if(s[i]=='e') order[i] = 5;
        if(s[i]=='r') order[i] = 6;
    }
    int times = 0;
    rep(i, 7){
        int index;
        // iの数字がorder配列の中のどこの要素にあるのか
        rep(j, 7){
            if(order[j]==i) index=j;
        }
        while(i!=index){
            swap(order[index], order[index-1]);
            index--; times++;
        }
    }

    cout << times << endl;
}*/

// ABC239 
// E問題
// ここで定義された配列は初期値0のNで要素数が定義されているため、main関数内で再度要素数を定義してやる必要がある
/*void bfs(ll parent, vector<vector<ll>> &G, vector<ll> &X, vector<vector<ll>> &partialSet){
    if(!G[parent].size()){
        partialSet[parent].push_back(X[parent]);
        return;
    }

    for(auto next : G[parent]){
        bfs(next, G, X, partialSet);
        for(auto a : partialSet[next]){
            partialSet[parent].push_back(a);
        }
    }

    partialSet[parent].push_back(X[parent]);

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
    
    rep(i, N) cin >> X[i];
    rep(i, N-1){
        ll A, B; cin >> A >> B;
        A--; B--;
        if(A>B) G[B].push_back(A);
        else if(B>A) G[A].push_back(B);
    }

    bfs(0, G, X, partialSet);
    
    rep(i, N){
        sort(partialSet[i].begin(), partialSet[i].end(), greater<int>());
    }

    rep(i, Q){
        int V, K; cin >> V >> K;
        cout << partialSet[V-1][K-1] << endl;
    }

    return 0;
}*/

// ABC267
// C問題
// 一度宣言した変数をまた宣言したために、値がおかしくなってしまった
/*int main(){
    int N, M; cin >> N >> M;
    vector<ll> A(N);
    vector<ll> partialSum;
    ll sum = 0;
    rep(i, M){
        ll a; cin >> a;
        sum+=a; A[i]=a;
    }
    partialSum.push_back(sum);
    FOR(i, M, N-2){
        ll a; cin >> a;
        A[i]=a;
        sum-=A[i-M]; sum+=A[i];
        partialSum.push_back(sum);
    }
    cin >> A[N-1];

    ll b = 0;
    ll ans = 0;
    rep(i, M){
        b+=(i+1)*A[i];
    }
    ans = b;

    FOR(i, M, N-1){
        b = b - partialSum[i-M] + M*A[i];
        if(ans<b) ans = b;
    }


    cout << ans << endl;

}*/

// D問題
// for構文を回す範囲とかが複雑で難しかった。
/*int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<ll>> dp(M, vector<ll>(N, -1e16));

    rep(i, M-1){
        if(i==0){
            rep(j, N-M+1){
                dp[0][j]=A[j];
            }
        }
        FOR(j, i, N-(M-i)){
            if(dp[i][j]==-1e10) continue;
            FOR(k, j+1, N-M+i+1){
                if(dp[i+1][k]<dp[i][j]+(i+2)*A[k]) dp[i+1][k]=dp[i][j]+(i+2)*A[k];
            }
        }
    }

    ll ans = -1e16;
    rep(i, N){
        if(ans<dp[M-1][i]) ans = dp[M-1][i];
    }

    cout << ans << endl;
}*/

// ABC261
// D問題
int main(){
    int N, M; cin >> N >> M;
    vector<ll> X(N);
    rep(i, N) cin >> X[i];
    map<int, ll> mp;
    rep(i, M){
        int a;
        ll b; cin >> a >> b;
        mp[a] = b;
    }

    vector<vector<ll>> dp(N, vector<ll>(N+1, 0));
    // 列がカウンタの数で、行が試行回数　カウンタの数がjで試行回数がiの時の最大値
    rep(i, N){
        // 試行回数がiの時
        if(i==0){
            dp[0][1]=X[0]+ mp[1];
            continue;
        }
        
        // 一つ手前の試行回数(i-1)回目の値について
        rep(j, i+1){
            dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + X[i] + mp[j+1]);
            if(j-1<0) {
                dp[i][0] = max(dp[i][0], dp[i-1][0]);
                continue;
            }
            dp[i][0] = max(dp[i][0], dp[i-1][j]);
        }
    }

    ll ans = 0;
    rep(i, N+1){
        if(ans<dp[N-1][i]) ans = dp[N-1][i];
    }

    cout << ans << endl;
}