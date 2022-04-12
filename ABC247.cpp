#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<(n);i++)
using ll = long long;

//  A問題
/*int main(){
    string S;
    cin >> S;
    
    cout << "0";
    rep(i, 3) cout << S[i];
    
    return 0;
}*/

// B問題
/*int main(){
    int N;
    cin >> N;
    vector<string> s(N);
    vector<string> t(N);
    vector<bool> ans(N, false);
    rep(i, N){
        cin >> s[i] >> t[i];
    }
    
    // 姓について
    rep(i, N){
        int res = 0;
        string s_i = s[i];
        for(int j=0; j<N; j++){
            if(i==j) continue;
            if(s_i==s[j] or s_i==t[j]){
                res++;
                break;
            }
        }
        if(res==0) ans[i] = true;
        else ans[i] = false;
    }

    // 名について
    rep(i, N){
        int res = 0;
        string t_i = t[i];
        rep(j, N){
            if(i==j) continue;
            if(t_i == t[j] or t_i == s[j]){
                res++;
                break;
            }
        }
        if(res == 0) ans[i] = true;
        else ans[i] = false;
    }



    rep(i, N){
        if(ans[i]==false){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}*/

// C問題(再帰に関する問題)
// 
/*void unit(int N, vector<string> &a){
    if(N==1){
        a[1] = "1 ";
        return;
    }
    string temp = to_string(N) + " ";

    unit(N-1, a);

    if(a[N-1]!="-1"){
        a[N] = a[N-1] + temp + a[N-1];
    }
    
    return;
}

int main(){
    int N;
    cin >> N;
    vector<string> ans(N+1, "-1");

    unit(N, ans);

    cout << ans[N];


    return 0;
}*/

// D問題
int main(){
    ll Q;
    cin >> Q;
    vector<pair<ll, ll>> in;
    vector<ll> out;

    rep(i, Q){
        int number;
        cin >> number;
        if(number==1){
            ll x, q;
            cin >> x >> q;
            // firstは値、secondは個数
            in.push_back(make_pair(x, q));
        } else {
            ll c;
            cin >> c;
            out.push_back(c);
        }
    }
    ll j = 0;
    for(auto count: out){
        ll sum = 0;
        while(count>0){
            ll rem = min(count, in[j].second);
            if(rem == in[j].second){
                sum += rem * in[j].first;
                count -= rem;
                j++;
            } else {
                sum += rem * in[j].first;
                in[j].second -= rem;
                break;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
