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
    double x1=2.0;
    double delta_r = 0.50/4.0;
    vector<double> theta;
    double x = pi/20;
    FOR(i, 0, 10){
        theta.push_back(x*i);
    }

    vector<double> r;
    r.push_back(x1);
    for(double i=1; i<=4; i++){
        r.push_back(x1+delta_r*1.0*i);
    }

    vector<node> coordinate;

    rep(i, r.size()){
        rep(j, theta.size()){
           coordinate.push_back(pair(r[i]*cos(theta[j]), r[i]*sin(theta[j]))); 
        }
    }

    cout << r.size() << endl;

    rep(i, coordinate.size()){
        printf("%d %1.9f %1.9f\n", i, coordinate[i].second, coordinate[i].first);
    }

}