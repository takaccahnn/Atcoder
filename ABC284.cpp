#include <bits/stdc++.h>
    using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using ll = long long;
using node = pair<int, int>;

// C問題　
bool isPrime(ll N){
    if(N==1) return false;
    if(N==2) return true;
    FOR(i, 2, sqrt(N)){
        if(N%i==0) return false;
    }
    return true;
}

int main(){
    int T; cin >> T;
    rep(i, T){
        ll N; cin >> N;
        ll size = pow(N, 1.0/3.0);
        for(ll j=2; j<=size; j++){
            if(N%j!=0) continue;
            double a, b;
            a = sqrt(N/j);
            // b = (double)N/(j*j);
            // if(b==(ll)b)と書くとエラーが生じる
            if(N%(j*j)==0){
                cout << j << " " << (ll)N/(j*j) << endl;
                break;
            } else {
                cout << (ll)a << " " << j << endl;
                break;
            }
        }
    }
}

