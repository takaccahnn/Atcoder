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
    int X, N; cin >> N >> X;
    vector<string> S(26);
    rep(i, 26){
        rep(j, N){
            S[i] += 'A'+i;
        }
    }
    string ans;
    rep(i, 26) ans += S[i];

    cout << ans[X-1] << endl;

    return 0;
}*/

//B問題
/*int main(){
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(K+1);
    FOR(i, 1, K) cin >> A[i];
    vector<int> L(Q+1);
    FOR(i, 1, Q) cin >> L[i];

    vector<bool> mas(N+1, false);
    FOR(i, 1, K) mas[A[i]] = true;
    
    FOR(i, 1, Q){
        if(A[L[i]]==N) continue;
        if(mas[A[L[i]]+1]) continue;
        // コマが横にあるならスキップ
        else {
            mas[A[L[i]]+1] = true;
            mas[A[L[i]]] = false;
            A[L[i]] += 1;
        }
    }

    rep(i, N+1){
        if(mas[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}*/


// C問題
int main(){
    int N; cin >> N;
    string S; cin >> S;
    vector<ll> adult;
    vector<ll> child;
    rep(i, N){
        ll x; cin >> x;
        if(S[i]=='1') adult.push_back(x);
        else child.push_back(x);
    }


    sort(adult.begin(), adult.end(), greater<ll>());
    sort(child.begin(), child.end(), greater<ll>());

    ll left = 0, right = 1000000000;
    ll ans = 0;

    /*auto itr_1 = lower_bound(adult.begin(), adult.end(), 0); 
    // 大人と判断できる数
    ll a1 = adult.end() - itr_1;
    cout << a1 << endl;

    auto itr_2 = lower_bound(child.begin(), child.end(), left);
    // 子供と判断できる数
    ll b1 = itr_2 - child.begin();
    cout << a1 << endl;*/


    while(right-left>1){

        auto itr_1 = lower_bound(adult.begin(), adult.end(), left); 
        // 大人と判断できる数
        ll a1 = adult.size() - (itr_1 - adult.begin());
        
        auto itr_2 = lower_bound(child.begin(), child.end(), left);
        // 子供と判断できる数
        ll b1 = itr_2 - child.begin();

        ll sum1 = a1 + b1;

        auto itr_3 = lower_bound(adult.begin(), adult.end(), right); 
        // 大人と判断できる数
        ll a2 = adult.size() - (itr_3 - adult.begin());

        auto tir_4 = lower_bound(child.begin(), child.end(), right);
        // 子供と判断できる数
        ll b2 = itr_2 - child.begin();

        ll sum2 = a2 + b2;

        if(sum1>=sum2){
            left = (right+left)/2;
            if(ans>sum1) break;
            else ans = sum1;
        } else {
            right = (right+left)/2;
            if(ans>sum2) break;
            else ans = sum2;
        }
        
    }

    cout << ans << endl;



    return 0;
}