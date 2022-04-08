
#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    int sum = 0;
    vector< vector<int> > a(H, vector<int>(W, 0));
    for(int i = 0; i < N; i++){
        int Ai, Bi;
        cin >> Ai >> Bi;v
        a[Ai][Bi] = i+1;
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            sum += a[i][j];
        }
        if(sum == 0)
    }
}

// これだと計算量がえげつなく多くなるのでまず解けない。そこで使うのが座標圧縮という知識だった。正直知らねー