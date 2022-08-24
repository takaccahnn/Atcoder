#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define rep(i,n) for(long long i=0;i<(n);i++)
#define rrep(i,n) for(long long i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;
struct inf{
    ll sum;
    int max_mum;
    int mini;
};

// A問題
/*int main(){
    vector<int> a(3);
    vector<int> b(3);
    rep(i, 3){
        int temp; cin >> temp;
        a[i] = temp;
        b[i] = temp;
    }
    sort(a.begin(), a.end());
    if(a[1] == b[1]){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    

    return 0;
}*/

// B問題
/*int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> mas(H, vector<char>(W));
    vector<node> koma;
    rep(i, H){
        string s; cin >> s;
        rep(j, W){
            mas[i][j] = s[j];
            if(s[j]=='o'){
                koma.push_back(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    ans += abs(koma[1].first-koma[0].first);
    ans += abs(koma[1].second-koma[0].second);

    cout << ans << endl;

    return 0;
}*/

// C問題
/*int main(){
    set<int> in;
    // 入っている数字の集合
    map<int, int> count;
    // 入っている数字の数
    int Q; cin >> Q;
    rep(i, Q){
        int j; cin >> j;
        if(j==1){
            int x; cin >> x;
            in.insert(x);
            count[x]++;
            continue;
        }
        if(j==2){
            int x, c; cin >> x >> c;
            int min_num;
            min_num = min(count[x], c);
            if(min_num==count[x]){
                if(min_num==0) continue;
                in.erase(x);
                count[x] = 0;
                continue;
            } else {
                count[x] -= c;
                continue;
            }
        }
        auto itr1 = in.begin();
        auto itr2 = in.rbegin();
        cout << *itr2-*itr1 << endl;
    }

    return 0;
}*/

// D問題
/*int main(){
    ll N, A, B; cin >> N >> A >> B;
    ll D = A/gcd(A, B)*B;
    ll A_r = N/A; ll B_r = N/B; ll D_r =N/D;
    ll sum = N * (N+1)/ 2;
    ll A_sum = A * A_r * (A_r+1) / 2;
    ll B_sum = B * B_r * (B_r+1) / 2;
    ll D_sum = D * D_r * (D_r+1) / 2;
    sum = sum -(A_sum+B_sum-D_sum);

    cout << sum << endl;


    return 0;
}*/

// E問題
int main(){

    ll N, M, K; cin >> N >> M >> K;
    vector<vector<ll>> dp(N, vector<ll>(M+1, 0));
    vector<vector<ll>> s(N, vector<ll>(M+1, 0));
    // 累積和を計算 i列めの値はdp[][1]からdp[][i]までの部分話
    FOR(i, 1, M) dp[0][i] = 1;

    FOR(i, 1, N-1){
        FOR(l, 1, M) s[i-1][l] += (dp[i-1][l] + s[i-1][l-1])%998244353;
        FOR(j, 1, M){
            if(-K+j>=1) dp[i][j] += s[i-1][-K+j] % 998244353;
            if(K+j<=M) dp[i][j] += (s[i-1][M] - s[i-1][K+j-1] + 998244353 ) % 998244353;
            if(K==0) dp[i][j] = (dp[i][j] - s[i-1][K+j] + 998244353) % 998244353;
        }
        // ここの処理のロジックの部分をしっかりと考えないとだめ
    }

    ll sum = 0;
    FOR(i, 1, M){
        sum += dp[N-1][i]%998244353;
    }
    
    cout << sum%998244353 << endl;
    

    


    return 0;
}