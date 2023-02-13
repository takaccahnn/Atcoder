#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using ll = long long;
using node = pair<int, int>;

// A問題
/*int main(){
    string s; cin >> s;
    rep(i, s.size()){
        if(s[i]=='0'){
            s[i] = '1';
            continue;
        }
        if(s[i]=='1'){
            s[i] = '0';
            continue;
        }
    }

    cout << s << endl;

    return 0;
}*/

// B問題
/*void dfs(Graph a, int b, int &time, stack<int> &temp){
    temp.push(b);
    if(a[b].size()==0){
        time = b;
        return;
    }
    for(auto i: a[b]){
        dfs(a, i, time, temp);
    }
}

int main(){
    int N, M; cin >> N >> M;
    vector<int> a(M);
    rep(i, M) cin >> a[i];
    Graph G(N+1, vector<int>());

    rep(i, M){
        G[a[i]].push_back(a[i]+1);
    }

    vector<int> ans;
    int step = 1;
    stack<int> temp;
    while(true){
        if(step>N) break;
        if(G[step].size()){
            int p = step;
            dfs(G, p, step, temp);
            while(temp.size()){
                int m = temp.top();
                temp.pop();
                ans.push_back(m);
            }
        } else {
            ans.push_back(step);
        }
        step++;
    }

    rep(i, ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
}*/

// B問題(dfsを使わない場合の解法、尺取り法)
/*int main(){
    queue<int> ans;
    int N, M; cin >> N >> M;
    vector<int> a(M);
    rep(j, M) cin >> a[j];
    if(M==0){
        FOR(j, 1, N) cout << j << " ";
        cout << endl;
        return 0;
    }

    int step = 0;
    int left = 1;
    while(left<=N){
        if(a[step]!=left){
            ans.push(left);
            left++;
            continue;
        }
        int right;
        right = left;
        while(a[step]==right){
            if(step>M-1){
                right=M-1;
                step=M-1;
                break;
            }
            right++;
            step++;
        }
        for(int k=right; k>=left; k--){
            ans.push(k);
        }
        left = right+1;
    }

    int length = ans.size();
    rep(j, length){
        cout << ans.front() << " ";
        ans.pop();
    }
}*/

// C問題
/*int main(){
    int N, M; cin >> N >> M;
    vector<vector<int>> a(M, vector<int>());
    rep(i, M){
        int c; cin >> c;
        rep(j, c){
            int temp; cin >> temp;
            a[i].push_back(temp);
        }
    }
    
    int ans = 0;
    for(int i=0; i < (1<<M); i++){
        vector<bool> exist(N+1, false);
        exist[0] = true;
        for(int j=0; j<M; j++){
            if(i & (1<<j)){
                for(auto k: a[j]){
                    exist[k] = true;
                }
            }
        }
        rep(j, N+1){
            if(!exist[j]) break;
            if(j==N) ans++;
        }
    }

    cout << ans << endl;
    
}*/

// D問題
// このやり方でもいいが、普通は使えない駒の位置を表す配列cangoを新たに用意し
// dpで移動できるマスは1、移動できないマスは0に設定し、cangoを参照しながら
// 動的計画法を実施するのがオーソドックス的なやり方なのだとは思う
/*int main(){
    int N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    int M; cin >> M;
    vector<ll> B(M);
    rep(i, M) cin >> B[i];
    ll X; cin >> X;

    vector<node> dp(100000+1);
    dp[0].first = 1;
    rep(i, M){
        dp[B[i]].second = -1;
    }

    rep(i, 100000){
        if(dp[i].second==-1){
            continue;
        } else {
            if(dp[i].first==0){
                continue;
            } else {
                for(auto p: A){
                    if(i+p>100000) continue;
                    if(dp[i+p].second!=-1) dp[i+p].first=1;
                }
            }
        }   
    }
    if(dp[X].first==0) cout << "No" << endl;
    else cout << "Yes" << endl;
}*/

