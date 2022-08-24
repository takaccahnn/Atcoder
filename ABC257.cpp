#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

// A問題
/*int main(){
    int N; cin >> N;
    ll ans = 1;
    if(N==0) cout << 1 << endl;
    else {
        rep(i, N){
            ans*=2;
        }
        cout << ans << endl;
    }

    return 0;
}*/

// B問題
/*int main(){
    int N; cin >> N;
    vector<vector<bool>> on(N+1, vector<bool>(4, false));
    int score = 0;

    rep(i, N){
        int A; cin >> A;
        on[i][0] = true;
        rep(j, 4){
            if(on[i][j]){
                if(j+A>3) score++;
                else {
                    on[i+1][j+A] = true;
                }
            }
        }
    }

    cout << score << endl;


    return 0;
}*/

// C問題
/*int main(){
    // vector<vector<vector<int>>> mas(100000, vector<int>(3, vector<int>(3)));
    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >>w1 >> w2 >> w3;
    int a11 = 0, a12 = 0, a13 = 0;
    int a21 = 0, a22 = 0, a23 = 0;
    int a31 = 0, a32 = 0, a33 = 0;
    int ans = 0;
    FOR(a11, 1, h1-2){
        FOR(a12, 1, h1-a11-1){
            a13 = h1 - a11 - a12;
            FOR(a21, 1, w1-a11-1){
                a31 = w1 - a11 - a21;
                if(a31<=0) continue;
                FOR(a22, 1, h2-a21-1){
                    a23 = h2 - a21 - a22;
                    if(a23<=0) continue;
                    a32 = w2 - a12 - a22;
                    if(a32<=0) continue;
                    a33 = w3 - a13 - a23;
                    if(a33<=0) continue;
                    if(a31+a32+a33!=h3) continue;
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}*/

// D問題
int main(){
    vector<node> s();
    int N; cin >> N;
    rep(i, N){
        int right, left; cin >> right >> left;
        if(i==0){
            s.push_back(make_pair(left, right));
            continue;
        }
        rep(j, s.size()){
            if(left < s[j].first){
                if(right<s[j.first]) s.push_bacl(make_pair(left, right));
                else if(s.second<left){
                    s[j].first = left;
                    s[j].second = right;
                } else {
                    s[j].first = left;
                }
            } else {
                if(s[j].second+1<left) continue; 
                else {
                    if(right<=s[j].second) continue;
                    } else s[j].second = left;
            }
        
    }

    rep(j, s.size()){
            
        }

    return 0;
}