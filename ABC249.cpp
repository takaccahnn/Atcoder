#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

//  A問題
/*int main(){
    int A, B, C;
    cin >> A >> B >> C;
    int D, E, F;
    cin >> D >> E >> F;
    int X;
    cin >> X;

    int time1 = 0;;
    int run1 = 0;
    while(time1<=X){
        if(time1+A<=X) {
            run1+=A*B;
            time1+=A;
        } else {
            run1+=B*(X-time1);
            break;
        }
        if(time1+C<=X) time1+=C;
        else break;
    }
    int time2 = 0; int run2 = 0;
    while(time2<=X){
        if(time2+D<=X) {
            run2+=D*E;
            time2+=D;
        } else {
            run2+=E*(X-time2);
            break;
        }
        if(time2+F<=X) time2+=F;
        else break;
    }

    if(run1 == run2){
        cout << "Draw" << endl;
        return 0;
    }
    if(run1>run2) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}*/

// B問題
/*int main(){
    string s; cin >> s;
    bool jud1 = false, jud2 = false, jud3 = true;

    // 大文字があるかどうか判定
    for(char i='A'; i<='Z'; i++){   
        rep(j, s.size()){
            if(i==s[j]) jud1 = true;
        }
    }

    // 小文字があるかどうか判定
    for(char i='a'; i<='z'; i++){   
        rep(j, s.size()){
            if(i==s[j]) jud2 = true;
        }
    }

    
    // 全てが相異なるか判定
    for(char i='A'; i<='Z'; i++){   
        int x = 0;
        rep(j, s.size()){
            if(i==s[j]) x++;
        }
        if(x>=2){
            jud3 = false;
            break;
        }
    }

    for(char i='a'; i<='x'; i++){   
        int x = 0;
        rep(j, s.size()){
            if(i==s[j]) x++;
        }
        if(x>=2){
            jud3 = false;
            break;
        }
    }

    if(jud1 and jud2 and jud3) cout << "Yes" << endl;
    else cout << "No" << endl;



    return 0;
}*/

// C問題
/*int main(){
    int N; cin >> N;
    int K; cin >> K;
    vector<string > S(N);
    rep(i, N) cin >> S[i];

    int ans = 0;
    for(int i=0; i<(1<<N); i++){
        map<char, int> a;
        rep(k, 26) a['a'+k] = 0;
        for(int j = 0; j<N; j++){
            if(i & (1<<j)){
                // ここまでが組み合わせの計算 jについて考えていけば良い
                rep(l, S[j].size()){
                    a[S[j][l]]++;
                }
            }
        }
        int x = 0;
        rep(l, 26){
            if(a['a'+l]==K) x++;
        }


        ans = max(ans, x);
    }

    cout << ans << endl;

    return 0;
}*/

int binary_search(vector<int>&A, ll x){
    int right = A.size(); int left = 0;
    while(right-left>1){
        int mid = (right+left)/2;
        if(x<=A[mid]) right = mid;
        else left = mid;
    }
    return right;
}

// D問題
int main(){
    int n;
    cin >> n;
    int MAX = 21e05;
    int max_num = 0;
    vector<int> c(MAX + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x]++;
        max_num = max(max_num, x);
    }
    ll sum = 0;

    // 計算量はlogで解けてしまう
    // この考え方は約数の列挙の際にも使ったやり方だった。i*jを不等号で比較するうやり方はプログラミング独特のやり方の気がする。数学はjを解として求めるイメージ。
    // jはこれ!って求まる感じ。下のコードはjはある固定値を取るのではなく、条件が合うまで代入していく感じ。この考え方に慣れないとなかなか厳しい気がする。
    for(int i=1; i<=max_num; i++){
        for(int j=1; i*j<=max_num; j++){
            sum+=c[i]*c[j]*c[i*j];
        }
    }

    cout << sum << endl;
    
    return 0;
}

