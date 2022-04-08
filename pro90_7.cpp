#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    int A[N];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    int Q;
    int B[Q];
    for(int i = 0; i < Q; i++){
        cin >> B[i];
    }

    int min = 1000;
    int sum;
    for(int i = 0; i < Q; i++){
        for(int j = 0; j < N; j++){
            if(B[i] > A[j]){
                sum = B[i] - A[j];
            } else {}
                sum = A[j] - B[i];
        }
            if(min > sum) min = sum;
        cout << min << endl;
    }

    return 0;

}

//このようなある値を探すプログラム(条件に合うような値を求めるプログラム)は
//ソートして二分探索を行うのが良い

// 二分探索のアルゴリズムをいかに示す。

/*
int main(){
    int left = 0, right; //leftの値は0, ringhtの値は配列の要素の数だと思えば良い
    int mid = (left + right) / 2;
    int ans;
    while(left <= right ){
        if(ans = mid) return 1;
        if(ans <= mid){
            right = mid;
            mid = (left + rihgt) / 2;
        } else {
            left = mid;
            mid = (left + right) / 2;
        }
    }
    return 0;
    
    
    
*/