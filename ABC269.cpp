
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

// C問題
// bitsetというSTLを使ってみる
/*
bitset<ビット数> 変数名("ビット列(長さはビット数に合わせる)"もしくは整数の値);
用いることができる演算子は、~のNOT演算子、^のXOR演算子、<<や>>のビット列の移動がある
変数.test(調べる位置)でビットが1になっているかを調べることができる。1ならtrueを返す
詳しいことはこのサイト(https://atcoder.jp/contests/apg4b/tasks/APG4b_ac?lang=ja)
を見ると詳しく書いてある

*/
/*int main(){
    ll N; cin >> N;
    bitset<60> bs(N);
    ll degit = 1;
    vector<ll> bitIsTrue;
    rep(i, 60){
        if(i==0){
            if(bs.test(0)) bitIsTrue.push_back(1);
            continue;
        }
        degit*=2;
        if(bs.test(i)) bitIsTrue.push_back(degit);
    }
    
    rep(i, 1<<bitIsTrue.size()){
        ll partialSum = 0;
        rep(j, bitIsTrue.size()){
            if(i & 1 << j){
                partialSum+=bitIsTrue[j];
            }
        }
        cout << partialSum << endl;
    }

    return 0;
}*/


void dfs(vector<vector<bool>> &black, int x, int y, int time){
    black[x][y] = false;
    
    if(black[x-1][y-1]){
        dfs(black, x-1, y-1, time+1);
        black[x-1][y-1] = true;
    }
    if(black[x-1][y]){
        dfs(black, x-1, y, time+1);
        black[x-1][y] = true;
    }
    if(black[x][y-1]){
        dfs(black, x, y-1, time+1);
        black[x][y-1] = true;
    }
    if(black[x][y+1]){
        dfs(black, x, y+1, time+1);
        black[x][y+1] = true;
    }
    if(black[x+1][y]){
        dfs(black, x+1, y, time+1);
        black[x+1][y] = true;
    }
    if(black[x+1][y+1]){
        dfs(black, x+1, y+1, time+1);
        black[x+1][y+1] = true;
    }

    black[x][y] = true;
}



// D問題
/*int main(){
    int N; cin >> N;
    vector<node> arr(N);
    vector<vector<bool>> black(2005, vector<bool>(2005, false));
    rep(i, N){
        int a, b; cin >> a >> b;
        a+=1001; b+=1001;
        arr[i] = node(a, b);
        black[a][b] = true;
    }

    vector<int> xGo = {-1, -1, 0, 0, 1, 1};
    vector<int> yGo = {-1, 0, -1, 1, 0, 1};
    
    int ans = 0;
    rep(i, 2003){
        rep(k, 2003){
            if(!black[i][k]) continue;
            ans++;
            queue<node> next;
            next.push(node(i, k));
            black[i][k] = false;
            while(!next.empty()){
                int x = next.front().first;
                int y = next.front().second;
                next.pop();
                rep(j, 6){
                    if(!black[x+xGo[j]][y+yGo[j]]) continue;
                    next.push(node((x+xGo[j]), y+yGo[j]));
                    black[x+xGo[j]][y+yGo[j]] = false;
                }
            }
        }
    }

    cout << ans << endl;
}*/

// E問題
int main(){
    int N; cin >> N;
    int up = 1;
    int down = N;
    int left = 1;
    int right = N;

   
    // まず上と下について
    while(down!=up){
        int mid = up + (down-up)/2;
        cout << "?" << " " << up << " " << mid << " " << 1 << " " << N << endl;
        int T; cin >> T;
        if(T==mid - up + 1){
            up = mid+1;
        } else {
            down = mid;
        }
    }

    while(right!=left){
        int mid = left + (right-left)/2;
        cout << "?" << " " << 1 << " " << N << " " << left << " " << mid << endl;
        int t; cin >> t;

        if(t==mid - left + 1){
            left = mid+1;
        } else {               
            right = mid;
        }
    }

    cout << "!" << " " << down << " " << right << endl;
}

