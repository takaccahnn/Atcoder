#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using node = pair<int, int>;


// A問題
/*int main(){
    int V, A, B, C;
    cin >> V >> A >> B >> C;
    while(V>-1){
        if(V-A>-1) V -= A;
        else {
            cout << "F" << endl;
            return 0;
        }
        if(V-B>-1) V -= B;
        else {
            cout << "M" << endl;
            return 0;
        }
        if(V-C>-1) V -= C;
        else {
            cout << "T" << endl;
            return 0;
        }
    }
    return 0;
}*/

// B問題
/*int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    int ans_1 = 0, ans_2 = 0;
    rep(i, N){
        if(A[i]==B[i]) ans_1++;
        rep(j, N){
            if(A[i]==B[j] && i!=j) ans_2++;
        }
    }
    
    cout << ans_1 << endl << ans_2 << endl;


    return 0;
}*/

// C問題(TLE)
/*int main(){
    int N;
    cin >> N;
    vector<node> coordinate(N);
    rep(i, N) cin >> coordinate[i].first >> coordinate[i].second;
    string S;
    cin >> S;
    
    int finish = 0;
    for(int i=0; i<N-1; i++){
        if(finish) break;
        for(int j=i+1; j<N; j++){
            if(coordinate[i].second == coordinate[j].second){
                if(S[i]!=S[j]){
                    int min_num = min(coordinate[i].first, coordinate[j].first);
                    int number;
                    if(min_num==coordinate[i].first) number = i;
                    else number = j;
                    if(S[number]=='R'){
                        cout << "Yes" << endl;
                        finish = 1;
                        break;
                    }
                }
            }
        }
    }

    if(finish==0) cout << "No" << endl;

    return 0;
}*/
// これだと線形探索なので、計算量がO(n^2)となり,TLEとなってしまうので不適。

// C問題(mapを用いて探索する方法)
int main(){
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    string S;
    cin >> S;

    // keyはy座標を表し、値はx座標を表す
    // rightは'L'に進む座標。leftは'R'に進む座標
    unordered_map<int, int> right, left;

    // 答えがあればYes、なければNo
    bool isOK = false;
    rep(i, N){
        int x = X[i]; int y = Y[i];

        if(S[i]=='R'){
            // left[y]の中身が空集合なら
            if(left.count(y)==0) left[y] = x; 
            // left[y]の最も左端の値があれば更新
            else if(x < left[y]) left[y] = x;
        } else {
            // right[y]の中身が空集合なら
            if(right.count(y)==0) right[y] = x;
            // right[y]の最も右端の値があれば更新
            else if(right[y] < x) right[y] = x;
        }

        //　衝突する条件は、(右に進む座標left) < (左に進む座標)　が成立し、かつ、空集合てない時
        if(left.count(y)!=0 and right.count(y)!=0){
            if(left[y]< right[y])
            {
                isOK = true;
                break;
            }
        }
    }
    if(isOK) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

// C問題(vectorとtupleの組み合わせを用いた)
/*int main(){
    int N;
    cin >> N;
    // 前から順に、y座標、x座標、番号
    vector<tuple<int, int, int>> yx(N);
    rep(i, N){
        int x, y;
        cin >> x >> y;
        yx[i] = make_tuple(y, x, i);
    }
    string S;
    cin >> S;

    sort(yx.begin(), yx.end());

    bool isOK = false;
    for(int i=1; i<N; i++){
        if(get<0>(yx[i-1])==get<0>(yx[i])){
            int x1, x2, num1, num2;
            x1 = get<1>(yx[i-1]);
            x2 = get<1>(yx[i]);
            num1 = get<2>(yx[i-1]);
            num2 = get<2>(yx[i]);
            if(S[num1]!=S[num2] and S[num1]=='R' and x1<x2){
                isOK = true;
                break;
            }
            if(S[num1]!=S[num2] and S[num1]=='L' and x1>x2){
                isOK = true;
                break;
            }
        }
    }

    if(isOK) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}*/