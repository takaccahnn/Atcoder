#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

// A問題
/*int main(){
    double n;
    cin >> n;
    double left, right;
    left = n*log(2.0);
    right = 2*log(n);
    if(left>right) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}*/

// B問題
/*int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<bool> cut(361, false);
    cut[360] = true;
    int sum = 0;
    cut[0] = true;
    rep(i, N){
        sum+=A[i];
        sum %= 360;
        cut[sum] = true;
    }

    int ans = 0;
    int angle = 0;
    rep(i, 361){
        if(!cut[i]) angle++;
        else {
            ans = max(ans, angle+1);
            angle = 0;
        }
    }

    cout << ans << endl;

    return 0;
}*/

// C問題
/*long long f(long long x){
  x%=998244353;
  long long res=x;
  res*=(x+1);res%=998244353;
  res*=499122177;res%=998244353;
  return res;

}
int main(){
    ll N;
    cin >> N;
    int rank = 1;
    // (桁数+1)を表す
    ll temp = 1;
    while(N>temp){
        temp *= 10;
        rank++;
    }
    // cout << rank;

    
    ll down, up;
    down = 1; up = 1;
    ll sum = 0;
    for(int i=1; i<rank; i++){
        if(i!=1)down *= 10;
        if(i!=rank-1){
            up *= 10;
            sum += (f(up-down))%998244353;
            sum %= 998244353;
            // cout << down << endl;
        } else {
            up = N;
            sum += (f(up-down+1))%998244353;
            sum %= 998244353;
        }
        
    }

    cout << sum << endl;

    return 0;
}*/

// D問題
int main(){
    int T;
    cin >> T;
    rep(i, T){
        ll a, s; cin >> a >> s;
        bool jud = false;
        ll temp = a; 
        while(s-temp>=a){
            ll x = (s-temp)&(temp);
            if(x==a) jud = true;
            temp++;
        }
        if(jud) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    /*int a, b;
    a = 5; b = 3;
    int ans = (a&b);
    cout << ans << endl;*/

    return 0;
}