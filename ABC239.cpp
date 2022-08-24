#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)

// A問題
/*int main(){
    ll H;
    cin >> H;
    cout << fixed << setprecision(10) << sqrt((double)H*(12800000+H)) << endl;

    return 0;
}*/

// B問題
/*int main(){
    ll X;
    cin >> X;

    // あまりを計算
    ll r = X % 10;

    if(X<0 and r!=0) cout << X/10-1 << endl;
    else cout << X/10 << endl;

    

    return 0;

}*/

// C問題
/*int main(){
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<pair<ll, ll>> ans;
    bool exist = false;

    for(int i=-2; i<3; i++){
        for(int j=-2; j<3; j++){
            ll temp;
            ll x, y;
            x = x1+i; y = y1+j;
            if((x-x1)*(x-x1)+(y-y1)*(y-y1)==5 and
                (x-x2)*(x-x2)+(y-y2)*(y-y2)==5){
                    cout << "Yes" << endl;
                    return 0;
                }
        }   
    }

    cout << "No" << endl;

    return 0;
}*/

// D問題
/*bool isprime(int x){
    if(x==2) return true;
    if(x==1) return false;
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;

}
int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // Aokiの出した数字に対して、Takahashiが出せるかどうかを調べる
    // 一つでもTakahashiが出せなければ、Aokiの勝ちが決まる
    for(int i=A; i<=B; i++){
        // Aokiが勝てる数字の数を入れる(1以上ならAokiの勝ちなのでok)
        int jud = 0;
        for(int j=C; j<=D; j++){
            int sum = i+j;
            if(isprime(sum)) jud++;
        }
        if(!jud){
            cout << "Takahashi" << endl;
            return 0;
        }
    }

    cout << "Aoki" << endl;

    return 0;
}*/

// E問題
int main(){
    int N, Q; cin >> N >> Q;
    vector<int> X(N);
    rep(i, N) cin >> X[i];
    vector<vector<int>> a(N, vector<int>());
    // i番目の頂点にはX[i]の数字が書かれている
    rep(i, N-1){
        int x, x1; cin >> x >> x1;
        a[x].push_back(x1);
        a[x1].push_back(x);
    }
    // グラフを生成
    vector<pair<int, int>> V(Q);
    rep(i, Q){
        int x, x1; cin >> x >> x1;
        V[i] = make_pair(x, x1);
    }




    return 0;
}

