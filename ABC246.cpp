#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

long long binary_search_min(long long vertex){
    long long left = 0;
    long long right = 1e06+1;
    while((right-left)>1){
        long long mid = (left+right)/2;
        if(vertex < (mid*mid*mid)) right = mid;
        else left = mid;
    }
    return left;
}

long long binary_search_max(long long vertex){
    long long left = 0;
    long long right = 1e06+1;
    while((right-left)>1){
        long long mid = (left+right)/2;
        if(vertex <= (mid*mid*mid)) right = mid;
        else left = mid;
    }
    return right;
}

long long f(long long a, long long b){
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

// A問題
/*int main(){
    vector<int> x(3), y(3);
    rep(i, 3) cin >> x[i] >> y[i];
    int ans_x, ans_y;
    if(x[0]==x[1]) ans_x = x[2];
    if(x[0]==x[2]) ans_x = x[1];
    if(x[1]==x[2]) ans_x = x[0];

    if(y[0]==y[1]) ans_y = y[2];
    if(y[0]==y[2]) ans_y = y[1];
    if(y[1]==y[2]) ans_y = y[0];

    cout << ans_x << " " << ans_y << endl;

    return 0;
}*/

// B問題
/*int main(){
    double A, B;
    cin >> A >> B;
    double hypotenuse = sqrt(A*A + B*B);
    double rate = 1/hypotenuse;

    double x, y;
    x = A*rate; y = B*rate;

    cout << x << " " << y << endl;

    return 0;
}*/

// C問題
/*int main(){
    long long N, K, X;
    // X円引きのクーポン
    cin >> N >> K >> X;
    vector<long long> goods(N);
    for(long long i=0; i<N; i++) cin >> goods[i];

    long long ans = 0;
    for(long long i=0; i<N; i++){
        while((goods[i]-X)>=0 and K>0){
            goods[i] -= X;
            K--;
        }
        if(K==0){
            for(long long i=0; i<N; i++) ans += goods[i];
            cout << ans << endl;
            return 0;
        }
    }

    sort(goods.begin(), goods.end(), greater<long long>());

    long long j = 0;
    while(K>0 and j<N){
        goods[j] = 0;
        j++; K--;
    }

    for(long long i=0; i<N; i++){
        ans += goods[i];
    }
    cout << ans << endl;

    return 0;
}*/

// D問題
//自分が考えた解法
/*
まず、条件式がaとbの同次式であるから、a>=bとして進める.
すると、N >= 4*b*b*b    N >= 4*a*a*a    と最大値と最小値の値を大雑把に見積もることができる
(upper_boudとlower_boud?みたいなイメージ)
これによって出た、bからaの範囲の値を組み合わせて、Nを超える最も小さい数を求めようと考えた
*/
/*int main(){
    long long N;
    cin >> N;

    // 最小と最大の値をそれぞれ求める
    long long b = binary_search_min(N/4);
    long long a = binary_search_max(N/4);;

    // 答えの候補を入れる。keyはNを超えた値の(a,b)の組み合わせのうち、小さい方の値bを格納、値はf(a,b)を格納
    map<long long, long long> ans;
    
    // bからaの中の値を組み合わせて、Nを超える最も小さい数を求める
    for(long long i=0; i<a-b+1; i++){
        long long res = b+i;
        long long res1 = res;
        while(f(res, res1)<N) res1++;
        if(f(res, res1)>=N) ans[res] = f(res, res1);
    }
    // 答えの候補の内、最も小さい値を見つける
    long long final = 1e18;
    for(auto j=ans.begin(); j!=ans.end(); j++){
        final = min(final, j->second);
    }

    cout << final << endl;

    return 0;
}*/

// 尺取り法について学習(開区間で探索している。基本、for構文とかでも開区間を用いて探索するように、
// 開区間を意識してプログラムを組み立てること
/*int main(){
    int n = 6;
    int x = 12;
    vector<int> a = {5, 3, 8, 6, 1, 4};
    int sum = 0, ans = 0;

    int right = 0, left = 0;
    rep(left, n){
        // n+1進めた時に満たす条件
        while(right<n and sum+a[right] <= x){
            sum += a[right];
            right++;
        }
        ans += right - left;
        if(left==right) right++;
        else sum -= a[left];
        cout << right-left << " " << endl;
    }

    cout << ans << endl;

}*/

// D問題(解答)
int main(){
    long long N;
    cin >> N;
    long long x, y;
    x = 1e06; y = 0;
    long long ans = 1e18;
    /*while(x>=y){
        if(f(x, y)>=N){
            x--;
            ans = min(ans, f(x, y));
        } else {
            y++;
        }
    }*/

    for(int y=0; y<1e06+1; y++){
        while(x>=y and f(x, y)>=N){
            ans = min(ans, f(x, y));
            x--;
        }
        if(x<y) break;
    }

    cout << ans << endl;

    return 0;

}