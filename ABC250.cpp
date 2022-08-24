#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using ll = long long;

//  A問題
/*int main(){
    int h, w, r, c; cin >> h >> w >> r >> c;
    int ans = 0;
    if(r-1>=1) ans++;
    if(r+1<=h) ans++;
    if(c-1>=1) ans++;
    if(c+1<=w) ans++;

    cout << ans << endl;

    return 0;
}*/

// B問題
/*int main(){
    int n, a, b; cin >> n >> a >> b;
    vector<vector<bool>> mas(n, vector<bool>(n, true));
    // 白ならtrue, 黒ならfalseを出力
    mas[0][0] = true;
    rep(i, n){
        // 偶数行については最初はtrueから始まる
        if(i%2 == 0){
            int x = 1;
            while(x<n){
                mas[i][x] = false;
                x+=2;
            }
        } else {
            int x = 0;
            while(x<n){
                mas[i][x] = false;
                x+=2;
            }
        }
    }

    rep(i, n){
        rep(k, a){
            rep(j, n){
                if(mas[i][j]){
                   rep(l, b) cout << ".";           
               } else {
                   rep(l, b) cout << "#";
                }
            }
            cout << endl;
        }
    }

    return 0;
}*/

// C問題
/*int main(){
    int N, Q; cin >> N >> Q;
    vector<int> ans(N+1);
    rep(i, N+1) ans[i] = i;

    unordered_map<int, int> location;
    rep(i, N+1) location[i] = i;

    rep(i, Q){
        int x; cin >> x;
        int place = location[x];
        // もとあったxの位置
        if(place == N){
            int place_left_number = ans[place-1];
            ans[place-1] = x;
            location[x] = place-1;
            ans[place] = place_left_number;
            location[place_left_number] = place;
            continue;
        }
        int place_right_number = ans[place+1];
        ans[place+1] = x;
        location[x] = place+1;
        ans[place] = place_right_number;
        location[place_right_number] = place; 
    }

    FOR(i, 1, N){
        cout << ans[i] << endl;
    }

    return 0;
}*/

vector<ll> Eratosthenes(ll N){
    vector<bool> is_prime(N+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(ll i=2; i*i<=N; i++){
        if(!is_prime[i]) continue;
        for(ll j=i*2; j<=N; j+=i){
            is_prime[j] = false;
        }
    }
    vector<ll> ans;
    rep(i, N+1){
        if(is_prime[i]) ans.push_back(i);
    }
    return ans;
}


// D問題
int main(){
    ll N; cin >> N;
    ll Max = 1;
    while(Max * Max * Max <= N/2){
        Max++;
    }

    vector<ll> is_prime = Eratosthenes(Max);

    ll ans = 0;
    ll right = is_prime.size()-1;
    rep(i, is_prime.size()){
        ll p = is_prime[i];
        while(p * is_prime[right] * is_prime[right] * is_prime[right] > N){
            right--;
        }
        if(i>=right) break;
        else ans += right - i;
    }

    cout << ans << endl;

    return 0;
}