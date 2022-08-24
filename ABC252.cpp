#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

// C問題
int main(){
    int N; cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<vector<int>> a(N, vector<int>(10));
    //  N個の文字列に対して、それぞれの数字が何番目に出たのかを収納する配列
    rep(i, N){
        rep(j, 10){
            int x = S[i][j] - '0';
            a[i][x] = j;
        }
    }

    int ans = 1<<8;
    rep(i, 10){
    // 0から9までの数字のそれぞれについて考える
        int max_num = 0;
        vector<int> used(10, 0);
        // 何番目に文字列が何個入ってるかをあらわす
        int x = 0;
        rep(j, N){
            used[a[j][i]]++;
            max_num = max(max_num, used[a[j][i]]);
        }
        rrep(j, 10){
           if(max_num == used[j]){
               x += j;
               break;
           }
        }
        x += 10*(max_num-1);
        ans = min(ans, x);
    }
    
    cout << ans << endl;


    return 0;
}
