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
    int L, R; cin >> L >> R;
    string S = "atcoder";

    FOR(i, L-1, R-1){
        cout << S[i];
    }
    cout << endl;


    return 0;
}*/

// B問題
/*int main(){
    int R, C; cin >> R >> C;
    vector<vector<char>> mas(15, vector<char>(15, 'b'));
    // 黒は'b'、白は'w'として表すこととする
    rep(i, 4){
        FOR(j, 1+i*2, 14-(1+i*2)){
            mas[1+i*2][j] = 'w';
            mas[14-(1+i*2)][j] = 'w';
            mas[j][1+i*2] = 'w';
            mas[j][14-(1+i*2)] = 'w';
        }
    }

    if(mas[R-1][C-1] == 'b') cout << "black" << endl;
    else cout << "white" << endl;


    return 0;
}*/

// C問題
int main(){
    ll H1, W1; cin >> H1 >> W1;
    vector<vector<ll>> A(H1, vector<int>(W1));
    rep(i, H1){
        rep(j, W1){
            cin >> A[H1][W1];
        }
    }
    ll H12, W2; cin >> H2 >> W2;
    vector<vector<ll>> B(H2, vector<int>(W2));
    rep(i, H2){
        rep(j, W2){
            cin >> B[H2][W2];
        }
    }
    
    vector<node> ans(); 
    // Bの配列の[0][0]の値と等しい値のAの場所を入れる

    
    rep(i, H2){
        rep(j, W2){
           if(A[i][j]==B[0][k]){
              ans.push_back(make_pair(i, j));
            }
        }
    }   
    
    queue<ll> line;
    // Bの配列の0行目と等しい値を持つ、Aの列を入れる
    rep(i, ans.size()){
        int x, y;
        x = ans[i].first; y = ans[i].second;
        
    }
    
    



    
    return 0;
}

// D問題

// 与えられた端の文字列に対し、端を最も少ない回数で入れ替えて処理する関数
// sは今修正したい文字列 left, rightはその修正したい文字列の位置
/*void change(string s, int left, int right){
    string ans = "Atcoder";
    char chr_left = s[left];
    char chr_right = s[right];
    int far_left;
    int far_right;
    int loc1; int loc2;
    // Atcoderの文字列での位置
    rep(i, 7){
        if(chr_left == s[i]){
            far_left = abs[i - left];
            loc1 = i;
            break;
        }
    }
    rep(i, 7){
        if(chr_right == s[i]){
            far_right = abs[i - right];
            loc2 = i;
            break;
        }
    }
    
    if(far_right < far_left){
        if(loc1 < right){
            while()
        }
    }


}

int main(){



    return 0;
}*/