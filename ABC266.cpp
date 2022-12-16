#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<long long, long long>;
using ll = long long;

// A問題
/*int main(){
    string S; cin >> S;
    cout << S[(S.size()+1)/2 - 1] << endl;

    return 0;
}*/

// B問題
/*int main(){
    ll N; cin >> N;
    ll X = 998244353;
    rep(i, 998244354){
        if((N-i)%X==0){
            cout << i << endl;
            return 0;
        } else continue;
    }

    return 0;
}*/

// C問題
/*int main(){
    vector<vector<double>> vertex(4, vector<double>(2));
    rep(i, 4){
        rep(j, 2) cin >> vertex[i][j];
    }

    vector<double> result_cos(4);

    rep(i, 4){
        double edge1, edge2, edge3;
        double A_x, A_y, B_x, B_y, C_x, C_y;
        A_x = vertex[i][0], A_y = vertex[i][1];
        B_x = vertex[(i+3)%4][0], B_y = vertex[(i+3)%4][1];
        C_x = vertex[(i+1)%4][0],  C_y = vertex[(i+1)%4][1];
        edge1 = sqrt((A_x - B_x)*(A_x - B_x)+(A_y - B_y)*(A_y - B_y));
        edge2 = sqrt((B_x - C_x)*(B_x - C_x)+(B_y - C_y)*(B_y - C_y));
        edge3 = sqrt((C_x - A_x)*(C_x - A_x)+(C_y - A_y)*(C_y - A_y));
        
        result_cos[i] = acos((edge3*edge3 + edge1*edge1 - edge2*edge2)/(2 * edge3 * edge1)) * 180 / 3.141593;
    }

    double sum = 0;
    rep(i, 4){
        sum += result_cos[i];
    }
    if(sum<=360.001 and sum>=359.990){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}*/

// D問題
int main(){
    int N; cin >> N;
    map<ll, ll> X;
    map<ll, ll> A; 
    rep(i, N){
        ll t, x, a; cin >> t >> x >> a;
        X[t] = x; A[t] = a;
    }

    vector<vector<ll>> dp(1e05+1, vector<ll>(5, -1));

    rep(i, 1e05+1){
        if(i==0){
            dp[0][0] = 0;
            continue;
        }

        rep(j, 5){
            if(j!=0){
                dp[i][j] = max(dp[i][j], max(dp[i-1][j-1], dp[i-1][j]));
            }
            if(j!=4){
                dp[i][j] = max(dp[i][j], max(dp[i-1][j+1], dp[i-1][j]));
            }
            if(X[i]==j and i>=X[i]) dp[i][j] += A[i];
        }
    }
    ll ans = 0;
    rep(i, 5){
        if(ans<dp[1e05][i]) ans = dp[1e05][i];
    }

    cout << ans << endl;

    
    return 0;
}
