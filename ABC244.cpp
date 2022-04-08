#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

// A問題
/*int main(){
    int N;
    string S;
    cin >> N >> S;
    cout << S[N-1] << endl;
    return 0;
}*/

// B問題
/*int main(){
    int N;
    string T;
    cin >> N >> T;
    vector<string> vec(N+1);
    vec[0] = "east";
    int x = 0; int y = 0;
    rep(i, N){
        if(T[i] == 'S'){
            if(vec[i]=="east"){
                x += 1;
                vec[i+1] = "east";
            }
            if(vec[i]=="west"){
                x -= 1;
                vec[i+1] = "west";
            }
            if(vec[i]=="nouth"){
                y += 1;
                vec[i+1] = "nouth";
            }
            if(vec[i]=="south"){
                y -= 1;
                vec[i+1] = "south";
            }
        }
        if(T[i] == 'R'){
            if(vec[i]=="east"){
                vec[i+1] = "south";
            }
            if(vec[i]=="west"){
                vec[i+1] = "nouth";
            }
            if(vec[i]=="nouth"){
                vec[i+1] = "east";
            }
            if(vec[i]=="south"){
                vec[i+1] = "west";
            }
        }
    }
    cout << x << " " << y << endl;
    return 0;
}*/

// C問題
/*int main(){
    int N;
    cin >> N;
    vector<bool> used(2*N+2, false);
    while(true){
        for(int i=1; i<2*N+2; i++){
            if(!used[i]){
                used[i] = true;
                cout << i << endl;
                break;
            }
        }
        int in;
        cin >> in;
        used[in] = true;

        if(used[0]) break;

    }
    return 0;
}*/

// D問題
int main(){
    string S, T;
    getline(cin, S); getline(cin, T);

    int ans_S, ans_T;
    if(S == "R G B" or S == "G B R" or S == "B R G") ans_S = 0;
    else ans_S = 1;
    if(T == "R G B" or T == "G B R" or T == "B R G") ans_T = 0;
    else ans_T = 1;

    if(ans_S == ans_T) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}