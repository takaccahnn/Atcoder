#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using ll = long long;
using node = pair<ll, ll>;

// A問題
/*int main(){
    string S; cin >> S;
    int ans = 0;
    rep(i, S.size()){
        if(S[i]=='v'){
            ans++;
            continue;
        }
        if(S[i]=='w') ans+=2;
    } 

    cout << ans << endl;
}*/

// B問題
/*int main(){
    string S, T; cin >> S >> T;
    int size = T.size();
    int same = 0;
    rep(i, S.size()){
        if(S[i]==T[same]){
            same++;
        } else {
            same = 0;
        }
        if(same==size){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}*/

// C問題
/*int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    vector<vector<char>> T(H, vector<char>(W));

    rep(i, H){
        string s; cin >> s;
        rep(j, W){
            S[i][j] = s[j];
        }
    }
    rep(i, H){
        string s; cin >> s;
        rep(j, W){
            T[i][j] = s[j];
        }
    }

    map<string, int> mps;
    map<string, int> mpt;

    rep(i, W){
        string s;
        rep(j, H){
            s+=S[j][i];
        }
        mps[s]+=1;
    }
    rep(i, W){
        string s;
        rep(j, H){
            s+=T[j][i];
        }
        mpt[s]+=1;
    }

    for(auto a: mps){
        if(mpt[a.first]==a.second){
            continue;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

}*/

//D問題
long double f(double A, double B, ll a){
    return B*a+A/sqrt(1+a);
}



int main(){
    long double A, B; cin >> A >> B;
    long double frac = A/(2*B);
    long double x = (long long)pow(frac, 2/3) -1;
    ll right, left;
    right = (ll)x+1;
    left = (ll)x-1;
    cout << "x=" << frac << endl;

    if(x<=0){
        cout << f(A, B, 0) << endl;
        return 0;
    } else {
        cout << min(f(A, B, right), f(A, B, left)) << endl;
        return 0;
    }
}
