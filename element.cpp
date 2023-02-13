#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using ll = long long;
using node = pair<double, double>;
const double pi=3.1415926535897932;

int main(){
    vector<vector<int>> mas(5, vector<int>(11));

    int time = 0;
    rep(i, 5){
        rep(j, 11){
            mas[i][j] = time;
            time++;
        }
    }
    
    vector<vector<int>> ans(40);

    int step = 0;
    rep(i, 40){
        if(i!=0 and i%10==0){
            step++;
        }
        ans[i].push_back(i+step);
        ans[i].push_back(i+1+step);
        ans[i].push_back(i+12+step);
        ans[i].push_back(i+11+step);
    }

    rep(i, 40){
        cout << i << " ";
        rep(j, ans[i].size()){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}