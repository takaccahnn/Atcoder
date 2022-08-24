#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)



// A問題
/*ll func(ll t){
    return t*t+2*t+3;
}
int main(){ 
    ll t; cin >> t;
    cout << func(func(func(t)+t) + func(func(t))) << endl;


    return 0;
}*/

// B問題
/*int main(){
    int N; cin >> N;
    vector<pair<double, double>> coordinate(N);
    rep(i, N){
        double x1, x2; cin >> x1 >> x2;
        coordinate[i] = make_pair(x1, x2);
    }

    double Max = 0;
    rep(i, N){
        for(int j=i+1; j<N; j++){
            double x = (coordinate[i].first-coordinate[j].first)*(coordinate[i].first-coordinate[j].first)
                     + (coordinate[i].second-coordinate[j].second) * (coordinate[i].second-coordinate[j].second) ;
            Max = max(Max, x);
        }
    }

    cout << fixed << setprecision(8) << sqrt(Max) << endl;

    return 0;
}*/

// C問題
/*int main(){
    ll K; cin >> K;
    string s;
    while(K>0){
        int remainder = K%2;
        if(remainder == 1){
            s.push_back('2');
        } else {
            s.push_back('0');
        }
        K /= 2;
    }

    rrep(i, s.size()) cout << s[i];
    cout << endl;

    return 0;
}*/

// D問題
/*int main(){
    int N, K; cin >> N >> K;

    priority_queue<int, vector<int>, greater<int>> Max;
    rep(i, K){
        int x; cin >> x;
        Max.push(x);
    }
    cout << Max.top() << endl;
    rep(i, N-K){
        int x; cin >> x;
        if(Max.top()<x){
            Max.pop();
            Max.push(x);
        }
        cout << Max.top() << endl;
    }
    
    return 0;
}*/

// E問題
int main(){
    
    ll x; cin >> x;

    string s;
    int a, b;

    FOR(i, x, 10*x){
        bool jud = true;
        s = to_string(x);
        a = s[0] - 'o';
        b = s[1] - 'o';
        int d = b-a;
        rep(i, s.size()-2){
            a = s[i+1] - 'o';
            b = s[i+2] - 'o';
            if(d!=(b-a)){
                jud = false;
                break;
            }
        }
        if(jud){
            cout << i << endl;
            break;
        }
    }

    return 0;
}