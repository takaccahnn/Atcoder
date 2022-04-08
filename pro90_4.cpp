#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    int a[H][W], b[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a[i][j]; 
        }
    }
    
    int sum;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            sum = 0;               
            for(int k = 0; k < W; k++){
                sum += a[i][k];
                // cout << sum << " " << k << endl;
            }
            for(int l = 0; l < H; l++){
                sum += a[l][j];
                // cout << sum << " " << l <<  endl;
            }
            sum = sum - a[i][j];
            // cout << sum << endl;
            b[i][j] = sum;
            // cout << sum << endl;
        }
    }

    for(int i = 0; i < H; i++){
        cout << endl;
        for(int j = 0; j < W; j++){
            cout << b[i][j] << " ";
        }
    }
    cout << endl;

    /*for(int i = 0; i < H; i++){
        cout << endl;
        for(int j = 0; j < W; j++){
            cout << a[i][j] << " ";
        }
    }*/
    
}