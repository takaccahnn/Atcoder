#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0; i<(n); i++)


// A問題
/*int main(){
    int a, b;
    cin >> a >> b;
    if((a==10 and b==1)or(a==1 and b==10)){
        cout << "Yes" << endl;
        return 0;
    }
    if(abs(a-b)==1){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}*/

// B問題
/*int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    vector<ll> ans;

    rep(i, N){
        bool exist = false;
        rep(j, ans.size()){
            if(a[i]==ans[j]){
                exist = true;
                break;
            }
        }
        if(!exist) ans.push_back(a[i]);
    }

    cout << ans.size() << endl;

    return 0;
}*/

// C問題(dpだね。見た瞬間に察したわ)
/*int main(){
    int N, X;
    cin >> N >> X;
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];
    vector<vector<bool>> ans(N, vector<bool>(10000, false));

    rep(i, N){
        if(i==0){
            ans[i][a[i]] = true;
            ans[i][b[i]] = true;
            continue;
        }
        rep(j, 10001){
            if(ans[i-1][j]==true){
                ans[i][j+a[i]] = true;
                ans[i][j+b[i]] = true;
            }
        }
    }

    if(ans[N-1][X]==true) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}*/

// D問題
/*int main(){
    int N;
    cin >> N;
    vector<int> a;
    vector<pair<ll, ll>> parts;
    parts.push_back(make_pair(0, 0));
    // pair(値, 個数)
    int count = 0;

    // countはpartsの要素数-1
    for(int i=0; i<N; i++){
        int temp; cin >> temp; a.push_back(temp);
        if(parts[count].first==temp) parts[count].second++;
        else {
            count++;
            parts.push_back(make_pair(temp, 1));
        }
        if(parts[count].second==temp){
            parts.pop_back();
            count--;
            rep(j, temp) a.pop_back();
        }
        cout << a.size() << endl;

    }
    
    return 0;
}*/

int main(){
    set<int> a;
    a.insert(1);
    a.insert(2);
    if(a.count(1)) cout << *a.find(1) << endl;


    return 0;
}

