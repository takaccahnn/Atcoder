#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


// A問題
/*int main(){
    string s;
    getline(cin, s);
    vector<bool> ans(10, false);
    rep(i, 9){
        int x = s[i] - '0';
        ans[x] = true;
    }
    
    rep(i, 10){
        if(ans[i] == false){
            cout << i << endl;
            return 0;
        }
    }
}*/

// B問題
/*int main(){
    ll A, B, K;
    cin >> A >> B >> K;

    int res = 0;
    while(A<B){
        A *= K;
        res++;
    }

    cout << res << endl;

    return 0;
}*/

// C問題
/*int main(){
    int N, M, K;
    cin >> N >> M >> K;
    // Nは配列の要素数　Mは配列の値の上限　Kは配列の値の総和の上限

    vector<vector<ll>> dp(N+1, vector<ll>(K+1, 0));
    // i項までの総和がjとなるような場合の数の総和
    
    dp[0][0] = 1;
    for(int i=0; i<N; i++){
        rep(l, K+1){
            if(dp[i][l]==0) continue;
            for(int m=1; m<M+1; m++){
                if(l+m<=K) dp[i+1][l+m]+=dp[i][l];
                dp[i+1][l+m]%=998244353;
            }
        }
    }

    ll sum = 0;
    for(int i=1; i<K+1; i++){
        sum += dp[N][i];
        sum%=998244353;
    }

    cout << sum << endl;
    
    return 0;
}*/

// D問題
int main(){
    int N;
    cin >> N;
    vector<vector<int>> count(N+1, vector<int>());
    // iの値がj番目に出てきた時、その値が配列Aでは何回目に出てきたか
    vector<int> A(N);
    rep(i, N){
        cin >> A[i];
        count[A[i]].push_back(i);
    }
    int Q;
    cin >> Q;
    rep(i, Q){
        int L, R, X;
        cin >> L >> R >> X;
        int res = 0;
        auto x = lower_bound(count[X].begin(), count[X].end(), L-1);
        auto y = upper_bound(count[X].begin(), count[X].end(), R-1);
        res = y-x;
        cout << res << endl;
    }

    return 0;

}