#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

// D問題

int main(){
    ll N;
    ll L, R; cin >> N >> L >> R;
    vector<ll> dpL(N);
    // Aの配列で要素iまでLに置換する操作を行った際の最小値
    vector<ll> dpR(N);
    // Aの配列で要素N-iから最後の要素までRに置換する操作を行った際の最小値

    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    rep(i, N){
        if(i==0){
            dpL[0] = min(L, A[0]);
            continue;
        }
        dpL[i] = min(dpL[i-1]+A[i], (i+1)*L);
    }

    rep(i, N){
        if(i==0){
            dpR[0] = min(A[N-1], R);
            continue;
        }
        dpR[i] = min(dpR[i-1]+A[N-1-i], (i+1)*R);
    }

    ll ans = 1e18;

    rep(i, N-1){
        ll temp = dpL[i]+dpR[N-2-i];
        if(ans>temp) ans = temp;
    }
    if(ans>dpL[N-1]) ans = dpL[N-1];
    if(ans>dpR[N-1]) ans = dpR[N-1];

    cout << ans << endl;
}