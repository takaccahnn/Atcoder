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
    int N; cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];

    int ans = 0, Max = 0;
    rep(i, N){
        if(ans<H[i]){
            ans = H[i];
            Max = i;
        }
    }

    cout << Max+1 << endl;
}*/

// B問題
/*int main(){
    vector<ll> A(6);
    rep(i, 6) cin >> A[i];

    ll r1=0, r2=0;
    rep(i, 3){
        if(i==0){
            r1+= A[i]%998244353;
            continue;
        }
        r1 *= A[i]%998244353;
        r1 %= 998244353;
    }

    FOR(i, 3, 5){
        if(i==3){
            r2+= A[i]%998244353;
            continue;
        }
        r2 *= A[i]%998244353;
        r2 %= 998244353;
    }
    if(r1>=r2){
        cout << (r1-r2)%998244353 << endl;
    } else {
        while(r1<r2){
            r1+=998244353;
        }
        cout << (r1-r2)%998244353 << endl;
    }
}*/

// C問題
/*int main(){
    vector<vector<char>> s(9, vector<char>(9));
    rep(i, 9){
        string S; cin >> S;
        rep(j, 9){
            s[i][j] = S[j];
        }
    }

    int ans = 0;
    // 数え方は行列と同じ、iが行を表、jが列を表す
    rep(i, 9){
        rep(j, 9){
            if(s[i][j]!='#') continue;
            FOR(k, i, 8){
                FOR(l, j+1, 8){
                    if(s[k][l]!='#') continue;
                    int v = k-i;
                    int h = l-j;
                    if(k+h>8) continue;
                    if(l-v<0) continue;
                    if(s[k+h][l-v]!='#') continue;
                    if(i+h>8) continue;
                    if(j-v<0) continue; 
                    if(s[i+h][j-v]!='#') continue;
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

}*/

// D問題
// C++では配列はコピーして渡される。だから、配列をメモリで渡したいときは
// 関数の宣言のところでメモリを指定してやらなければならない。それ以降はほとんどCと一緒
map<ll, ll> mp;

void f(ll N, map<ll, ll> &mp){
    if(N==0){
        mp[0] = 1;
        return;
    }
    if(mp[N/2]==0) f(N/2, mp);
    if(mp[N/3]==0) f(N/3, mp);

    mp[N] = mp[N/2] + mp[N/3];

    return;
}

int main(){
    ll N; cin >> N;

    f(N, mp);

    cout << mp[N] << endl;

    return 0;
}
