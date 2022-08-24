#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "16進数に変換します" << endl;
    string s;
    vector<string> S;
    for(int j =0; j<11*4; j++){
        cin >> s;
        S.push_back(s);
    }

    for(int j =0; j<11*4; j++){
        int pixcel = 0;
        int multi = 1;
        
        for(int i=1; i>=0; i--){
            if(S[j][i] == '0') pixcel += multi*0;
            if(S[j][i] == '1') pixcel += multi*1;
            if(S[j][i] == '2') pixcel += multi*2;
            if(S[j][i] == '3') pixcel += multi*3;
            if(S[j][i] == '4') pixcel += multi*4;
            if(S[j][i] == '5') pixcel += multi*5;
            if(S[j][i] == '6') pixcel += multi*6;
            if(S[j][i] == '7') pixcel += multi*7;
            if(S[j][i] == '8') pixcel += multi*8;
            if(S[j][i] == '9') pixcel += multi*9;
            if(S[j][i] == 'A') pixcel += multi*10;
            if(S[j][i] == 'B') pixcel += multi*11;
            if(S[j][i] == 'C') pixcel += multi*12;
            if(S[j][i] == 'D') pixcel += multi*13;
            if(S[j][i] == 'E') pixcel += multi*14;
            if(S[j][i] == 'F') pixcel += multi*15;
            multi *= 16;
        }
        cout << pixcel << " ";
    }


    
    cout << s.size() << endl;

    return 0;
}