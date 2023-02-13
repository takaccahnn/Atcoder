#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using ll = long long;
using node = pair<int, int>;

// D問題(×)
int main(){
    string S; cin >> S;
    stack<set<char>> st;
    set<char> a;
    st.push(a);
    set<char> box;

    rep(i, S.size()){
        if(S[i]=='('){
            st.push(a);
            continue;
        }
        if(S[i]==')'){
            for(auto p: st.top()){
                box.erase(p);
            }
            st.pop();
            continue;
        }
        if(box.find(S[i])!=box.end()){
            cout << "No" << endl;
            return 0;
        }
        box.insert(S[i]);
        set<char> temp = st.top();
        temp.insert(S[i]);
        st.pop();
        st.push(temp);
    }

    cout << "Yes" << endl;
}