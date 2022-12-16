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
    string s; 
    int q = N/16;
    int r = N%16;
    while(true){
        if(q==10) {
            s.push_back('A');
            break;
        }
        if(q==11) {
         s.push_back('B');
         break;
        }
        if(q==12) {
            s.push_back('C');
            break;
        }
        if(q==13) {
            s.push_back('D');
            break;
        }
        if(q==14) {
            s.push_back('E');
            break;
        }
        if(q==15) {
            s.push_back('F');
            break;
        }
        if(q==0) {
            s.push_back('0');
            break;
        }
        s.push_back(q+'0');
        break;
    }
    while(true){
        if(r==10) {
            s.push_back('A');
            break;
        }
        if(r==11) {
         s.push_back('B');
         break;
        }
        if(r==12) {
            s.push_back('C');
            break;
        }
        if(r==13) {
            s.push_back('D');
            break;
        }
        if(r==14) {
            s.push_back('E');
            break;
        }
        if(r==15) {
            s.push_back('F');
            break;
        }
        if(r==0) {
            s.push_back('0');
            break;
        }
        s.push_back(r+'0');
        break;
    }
    // 数字をcharに直す時は+
    cout << s << endl;
    


    return 0;
}*/

// B問題
/*int main(){
    int N, Q; cin >> N >> Q;
    vector<vector<int>> a(N);
    rep(i, N){
        int L; cin >> L;
        rep(j, L){
            int temp; cin >> temp;
            a[i].push_back(temp);
        }
    }
    
    rep(i, Q){
        int s, t; cin >> s >> t;
        cout << a[s-1][t-1] << endl;
    }

    return 0;
}*/

// C問題
/*int main(){
    int N; cin >> N;
    vector<int> a;
    set<int> st;
    int sameBook=0;

    rep(i, N){
        int temp; cin >> temp;
        if(st.find(temp)==st.end()){
            st.insert(temp);
            a.push_back(temp);
        } else sameBook++;
    }

    sort(a.begin(), a.end());       
    

    rep(i, sameBook){
        a.push_back(1e09+1);
    }


    int left=0;
    int right=a.size()-1;
    int read = 1;

    while(left<=right){
        if(right==left){
            if(a[left]==read){
                read++;
                break;
            } else break;
        }
        if(a[left]==read){
            left++;
            read++;
        } else {
            right-=2;
            read++;
        }
    }

    cout << read-1 << endl;

}*/

// D問題
/*int main(){
    int N, S; cin >> N >> S;
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    vector<vector<string>> dp(N, vector<string>(100001));

    dp[0][a[0]].push_back('H');
    dp[0][b[0]].push_back('T');
    FOR(i, 1, N-1){
        FOR(j, 1, 100000){
            if(dp[i-1][j]=="") continue;
            dp[i][j+a[i]]=dp[i-1][j]+'H';
            dp[i][j+b[i]]=dp[i-1][j]+'T';
        }
    }
    if(dp[N-1][S]!=""){
        cout << "Yes" << endl;
        cout << dp[N-1][S] << endl;
    } else cout << "No" << endl;

}*/

// E問題
int main(){
    
}

