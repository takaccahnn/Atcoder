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
double f(ll* n, double A, double B){
    return *n*B + A/(sqrt(1+*n));
}

/*int main(){
    double A, B; cin >> A >> B;
    double frac = A/(2*B);
    // cout << (double)pow(frac, 2/3) << endl;
    double x = pow(frac, 2.0/3.0) -1;
    // cout << x << endl;
    double ans = 1e18;
    for(ll i = x-2; i<=x+2; i++){
        if(i<0) continue;
        ans = min(ans, f(i, A, B));
    }

    cout << ans << endl;
}*/

int main(){
    ll A, B; cin >> A >> B;
    ll left, right; 
    left = 0, right = 1e13;
    ll mid1, mid2;
    double mid1_time, mid2_time;
    while((right-left)>2){
        mid1 = (2*left+right)/3;
        mid2 = (left+2*right)/3;
        mid1_time = f(&mid1, A, B);
        mid2_time = f(&mid2, A, B);
        if(mid1_time>mid2_time){
            left = mid1;
        } else {
            right = mid2;
        }
    }
    double ans = 1e13;
    for(ll i=left-1; i<=right+1; i++){
        ans = min(ans, f(&i, A, B));
    }

    cout << fixed << setprecision(10) << ans << endl;
}



