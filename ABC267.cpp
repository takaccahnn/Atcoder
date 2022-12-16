#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<long long>>;
using node = pair<int, int>;
using ll = long long;

// A問題

// B問題
/*int main(){
    // stringなのに数字としてプログラムを書いてエラーを起こすミス
    // 数字を受け取った時は必ずintなのかcharなのかstringなのかを確認すること
    string s; cin >> s;
    vector<int> S(10);
    rep(i, 10) S[i] = s[i]-'0';
    if(S[0] != 0){
        cout << "No" << endl;
        return 0;
    }
    vector<bool> pin_all_fall(7, false);

    if(!S[6]) pin_all_fall[0] = true;
    if(!S[3]) pin_all_fall[1] = true;
    if(!S[1] and !S[7]) pin_all_fall[2] = true;
    if(!S[4] and !S[0]) pin_all_fall[3] = true;
    if(!S[2] and !S[8]) pin_all_fall[4] = true;
    if(!S[5]) pin_all_fall[5] = true;
    if(!S[9]) pin_all_fall[6] = true;
    
    rep(i, 7){
        bool jud1 = false;
        bool jud2 = false;
        if(pin_all_fall[i]){
            for(int j=i-1; j>=0; j--){
                if(!pin_all_fall[j]){
                    jud1 = true;
                    break;
                }
            }
            for(int k=i+1; k<7; k++){
                if(!pin_all_fall[k]){
                    jud2 = true;
                    break;
                }
            }
        }
        if(jud1 and jud2){
            cout << "Yes" << endl;
            return 0;
        }

    }

    cout << "No" << endl;

    return 0;
}*/

// C問題
// 部分和の考え方とか数学チックな問題だと思った
// 
/*int main(){
    int N, M; cin >> N >> M;
    vector<ll> particial_sum;
    vector<ll> A(N);
    ll temp=0;
    for(int i=0; i<M; i++){
        cin >> A[i];
        temp+=A[i];
    }
    particial_sum.push_back(temp);

    for(int i=M; i<=N-1; i++){
        cin >> A[i];
        temp += (-A[i-M]+A[i]);
        particial_sum.push_back(temp);
    }
   
    ll preresult = 0;
    rep(i, M) preresult+=(i+1)*A[i];

    ll max = preresult;

    rep(i, N-M){
        preresult = preresult - particial_sum[i] + M*A[i+M];
        if(preresult>max) max = preresult;
    }

    cout << max << endl;
}*/

// D問題(dfsと似たアルゴリズム)
// この解法は全探索なのでTLEになってしまう。しかしながら、dfsを用いて
// 再帰のアルゴリズムを応用したもので、考え方は非常に大事なので復習した
/*ll max_ans = 0;
vector<ll> maxElement(0);
ll max_num = 0;
vector<ll> A;
int M;


//　Aの配列のindexを使用しようとした時の長さjの部分列の和
void partialSum(int index, int j){
    if(M-j>A.size()-index){
        return;
    }
    if(j==M){
        if(max_ans<max_num) max_ans = max_num;
        return;
    }
    rep(i, 2){
        if(!(index+1<=A.size())){
            return;
        }
        if(i==1){
            ll temp = (j+1)*A[index];
            maxElement.push_back(temp);
            max_num += temp;
        }
        partialSum(index+1, j+i); 
        if(i==1){
            max_num-=maxElement.back();
            // 末尾の値を取り出す(要素はそのまま)
            maxElement.pop_back();
        }
    }
}

int main(){
    int N; cin >> N >> M;
    rep(i, N){
        ll temp1; cin >> temp1;
        A.push_back(temp1);
    }

    partialSum(0, 0);

    cout << max_ans << endl;

    return 0;

}*/

// D問題(dp)
int main(){
    int N, M; cin >> N >> M;
    vector<vector<ll>> dp(N, vector<ll>(M, -1e18));
    // Aの配列の要素Nまで用いて、部分列の長さがMだった時の最大値
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    rep(i, N){
        if(i==0){
            dp[0][0] = A[0];
            continue;
        }
        rep(j, M){
            if(j==0){
                dp[i][0] = max(dp[i-1][j], A[i]); 
            }
            if(i<j) continue;
            if(dp[i-1][j]!=-1e09 and i-1>=0) dp[i][j] = max(dp[i-1][j], dp[i][j]);
            if(j-1>=0 and i-1>=0 and dp[i-1][j-1]!=-1e18){
                ll temp = dp[i-1][j-1] + (j+1)*A[i];
                dp[i][j] = max(dp[i][j], temp);
            }
        }
    }

    cout << dp[N-1][M-1] << endl;

    return 0;
}


