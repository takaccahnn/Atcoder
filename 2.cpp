#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using node = pair<int, int>;
using ll = long long;

struct temp {
    int a;
    int b;
    /*temp(int m){
        a = m; b = m*2;
    } */
    // 構造体の中にコンストラクタを内蔵することも可能
    /* ただし、これだとメンバ変数が初期化された後にコンストラクタ内で再代入しているため、2回値が代入されていることになり効率が悪い
       以下の書き方を用いれば、コンストラクタ内でメンバ関数の初期化をすることができる。(やっている過程は違うが結果は同じ) */
    temp(int m) : a(m), b(m*2){}

};

// テンプレートと呼ばれる機能について 関数宣言の型verみたいなイメージ
template <class T, class U>
struct t {
    T a1;
    U b1;
private:
    int c;
    // struct内部だけで用いることができるように設定できる
};

// structとclassの違い
/*
classはデフォルトのアクセシビリティがprivate
structはデフォルトのアクセシビリティがpublic
正直どっちを使ってもいいが、上部にpublic、下部にprivateを用いた方がわかりやすいのでstruct派
*/

int main(){

    vector<int> b = {3, 2, 1};
    sort(b.begin(), b.end());
    temp x(4);
    cout << "aの値は" << x.a << endl;
    cout << "bの値は" << x.b << endl;

    t<double, int> y;
    y.a1 = 3.14; y.b1 = 3.141592; /*y.c=3; と書くとエラーになる*/
    cout << "aの値は" << y.a1 << endl;
    cout << "bの値は" << y.b1 << endl;



    return 0;
}