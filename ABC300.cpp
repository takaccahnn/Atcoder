#include  <bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0; i<(N); i++)
#define FOR(i, a, b) for(int i=(a); i<=(b); i++)
#define rrep(i, N) for(int i=(N)-1; i>=0; i--)
using ll = long long;
using Graph = vector<vector<int>>;
using node = pair<int, int>;

// A問題
/*int main(){
    int N, A, B; cin >> N >> A >> B;
    int ans = A+B;
    rep(i, N){
        int c; cin >> c;
        if(c==ans){
            cout << i+1 << endl;
        }
    }
    return 0;
}*/

// B問題(行及び列基本変形の数は高々知れているので全探索?)
int main(){
    int H, W; cin >> H >> W;
    vector<string> A(H), B(H);
    rep(i, H) cin >> A[i];
    rep(i, H) cin >> B[i];
    
    vector<vector<char>> a(H, vector<char>(W));

    // i行j列ずらした場合を考える
    rep(i, H){
        rep(j, W){
            bool isTrue = true;
            rep(k, H){
                rep(l, W){
                    a[(k+i)%H][(l+j)%W] = A[k][l];
                    if(a[(k+i)%H][(l+j)%W] != B[(k+i)%H][(l+j)%W]){
                        isTrue = false;
                        break;
                    }
                }
                if(!isTrue) break;
            }
            if(isTrue){
                cout << "Yes" << endl;
                return 0;
            } else continue;
        }
    }

    cout << "No" << endl;
}

// C問題