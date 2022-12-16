#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<long long, long long>;
using ll = long long;

// A問題
/*int sum(int N){
    if(N==1) return 1;
    return N*sum(N-1);
}

int main(){
    int N; cin >> N;
    if(N==0){
        cout << 1 << endl;
        return 0;
    }

    cout << sum(N) << endl;

    return 0;
}*/

// B問題
/*int main(){
    ll X, K; cin >> X >> K;

    rep(i, K){
        ll digit = pow(10, (i+1));
        ll number = X%digit;
        if(number>=5*pow(10, i)){
            X-=number;
            X+=digit;
        } else {
            X-=number;
        }
    }
    
    cout << X << endl;
}*/

// C問題
/*int main(){
    int N; cin >> N;
    vector<ll> A(N), B(N), C;
    map<ll, bool> mp;
    rep(i, N){
        ll a; cin >> a;
        A[i] = a; B[i] = a;
        if(!mp[a]){
            C.push_back(a);
            mp[a] = true;
        }
    }

    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    // Cは数字の種類を格納
    ll Max = B[N-1];

    // ans(i)=j jよりも大きい数字の種類はi種類
    vector<ll> ans(C.size());
    ll Csize = C.size();
    rep(i, Csize){
        ans[i] = C[Csize-i-1];
    }

    rep(i, N){
        if(i>Csize-1){
            cout << 0 << endl;
            continue;
        }
        auto minus = upper_bound(B.begin(), B.end(), ans[i]) - lower_bound(B.begin(), B.end(), ans[i]); 
        cout << minus << endl;
    }

    return 0;
}*/

// D問題
int main(){
    map<ll, set<ll>> mpColum;
    // 同じ列のものの値を入れる
    map<ll, set<ll>> mpLine;
    // 同じ行のものの値を入れる

    ll H, W; cin >> H >> W;
    ll x, y; cin >> x >> y;
    // 現在プレイヤーがいる場所(数え方は行列と一緒)

    int N; cin >> N;
    rep(i, N){
        ll r, c; cin >> r >> c;
        mpColum[c].insert(r);
        mpLine[r].insert(c);
    }

    int Q; cin >> Q;
    rep(i, Q){
        char d; cin >> d;
        ll l; cin >> l;
        if(d=='L'){
            if(!mpLine[x].size()){
                if(y-l<=0) y=1;
                else y-=l;
                cout << x << " " << y << endl;
                continue;
            }
            auto itr = mpLine[x].end();
            itr--;
            while(true){
                if(*itr<y and y-l<=*itr){
                    y = *itr + 1;
                    cout << x << " " << y << endl;
                    break;
                }
                if(itr==mpLine[x].begin()){
                    if(y-l<=0) y=1;
                    else y-=l;
                    cout << x << " " << y << endl;
                    break;
                }
                itr--;
            }
        }

        if(d=='R'){
            if(!mpLine[x].size()){
                if(y+l<=W){
                    y += l;
                    cout << x << " " << y << endl;
                    continue;
                } else {
                    y=W;
                    cout << x << " " << y << endl;
                    continue;
                }
            }
            auto itr = lower_bound(mpLine[x].begin(), mpLine[x].end(), y);
            if(*itr<=y+l){
                y = *itr-1;
                cout << x << " " << y << endl;
                continue;
            } else {
                if(y+l<=W)y += l;
                else y=W;
                cout << x << " " << y << endl;
                continue;
            }
        }

        if(d=='U'){
            if(!mpColum[y].size()){
                if(x-l<=0) x=1;
                else x-=l;
                cout << x << " " << y << endl;
                continue;
            }
            auto itr = mpColum[y].end();
            while(1){
                if(*itr<x and x-l<=*itr){
                    x=*itr+1;
                    cout << x << " " << y << endl;
                    break;
                }
                if(itr==mpColum[y].begin()){
                    if(x-l<=0) x=1;
                    else x-=l;
                    cout << x << " " << y << endl;
                    break;
                }
                itr--;
            }
        }

        if(d=='D'){
            if(!mpColum[y].size()){
                if(x+l<=H){
                    x += l;
                    cout << x << " " << y << endl;
                    continue;
                } else {
                    x = H;
                    cout << x << " " << y << endl;
                    continue;
                }
            }
            auto itr = lower_bound(mpColum[y].begin(), mpColum[y].end(), x);
            if(*itr<=x+l){
                x = *itr-1;
                cout << x << " " << y << endl;
                continue;
            } else {
                if(x+l<=H)x += l;
                else x = H;
                cout << x << " " << y << endl;
                continue;
            }
        }
    }


    return 0;
}