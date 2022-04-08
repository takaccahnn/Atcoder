// プログラムを書く練習のためのファイル
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define rep(i,n) for(long long i=0;i<(n);i++)

// 尺取り法について勉強
/*nt mains(){
    long long N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    vector<long long> x(Q);
    rep(i, N) cin >> a[i];
    rep(i, Q) cin >> x[i];

    long long sum = 0, res = 0;
    long long right = 0;
    rep(left, N){
        while(right<N and (sum+a[right] <= x[left])){
            sum += a[right];
            right++;
        }
        res += left - right;
        if(left==right) right++;
        else sum -= a[left];
    }

    cout << res << endl;

    return 0;
}*/

/*int main(){
    long long N;
    cin >> N;
    vector<long long> a(N);
    for(long long i =0; i<N; i++) cin >> a[i];
    
    long long right = 0;
    long long res = 0;
    for(int left=0; left<N; left++){
        // rightを一個進めたものが条件を満たすかどうか
        while(right<N and (a[right-1]<a[right] or right==left)){
            right++;
        }
        res += right - left;
    }

    cout << res << endl;

    return 0;
}*/


using ll = long long;
constexpr ll INF64 = (1LL << 62) - 1;

// 入力高速化 (この問題では300msほど速くなりました）
struct fast_ios {
    fast_ios() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
} fast_ios;


int main() {
    int Q;
    cin >> Q;
    ll q, x, k;
    multiset<ll> S;
    for (int i = 0; i < 5; ++i) {
        S.insert(-INF64);  // 番兵として、-INF64とINF64を5個入れておくと楽です
        S.insert(INF64);
    }

    for (int i = 0; i < Q; ++i) {
        cin >> q >> x;
        if (q == 1) {
            S.insert(x);
        }
        if (q == 2) {
            cin >> k;
            auto it = S.upper_bound(x);
            for (int j = 0; j < k; ++j) { --it; }
            ll ans = *it != -INF64 ? *it : -1;
            cout << ans << '\n';
        }
        if (q == 3) {
            cin >> k;
            auto it = S.lower_bound(x);
            for (int j = 0; j < k - 1; ++j) { ++it; }
            ll ans = *it != INF64 ? *it : -1;
            cout << ans << '\n';
        }
    }
}