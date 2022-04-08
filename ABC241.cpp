#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
constexpr long long INF = (1LL << 62) - 1;
using ll = long long;


// C問題
/*int main(){
    int N;
    cin >> N;
    vector<vector<char>> s(N, vector<char>(N));
    rep(i, N){
        string S;
        cin >> S;
        rep(j, N) s[i][j] = S[j];
    }

    bool ans = false;
    // 横について調べる
    rep(i, N){
        int left = 0, right = 5, count_1 = 0;
        while(right<N){
            FOR(j, left, right){
                if(s[i][j]=='#') count_1++;
            }
            if(count_1>=4){
                ans = true;
                break;
            }
            count_1 = 0; left++; right++;
        }
        if(ans){
            cout << "Yes" << endl;
            return 0;
        }
    }
    // 縦について調べる
    rep(i, N){
        int top = 0, down = 5, count_2 = 0;
        while(down<N){
            FOR(j, top, down){
                if(s[j][i]=='#') count_2++;
            }
            if(count_2>=4){
                ans = true;
                break;
            }
            count_2 = 0; top++; down++;
        }
        if(ans){
            cout << "Yes" << endl;
            return 0;
        }
    }
    // 斜めについて調べる
    for(int i=5; i<N; i++){
        for(int j=5; j<N; j++){
            int count_3 = 0;
            int count_4 = 0;
            for(int k=0; k<6; k++){
                if(s[j-k][i-k]=='#') count_3++;
                if(s[j-k][i-5+k]=='#') count_4++;
            }
            if(count_3>=4){
                ans = true;
                break;
            }
            if(count_4>=4){
                ans = true;
                break;
            }
        }
        if(ans){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}*/

// D問題
struct fast_ios {
    fast_ios() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
} fast_ios;

int main(){
    int Q;
    cin >> Q;
    multiset<ll> a;
    vector<ll> res(0);
    int number, k; 
    ll x;
    rep(i, 5) a.insert(INF);
    rep(i, 5) a.insert(-INF);
    rep(i, Q){
        cin >> number >> x;
        if(number == 1) a.insert(x);
        if(number == 2){
            cin >> k;
            auto itr = a.upper_bound(x);
            rep(j, k) --itr;
            ll ans = *itr != -INF ? *itr : -1;
            res.push_back(ans);
        }
        if(number == 3){
            cin >> k;
            auto itr = a.lower_bound(x);
            rep(j, k-1) ++itr;
            ll ans = *itr != INF ? *itr : -1;
            cout << ans << endl;
            res.push_back(ans);
        }
    }
    rep(i, res.size()) cout << res[i] << endl;
}