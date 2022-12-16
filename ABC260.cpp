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
    string s; cin >> s;
    map<char, int> mp;
    rep(i, 3){
        mp[s[i]]++;
    }
    rep(i, 3){
        if(mp[s[i]]==1){
            cout << s[i] << endl;
            return 0;
        }
    }

    cout << "-1" << endl;

    return 0;
}*/

// B問題
/*struct gradeMath{
    int score;
    int number;
    bool operator>(const gradeMath& another) const {
        return score==another.score ? number<another.number : score>another.score;
    }
};
struct gradeEnglish{
    int score;
    int number;
    bool operator>(const gradeEnglish& another) const {
        return score==another.score ? number<another.number : score>another.score;
    }
};

int main(){
    int N, X, Y, Z; cin >> N >> X >> Y >> Z;
    vector<gradeMath> math(N);
    vector<gradeEnglish> English(N);
    vector<bool> pass(N, false);
    rep(i, N) cin >> math[i].score;
    rep(i, N) cin >> English[i].score;
    rep(i, N) {
        math[i].number = i;
        English[i].number = i;
    }

    vector<int> sum(N), number(N);
    rep(i, N) {
        sum[i] = math[i].score + English[i].score;
        number[i] = i;
    }

    sort(math.begin(), math.end(), greater<gradeMath>());
    int i=0;
    while(X>0){
        if(pass[math[i].number]){
            i++;
            continue;
        }
        pass[math[i].number] = true;
        X--; i++;
    }
    i=0;

    sort(English.begin(), English.end(), greater<gradeEnglish>());
    while(Y>0){
        if(pass[English[i].number]){
            i++;
            continue;
        }
        pass[English[i].number] = true;
        Y--; i++;
    }
    i=0;

    stable_sort(number.begin(), number.end(), [&](int i, int j){ return sum[i]>sum[j]; });

    i=0;
    while(Z>0){
        if(pass[number[i]]){
            i++;
            continue;
        }
        pass[number[i]] = true;
        Z--; i++;
    }

    rep(i, N){
        if(pass[i]) cout << i+1 << endl;
    }

    return 0;
}*/


// C問題
int main(){

    ll N, X, Y; cin >> N >> X >> Y;

    vector<ll> red(N+1, 0), blue(N+1, 0);
    red[N] = 1;

    for(int i=N; i>1; i--){
        while(red[i]>0){
            red[i-1]++; blue[i]+=X;
            red[i]--;
        }
        while(blue[i]>0){
            red[i-1]++; blue[i-1]+=Y;
            blue[i]--;
        }
    }

    cout << blue[1] << endl;

    return 0;
}