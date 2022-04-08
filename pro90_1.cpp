#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, L, A[N], score;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int a[N+1];
    a[0] = A[0], a[N] = L - A[N-1]; //配列aはそれぞれの切れ目の長さを表す行列
    for(int i = 1; i < N; i++){
        a[i] = A[i] - A[i-1];
    }

    bool a = true;
    int jud = 1;
    int time = 0;
    int sum;
    
    while(a){
        for(int i = 0; i < N+1; i++){
            sum += a[i];
            if(sum >= jud){
                sum = 0;
                time++;
                }
        }
        if(time >= K){
            a = true;
            jud++;
        } else { 
            cout << jud;
            a = false;}

    }
    


}