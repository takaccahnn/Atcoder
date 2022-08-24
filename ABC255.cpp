#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<double, double>;
using ll = long long;

// A問題
/*int main(){
    int R, C; cin >> R >> C;
    vector<vector<int>> a(2, vector<int>(2));

    rep(i, 2){
        rep(j, 2){
            cin >> a[i][j];
        }
    }

    cout << a[R-1][C-1] << endl;

    return 0;
}*/

// B問題
/*int main(){
    int N, K; cin >> N >> K;
    // Kは光っている人
    vector<double> A(K);
    // 配列Aは明かりを持っている人を収納している
    rep(i, K) cin >> A[i];
    vector<node> X(N);
    rep(i, N) cin >> X[i].first >> X[i].second;

    vector<node> shine;
    // 光っている点の座標の値を収納
    vector<bool> dark(N, true);
    // 光ってない人を収納
    rep(i, K){
        shine.push_back(make_pair(X[A[i]-1].first, X[A[i]-1].second));
        dark[A[i]-1] = false;
    }

    double R = 0.0;
    vector<double> distance;

    // rep(i, K) cout << shine[i].first << " " << shine[i].second << endl;

    // 光っている点から光ってない各点に対して最小の距離を求める
    rep(i, N){
        if(!dark[i]) continue;
        double mini = 1e11;
        rep(j, K){
            double x = (X[i].first-shine[j].first) * (X[i].first-shine[j].first) + (X[i].second-shine[j].second) * (X[i].second-shine[j].second);
            mini = min(mini, sqrt(x));
        }
        distance.push_back(mini);
        // cout << mini << endl;
    }

    rep(i, distance.size()){
        R = max(R, distance[i]);
    }

    cout << fixed << setprecision(15) << R << endl;

    return 0;
}*/

// C問題

// Dが正の場合
/*ll binary_search_p(ll X, ll A, ll D){
    ll left = 0, right = (X-A)/D+2;
    ll mid;
    while(right-left>1){
        mid = (right+left)/2;
        if(A+(mid-1)*D>X) left = mid;
        else right = mid;
    }
    return right;
}
// Dが負の場合
ll binary_search_m(ll x, ll A, ll D){
    ll right = 0, right = (X-A)/D;
    ll mid;
    while(right-left>1){
        mid = (right+left)/2;
        if(A+(mid-1))
    }
}*/
/*ll f(ll A, ll N, ll D){
    return A+(N-1)*D;
}

int main(){
    ll X; cin >> X;
    ll A, D, n; cin >> A >> D >> n;

    if(D==0){
        cout << abs(A-X) << endl;
        return 0;
    }
    
    if(D>0){
        ll N = (X-A)/D + 1;
        if(N<=0){
            N = 1;
            ll mini = abs(X-f(A, N, D));
            cout << mini << endl;
            return 0;
        }
        if(N>=n){
            N=n;
            cout << abs(X-f(A, N, D)) << endl;
            return 0;
        }
        ll mini = min(abs(X-f(A, N, D)), abs(X-f(A, N+1, D)));
        cout << mini << endl;
        return 0;
    }

    if(D<0){
        ll N = (X-A)/D + 1;
        if(N<=0){
            N = 1;
            ll mini = abs(X-f(A, N, D));
            cout << mini << endl;
            return 0;
        }
        if(N>=n){
            N=n;
            cout << abs(X-f(A, N, D)) << endl;
            return 0;
        }
        ll mini = min(abs(X-f(A, N, D)), abs(X-f(A, N+1, D)));
        cout << mini << endl;
        return 0;
    }

    


    return 0;
}*/


int main(){
    ll N, Q; cin >> N >> Q;
    vector<ll> A(N);
    vector<ll> sum(Q);
    ll sum1 = 0;
    cin >> A[0];
    rep(i, N-1){
        cin >> A[i+1];
        A[i+1] -= A[0];
        sum1 += A[i+1];
    }
    rep(i, Q) sum[i] = sum1;
    cout << sum1 << endl;
    rep(i, Q){
        ll X; cin >> X;
        sum[i] -= (X-A[0]) * (N);
        cout << sum[i] << endl;
    }

    return 0;
}