#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<(b);i++)
using Graph = vector<vector<int>>;
using node = pair<int, int>;

string toBinary(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

/*int main() {
    int number = pow(7, 9) * (-7);

    bitset<32> bs2(number);
    cout << "binary:  " << bs2 << endl;
    // signed int a = bs2;
    // unsigned int b = bs2;
    // float c = bs2;




    return EXIT_SUCCESS;
}*/

int main(){

    signed int a = pow(7, 9) * (-7);
    
    cout << "signed intで表現すると次の数字になります" << endl << a << endl;
    cout << "unsigned intで表現すると次の数字になります" << endl << (unsigned int)a << endl;
    cout << endl;

    string s = "11101111001010011100010100001111";
    
    double fix = 1;
    double E = 0;
    for(int i=8; i>=1; i--){
        int b = s[i]- '0';
        E += b * fix;
        fix *= 2;
    }
    double fix1 = 1.0;
    double M = 0.0;
    FOR(i, 9, 31){
        int b = s[i] - '0';

        M += (double)b / fix1;
        cout << (double)b/ fix1 << endl;
        fix1 *= 10;
    }
    cout << "E=" << E << endl;
    cout << "M=" << fixed << setprecision(32) << M << endl;



    cout << endl;
    double ans = (1.0 + M*pow(2, 95)) * pow(2, E-127);
    cout << "floatで表現すると次の数字になります" << endl << ans << endl;



    // (-7)^10
}