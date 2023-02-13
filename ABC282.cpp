#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using ll = long long;
using node = pair<int, int>;

// C問題
int main(){
    int N; cin >> N;
    vector<char> ans(N);
    rep(i, N){
        char c; cin >> c;
        ans[i] = c;
    }

    int change = -1;
    rep(i, N){
        if(ans[i]=='"') change*=(-1);
        if(change==-1 and ans[i]==',') ans[i]='.';
    }

    rep(i, N) cout << ans[i];
    cout << endl;
}