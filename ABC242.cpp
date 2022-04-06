#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

// A問題
/*int main(){
    int A, B, C, D;
    // Aまでは必ずもらえる。A+1からBまではランダムでC人選ばれる。順位はD
    cin >> A >> B >> C >> D;
    
    double rate = 1.000;
    if(D<=A) cout << rate << endl;
    if(A+1<=D and D<=B){
        rate = (double)C/(B-A);
        cout << rate << endl;
    } 
    if(B+1<=D){
        rate = 0;
        cout << rate << endl;
    }

    return 0;
}*/

// B問題
/*int main(){
    string S;
    cin >> S;
    
    sort(S.begin(), S.end());
    cout << S << endl;
    return 0;
}*/

// C問題(dp)
int main(){
    int N;
    cin >> N;

    long long ans = 0;
    // dp[各桁で何個生成できるか][桁の値] 0は何も値が生成できない
    vector<vector<long long>> dp(N+1, vector<long long>(10, 0));
    
    rep(i, 10) dp[1][i] = 1;
    // 動的計画法        
    for(int j=2; j<=N; j++){
        for(int l=1; l<10; l++){
            dp[j][l] += dp[j-1][l]%998244353;
            if(l+1<=9) dp[j][l+1] += dp[j-1][l]%998244353;
    
            if(l-1>=1) dp[j][l-1] += dp[j-1][l]%998244353;            
        }
    }
    for(int m=1; m<10; m++) {
        ans += dp[N][m];
        ans %= 998244353;
    }


    cout << ans << endl;
    
    return 0;
}