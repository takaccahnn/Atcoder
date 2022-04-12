#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);

    int ans;
    int res;
    if(s == "R G B" or s == "G B R" or s == "B R G") ans = 2;
    else ans = 1;

    if(t == "R B G" or t == "G R B" or t == "B G R") res = 1;
    else res = 2;

    if(res==ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    

    return 0;
}