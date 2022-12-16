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
    int N; cin >> N;
    int sum = 0;
    rep(i, N){
        int a; cin >> a;
        sum+=a;
    }
    cout << sum << endl;    
}*/

// B問題
/*int main(){
    int N, M; cin >> N >> M;
    vector<vector<bool>> ans(N, vector<bool>(N, false));
    rep(i, N){
        ans[i][i] = true;
    }
    
    rep(i, M){
        int k; cin >> k;
        vector<int> attend(k);
        rep(j, k) cin >> attend[j];

        rep(l, k-1){
            FOR(m, l+1, k-1){
                ans[attend[l]-1][attend[m]-1] = true;
                ans[attend[m]-1][attend[l]-1] = true;
            }
        }
    }

    bool jud = true;
    rep(i, N){
        rep(j, N){
            if(!ans[i][j]){
                jud = false;
                break;
            }
        }
    }

    jud ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;
}*/

// C問題
/*int main(){
    int noneZeroNumber = 0;
    int N; cin >> N;
    ll sum = 0;
    vector<ll> odd(2, -1);
    vector<ll> even(2, -1);
    rep(i, N){
        ll a; cin >> a;
        if(a!=0) noneZeroNumber++;
        sum+=a;
        if(a%2){
            // 奇数なら
            if(odd[0]<=a and a<=odd[1]){
                odd[0] = a;
            }
            if(a>odd[0] and a>odd[1]){
                odd[0] = odd[1];
                odd[1] = a;
            }
        } else {
            if(even[0]<=a and a<=even[1]){
                even[0] = a;
            }
            if(a>even[0] and a>even[1]){
                even[0] = even[1];
                even[1] = a;
            }
        }
    }


    if(noneZeroNumber<=2){
        if(noneZeroNumber==0){
            cout << 0 << endl;
            return 0;
        }
        if(sum%2==1){
            cout << "-1" << endl;
            return 0;
        }
        cout << sum << endl;
        return 0;
    }


    int max = even[0] + even[1];
    if(max<(odd[0]+odd[1])) max = odd[0]+odd[1];

    cout << max << endl;
}*/

// D問題
int main(){
    ll H, W, r, s; cin >> H >> W >> r >> s;
    r--; s--;
    int N; cin >> N;
    map<ll, vector<ll>> lineMp;
    // 行にある壁の値を入力
    map<ll, vector<ll>> columMp;
    // 列にある壁の値を入力
    rep(i, N){
        ll temp, temp1; cin >> temp >> temp1;
        temp--; temp1--;
        lineMp[temp].push_back(temp1);
        columMp[temp1].push_back(temp);
    }

    for(auto &p: lineMp){
        sort(p.second.begin(), p.second.end());
    }
    for(auto &p: columMp){
        sort(p.second.begin(), p.second.end());
    }

    int Q; cin >> Q;
    rep(i, Q){
        if(i!=0) cout << r+1 << " " << s+1 << endl;
        char d; ll l; cin >> d >> l;
        if(d=='L'){
            auto itr = upper_bound(lineMp[r].begin(), lineMp[r].end(), s);
            if(itr==lineMp[r].begin()){
                s-=l;
                if(s<0) s=0;
                continue;
            }
            itr--;
            s=max(s-l, *itr+1);
        }
        if(d=='R'){
            auto itr = upper_bound(lineMp[r].begin(), lineMp[r].end(), s);
            if(itr==lineMp[r].end()){
                s+=l;
                if(s>=W) s=W-1;
                continue;
            }
            s=min(s+l, *itr-1);
        }
        if(d=='U'){
            auto itr = upper_bound(columMp[s].begin(), columMp[s].end(), r);
            if(itr==columMp[s].begin()){
                r-=l;
                if(r<0) r=0;
                continue;
            }
            itr--;
            r=max(r-l, *itr+1);

        }
        if(d=='D'){
            auto itr = upper_bound(columMp[s].begin(), columMp[s].end(), r);
            if(itr==columMp[s].end()){
                r+=l;
                if(r>=H) r=H-1;
                continue;
            }
            r=min(r+l, *itr-1);
        }
    }

    cout << r+1 << " " << s+1 << endl;
}