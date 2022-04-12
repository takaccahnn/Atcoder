#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)

// C問題(dpだね。見た瞬間に察したわ)
int main(){
    int N, X;
    cin >> N >> X;
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];
    vector<vector<bool>> ans(N, vector<bool>(10000, false));

    rep(i, N){
        if(i==0){
            ans[i][a[i]] = true;
            ans[i][b[i]] = true;
            continue;
        }
        rep(j, 10001){
            if(ans[i-1][j]==true){
                ans[i][j+a[i]] = true;
                ans[i][j+b[i]] = true;
            }
        }
    }

    if(ans[N-1][X]==true) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}

