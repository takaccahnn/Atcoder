#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

// B問題
/*int main(){
    string s, n; cin >> s >> n;
    bool jud = true;
    rep(i, s.size()){
        if(s[i]!=n[i]){
            jud = false;
            break;
        } else continue;
    }
    
    (jud)? cout << "Yes" : cout << "No";
    cout << endl;

    return 0;
}*/

// C問題
// 回転問題では、0からN-1までの番号をふり、移動する際は
//　要素数Nで余りに着目して考える

int main(){
    int N; cin >> N;
    vector<int> cook(N);
    // i番目の人はcook[i]の料理が置かれている
    rep(i, N) cin >> cook[i];


    vector<int> ans(N, 0);
    // i回転した時に正解となる人数の数

    rep(i, N){
        int move = (cook[i]-i+N)%N;
        ans[move]++;
        ans[(move+1)%N]++;
        ans[(move-1+N)%N]++;
    }

    int res = -1;

    rep(i, N){
        if(res<ans[i]) res = ans[i];
    }

    cout << res << endl;

    return 0;
}