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
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;
    if(M>=X) cout << T<< endl;
    else cout << T - X*D + M*D << endl; 

    return 0;
}*/

// B問題
/*int main(){
    const double PI = 3.1415926535;
    double a, b, d; cin >> a >> b >> d;
    d = d*PI/180;
    cout << setprecision(9) << a*cos(d) - b*sin(d) << " ";
    cout <<  setprecision(9) <<a*sin(d) + b*cos(d) << endl;

    return 0;
}*/

// C問題
/*int main(){
    string S, T; cin >> S >> T;
    S.push_back('@'); T.push_back('@');
    vector<pair<char, int>> S_ch;
    char x = S[0];
    int n = 0;
    // [i-1]の要素
    // あわられたアルファベットが何個あるか
    rep(i, S.size()){
        if(S[i]==x){
            n++;
        } else {
            S_ch.push_back(make_pair(x, n));
            n = 1;
            x = S[i];
        }
    }
    vector<pair<char, ll>> T_ch;
    x = T[0];
    n = 0;
    rep(i, T.size()){
        if(T[i]==x){
            n++;
        } else {
            T_ch.push_back(make_pair(x, n));
            n = 1;
            x = T[i];
        }
    }

    if(T_ch.size() != S_ch.size()){
        cout << "No" << endl;
        return 0;
    }
    rep(i, max(T_ch.size(), S_ch.size())){
        if(T_ch[i].first == S_ch[i].first and T_ch[i].second == S_ch[i].second) continue;
        if(T_ch[i].first == S_ch[i].first and T_ch[i].second>S_ch[i].second and S_ch[i].second>1) continue;
        cout << "No" << endl;
        return 0;
    }


    cout << "Yes" << endl;

    return 0;
}*/

// D問題

vector<int> bit;

int sum(int i){
    int s = 0;
    while(i>0){
        s+=bit[i];
        i-=i&(-i);
    }
    return s;
}

void add(int i, int x){
    while(i<bit.size()){
        bit[i]+=x;
        i+=i&(-i);
    }
}

int main(){

    // 転倒数という有名問題。Atcoderという文字列に対し前から順に番号をつける。与えられた文字列をその番号順に並べられているとして、
    // 1から順に並べていく問題(= 転倒数)と解釈して解く。

    bit.resize(10);
    rep(i, 10) bit[i] = 0;

    string s; cin >> s;
    map<string, int> mp;
    string atc = "*atcoder";
    FOR(i, 1, 7){
        mp[atc[i]] = i;
    }
    // atcoderという文字列を1から順に番号を振って、その番号とアルファベットをmpに保存する

    vector<int> a = {-1};
    for(int i = 0; i < 7; i++){
        a.push_back(mp[s[i]]);
    }
    // 与えられた文字列に1から順に番号を振って、その番号とアルファベットをmpに保存する

    int res = 0;
    FOR(i, 1, 7){
        res += (i-1-sum(a[i]));
        add(a[i], 1);
    }
    cout << res << endl

    return 0;
}
