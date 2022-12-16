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
    rrep(i, N+1){
        cout << i << endl;
    }
    return 0;
}*/

// B問題
/*int main(){
    string S; cin >> S;

    if(!(S.size()==8)){
        cout << "No" << endl;
        return 0;
    } 
    if(!(S[0]>='A' and S[0]<='Z')){
        cout << "No" << endl;
        return 0;
    }
    FOR(i, 1, 6){
        if(i==1){
            if(!(S[i]>='1' and S[i]<='9')){
                cout << "No" << endl;
                return 0;
            }
        }
        if(!(S[i]>='0' and S[i]<='9')){
            cout << "No" << endl;
            return 0;
        }
    }
    if(!(S[7]>='A' and S[7]<='Z')){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
}*/

// C問題
/*int main(){
    int N; cin >> N;
    ll T; cin >> T;
    vector<ll> A(N);
    vector<ll> subA(N);

    rep(i, N){
        cin >> A[i];
        if(i==0){
            subA[i] = A[i];
            continue;
        }
        subA[i] = subA[i-1] + A[i];
    }
    T = T%subA[N-1];

    auto itr = upper_bound(subA.begin(), subA.end(), T);

    int number;
    rep(i, N){
        if(*itr==subA[i]) number = i;
    }

    if(number==0){
        cout << number+1 << " " << T << endl;
        return 0;
    } else {
        cout << number+1 << " " << T-subA[number-1] << endl;
        return 0;
    }   
}*/

// D問題
/*int main(){
    int N, K; ll D; cin >> N >> K >> D;
    vector<pair<ll, ll>> a(N);
    rep(i, N){
        ll temp, q, r;
        cin >> temp;
        q = temp/D; // 商
        r = temp%D; //　余り
        a[i] = make_pair(q, r);
    }

    sort(a.begin(), a.end());

    ll ansP, ansR;

    for(int i=N-1; i>=N-K; i--){
        ansP = a[i].first;
        ansR = a[i].second;
    }
}*/

// E問題
int main(){
    int N, M, K; cin >> N >> M >> K;
    vector<ll> kari(N); 
    rep(i, N) cin >> kari[i];
    multiset<ll> st;

   
    rep(i, N-M+1){
        ll sum = 0;
        if(i==0){
            rep(j, M){
                st.insert(kari[j]);
            }
            auto itr1 = st.begin();
            rep(l, K){
                sum += *itr1;
                itr1++;
            }
            cout << sum << endl;
            continue;
        }
        ll a = kari[i+M-1];
        ll b = kari[i-1];
        st.erase(st.find(b));
        st.insert(a);

        auto itr = st.begin();
        rep(l, K){
            sum += *itr;
            itr++;
        }
        cout << sum << endl;
    }
}