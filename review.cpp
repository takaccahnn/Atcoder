#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

// ABC239
// B問題
/*int main(){
    long double X; cin >> X;
    ll x = X;
    if(X>=0) cout << x/10 << endl;
    else {
        if(x%10==0) cout << x/10 << endl;
        else {
            ll ans = x/10 - 1;
            cout << ans << endl;
        }
    }
    return 0;
}*/

// 負の数の場合の余りについて(復習)
/*
    負の数で割ることは現実問題としてほとんどないので、負の数を正の数で割る場合のみ考える
    -1%3=-1　これからわかるように余りは0から-2の範囲で出力される
    数学では余りは正として定義されるので、厳密には数学の定義とは異なる
*/

// D問題
bool isPrime(int a){
    bool jud = true;
    for(int i=2; i*i<=a; i++){
        if(a%i==0) jud = false;
        if(!jud) break; 
    }

    return jud;
}
// 素数ならtrue、でないならfalseを返す

/*int main(){
    int A, B, C, D; cin >> A >> B >> C >> D;    
    vector<bool> win_Aoki(B+1, false);
    FOR(i, A, B){
        FOR(j, C, D){
            if(isPrime(i+j)){
                win_Aoki[i] = true;
                break;
            }
        }
    }
    FOR(i, A, B){
        if(!win_Aoki[i]){
            cout << "Takahashi" << endl;
            return 0;
        }
    }

    cout << "Aoki" << endl;
    return 0;

}*/

// 素因数分解とエラトステネスのふるいについて(復習)
// 素因数分解をするプログラム
vector<pair<int, int>> primeFactorization(int a){
    vector<pair<int, int>> ans;

    for(int i=2; i*i<=a; i++){
        int times = 0;
        while(a%i==0){
            times++;
            a/=i;
        }
        if(times)ans.push_back(make_pair(i, times));
    }

    if(a!=1)ans.push_back(make_pair(a, 1));

    return ans;
}
// ある数aが与えられた時に、その値までの素数を一覧にして出力する
// 具体的には約数であれば、その数はtrue、約数でなければfalseを返す
vector<bool> Eratosthenes(int a){
    vector<bool> divisors(a+1, true);
    divisors[1] = false;
    divisors[0] = false;

    for(int i=2; i*i<=a; i++){
        if(!divisors[i]) continue;
        // これがあるだけで操作が高速になる
        int p = i*2;
        while(p<=a){
            divisors[p] = false;
            p += i;
        }
    }

    return divisors;

}

// ABC240
// D問題
int main(){
    int N; cin >> N;
    vector<int> ball(N);
    stack<pair<int, int>> a;
    a.push(make_pair(-1, -1));
    int size = 0;;
    
    rep(i, N){
        cin >> ball[i];
        if(a.top().first==ball[i]){
            if(a.top().second+1 == ball[i]){
                size-=(ball[i]-1);
                a.pop();
            }
            else {
                int temp = a.top().second+1;
                a.pop();
                a.push(make_pair(ball[i], temp));
                size++;
            }
        } else {
            a.push(make_pair(ball[i], 1));
            size++;
        }
        cout << size << endl;
    }

    return 0;

}

