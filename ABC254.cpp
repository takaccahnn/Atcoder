#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;


// A問題
/*int main(){
    int N; cin >> N;
    string s = to_string(N);
    int size = s.size();
    for(int i=1; i<=2; i++){
       cout << s[size-3+i];
    }
    cout << endl;

    return 0;
}*/

// B問題
/*int main(){
    int N; cin >> N;
    vector<vector<int>> ans(N, vector<int>(N, 0));
    ans[0][0] = 1;

    int size = 1;
    FOR(i, 1, N-1){
        size++;
        rep(j, i+1){
            if(j==size){
                ans[i][j] = 1;
                continue;
            }
            if(j==0){
                ans[i][j] = 1;
                continue;
            }
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }

    rep(i, N){
        rep(j, N){
            if(ans[i][j] == 0){
                cout << endl;
                break;
            }
            cout << ans[i][j] << " ";
        }
    }


    return 0;
}*/

// C問題
/*int main(){
    ll N, K; cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    rep(i, N-K){
        if(a[i]>a[K+i]) swap(a[i], a[K+i]);
    }
    rep(i, N-1){
        if(a[i]>a[i+1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    return 0;
}*/

// D問題
ll prime_count(int b, int N){
    // 1はmainの関数の方で考える
    // 約数の個数を出力する。ただし約数はN以下
    ll res = 0;
    ll a = b*b;

    for(ll i = a; i>=2; i--){
        if(a/i >= N) break;
        if(a%i==0){
            if(a/i != i) res += 2; 
            else res++;
        }
    }

    return res;

}

// D問題
int main(){
    ll N; cin >> N;
    ll res = 1;
    for(ll i=2; i<=N; i++){
        ll res1 = prime_count(i, N);
        res += res1;
    }

    cout << res << endl;

    return 0;
}