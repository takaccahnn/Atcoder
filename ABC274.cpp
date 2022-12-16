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
    double A, B;
    cin >> A >> B;
    double ans = B/A;
    string s = to_string(ans);
    // 0.0001
    if(s[5]=='0' or s[5]=='1' or s[5]=='2' or s[5]=='3' or s[5]=='4'){
        cout << fixed << setprecision(3) << ans;
        return 0;
    } else {
        // ans+=0.001;
        cout << fixed << setprecision(3) << ans;
        return 0;
    }
}*/

// B問題
/*int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> mas(H, vector<char>(W));
    rep(i, H){
        rep(j, W){
            cin >> mas[i][j];
        }
    }

    vector<int> ans(W, 0);

    rep(i, W){
        rep(j, H){
            if(mas[j][i]=='#') ans[i]++;
        }
    }

    rep(i, W){
        cout << ans[i] << endl;
    }
}*/

// C問題
/*void dfs(vector<int> &ans, Graph &G, int parent, int time){
    if(G[parent].size()==0){
        ans[parent] = time;
    }
    for(auto next: G[parent]){
        int temp = time+1;
        ans[next] = temp;
        dfs(ans, G, next, temp);
    }
}

int main(){
    int N; cin >> N;
    Graph G(1E06); 
    FOR(i, 1, N){
        int a; cin >> a;
        G[a].push_back(2*i);
        G[a].push_back(2*i+1);
    }

    vector<int> ans(2*N+2);
    ans[1] = 0;

    dfs(ans, G, 1, 0);

    FOR(i, 1, 2*N+1){
        cout << ans[i] << endl;
    }
}*/

// D問題
int main(){
    int N; cin >> N;
    int x, y; cin >> x >> y;
    x+=1e04; y+=1e04;
    vector<int> up, right;
    rep(i, N){
        int a; cin >> a;
        if(i%2){
            up.push_back(a);
        } else {
            right.push_back(a);
        }
    }
    
    vector<vector<bool>> v(N/2+1, vector<bool>(2*1e04+1, false));
    vector<vector<bool>> h(N/2+1, vector<bool>(2*1e04+1, false));

    rep(i, up.size()){
        int temp = up[i];
        if(i==0){
            int temp1 = 1e04+temp;
            int temp2 = 1e04-temp;
            v[0][temp1] = true;
            v[0][temp2] = true;
            continue;
        }
        rep(j, 2*1e04+1){
            if(v[i-1][j]){
                v[i][j+temp] = true;
                v[i][j-temp] = true;
            }
        }
    }

    rep(i, right.size()){
        int temp = right[i];
        if(i==0){
            temp += 1e04;
            h[0][temp] = true; 
            continue;
        }
        rep(j, 2*1e04+1){
            if(h[i-1][j]){
                h[i][j+temp] = true;
                h[i][j-temp] = true;
            }
        }
    }

    if(h[right.size()-1][x] and v[up.size()-1][y]){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}