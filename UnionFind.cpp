#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
using Graph = vector<vector<int>>;
using ll = long long;
using node = pair<int, int>;

struct UnionFind{
    // sizeはツリーの要素数の数
    vector<int> par, size;

    // 初期化
    UnionFind(int n) : par(n, -1), size(n, 1) {}

    // 根を求める
    int root(int x){
        if(par[x]==-1) return x;
        else return par[x] = root(par[x]);
    }

    // xとyが同じグループかどうか判断する
    bool issame(int x, int y){
        if(root(x)==root(y)) return true;
        else return false;
    }

    // xを含むグループとyを含むグループを合併する
    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x==y) return false;
        if(size[x]<size[y]) swap(x, y);
        // yをxの子とする(swapしたのでxの方が大きい)
        par[y] = x;
        size[x] += size[y];
        return true;
    }

    int siz(int x){
        return size[root(x)];
    }
};

int main(){
    UnionFind uf(7);

    uf.unite(1, 2);
    cout << uf.issame(2, 4);
}

