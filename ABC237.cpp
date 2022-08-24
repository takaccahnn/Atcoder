#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)


// A問題
/*int main(){
    cin >> N;
    ll left, right;
    left = -1 * (ll)1 << 31;
    right = (ll)1 << 31;
    if(N>=left and N<right) cout << "Yes" << endl;
    else cout << "No" << endl; 

    return 0;
}*/

// B問題
/*int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H){
        rep(j, W) cin >> A[i][j];
    }

    vector<vector<int>> B(W, vector<int>(H));
    rep(i, W){
        rep(j, H) B[i][j] = A[j][i];
    }

    rep(i, W){
        cout << endl;
        rep(j, H) cout << B[i][j] << " ";
    }

    cout << endl;


    return 0;
}*/

// C問題
/*int main(){
    string S;
    cin >> S;

    ll right;
    ll left;
    ll x=0, y=0;
    // 右端から数えたときに、初めてaじゃない値が出てきた時が何番目の数か
    for(int i=S.size()-1; i>=0; i--){
        if(S[i]=='a'){
            x++;
            continue;
        }
        right = i;
        break;
    }
    rep(i, S.size()){
        if(S[i]=='a'){
            y++;
            continue;
        }
        left = i;
        break;
    }

    bool jud = true;

    if(y==S.size()){
        cout << "Yes" << endl;
        return 0;
    }

    if(y>x){
        cout << "No" << endl;
        return 0;
    }

    while(right-left>0){
        if(S[left]==S[right]){         
            right--; left++;
            continue;
        }
        jud = false;
        break;
    }


    if(jud) cout << "Yes" << endl;
    else cout << "No" << endl;
    

    return 0;
}*/

// D問題
int main(){
    int N; cin >> N;
    string S; cin >> S;

    list<int> ans = {0};
    // 上記のように、最初に入れておく要素を決めることもできる
    auto itr = ans.begin();
    // itrの初期値は0が入っているところのイテレータ

    rep(i, N){
        if(S[i]=='R'){
            itr++;
            itr = ans.insert(itr, i+1);
        } else {
            itr = ans.insert(itr, i+1);
        }
    }

    for(auto i=ans.begin(); i!=ans.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    
    return 0;
}