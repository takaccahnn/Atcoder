#include <bits/stdc++.h>
using namespace std;

//文字列が、0と1の数が等しいか、0の方が1よりも常に数が多いか、を判断するための関数hantei
bool hantei(string s){
    int dep = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') dep++;
        if(s[i] == ')') dep--;
        if(dep < 0) return false;
    }
    if(dep == 0) return true;
    return false;
}

int main(){
    int N;
    cin >> N;
    string s = "";

    for(int i = 0; i < (1 << N); i++){
        for(int j = N - 1; j >= 0; j--){
            if((i & (1 << j)) == 0){
                s += "(";
            } else {
                s += ")"; //if((i & (1 << j)) == 1)とすると満たされないことがある。
                //つまり、論理演算子として、&の結果は必ずしも1ではなく０以外の値が用いられているということ
            }
                 //ビット演算子を使った表現についてもしっかりと復習すること
             //文字列通しの足し算も可能。stringは文字列
        }
        if(hantei(s)) cout << s << endl;
        s = "";
    }

    return 0;
}

