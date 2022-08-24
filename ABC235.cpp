#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

// A問題
/*int main(){
    string s;
    cin >> s;

    int sum = 0;

    rep(i, s.size()){
        int x = s[i] - '0';
        sum += 100*x + 10*x + x;
    }

    cout << sum << endl;

    return 0;
}*/

// B問題
/*int main(){
    int N;
    cin >> N;
    vector<ll> H(N);
    rep(i, N) cin >> H[i];

    int takahashi = 0;
    for(int i=1; i<N; i++){
        if(H[takahashi]<H[i]) takahashi++;
        else break;
    }

    cout << H[takahashi] << endl;

    return 0;
}*/

// C問題
/*int main(){
    map<ll, vector<ll>> a;
    
    ll N, Q;
    cin >> N >> Q;
    rep(i, N){
        ll x; cin >> x;
        a[x].push_back(i+1);
    }

    rep(i, Q){
        ll x, k;
        cin >> x >> k;
        if(k>a[x].size()){
            cout << -1 << endl;
            continue;
        }
        cout << a[x][k-1] << endl;
    }

    return 0;
}*/


// D問題
/*int main(){
    ll a, N; cin >> a >> N;
    int degit = log10(N);
    // Nがdegit桁の数字であることがわかった
    ll size = pow(10, degit+1)-1;

    vector<bool> used(size, false);
    used[1] = true;
    queue<ll> dist;
    dist.push(1);

   
    int count = 0;
    while(!dist.empty()){
        count++;
        int length = dist.size();        
        rep(i, length){
            ll x = dist.front();
            dist.pop();
            if(x*a<=size && !used[x*a]){
                used[x*a] = true;
                dist.push(x*a);
            }
            if(N == x*a){
                cout << count << endl;
                return 0;
            }
            if(x%10 && x>=10){
                string s = to_string(x);
                s.insert(s.begin(),s.back());
                s.pop_back();
                ll temp = stoll(s);
                if(temp<=size && !used[temp]){
                    used[temp] = true;
                    dist.push(temp);
                }
                if(temp==N){
                    cout << count << endl;
                    return 0;
                }
            }
        }
    }

    cout << "-1" << endl;

    return 0;
}*/

