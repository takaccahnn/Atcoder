#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

//配列の中の最大値を求める関数
int max_a(vector<int> A){
    int max = A[0];
    rep(i, A.size()){
        if(max<A[i]) max = A[i];
    }
    return max;
}

// A問題
/*int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int get_up_T = A*3600 + B*60;
    int get_up_A = C*3600 + D*60 + 1;

    if(get_up_T>=get_up_A) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;

    return 0;
}*/

// B問題
/*int main(){
    int L;
    cin >> L;
    vector<int> N(L);
    rep(i, L) cin >> N[i];

    int size = max_a(N);
    vector<bool> used(size+2, false);

    rep(i, L){
        used[N[i]] = true;
    }

    rep(i, size+2){
        if(!used[i]){
            cout << i << endl;
            break;
        }
    }

    return 0;
}*/

// C問題
/*bool func(vector<int> &A, vector<int> &B, int number, vector<bool> &ans_A, vector<bool> &ans_B, int K){ //numberは比較している要素の番目
// ansは条件を満たせていれば、trueを返す
    if(ans_A[number-1]){
        if(abs(A[number-1]-A[number])<=K) ans_A[number] = true;
        if(abs(A[number-1]-B[number])<=K) ans_B[number] = true;
    }
    if(ans_B[number-1]){
        if(abs(B[number-1]-A[number])<=K) ans_A[number] = true;
        if(abs(B[number-1]-B[number])<=K) ans_B[number] = true;
    }

    if(ans_A[number]==false and ans_B[number]==false) return false;
    else return true;


}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vector<bool> ans_A(N, false);
    vector<bool> ans_B(N, false);
    ans_A[0] = true; ans_B[0] = true;

    for(int i=1; i<N; i++){
        if(!func(A, B, i, ans_A, ans_B, K)){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}*/

// D問題
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N+1);
    rep(i, N+1) cin >> A[i];
    vector<int> C(N+M+1);
    rep(i, N+M+1) cin >> C[i];
    vector<int> B(M+1);

    for(int i = M; i>=0; i--){
        B[i] = C[i+N]/A[N];
        for(int j=0; j<=N; j++){
            C[i+j] -= B[i]*A[j];
        }
    }

    rep(i, M+1) cout << B[i] << endl;



    return 0;
}