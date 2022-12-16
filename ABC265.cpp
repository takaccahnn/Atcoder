#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

// C問題
/*int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    vector<vector<bool>> used(H, vector<bool>(W, false));

    rep(i, H){
        rep(j, W){
            cin >> G[i][j];
        }
    }

    int x, y;
    x = 0; y = 0;

    while(true){
        if(used[x][y]){
            cout << -1 << endl;
            break;
        }
        used[x][y] = true;
        if(G[x][y]=='U'){
            if(x-1<0){
                cout << x+1 << " " << y+1 << endl;
                break;
            }
            x-=1;
            continue;
        }
        if(G[x][y]=='D'){
            if(x+1>=H){
                cout << x+1 << " " << y+1 << endl;
                break;
            }
            x+=1;
            continue;
        }
        if(G[x][y]=='L'){
            if(y-1<0){
                cout << x+1 << " " << y+1 << endl;
                break;
            }
            y-=1;
            continue;
        }
        if(G[x][y]=='R'){
            if(y+1>=W){
                cout << x+1 << " " << y+1 << endl;
                break;
            }
            y+=1;
            continue;
        }
    }


    return 0;
}*/

// これ尺取り法っていうらしい。4つWAが出てくるんだけど、原因がわからない。
// D問題
int main(){
    int N; cin >> N;
    ll P, Q, R; cin >> P >> Q >> R;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll temp = A[0];
    auto left = 1;
    auto right = 0;


    // 半開区間[left, right)で考えたい
    while(true){
        if(temp==P){
            break;
        }
        if(right==N){
            cout << "No" << endl;
            return 0;
        }
        if(temp<P){
            temp+=A[right];
            right++;
        } else {
            temp-=A[left];
            left++;
        }
        
    }
    if(right==N){
        cout << "No" << endl;
        return 0;
    }
    left = right;
    right++;
    temp = A[left];


    while(true){
        if(temp==Q){
            break;
        }
        if(right==N){
            cout << "No" << endl;
            return 0;
        }
        if(temp<Q){
            temp+=A[right];
            right++;
        } else {
            temp-=A[left];
            left++;
        }
    }
    if(right==N){
        cout << "No" << endl;
        return 0;
    }
    left = right;
    right++;
    temp = A[left];

    while(true){
        if(temp==R){
            break;
        }
        if(right==N){
            cout << "No" << endl;
            return 0;
        }
        if(temp<R){
            temp+=A[right];
            right++;
        } else {
            temp-=A[left];
            left++;
        }
    }

    cout << "Yes" << endl;

    return 0;
}