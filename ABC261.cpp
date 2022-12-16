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
    int L1, R1, L2, R2; cin >> L1 >> R1 >> L2 >> R2;
    vector<bool> line(1001, false);
    FOR(i, L1, R1) line[i] = true;

    int ans = 0;
    FOR(j, L2, R2){
        if(line[j]) ans++;
    }
    
    if(ans==0) cout << "0" << endl;
    else cout << ans-1 << endl;

    return 0;
}*/

// B問題
/*int main(){
    int N; cin >> N;
    vector<vector<char>> result(N, vector<char>(N));
    rep(i, N){
        rep(j, N){
            cin >> result[i][j];
        }
    }

    rep(i, N-1){
        for(int j=i+1; j<N; j++){
            char a, b;
            a = result[i][j]; b = result[j][i];
            if(a=='W'){
                if(b=='L'){
                    continue;
                } else {
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
            if(a=='L'){
                if(b=='W'){
                    continue;
                } else {
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
            if(a=='D'){
                if(b=='D'){
                    continue;
                } else {
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "correct" << endl;

    return 0;
}*/

// C問題
/*int main(){
    int N; cin >> N;
    map<string, int> mp;
    rep(i, N){
        string s; cin >> s;
        if(mp[s]==0) cout << s << endl;
        else {
            cout << s << "(" << mp[s] << ")" << endl;
        }
        mp[s]++;
    }

    return 0;
}*/

// D問題


ll max, N, M;
vector<node> C(M);
vector<ll> X(N);

ll bonus(ll time){
    rep(i, C.size){
        if(C[i].first==time) return C[i].second;
    }
    return 0;
}

void getMoney(ll time, ll count, ll money){
    if(time==N) return max;
    getMoney(time+1, 0, money);
    ll a = money+X[count+1]+bonus(count+1);
    getMoney(time+1, count+1, a);
    if(a>max) max = a;
}

int main(){
    cin >> N >> M;
    rep(i, N) cin >> X[i];
    rep(i, M) cin >> C[i].first >> C[i].second;

    getMoney(0, 0, 0);

    return 0;
}