#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using ll = long long;

//  A問題
/*int main(){
    
    string s; cin >> s;
    int a, b; cin >> a >> b;

    char x = s[a-1];
    s[a-1] = s[b-1];
    s[b-1] = x;

    cout << s << endl;

    return 0;
}*/

// B問題
/*int main(){

    int N; cin >> N;
    int size = 4*N-1;
    vector<int> given(N+1, 0);
    rep(i, size){
        int x; cin >> x;
        given[x]++;
    }

    FOR(i, 1, N){
        if(given[i]!=4){
            cout << i << endl;
            return 0;
        }
    }


    return 0;
}*/

// C問題
/*int main(){

    int n, m; cin >> n >> m;
    vector<string> local(n);
    rep(i, n) cin >> local[i];
    vector<bool> stop(n, false);

    int j = 0;
    rep(i, m){
        string s; cin >> s;
        while(local[j]!=s){
            j++;
        }
        stop[j] = true;
        j++;
    }

    rep(i, n){
        if(stop[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}*/

vector<pair<int, int>> vec;
vector<bool> used(16);
int ans = 0;
// 上の様に予め関数外で変数を宣言してやることで、関数で再三宣言しなければいけない手間を省くことができる
// 今回の問題で学んだと -> 再帰の呼び出しによりグループから特定の集団を作る際、条件に最も適したグループを作ることができる

// D問題
int calc(int n, vector<vector<int>> &a){
    // 組み合わせを考えたい
    // 今まで番号が使われているならtrue, 使われていないならfalseを返す配列 used
    // 組み合わせを収納した配列 vec
    // 二人の相性値を収納している配列 a
    // 出力値は相性の最大値
    
    
    if(vec.size()==n){
        int res = 0;
        for(auto p: vec){
            res = res ^ a[p.first][p.second];
        }
        return res;
    }

    int x;
    rep(i, 2*n){
        if(!used[i]){
            used[i] = true;
            x = i;
            break;
        }
    }

    int x1;
    rep(i, 2*n){
        if(!used[i]){
            used[i] = true;
            x1 = i;
            vec.push_back(make_pair(x, x1));
            ans = max(calc(n, a), ans);
            vec.pop_back();
            used[x1] = false;
        }
    }
    used[x] = false;
    
    return ans;

}


int main(){
    
    int n; cin >> n;
    vector<vector<int>> a(2*n, vector<int>(2*n));

    rep(i, 2*n-1){
        FOR(j, i+1, 2*n-1){
            int x; cin >> x;
            a[i][j] = x;
        }
    }

    cout << calc(n, a) << endl;


    return 0;
}

